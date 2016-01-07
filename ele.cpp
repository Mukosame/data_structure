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