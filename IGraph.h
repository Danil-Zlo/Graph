#pragma once

#include <iostream>
#include <cassert>
#include <functional>
#include <vector>
#include <queue>

struct IGraph {
public:
    virtual ~IGraph() {}

    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

void mainBFS(const IGraph& graph, const std::function<void(int)>& func);
void BFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void(int)>& func);

void mainDFS(const IGraph& graph, const std::function<void(int)>& func);
void DFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void(int)>& func);
