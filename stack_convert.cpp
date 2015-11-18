//利用栈进行进制转换
void convert(Stack<char> &S, _int64 n, int base)
{
 static char digit[]= //新进制下的数位符号，可视base范围适当扩充
 {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
 while (n > 0)
 {
  S.push(digit [n % base]);//把余数入栈
  n /= base; //n更新为商
 }
}