//对列表中起始于位置p连续n个元素做插入排序,valid(p) && rank(p) + n <=size
template<typename T> void List<T>::insertionSort(Posi(T) p, int n)
{
 for (int r = 0; r < n; r++)
 {
   insertAfter( search(p->data, r, p),p->data);//查找，插入
   p = p->succ; remove(p->pred);//转向下一节点
 }//n次迭代，每次O(r+1)
}//辅助空间O(1)