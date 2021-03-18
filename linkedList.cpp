#include "linkedList.h"

#include <bits/stdc++.h>

/*
 * Node
 */

template <class T> Node<T>::Node(T v) { val_ = v; }

template <class T> Node<T>::~Node() {
    if (prev_ == nullptr && next_ == nullptr) {
        return; // Do nothing, list is one entry
    }
    if (prev_ != nullptr) {
        prev_->setNext(next_);
    }
    if (next_ != nullptr) {
        next_->setPrev(prev_);
    }
}

template <class T> Node<T> *Node<T>::getNext() { return next_; }

template <class T> Node<T> *Node<T>::getPrev() { return prev_; }

template <class T> void Node<T>::setNext(Node<T> *n) { next_ = n; }

template <class T> void Node<T>::setPrev(Node<T> *n) { prev_ = n; }

template <class T> T Node<T>::getVal() { return val_; };

template <class T> void Node<T>::setVal(T v) { val_ = v; }

/*
 * LinkedList
 */

template <class T> LinkedList<T>::LinkedList() {}

template <class T> LinkedList<T>::~LinkedList() {
    Node<T> *node = head_;
    Node<T> *curNode = node;
    while (node->getNext() != nullptr) {
        node = curNode->getNext();
        delete curNode;
        numNodes_--; // debug
    }
}

template <class T> void LinkedList<T>::initFirst(Node<T> *n) {
    head_ = n;
    tail_ = n;
}

template <class T> void LinkedList<T>::push(T v) {
    LinkedList<T>::pushRight(v);
}

template <class T> void LinkedList<T>::pushRight(T v) {
    Node<T> *node = new Node<T>(v);
    if (numNodes_ != 0) {
        tail_->setNext(node);
        node->setPrev(tail_);
        tail_ = node;
    } else {
        initFirst(node);
    }
    numNodes_++;
}

template <class T> void LinkedList<T>::pushLeft(T v) {
    Node<T> *node = new Node<T>(v);
    if (numNodes_ != 0) {
        head_->setPrev(node);
        node->setNext(head_);
        head_ = node;
    } else {
        initFirst(node);
    }
    numNodes_++;
}

template <class T> T LinkedList<T>::pop() {
    // what about when the list is empty?
    return LinkedList<T>::popRight();
}

template <class T> T LinkedList<T>::popRight() {
    T ret = tail_->getVal();
    delete tail_;
    numNodes_--;
    return ret;
}

template <class T> T LinkedList<T>::popLeft() {
    T ret = head_->getVal();
    delete head_;
    numNodes_--;
    return ret;
}

template <class T> uint64_t LinkedList<T>::getLength() { return numNodes_; }

template <class T> std::string LinkedList<T>::str() {
    std::stringstream ss;
    ss << "[ ";

    Node<T> *node = head_;
    while (node != nullptr) {
        ss << node->getVal();
        node = node->getNext();
        if (node != nullptr) {
            ss << " -> ";
        }
    }
    ss << " ]";
    return ss.str();
}

void testInts() {
    std::cout << "Testing <int>:" << std::endl;
    LinkedList<int> *dll = new LinkedList<int>();

    dll->push(4);
    std::cout << "push(4):\t" << dll->str() << std::endl;

    dll->push(12);
    std::cout << "push(12):\t" << dll->str() << std::endl;

    dll->push(-24);
    std::cout << "push(-24):\t" << dll->str() << std::endl;

    std::cout << "pop(): " << dll->pop() << ":\t" << dll->str() << std::endl;

    dll->pushLeft(17);
    std::cout << "pushLeft(17)\t" << dll->str() << std::endl;

    dll->pushLeft(6);
    std::cout << "pushLeft(6)\t" << dll->str() << std::endl;
}

void testStrings() {
    std::cout << "Testing <std::string>:" << std::endl;
    LinkedList<std::string> *dll = new LinkedList<std::string>();

    dll->push("foo");
    std::cout << "push(\"foo\"):\t" << dll->str() << std::endl;

    dll->push("bar");
    std::cout << "push(\"bar\"):\t" << dll->str() << std::endl;

    dll->push("gaz");
    std::cout << "push(\"gaz\"):\t" << dll->str() << std::endl;

    std::cout << "pop(): " << dll->pop() << ":\t" << dll->str() << std::endl;

    dll->pushLeft("tim");
    std::cout << "pushLeft(\"tim\")\t" << dll->str() << std::endl;

    dll->pushLeft("goo");
    std::cout << "pushLeft(\"goo\")\t" << dll->str() << std::endl;
}

int main(int argc, char *argv[]) {
    std::cout << "Hello from main" << std::endl;
    std::cout << std::endl;
    testInts();
    testStrings();
    return 0;
}
