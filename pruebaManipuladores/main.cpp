//***********************************************
//  archiv02.cpp
//  Demuestra el uso de manipuladores
//  ©1999, Jaime Virgilio Gómez Negrete
//***********************************************

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
    ofstream archivo("Datos.txt");  // constructor de ofstream
    int numero;

    cout << "Introduzca un numero:" << endl;
    cin >> numero;
    archivo << "El valor introducido en base 10 es: " << numero << endl;

    archivo << resetiosflags(ios::dec);
    archivo << setiosflags(ios::oct);
    archivo << "en base octal es: " << numero << endl;

    archivo << resetiosflags(ios::oct);
    archivo << setiosflags(ios::hex);
    archivo << "y en base hexadecimal es: " << numero << endl;
    archivo << setiosflags(ios::uppercase|ios::showbase);
    archivo << "utilizando los manipuladores uppercase y showbase"
<< " el valor es: " << numero << endl;

    archivo << resetiosflags(ios::uppercase|ios::showbase);
    archivo << resetiosflags(ios::hex);
    archivo << setiosflags(ios::showpos|ios::showpoint|ios::fixed);
    archivo << "Utilizando los manipuladores showpos," << " showpoint y fixed: "
<< (float)numero << endl;

    archivo << resetiosflags(ios::showpos|ios::showpoint|ios::fixed);
    archivo << "Finalmente el valor es " << numero << endl;

    archivo.close();

    return 0;
}
