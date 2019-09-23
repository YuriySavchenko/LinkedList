//
// Created by yuriy on 30.05.18.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>

template <typename T>
class LinkedList {

private:
    /* typical structure with two lines */

    struct Node {
        T value;
        Node *next;
    };

private:
    /* variables for save pointer on the List and save count of elements */

    Node    *LIST;
    int     COUNT;

public:
    /* some methods which allow are working with list */

    LinkedList();
    LinkedList(int, T);
    ~LinkedList();

    void    append(const T &);
    void    append(const LinkedList<T> &);
    void    insert(int, const T &);
    void    insert(int, const LinkedList<T> &);
    void    remove(T);
    void    remove(const int);
    void    reverse();
    void    clear();
    void    print();

    bool    isEmpty() const;

    /* functions for easy access to nodes in lists */

    auto    end() const;
    auto    begin() const;

    /* functions which allow known size of list */

    int     count() const;
    int     size() const;
    int     length() const;

    /* methods and overriding operators for access to element */

    T       &first();
    T       &last();
    T       at(int) const;
    T       value(int) const;
    T       &operator[](int);
};

/* basic constructor of class LinkedList */

template<typename T>
LinkedList<T>::LinkedList() {
    this->LIST = nullptr;
    this->COUNT = 0;
}

/* custom constructor for fill list by values */

template<typename T>
LinkedList<T>::LinkedList(int count, T value) {
    this->LIST = nullptr;
    this->COUNT = 0;
    
    int counter = count;

    for (int i=0; i < counter; i++)
        append(value);
}

/* destructor of class LinkedList */

template<typename T>
LinkedList<T>::~LinkedList() {
    // invoke function for delete all elements in list

    this->clear();
}

/* method which allows to append element in top of the list */

template<typename T>
void LinkedList<T>::append(const T &value) {
    Node *begin = new Node();

    begin->value = value;
    begin->next = LIST;

    LIST = begin;
    COUNT++;
}

/* function which allows to append another LinkedList in the end of current list */

template<typename T>
void LinkedList<T>::append(const LinkedList<T> &value) {
    // if another list is empty then we are printing Error

    if (value.isEmpty())
        std::cerr << "Error! Nothing to insert so as list are empty." << std::endl;

        // if another list is not empty then we can append this list on begin

    else {
        // create copy of list value

        LinkedList<T> *copy = new LinkedList<double>;

        for (int i=value.length()-1; i >= 0; i--)
            copy->append(value.at(i));

        // set link last node on the next node of another list as link on the begin node in current list

        copy->end()->next = LIST;
        LIST = copy->begin();

        // addition count of elements in old list to count of elements in another list

        COUNT += value.count();
    }
}

/* method which allows insert node in some position without losing ties */

template<typename T>
void LinkedList<T>::insert(int index, const T &value) {
    // if index is less than count of elements in list then we can make insert

    if (index < this->COUNT) {
        // if index is equal null then we can make insert in begin of list

        if (index == 0) {
            append(value);
            return;
        }

        // in other cases we will make insert in some position of list

        else {
            Node *tmp = new Node();
            tmp->value = value;

            Node *begin = LIST;
            Node *next = begin->next;

            // look for position in list

            for (int i = 0; i < index-1; i++) {
                next = next->next;
                begin = begin->next;
            }

            // insert value with saves ties

            tmp->next = next;
            begin->next = tmp;

            // addition count of elements

            COUNT++;
        }
    }

    // if index is greater than count of elements in list then we are printing Error

    else {
        std::cerr << "Error! index must be less than count of elements in list." << std::endl;
    }
}

/* method which allows insert another list in some position at our list */

template<typename T>
void LinkedList<T>::insert(int index, const LinkedList<T> &value) {
    // if index is less than count of elements in list then we can make insert

    if (index < this->COUNT) {
        // if index is equal null then we can make insert on begin

        if (index == 0) {
            append(value);
            return;
        }

        // in other cases we will make insert in some position of the list

        else {
            LinkedList<T> *copy = new LinkedList<T>;
            Node *begin = LIST;
            Node *tmp = LIST;
            Node *next = tmp->next;

            // look for position in list

            for (int i = 0; i < index-1; i++) {
                next = next->next;
                tmp = tmp->next;
            }

            // fill copy list

            for (int i=value.length()-1; i >= 0; i--)
                copy->append(value.at(i));

            // insert another list with saves ties

            copy->end()->next = next;
            tmp->next = copy->begin();
            LIST = begin;

            // addition count of elements in old list to count of elements in another list

            COUNT += value.count();
        }
    }

        // if index is greater than count of elements in list then we are printing Error

    else {
        std::cerr << "Error! index must be less than count of elements in list." << std::endl;
    }
}


/* method which allows delete node with some value */

