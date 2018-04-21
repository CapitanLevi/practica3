
#include <fstream>
#include <iostream>
using namespace std;

void IntToBin(int A, char* bin);

int main(){
    char Letra;
    cout<<"Ingreseñ letra a pasar a binario con ASCII: ";
    cin>>Letra;
    int asciiLetra = Letra;
    char bin[8];
    IntToBin(asciiLetra,bin);
    cout<<"El decimal de la letra "<<Letra<<" es: "<<asciiLetra<<endl;
    cout<<"El binario de la letra "<<Letra<<" es: "<<bin<<endl;
    return 0;
}

void IntToBin(int A, char* bin){
    for(int i=7;i>=0;i--){
        *(bin+i) = (A%2)+48;
        A/=2;
    }
}
