#include <bits/stdc++.h>

template <class T>
class Node {
  public:
    Node(T v) {
        _val = v;
    };
    ~Node() {
        // code for linking prev and next
        // link prev node (left)
        if (_prev == nullptr && _next == nullptr) {
            return; // Do nothing, list is one entry
        }
        if (_prev != nullptr) {
            _prev->setNext(_next);
        }
        if (_next != nullptr) {
            _next->setPrev(_prev);
        }
    }
    Node *getNext() {
        return _next;
    }
    Node *getPrev() {
        return _prev;
    }
    void setNext(Node *n) {
        _next = n;
    }
    void setPrev(Node *n) {
        _prev = n;
    }
    T getVal() {
        return _val;
    };
    void setVal(T v) {
        _val = v;
    };
  private:
    T _val;
    Node *_next = nullptr;
    Node *_prev = nullptr;
};


// Doubly linked list impl.
template <class T>
class LinkedList 
{
  public:
    LinkedList();
    ~LinkedList() {
        Node<T> *node = _head;
        Node<T> *curNode = node;
        while(node->getNext() != nullptr) {
            node = curNode->getNext();
            delete curNode;
            _numNodes--;  // debug
        }
    };
    void push(T v);
    void pushRight(T v);
    void pushLeft(T v);
    T pop();
    T popRight();
    T popLeft();
    uint64_t getLength();
    std::string str();
  private:
    void initFirst(Node<T> *n);
    Node<T> *_head = nullptr;
    Node<T> *_tail = nullptr;
    uint64_t _numNodes = 0;
};
