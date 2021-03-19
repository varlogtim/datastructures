#include <bits/stdc++.h>

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

#define LINKED_LIST_STR_SEP " -> "

// Should Node be inside of the LinkedList class?
template <class T> class Node {
  public:
    using NodeT = Node<T>;
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

    NodeT *get_next() { return next_; }
    NodeT *get_prev() { return prev_; }
    T get_val() { return val_; }
    void set_next(NodeT *n) { next_ = n; }
    void set_prev(NodeT *n) { prev_ = n; }
    void set_val(T v) { val_ = v; }

  private:
    T val_;
    NodeT *next_ = nullptr;
    NodeT *prev_ = nullptr;
};

// Doubly linked list impl.
template <class T> class LinkedList {
  public:
    // We possibly want a size limited list?
    using NodeT = Node<T>;
    LinkedList() {}
    LinkedList(const uint64_t max_nodes) { max_nodes_ = max_nodes; }
    ~LinkedList() {
        NodeT *node = head_;
        NodeT *next_node;
        while (node != nullptr) {
            next_node = node->get_next();
            delete node;
            node = next_node;
            num_nodes_--; // debug
        }
    }

    void push(T v) { push_right(v); }
    void push_right(T v) {
        check_list_max_();
        NodeT *node = new NodeT(v);
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
        check_list_max_();
        NodeT *node = new NodeT(v);
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
        check_empty_list_();
        T ret = tail_->get_val();
        delete_node_(tail_);
        num_nodes_--;
        return ret;
    }
    T pop_left() {
        check_empty_list_();
        T ret = head_->get_val();
        delete_node_(head_);
        num_nodes_--;
        return ret;
    }
    T peek() { return peek_right(); }
    T peek_right() { return tail_->get_val(); }
    T peek_left() { return head_->get_val(); }
    T get_index(const uint64_t index) {
        return get_node_index_(index)->get_val();
    }
    T pop_index(const uint64_t index) {
        check_empty_list_();
        NodeT *node = get_node_index_(index);
        T ret = node->get_val();
        delete_node_(node);
        num_nodes_--;
        return ret;
    }
    // push_index(T v) {}
    uint64_t get_length() { return num_nodes_; }
    std::string str() {
        std::stringstream ss;
        ss << "[ ";
        NodeT *node = head_;
        // I feel like I only need one "node != nullptr" condition
        while (node != nullptr) {
            ss << node->get_val();
            node = node->get_next();
            if (node != nullptr) {
                ss << LINKED_LIST_STR_SEP;
            }
        }
        ss << " ]";
        return ss.str();
    }

  private:
    void initFirst(NodeT *n) {
        head_ = n;
        tail_ = n;
    }
    void check_empty_list_() {
        if (num_nodes_ == 0)
            throw std::out_of_range("List is empty");
    }
    void check_list_max_() {
        if (unlikely(num_nodes_ == max_nodes_)) {
            throw std::out_of_range("List is too large");
        }
    }
    void delete_node_(NodeT *node) {
        // Need multiple statements as head and tail maybe the same.
        if (node == head_) {
            head_ = head_->get_next();
        }
        if (node == tail_) {
            tail_ = tail_->get_prev();
        }
        delete node;
    }
    NodeT *get_node_index_(const uint64_t index) {
        // TODO: think about supporting negative indexes?
        check_empty_list_();
        if (index >= num_nodes_) {
            throw std::out_of_range("Index out of bounds");
        }

        uint64_t steps;
        NodeT *node;
        if (index < num_nodes_ / 2) { // start from head
            node = head_;
            steps = index;
            while (steps--) {
                node = node->get_next();
            }
        } else { // start from tail
            node = tail_;
            steps = num_nodes_ - index - 1;
            while (steps--) {
                node = node->get_prev();
            }
        }
        assert(node != nullptr);
        return node;
    }

    NodeT *head_ = nullptr;
    NodeT *tail_ = nullptr;
    uint64_t num_nodes_ = 0;
    uint64_t max_nodes_ = UINT64_MAX;
};
