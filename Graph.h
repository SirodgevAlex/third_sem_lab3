#include <iostream>
#include <vector>
#include <set>

#pragma once

using namespace std;

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
    Ed.Set(NumberOfVertexFrom - 1, NumberOfVertexTo - 1, Weight);
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
        //Ed.SetNumberOfVertexFrom(Ed.GetNumberOfVertexFrom() - 1);
        //Ed.SetNumberOfVertexTo(Ed.GetNumberOfVertexTo() - 1);
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



