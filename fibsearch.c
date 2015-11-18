//fib searche is more efficient than the binary search
//binsearch: lambda=0.5 fibsearch: lambda=0.618
//mean search length: 0.618 is the smallest sequence
template <typename T> //0 <= lo <= hi <= _size
static Rank fibSearch(T* A, T const & e, Rank lo, Rank hi)
{
 Fib fib(hi - lo);
 while (lo < hi)
 {
  while (hi - lo < fib.get()) fib.prev();
  Rank mi = lo + fib.get() - 1;
  if (e < A[mi]) hi = mi;
  else if (A[mi] < e) lo=mi + 1;
  else return mi;
 }
}