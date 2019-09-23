#include <iostream>
#import "LinkedList.h"

int main() {
    LinkedList<double> list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list.print();
    list.reverse();
    list.print();

    return 0;
}