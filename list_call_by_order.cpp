template <typename T> //assert:0 <= r < size
T List<T>::operator[](Rank r) const { 
 Posi(T) p = first();
 while (0 < r--) p = p->succ;
 return p->data;
}

