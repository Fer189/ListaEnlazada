// Lista.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "LinkedList.h"

int main() {
    std::cout << "Hello World!\n";

    LinkedList linkedList;
    bool terminado = false;
    while (!terminado) {
        int option = 0;
        std::cout << " " << std::endl;
        std::cout << "1.- Agregar nodo" << std::endl;
        std::cout << "2.- Imprimir lista" << std::endl;
        std::cout << "3.- Buscar un nodo" << std::endl;
        std::cout << "4.- Eliminar ultimo nodo" << std::endl;
        std::cout << "5.- Eliminar lista" << std::endl;
        std::cout << "6.- Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> option;
        int valor = 0;
        Node* nodoSeleccionado;
        switch (option) {
        case 1:
            std::cout << "Ingrese el valor del nodo que desea agregar: ";
            std::cin >> valor;
            linkedList.AddNode(valor);
            break;
        case 2:
            linkedList.PrintNodes();
            break;
        case 3:
            std::cout << "Ingrese el valor del nodo que desea encontrar: ";
            std::cin >> valor;
            nodoSeleccionado = linkedList.FindNode(valor);
            if (nodoSeleccionado != nullptr) {
                std::cout << "Nodo encontrado!" << std::endl;
                while (!terminado) {
                    std::cout << "1.- Eliminar nodo" << std::endl;
                    std::cout << "2.- Insertar un nuevo nodo" << std::endl;
                    std::cout << "Seleccione una opcion: ";
                    std::cin >> valor;
                    switch (valor) {
                    case 1:
                        linkedList.DeleteNode(nodoSeleccionado);
                        std::cout << "Nodo eliminado!" << std::endl;
                        terminado = true;
                        break;
                    case 2:
                        std::cout << "Ingrese el valor del nuevo nodo: ";
                        std::cin >> valor;
                        linkedList.InsertNode(nodoSeleccionado, valor);
                        std::cout << "Nodo insertado!" << std::endl;
                        terminado = true;
                        break;
                    default:
                        std::cout << "Seleccion invalida!" << std::endl;
                        break;
                    }
                }
                terminado = false;
            }
            else {
                std::cout << "Nodo no encontrado!" << std::endl;
            }
            break;
        case 4:
            switch (linkedList.DeleteNode(linkedList.GetLast())) {
            case 0:
                std::cout << "La lista esta vacia!" << std::endl;
                break;
            case 1:
                std::cout << "Nodo principal eliminado: La lista esta vacia!" << std::endl;
                break;
            case 2:
                std::cout << "Nodo eliminado!" << std::endl;
                break;
            }
            
            break;
        case 5:
            linkedList.ClearList();
            std::cout << "Lista enlazada eliminada!" << std::endl;
            break;
        case 6:
            terminado = true;
            break;
        default:
            std::cout << "Seleccion invalida!" << std::endl;
            break;
        }
    }
    return 0;
}