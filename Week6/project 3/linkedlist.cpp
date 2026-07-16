#include <iostream>
#include "linkedlist.hpp"

// 3.2 Default constructor -- initializes an empty list.
LinkedList::LinkedList() : size_(0), head_(nullptr) {}
//3.3 InsertNode
// @param: Takes in a const int parameter representing the value to insert.
// @return: Returns nothing.
void LinkedList::InsertNode(const int value) {
// Insert the provided value as a new node at the end of the list.
// Ensure that the list's tracking variables are updated accordingly.
Node* new_node = new Node (value);
  if (head_ == nullptr) {
    head_ = new_node;
  } else {
    Node* current = head_;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new_node;
  }
  size_++;
}
//3.4 InsertNodeFront()
// @param: Takes in a const int parameter representing the value to insert.
// @return: Returns nothing.
void LinkedList::InsertNodeFront(const int value) {
// Insert the provided value as a new node at the beginning of the list.
// Ensure that the list's tracking variables are updated accordingly.
  Node* new_node = new Node(value);
  new_node->next = head_;
  head_ = new_node;
  size_++;
}

//3.5 Contains()
// @param: Takes in a const int target value.
// @return: Returns true if the value is found, false otherwise.
bool LinkedList::Contains(const int value) const {
  Node* current = head_;
  while (current != nullptr) {
    if (current->value == value) {
      return true;
    }
    current = current->next;
  }
  return false;
}

//3.6 Remove()
// @param: Takes in a const int representing the 1-based position to remove.
// @return: Returns true if successfully removed, false otherwise
//claude explanation; did not know hoe to do this
bool LinkedList::Remove(const int position) {
  if (position < 1 || position > size_) {
    return false;
  }
  Node* to_delete = nullptr;
  if (position == 1) {
    to_delete = head_;
    head_ = head_->next;
  } else {
    Node* prev = head_;
    for (int i = 1; i < position - 1; i++) {
      prev = prev->next;
    }
    to_delete = prev->next;
    prev->next = to_delete->next;
  }
  delete to_delete;
  size_--;
  return true;
}

//3.7 PrintValues() and PrintAddresses()
void LinkedList::PrintValues() const {
// Print all values sequentially, separated by " -> ",
// and terminate the output with "nullptr" and a newline
  Node* current = head_;
  while (current != nullptr) {
    std::cout << current->value << " -> ";
    current = current->next;
  }
  std::cout << "nullptr" << std::endl;
}
void LinkedList::PrintAddresses() const {
// Print the 1-based position, a space, and the node's memory address
// for every node in the list.
  Node* current = head_;
  int position = 1;
  while (current != nullptr) {
    std::cout << position << " " << current << std::endl;
    position++;
    current = current->next;
  }
} 

//3.8 GetValueAtPosition()
// @param: Takes in a const int representing the 1-based position.
// @return: Returns the integer value at that position.
// @throws: std::out_of_range if the position is < 1 or > size_.
int LinkedList::GetValueAtPosition(const int position) const {
// Validate the position, throwing an exception if it is out of bounds.
// Otherwise, navigate to the correct node and return its value.
  if (position < 1 || position > size_) {
    throw std::out_of_range("Position is out of range.");
  }
  Node* current = head_;
  for (int i = 1; i < position; i++) {
    current = current->next;
}
return current->value;
}

//3.9 ReverseList()
// @return: Returns a pointer to a new LinkedList containing the reversed
//nodes
LinkedList* LinkedList::ReverseList() {
// Reverse the nodes of the current list.
// Allocate a new LinkedList dynamically, give it ownership of the
//reversed nodes
// and reset the current (original) list to an empty state.
// Return the pointer to the newly created list.
  Node* prev = nullptr;
  Node* current = head_;
  while (current != nullptr) {
    Node* next_node = current->next;
    current->next = prev;
    prev = current;
    current = next_node;
    //what? struggled
  }// oh, code block of doom
    LinkedList* reversed_list = new LinkedList();
    reversed_list->head_ = prev;
    reversed_list->size_ = size_; 
    // The original list is now empty
    head_ = nullptr;
    size_ = 0;
 
    return reversed_list;
}

//3.10 InsertNodeAt()
// @param: value to insert, and the 1-based position where it should land.
// @return: Returns nothing.
// @throws: std::out_of_range if the position is invalid.
void LinkedList::InsertNodeAt(const int value, const int position) {
// Check if the position is valid (allowing insertions at the very end).
// If invalid, throw std::out_of_range.
// Otherwise, insert the new node at the correct spot and update list properties
  if (position < 1 || position > size_ + 1) {
    throw std::out_of_range("Position is out of range.");
  }
  if (position == 1) {
    InsertNodeFront(value);
    return;
  }
  Node* prev = head_;
  for (int i = 1; i < position - 1; i++) {
    prev = prev->next;
  }
  Node* new_node = new Node(value);
  new_node->next = prev->next;
  prev->next = new_node;
  size_++;
}

//3.11 GetSize()
// @return: Returns the current number of nodes in the list.
int LinkedList::GetSize() const {
  return size_;
}

//3.12 MergeIntertwine()
// @param: Takes in a const reference to a second LinkedList.
// @return: Returns a dynamically allocated pointer to the new merged list.
LinkedList* LinkedList::MergeIntertwine(const LinkedList& second_list) const
{
// Create a new LinkedList on the heap.
// Populate it by alternating nodes from THIS list and the second_list.
// If one list is longer, append the remaining nodes from the longer list
// Do not alter the original lists. Return the new merged list.
LinkedList* merged = new LinkedList();
Node* current1 = head_;
Node* current2 = second_list.head_; 
  // Alternate between the two lists until both are exhausted. InsertNode
  // is used so the new list owns entirely new nodes (copies of the
  // values), leaving both original lists untouched.
  while (current1 != nullptr || current2 != nullptr) {
    if (current1 != nullptr) {
      merged->InsertNode(current1->value);
      current1 = current1->next;
    }
    if (current2 != nullptr) {
      merged->InsertNode(current2->value);
      current2 = current2->next;
    }
  }
  return merged;

}
//3.13
LinkedList::~LinkedList() {
  Node* current = head_;
  while (current != nullptr) {
    Node* next_node = current->next;
    delete current;
    current = next_node;
  }
  head_ = nullptr;
}
