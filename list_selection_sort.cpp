//对列表中起始于位置p的连续n个元素做选择排序，valid(p) && rank(p) + n<= size
template <typename T> void List<T>::selectionSort(Posi(T) p, int n)
Posi(T) head = p->pred;
Posi(T) tail = p;//待排序区间(head, tail)
for (int i = 0, i < n; i++)
 tail = tail->succ; //head tail可能是头尾哨兵
while (1 < n) //反复从非平凡的待排序区间内找出最大者，并移动至有序区间前段
{
 insertBefore (tail, remove(selectMax(head->succ,n)));
 tail = tail->pred;//待排序区间缩进一个
 n--;//少一个要排序的元素啦
}