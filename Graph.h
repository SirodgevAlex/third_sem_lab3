#include <iostream>
#include <vector>
#include <set>

#pragma once

using namespace std;

// todo-Alexander написать перегрузку оператора [] для класса Graph
// todo-Alexander написать деструкторы

//граф ориентированный


template<class T>
class Edge {
private:
    int NumberOfVertexFrom = 0;
    int NumberOfVertexTo = 0;
    T Weight = 0;
public:
    Edge() {

    }

    Edge(int NumberOfVertexFrom, int NumberOfVertexTo, T Weight) {
        this->NumberOfVertexFrom = NumberOfVertexFrom;
        this->NumberOfVertexTo = NumberOfVertexTo;
        this->Weight = Weight;
    }

    void Set(int NumberOfVertexFrom, int NumberOfVertexTo, T Weight) {
        this->NumberOfVertexFrom = NumberOfVertexFrom;
        this->NumberOfVertexTo = NumberOfVertexTo;
        this->Weight = Weight;
    }

    int GetNumberOfVertexFrom() {
        return this->NumberOfVertexFrom;
    }

    void SetNumberOfVertexFrom(int value) {
        this->NumberOfVertexFrom = value;
    }

    int GetNumberOfVertexTo() {
        return this->NumberOfVertexTo;
    }

    void SetNumberOfVertexTo(int value) {
        this->NumberOfVertexTo = value;
    }

    T GetWeight() {
        return this->Weight;
    }

    void SwapHumbersOfVertex() {
        int Cur = this->GetNumberOfVertexFrom();
        this->SetNumberOfVertexFrom(this->GetNumberOfVertexTo());
        this->SetNumberOfVertexTo(Cur);
    }

    void Print() {
        cout << "this edge starts in vertex number: ";
        cout << GetNumberOfVertexFrom();
        cout << "\n";
        cout << "this edge ends in vertex number: ";
        cout << GetNumberOfVertexTo() << '\n';
        cout << "and has weight: ";
        cout << GetWeight() << '\n';
    }
};

template<class T>
class Vertex {
private:
    int NumberOfElement = 0;
    vector<Edge<T>> IncedentArray;
    vector<Edge<T>> HiddenIncedentArray; //ребра ор графа, которыые приходят в данную вершину
    vector<Edge<T>> TransposedIncedentArray;
public:
    Vertex() {

    }

    Vertex(int NumberOfElement) {
        this->NumberOfElement = NumberOfElement;
    }

    void Push_back(Edge<T> Ed) {
        this->IncedentArray.push_back(Ed);
    }

    void HiddenPush_back(Edge<T> Ed) {
        this->HiddenIncedentArray.push_back(Ed);
    }

    int GetIncedentArrayLength() {
        return this->IncedentArray.size();
    }

    int GetHiddenIncedentArrayLength() {
        return this->HiddenIncedentArray.size();
    }

    int GetTransposedIncedentArrayLength() {
        return this->TransposedIncedentArray.size();
    }

    int GetNumberOfElement() {
        return this->NumberOfElement;
    }

    Edge<T> Get(int index) {
        return this->IncedentArray[index];
    }

    Edge<T> GetHidden(int index) {
        return this->HiddenIncedentArray[index];
    }

    Edge<T> GetTransposed(int index) {
        return this->TransposedIncedentArray[index];
    }

    void SetNumberOfElement(int NumberOfElement) {
        this->NumberOfElement = NumberOfElement;
    }

    void Print() {
        cout << "Vertex number ";
        cout << GetNumberOfElement();
        cout << " has ";
        cout << GetIncedentArrayLength();
        cout << " incident edges\n";
        for (int i = 0; i < GetIncedentArrayLength(); i++) {
            Get(i).Print();
        }
    }

    void PrintHidden() {
        cout << "Vertex number ";
        cout << GetNumberOfElement();
        cout << " has ";
        cout << GetHiddenIncedentArrayLength();
        cout << " incident edges\n";
        for (int i = 0; i < GetHiddenIncedentArrayLength(); i++) {
            GetHidden(i).EdgePrint();
        }
    }

};

