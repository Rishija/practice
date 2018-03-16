/*
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null. Create a new list which follows the same struture.
 */

#include "random_list.h"

int main() {
    
    List<int>list;
    
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    list.insert(60);
    list.insert(70);
    list.insert(80);
    list.insert(90);
    
    list.print();
    return 0;
}
