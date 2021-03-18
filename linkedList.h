#include <bits/stdc++.h>

// Should Node be inside of the LinkedList class?
template <class T> class Node {
  public:
    Node(T v) { val_ = v; }
    ~Node() {
        if (prev_ == nullptr && next_ == nullptr) {
            return; // Do nothing, list is one entry
        }
        if (prev_ != nullptr) {
            prev_->set_next(next_);
        }
        if (next_ != nullptr) {
            next_->set_prev(prev_);
        }
    }

    Node<T> *get_next() { return next_; }
    Node<T> *get_prev() { return prev_; }
    T get_val() { return val_; }
    void set_next(Node<T> *n) { next_ = n; }
    void set_prev(Node<T> *n) { prev_ = n; }
    void set_val(T v) { val_ = v; }

  private:
    T val_;
    Node<T> *next_ = nullptr;
    Node<T> *prev_ = nullptr;
};

// Doubly linked list impl.
template <class T> class LinkedList {
  public:
    LinkedList() {}
    ~LinkedList() {
        Node<T> *node = head_;
        Node<T> *cur_node = node;
        while (node->get_next() != nullptr) {
            node = cur_node->get_next();
            delete cur_node;
            num_nodes_--; // debug
        }
    }

    void push(T v) { push_right(v); }
    void push_right(T v) {
        Node<T> *node = new Node<T>(v);
        if (num_nodes_ > 0) {
            tail_->set_next(node);
            node->set_prev(tail_);
            tail_ = node;
        } else {
            initFirst(node);
        }
        num_nodes_++;
    }
    void push_left(T v) {
        Node<T> *node = new Node<T>(v);
        if (num_nodes_ > 0) {
            head_->set_prev(node);
            node->set_next(head_);
            head_ = node;
        } else {
            initFirst(node);
        }
        num_nodes_++;
    }
    T pop() { return pop_right(); }
    T pop_right() {
        T ret = tail_->get_val();
        delete tail_;
        num_nodes_--;
        return ret;
    }
    T pop_left() {
        T ret = head_->get_val();
        delete head_;
        num_nodes_--;
        return ret;
    }
    // T peek();
    // T peekRight();
    // T peekLeft();
    // T getIndex();
    // T popIndex();
    uint64_t getLength() { return num_nodes_; }
    std::string str() {
        std::stringstream ss;
        ss << "[ ";

        Node<T> *node = head_;
        while (node != nullptr) {
            ss << node->get_val();
            node = node->get_next();
            if (node != nullptr) {
                ss << " -> ";
            }
        }
        ss << " ]";
        return ss.str();
    }

  private:
    void initFirst(Node<T> *n) {
        head_ = n;
        tail_ = n;
    }
    Node<T> *head_ = nullptr;
    Node<T> *tail_ = nullptr;
    uint64_t num_nodes_ = 0;
};
