//�ڽӱ�ı���
void Visit(Vertex V) {
	printf("���ڷ��ʽ��%d", V);
}
//Visited[]Ϊȫ�ֱ������Ѿ���ʼ��ΪFASLE
void DFS(LGraph Graph, Vertex V, void (*Visit)(Vertex))
{//��VΪ��������ڽӱ�洢��ͼGraph����DFS����
	PtrToAdjVNode W;
	Visit(V);/* ���ʵ�V������ */
	Visited[V] = true;/* ���V�ѷ��� */
	for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
		/* ��V��ÿ���ڽӵ�W->AdjV */
		if (!Visited[V->Adjv])/* ��W->AdjVδ������ */
			DFS(Graph, W->Adjv, Visit); /* ��ݹ����֮ */
	}
	}
}

/* �ڽӾ���洢��ͼ - BFS */
/* IsEdge(Graph, V, W)���<V, W>�Ƿ�ͼGraph�е�һ���ߣ���W�Ƿ�V���ڽӵ㡣  */
/* �˺�������ͼ�Ĳ�ͬ����Ҫ����ͬ��ʵ�֣��ؼ�ȡ���ڶԲ����ڵıߵı�ʾ������*/
/* �������Ȩͼ, ��������ڵı߱���ʼ��ΪINFINITY, ����ʵ������:         */
bool1 IsEdge(MGraph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINTY ? true ? false;
}
/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */
void BFS(MGraph, Vertex V, void(*Visit)(Vertex))
{ /* ��SΪ��������ڽӾ���洢��ͼGraph����BFS���� */
	Queue Q;
	Vertex V, W;
	Q = CreateQueue(MaxSize); /* �����ն���, MaxSizeΪ�ⲿ����ĳ��� */
	/* ���ʶ���S���˴��ɸ��ݾ��������Ҫ��д */
	Visit(V,);
	Visited[S][0] = true; /* ���S�ѷ��� */
	AddQ(Q, S); /* S����� */

	while (!IsEmpty(Q)) {
		V = DeleteQ(Q);  /* ����V */
		for (W = 0; W < Graph->Nv; W++) /* ��ͼ�е�ÿ������W */
			/* ��W��V���ڽӵ㲢��δ���ʹ� */
			if (!Visited[W] && IsEdge(Graph, V, W)) {
				/* ���ʶ���W */
				Visit(W);
				Visited[W] = true; /* ���W�ѷ��� */
				AddQ(Q, W); /* W����� */
			}
	} /* while����*/
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

