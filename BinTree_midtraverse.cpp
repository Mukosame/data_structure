template <typename T, typename VST>
void traverse (BinNodePosi(T) x, VST & visit){
	if (!x) return;
	traverse ( x->lChild, visit);
	visit( x -> data);
	traverse( x -> rChild, visit);
}//T(n) = T(a) + O(1) + T( n - a -1) = O(n)

//迭代算法
template <typename T>
static void goAlongLeftBranch( BinNodePosi(T) x, Stack <BinNodePosi(T)> & S)
{while (x) {S.push(x); x = x->lChild;}}

template <typename T, typename V>
void travIn_I1(BinNodePosi(T) x, V & visit){
	Stack <BinNodePosi(T)> S;
	while(true){
		goAlongLeftBranch(x,S);
		if ( S.empty() ) break;//直到所有节点处理完毕
		x = S.pop();
		visit( x->data );
		x = x->rChild;//再转向右子树，没有则进入循环，跳过goAlongB(NUll), 继续弹出下一个节点
}
}
