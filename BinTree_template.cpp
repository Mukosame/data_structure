template <typename T> class BinTree{
protected:
 int _size;//��ģ
 BinNodePosi(T) _root;//���ڵ�
 virtual int updateHeight( BinNodePosi(T) x);//���½ڵ�x�ĸ߶ȣ�����Ϊvirtual������д
 void updateHeightAbove( BinNodePosi(T) x);//����x�����ȵĸ߶�
public:
 int size() const {return _size;}
 bool empty() const {return !_root;}
 BinNodePosi(T) root() const {return _root;}//����
}
