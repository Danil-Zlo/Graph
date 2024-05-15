#pragma once

#include <set>

#include "IGraph.h"

// ListGraph - граф в виде массива хэш-таблиц/сбалансированных деревьев поиска

class SetGraph : public IGraph {
public:
    SetGraph(int size);

    SetGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::set<int>> sets;
};