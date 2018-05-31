//
// Created by yuriy on 30.05.18.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>

template <typename T>
class LinkedList {

private:
    // typical structure with two lines

    struct Node {
        T value;
        Node *next;
    };

private:
    // variables for save pointer on the List and save count of elements

    Node *list;
    int count;

public:
    // some methods which allows are working with list

    LinkedList();
    virtual ~LinkedList();

    void     addElement(T);
    void     insertElement(T, int);
    void     deleteElement(T);
    void     deleteElement(int);
    void     printList();
    int      countElements();

    // override operator for choosing element by index

    T operator[](const int);
};


// method which allows add node in top of the list

template<typename T>
void LinkedList<T>::addElement(T value) {
    Node *begin = new Node();

    begin->value = value;
    begin->next = list;

    this->list = begin;
    this->count++;
}

// destructor of class LinkedList

template<typename T>
LinkedList<T>::~LinkedList() {
    delete [] list;
}

// method which allows insert node in some position without losing ties

template<typename T>
void LinkedList<T>::insertElement(T value, int index) {
    // if index is less than count of elements in list then we can make insert

    if (index < this->count) {
        Node *tmp = new Node();
        Node *begin = list;

        tmp->value = value;

        int key = this->count;

        for (int i = key; i > index; i--) {
            begin = begin->next;
        }

        tmp->next = begin->next;
        begin->next = tmp;

        this->count++;
    }

    // if index is greater than count of elements in list then we are printing error

    else {
        std::cerr << "Error! index must be less than count of elements in list." << std::endl;
    }
}

// method which allows delete node with some value

template<typename T>
void LinkedList<T>::deleteElement(T value) {
    if (list->next == nullptr) {
        std::cerr << "Error! List can't be empty." << std::endl;
        return;
    }

    Node *begin = list;

    // if element is situating in the top node then we are remove this node

    if (begin->value == value) {
        list = list->next;

        delete begin;
        this->count--;
        return;
    }

    Node *end = begin->next;

    // looking for element in nodes

    while (end) {
        if (end->value == value)
            break;

        begin = end;
        end = end->next;
    }

    // if we can't found element in the nodes then we are printing information about this error

    if (!end)
        std::cerr << "Can't remove value! Not match found." << std::endl;

    // if we were found element in some node then we are removing this node with saving ways

    else {
        begin->next = end->next;
        delete end;
        this->count--;
    }
}

// method which allows counting nodes in list and are returning theirs count

template<typename T>
int LinkedList<T>::countElements() {
    return this->count;
}

// method which allows delete node in the list for some index

template<typename T>
void LinkedList<T>::deleteElement(int index) {
    // if index is equal or greater than count elements in list we are print Error

    if (index >= this->count) {
        std::cerr << "Error! Index must be less than count of elements in list." << std::endl;
        return;
    }

    // looking for element in nodes by index and remove it

    else {
        Node *begin = list;

        // if index equal 0 then we are removing element from top node with saving ways

        if (index == 0) {
            list = list->next;

            delete begin;
            this->count--;
            return;
        }

        Node *end = begin->next;

        for (int i = 1; i < index && end; i++) {
            begin = end;
            end = end->next;
        }

        begin->next = end->next;
        delete end;
        this->count--;
    }
}

// basic constructor of class LinkedList

template<typename T>
LinkedList<T>::LinkedList() {
    this->list = nullptr;
    this->count = 0;
}

// simple method for print list on display

template<typename T>
void LinkedList<T>::printList() {
    Node *begin = list;

    // until the node is empty we will be printing their elements from nodes

    std::cout << "[";

    while (begin) {
        std::cout << begin->value;

        if (begin->next != nullptr)
            std::cout << "; ";

        begin = begin->next;
    }

    // print the transition to a new line

    std::cout << "]";
    std::cout << std::endl;
}

// operator which allows get access until element in list

template<typename T>
T LinkedList<T>::operator[](const int index) {
    // if we will have been had problems with our list we can easily print Error on display

    try {

        // we can accessed to element in list if index are less than count of elements

        if (index < this->count) {
            Node *begin = list;

            int key = 0;

            while (begin) {
                if (key == index) {
                    return begin->value;
                    break;
                }
                begin = begin->next;
                key++;
            }
        }

        // if index is greater than count of elements in list we are printing Error

        else
            throw index;
    }
    catch (int DEFUNCT_INDEX) {
        std::cerr << "Error! Index { " << DEFUNCT_INDEX << " } doesn't exist." << std::endl;
    }

    // let's return the maximum number as the error code

    return RAND_MAX;
}


#endif //LINKEDLIST_LINKEDLIST_H
