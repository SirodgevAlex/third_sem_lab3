#pragma once

#include <iostream>

using namespace std;

void DataTypeMenu() {
    cout << "What data type you want?" << '\n';
    cout << "1 - int" << '\n';
    cout << "2 - double" << '\n';
    //cout << "3 - complex " << '\n';
}

void CommandMenu() {
    cout << "What do you want to do?\n";
    cout << "1 - input graph\n";
    cout << "2 - print graph\n";
    cout << "3 - add edge to graph\n";
    cout << "4 - get length of incedent array of vertex\n";
    cout << "5 - get the distance with the least weight to each of the vertices\n";
    cout << "6 - color the graph\n";
    cout << "7 - make minimum stable tree\n";
    cout << "8 - find connectivity components in tree\n";
    cout << "9 - Test\n";
    cout << "10 - find strong connected components\n";
    cout << "0 - Stop\n";
}