#include <iostream>
#include "heap.hpp"

using namespace std;

struct CharCode
{
    char ch;
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

        int sum = left->freq + right->freq;
        minHeap.insert(new Node{'\0', sum, left, right});
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
    // Pregunta al usuario por una palabra
    cout << "Ingrese una palabra: ";
    string palabra;
    getline(cin, palabra);

    // Codifica la palabra ingresada
    string textoCodificado;
    for (char caracter : palabra)
    {
        for (int i = 0; i < huffmanCodeSize; ++i)
        {
            if (huffmanCode[i].ch == caracter)
            {
                textoCodificado += huffmanCode[i].code;
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
    Node *nodeA = new Node{'A', 1, nullptr, nullptr};
    Node *nodeB = new Node{'B', 3, nullptr, nullptr};
    Node *nodeC = new Node{'C', 7, nullptr, nullptr};

    // Crear el montículo e insertar los nodos
    MinHeap minHeap;
    minHeap.insert(nodeA);
    minHeap.insert(nodeB);
    minHeap.insert(nodeC);

    CharCode huffmanCode[100]; // Asumiendo un máximo de 100 caracteres

    buildHuffmanTree(minHeap, huffmanCode);

    // Aqui se puede llamar esta funcion para codificar. Lo haremos en la ETAPA V
    // codificarPalabra(huffmanCode, 3);

    return 0;
}
