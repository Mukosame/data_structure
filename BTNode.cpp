template <typename T> struct BTNode{ //B树节点
BTNodePosi(T) parent;
Vector<T> key;//数值向量
Vector< BTNodePosi(T) > child;//孩子向量，其长度总比key多一
BTNode() {parent = NULL; child.insert(0, NULL);}
BTNode( T e, BTNodePosi(T) lc = NULL, BTNodePosi(T) rc = NULL){//生成初始阶数为1的超级节点
    parent = NULL;
    key.insert(0, e);//仅有一个关键码
    child.insert(0, lc);
    child.insert(0, rc);
    if (lc) lc->parent = this;
    if (rc) rc->parent = this;
}

//BTree
#define BTNodePosi(T) BTNode<T>* //B树节点位置
template <typename T> class BTree { //B-树
protected: 
 int _size;//关键码总数
 int _order;//阶次
 BTNodePosi(T) _root;//根
 BTNodePosi(T) _hot;//search()最后访问的非空节点位置
 void solveOverflow( BTNodePosi(T) );//因插入而上溢后的分裂处置
 void solveUnderflow( BTNodePosi(T) );//因删除而下溢后的合并处置
public:
 BTNodePosi(T) search(const T & e);//查找
 BTNodePosi(T) insert(const T & e);//插入
 bool remove(const T & e);//删除
}

template <typename T> BTNodePosi(T) BTree<T>::search( const T & e ) {
BTNode(T) v = _root; _hot = NULL;//从根节点出发
while ( v ){//逐层查找
    Rank r = v->key.search(e);//在当前节点对应的向量中顺序查找
    if ((0 <= r) && (e == v->key[r])) return v;//若成功，则返回v
    _hot = v;
    v = v->child[r+1];//沿着引用转至对应的下层子树，并载入其根I/O
}//若因!v退出，则意味着抵达外层节点
return NULL;//失败
}

//插入
template <typename T> bool BTree<T>::insert(const T & e) {
BTNodePosi(T) v = search(e);
if (v) return false;
Rank r = _hot->key.search(e);//在节点_hot中确定插入位置
_hot->key.insert( r+1, e );//将新关键码插入该位置
_hot->key.insert(r+1, NULL);//创建一个空子树指针
_size++;
solveOverflow(_hot);//如果发生上溢，需要做分裂
return true;
}

//解决上溢
//solve overflow
//当分裂到根时会增加BTree高度
//O(h)
template <typename T> bool BTree<T>::solveOverflow(const BTNodePosi(T) & v) {
if (v->key<) return false;

return true;
}

//删除
template <typename T> 
bool BTree<T>::remove(const T & e) {
    BTNodePosi(T) v = search(e);
    if (!v) return false;
    Rank r = _hot->key.search(e);
    if (v->child[0]) {//若v非叶子，则
        BTNodePosi(T) u = v->child[r+1];//在右子树中一直向左即可
        while (u->child[0]) u = u->child[0];//找到e的后继
        v->key[r] = u->key[0];
        v = u;
        r = 0;//交换位置
    }//至此，v必然位于最底层，且第r个关键码就是待删除者
    v->key.remove(r);
    v->child.remove(r+1);
    _size--;
    solveUnderflow(v);
    return true;
}

//解决下溢
//solve underflow
//优先：左顾右盼；其次：合并
