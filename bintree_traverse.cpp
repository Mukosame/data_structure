template <typename T,typename VST>//�ݹ�ʵ�֣����۾޴�
void traverse( BinNodePosi(T) x, VST & visit){
	if ( !x ) return;
	visit ( x-> data );
	traverse( x->lChild, visit );
	traverse( x->rChild, visit );
}//T(n) = O(1)+T(a)+T(n-a-1)=O(n)

//������
template<typename T, typename VST>
void travPre_T1(BinNodePosi(T) x, VST & visit){
	Stack <BinNodePosi(T)> S;//����ջ
	if (x) S.push(x);//���ڵ���ջ
	while ( !S.empty() ){
		x = S.pop();
		visit( x-> data);
		if ( HasRchild( *x )) S.push( x->rChild );//������������
		if ( HasLChild( *x )) S.push( x->LChild );//�������ȳ�����


	}
}

//������2
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