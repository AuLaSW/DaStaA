#ifndef NODE
#define NODE 
#include <memory>

using std::shared_ptr;

/* This class manages nodes for Linked lists
 */
template<typename T>
class Node {
public:
    // constructor
    Node();

    // copy constructor
    Node(shared_ptr<Node<T>>);

    // destructor
    virtual ~Node();

    // return the next node this node points to
    const shared_ptr<const Node<T>> getNext() const;
    // return the previous node this node points to
    const shared_ptr<const Node<T>> getPrev() const;
    // get the value of the node
    const shared_ptr<const T> getValue() const;

    // set the next node this node points to
    void setNext(const shared_ptr<const Node<T>>);
    // set the previous node this node points to
    void setPrev(const shared_ptr<const Node<T>>);
    // set the value of the node
    void setValue(const shared_ptr<const T>);

private:
    shared_ptr<Node<T>> next;
    shared_ptr<Node<T>> prev;

    shared_ptr<T> value;
};

#endif /* ifndef NODE */
