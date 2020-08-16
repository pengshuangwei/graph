//邻接表的遍历
void Visit(Vertex V) {
	printf("正在访问结点%d", V);
}
//Visited[]为全局变量，已经初始化为FASLE
void DFS(LGraph Graph, Vertex V, void (*Visit)(Vertex))
{//以V为出发点对邻接表存储的图Graph进行DFS搜索
	PtrToAdjVNode W;
	Visit(V);/* 访问第V个顶点 */
	Visited[V] = true;/* 标记V已访问 */
	for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
		/* 对V的每个邻接点W->AdjV */
		if (!Visited[V->Adjv])/* 若W->AdjV未被访问 */
			DFS(Graph, W->Adjv, Visit); /* 则递归访问之 */
	}
	}
}

/* 邻接矩阵存储的图 - BFS */
/* IsEdge(Graph, V, W)检查<V, W>是否图Graph中的一条边，即W是否V的邻接点。  */
/* 此函数根据图的不同类型要做不同的实现，关键取决于对不存在的边的表示方法。*/
/* 例如对有权图, 如果不存在的边被初始化为INFINITY, 则函数实现如下:         */
bool1 IsEdge(MGraph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINTY ? true ? false;
}
/* Visited[]为全局变量，已经初始化为false */
void BFS(MGraph, Vertex V, void(*Visit)(Vertex))
{ /* 以S为出发点对邻接矩阵存储的图Graph进行BFS搜索 */
	Queue Q;
	Vertex V, W;
	Q = CreateQueue(MaxSize); /* 创建空队列, MaxSize为外部定义的常数 */
	/* 访问顶点S：此处可根据具体访问需要改写 */
	Visit(V,);
	Visited[S][0] = true; /* 标记S已访问 */
	AddQ(Q, S); /* S入队列 */

	while (!IsEmpty(Q)) {
		V = DeleteQ(Q);  /* 弹出V */
		for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
			/* 若W是V的邻接点并且未访问过 */
			if (!Visited[W] && IsEdge(Graph, V, W)) {
				/* 访问顶点W */
				Visit(W);
				Visited[W] = true; /* 标记W已访问 */
				AddQ(Q, W); /* W入队列 */
			}
	} /* while结束*/
}
void BFS(LGraph, Graph, Vertex V,void(*Visit)(Vertex))
{
	PtrToAdjVNode W;
	Queue Q;
	Visit(V);
	Push(Q, V);
	Visited[V] = true;
	while (!Q) {
		W = Pop(Q);
		for (; W->Next; W = W->Next) {
			if (!Visited[W->Adiv])
				Visit(V);
				Push(Q, V);
				Visited[V] = true;
		}
	}
}
void DFS(MGraph Graph,Vertex V,void (*Visit)(Vertex))
{
	Vertex V;
	Visit(V);
	Visited[V] = true;
	for(W=0;W,Graph->Nv;W++){
		 if (!Visited[W] && IsEdge(Graph, V, W)) {
			 Visited(W);
			 Visited[W] = true;
			DFS(Graph, W, Visit);
		}
}

