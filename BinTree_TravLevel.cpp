template <typename T> template <typename VST>
void BinNode<T>::travLevel( VST & visit){//��������α���
	Queue<BinNodePosi(T)> Q;
	Q.enqueue( this );//���ڵ����
	while ( !Q.empty() ){
		BinNodePosi(T) x = Q.dequeue();
		visit( x->data );
		if ( HasLChild(*x) )Q.enqueue();
		if ( HasrChild(*x) )Q.enqueue();
	}
}
