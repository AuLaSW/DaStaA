#ifndef CIRCLELINKEDLIST_H
#define CIRCLELINKEDLIST_H
#include <memory>
#include "Node.hpp"

using std::shared_ptr;

template<typename T>
class CircleLinkedList {
public:
    // constructor
    CircleLinkedList();

    // copy constructor
    CircleLinkedList(shared_ptr<CircleLinkedList<T>>);

    // destructor
    virtual ~CircleLinkedList();

    // true if the list is empty
    bool empty() const;

    // return the value of the front element
    const shared_ptr<T> front() const;
    // return the value of the last element
    const shared_ptr<T> back() const;

    // move the cursor forward one node
    void advance();
    // add a node after the cursor
    void add(const shared_ptr<T>);
    // remove node after the cursor
    void remove();
private:
    shared_ptr<Node<T>> cursor;
};

#endif /* CIRCLELINKEDLIST_H */
