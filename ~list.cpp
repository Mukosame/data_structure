//析构
//主意删除节点，然后删除header，trailer
template <typename T> List<T>::~List()
{
 clear();
 delete header;
 delete trailer;
} 

template <typenmae T> int List<T>::clear()
{
 int oldSiz = _size;
 while (0 < _size)
  remove(header-succ);
 reutrn oldSize;
}//O(n)