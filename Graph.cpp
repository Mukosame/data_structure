template <typename Tv, typename Te> class Graph{//顶点类型、边类型
private:
 void reset(){//所有顶点、边的辅助信息复位
 for (int i = 0; i < n; i++){//顶点
    status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1;
    parent(i) = -1; priority(i) = INT_MAX;	
	for (int j = 0; j < n; j++)//边
	  if (exists(i, j)) status(i, j) = UNDETERMINED;
	}
}
public: //顶点操作，边操作，图算法：无论如何实现，接口必须统一
}//Graph

//Graph::BFS()
template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS( int v, int & clock) {
    Queue<int> Q;
    status(v) = DISCOVERED;
    Q.enqueue(v);//初始化
    while ( !Q.empty() ){
        int v = Q.dequeue();
        dTime(v) = ++clock;//取出队首顶点v，并
        for ( int u = firstNbr(v); -1 < u; u = nextNbr(v, u) )//考察v的每一个邻居u
        { /*分别处理*/
            if ( UNDISCOVERED == status(u) ){
                status(u) = DISCOVERED;
                Q.enqueue(u);//发现该顶点
                type(u, v) = TREE;
                parent(u) = v;//引入树边
            } else //若已经被发现（在队列中），或被访问完毕（出队），则
                type(v, u) = CROSS; //跨边
            status(v) = VISITED;//当前节点访问完毕
        }
    }

    //Graph::bfs
template <typename Tv, typename Te> //顶点类型、边类型
void Graph<Tv, Te>::bfs( int s ){//s为起始顶点
    reset();
    int clock = 0;
    int v = s; //初始化O(n+e)
    do //逐一检查所有顶点，一旦遇到尚未发现的顶点
        if ( UNDISCOVERED == status(v) )//累计O(n)
            BFS(v, clock);//即从该顶点发动一次BFS
    while ( s != (v = (++v%n) ) );
    //按序列号访问，不重不漏
}

template <typename Tv, typename Te>//顶点类型，边类型
void Graph<Tv, Te>::DFS(int v, int & clock) {
    dTime(v) = ++clock;
    status(v) = DISCOVERED;//发现当前顶点v
    for ( int u = firstNbr(v); -1 < u; u = nextNbr(v, u) )//枚举v的每一个邻居u
        //视u的状态分别处理
        //与BFS不同，含有递归
        switch (status(u) ){
            case UNDISCOVERED: //尚未被发现，即支撑树可以在此扩展
                type(v, u) = TREE;
                parent(u) = v;
                DFS(u, clock);//递归
                break;
            case DISCOVERED://u被发现但是尚未被访问完毕，应属于被后代指向的祖先
                type(v, u) = BACKWARD;
                break;
            case VISITED://u已访问完毕(VISITED, 有向图)，则视承袭关系分为前向边或跨边
                type (v, u) = dTime(v) < dTime(u) ? FORWARD :CROSS;
                break;
        }//switch
    status(v) = VISITED;
    fTime(v) = ++clock;
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s){//s为起始顶点
    reset();
    int clock = 0;
    int v= s;//初始化
    do //逐一检查所有顶点，一旦遇到尚未发现的顶点
        if ( UNDISCOVERED == status(v) )
            DFS(v, clock);//即从该点出发启动一次DFS
        while (S != ( v = (++v % n) ) );//按序号访问，不重不漏
}
