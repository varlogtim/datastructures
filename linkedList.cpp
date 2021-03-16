#include <bits/stdc++.h>
#include "linkedList.h"

LinkedList::LinkedList() {}

void
LinkedList::initFirst(Node *n)
{
    _head = n;
    _tail = n;
}

void
LinkedList::push(int v)
{
    LinkedList::pushRight(v);   
}

void
LinkedList::pushRight(int v)
{
    Node *node = new Node(v);
    if (_numNodes != 0) {
        _tail->setNext(node);
        node->setPrev(_tail);
        _tail = node;
    } else {
        initFirst(node);
    }
    _numNodes++;
}

void
LinkedList::pushLeft(int v)
{
    Node *node = new Node(v);
    if (_numNodes != 0) {
        _head->setPrev(node);
        node->setNext(_head);
        _head = node;
    } else {
        initFirst(node);
    }
    _numNodes++;
}

int
LinkedList::pop()
{
    // what about when the list is empty?
    return LinkedList::popRight();
}

int
LinkedList::popRight()
{
    int ret = _tail->getVal();
    delete _tail;
    _numNodes--;
    return ret;
}

int
LinkedList::popLeft()
{
    int ret = _head->getVal();
    delete _head;
    _numNodes--;
    return ret;
}

uint64_t
LinkedList::getLength()
{
    return _numNodes;
}

std::string
LinkedList::str()
{
    std::stringstream ss;
    ss << "[";

    Node *node = _head;
    while (node != nullptr) {
        ss << node->getVal();
        node = node->getNext();
        if (node != nullptr) {
            ss << " -> ";
        }
    }
    ss << "]";
    return ss.str();
}

int main(int argc, char *argv[])
{
    std::cout << "Hello from main" << std::endl;
    LinkedList *dll = new LinkedList();

    dll->push(1);
    dll->push(2);
    dll->push(3);
    std::cout << dll->str() << std::endl;
    std::cout << "DLL length: " << dll->getLength() << std::endl;
    int test = dll->pop();
    std::cout << "popped: " << test 
        << " DLL length: " << dll->getLength() << std::endl;
    std::cout << dll->str() << std::endl;
    return 0;
}
