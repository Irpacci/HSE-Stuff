#include "queue.h"

Node::Node(int32_t value, Node* next) : value{value}, next{next} {
}

Queue::Queue() : front_{nullptr}, tail_{nullptr}, size_{0} {
}

bool Queue::Empty() const {
    return front_ == nullptr;
}

void Queue::Push(int32_t value) {
    size_++;
    if (this->Empty()) {
        front_ = new Node(value, nullptr);
        tail_ = front_;
        return;
    }
    Node* new_node = new Node(value, nullptr);
    tail_->next = new_node;
    tail_ = new_node;
}

int32_t Queue::Size() const {
    return size_;
}

void Queue::Pop() {
    if (this->Empty()) {
        return;
    }
    Node* current = front_;
    front_ = front_->next;
    delete current;
    size_--;
}

int32_t Queue::Front() const {
    return front_->value;
}

void Queue::Clear() {
    while (!this->Empty()) {
        this->Pop();
    }
}

Queue::~Queue() {
    this->Clear();
    delete front_;
}