template<class T>
class Graph {
private:
    vector<Vertex<T>> VertexArray;
public:
    Graph() {

    }

    Graph(int CountOfVertex) {
        this->VertexArray.clear();
        this->VertexArray = vector<Vertex<T>>(CountOfVertex);
        for (int i = 0; i < CountOfVertex; i++) {
            this->VertexArray[i].SetNumberOfElement(i);
        }
    }

    void Push_back(Edge<T> Ed) {
        this->VertexArray[Ed.GetNumberOfVertexFrom()].Push_back(Ed);
        this->VertexArray[Ed.GetNumberOfVertexTo()].HiddenPush_back(Ed);
        Ed.SwapHumbersOfVertex();
        //this->VertexArray[E]
    }

    void PrintHidden() {
        cout << "this graph has ";
        cout << GetLength();
        cout << " vertex\n";
        for (int i = 0; i < GetLength(); i++) {
            this->VertexArray[i].PrintHidden;
        }
    }

    int GetLength() {
        return this->VertexArray.size();
    }

    Vertex<T> Get(int index) {
        return this->VertexArray[index];
    }

    int GetLengthOfIncedentArrayOfVertex() {
        cout << "input please number of vertex from 1 to" << ' ' << GetLength() << '\n';
        int NumberOfVertex;
        cin >> NumberOfVertex;
        return VertexArray[NumberOfVertex].GetIncedentArrayLength();
    }

    vector<T> GetTheLeastWeightDistance(int StartVertex) {
        set<pair<int, int>> Set;
        vector<T> Weights(GetLength(), 1000000000);
        vector<bool> Flag(GetLength(), false);
        Weights[StartVertex] = 0;
        Set.insert({0, StartVertex});
        while (Set.size() != 0) {
            int StartVertex = Set.begin()->second;
            Set.erase(Set.begin());
            for (int i = 0; i < this->VertexArray[StartVertex].GetIncedentArrayLength(); i++) {
                int FinishVertex = this->VertexArray[StartVertex].Get(i).GetNumberOfVertexTo();
                T Weight = this->VertexArray[StartVertex].Get(i).GetWeight();
                if (Weights[StartVertex] + Weight < Weights[FinishVertex]) {
                    Set.erase({Weights[FinishVertex], FinishVertex});
                    Weights[FinishVertex] = Weights[StartVertex] + Weight;
                    Set.insert({Weights[FinishVertex], FinishVertex});
                }
            }
        }
        return Weights;
    }

