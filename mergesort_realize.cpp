template <typename T> void Vector<T>::merge(Rank lo, Rank mi, Rank hi)
{
 T* A = _elem + lo;//合并后的向量A[0, hi - lo) = _elem[lo, hi)
 int lb = mi - lo; T* B = new T[lb];//前子向量B[0, lb) = _elem[lo, mi)
 for (Rank i = 0; i < lb; B[i] = A[i++]);//复制前子向量B
 int lc = hi - mi; T* C = _elem + mi;//后子向量C[0, lc) = _elem[mi, hi)
 for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc); )
 {
  if ((j < lb) && ((lc <=k) || (B[j] <= C[k])))
   A[i++] = B[j++];//C[k]已无或不小
  if ((k < lc) && (lb <=j || (C[k] < B[j])))
   A[i++] = C[k++];//B[j]已
 }
 delete [] B; //释放临时空间B
}