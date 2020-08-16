/*
* 数据类型：图
* 数据对象集合：G(V,E),由一个非空的有限顶点集合V和一个有限边集合E组成
* 操作集合：对于任意图G属于Graph，以及v-V,e-E
*/
//主要功能
Graph Create();//建立空图并返回
Graph InsertEdge(Graph G, Edge e);// 将有限边集插入G
Graph InsertVertex(Graph G, Vertex v);//将有限顶点集插入G
void DFS(Graph G, Vertex v);//从顶点v出发深度优先遍历图G
void BFS(Graph G, Vertex v);//从顶点v出发宽度优先遍历图G
void ShortestPath(Graph G, Vertex V, int Dist[]);
//计算图G中顶点v到任意其他顶点的最短距离；
void MST(Graph G);//计算图G的最小生成树
//图的邻接表示法

#define MaxVertexnum 100//最大顶点数
typedef int Vertex;//用顶点下标，为整型
typedef int WeightType;//边得权重
typedef char DataType;//顶点存储的数据类型为字符型//
//边的定义
typedef struct ENode* PtrToAdjNode;
struct ENode {
	Vertex V1.V2;//有向边<V1,V2>
	WeightType Weight;//权重
};
typedef PtrToENode Edge;
//邻接点的定义
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex Adjv;//邻接点下标
	WeightType Weight;//边权重
	PtrToAdjVNode Next;//指向下一个邻接点的指针
};
//顶点表头结点的定义
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;//边表头指针
	DataType Data;//存储顶点的数据
	//很多情况下，表头不存储数据
}AdjList[MaxVertexnum];
//图结点的定义
typedef  struct GNode* PtrToGNode;
struct GNode {
	int Nv;//顶点数
	int Ne;//边数
	AdjList G;//邻接表
};
typedef PtrToGNode LGraph;//以邻接表的方式存储的图类型

LGraph CreateGraph(int VertexNum) {
	//初始化一个有VertexNum个顶点但没有边的图
	Vertex V;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNode));//建立图
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//初始化邻接点指针
	//默认顶点编号从0开始，到（Graph->Ne-1)
	for (V = 0; V < Graph->Ne; V++) {
		Graph->G[V].FirstEdge = NULL;
	}
	return Graph;
}
void InsertEdge(LGraph, Edge E) {
	PtrToAdjVNode NewNode;
	//插入边《V1，V2》
	NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
	NewNode->Adjv = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
	//若为无向图，还要插入<V2,V1>
	NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
	NewNode->Adjv = E->V1;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V2].FirstEdge ;
	Graph->G[E->V2].FirstEdge = NewNode;

}
LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf_s("%d", &Nv);//读入顶点个数
	Graph = CreateGraph(Nv);//初始化有Nv个顶点但没有边的图
	scanf_s("%d", &(Graph->Ne));//读入边数
	if (Graph->Ne != 0) {//如果右边
		E = (Edge)malloc(sizeof(ENode));//建立边结点
		//读入边，格式起点、终点、权重，插入到邻接表；
		for (i = 0; i < Graph->Ne; i++) {
			scanf_s("%d %d %d", &E->V1, &E->V2, &E->weight);
			InsertEdge(Graph, E);
		}
	}
	for (V = 0; V < Graph->Nv; V++) {
		//如果有顶点数据，读入
		scanf_s("%c", &(Graph->G[V].Data));
	}
	return Graph;
}

//图的邻接矩阵表示
#define MaxVertexNum 100 //最大顶点数
#define INFINITY 65535 //∞设为双字节无符号整数的最大值65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;


//边的定义
typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2; /* 有向边<V1, V2> */
	WeightType weight;/* 权重 */
};
typedef PtrToENode Edge;
/*图节点的定义*/
typedef struct GNode* PtrToGNode;
struct GNode {
	int Nv;//顶点数
	int Ne;//边数
	WeightType G[MaxVertexNum][MaxVertexNum];//邻接矩阵
	DataType data[MaxVertexNum];//存储顶点数据
	//很多情况下，顶点无数据，可以没有data[]
};
typedef PtrToGNode MGraph;//邻结接矩阵存储的图类型

MGraph CreateGraph(int VertexNum) {
	//建立一个图,有结点没有边
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));//建立图
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//初始化邻接矩阵
	 /* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++) {
		for (W = 0; W < Graph->Nv; W++) {
			Graph->G[V][W] = INFINITY;
		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	//插入边<V1,V2>
	Graph->G[E->V1][E->V2] = E->weight;
	//若是无向图，还要插入边<V2, V1> 
	Graph->G[E->V2][E->V1] = E->weight;
}
MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf_s("%d", &Nv);//读入顶点个数
	Graph = CreateGraph(Nv);//初始化有Nv个顶点但没有边的图
	if (Graph->Ne != 0) {
		//如果有边
		E = (Edge)malloc(sizeof(struct ENode));
		//建立边结点
		for (i = 0; i < Graph->Ne; i++) {
			scanf_s("%d %d %d", &E->V1, &E->V2, &E->weight);
			//读入边，格式为起点、终点、权重，
			InsertEdge(Graph, E);
			//插入邻接矩阵
		}
	}
	for (V = 0; V < Graph->Nv; i++) {
		scanf_s("%c", $(Graph->Data[V]));
		//插入顶点数据，
	}
	return Graph;
}