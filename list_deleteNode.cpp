//delete node and return to p->data
template <typename T>
T List<T>::remove(Poso(T) p)//O(1)
{
 T e = p->data;//备份数值
 p->pred->succ = p->succ;
 p->succ-pred = p->pred;//这两个操作都是直接跳过了p，将p和原来列表进行拓扑隔离
 delete p;
 _size--;
 return e;//返回备份数值
}
