#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include <memory>
#include "Node.hpp"

using std::shared_ptr;

template<typename T>
class SingleLinkedList {
public:
    // constructor
    SingleLinkedList();

    // copy constructor
    SingleLinkedList(shared_ptr<SingleLinkedList<T>>);

    // destructor
    virtual ~SingleLinkedList();

    // true if the list is empty
    bool empty() const;

    // return a constant reference to the front element
    const shared_ptr<T> front() const;

    // add element to the front of the list
    void addFront(const shared_ptr<T> e);

    // remove element from the front of the list
    void removeFront();
private:
    Node<T> head;
};

#endif /* SINGELINKEDLIST_H */
