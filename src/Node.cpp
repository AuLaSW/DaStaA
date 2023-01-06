#define NODE
#include <stdexcept>
#include "../include/Node.hpp"

typedef const shared_ptr<const Node<T>> ccNode
typedef const shared_ptr<const T> ccT

/*

Constructors/Destructor

*/

// base constructor
template<typename T>
Node<T>::Node() : next(nullptr), prev(nullptr), value(nullptr)
{ }

// copy constructor
template<typename T>
Node<T>::Node(const shared_ptr<const Node<T>> copyNode) :
	next(copyNode.next), prev(copyNode.prev), value(copyNode.value)
{ }

// destructor
// This function is empty because all member variables
// are smart pointers. They will be deleted as soon as
// the object itself is deleted.
template<typename T>
Node<T>::~Node() 
{ }

/*

Getters

*/

// returns the next node
template<typename T>
ccNode Node<T>::getNext() const {	
	return this.next;
}

// returns the previous node
// This function throws an error when there is
// no previous node. Singly Linked Lists cannot
// have nodes that point to previous nodes, so
// throwing an error in this state should help
// keep the program from doing that.
template<typename T>
ccNode Node<T>::getPrev() const {
	if (this.prev == nullptr) {
		throw std::runtime_exeption("No previous node found.");
	}
	
	return this.prev;
}

// returns the value the node points to
template<typename T>
ccT Node<T>::getValue() const {
	return this.value;
}

/*

Setters

*/

// Accepts a constant smart pointer to a constant
// node and sets that as the next node.
template<typename T>
void Node<T>::setNext(ccNode node) {
	this.next = node;
}

// Accepts a constant smart pointer to a constant
// node and sets that as the previous node
template<typename T>
void Node<T>::setPrev(ccNode node) {
	this.prev = node;
}

// Accepts a constant smart pointer to a constant
// typename and sets that as the value
template<typename T>
void Node<T>::setValue(ccT value) {
	this.value = value;
}