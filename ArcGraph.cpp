#include "ArcGraph.h"

ArcGraph::ArcGraph(int size) : verticesCount(size) { }

ArcGraph::ArcGraph(const IGraph& graph) {
    verticesCount = graph.VerticesCount();
    for (int from = 0; from < verticesCount; ++from)
        for (int to : graph.GetNextVertices(from))
            pairs.emplace_back(from, to);
}

void ArcGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < verticesCount);
    assert(0 <= from && to < verticesCount);
    pairs.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < verticesCount);
    std::vector<int> nextVertices;
    for (auto pair : pairs) {
        if (pair.first == vertex) {
            nextVertices.push_back(pair.second);
        }
    }
    return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < verticesCount);
    std::vector<int> prevVertices;
    for (auto pair : pairs) {
        if (pair.second == vertex) {
            prevVertices.push_back(pair.first);
        }
    }
    return prevVertices;
}