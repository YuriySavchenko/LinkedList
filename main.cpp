#include <iostream>
#import "LinkedList.h"

int main() {
    LinkedList<double> list;
    LinkedList<double> list_new;

    for (int i=1; i < 11; i++)
        list.append(i);

    for (int i=21; i < 31; i++)
        list_new.append(i);

    list.print();
    list_new.print();
    list.insert(2, list_new);
    list.print();
    list_new.print();

    return 0;
}