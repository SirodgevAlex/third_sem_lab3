#include <iostream>
#include <vector>

#pragma once

using namespace std;

// todo-Alexander написать перегрузку оператора [] для класса Graph


//граф ориентированный

template<class T>
class Edge {
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

    T GetWeight() {
        return this->Weight;
    }
};

template<class T>
class Vertex {
private:
    int NumberOfElement = 0;
    vector<Edge<T>> IncedentArray;
public:
    Vertex() {

    }

    void Push_back(Edge<T> Ed) {
        this->IncedentArray.push_back(Ed);
    }

    int GetIncedentArrayLength() {
        return this->IncedentArray.size();
    }

    int GetNumberOfElement() {
        return this->NumberOfElement;
    }

    Edge<T> Get(int index) {
        return this->IncedentArray[index];
    }

    void Print() {
        cout << "this edge starts in vertex number: ";
        cout << this->GetNumberOfVertexFrom();
        cout << "\n";
        cout << "this edge ends in vertex number: ";
        cout << this->GetNumberOfVertexTo();
        cout << "and has weight: ";
        cout << this->GetWeight();
    }

    void SetNumberOfElement(int NumberOfElement) {
        this->NumberOfElement = NumberOfElement;
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
        for (int i = 0; i < CountOfVertex; i++) {
            this->Get(i).SetNumberOfElement(i);
        }
    }

    void Push_back(int NumberOfVertex, Edge<T> Ed) {
        Get(NumberOfVertex).Push_back(Ed);
    }

    int GetLength() {
        return this->VertexArray.size();
    }

    Vertex<T> Get(int index) {

        return this->VertexArray[index];
    }

    Vertex<T>& GetVertex(int index) {
        //cout << this->VertexArray[index];
        return &this->VertexArray[index];
    }

    void Print() {
        cout << "Vertex number ";
        cout << this->GetNumberOfElement();
        cout << " has ";
        cout << this->GetIncedentArrayLength();
        cout << " incident edges\n";
        for (int i = 0; i < this->GetIncedentArrayLength(); i++) {
            this->Get(i).Print();
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
        Gr.Push_back(Ed.GetNumberOfVertexFrom(), Ed);
        Gr.Push_back(Ed.GetNumberOfVertexTo(), Ed);
    }
}

template<typename T>
ostream &operator<<(ostream &out, Edge<T> &Ed) {
    out << "this edge starts in vertex number: ";
    out << Ed.GetNumberOfVertexFrom();
    out << "\n";
    out << "this edge ends in vertex number: ";
    out << Ed.GetNumberOfVertexTo();
    out << "and has weight: ";
    out << Ed.GetWeight();
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
        Ve.Get(i).Print();
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

