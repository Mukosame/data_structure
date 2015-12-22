//method 1
int match( char *P, char * T) {
	size_t n = strlen(T), i = 0;
	size_t m = strlen(P), j = 0;
	while (j < m && i < n)//自左向右逐个对比字符
	if ( T[i] == P[j] ) {i++; j++;}//若匹配，转到下一个字符
	else  {i -= j-1; j = 0;}//否则，T回退，P复位
	return i - j;
}

//method 2
int match(char * P, char * T ) {
	size_t n = strlen(T), i = 0;//T[i]与P[0]对齐
	size_t m = strlen(P), j;//T[i+j]与P[j]对齐
	for ( i = 0; i < n - m + 1; i++ ) {
		for (j = 0; j < m; j++)//P中对应的字符逐个比对
		if (T[i+j] != P[j]) break;//若失配，P整体右移一个字符，重新比对
		if (m <= j ) break;//找到匹配子串
	}
	return i；
}

//KMP
int match (char * P, char * T) {
	int * next = buildNext(P);//构造next表
	int n = (int) strlen(T), i = 0;//文本串指针
	int m = (int) strlen(P), j = 0;//模式串指针
	while (j<m && i<n)//从左向右，逐个比对字符
	if (0>j || T[i] == P[j]) {//若匹配
	i ++; j++;	
	}
	else //否则，P右移，T不回退
	j = next[j];
	delete [] next;//释放next表
	return i - j;
}