template <typename T> template <typename VST>
void BinNode<T>::travLevel( VST & visit){//二叉树层次遍历
	Queue<BinNodePosi(T)> Q;
	Q.enqueue( this );//根节点入队
	while ( !Q.empty() ){
		BinNodePosi(T) x = Q.dequeue();
		visit( x->data );
		if ( HasLChild(*x) )Q.enqueue();
		if ( HasrChild(*x) )Q.enqueue();
	}
}