    void GetTheLeastWeightDistanceAnswer() {
        int StartVertex;
        cout << "input please vertex for which you want to get answer\n";
        cin >> StartVertex;
        StartVertex--;
        vector<T> Weights = GetTheLeastWeightDistance(StartVertex);
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

    vector<int> ColorTheGraph() {
        vector<int> Colors(GetLength(), -1);
        for (int i = 0; i < GetLength(); i++) {
            vector<bool> AvailableColors(GetLength(), true);
            for (int g = 0; g < this->VertexArray[i].GetIncedentArrayLength(); g++) {
                int IncedentVertexNumber = this->VertexArray[i].Get(g).GetNumberOfVertexTo();
                if (Colors[IncedentVertexNumber] != -1) AvailableColors[Colors[IncedentVertexNumber]] = false;
            }
            for (int g = 0; g < this->VertexArray[i].GetHiddenIncedentArrayLength(); g++) {
                int IncedentVertexNumber = this->VertexArray[i].GetHidden(g).GetNumberOfVertexFrom();
                if (Colors[IncedentVertexNumber] != -1) AvailableColors[Colors[IncedentVertexNumber]] = false;
            }
            int g = 0;
            while (!AvailableColors[g]) g++;
            Colors[i] = g;
        }
        return Colors;
    }

    void ColorTheGraphAnswer() {
        vector<int> Colors = ColorTheGraph();
        for (int i = 0; i < GetLength(); i++) {
            cout << "Vertex number" << i + 1 << ' ' << "has color number " << Colors[i] << '\n';
        }
    }

    vector<Edge<T>> MinStableTree() {
        vector<bool> used(GetLength(), false);
        int INF = 1000000000;
        vector<T> Weights(GetLength(), INF);
        vector<int> EndOfEdge(GetLength(), -1);
        Weights[0] = 0;
        vector<Edge<T>> MST;
        for (int i = 0; i < GetLength(); i++) {
            int v = -1;
            for (int g = 0; g < GetLength(); g++) {
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
                for (int g = 0; g < this->VertexArray[v].GetIncedentArrayLength(); g++) {
                    //cout << v << ' ' << this->VertexArray[v].Get(g).GetWeight() << ' ' << Weights[g] << '\n';
                    if (this->VertexArray[v].Get(g).GetWeight() <
                        Weights[this->VertexArray[v].Get(g).GetNumberOfVertexTo()]) {
                        Weights[this->VertexArray[v].Get(g).GetNumberOfVertexTo()] = this->VertexArray[v].Get(
                                g).GetWeight();
                        EndOfEdge[this->VertexArray[v].Get(g).GetNumberOfVertexTo()] = v;
                    }
                }
            }
        }
        return MST;
    }

    void MinStableTreeAnswer() {
        vector<Edge<T>> Answer = MinStableTree();
        for (int i = 0; i < Answer.size(); i++) {
            if (Answer[i].GetWeight() == -2) cout << "Vertex Number " << Answer[i].GetNumberOfVertexTo() << " have no MST\n";
            else cout << "Edge from vertex number " << Answer[i].GetNumberOfVertexFrom() << ' ' << "to " << Answer[i].GetNumberOfVertexTo() << " and has weight " << Answer[i].GetWeight() << '\n';
        }
    }

    void DeepFindSearch(vector<int> &used, int last, int count) {
        used[last] = count;
        for (int i = 0; i < this->VertexArray[last].GetIncedentArrayLength(); i++) {
            if (used[this->VertexArray[last].Get(i).GetNumberOfVertexTo()] == -1) DeepFindSearch(used, this->VertexArray[last].Get(i).GetNumberOfVertexTo(), count);
        }
        for (int i = 0; i < this->VertexArray[last].GetHiddenIncedentArrayLength(); i++) {
            if (used[this->VertexArray[last].GetHidden(i).GetNumberOfVertexFrom()] == -1) DeepFindSearch(used, this->VertexArray[last].GetHidden(i).GetNumberOfVertexFrom(), count);
        }
    }

    void DeepFindSearchTimeIn(vector<bool> &used, int last, vector<int> &order) {
        used[last] = true;
        for (int i = 0; i < this->VertexArray[last].GetIncedentArrayLength(); i++) {
            if (used[this->VertexArray[last].Get(i).GetNumberOfVertexTo()] == false) DeepFindSearchTimeIn(used, this->VertexArray[last].Get(i).GetNumberOfVertexTo(), order);
        }
        order.push_back(last);
    }

    void DeepFindSearchTimeOut(vector<bool> &used, int last, vector<vector<int>> &Components, int NumberOfComponent) {
        used[last] = true;
        Components[NumberOfComponent].push_back(last);

        for (int i = 0; i < this->VertexArray[last].GetHiddenIncedentArrayLength(); i++) {
            if (used[this->VertexArray[last].GetHidden(i).GetNumberOfVertexFrom()] == false) DeepFindSearchTimeOut(used, this->VertexArray[last].GetHidden(i).GetNumberOfVertexFrom(), Components, NumberOfComponent);
        }
    }

    vector<vector<int>> FindConnectedComponents() {
        vector<int> used(GetLength(), -1);
        int count = 0;
        for (int i = 0; i < GetLength(); i++) {
            if (used[i] == -1) {
                DeepFindSearch(used, i, count);
                count++;
            }
        }
        vector<vector<int>> Components(count);
        for (int i = 0; i < GetLength(); i++) {
            Components[used[i]].push_back(i);
        }
        return Components;
    }

    void FindConnectedComponentsAnswer() {
        vector<vector<int>> Answer = FindConnectedComponents();
        for (int i = 0; i < Answer.size(); i++) {
            cout << "In the connectivity component number " << i + 1 << ' ' << "there are vertices: ";
            for (int g = 0; g < Answer[i].size(); g++) {
                cout << Answer[i][g] + 1 << ' ';
            }
            cout << '\n';
        }
    }

    vector<vector<int>> FindStrongConnectedComponents() {
        vector<bool> used(GetLength(), false);
        vector<int> order;
        for (int i = 0; i < GetLength(); i++) {
            if (!used[i]) DeepFindSearchTimeIn(used, i, order);
        }
        used.assign(GetLength(), false);
        vector<vector<int>> Components(GetLength());
        int NumberOfComponent = 0;
        for (int i = 0; i < GetLength(); i++) {
            if (!used[order[GetLength() - 1 - i]]) {
                DeepFindSearchTimeOut(used, order[GetLength() - 1 - i], Components, NumberOfComponent);
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

    void FindStrongConnectedComponentsAnswer() {
        vector<vector<int>> Answer = FindStrongConnectedComponents();
        for (int i = 0; i < Answer.size(); i++) {
            cout << "In the strong connectivity component number " << i + 1 << ' ' << "there are vertices: ";
            for (int g = 0; g < Answer[i].size(); g++) {
                cout << Answer[i][g] + 1 << ' ';
            }
            cout << '\n';
        }
    }

};

template<typename T>
istream &operator>>(istream &in, Edge<T> &Ed) {
    cout << "From which vertex does this edge originate?\n";
    int NumberOfVertexFrom;
    in >> NumberOfVertexFrom;
    cout << "What vertex does this edge come to\n";
    int NumberOfVertexTo;
    in >> NumberOfVertexTo;
    cout << "what is the weight of this edge?\n";
    T Weight;
    in >> Weight;
    Ed.Set(NumberOfVertexFrom, NumberOfVertexTo, Weight);
    return in;
}

template<typename T>
istream &operator>>(istream &in, Graph<T> &Gr) {
    cout << "How much vertex in graph?\n";
    int CountOfVertex;
    in >> CountOfVertex;
    Gr = Graph<T>(CountOfVertex);
    cout << "How many edges in graph\n";
    int CountOfEdges;
    in >> CountOfEdges;
    for (int i = 0; i < CountOfEdges; i++) {
        Edge<T> Ed;
        cin >> Ed;
        Ed.SetNumberOfVertexFrom(Ed.GetNumberOfVertexFrom() - 1);
        Ed.SetNumberOfVertexTo(Ed.GetNumberOfVertexTo() - 1);
        Gr.Push_back(Ed);
        //Gr.Push_back(Ed.GetNumberOfVertexTo(), Ed);
    }
}

template<typename T>
ostream &operator<<(ostream &out, Edge<T> &Ed) {
    out << "this edge starts in vertex number: ";
    out << Ed.GetNumberOfVertexFrom();
    out << "\n";
    out << "this edge ends in vertex number: ";
    out << Ed.GetNumberOfVertexTo();
    out << "\n";
    out << "and has weight: ";
    out << Ed.GetWeight();
    out << "\n";
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, Vertex<T> Ve) {
    out << "Vertex number ";
    out << Ve.GetNumberOfElement();
    out << " has ";
    out << Ve.GetIncedentArrayLength();
    out << " incident edges\n";
    for (int i = 0; i < Ve.GetIncedentArrayLength(); i++) {
        Edge<T> Ed = Ve.Get(i);
        Ed.Print();
    }
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, Graph<T> Gr) {
    out << "this graph has ";
    out << Gr.GetLength();
    out << " vertex\n";
    for (int i = 0; i < Gr.GetLength(); i++) {
        out << Gr.Get(i);
    }
    return out;
}

template<typename T>
bool operator==(Edge<T> Ed1, Edge<T> Ed2) {
    if (Ed1.GetNumberOfVertexFrom() != Ed2.GetNumberOfVertexFrom()) return false;
    if (Ed1.GetNumberOfVertexTo() != Ed1.GetNumberOfVertexTo()) return false;
    if (Ed1.GetWeight() != Ed2.GetWeight()) return false;
    return true;
}



