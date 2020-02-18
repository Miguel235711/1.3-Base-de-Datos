#include <iostream>
#include "include/profesor.h"
#include "include/materia.h"
#include "include/grupo.h"

using namespace std;

int main()
{
    materia laMateria;
    laMateria.loadFile();
    //laMateria.mostrarMaterias();
    //laMateria.borrarMateria("1");
    //laMateria.agregarMateria();
    //laMateria.editarMateria("1");
    return 0;
    grupo miGrupo;
    miGrupo.loadFile();
    int opc=0;
    cout<<"Seleccione opcion \n";
    cout<<"1. Imprimir\n";
    cout<<"2. Agregar\n";
    cout<<"3. Quitar\n";
    cout<<"4. Editar\n";
    string garbage;
    cout << "opc: ";
    cin>>opc;
    getline(cin,garbage);
    if(opc==1){
        miGrupo.printlist();
        opc=0;
    }else if(opc==2){
        //cout << "opc 2\n";
        miGrupo.addlist();
        opc=0;
    }else if(opc==3){
        miGrupo.deletelist();
        opc=0;
    }else if(opc==4){
        miGrupo.editlist();
    }
}


