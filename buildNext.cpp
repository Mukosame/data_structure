int * buildNext(char * P){
    //构造模式串P的next[]表
    size_t m = strlen(P), j = 0;//‘主‘串指针
    int t = N[0] = -1;//模式串指针（P[-1]通配符）
    while (j < m - 1)
     if (0 > t || P[j] == P[t] )//匹配
      N[++j] = ++t;
     else //失配，滑动
      t = N[t];
    return N;
}

//改进
int * buildNext(char * P) {
    size_t m = strlen(P), j = 0;//“主”串指针
    int * N = new int [m];//next表
    int t = N[0] = -1; //模式串指针 
    while (j < m - 1)
     if (0 > t || P[j] == P[t]){
         //匹配
         j++; t++; N[j] = P[j] != P[t] ? t :N[t];
     }
     else //失配 
      t = N[t];
    return N;
}