#include "materia.h"

materia::materia()
{
    //ctor

}

materia::~materia()
{
    //dtor
}

materia::materia(string clave,string nombre,int unidades,int CIP,vector<string>programasAcademicos,vector<string>requisitos){
    this->clave=clave;
    this->nombre=nombre;
    this->unidades=unidades;
    this->CIP=CIP;
    this->programasAcademicos=programasAcademicos;
    this->requisitos=requisitos;
}


const string materia::fileName = "materias.txt";

vector<string> materia::separateByOrChar(string value){
    char * pch;
    char char_array[value.size()];
    vector<string>answer;
    strcpy(char_array,value.c_str());
    pch = strtok(char_array,"|");
    while(pch){
        answer.push_back((string)pch);
        pch = strtok(NULL,"|");
    }
    return answer;
}

void materia::agregarMateria(){
    //string fileNameLocal = fileName;
    cout << "ingresa clave: ";
    cin >> clave;
    overwriteMateria();
    cout << "Materia agregada exitosamente\n";
}
void materia::loadFile(){
    inFileStream.open(fileName);
    string unidadesStr,programasAcademicosStr,requisitosStr,CIPStr;
    while(getline(inFileStream,clave)){/// leer linea clave
        ///leer nombre, CIP, unidades, lista de programa separados por | , lista de requisitos separados por |
        getline(inFileStream,nombre);
        getline(inFileStream,CIPStr);
        std::string::size_type sz;
        CIP = stoi(CIPStr,&sz);
        getline(inFileStream,unidadesStr);
        unidades = stoi(unidadesStr,&sz);
        getline(inFileStream,programasAcademicosStr);
        programasAcademicos = separateByOrChar(programasAcademicosStr);
        getline(inFileStream,requisitosStr);
        requisitos = separateByOrChar(requisitosStr);
        /// insert in map
        //pair<string,materia> currentMa
        //pair<string,materia*>pa= ;
        materias.insert(make_pair(clave,new materia(clave,nombre,unidades,CIP,programasAcademicos,requisitos)));
        for(auto it = materias.begin(); it!=materias.end() ; it++){
            cout << "clave: " << it->second->clave << "\n";
            cout << "nombre: "<< it->second->nombre << "\n";
            cout << "programas size: " << it->second->programasAcademicos.size() << "\n";
        }
        //materias.insert(make_pair(materia.clave,new materia(clave,nombre,unidades,CIP,programasAcademicos,requisitos)));
    }
    inFileStream.close();
}
void materia::writeFile(){
    outFileStream.open(fileName);
    for(auto it=materias.begin();it!=materias.end();it++){
        outFileStream << it->second->clave << "\n";
        outFileStream << it->second->nombre << "\n";
        outFileStream << it->second->CIP << "\n";
        outFileStream << it->second->unidades << "\n";
        for(auto it2 = it->second->programasAcademicos.begin() ; it2!=it->second->programasAcademicos.end();it2++){
            outFileStream << *it2 << "|";
        }
        outFileStream << "|\n";
        for(auto it2 = it->second->requisitos.begin() ; it2!=it->second->requisitos.end();it2++){
            outFileStream << *it2 << "|";
        }
        outFileStream << "|\n";
    }
    outFileStream.close();
}
void materia::borrarMateria(string clave){
    auto it = materias.find(clave);
    if(it==materias.end()){
        cout << "Clave no existe";
    }else{
        materias.erase(it);
        writeFile();
        cout << "Materia con clave " << clave << " ha sido borrada exitosamente";
    }
    cout << "\n";
}
void materia::editarMateria(string clave){
    this->clave=clave;
    if(materias.find(clave)!=materias.end()){
        overwriteMateria();
    }else{
        cout << "Clave no existe\n";
    }
}

void materia::overwriteMateria(){
    cout << "ingresa nombre: ";
    cin >> nombre;
    cout << "ingresa CIP: ";
    cin >> CIP;
    cout << "ingresa unidades: ";
    cin >> unidades;
    ///checar que clave no esté repetida
    programasAcademicos = requisitos = vector<string>(0);
    auto it = materias.find(clave);
    auto materiaAMeter = new materia(clave,nombre,unidades,CIP,programasAcademicos,requisitos);
    if(it==materias.end()){
        materias.insert(make_pair(clave,materiaAMeter));
    }else{
        it->second = materiaAMeter;
    }
    writeFile();
}

void materia::mostrarMaterias(){
    cout << "Materias:\n";
    cout << "------------------\n";
    for(auto it=materias.begin();it!=materias.end();it++){
        cout << it->second->clave << "\n";
        cout << it->second->nombre << "\n";
        cout << it->second->CIP << "\n";
        cout << it->second->unidades << "\n";
        cout << "/tProgramas Academicos:\n";
        cout << "--------\n";
        mostrarVector(it->second->programasAcademicos);
        cout << "--------\n";
        cout << "/tRequisitos:\n";
        cout << "--------\n";
        mostrarVector(it->second->requisitos);
        cout << "--------\n";
    }
    cout << "------------------\n";
}
template<class T>
void materia::mostrarVector(vector<T>&v){
    for(auto it = v.begin(); it!=v.end();it++){
        cout << *it << "|";
    }
}
