//advanced bin search
template <typename T> static Rank binSearch (T* A, T const & e, Rank lo, Rank hi)
{
 while (1 < hi -lo)
 {
  Rank mi = (lo + hi) >> 1;
  (e < A[mi]) ? hi = mi : lo = mi;//[lo, mi) or [mi, hi)
  // lo = mi + 1; // (mi, hi)
 }//exit when hi = lo +1, get the one element
 return (e == A[lo]) ? lo : -1;
}