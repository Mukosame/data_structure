template <typename T> BinNodePosi(T)
BinTree<T>::insertAdRc( BinNodePosi(T) x, T const & e){//insertAsLc()对称
	_size++; x->insertAsRc(e);//x祖先的高度可能增加，其余节点必然不变
	updateHeightAbove(x);
	return x->rChild;
}
