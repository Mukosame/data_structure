//insert
template <typename T> Posi(T) List<T>::insertBefore(Posi(T) p, T const& e)
{_size++; return p->insertAsPred(e);}

template <typename T> //前插入算法
Posi(T) ListNode<T>::insertAsPred(T const& e)
{
 Posi(T) x = new ListNode(e, pred, this);
 pred->succ = x;
 pred = x;
 return x; //创建链接，返回新节点的位置
}


template <typename T>::insertAsLast()//末插入算法，insertBeforeTrailer
{
 return insertAsPred(trailer);
}


template <typename T> //基本接口
void List<T>::copyNodes(Posi(T) p, int n)
{
 init();//创建头尾哨兵节点并且初始化
 while (n--)//将起自p的n项依次作为末节点插入
  {insertAsLast(p->data); p = p->succ;}
}