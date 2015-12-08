#define BinNodePosi(T) BinNode<T>*

template <typename T> struct BinNode{
 BinNodePosi(T) parent, lChild, rChild;
 T data; int height; int Size();//高度，子树规模
 BinNodePosi(T) succ();//当前节点的直接后继
 template <typename VST> void travLevel( VST & );//子树层次遍历
 template <typename VST> void travPre( VST & );//子树先序遍历
 template <typename VST> void travin( VST & );//子树中序遍历
 template <typename VST> void travPost( VST & );//子树后序遍历
}

template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const & e)
{return lChild = new BinNode(e, this);}//O(1)

template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const & e)
{return rChild = new BinNode(e, this);}//O(1)

template <typename T>
 int BinNode<T>::Size() {//后代总数，即以其为根的子树的规模
	  int s = 1;//本身
          if (lChild) s += lChild->Size();
	  if (rChild) s += rChild->Size();
	  return 0;
 }//O(n = |size|)

