#include "profesor.h"

profesor::profesor()
{
    //Constructor
}

profesor::~profesor()
{
    //Destructor
}
profesor::profesor(string nominaProfesor,string nombre,string CIP){
    this->nominaProfesor=nominaProfesor;
    this->nombre=nombre;
    this->CIP=CIP;
}
void profesor::loadFile(){
    infile.open("profesores.txt");
    string numProfeStr;
    std::string::size_type sz;
    while(getline(infile,nominaProfesor)){
        getline(infile,nombre);
        getline(infile,CIP);
        profesores.insert(make_pair(nominaProfesor,new profesor(nominaProfesor,nombre,CIP)));
    }
    cout << "grupos cargados de archivo:\n";
    cout << "-------\n";
    for(auto it =profesores.begin(); it!= profesores.end(); it ++ ) {
        cout << "it->first" << it ->first<< "\n";
    }
    cout << "--------\n";
}

void profesor::printlist(){
    cout << "Grupos:\n";
    cout << "--------\n";
    for(auto it = profesores.begin(); it!=profesores.end();it++){
        cout << "Nomina de profesor: " << it->second->nominaProfesor << "\n";
        cout << "nombre: " << it->second->nombre << "\n";
        cout << "CIP: " << it->second->CIP << "\n";
    }
    cout << "--------\n";
}

void profesor::writeFile(){
    outfile.open("profesores.txt");
    for(auto it=profesores.begin();it!=profesores.end();it++){
        outfile << it->second->nominaProfesor << "\n";
        outfile << it->second->nombre << "\n";
        outfile << it->second->CIP << "\n";
    }
    outfile.close();
}

void profesor::addlist(){
    int opc=0;
    //int lineNum = 0 ;
    //cin >> line;
  //  cout << "addList before while\n";
    cout << "ingresa nominaProfesor: ";
    while(getline(cin,nominaProfesor)){
        overwriteProfesor();
        /*cout << "line:\n";
        outfile << line << "\n";*/
        //cout << ++lineNum << "\n";
        cout<<"Para seguir ingresando datos ingrese 0, sino presione otro numero: ";
        cout << "opc of addlist(): ";
        cin>>opc;
        if(opc!=0)
            break;
        getline(cin,nominaProfesor);
        cout << "ingresa nominaProfesor: ";
    }
}

void profesor::deletelist(){
    string nominaProfesor;
    cout << "ingresa nominaProfesor a borrar: ";
    getline(cin,nominaProfesor);
    profesores.erase(nominaProfesor);
    writeFile();
}

void profesor::editlist(){
    cout<< "Ingresa nominaProfesor a editar: ";
    getline(cin, nominaProfesor);
    cout << "profesor.nominaProfesor " <<nominaProfesor << "\n";
    if(profesores.find(nominaProfesor)!=profesores.end()){
        overwriteProfesor();
        cout << "nominaProfesor editado exitosamente\n";
    }else{
        cout << "nominaProfesor no existe\n";
    }
    //infile.close();
}

void profesor::overwriteProfesor(){
    cout << "ingresar nombre: ";
    getline(cin,nombre);
    cout << "ingresa CIP de profesor: ";
    getline(cin,CIP);
    auto it = profesores.find(nominaProfesor);
    profesor * profesorAMeter = new profesor(nominaProfesor,nombre,CIP);
    if(it==profesores.end()){
        profesores.insert(make_pair(nominaProfesor,profesorAMeter));
    }else{
        it->second=profesorAMeter;
    }
    printlist();
    //cout << "grupos.size(): " << grupos.size()<<"\n";
    writeFile();
}
