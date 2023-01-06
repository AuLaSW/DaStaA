#include <memory>
#define CATCH_CONFIG_MAIN
#include "../../lib/Catch2/extras/catch_amalgamated.hpp"
#include "../../../include/Node.hpp"

/*
 * This file contains the tests for the Node class
 */

SCENARIO("An empty node is created", "[node]") {
    GIVEN("An empty node") {
        // create an empty Node of type int
        // we chose int because it's a simple and common
        // type to use
        shared_ptr<Node<int>> node(new Node<int>);

        THEN("The node should have nullptr values") {
            REQUIRE(node->getNext() == nullptr);
            REQUIRE(node->getPrev() == nullptr);
            REQUIRE(node->getValue() == nullptr);
        }

        WHEN("A node is added after the current node") {
            // add an anonymous, empty node to the next
            // member variable
            shared_ptr<Node<int>> newNode (new Node<int>);
            node->setNext(newNode);

            THEN("The value should be reflected") {
                // we are actually checking the memory locations
                // of the two nodes. They should be the same.
                REQUIRE(node->getNext() == newNode);
            }
        }

        WHEN("A node is added before the current node") {
            // add an anonymous, empty node to the prev
            // member variable
            shared_ptr<Node<int>> newNode (new Node<int>);
            node->setPrev(newNode);

            THEN("The value should be reflected") {
                // we are actually checking the memory locations
                // of the two nodes. They should be the same.
                REQUIRE(node->getPrev() == newNode);
            }
        }

        WHEN("A value is added into the current node") {
            // create a list of values to work with
            const int VALUES = GENERATE(0, 1, 2, 5, 11, 21, 100, 1000);
            // generate a shared pointer version of an integer
            shared_ptr<int> input(new int(VALUES));
            // add a value to the current node object
            node->setValue(input);

            THEN("The value should be reflected") {
                REQUIRE(*(node->getValue()) == VALUES);
            }
        }

        WHEN("A non-empty node is given to copy") {
            // generate an new empty node that we will populate
            shared_ptr<Node<int>> newNode(new Node<int>());
            // empty node that comes after the current node
            shared_ptr<Node<int>> nextNode(new Node<int>);
            // empty node that comes before the current node
            shared_ptr<Node<int>> prevNode(new Node<int>);
            
            // point newNode to nextNode
            newNode->setNext(nextNode);
            // point newNode to prevNode
            newNode->setPrev(prevNode);

            // generate values to use
            const int VALUES = GENERATE(0, 1, 2, 5, 11, 21, 100, 1000);
            // add generated values to value member
            newNode->setValue(shared_ptr<int> (new int(VALUES)));

            THEN("Copying the node should perform a deep copy") {
                // this should invoke the copy constructor
                node = newNode;
                // we are checking that they are pointing to
                // the same address
                REQUIRE(node->getNext() == newNode->getNext());
                // we are checking that they are pointing to
                // the same address
                REQUIRE(node->getPrev() == newNode->getPrev());
                // here we want to make sure we are pointing to
                // the same *value* (that the equals operator
                // returns true for the two objects)
                REQUIRE(*(node->getValue()) == *(newNode->getValue()));
            }
        }
    }
}

/*
SCENARIO("A non-empty node is created", "[node]") {
    GIVEN("A node with populated values") {
        // node we will be working with
        shared_ptr<Node<int>> node(new Node<int>);
        // empty node that comes after the current node
        shared_ptr<Node<int>> nextNode(new Node<int>);
        // empty node that comes before the current node
        shared_ptr<Node<int>> prevNode(new Node<int>);

        // point the current node to the next node
        node->setNext(nextNode);
        // point the current node to the prev node
        node->setPrev(prevNode);

        // add a value to the current node
        const int VALUES = GENERATE(0, 1, 2, 5, 11, 21, 100, 1000);
        node->setValue(shared_ptr<int> (new int(VALUES)));
    }
}
*/
