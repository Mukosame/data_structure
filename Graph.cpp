template <typename Tv, typename Te> class Graph{//�������͡�������
private:
 void reset(){//���ж��㡢�ߵĸ�����Ϣ��λ
 for (int i = 0; i < n; i++){//����
    status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1;
    parent(i) = -1; priority(i) = INT_MAX;	
	for (int j = 0; j < n; j++)//��
	  if (exists(i, j)) status(i, j) = UNDETERMINED;
	}
}
public: //����������߲�����ͼ�㷨���������ʵ�֣��ӿڱ���ͳһ
}//Graph

//Graph::BFS()
template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS( int v, int & clock) {
    Queue<int> Q;
    status(v) = DISCOVERED;
    Q.enqueue(v);//��ʼ��
    while ( !Q.empty() ){
        int v = Q.dequeue();
        dTime(v) = ++clock;//ȡ�����׶���v����
        for ( int u = firstNbr(v); -1 < u; u = nextNbr(v, u) )//����v��ÿһ���ھ�u
        { /*�ֱ���*/
            if ( UNDISCOVERED == status(u) ){
                status(u) = DISCOVERED;
                Q.enqueue(u);//���ָö���
                type(u, v) = TREE;
                parent(u) = v;//��������
            } else //���Ѿ������֣��ڶ����У����򱻷�����ϣ����ӣ�����
                type(v, u) = CROSS; //���
            status(v) = VISITED;//��ǰ�ڵ�������
        }
    }

    //Graph::bfs
template <typename Tv, typename Te> //�������͡�������
void Graph<Tv, Te>::bfs( int s ){//sΪ��ʼ����
    reset();
    int clock = 0;
    int v = s; //��ʼ��O(n+e)
    do //��һ������ж��㣬һ��������δ���ֵĶ���
        if ( UNDISCOVERED == status(v) )//�ۼ�O(n)
            BFS(v, clock);//���Ӹö��㷢��һ��BFS
    while ( s != (v = (++v%n) ) );
    //�����кŷ��ʣ����ز�©
}

template <typename Tv, typename Te>//�������ͣ�������
void Graph<Tv, Te>::DFS(int v, int & clock) {
    dTime(v) = ++clock;
    status(v) = DISCOVERED;//���ֵ�ǰ����v
    for ( int u = firstNbr(v); -1 < u; u = nextNbr(v, u) )//ö��v��ÿһ���ھ�u
        //��u��״̬�ֱ���
        //��BFS��ͬ�����еݹ�
        switch (status(u) ){
            case UNDISCOVERED: //��δ�����֣���֧���������ڴ���չ
                type(v, u) = TREE;
                parent(u) = v;
                DFS(u, clock);//�ݹ�
                break;
            case DISCOVERED://u�����ֵ�����δ��������ϣ�Ӧ���ڱ����ָ�������
                type(v, u) = BACKWARD;
                break;
            case VISITED://u�ѷ������(VISITED, ����ͼ)�����ӳ�Ϯ��ϵ��Ϊǰ��߻���
                type (v, u) = dTime(v) < dTime(u) ? FORWARD :CROSS;
                break;
        }//switch
    status(v) = VISITED;
    fTime(v) = ++clock;
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s){//sΪ��ʼ����
    reset();
    int clock = 0;
    int v= s;//��ʼ��
    do //��һ������ж��㣬һ��������δ���ֵĶ���
        if ( UNDISCOVERED == status(v) )
            DFS(v, clock);//���Ӹõ��������һ��DFS
        while (S != ( v = (++v % n) ) );//����ŷ��ʣ����ز�©
}
