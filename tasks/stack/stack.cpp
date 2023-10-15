#include "stack.h"

Node::Node(int32_t value, Node* previous) : value{value}, previous{previous} {
}

Stack::Stack() : head_{nullptr}, size_{0} {
}

int32_t Stack::Top() const {
    return head_->value;
}

int32_t Stack::Size() const {
    return size_;
}

bool Stack::Empty() const {
    return head_ == nullptr;
}

void Stack::Push(int32_t value) {
    Node* new_node = new Node(value, head_);
    head_ = new_node;
    size_++;
}

void Stack::Pop() {
    if (this->Empty()) {
        return;
    }
    Node* current = head_;
    head_ = head_->previous;
    delete current;
    size_--;
}

void Stack::Clear() {
    while (!this->Empty()) {
        this->Pop();
    }
}

Stack::~Stack() {
    this->Clear();
    delete head_;
}