#include <iostream>

#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "ArcGraph.h"
#include "SetGraph.h"


int main() {
    ListGraph listGraph(7);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);

    std::cout << "List Graph. BFS" << std::endl;
    mainBFS(listGraph, [](int vertex) { std::cout << vertex << " "; });  // Лямбда функция, принимает вершины и выводит их
    std::cout << std::endl;

    std::cout << "List Graph. DFS" << std::endl;
    mainDFS(listGraph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl << std::endl;
    
    
    MatrixGraph matrixGraph = listGraph;

    std::cout << "Matrix Graph. BFS" << std::endl;
    mainBFS(matrixGraph, [](int vertex) { std::cout << vertex << " "; });  // Лямбда функция, принимает вершины и выводит их
    std::cout << std::endl;

    std::cout << "Matrix Graph. DFS" << std::endl;
    mainDFS(matrixGraph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl << std::endl;


    ArcGraph arcGraph = matrixGraph;

    std::cout << "Arc Graph. BFS" << std::endl;
    mainBFS(arcGraph, [](int vertex) { std::cout << vertex << " "; });  // Лямбда функция, принимает вершины и выводит их
    std::cout << std::endl;

    std::cout << "Arc Graph. DFS" << std::endl;
    mainDFS(arcGraph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl << std::endl;


    SetGraph setGraph = arcGraph;
    
    std::cout << "Set Graph. BFS" << std::endl;
    mainBFS(setGraph, [](int vertex) { std::cout << vertex << " "; });  // Лямбда функция, принимает вершины и выводит их
    std::cout << std::endl;
    
    std::cout << "Set Graph. DFS" << std::endl;
    mainDFS(setGraph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl << std::endl;

    return 0;
}