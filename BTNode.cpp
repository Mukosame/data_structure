template <typename T> struct BTNode{ //B树节点
BTNodePosi(T) parent;
Vector<T> key;//数值向量
Vector< BTNodePosi(T) > child;//孩子向量，其长度总比key多一
BTNode() {parent = NULL; child.insert(0, NULL);}
BTNode( T e, BTNodePosi(T) lc = NULL, BTNodePosi(T) rc = NULL){
    parent = NULL;
    key.insert(0, e);//仅有一个关键码
    child.insert(0, lc);
    child.insert(0, rc);
    if (lc) lc->parent = this;
    if (rc) rc->parent = this;
}

