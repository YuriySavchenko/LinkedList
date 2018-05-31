#include <iostream>
#import "LinkedList.h"

int main() {
    LinkedList<double> list;
    LinkedList<double> list_new;

    for (int i=1; i < 10; i++)
        list.addElement(i);

    for (int i=20; i < 30; i++)
        list_new.addElement(i);

    list.printList();
    list_new.printList();

    return 0;
}