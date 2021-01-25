#include <iostream>
#include <vector>

#define MaxVertexNum 10
typedef int Vertex; // 用顶点下标表示顶点，为整形
// typedef int WeightType; // 边的权值设为整型
typedef char DataType; //顶点存储的数据类型设为字符型

// 边的定义
// typedef struct ENode *PtrToENode;
typedef struct ENode *Edge;
struct ENode {
  Vertex V1, V2; // 有向边v1，V2
                 // WeightType Weight; // 权重
};
// typedef PtrToENode Edge;

// 图节点的定义
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
  Vertex AdjV; // 邻接点下标
  // WeightType Weight; //边权重
  PtrToAdjVNode Next; //指向下一个
};

// 顶点表头结点的定义
typedef struct Vnode {
  PtrToAdjVNode FirstEdge; // 边表头指针
} AdjList[MaxVertexNum];

//图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode {
  int Nv;    //顶点数
  int Ne;    //边数
  AdjList G; //邻接表
};
typedef PtrToGNode LGragh; //以邻接表方式存储的图类型

LGragh CreateGraph(int VertexNum) { // 初始化一个有VertexNum个顶点，但没有边的图
  Vertex V;
  LGragh Graph = new GNode; //建立图

  Graph->Nv = VertexNum;
  Graph->Ne = 0;
  // 初始化邻接表头指针
  // 默认顶点编号从0开始，到Nv-1
  for (int i = 0; i < Graph->Nv; ++i) {
    Graph->G[i].FirstEdge = nullptr;
  }

  return Graph;
}

void InsertEdge(LGragh &Graph, Edge &E) {
  PtrToAdjVNode NewNode = new AdjVNode;

  // 插入边 v1, V2
  //为v2建立新的邻接点
  NewNode->AdjV = E->V2;
  // NewNode->Weight = E->Weight;

  // 将v2插入v1的表头
  NewNode->Next = Graph->G[E->V1].FirstEdge;
  Graph->G[E->V1].FirstEdge = NewNode;

  // 若是无向图，还要插入边v2，v1
  // 为v1建立新的邻接点
  PtrToAdjVNode NewNodeV2 = new AdjVNode;
  NewNodeV2->AdjV = E->V1;
  // NewNodeV2->Weight = E->Weight;
  // 将v1插入v2的表头
  NewNodeV2->Next = Graph->G[E->V2].FirstEdge;
  Graph->G[E->V2].FirstEdge = NewNodeV2;
}

LGragh BuildGraph(int Nv, int Ne) {
  LGragh Graph;

  for (int i = 0; i < Ne; ++i) {
    Edge E = new ENode;
    std::cin >> E->V1 >> E->V2; //  >> E->Weight;
    InsertEdge(Graph, E);
  }

  return Graph;
}

void Visit(Vertex V) { std::cout << V << " "; }

void DFS(LGragh Graph, Vertex V, std::vector<bool> &visited) {
  Visit(V);          // 访问第v个顶点
  visited[V] = true; // 标记v已访问

  for (auto N = Graph->G[V].FirstEdge;; N = N->Next) {
    if (!visited[N->AdjV])
      DFS(Graph, N->AdjV, visited);
  }
}

int main() {

  std::cout << "hi, the process is running.";
  int Nv, Ne;
  std::cin >> Nv >> Ne;
  LGragh graph = BuildGraph(Nv, Ne);
  std::vector<bool> visited(Nv, false);
  Vertex V{0};

  std::cout << "{ ";
  DFS(graph, V, visited);
  std::cout << "}";
  return 0;
}#include <iostream>
#include <vector>

#define MaxVertexNum 10
typedef int Vertex; // 用顶点下标表示顶点，为整形
// typedef int WeightType; // 边的权值设为整型
typedef char DataType; //顶点存储的数据类型设为字符型

// 边的定义
// typedef struct ENode *PtrToENode;
typedef struct ENode *Edge;
struct ENode {
  Vertex V1, V2; // 有向边v1，V2
                 // WeightType Weight; // 权重
};
// typedef PtrToENode Edge;

// 图节点的定义
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
  Vertex AdjV; // 邻接点下标
  // WeightType Weight; //边权重
  PtrToAdjVNode Next; //指向下一个
};

// 顶点表头结点的定义
typedef struct Vnode {
  PtrToAdjVNode FirstEdge; // 边表头指针
                           // DataType Data; // 存顶点的数据
} AdjList[MaxVertexNum];

//图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode {
  int Nv;    //顶点数
  int Ne;    //边数
  AdjList G; //邻接表
};
typedef PtrToGNode LGragh; //以邻接表方式存储的图类型

LGragh CreateGraph(int VertexNum) { // 初始化一个有VertexNum个顶点，但没有边的图
  Vertex V;
  LGragh Graph = new GNode; //建立图

  Graph->Nv = VertexNum;
  Graph->Ne = 0;
  // 初始化邻接表头指针
  // 默认顶点编号从0开始，到Nv-1
  for (int i = 0; i < Graph->Nv; ++i) {
    Graph->G[i].FirstEdge = nullptr;
  }

  return Graph;
}

void InsertEdge(LGragh &Graph, Edge &E) {
  PtrToAdjVNode NewNode = new AdjVNode;

  // 插入边 v1, V2
  //为v2建立新的邻接点
  NewNode->AdjV = E->V2;
  // NewNode->Weight = E->Weight;

  // 将v2插入v1的表头
  NewNode->Next = Graph->G[E->V1].FirstEdge;
  Graph->G[E->V1].FirstEdge = NewNode;

  // 若是无向图，还要插入边v2，v1
  // 为v1建立新的邻接点
  PtrToAdjVNode NewNodeV2 = new AdjVNode;
  NewNodeV2->AdjV = E->V1;
  // NewNodeV2->Weight = E->Weight;
  // 将v1插入v2的表头
  NewNodeV2->Next = Graph->G[E->V2].FirstEdge;
  Graph->G[E->V2].FirstEdge = NewNodeV2;
}

LGragh BuildGraph(int Nv, int Ne) {
  LGragh Graph;

  for (int i = 0; i < Ne; ++i) {
    Edge E = new ENode;
    std::cin >> E->V1 >> E->V2; //  >> E->Weight;
    InsertEdge(Graph, E);
  }

  return Graph;
}

void Visit(Vertex V) { std::cout << V << " "; }

void DFS(LGragh Graph, Vertex V, std::vector<bool> &visited) {
  Visit(V);          // 访问第v个顶点
  visited[V] = true; // 标记v已访问

  for (auto N = Graph->G[V].FirstEdge;; N = N->Next) {
    if (!visited[N->AdjV])
      DFS(Graph, N->AdjV, visited);
  }
}

int main() {

  std::cout << "hi, the process is running.";
  int Nv, Ne;
  std::cin >> Nv >> Ne;
  LGragh graph = BuildGraph(Nv, Ne);
  std::vector<bool> visited(Nv, false);
  Vertex V{0};

  std::cout << "{ ";
  DFS(graph, V, visited);
  std::cout << "}";
  return 0;
}