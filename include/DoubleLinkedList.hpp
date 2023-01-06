#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <memory>
#include "Node.hpp"

using std::shared_ptr;

template<typename T>
class DoubleLinkedList {
public:
    // constructor
    DoubleLinkedList ();

    // copy constructor
    DoubleLinkedList (shared_ptr<DoubleLinkedList<T>>);

    // destructor
    virtual ~DoubleLinkedList ();

    // true if the list is empty
    bool empty() const;

    // return the front element of the list
    const shared_ptr<T> front() const;
    // return the last element of the list
    const shared_ptr<T> back() const;

    // add element to the front of the list
    void addFront(const shared_ptr<T>);
    // add element to the back of the list
    void addBack(const shared_ptr<T>);

    // remove the first element of the list
    void removeFront();
    // remove the last element from the list
    void removeBack();
private:
    shared_ptr<Node<T>> header;
    shared_ptr<Node<T>> trailer;
};

#endif /* DOUBLELINKEDLIST_H */
