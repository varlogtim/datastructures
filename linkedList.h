#include <bits/stdc++.h>

class Node {
  public:
    Node(int v) {
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
    int getVal() {
        return _val;
    };
    void setVal(int v) {
        _val = v;
    };
  private:
    int _val;
    Node *_next = nullptr;
    Node *_prev = nullptr;
};


// Doubly linked list impl.
class LinkedList 
{
  public:
    LinkedList();
    ~LinkedList() {
        Node *node = _head;
        Node *curNode = node;
        while(node->getNext() != nullptr) {
            node = curNode->getNext();
            delete curNode;
            _numNodes--;  // debug
        }
    };
    void push(int v);
    void pushRight(int v);
    void pushLeft(int v);
    int pop();
    int popRight();
    int popLeft();
    uint64_t getLength();
    std::string str();
  private:
    void initFirst(Node *n);
    Node *_head = nullptr;
    Node *_tail = nullptr;
    uint64_t _numNodes = 0;
};
