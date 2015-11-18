template <typename T> class BinTree{
protected:
 int _size;//规模
 BinNodePosi(T) _root;//根节点
 virtual int updateHeight( BinNodePosi(T) x);//更新节点x的高度，定义为virtual方便重写
 void updateHeightAbove( BinNodePosi(T) x);//更新x及祖先的高度
public:
 int size() const {return _size;}
 bool empty() const {return !_root;}
 BinNodePosi(T) root() const {return _root;}//树根
}
