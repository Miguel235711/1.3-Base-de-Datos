#ifndef GRUPO_H
#define GRUPO_H

#include<iostream>
#include<fstream>
#include<map>

using namespace std;

class grupo
{
    public:
    grupo();
    grupo(string CRN, string claveMateria, string nominaProfesor, string horario,int numGrupo){
        this->CRN = CRN;
        this->claveMateria = claveMateria;
        this->nominaProfesor = nominaProfesor;
        this->horario = horario;
        this->numGrupo = numGrupo;
    }
    void printlist();
    void addlist();
    void deletelist();
    void editlist();
    void loadFile();

    virtual ~grupo();

    protected:

    private:
        ifstream infile;
        ofstream outfile;
        map<string,grupo*>grupos;
        string CRN,claveMateria,nominaProfesor,horario;
        int numGrupo;

        void writeFile();
        void overwriteGrupo();
};

#endif // GRUPO_H
