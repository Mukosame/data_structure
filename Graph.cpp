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
