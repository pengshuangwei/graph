/*
* �������ͣ�ͼ
* ���ݶ��󼯺ϣ�G(V,E),��һ���ǿյ����޶��㼯��V��һ�����ޱ߼���E���
* �������ϣ���������ͼG����Graph���Լ�v-V,e-E
*/
//��Ҫ����
Graph Create();//������ͼ������
Graph InsertEdge(Graph G, Edge e);// �����ޱ߼�����G
Graph InsertVertex(Graph G, Vertex v);//�����޶��㼯����G
void DFS(Graph G, Vertex v);//�Ӷ���v����������ȱ���ͼG
void BFS(Graph G, Vertex v);//�Ӷ���v����������ȱ���ͼG
void ShortestPath(Graph G, Vertex V, int Dist[]);
//����ͼG�ж���v�����������������̾��룻
void MST(Graph G);//����ͼG����С������
//ͼ���ڽӱ�ʾ��

#define MaxVertexnum 100//��󶥵���
typedef int Vertex;//�ö����±꣬Ϊ����
typedef int WeightType;//�ߵ�Ȩ��
typedef char DataType;//����洢����������Ϊ�ַ���//
//�ߵĶ���
typedef struct ENode* PtrToAdjNode;
struct ENode {
	Vertex V1.V2;//�����<V1,V2>
	WeightType Weight;//Ȩ��
};
typedef PtrToENode Edge;
//�ڽӵ�Ķ���
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex Adjv;//�ڽӵ��±�
	WeightType Weight;//��Ȩ��
	PtrToAdjVNode Next;//ָ����һ���ڽӵ��ָ��
};
//�����ͷ���Ķ���
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;//�߱�ͷָ��
	DataType Data;//�洢���������
	//�ܶ�����£���ͷ���洢����
}AdjList[MaxVertexnum];
//ͼ���Ķ���
typedef  struct GNode* PtrToGNode;
struct GNode {
	int Nv;//������
	int Ne;//����
	AdjList G;//�ڽӱ�
};
typedef PtrToGNode LGraph;//���ڽӱ�ķ�ʽ�洢��ͼ����

LGraph CreateGraph(int VertexNum) {
	//��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
	Vertex V;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNode));//����ͼ
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//��ʼ���ڽӵ�ָ��
	//Ĭ�϶����Ŵ�0��ʼ������Graph->Ne-1)
	for (V = 0; V < Graph->Ne; V++) {
		Graph->G[V].FirstEdge = NULL;
	}
	return Graph;
}
void InsertEdge(LGraph, Edge E) {
	PtrToAdjVNode NewNode;
	//����ߡ�V1��V2��
	NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
	NewNode->Adjv = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
	//��Ϊ����ͼ����Ҫ����<V2,V1>
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

	scanf_s("%d", &Nv);//���붥�����
	Graph = CreateGraph(Nv);//��ʼ����Nv�����㵫û�бߵ�ͼ
	scanf_s("%d", &(Graph->Ne));//�������
	if (Graph->Ne != 0) {//����ұ�
		E = (Edge)malloc(sizeof(ENode));//�����߽��
		//����ߣ���ʽ��㡢�յ㡢Ȩ�أ����뵽�ڽӱ�
		for (i = 0; i < Graph->Ne; i++) {
			scanf_s("%d %d %d", &E->V1, &E->V2, &E->weight);
			InsertEdge(Graph, E);
		}
	}
	for (V = 0; V < Graph->Nv; V++) {
		//����ж������ݣ�����
		scanf_s("%c", &(Graph->G[V].Data));
	}
	return Graph;
}

//ͼ���ڽӾ����ʾ
#define MaxVertexNum 100 //��󶥵���
#define INFINITY 65535 //����Ϊ˫�ֽ��޷������������ֵ65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;


//�ߵĶ���
typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2; /* �����<V1, V2> */
	WeightType weight;/* Ȩ�� */
};
typedef PtrToENode Edge;
/*ͼ�ڵ�Ķ���*/
typedef struct GNode* PtrToGNode;
struct GNode {
	int Nv;//������
	int Ne;//����
	WeightType G[MaxVertexNum][MaxVertexNum];//�ڽӾ���
	DataType data[MaxVertexNum];//�洢��������
	//�ܶ�����£����������ݣ�����û��data[]
};
typedef PtrToGNode MGraph;//�ڽ�Ӿ���洢��ͼ����

MGraph CreateGraph(int VertexNum) {
	//����һ��ͼ,�н��û�б�
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));//����ͼ
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//��ʼ���ڽӾ���
	 /* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++) {
		for (W = 0; W < Graph->Nv; W++) {
			Graph->G[V][W] = INFINITY;
		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	//�����<V1,V2>
	Graph->G[E->V1][E->V2] = E->weight;
	//��������ͼ����Ҫ�����<V2, V1> 
	Graph->G[E->V2][E->V1] = E->weight;
}
MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf_s("%d", &Nv);//���붥�����
	Graph = CreateGraph(Nv);//��ʼ����Nv�����㵫û�бߵ�ͼ
	if (Graph->Ne != 0) {
		//����б�
		E = (Edge)malloc(sizeof(struct ENode));
		//�����߽��
		for (i = 0; i < Graph->Ne; i++) {
			scanf_s("%d %d %d", &E->V1, &E->V2, &E->weight);
			//����ߣ���ʽΪ��㡢�յ㡢Ȩ�أ�
			InsertEdge(Graph, E);
			//�����ڽӾ���
		}
	}
	for (V = 0; V < Graph->Nv; i++) {
		scanf_s("%c", $(Graph->Data[V]));
		//���붥�����ݣ�
	}
	return Graph;
}