#include <iostream>
#include "Graph.h"
#include "assert.h"

#pragma once


void TestFirstGroup() {
    Graph<int> graph = Graph<int>(3);
    Vertex<int> vertex = Vertex<int>();
    Edge<int> edge = Edge<int>();
    //cout << graph.Get(0).GetNumberOfElement() << '\n';
    edge.Set(0, 1, 1);
    assert(edge.GetNumberOfVertexTo() == 1);
    assert(edge.GetNumberOfVertexFrom() == 0);
    assert(edge.GetWeight() == 1);
    graph.Push_back(edge.GetNumberOfVertexFrom(), edge);
    assert(graph.Get(edge.GetNumberOfVertexFrom()).GetNumberOfElement() == edge.GetNumberOfVertexFrom());
    edge.Set(1, 2, 2);
    graph.Push_back(edge.GetNumberOfVertexFrom(), edge);
    assert(edge.GetNumberOfVertexTo() == 2);
//    cout << graph.Get(0).GetNumberOfElement() << '\n';
    assert(graph.Get(1).GetNumberOfElement() == 1);
    assert(graph.Get(0).GetIncedentArrayLength() == 1);
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

void Test() {
    TestFirstGroup();
    cout << "Set() from Edge, Push_back() from Graph, GetIncedentArrayLength() from Graph work correct\n";
    TestVertexGroup();
    cout << "";
}