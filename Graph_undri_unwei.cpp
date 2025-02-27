#include <iostream>
using namespace std;

typedef struct tagGraph
{
    int Vcnt, Ecnt; // 图的顶点数和边数
    int digraph;    // 是否为有向图
    int *adj;       // 指向邻接矩阵指针
    int *visited;   // 顶点是否被访问过的标志数组
} Graph;

// 基于领接矩阵的无权图
void Initialize(Graph *graph, int V, int digraph)
{
}

int main()
{
    cout << "Hello World" << endl;
    return 0;
}