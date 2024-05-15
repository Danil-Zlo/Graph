#include "ListGraph.h"

ListGraph::ListGraph(int size) : adjacencyLists(size) {}

ListGraph::ListGraph(const IGraph& graph)
{
    for (int i = 0; i < graph.VerticesCount(); ++i)  // Проходим по всем вершинам
    {
        adjacencyLists[i] = graph.GetNextVertices(i);  // Заполняем список смежности
    }
}

void ListGraph::AddEdge(int from, int to)
{
    assert(0 <= from && from < adjacencyLists.size());
    assert(0 <= to && to < adjacencyLists.size());
    adjacencyLists[from].push_back(to);
}

int ListGraph::VerticesCount() const
{
    return (int)adjacencyLists.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const
{
    assert(0 <= vertex && vertex < adjacencyLists.size());
    return adjacencyLists[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const
{
    assert(0 <= vertex && vertex < adjacencyLists.size());
    std::vector<int> prevVertices;

    for (int from = 0; from < adjacencyLists.size(); ++from)  // Цикл по начальным вершинам
    {
        for (int to : adjacencyLists[from])  // Цикл по конечным вершинам
        {
            if (to == vertex)
                prevVertices.push_back(from);
        }
    }
    return prevVertices;  // Возвращаем то, что смогли собрать
}