#define stature(p) ( (p) ? p->height : -1) //定义空树高度为-1

template <typename T>
int BinTree<T>::updateHeight( BinNodePosi(T) x){
	return x->height = 1+
	    max(stature( x->lChild), stature(x->rChild));
}//采用常规二叉树规则,O(1)

template <typename T>//更新v及其历代祖先的高度
void BinTree<T>::updateHeightAbove( BinNodePosi(T) x){
	while (x)
	{updateHeight x; x = x->parent;}
}//O(n = depth(x))

