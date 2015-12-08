template <typename T>
class Splay : public BST<T> {//由BST派生
 protected: BinNodePosi(T) splay ( BinNodePosi(T) v );//将v伸展至根
 public://伸展树的查找也会引起整树的结构调整，search()需重写
            BinNodePosi(T) & search (const T & e); //查找
            BinNodePosi(T) & insert (const T & e);//插入
            bool remove(const T & e);//删除
};

//
//伸展算法的实现
//
template <typename T> BinNodePosi(T) Splay<T>::splay( BinNodePosi(T) v ) {
if (!v) return NULL; 
BinNodePosi(T) p; BinNodePosi(T) g;//父亲，祖父
while ((p = v->parent) && (g=p->parent)) {//自下而上，反复双层伸展
    BinNodePosi() gg = g->parent;//每轮之后，v就以原曾祖父为父亲
    if (IsLChild(*v))
        if (IsLChild(*p)) 
        {/*zig-zig*/
        attachAsLChild(g, p->rc);
        attachAsLChild(p, v->rc);
        attachAsRChild(p, g);
        attachAsRChild(v, p);
        }
        else
        {/*zig-zag*/
        attachAsRChild(g, v->lChild);
        attachAsLChild(p, v->rChild);
        attachAsLChild(v, g);
        attachAsRChild(v, p);
        }
    else if (IsRChild(*p))
    {/*zag-zag*/
    attachAsRChild(g, p->lc);
    attachAsRChild(p, v->lc);
    attachAsLChild(p, g);
    attachAsLChild(v, p);
    }
    else
    {/*zag-zig*/
    attachAsRChild(p, v->lChild);
    attachAsLChild(g, v->rChild);
    attachAsLChild(v, p);
    attachAsRChild(v, g);
    }
    if (!gg) v->parent = NULL;//若无曾祖父gg，则v现在即为树根；否则，gg此后应以v为左或右孩子
    else (g == gg->lc) ? attachAsLChild(gg, v) : attachAdRChild(gg, v);
    updateHeight(g);
    updateHeight(p);
    updateHeight(v);
}//双伸展结束时，必有g==NULL,但p可能非空
if (p = v->parent) {//p是根的话，只需要至多额外单旋一次
}
v->parent = NULL;
return v;//伸展完成，v抵达树根

//查找算法
//无论成功与否，都会改变树的拓扑结构
//不是静态操作
template <typename T> BinNodePosi(T) & Splay<T>::search( const T & e) {
//调用标准BST的内部接口定位目标节点
BinNodePosi(T) p = searchIn(_root, e, _hot = NULL);
//无论成功与否，最后被访问的节点都将伸展至根
_root = splay(p ? p : _hot);//成功，失败
return _root;//局部性
}

//插入
template <typename T> BinNodePosi(T) & Splay<T>::insert(const T & e) {
BinNodePosi(T) & t= search(e); 
v = new BinNode<T> (e, NULL);
if (e > t->data){
    attachAsRChild(v, t->rChild);
    attachAsLChild(v, t);
    release(t->rChild->data);
    release(t->rChild);
    updateHeight(t);
    updateHeight(v);}
else if (e < t->data){
    attachAsLChild(v, t->lChild);
    attachAsRChild(v, t);
    release(t->lChild->data);
    release(t->lChild);
    updateHeight(t);
    updateHeight(v);}
else
{release(v);
return t;}
return v;
}

//删除
template <typename T> bool Splay<T>::remove(const T & e) {
BinNodePosi(T) & m = NULL;
if (e==NULL) return false;
BinNodePosi(T) & t = search(e);
if (e==t->data) { //found it
    if (t->lChild == NULL){
        m = t->rChild;
    }else {
        m = splay(t->lChild);
        m->rChild = t->rChild;
    }
    updateSize(x);
    release(t);}
return true;
}
