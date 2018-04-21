#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void IntToBin(int, char*);

int main()
{
    char *bin[8];
    ofstream archivo;
    string nombreArchivo,texto;
    cout<<"\nDigite el nombre del archivo: ";
    getline(cin,nombreArchivo);
    archivo.open(nombreArchivo.c_str(),ios::out); //Creando y abriendo el archivo
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo.";
        exit(1);
    }
    cout<<"\nDigite el texto del archivo: ";
    getline(cin,texto);

    IntToBin()
    archivo.close();
    return 0;
}

void IntToBin(int A, char* bin){
    for(int i=7;i>=0;i--){
        *(bin+i) = (A%2)+48;
        A/=2;
    }
}
