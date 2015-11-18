//队列的实现
template<typename T> class Queue: public List<T>{
public: //size()和empty()直接沿用
 void enqueue(T const & e) {insertAsLast(e);}
 T dequeue() {return remove(first());}
 R & front() {return first()->data;}
};