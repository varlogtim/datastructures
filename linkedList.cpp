#include <bits/stdc++.h>
#include "linkedList.h"

template <class T>
LinkedList<T>::LinkedList() {}

template <class T>
void
LinkedList<T>::initFirst(Node<T> *n)
{
    _head = n;
    _tail = n;
}

template <class T>
void
LinkedList<T>::push(T v)
{
    LinkedList<T>::pushRight(v);   
}

template <class T>
void
LinkedList<T>::pushRight(T v)
{
    Node<T> *node = new Node<T>(v);
    if (_numNodes != 0) {
        _tail->setNext(node);
        node->setPrev(_tail);
        _tail = node;
    } else {
        initFirst(node);
    }
    _numNodes++;
}

template <class T>
void
LinkedList<T>::pushLeft(T v)
{
    Node<T> *node = new Node<T>(v);
    if (_numNodes != 0) {
        _head->setPrev(node);
        node->setNext(_head);
        _head = node;
    } else {
        initFirst(node);
    }
    _numNodes++;
}

template <class T>
T LinkedList<T>::pop()
{
    // what about when the list is empty?
    return LinkedList<T>::popRight();
}

template <class T>
T LinkedList<T>::popRight()
{
    T ret = _tail->getVal();
    delete _tail;
    _numNodes--;
    return ret;
}

template <class T>
T LinkedList<T>::popLeft()
{
    T ret = _head->getVal();
    delete _head;
    _numNodes--;
    return ret;
}

template <class T>
uint64_t
LinkedList<T>::getLength()
{
    return _numNodes;
}

template <class T>
std::string
LinkedList<T>::str()
{
    std::stringstream ss;
    ss << "[ ";

    Node<T> *node = _head;
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

void testInts()
{
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

void testStrings()
{
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

int main(int argc, char *argv[])
{
    std::cout << "Hello from main" << std::endl;
    std::cout << std::endl;
    testInts();
    testStrings();
    return 0;
}
