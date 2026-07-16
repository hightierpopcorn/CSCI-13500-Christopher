#include "Snake.h"
#include <iostream>

// TODO: Constructor
// - Build a snake with STARTING_LENGTH segments using `new`.
// - head should point to segment id 0 (or 1, your choice - just be consistent),
//   tail should point to the last segment created.
// - Set length and nextId appropriately.
Snake::Snake() {
    head_ = nullptr;
    tail_ = nullptr;
    length_ = 0;
    id_ = 0;
    // TODO: allocate STARTING_LENGTH nodes and link them together
    for (int i = 0; i < STARTING_LENGTH; i++) {
        
    // this is the very first node
    Node* new_node = new Node;
    new_node->body_part_ = id_;
    id_++;
    new_node->next_ = nullptr;
    if (head_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
} else {
    // there's already at least one node — attach new_node
    tail_->next_ = new_node;
    tail_ = new_node;

    // after the current tail_, and then update tail_?
            } 
    length_++;
        }

}
    // runs once per node
    

// TODO: Destructor
// - Walk the list and delete every remaining node.
// - If you don't do this, running under valgrind/ASan will report a leak.
Snake::~Snake() {
    // TODO
    Node* current = head_;
    while (current != nullptr){
        Node* next_node = current->next_;
        delete current;
        current = next_node;
    }
}

// TODO: kill()
// - Remove up to `count` nodes from the FRONT of the list, deleting each one.
// - Handle the edge case where the snake has fewer than `count` nodes left:
//   kill all remaining nodes and stop. Do not crash.
// - Update `length` (and `tail`/`head` if the snake becomes empty!).
// - Return the number of segments ACTUALLY killed.
int Snake::Kill(int count) {
    // TODO
    int killedCount = 0;
    while (head_ != nullptr && killedCount < count) {
        Node* next_node = head_->next_; 
        delete head_; 
        head_ = next_node; 
        killedCount++;
    }

    if (head_ == nullptr) {
        tail_ = nullptr;
    }

    length_ -= killedCount;

    return killedCount;
}

// TODO: regenerate()
// - Append `count` new nodes to the BACK of the list using `new`.
// - Use `nextId` to assign each new node a unique, increasing id, and
//   increment `nextId` each time.
// - Update `tail` (and `head` if the snake was empty!) and `length`.
void Snake::Regenerate(int count) {
    // TODO
    for (int i = 0; i < count; i++) {
        Node* new_node = new Node;
        new_node->body_part_ = id_;
        id_++;
        new_node->next_ = nullptr;
    
    if (head_ == nullptr) {
        head_ = new_node;
        tail_ = new_node;
        } else {
        tail_->next_ = new_node;
        tail_ = new_node;
        }    
        
        length_++;

    }
}

// TODO: print()
// - Walk the list from head to tail and print in the format:
//   Snake: [12] -> [13] -> [14] -> [15]
// - If the snake is empty, print something sensible like "Snake: (dead)".
// - This function must not modify the snake - use a `const Node*` to walk it.
void Snake::PrintSnake() const {
    if (head_ == nullptr) {
        std::cout << "Snake: (dead)" << std::endl;
    } else {
        std::cout << "Snake: ";
        const Node* current = head_;
        bool isFirst = true;
        while (current != nullptr) {
            if (!isFirst) {
                std::cout << " -> ";
            }
        std::cout << "[" << current->body_part_ << "]";
        isFirst = false;
        current = current->next_;
    }
    std::cout << std::endl;
}
}


int Snake::GetLength() const {
    // TODO
    return length_;
    return 0;
}
