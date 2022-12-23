#include <iostream>
#include <vector>
#pragma once

using namespace std;

// todo-Alexander написать граф и конструкторы
// todo-Alexander написать считывание и вывод графа

template <class T>
class Edge{
private:
    int NumberOfVertexFrom;
    int NumberOfVertexTo;
    T Weight = 0;
public:
    Edge() {

    }

    void Set(int NumberOfVertexFrom, int NumberOfVertexTo, T Weight) {
        this->NumberOfVertexFrom = NumberOfVertexFrom;
        this->NumberOfVertexTo = NumberOfVertexTo;
        this->Weight = Weight;
    }

    int GetNumberOfVertexFrom() {
        return this->NumberOfVertexFrom;
    }

    int GetNumberOfVertexTo() {
        return this->NumberOfVertexTo;
    }
};

template <class T>
class Vertex {
private:
    int NumberOfElement;
    vector<Edge<T>> IncedentArray;
public:
    Vertex() {

    }

    void Push_back(Edge<T> Ed) {
        this->IncedentArray.push_back(Ed);
    }

    int GetIncedentArraySize() {
        return this->IncedentArray.size();
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
        VertexArray.clear();
        VertexArray = vector<Vertex<T>>(CountOfVertex);
    }

    void Push_back(int NumberOfVertex, Edge<T> Ed) {
        this->VertexArray[NumberOfVertex].Push_back(Ed);
    }

};

template<typename T>
istream& operator >>(istream& in, Edge<T> &Ed) {
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
istream& operator >>(istream& in, Graph<T> &Gr) {
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
        Gr.Push_back(Ed.GetNumberOfVertexFrom(), Ed);
        Gr.Push_back(Ed.GetNumberOfVertexTo(), Ed);
    }
}

template<typename T>
ostream& operator <<(ostream &out, Edge<T> &Ed) {
    out << "this edge start in vertex number: ";
    out << Ed.GetNumberOfVertexFrom()
}