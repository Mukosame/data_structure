template <typename K, typename V> struct Entry{//词条模板类
 K key; V value;
 Entry( K k = K(), V v = V() ): key(k), value(v) {};//默认构造函数
 Entry( Entry<K, V> const & e ): key(e.key), value(e.value) {};//克隆

 //比较器、判等器
 //从此不必严格区分词条及其对应的关键码
 bool operator< ( Entry<K, V> const & e ) {return key < e.key; }
 bool operator> ( Entry<K, V> const & e ) {return key > e.key; }
 bool operator == ( Entry<K, V> const & e ) {return key == e.key; }
 bool operator != ( Entry<K, V> const & e ) {return key != e.key; }
};

template <typename T> class BST: public BinTree<T>{//由Binary Tree派生
public://以virtual修饰，以便派生类重写
 virtual BinNodePosi(T) & search(const T &);//search
 virtual BinNodePosi(T) insert(const T &);//insert
 virtual bool remove(const T &);//remove

protected:
 BinNodePosi(T) _hot;//命中节点的父亲
 BinNodePosi(T) connect34( //3+4重构
     BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
     BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
 BinNodePosi(T) rotateAt( BinNodePosi(T) );//旋转调整

 
//BST::查找
//hot对应语义：
//查找成功时：返回一个关键码为e且真实存在的节点：命中返回节点的parent
//失败时：指向最后一次试图转向的空节点NULL
//可以在尾部设置哨兵节点，且其值=查找失败时最后一个节点。则返回值为最后一个节点l/rChild引用
template <typename T>BinNodePosi(T) & BST<T>::search(const T & e)
{return searchIn( _root, e, _hot = NULL);}//hot被初始化为NULL

static BinNodePosi(T) & searchIn(//典型的尾递归
    BinNodePosi(T) & v,//当前（子）树根
    const T & e,//目标关键码
    BinNodePosi(T) & hot)//记忆热点
{
    if ( !v || (e == v->data)) return v;//没有子树了， 或者查找到相等结果，即确定失败/成功
    hot = v;//先记下当前（非空）节点，然后进行
    return searchIn( ((e< v->datqa)?v->lChild : v->rChild), e, hot );//选择左/右子树，再次进行查找
}//运行时间正比于返回节点v的深度，不超过树高O(h)

//BST::insert
template<typename T>BinNodePosi(T) & BST<T>::insert(const T & e) {
BinNodePosi(T) & x =search(e);//查找目标
if (!x) {//禁止雷同元素，故仅仅在查找失败时实行插入操作
    x = new BinNode(T) (e, _hot);//在x处创建新节点，以_hot为父亲
    _size++;
    updateHeightAbove( x );//更新全树规模，更新x及其所有parent高度
}
return x;//无论e是否存在于原树中，总有x->data == e
}//对于首个节点插入之类的边界情况，都可正确处置

//BST::REMOVE
template <typename T> bool BST<T>::remove(const T & e){
BinNodePosi(T) & x = search(e);//定位目标节点
if (!x) return false;//确认目标存在
removeAt(x, _hot);//分两大类情况实施删除，更新全树规模
__size--;
updateHeightAbove(_hot);//更新_hot及其所有parent高度
return true;
}//返回值：删除成功与否

template <typename T> static BinNodePosi(T)
removeAt( BinNodePosi (T) & x, BinNodePosi(T) & hot) {
    BinNodePosi(T) w = x;//实际被删除的节点，初值等于x
    BinNodePosi(T) succ = NULL; //实际被删除节点的接替者
    if (! HasLChild(*x) ) succ = x = x->rChild;//左子树为空
    else if (! HasrChild(*x) ) succ = x = x->lChild;//右子树为空
    else {//左右子树并存
        w = w->succ();
        swap(x->data, w->data);//令*x与起后继*w互换数据
        BinNodePosi(T) u = w->parent;//原问题化为：摘除非二度的节点w
        (u == x ? u->rChild : u->lChild) succ = w->rChild;
    }//O(h)
    hot = w->parent;//记录实际被删除节点的parent
    if (succ) succ->parent = hot;//将被删除节点的接替与hot相连
    release( w->data );
    release(w);//释放被删除的节点
    return succ;//返回接替者
}//O(1)

//
//AVL接口
//
#define Balanced(x) \ //理想平衡
    (stature( (x).lChild )==stature( (x).rChild ))

#define BalFac \ //平衡因子
    (stature( (x).lChild ) - stature( (x).rChild ))

#define AvlBalanced(x) \//AVL平衡条件
    ( (-2 < BalFac(x)) && (2 > BalFac(x)) )

template <typename T> class AVL: public BST<T>{//由BST派生
public: //BST::search()等接口，可直接沿用
 BinNode(T) insert( const T & );//插入重写
 bool remove( const T & );//删除重写
};

//AVL插入
template <typename T> BinNodePosi(T) AVL<T>::insert(const T & e) {
BinNodePosi(T) & x = search(e);
if (x)
    return x;//若目标尚不存在
x = new BinNode<T>(e, _hot);
_size++;
BinNodePosi(T) xx = x;//则创建x
//以下从x的父亲出发逐层向上，依次检查各代祖先g
for (BinNodePosi(T) g = x->parent; g; g = g->parent)
    if (!AvlBalanced(*g)){//一旦发现g失衡，则通过调整恢复平衡
        FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
        break;//g复衡后，局部子树高度必然复原，其祖先也复原，调整结束
    }else //否则（在依然平衡的祖先出），只需简单地
        updateHeight(g);//更新高度
return xx;//返回新节点
}//最多只需一次调整

//AVL删除
template <typename T> bool AVL<T>::remove( const T & e ) {
BinNodePosi(T) & x = search(e);
if (!x) return false;//若目标确实存在
removeAt(x, _hot);
size--;//按BST规则删除，然后检查祖先失衡
for ( BinNodePosi(T) g = _hot; g; g = g->parent ) {
    if ( !AvlBalanced(*g) ) //一旦发现g失衡，则通过调整恢复平衡
        g = FromParentTo(*g) = rotateAt( tallerChild(tallerChild(g)) );
    updateHeight(g);//并更新其高度
}//可能需要做O(log(n))次；
//无论是否做过调整，全树高度均可能下降
return true;//删除成功
}

//AVL 3+4重构
template <typename T> BinNodePosi(T) BST<T>::connect34(
BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
BinNodePosi(T) T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3)
{
    a->lChild = T0; if (T0) T0->parent = a;
    a->rChild = T1; if (T1) T1->parent = a; updateHeight(a);
    c->lChild = T2; if (T2) T2->parent = c;
    c->rChild = T3; if (T3) T3->parent = c; updateHeight(c);
    b->lChild = a; a->parent = b;
    b->rChild = c; c->parent = b; updateHeight(b);
    return b;//该子树新的根节点
}

//rotateAt
template<typename T> BinNodePosi(T) BST<T>::rotateAt( BinNodePosi(T) v ){
BinNodePosi(T) p = v->parent, g = p->parent;//父亲、祖父
if (IsLChild(*p))//zig
    if (IsLChild(*v)){//zig-zig
        p->parent = g->parent;//向上连接
        return connect34(v, p, g,
                         v->lChild, v->rChild, p->rChild, g->rChild);
    }else {//zig-zag
        v->parent = g->parent;//向上连接
        return connect34(p, v, g,
                         p->lChild, v->lChild, v->rChild, g->rChild);
    }
    else{/*zag-zig, zag-zag*/}
