//advanced bubble sort
//old version
template <typename T> void Vector <T>::bubbleSort (Rank lo, Rank hi)
{while (lo< (hi = bubble(lo, hi))); }
//new version
template <typename T> Rank Vector<T>::bubble(Rank lo, Rank hi)
{
 Rank last = lo;
 while (++lo < hi)
  if (_elem[lo - 1] > _elem[lo])
  {
   last = lo;
   swap(_elem[lo - 1], _elem[lo]);
  }
  return last;//flag!
}