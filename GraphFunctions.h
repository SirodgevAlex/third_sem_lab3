#pragma once

#include <iostream>
#include "Graph.h"
#include <set>
#include "Colors.h"

using namespace std;

template<class T>
class GraphFunctions {
public:
    vector<T> GetTheLeastWeightDistance(Graph<T> graph, int StartVertex) {
        set<pair<int, int>> Set;
        vector<T> Weights(graph.GetLength(), 1000000000);
        vector<bool> Flag(graph.GetLength(), false);
        Weights[StartVertex] = 0;
        Set.insert({0, StartVertex});
        while (Set.size() != 0) {
            int StartVertex = Set.begin()->second;
            Set.erase(Set.begin());
            for (int i = 0; i < graph.Get(StartVertex).GetIncedentArrayLength(); i++) {
                int FinishVertex = graph.Get(StartVertex).Get(i).GetNumberOfVertexTo();
                T Weight = graph.Get(StartVertex).Get(i).GetWeight();
                if (Weights[StartVertex] + Weight < Weights[FinishVertex]) {
                    Set.erase({Weights[FinishVertex], FinishVertex});
                    Weights[FinishVertex] = Weights[StartVertex] + Weight;
                    Set.insert({Weights[FinishVertex], FinishVertex});
                }
            }
        }
        return Weights;
    }

    void GetTheLeastWeightDistanceAnswer(Graph<T> graph) {
        int StartVertex;
        cout << "input please vertex for which you want to get answer\n";
        cin >> StartVertex;
        StartVertex--;
        vector<T> Weights = GetTheLeastWeightDistance(graph, StartVertex);
        for (int i = 0; i < Weights.size(); i++) {
            if (Weights[i] == 1000000000)
                cout << "To vertex number " << i << " there is no path from start vertex number " << StartVertex
                     << '\n';
            else if (i == StartVertex) cout << "it is start vertex\n";
            else
                cout << "To vertex number " << i << " weigth of path from start vertex number " << StartVertex << " is "
                     << Weights[i] << '\n';
        }
    }

    Colors ColorTheGraph(Graph<T> graph) {
        Colors colors = Colors(graph.GetLength(), -1);
        for (int i = 0; i < graph.GetLength(); i++) {
            vector<bool> AvailableColors(graph.GetLength(), true);
            for (int g = 0; g < graph.Get(i).GetIncedentArrayLength(); g++) {
                int IncedentVertexNumber = graph.Get(i).Get(g).GetNumberOfVertexTo();
                if (colors[IncedentVertexNumber] != -1) AvailableColors[colors[IncedentVertexNumber]] = false;
            }
            for (int g = 0; g < graph.Get(i).GetHiddenIncedentArrayLength(); g++) {
                int IncedentVertexNumber = graph.Get(i).GetHidden(g).GetNumberOfVertexFrom();
                if (colors[IncedentVertexNumber] != -1) AvailableColors[colors[IncedentVertexNumber]] = false;
            }
            int g = 0;
            while (!AvailableColors[g]) g++;
            colors.SetColorNumber(i, g);
        }
        return colors;
    }

    vector<Edge<T>> MinStableTree(Graph<T> graph) {
        vector<bool> used(graph.GetLength(), false);
        int INF = 1000000000;
        vector<T> Weights(graph.GetLength(), INF);
        vector<int> EndOfEdge(graph.GetLength(), -1);
        Weights[0] = 0;
        vector<Edge<T>> MST;
        for (int i = 0; i < graph.GetLength(); i++) {
            int v = -1;
            for (int g = 0; g < graph.GetLength(); g++) {
                if ((used[g] == false) and ((v == -1) or (Weights[g] < Weights[v]))) v = g;
                //cout << v << '\n';
            }
            if (Weights[v] == INF) {
                Edge<T> edge = Edge<T>(-1, v, -2);
                MST.push_back(edge);
            } else {
                used[v] = true;
                if (EndOfEdge[v] != -1) {
                    Edge<T> edge = Edge<T>(EndOfEdge[v], v, Weights[v]);
                    //cout << edge;
                    MST.push_back(edge);
                }
                for (int g = 0; g < graph.Get(v).GetIncedentArrayLength(); g++) {
                    //cout << v << ' ' << this->VertexArray[v].Get(g).GetWeight() << ' ' << Weights[g] << '\n';
                    if (graph.Get(v).Get(g).GetWeight() <
                        Weights[graph.Get(v).Get(g).GetNumberOfVertexTo()]) {
                        Weights[graph.Get(v).Get(g).GetNumberOfVertexTo()] = graph.Get(v).Get(
                                g).GetWeight();
                        EndOfEdge[graph.Get(v).Get(g).GetNumberOfVertexTo()] = v;
                    }
                }
            }
        }
        return MST;
    }

