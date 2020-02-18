#ifndef PROFESOR_H
#define PROFESOR_H
#include <iostream>
#include <fstream>
using namespace std ;


class profesor
{
    public:
        profesor();
        void saludar();
        void mostrar_nombres ();
        void agregar_nombres ();
        virtual ~profesor();

    protected:

    private:
        int nomina,CIP;
        string nombre_profesor;
        ifstream infile;
        ofstream outfile;
};

#endif // PROFESOR_H
