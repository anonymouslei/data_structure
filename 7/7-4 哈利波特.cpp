//
// Created by lei on 18.11.20.
//

#include <climits>
#include <iostream>
#include <vector>

#define MaxVertexNum 100
#define INFINITY 65535 // 无穷设为双字节无符号数的最大值65535
typedef int Vertex;    // 用顶点下标表示顶点，为整形
typedef int WeightType;// 边的权值设为整形

// 边的定义
typedef struct ENode *PtrToENode;
struct ENode {
    Vertex startVertex_, endVertex_;// 有向边, 我们使用无向边就够了
    WeightType weight_;
};
typedef PtrToENode Edge;

// 图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv_;// 顶点数
    int Ne_;// 边数

    std::vector<std::vector<WeightType>> G_;
    // WeightType G[MaxVertexNum][MaxVertexNum]; // 邻接矩阵, error，用vector做邻接矩阵
};
typedef PtrToGNode MGraph;//以邻接矩阵存储的图类型

class Floyd {
public:
    Floyd(MGraph graph);
    bool run();
    Vertex getShortestWeight(Vertex startV, Vertex endV);
    void outputAnimal();
    WeightType findMaxDis(Vertex vertex);

private:
    MGraph graph_;
    std::vector<std::vector<WeightType>> D_;
};

bool Floyd::run() {
    for (int k = 0; k < graph_->Nv_; ++k) {
        for (int i = 0; i < graph_->Nv_; ++i) {
            for (int j = 0; j < graph_->Nv_; ++j) {
                if (D_[i][k] + D_[k][j] < D_[i][j]) {
                    D_[i][j] = D_[i][k] + D_[k][j];
                    if (i == j && D_[i][j] < 0)
                        return false;
                }
            }
        }
    }
    return true;
}


Floyd::Floyd(MGraph graph) : graph_(graph) {
    D_ = std::vector<std::vector<WeightType>>(graph_->Nv_, std::vector<WeightType>(graph_->Nv_, -1));

    for (int i = 0; i < graph_->Nv_; ++i)
        for (int j = 0; j < graph_->Nv_; ++j) {
            if (i == j)
                D_[i][j] = 0;
            else
                D_[i][j] = graph_->G_[i][j];
        }
}

Vertex Floyd::getShortestWeight(Vertex startV, Vertex endV) {
    return D_[startV][endV];
}

void Floyd::outputAnimal() {
    Vertex animal;
    WeightType minDistance = INFINITY;

    for (int i = 0; i < graph_->Nv_; ++i) {
        WeightType distance = findMaxDis(i);
        if (distance == INFINITY) {
            std::cout << "0" << std::endl;
            return;
        }

        if (distance < minDistance) {
            minDistance = distance;
            animal = i;
        }
    }

    std::cout << animal + 1 << " " << minDistance << std::endl;
}

WeightType Floyd::findMaxDis(Vertex vertex) {
    auto weightOfVertex = D_[vertex];
    WeightType maxWeight = 0;
    for (auto weight : weightOfVertex) {
        if (weight > maxWeight)
            maxWeight = weight;
    }
    return maxWeight;
}

class NeighborhoodMatrixGraph {
public:
    NeighborhoodMatrixGraph(int Nv, int Ne);
    // MGraph createGraph(int VertexNum);
    std::vector<ENode> readData(int Nv, int Ne);
    void insertEdge(ENode E);
    MGraph buildGraph(std::vector<ENode> inputDataFromCon);

private:
    MGraph graph_;
    int Nv_;
    int Ne_;
    // int numOfVertex_;
};

NeighborhoodMatrixGraph::NeighborhoodMatrixGraph(int Nv, int Ne) : Nv_(Nv), Ne_(Ne) {
    // 初始化一个有VertexNum个顶点但没有边的图
    graph_ = new GNode;
    graph_->Nv_ = Nv;
    graph_->Ne_ = Ne;

    // 初始化邻接矩阵
    // 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1)
    graph_->G_ = std::vector<std::vector<WeightType>>(Nv, std::vector<WeightType>(Nv, INFINITY));
}

std::vector<ENode> NeighborhoodMatrixGraph::readData(int Nv, int Ne) {
    std::vector<ENode> inputDataFromCon;

    for (int i = 0; i < Ne_; ++i) {
        Vertex startVertex, endVertex;
        WeightType weight;
        std::cin >> startVertex >> endVertex >> weight;
        inputDataFromCon.push_back(ENode{startVertex, endVertex, weight});
    }

    return inputDataFromCon;
}

void NeighborhoodMatrixGraph::insertEdge(ENode E) {
    // 插入边 <V1, V2>
    graph_->G_[E.startVertex_ - 1][E.endVertex_ - 1] = E.weight_;
    graph_->G_[E.endVertex_ - 1][E.startVertex_ - 1] = E.weight_;
}

MGraph NeighborhoodMatrixGraph::buildGraph(std::vector<ENode> inputDataFromCon) {
    if (graph_->Ne_ != 0)// 如果有边
    {
        //        E = new ENode;
        //        ENode E;
        // 读入边，格式为“起点，终点，权重”，插入邻接矩阵
        for (ENode inputitem : inputDataFromCon) {
            insertEdge(inputitem);
        }
    }

    return graph_;
}

int main()
{
    int Nv, Ne;
    std::cin >> Nv >> Ne;
    NeighborhoodMatrixGraph test(Nv, Ne);
    std::vector<ENode> inputData = test.readData(Nv, Ne);
    MGraph testGraph = test.buildGraph(inputData);
    
    Floyd testFloyd(testGraph);
    testFloyd.run();
    testFloyd.outputAnimal();
}