    void MinStableTreeAnswer(Graph<T> graph) {
        vector<Edge<T>> Answer = MinStableTree(graph);
        for (int i = 0; i < Answer.size(); i++) {
            if (Answer[i].GetWeight() == -2) cout << "Vertex Number " << Answer[i].GetNumberOfVertexTo() << " have no MST\n";
            else cout << "Edge from vertex number " << Answer[i].GetNumberOfVertexFrom() << ' ' << "to " << Answer[i].GetNumberOfVertexTo() << " and has weight " << Answer[i].GetWeight() << '\n';
        }
    }

    void DeepFindSearch(Graph<T> graph, vector<int> &used, int last, int count) {
        used[last] = count;
        for (int i = 0; i < graph.Get(last).GetIncedentArrayLength(); i++) {
            if (used[graph.Get(last).Get(i).GetNumberOfVertexTo()] == -1) DeepFindSearch(graph,used, graph.Get(last).Get(i).GetNumberOfVertexTo(), count);
        }
        for (int i = 0; i < graph.Get(last).GetHiddenIncedentArrayLength(); i++) {
            if (used[graph.Get(last).GetHidden(i).GetNumberOfVertexFrom()] == -1) DeepFindSearch(graph, used, graph.Get(last).GetHidden(i).GetNumberOfVertexFrom(), count);
        }
    }

    void DeepFindSearchTimeIn(Graph<T> graph, vector<bool> &used, int last, vector<int> &order) {
        used[last] = true;
        for (int i = 0; i < graph.Get(last).GetIncedentArrayLength(); i++) {
            if (used[graph.Get(last).Get(i).GetNumberOfVertexTo()] == false) DeepFindSearchTimeIn(graph, used, graph.Get(last).Get(i).GetNumberOfVertexTo(), order);
        }
        order.push_back(last);
    }

    void DeepFindSearchTimeOut(Graph<T> graph, vector<bool> &used, int last, vector<vector<int>> &Components, int NumberOfComponent) {
        used[last] = true;
        Components[NumberOfComponent].push_back(last);
        for (int i = 0; i < graph.Get(last).GetHiddenIncedentArrayLength(); i++) {
            if (used[graph.Get(last).GetHidden(i).GetNumberOfVertexFrom()] == false) DeepFindSearchTimeOut(graph, used, graph.Get(last).GetHidden(i).GetNumberOfVertexFrom(), Components, NumberOfComponent);
        }
    }

    vector<vector<int>> FindConnectedComponents(Graph<T> graph) {
        vector<int> used(graph.GetLength(), -1);
        int count = 0;
        for (int i = 0; i < graph.GetLength(); i++) {
            if (used[i] == -1) {
                DeepFindSearch(graph, used, i, count);
                count++;
            }
        }
        vector<vector<int>> Components(count);
        for (int i = 0; i < graph.GetLength(); i++) {
            Components[used[i]].push_back(i);
        }
        return Components;
    }

    void FindConnectedComponentsAnswer(Graph<T> graph) {
        vector<vector<int>> Answer = FindConnectedComponents(graph);
        for (int i = 0; i < Answer.size(); i++) {
            cout << "In the connectivity component number " << i + 1 << ' ' << "there are vertices: ";
            for (int g = 0; g < Answer[i].size(); g++) {
                cout << Answer[i][g] + 1 << ' ';
            }
            cout << '\n';
        }
    }

    vector<vector<int>> FindStrongConnectedComponents(Graph<T> graph) {
        vector<bool> used(graph.GetLength(), false);
        vector<int> order;
        for (int i = 0; i < graph.GetLength(); i++) {
            if (!used[i]) DeepFindSearchTimeIn(graph, used, i, order);
        }
        used.assign(graph.GetLength(), false);
        vector<vector<int>> Components(graph.GetLength());
        int NumberOfComponent = 0;
        for (int i = 0; i < graph.GetLength(); i++) {
            if (!used[order[graph.GetLength() - 1 - i]]) {
                DeepFindSearchTimeOut(graph, used, order[graph.GetLength() - 1 - i], Components, NumberOfComponent);
                NumberOfComponent++;
            }
        }
        Components.resize(NumberOfComponent);
        for (int i = 0; i < Components.size(); i++) {
            for (int g = 0; g < Components[i].size(); g++) {
                cout << Components[i][g] << ' ';
            }
            cout << '\n';
        }
        return Components;
    }

    void FindStrongConnectedComponentsAnswer(Graph<T> graph) {
        vector<vector<int>> Answer = FindStrongConnectedComponents(graph);
        for (int i = 0; i < Answer.size(); i++) {
            cout << "In the strong connectivity component number " << i + 1 << ' ' << "there are vertices: ";
            for (int g = 0; g < Answer[i].size(); g++) {
                cout << Answer[i][g] + 1 << ' ';
            }
            cout << '\n';
        }
    }
};