#include "IGraph.h"

// ListGraph - граф в виде массива списка смежности

struct ListGraph : public IGraph
{
public:
    ListGraph(int size);

    // Конструктор копирования
    ListGraph(const IGraph& graph);

    ~ListGraph() {}

    // Добавление ребра 
    void AddEdge(int from, int to) override;

    // Получить число вершин, размер вектора списка смежности
    int VerticesCount() const override;

    // Получить следующую вершину
    std::vector<int> GetNextVertices(int vertex) const override;

    // Получить предыдущую вершину
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacencyLists;
};