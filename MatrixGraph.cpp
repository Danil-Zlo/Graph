#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int size) : matrix(size) {
    for (int i = 0; i < size; ++i) {
        matrix[i].resize(size);
        for (int j = 0; j < size; ++j)
            matrix[i][j] = 0;
    }
}

// Конструктор копирования
MatrixGraph::MatrixGraph(const IGraph& graph) : matrix(graph.VerticesCount()) {
    int size = graph.VerticesCount();
    for (int i = 0; i < size; ++i) {
        matrix[i].resize(size);
        for (int to : graph.GetNextVertices(i)) {
            matrix[i][to] = 1;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < matrix.size());
    assert(0 <= to && to < matrix.size());
    matrix[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < matrix.size());
    std::vector<int> nextVertices;
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[vertex][i])
            nextVertices.push_back(i);
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < matrix.size());
    std::vector<int> prevVertices;
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][vertex])
            prevVertices.push_back(i);
    }
    return prevVertices;
}