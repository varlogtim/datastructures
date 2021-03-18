#include <bits/stdc++.h>

template <class T> class Node {
  public:
    Node(T v);
    ~Node();

    Node<T> *getNext();
    Node<T> *getPrev();
    void setNext(Node<T> *n);
    void setPrev(Node<T> *n);
    T getVal();
    void setVal(T v);

  private:
    T val_;
    Node<T> *next_ = nullptr;
    Node<T> *prev_ = nullptr;
};

// Doubly linked list impl.
template <class T> class LinkedList {
  public:
    LinkedList();
    ~LinkedList();

    void push(T v);
    void pushRight(T v);
    void pushLeft(T v);
    T pop();
    T popRight();
    T popLeft();
    // T peek();
    // T peekRight();
    // T peekLeft();
    // T getIndex();
    // T popIndex();
    uint64_t getLength();
    std::string str();

  private:
    void initFirst(Node<T> *n);
    Node<T> *head_ = nullptr;
    Node<T> *tail_ = nullptr;
    uint64_t numNodes_ = 0;
};
