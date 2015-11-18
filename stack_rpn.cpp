float evaluate( char* S, char* & RPN) {//RPN转换
while(!optr.empty() ){//处理各个字符，直到运算符栈空
 if( isdigit(*S) )//当前字符为操作数
  {readNumber(S, opnd); append(RPN, opnd.top() );}
 else
  switch (orderBetween()optr.top(), *S )
  {
   case '>': {//且可立即执行，则在执行相应计算同时将其
     char op = optr.pop();
	 append(RPN, op);//接入RPN
  }