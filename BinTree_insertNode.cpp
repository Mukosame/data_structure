template <typename T> BinNodePosi(T)
BinTree<T>::insertAdRc( BinNodePosi(T) x, T const & e){//insertAsLc()�Գ�
	_size++; x->insertAsRc(e);//x���ȵĸ߶ȿ������ӣ�����ڵ��Ȼ����
	updateHeightAbove(x);
	return x->rChild;
}
