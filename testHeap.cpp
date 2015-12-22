template <typename PQ, typename T> void testHeap( int n ){
T*  A = new T[ 2 * n / 3];//创建容量为2n/3的数组，并且
for (int i = 0; i < 2 * n / 3; i++) A[i] = dice( (T) 3 * n ); //随机化
PQ heap( A + n / 6, n / 3 ; ) delete[] A;
while (heap.size() < n )//随机测试
if (dice(100) < 70) heap.insert(dice( (T) 3 * n));//70%概率插入
else if ( !heap.empty() )heap.delMax();//30%概率删除
while (! heap.empty()) heap.delMax();//清空
}