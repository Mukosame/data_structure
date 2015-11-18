//唯一化
template <typename T> int List<T>::deduplicate()
{
 if (_size < 2) return 0;//平凡列表无重复
 int oldSize = _size;
 Posi(T) p = first(); Rank r=1;//初始，从首节点开始
 while (trailer != (p = p->succ))
 {
  Posi(T) q = find(p->data, r, p);//在p的r个（真）前驱中，查找与之雷同者
  q ? remove(q) : r++;//若确实存在，删除；否则秩递增
 }//assert: 循环过程中的任意时刻，p的所有前驱互不相同
 return oldSize - _Size; //变化量
}