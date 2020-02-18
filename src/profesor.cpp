#include "profesor.h"

profesor::profesor()
{
    //ctor
}

profesor::~profesor()
{
    //dtor
}
void profesor::saludar(){

    cout<<"Hola"<<endl;
}

 void profesor::agregar_nombres (){
    infile.open("nombres.txt");
    //outfile.open("grupos.txt");
    string line;
    int lineNum = 0 ;
    while(getline(infile,line)){
        cout << line << "\n";
        cout << ++lineNum << "\n";
        //break;
    }
    //outfile.close();
    infile.close();
 }

 void profesor::mostrar_nombres(){
     outfile.open("nombres.txt");
     string line;
     int lineNum = 0;
     while(getline(cin,line)){
        cout<< line<<"\n";
        cout << ++lineNum << "\n";
     }
 }


