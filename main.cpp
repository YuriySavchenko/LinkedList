#include <iostream>
#import "LinkedList.h"

int main() {
    LinkedList<double> list(5, 2.3);
    LinkedList<double> list_new(17, 45.2);

    list.print();
    list_new.print();

    return 0;
}