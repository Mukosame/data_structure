#define Posi(T) ListNode<T>*
template <typename T>
struct ListNode
{
 T data;//数值
 Posi(T) pred;
 Posi(T) succ;
 ListNode() {} //针对header和trailer的构造
 ListNode (T e, Posi(T) p = NULL, Posi(T) s = NULL)
  :data(e), pred(p), succ(s) {} //默认构造器
 Posi(T) insertAsPred (T const& e);
 Posi(T) insertAsSucc (T const& e);
};