template <typename T> class RedBlack : public BST<T> {//红黑树
public: //BST::SEARCH()等其余接口可以直接沿用
 BinNodePosi(T) insert(const T & e);//插入
 bool remove(const T & e);//删除
protected: void solveDoubleRed(BinNodePosi(T) x);//双红修正
           void solveDoubleBlack(BinNodePosi(T) x);//双黑修正
           int updateHeight( BinNodePosi(T) x );//更新节点x的高度
};

template <typename T> int RedBlack<T>::updateHeight( BinNodePosi(T) x ) {
x->height = max (stature(x->lc), stature(x->rc));
if (IsBlack(x)) x->height++;
return x->height;//只计黑节点
}

template <typename T> BinNodePosi(T) RedBlack<T>::insert( const T & e ) {
//确认目标节点不存在
BinNodePosi(T) & x = search( e );
if (x) return x;
//创建红节点x，以_hot为父，黑高度-1
x = new BinNode<T> (e, _hot, NULL, -1);
size++;
//双红修正试试
solveDoubleRed(x);
//返回插入的节点
return x ? x : _hot->parent;
}//无论原树中是否存有e, 返回时总有x->data == e
