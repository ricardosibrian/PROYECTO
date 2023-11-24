#include <iostream>
#include "heap.hpp"

using namespace std;

struct CharCode
{
    std::string ch;
    string code;
};

void encode(Node *root, string str, CharCode *huffmanCode, int &index)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
    {
        huffmanCode[index++] = {root->ch, str};
    }

    encode(root->left, str + "0", huffmanCode, index);
    encode(root->right, str + "1", huffmanCode, index);
}

void buildHuffmanTree(MinHeap &minHeap, CharCode *huffmanCode)
{
    while (minHeap.getSize() > 1)
    {
        Node *left = minHeap.extractMin();
        Node *right = minHeap.extractMin();

        double sum = left->prob + right->prob;  // Cambio de int a double
        minHeap.insert(new Node{"\0", sum, left, right});
    }

    Node *root = minHeap.extractMin();

    int index = 0;
    encode(root, "", huffmanCode, index);

    cout << "Huffman Codes are :\n"
         << '\n';
    for (int i = 0; i < index; ++i)
    {
        cout << huffmanCode[i].ch << " " << huffmanCode[i].code << '\n';
    }
}

void codificarPalabra(const CharCode *huffmanCode, int huffmanCodeSize)
{
    // Pregunta al usuario por una palabra con caracteres árabes
    cout << "Ingrese una palabra con caracteres árabes: ";
    string palabra;
    getline(cin, palabra);

    // Codifica la palabra ingresada
    string textoCodificado;
    size_t longitudCaracterArabe = 2; // Longitud esperada de un carácter árabe en formato "\uXXXX"

    for (size_t i = 0; i < palabra.size(); i += longitudCaracterArabe)
    {
        // Extrae el carácter árabe completo
        string caracterArabe = palabra.substr(i, longitudCaracterArabe);

        // Realiza la comparación y concatena el código correspondiente
        for (int j = 0; j < huffmanCodeSize; ++j)
        {
            if (huffmanCode[j].ch == caracterArabe)
            {
                textoCodificado += huffmanCode[j].code;
                break;
            }
        }
    }

    // Imprime el texto codificado
    cout << "Texto codificado: " << textoCodificado << endl;
}

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

    CharCode huffmanCode[100]; // Asumiendo un máximo de 100 caracteres

    buildHuffmanTree(minHeap, huffmanCode);

    // Aquí se puede llamar esta función para codificar. Lo haremos en la ETAPA V
    codificarPalabra(huffmanCode, 3);

    return 0;
}
