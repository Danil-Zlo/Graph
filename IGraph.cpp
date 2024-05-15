#include "IGraph.h"

void BFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void(int)>& func)
{
    std::queue<int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty())
    {
        int currentVertex = qu.front();  // Первый элемент очереди
        qu.pop();

        func(currentVertex);

        // Обходим следующие вершины, если они не посещены, то кладём в конец очереди
        for (int nextVertex : graph.GetNextVertices(currentVertex))
        {
            if (!visited[nextVertex])
            {
                visited[nextVertex] = true;
                qu.push(nextVertex);
            }
        }
    }
}

void mainBFS(const IGraph& graph, const std::function<void(int)>& func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        if (!visited[i])
        {
            BFS(graph, i, visited, func);
        }
    }
}

void DFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void(int)>& func)
{
    visited[vertex] = true;
    func(vertex);

    for (int nextVertex : graph.GetNextVertices(vertex))
    {
        if (!visited[nextVertex])
        {
            DFS(graph, nextVertex, visited, func);
        }
    }
}

void mainDFS(const IGraph& graph, const std::function<void(int)>& func)  // принимает int, возвращает void
{
    std::vector<bool> visited(graph.VerticesCount(), false);  // Вектор с элементами false, размерность graph.VerticesCount()

    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        if (!visited[i])
        {
            DFS(graph, i, visited, func);  // graph - вершина, с которой начнём обход
        }
    }
}