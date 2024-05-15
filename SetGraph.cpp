#include "SetGraph.h"

SetGraph::SetGraph(int size) : sets(size) { }

SetGraph::SetGraph(const IGraph& graph) : sets(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i)
        for (auto to : graph.GetNextVertices(i))
            sets[i].insert(to);
}

void SetGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < sets.size());
    assert(0 <= to && to < sets.size());

    sets[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return sets.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < sets.size());

    std::vector<int> nextVertices;
    for (auto to : sets[vertex]) {
        nextVertices.push_back(to);
    }
    return nextVertices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < sets.size());

    std::vector<int> prevVertices;

    for (auto parent : sets)
        for (auto child : parent)
            if (child == vertex)
                prevVertices.push_back(child);

    return prevVertices;
}