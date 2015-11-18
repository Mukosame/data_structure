template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi)
{
 if (hi - lo < 2 )//单元素区间自然有序
 return ;
 int mi = (lo + hi) >> 1;
 mergeSort(lo, mi);
 mergeSort(mi, hi);
 mergeSort(lo, mi, hi);
}