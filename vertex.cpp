typedef enum { UNDISCOVERED, DISCOVERED, VISITED} Vstatus;

template <typename Tv> struct Vertex{//顶点对象，未严格封装
  Tv data;
  int inDegree, outDegree;
  VStatus status;//以上三种状态定义
  int dTime, fTime;//时间标签
  int parent;//遍历树中的父节点
  int priority; //遍历树中的优先级
  
  Vertex (Tv const & d): //构造新节点
      data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
      dTime(-1), fTime(-1), parent(-1), priority(INT_MAX) {}
};

typedef 
  enum {UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD}
  EType;

template <typename Te> struct Edge {//边对象：没有被严格封装
  Te data;//数据
  int weight;//权重
  EType type;//在遍历树中的类型
  
  Edge(Te const & d, int w)://构造新边
      data(d), weight(w), type(UNDETERMINED) {}
};

template <typename Tv, typename Te> class GraphMatrix: public Graph<Tv, Te> {
  private:
   Vector< Vertex<Tv> >V; //顶点集
   Vector< Vector< Edge<Te>* > > E;//边集
  public:
   /*操作接口：顶点相关，边相关*/
   GraphMatrix() {n=e=0;}
   ~GraphMatrix() {
       for (int j = 0; j < n; j++)
           for (int k = 0; k < n; k++)
               delete E[j][k]; //清除所有动态申请的边记录
   }
};

//顶点操作
Tv & vertex(int i) {return V[i].data;}//数据
int inDegree(int i) {return V[i].inDegree;}//入度
int outDegree(int i) {return V[i].outDegree};//出度
VStatus & status(int i) {return V[i].status;}//状态
int & dTime(int i) {return V[i].dTime;}//时间标签dTime
int & fTime(int i) {return V[i].fTime;}//时间标签fTime
int & parent(int i) {return V[i].parent;}//在遍历树中的父亲
int & priority (int i) {return V[i].priority;}//优先函数

int nextNbr( int i, int j ){//若已枚举至邻居j，则转向下一邻居
    while ( (-1 < j) && !exists(i, --j) );//逆向顺序查找,O(n)
    return j;
}//改用邻接表可提高至O(1+outDegree(i) )

int firstNbr( int i ){
    return nextNbr( i, n );//假想哨兵
}//首个邻居

//边操作
bool exists (int j, int j){//判断边(i, j)是否存在
    return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != NULL;
}

Te & edge (int i, int j)//边(i, j)的数据
{return E[i][j]->data;}//O(1)

EType & type(int i; int j)//边(i, j)的类型
{return E[i][j]->type;}//O(1)

int & weight (int j; int j)//边(i, j)的权重
{return E[i][j]->weight;}//O(1)

//边插入
void insert (Te const & edge, int w, int i, int j){//插入(i, j, w)
    if (exists(i, j) ) return;//忽略已有边
    E[i][j] = new Edge<Te> (edge, w);//创建新边
    e++;//更新边计数
    V[i].outDegree++;//更新关联点i的出度
    V[j].inDegree++；//更新关联点j的入度
}

//边删除
Te remove(int i, int j){//删除顶点i和j之间的边(exists(i, j))
    Te eBak = edge(i, j);//备份边(i, j)的信息
    delete E[i][j];
    E[i][j] = NULL;
    e--;//更新计数
    V[i].outDegree--;
    V[j].inDegree--;
    return eBak;//返回删除边的信息
}

//顶点插入
int insert(Tv const & vertex) {//插入顶点，返回编号
    for (int j = 0; j < n; j++) E[j].insert(NUll); n++;
    E.insert(Vector< Edge<Te>* > (n, n, NULL) );
    return V.insert( Vertex<Tv>(vertex) );
}

//顶点删除
Tv remove(int i){//删除顶点及其关联边，返回该顶点信息
    for (int j = 0; j < n; j++)//删除所有边 
        if ( exists(i, j) ) {delete E[i][j]; V[j].inDegree--;}
    E.remove(i);
    n--;//删除第n行
    Tv vBak = vertex(i);
    V.remove(i);//备份后删除顶点i
    for (int j = 0; j < n; j++)//删除所有入边及第i列
        if ( Edge<Te> *e = E[j].remove(i) ){delete e; V[j].outDegree--;}
    return vBak;//返回被删除顶点的信息
}
