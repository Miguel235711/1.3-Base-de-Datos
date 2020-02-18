#ifndef MATERIA_H
#define MATERIA_H

#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>
//#include<string>
#include<map>
#include<utility>

using namespace std;

class materia
{
    public:
        materia();
        materia(string clave,string nombre,int unidades,int CIP,vector<string>programasAcademicos,vector<string>requisitos);
        virtual ~materia();
        void agregarMateria();
        void borrarMateria(string clave);
        void editarMateria(string clave);
        void mostrarMaterias(); /// mostrar todos los atributos
        void loadFile();

    protected:

    private:
        static const string fileName;
        string clave,nombre;
        int unidades,CIP;
        vector<string> programasAcademicos,requisitos;
        map<string,materia*>materias;
        ifstream inFileStream;
        ofstream outFileStream;
        vector<string> separateByOrChar(string value);
        void writeFile();
        void overwriteMateria();
        template<class T>
        void mostrarVector(vector<T>&v);
};

#endif // MATERIA_H
