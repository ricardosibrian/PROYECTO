#include <iostream>
#include <locale>

int main() {
    // Configura la consola para admitir caracteres anchos
    setlocale(LC_ALL, "");

    // Imprime el carácter Unicode U+0628 (ب)
    std::wcout << L"\u0628" << std::endl;

    // Lee un carácter desde la consola
    wchar_t caracter_ingresado;
    std::wcout << L"Ingrese un carácter: ";
    std::wcin >> caracter_ingresado;

    // Comprueba si el carácter ingresado es igual al carácter Unicode U+0628 (ب)
    if (caracter_ingresado == L'\u062A') {
        std::wcout << L"1: Se detectó el carácter árabe." << std::endl;
    } else {
        std::wcout << L"2: No se detectó el carácter árabe." << std::endl;
    }

    return 0;
}