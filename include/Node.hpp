#ifndef NODE
#define NODE 
#include <memory>

using std::shared_ptr;

/* 
This class manages nodes for Linked lists
 */
template<typename T>
class Node {
public:

	/*
	
	Constructors/Destructor
	
	*/
    
	// constructor
    Node();

    // copy constructor
    Node(const shared_ptr<const Node<T>>);

    // destructor
    virtual ~Node();

	/*
	
	Getters
	
	*/
	
	// Return const pointer to prevent accidental
	// change of address to pointer. 
	//
	// Allow change of object/value pointed to 
	// since this is the only way for lists of 
	// nodes to move through their nodes.
	
    // return the next node this node points to
    const shared_ptr<Node<T>> getNext() const;
    // return the previous node this node points to
    const shared_ptr<Node<T>> getPrev() const;
    // get the value of the node
    const shared_ptr<T> getValue() const;
	
	/*
	
	Setters
	
	*/

    // set the next node this node points to
    void setNext(const shared_ptr<const Node<T>>);
    // set the previous node this node points to
    void setPrev(const shared_ptr<const Node<T>>);
    // set the value of the node
    void setValue(const shared_ptr<const T>);

private:
	// node that comes after this node
    shared_ptr<Node<T>> next;
	// node that comes before this node
    shared_ptr<Node<T>> prev;

	// value the node points to
    shared_ptr<T> value;
};

#endif /* ifndef NODE */
