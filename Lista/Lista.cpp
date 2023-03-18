// Lista.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "LinkedList.h"

int main() {
    std::cout << "Hello World!\n";

    LinkedList linkedList;
    linkedList.AddNode(123);
    linkedList.AddNode(1234);
    linkedList.AddNode(87);
    linkedList.PrintNodes();

    std::cout << linkedList.FindNode(87) << std::endl;

    linkedList.InsertNode(linkedList.FindNode(1234), 15);
    linkedList.PrintNodes();
    std::cout << " " << std::endl;
    linkedList.DeleteNode(linkedList.FindNode(15));
    linkedList.PrintNodes();
}