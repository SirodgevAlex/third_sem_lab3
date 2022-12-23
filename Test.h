#include <iostream>
#include "Graph.h"
#pragma once


void TestFirstGroup() {
    Graph<int> graph = Graph<int>(3);
    Vertex<int> vertex = Vertex<int>();
    Edge<int> edge = Edge<int>();
    edge.Set(1, 2, 1);
    graph.Push_back(edge.GetNumberOfVertexFrom(), edge);
    edge.Set(2, 3, 2);
    graph.Push_back(edge.GetNumberOfVertexFrom(), edge);
    assert(graph[0].== )
}

void Test() {
    TestFirstGroup();
    cout << ""
}