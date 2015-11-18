//select Max实现

template <typename T>
Posi(T) List<T>::SelectMax(Posi(T) p, int n)
{
 Posi(T) max = p;
 for (Posi(T) cur = p; 1 < n; n--)//后续节点逐一与max比较
  if (!lt((cur = cur->succ)->data, max->data)) //若 >= max
   max = cur;
  return max;//最大节点位置记录
}