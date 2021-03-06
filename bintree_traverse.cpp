template <typename T,typename VST>//递归实现，代价巨大
void traverse( BinNodePosi(T) x, VST & visit){
	if ( !x ) return;
	visit ( x-> data );
	traverse( x->lChild, visit );
	traverse( x->rChild, visit );
}//T(n) = O(1)+T(a)+T(n-a-1)=O(n)

//迭代法
template<typename T, typename VST>
void travPre_T1(BinNodePosi(T) x, VST & visit){
	Stack <BinNodePosi(T)> S;//辅助栈
	if (x) S.push(x);//根节点入栈
	while ( !S.empty() ){
		x = S.pop();
		visit( x-> data);
		if ( HasRchild( *x )) S.push( x->rChild );//右子树先入后出
		if ( HasLChild( *x )) S.push( x->LChild );//左子树先出后入


	}
}

//迭代法2
template<typename T, typename VST>
static void visitAlongLeftBrach(
    BinNodePosi(T) x,
    VST & visit,
    Stack <BinNodePosi(T)> & S)
{
	while x {
		visit (x->data);
		S.push(x->rChild);
		x = x->lChild;
	}
}
