#ifndef profesor_h
#define profesor_h

#include<iostream>
#include<fstream>
#include<map>

using namespace std;

class profesor
{
    public:
    profesor();
    profesor(string nominaProfesor,string nombre,string CIP);

    void printlist();
    void addlist();
    void deletelist();
    void editlist();
    void loadFile();

    virtual ~profesor();

    protected:

    private:
        ifstream infile;
        ofstream outfile;
        map<string,profesor*>profesores;
        string nombre,nominaProfesor,CIP;

        void writeFile();
        void overwriteProfesor();
};

#endif // GRUPO_H
