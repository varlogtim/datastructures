#include "LinkedList.h"
#include <assert.h>

// So, for testing, perhaps I have an Array of values, I do
// different operations on the list and validate the str()
// representation of the LinkedList.

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

template <typename T>
void print_list_state(LinkedList<T> *dll, std::string op) {
    uint64_t pad_len;
    uint8_t op_width = 34;
    std::stringstream ss;

    ss << op;
    pad_len = ss.tellp() < op_width ? op_width - ss.tellp() : 0;
    if (pad_len > 0)
        while (pad_len--)
            ss << " ";
    ss << "len(" << dll->get_length() << "): " << dll->str() << std::endl;
    std::cout << ss.str();
}

template <typename T> void test_linked_list(std::vector<T> values) {
    size_t num_elems = values.size();
    assert(num_elems == 9);

    /* for (T &v : values) { */
    /*     std::cout << "Value: " << v << std::endl; */
    /* } */

    /*
     * I feel like this is a big long ugly thing ...
     * Put, the results and operations depend on the
     * order the ops occur in.. so.. it is what it is.
     */
    LinkedList<T> *dll = new LinkedList<T>();

    std::stringstream exp_ss;
    std::stringstream op_ss;
    T value;

    // push
    dll->push(values.at(0));
    op_ss << "push(" << values.at(0) << ")";
    exp_ss << "[ " << values.at(0) << " ]";

    assert(exp_ss.str().compare(dll->str()) == 0);
    assert(dll->get_length() == 1);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // push_right
    dll->push_right(values.at(1));
    op_ss << "push_right(" << values.at(1) << ")";
    exp_ss << "[ " << values.at(0) << LINKED_LIST_STR_SEP << values.at(1)
           << " ]";

    assert(exp_ss.str().compare(dll->str()) == 0);
    assert(dll->get_length() == 2);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // push_left
    dll->push_left(values.at(2));
    op_ss << "push_left(" << values.at(2) << ")";
    exp_ss << "[ " << values.at(2) << LINKED_LIST_STR_SEP << values.at(0)
           << LINKED_LIST_STR_SEP << values.at(1) << " ]";

    assert(exp_ss.str().compare(dll->str()) == 0);
    assert(dll->get_length() == 3);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // get_length
    uint64_t length = dll->get_length();
    op_ss << "get_length() -> " << length;

    assert(length == 3);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // peek
    value = dll->peek();
    op_ss << "peek() -> " << value;

    assert(value == values.at(1));
    assert(dll->get_length() == 3);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // peek_right
    value = dll->peek_right();
    op_ss << "peek_right() -> " << value;

    assert(value == values.at(1));
    assert(dll->get_length() == 3);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // peek_left
    value = dll->peek_left();
    op_ss << "peek_left() -> " << value;

    assert(value == values.at(2));
    assert(dll->get_length() == 3);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // get_index
    value = dll->get_index(1);
    op_ss << "get_index(1) -> " << value;

    assert(value == values.at(0));
    assert(dll->get_length() == 3);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // pop_index
    value = dll->pop_index(1);
    op_ss << "pop_index(1) -> " << value;
    exp_ss << "[ " << values.at(2) << LINKED_LIST_STR_SEP << values.at(1)
           << " ]";

    assert(value == values.at(0));
    assert(exp_ss.str().compare(dll->str()) == 0);
    assert(dll->get_length() == 2);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // push
    dll->push(values.at(3));
    op_ss << "push(" << values.at(3) << ")";
    exp_ss << "[ " << values.at(2) << LINKED_LIST_STR_SEP << values.at(1)
           << LINKED_LIST_STR_SEP << values.at(3) << " ]";

    assert(exp_ss.str().compare(dll->str()) == 0);
    assert(dll->get_length() == 3);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // pop
    value = dll->pop();
    op_ss << "pop() -> " << value;
    exp_ss << "[ " << values.at(2) << LINKED_LIST_STR_SEP << values.at(1)
           << " ]";

    assert(exp_ss.str().compare(dll->str()) == 0);
    assert(dll->get_length() == 2);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // pop_right
    value = dll->pop_right();
    op_ss << "pop_right() -> " << value;
    exp_ss << "[ " << values.at(2) << " ]";

    assert(exp_ss.str().compare(dll->str()) == 0);
    assert(dll->get_length() == 1);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // pop_left
    value = dll->pop_left();
    op_ss << "pop_left() -> " << value;
    exp_ss << "[  ]";

    assert(exp_ss.str().compare(dll->str()) == 0);
    assert(dll->get_length() == 0);
    print_list_state(dll, op_ss.str());

    std::stringstream().swap(exp_ss); // reset
    std::stringstream().swap(op_ss);

    // get_index - empty list
    op_ss << "get_index(1) -> ";
    try {
        value = dll->get_index(1);
    } catch (const std::out_of_range &err) {
        op_ss << "EXP ERR";
        print_list_state(dll, op_ss.str());
        // std::cout << "\tERR: " << err.what() << std::endl;
    }
    std::stringstream().swap(op_ss);

    // pop - emtpy list
    op_ss << "pop() -> ";
    try {
        value = dll->pop();
    } catch (const std::out_of_range &err) {
        op_ss << "EXP ERR";
        print_list_state(dll, op_ss.str());
        // std::cout << "\tERR: " << err.what() << std::endl;
    }
    std::stringstream().swap(op_ss);

    // pop_right - emtpy list
    op_ss << "pop_right() -> ";
    try {
        value = dll->pop_right();
    } catch (const std::out_of_range &err) {
        op_ss << "EXP ERR";
        print_list_state(dll, op_ss.str());
        // std::cout << "\tERR: " << err.what() << std::endl;
    }
    std::stringstream().swap(op_ss);

    // pop_left - empty list
    op_ss << "pop_left() -> ";
    try {
        value = dll->pop_left();
    } catch (const std::out_of_range &err) {
        op_ss << "EXP ERR";
        print_list_state(dll, op_ss.str());
        // std::cout << "\tERR: " << err.what() << std::endl;
    }
    std::stringstream().swap(op_ss);

    op_ss << "DTOR -> Empty LinkedList()";
    print_list_state(dll, op_ss.str());
    delete dll;
    std::stringstream().swap(op_ss);

    // Populate a new list
    dll = new LinkedList<T>();
    dll->push(values.at(4));
    dll->push(values.at(5));
    dll->push(values.at(6));
    dll->push(values.at(7));
    dll->push(values.at(8));
    op_ss << "DTOR -> Full LinkedList()";
    print_list_state(dll, op_ss.str());
    delete dll;
    std::stringstream().swap(op_ss);

    // Populate a new list
    dll = new LinkedList<T>();
    dll->push(values.at(4));
    dll->push(values.at(5));
    dll->push(values.at(6));
    dll->push(values.at(7));
    dll->push(values.at(8));
    assert(dll->get_length() == 5);

    // get_index - out of bounds
    op_ss << "get_index(" << dll->get_length() << ") -> ";
    try {
        value = dll->get_index(dll->get_length());
    } catch (const std::out_of_range &err) {
        op_ss << "EXP ERR";
        print_list_state(dll, op_ss.str());
        // std::cout << "\tERR: " << err.what() << std::endl;
    }
    std::stringstream().swap(op_ss);

    // pop_index at tail
    value = dll->pop_index(dll->get_length() - 1);
    op_ss << "pop_index(" << dll->get_length() << "<TAIL>) -> " << value;
    assert(dll->get_length() == 4);
    assert(value == values.at(8));
    print_list_state(dll, op_ss.str());
    std::stringstream().swap(op_ss);

    // pop_index at tail (confirming tail is reset correctly)
    value = dll->pop_index(dll->get_length() - 1);
    op_ss << "pop_index(" << dll->get_length() << "<TAIL>) -> " << value;
    assert(dll->get_length() == 3);
    assert(value == values.at(7));
    print_list_state(dll, op_ss.str());
    std::stringstream().swap(op_ss);

    // Need to verify delete of a single node ??
    // Maybe delete a single node?

    // pop_index at head
    value = dll->pop_index(0);
    op_ss << "pop_index(0<HEAD>) -> " << value;
    assert(dll->get_length() == 2);
    assert(value == values.at(4));
    print_list_state(dll, op_ss.str());
    std::stringstream().swap(op_ss);

    // pop_index at head
    value = dll->pop_index(0);
    op_ss << "pop_index(0<HEAD>) -> " << value;
    assert(dll->get_length() == 1);
    assert(value == values.at(5));
    print_list_state(dll, op_ss.str());
    std::stringstream().swap(op_ss);

    // pop_index at head
    value = dll->pop_index(0);
    op_ss << "pop_index(0<HEAD>) -> " << value;
    assert(dll->get_length() == 0);
    assert(value == values.at(6));
    print_list_state(dll, op_ss.str());
    std::stringstream().swap(op_ss);

    // Test delete empty node
    delete dll;

    // Test LinkedList with limit
    const uint64_t limit = 4;
    dll = new LinkedList<T>(limit);
    try {
        for (uint64_t ii = limit + 1; ii--;) {
            dll->push(values.at(ii));
        }
    } catch (const std::out_of_range &err) {
        std::cout << err.what() << std::endl;
    }
}

// So, neat thing, passing the pointer enforces length of array.
void test_linked_list_ints(int (*values)[9]) {
    std::vector<int> vect_values(std::begin(*values), std::end(*values));
    std::cout << std::endl << "Starting LinkedList<int> Tests: " << std::endl;
    test_linked_list(vect_values);
    std::cout << "**All LinkedList<int> tests: PASSED" << std::endl;
}

void test_linked_list_strs(std::string (*values)[9]) {
    std::vector<std::string> vect_values(std::begin(*values),
                                         std::end(*values));
    std::cout << std::endl
              << "Starting LinkedList<std::string> Tests: " << std::endl;
    test_linked_list(vect_values);
    std::cout << "**All LinkedList<std::string> tests: PASSED" << std::endl;
}

int main(int argc, char *argv[]) {
    std::cout << "Hello from main" << std::endl;
    std::cout << std::endl;

    int arr_ints[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    test_linked_list_ints(&arr_ints);

    std::string arr_strs[9]{"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    test_linked_list_strs(&arr_strs);

    return 0;
}
