#include <iostream>
#include "Graph.h"
#include "Test.h"
#include "Menu.h"
#include "GraphFunctions.h"
#include "Colors.h"

using namespace std;

template<typename T>
void Mainfunc() {
    int Command = -1;
    Graph<T> graph;
    GraphFunctions<T> GrFunctions;
    Colors colors;
    while (Command != 0) {
        CommandMenu();
        cin >> Command;
        if (Command == 1) {
            cin >> graph;
        } else if (Command == 2) {
            cout << graph;
        } else if (Command == 3) {
            Edge<T> edge;
            cin >> edge;
            graph.Push_back(edge);
        } else if (Command == 4) {
            graph.GetLengthOfIncedentArrayOfVertex();
        } else if (Command == 5) {
            GrFunctions.GetTheLeastWeightDistanceAnswer(graph);
        } else if (Command == 6) {
            colors = GrFunctions.ColorTheGraph(graph);
        } else if (Command == 7) {
            GrFunctions.MinStableTreeAnswer(graph);
        } else if (Command == 8) {
            GrFunctions.FindConnectedComponentsAnswer(graph);
        } else if (Command == 9) {
            Test();
        } else if (Command == 10) {
            GrFunctions.FindStrongConnectedComponentsAnswer(graph);
        }
    }
}

int main() {
    DataTypeMenu();
    int DataType = 0;
    cin >> DataType;
    cout << "first of all input sequence please" << '\n';
    if (DataType == 1) {
        Mainfunc<int>();
    } else if (DataType == 2) {
        Mainfunc<double>();
    } else if (DataType == 3) {
        //Mainfunc<Complex<int>>();
    }
}

