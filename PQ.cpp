template <typename T>struct PQ{//priority queue
virtual void insert(T) = 0;//按照优先级次序插入词条
virtual T getMax() = 0; //取出优先级最高的词条
virtual T delMax() = 0;//删除优先级最高的词条
};

template <typename T> T
PQ_ComplHeap<T>::getMax() {return _elem[0];}

template<typename T> void PQ_ComplHeap<T>::insert(T e) //插入
{Vector<T>::insert(e); percolateUp( _size - 1);}

template <typename T>::percolateUp(Rank i) {
	while(ParentValid(i)){//尚未抵达堆顶，则
		Rank j = Parent(i);//将i的父亲记作j
		if (lt(_elem[i], _elem[j])) break;//不再逆序，则上滤完成
		swap(_elem[i], _elem[j]);
		i = j;//否则交换父子位置，且上升一层
	}
	return i;//返回上滤最终抵达的位置
}

template <typename T> T PQ_ComplHeap<T>::delMax(){//删除
	T maxElem = _elem[0];
	_elem[0] = _elem[--_size];//摘除堆顶，代之以末词条
	percolateDown( _size, 0);//对新堆实行下滤
	return maxElem;//返回此前备份的最大词条
}

template <typename T>//对前n个词条中的第i个实施下滤, i < n
 Rank PQ_ComplHeap<T>::percolateDown(Rank n, Rank i) {
	 Rank j;//i及其（至多两个）孩子中，堪为夫者
	 while (i != (j = ProperParent(_elem, n ,i) ) )//只要i非j，则
	 {swap(_elem[i], _elem[j]);
	 i = j;} 
	 return i;
}

template <typename T>
void PQ_ComplHeap<T>::heapify( Rank n ){
	for (int i = LastInternal(n); i >= 0; i-- )//自下而上，依次
	percolateDown(n, i);//下滤各内部节点
}//可理解为子堆的逐层合并

template <typename T> //对向量区间[lo, hi)做就地排序
void Vector<T>::heapSort( Rank lo, Rank hi){
	PQ_ComplHeap<T> H( _elem + lo, hi - lo);//待排序区间建堆，O(n)
	while ( !H.empty() )//反复摘除最大元并归入已排序的后缀，直至堆空
	_elem[--hi] = H.delMax();//等效于堆顶与末元素对换后下滤
}

template <typename T>//基于二叉树，以左堆形式实现的优先级队列
class PQ_LeftHeap : public PQ<T>, public BinTree<T> {
	public: 
	void insert(T) ;//按照比较器确定的优先次序插入元素
	T getMax() {return _root->data;}
	T delMax();//删除优先级最高的元素
};

template <typename T>
static BinNodePosi(T) merge(BinNodePosi(T), BinNodePosi(T));

template <typename T>
static BinNodePosi(T) merge( BinNodePosi(T) a, BinNodePosi(T) b ){
	if (!a) return b;//递归基
	if (!b) return a;//递归基
	if (lt(a->data, b->data)) swap(b, a);//首先确保b不大
	a->rc = merge(a->rc, b);//将a的右子堆与b合并
	a->rc->parent = a;//更新父子关系
	if ( ! a->lc || a->lc->npl < a->rc->npl )//若有必要
	swap (a->lc, a->rc);//交换a的左右子堆，以确保右子堆的npl不大
	a->npl = a->rc ? a->rc->npl + 1 : 1;//更新a的npl
	return a;
}

//insert
template <typename T>
void PQ_LeftHeap<T>::insert(T e){//O(log n)
  BinNodePosi(T) v = new BinNode<T> (e);
  _root = merge(_root, v);//通过合并完成新节点的插入
  _root->parent = NULL;//既然此时堆非空，还需要相应设置父子链接
  _size++;//更新规模
}

//delMax()
template <typename T> PQ_LeftHeap<T>::delMax{//O(log n)
	BinNodePosi(T) lHeap = _root->lc;
	BinNodePosi(T) rHeap = _root->rc;
	T e = _root->data;//备份堆顶处的最大元素
	delete _root;
	_size--;//删除根节点
	_root = merge(lHeap, rHeap);//合并左右子堆
	if (_root) _root->parent=NULL;
	return e; 
}

