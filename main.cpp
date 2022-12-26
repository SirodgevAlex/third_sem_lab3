#include <iostream>
#include "Graph.h"
#include "Test.h"
#include "Menu.h"

using namespace std;

template<typename T>
void Mainfunc() {
    int Command = -1;
    while (Command != 0) {
        CommandMenu();
        cin >> Command;
        if (Command == 1) {
            Graph<int> graph;
            cin >> graph;
        } else if (Command == 2) {

        } else if (Command == 9) {
            Test();
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
        Mainfunc<float>();
    } else if (DataType == 3) {
        //Mainfunc<Complex<int>>();
    }
}