template<typename T>
void LinkedList<T>::remove(T value) {
    if (LIST == nullptr) {
        std::cerr << "Error! List can't be empty." << std::endl;
        return;
    }

    Node *begin = LIST;

    // if element is situating in the top node then we are remove this node

    if (begin->value == value) {
        LIST = LIST->next;

        delete begin;
        this->COUNT--;
        return;
    }

    Node *next = begin->next;

    // look for element in nodes

    while (next) {
        if (next->value == value)
            break;

        begin = next;
        next = next->next;
    }

    // if we can't found element in the nodes then we are printing information about this error

    if (!next)
        std::cerr << "Can't remove value! Not match found." << std::endl;

    // if we were found element in some node then we are removing this node with saving ways

    else {
        begin->next = next->next;
        delete next;
        this->COUNT--;
    }
}

/* method which allows delete node in the list for some index */

template<typename T>
void LinkedList<T>::remove(const int index) {
    // if index is equal or greater than count elements in list we are print Error

    if (index >= this->COUNT) {
        std::cerr << "Error! Index must be less than count of elements in list." << std::endl;
        return;
    }

        // looking for element in nodes by index and remove it

    else {
        Node *begin = LIST;

        // if index equal 0 then we are removing element from top node with saving ways

        if (index == 0) {
            LIST = LIST->next;

            delete begin;
            this->COUNT--;
            return;
        }

        Node *next = begin->next;

        // look for position in list

        for (int i = 1; i < index && next; i++) {
            begin = next;
            next = next->next;
        }

        // remove element from position in list

        begin->next = next->next;
        delete next;
        this->COUNT--;
    }
}

/* method which allows make reverse the current list */

template <typename T>
void LinkedList<T>::reverse() {
    Node *reverse = nullptr;

    int reverseCount = size();

    while (LIST) {
        Node *begin = new Node();
        begin->value = LIST->value;
        begin->next = reverse;

        reverse = begin;

        LIST = LIST->next;  
    }

    clear();

    LIST = reverse;
    COUNT = reverseCount;
}

/* method which allows counting nodes in list and are returning theirs count */

template<typename T>
int LinkedList<T>::count() const {
    return this->COUNT;
}

/* simple method for print list on display */

template<typename T>
void LinkedList<T>::print() {
    Node *begin = LIST;

    // until the node is empty we will be printing their elements from nodes

    std::cout << "{ ";

    while (begin) {
        std::cout << begin->value;

        if (begin->next != nullptr)
            std::cout << ", ";

        begin = begin->next;
    }

    // print the transition to a new line

    std::cout << " }";
    std::cout << std::endl;
}

/* function for monitoring state of list */

template<typename T>
bool LinkedList<T>::isEmpty() const {
    // if list are empty then we return { true }

    if (!LIST)
        return true;

    // if list are not empty then we return { false }

    else
        return false;
}

/* function which allows known size of list */

template<typename T>
int LinkedList<T>::size() const {
    return this->COUNT;
}

/* functions which return size of list */

template<typename T>
int LinkedList<T>::length() const {
    return this->COUNT;
}

/* method which allows get access to last element in list */

template<typename T>
auto LinkedList<T>::end() const {
    Node *begin = LIST;

    while (begin->next)
        begin = begin->next;

    return begin;
}

/* method which allows get access until element in one of the nodes in list */

template<typename T>
T LinkedList<T>::at(int index) const {
    // if we will have been had problems with our list we can easily print Error on display

    try {

        // we can accessed to element in list if index are less than count of elements

        if (index < this->COUNT) {
            Node *begin = LIST;

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

/* exactly the same method as previous method { T LinkedList<T>::at(int index) } */

template<typename T>
T LinkedList<T>::value(int index) const {
    return at(index);
}

/* operator which allows get access until element in list via { T LinkedList<T>::at(int index) } */

template<typename T>
T &LinkedList<T>::operator[](int index) {
    return at(index);
}

/* method which allows get access to the first element in list */

template<typename T>
auto LinkedList<T>::begin() const {
    return this->LIST;
}

/* method which allows you to free up memory and delete all elements in array */

template<typename T>
void LinkedList<T>::clear() {
    if (this->isEmpty())
        return;

    Node *pointer = LIST;
    Node *trash;

    // while pointer on the LIST isn't empty we'll be remove nodes

    while (pointer)
    {
        trash = pointer;
        pointer = pointer->next;
        delete [] trash;
    }

    COUNT = 0;
}

/* method which allows return first element in list */

template<typename T>
T &LinkedList<T>::first() {
    return this->value(0);
}

/* method which allows return last element in list */

template<typename T>
T &LinkedList<T>::last() {
    return this->value(COUNT-1);
}


#endif //LINKEDLIST_LINKEDLIST_H