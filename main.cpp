#include <iostream>
#include "Graph.h"
#include "Test.h"
#include "Menu.h"

using namespace std;

template<typename T>
void Mainfunc() {
    int Command = -1;
    Graph<T> graph;
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
            graph.GetTheLeastWeightDistanceAnswer();
        } else if (Command == 6) {
            graph.ColorTheGraphAnswer();
        } else if (Command == 7) {
            graph.MinStableTreeAnswer();
        } else if (Command == 8) {
            graph.FindConnectedComponentsAnswer();
        } else if (Command == 9) {
            Test();
        } else if (Command == 10) {
            graph.FindStrongConnectedComponentsAnswer();
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

