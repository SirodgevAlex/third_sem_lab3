#include <iostream>
#include "Graph.h"
#include "assert.h"

#pragma once


void TestEdgeConstuctor() {
    Edge<int> edge = Edge<int>();
    assert(edge.GetNumberOfVertexFrom() == 0);
    assert(edge.GetNumberOfVertexTo() == 0);
    assert(edge.GetWeight() == 0);
    edge = Edge<int>(1, 2, 3);
    assert(edge.GetNumberOfVertexFrom() == 1);
    assert(edge.GetNumberOfVertexTo() == 2);
    assert(edge.GetWeight() == 3);
}

void TestEdgeFirstGroup() {
    Edge<int> edge = Edge<int>();
    edge.Set(0, 1, 1);
    assert(edge.GetNumberOfVertexFrom() == 0);
    assert(edge.GetNumberOfVertexTo() == 1);
    assert(edge.GetWeight() == 1);
}

void TestVertexConstructor() {
    Vertex<int> vertex = Vertex<int>();
    assert(vertex.GetNumberOfElement() == 0);
    assert(vertex.GetIncedentArrayLength() == 0);
}

void TestVertexSetNumberOfElement() {
    Vertex<int> vertex = Vertex<int>();
    vertex.SetNumberOfElement(1);
    assert(vertex.GetNumberOfElement() == 1);
}

void TestFirstGroup() {
    Graph<int> graph = Graph<int>(3);
    Vertex<int> vertex = Vertex<int>();
    Edge<int> edge = Edge<int>();
    //cout << graph.Get(0).GetNumberOfElement() << '\n';
    edge.Set(0, 1, 1);
    assert(edge.GetNumberOfVertexTo() == 1);
    assert(edge.GetNumberOfVertexFrom() == 0);
    assert(edge.GetWeight() == 1);
    graph.Push_back(edge);
    assert(graph.Get(edge.GetNumberOfVertexFrom()).GetNumberOfElement() == edge.GetNumberOfVertexFrom());
    edge.Set(1, 2, 2);
    graph.Push_back(edge);
    cout << graph.Get(1).GetIncedentArrayLength() << '\n';
    assert(edge.GetNumberOfVertexTo() == 2);
    cout << graph.Get(1).GetNumberOfElement() << '\n';
    //assert(graph.Get(1).GetNumberOfElement() == 1);
    //assert(graph.Get(0).GetIncedentArrayLength() == 1);
}


void TestVertexGroup() {
    Vertex<int> vertex = Vertex<int>();
    assert(vertex.GetIncedentArrayLength() == 0);
    Edge<int> edge = Edge<int>();
    edge.Set(0, 1, 1);
    assert(vertex.GetIncedentArrayLength() == 1);
    assert(vertex.GetNumberOfElement() == 0);
    assert(vertex.Get(0) == edge);
}

void TestGraphConstrutors() {
    Graph<int> graph = Graph<int>(0);
    assert(graph.GetLength() == 0);
    graph = Graph<int>(3);
    assert(graph.Get(0).GetNumberOfElement() == 0);
    assert(graph.Get(1).GetNumberOfElement() == 1);
    assert(graph.Get(2).GetNumberOfElement() == 2);
}

void TestGraphGetLength() {
    Graph<int> graph = Graph<int>(3);
    assert(graph.GetLength() == 3);
}

void TestGraphPush_back() {
    Graph<int> graph = Graph<int>(3);
    assert(graph.Get(0).GetIncedentArrayLength() == 0);
    Edge<int> edge = Edge<int>(0, 1, 2);
    graph.Push_back(edge);
    assert(graph.Get(0).GetIncedentArrayLength() == 1);
}

void Test() {
    cout << "\e[1;93mFOR EDGE : \e[0m";
    cout << '\n';
    TestEdgeConstuctor();
    cout << "   Constructor for Edge works correct\n";
    TestEdgeFirstGroup();
    cout << "   Set(), GetNumberOfVertexFrom(), GetNumberOfVertexTo(), GetWeight() work correct\n";
    cout << "\e[1;93mFOR Vertex : \e[0m";
    cout << '\n';
    TestVertexConstructor();
    cout << "   Constructor for Vertex works correct\n";
    TestVertexSetNumberOfElement();
    cout << "   SetNumberOfElement() for Vertex works correct\n";
    cout << "\e[1;93mFOR GRAPH : \e[0m";
    cout << '\n';
    TestGraphConstrutors();
    cout << "   All constructors for Graph work correct\n";
    TestGraphGetLength();
    cout << "   GetLength() for Graph work correct\n";
    TestGraphPush_back();
    cout << "   Push_back() for Graph work correct\n";

}