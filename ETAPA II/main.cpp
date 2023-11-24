#include <iostream>
#include "heap.hpp"

int main()
{
     // Crear nodos independientes
    Node *nodeA = new Node{"\u062A", 0.1, nullptr, nullptr};  // Cambio de int a double
    Node *nodeB = new Node{"\u0628", 0.3, nullptr, nullptr};  // Cambio de int a double
    Node *nodeC = new Node{"\u0627", 0.7, nullptr, nullptr};  // Cambio de int a double

    // Crear el montículo e insertar los nodos
    MinHeap minHeap;
    minHeap.insert(nodeA);
    minHeap.insert(nodeB);
    minHeap.insert(nodeC);

    // Mostrar el tamaño del montículo
    std::cout << "Tamano del monticulo: " << minHeap.getSize() << std::endl;

    // Extraer el nodo con la frecuencia mínima
    Node *minNode = minHeap.extractMin();

    // Mostrar la información del nodo extraído
    std::cout << "Nodo extrado: " << minNode->ch << " " << minNode->prob << std::endl;

    // Liberar memoria de los nodos
    delete nodeA;
    delete nodeB;
    delete nodeC;

    return 0;
}
