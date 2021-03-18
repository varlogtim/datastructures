#include "linkedList.h"

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

    dll->push_left(17);
    std::cout << "push_left(17)\t" << dll->str() << std::endl;

    dll->push_left(6);
    std::cout << "push_left(6)\t" << dll->str() << std::endl;
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

    dll->push_left("tim");
    std::cout << "push_left(\"tim\")\t" << dll->str() << std::endl;

    dll->push_left("goo");
    std::cout << "push_left(\"goo\")\t" << dll->str() << std::endl;
}

int main(int argc, char *argv[]) {
    std::cout << "Hello from main" << std::endl;
    std::cout << std::endl;
    testInts();
    testStrings();
    return 0;
}
