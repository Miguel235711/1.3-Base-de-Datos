#include <iostream>
#include "include/profesor.h"
using namespace std;

int main()
{
    int centinela, opcion;

    profesor misa;

  do{
        cout<<"Escribe 1 para agregar nombres"<<endl;
        cin>>opcion;
        cout<<"Escribe 2 para mostrar los nombres"<<endl;
        cin >>opcion;
        cout<<"Escribe -1 para salir"<<endl;
        cin>> centinela;
        if(opcion == 1) misa.agregar_nombres();
        if(opcion==2) misa.mostrar_nombres();
    }while(centinela != -1);

   // outfile.close();
    //infile.close();
    return 0;


}


