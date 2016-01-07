template <typename T> void Vector<T>::quickSort( Rank lo, Rank hi){
    if (hi - lo <2 ) return ; //平凡解
    Rank mi = partition(lo, hi - 1);//pivot
    quickSort(lo, mi);//前缀排序
    quickSort(mi + 1, hi);//后缀排序
}

template <typename T> Rank Vector<T>::partition(Rank lo, Rank hi){
    swap(_elem[lo], _elem[lo+rand()%(hi - lo + 1)]);//随机交换
    T pivot = _elem[lo];//随机选取候选轴点
    while (lo < hi){
        while (lo < hi && pivot <= _elem[hi]) hi--;//向左扩展G
        _elem[lo] = _elem[hi];//凡小于轴点者，归于L
        while (lo < hi && _elem[lo] <= pivot) lo++;
        _elem[hi] = _elem[lo];//凡大于轴点者，归入G
    }//assert: lo == hi
    _elem[lo] = pivot; //候选轴点归位
    return lo;//返回其rank
}

//微调A1
template <typename T> Rank Vector<T>::partition( Rank lo, Rank hi) {
    swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);
    T pivot = _elem[lo];
    while (lo < hi){
        while (lo < hi && pivot <= _elem[hi]) hi--;
        if (lo < hi) _elem[lo++] = _elem[hi];
        while (lo < hi && _elem[lo] <= pivot) lo++;
        if (lo < hi) _elem[hi--] = _elem[lo];
    }//assert: lo == hi
    _elem[lo] = pivot;
    return lo;
}

//微调B1
template <typename T> Rank Vector<T>::partition(Rank lo, Rank hi){
    swap(_elem[lo], _elem[lo + rand()%(hi - lo + 1)]);
    T pivot = _elem[lo];
    while (lo < hi) {
        while (lo < hi && pivot < _elem[hi]) hi--;
        if (lo < hi) _elem[lo++] = _elem[hi];
        while(lo < hi && _elem[lo] < pivot) lo++;
        if (lo < hi) _elem[hi--] = _elem[lo]; 
    }//assert:lo == hi
    _elem[lo] = pivot;
    return lo;
}

//微调B 
template <typename T> Rank Vector<T>::partition(Rank lo, Rank hi) {
    swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);
    T pivot = _elem[lo];
    while (lo < hi){
        while (lo < hi)
          if (pivot < _elem[hi]) hi--;
          else {_elem[lo++] = _elem[hi];break;}
        while (lo < hi)
          if (_elem[lo] < pivot) lo++;
          else {_elem[hi--] = _elem[lo];break;}
    }//assert: lo == hi 
    _elem[lo] = pivot; return lo;
}

//快排变种：引入mi
template <typename T> Rank Vector<T>::partition(Rank lo, Rank hi){
    swap(_elem[lo], _elem[lo + rand() % (hi - lo +1)]);
    T pivot = _elem[lo]; int mi = lo;
    for (int k = lo + 1; k <= hi; k++)//自左向右考查每个[k]
      if (_elem[k] < pivot)
        swap(_elem[++mi], _elem[k]);
    swap(_elem[lo], _elem[mi]);
    return mi;
}