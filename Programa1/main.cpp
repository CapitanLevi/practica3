#include <fstream>
#include <iostream>
#include <exception>
using namespace std;

int getCount(char* array,int n){
    //Cuenta el número de ceros del bloque anterior
    int count= 0;
    for(int i=0;i<n;i++){
        if(array[i]-48==0){
            count++;
        }
    }
    return count;
}


void Codificacion1(ifstream* lectura,ofstream* escritura){
    cout << "Codicacion 1 escogida" << endl;

    int n;
    cout << "Ingrese tamaño del bloque:" << endl;
    cin >> n;

    lectura->seekg(0, ios::end);
    int fin = lectura->tellg() - 1;
    lectura->seekg(0, ios::beg);
    char bloqueActual[100], bloquePasado[100], bloqueConvertido[100];

    bool PrimerBloque = true;
    int indice = 0;

    while(!lectura->eof()){
        lectura->read(bloqueActual,n);

        for(int i=0;i<n;i++){
            bloqueConvertido[i]=bloqueActual[i];
        }

        if(indice>=fin){
            break;
        }

        if(PrimerBloque){
            for(int i=0;i<n;i++){
                if(bloqueActual[i]-48==0){
                    bloqueConvertido[i]=49;
                }
                else {
                    bloqueConvertido[i]=48;
                }
            }
        }
        else {
            int numZeros = getCount(bloquePasado,n);
            cout << numZeros<<endl;

            if (n-numZeros==numZeros){ //Iguales
                for(int i=0;i<n;i++){
                    if(bloqueActual[i]-48==0){
                        bloqueConvertido[i]=49;
                    }
                    else {
                        bloqueConvertido[i]=48;
                    }
                }
            }
            else if(n-numZeros>numZeros){ //Hay más 1
                for(int i=2;i<n;i+=3){
                    cout << int(bloqueActual[i]);
                    if(bloqueActual[i]-48==0){
                        bloqueConvertido[i]=49;
                    }
                    else {
                        bloqueConvertido[i]=48;
                    }
                }
            } else { //Hay más 0
                for(int i=1;i<n;i+=2){
                    if(bloqueActual[i]-48==0){
                        bloqueConvertido[i]=49;
                    }
                    else {
                        bloqueConvertido[i]=48;
                    }
                }
            }
        }

        cout << "Actual: " << bloqueActual << endl;
        cout << "Convertido: " << bloqueConvertido << endl;

        if(lectura->eof() && indice<fin){
            escritura->write(bloqueConvertido,n-indice);
        }
        else {
            escritura->write(bloqueConvertido,n);
        }


        for(int i=0;i<n;i++){
            bloquePasado[i] = bloqueActual[i];
        }

        PrimerBloque=false;
        indice += n;
    }
}

void Codificacion2(ifstream* lectura,ofstream* escritura){
    cout << "Codicacion 2 escogida" << endl;

    int n;
    cout << "Ingrese tamaño del bloque:" << endl;
    cin >> n;

    lectura->seekg(0, ios::end);
    int fin = lectura->tellg() - 1;

    lectura->seekg(0, ios::beg);
    char bloqueActual[100], bloquePasado[100], bloqueConvertido[100];
    int indice = 0;

    while(!lectura->eof()){
        lectura->read(bloqueActual,n);

        if(indice>=fin){
            break;
        }

        if(lectura->eof() && indice<fin){
            bloqueConvertido[0]=bloqueActual[fin-indice-1];
            for(int i=1;i<fin-indice;i++){
              bloqueConvertido[i]=bloqueActual[i-1];
            }
            escritura->write(bloqueConvertido,fin-indice);
        }
        else {
            bloqueConvertido[0]=bloqueActual[n-1];
            for(int i=1;i<n;i++){
              bloqueConvertido[i]=bloqueActual[i-1];
            }
            escritura->write(bloqueConvertido,n);
        }

        cout << "Actual: " << bloqueActual << endl;
        cout << "Convertido: " << bloqueConvertido << endl;

        for(int i=0;i<n;i++){
            bloquePasado[i] = bloqueActual[i];
        }

        indice+= n;
    }
}

int main()
{

    string mensajeFile;
    cout << "Ingrese la ruta del mensaje a codificar:" << endl;
    cin >> mensajeFile;

    ifstream lectura;
    lectura.open(mensajeFile, ios::binary);

    if(lectura.fail()){
        cout << "Error al abrir el archivo de lectura\n";
        return -1;
    }

    string codificadoFile;
    cout << "Ingrese la ruta de salida:" << endl;
    cin >> codificadoFile;
    ofstream escritura;

    escritura.open(codificadoFile);

    if(escritura.fail()){
        cout << "Error al abrir el archivo de escritura\n";
        return -1;
    }

    int Metodo;
    cout << "Ingrese método de codificacion (1 o 2):" << endl;
    cin >> Metodo;

    switch (Metodo) {
    case 1:
        Codificacion1(&lectura, &escritura);
        break;
    case 2:
        Codificacion2(&lectura, &escritura);
        break;
    default:
        cout << "Método incorrecto \n";
        return -1;
    }
    lectura.close();
    escritura.close();
}

