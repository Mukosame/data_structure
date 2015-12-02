template <typename K, typename V> struct Entry{//词条模板类
 K key; V value;
 Entry( K k = K(), V v = V() ): key(k), value(v) {};//默认构造函数
 Entry( Entry<K, V> const & e ): key(e.key), value(e.value) {};//克隆

 //比较器、判等器
 //从此不必严格区分词条及其对应的关键码
 bool operator< ( Entry<K, V> const & e ) {return key < e.key; }
 bool operator> ( Entry<K, V> const & e ) {return key > e.key; }
 bool operator == ( Entry<K, V> const & e ) {return key == e.key; }
 bool operator != ( Entry<K, V> const & e ) {return key != e.key; }
};

template <typename T> class BST: public BinTree<T>{//由Binary Tree派生
public://以virtual修饰，以便派生类重写
 virtual BinNodePosi(T) & search(const T &);//search
 virtual BinNodePosi(T) insert(const T &);//insert
 virtual bool remove(const T &);//remove

protected:
 BinNodePosi(T) _hot;//命中节点的父亲
 BinNodePosi(T) connect34( //3+4重构
     BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
     BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
 BinNodePosi(T) rotateAt( BinNodePosi(T) );//旋转调整
