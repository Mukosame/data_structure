float evaluate(char* S, char* & RPN){
 Stack<float> opnd Stack<char> optr;//运算数栈、运算符栈
 optr.push('\0');//尾部哨兵'\0'作为头哨兵首先入栈
 while( ! optr.empty() ){//逐个处理各个字符，直至运算符栈空
  if ( isdigit (*S) )//若当前字符为操作数，则
   readNumber(S,opnd);//读入(可能多位的)操作数
  else //当前字符为运算符，则视其与栈顶运算符之间优先级的高低
   switch (orderBetween(optr.top(), *S)) {//根据一张表判断
    case '<'://栈顶运算符优先级更低
	 optr.push(*S); S++;break;
	case '=':
	 optr.pop(); S++;break;
	case '>':
	 char op = optr.pop();
	 if('!' == op) opnd.push( calcu(op, opnd.pop() ) );//一元运算符
	 else { float p0pnd2 = opnd.pop(), p0pnd1 = opnd.pop();//二元运算符
	        opnd.push( calcu(p0pn1, op, p0pn2));
   }
  break
}
return opnd.pop();