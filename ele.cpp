template <typename T> T majEleCandidate(Vector<T> A) {
    T maj;//众数候选者
    //线性扫描：借助计数器c，记录maj与其他元素的数量差额
    for (int c = 0, i = 0; i < A.size(); i++)
      if (0 == c){//每当c归零，都意味着此时的前缀P可以剪除
          maj = A[i]; c = 1; //众数候选者改为新的当前元素
      } else 
        maj == A[i] ? c++ : c--;//更新差额计数器
    return maj;
} 

//归并向量的中位数
//等长子向量：实现
template <typename T> //尾递归，可改写为迭代形式
T median(Vector<T> & S1, int lo1, Vector<T> & S2, int lo2, int n) {
    if (n < 3) return trivialMedian(S1, lo1, n, S2, lo2, n);//递归基
    int mi1 = lo1 + n/2, mi2 = lo2 + (n-1)/2;//长度减半
    if (S1[mi1] < S2[mi2])//取S1右半，S2左半
      return median(S1, mi1, S2, lo2, n + lo1 - mi1);
    else if (S1[mi1] > S2[mi2]) //取S1左半、S2右半
      return median(S1, lo1, S2, mi2, n + lo2 - mi2);
    else  
      return S1[mi1];   
}

template <typename T>
T median ( Vector<T> & S1, int lo1, int n1, Vector<T> & S2, int lo2, int n2){
    if (n1 > n2)
      return median (S2, lo2, n2, S1, lo1, n1);//确保n1 <= n2
    if (n2 < 6)
      return trivialMedian(S1, lo1, n1, S2, lo2, n2);//递归基
    if (2 * n1 < n2)
      return median(S1, lo1, n1, S2, lo2 + (n2 - n2 - 1)/2, n1+2-(n2-n1)%2);
    int mi1 = lo1 + n1/2, mi2a = lo2 + (n1 - 1)/2, mi2b = lo2 + n2 - 1 - n1/2;
    if (S1[mi1] > S2[mi2b])//取S1左半、S2右半
      return median(S1, lo1, n1 / 2 + 1, mi2a, n2 - (n1 - 1) / 2);
    else if (S1[mi1] < S2[mi2a])//取S1右半，S2左半
      return median(S1, mi1, (n1 + 1) / 2, S2, lo2, n2 - n1 / 2);
    else //S1保留，S2左右同时缩短
      return median(S1, lo1, n1, S2, mi2a, n2 - (n1 - 1) / 2 * 2);
}//O(log min(n1, n2))

//quickSelect()
template <typename T> void quickSelect(Vector<T> & A, Rank k){
    for (Rank lo = 0, hi = A.size() - 1; lo < hi; ){
        Rank i = lo, j = hi; T pivot = A[lo];
        while (i < j){
            //O(hi - lo + 1) = O(n)
            while (i < j && pivot <= A[j] ) j--; A[i] = A[j];
            while (i < j && A[i] <= pivot ) i++; A[j] = A[i];
        }//assert: i == j
        A[i] = pivot;
        if ( k <= i) hi = i - 1;
        if (i <= k) lo = i + 1;
    }//A[k] is now a pivot
}

//LineSelect()
