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
