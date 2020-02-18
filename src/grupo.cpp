#include "grupo.h"

grupo::grupo()
{
    //Constructor
}

grupo::~grupo()
{
    //Destructor
}
void grupo::loadFile(){
    infile.open("grupos.txt");
    string numGrupoStr;
    std::string::size_type sz;
    while(getline(infile,CRN)){
        getline(infile,claveMateria);
        getline(infile,nominaProfesor);
        getline(infile,horario);
        getline(infile,numGrupoStr);
        numGrupo = stoi(numGrupoStr,&sz);
        grupos.insert(make_pair(CRN,new grupo(CRN,claveMateria,nominaProfesor,horario,numGrupo)));
    }
    cout << "grupos cargados de archivo:\n";
    cout << "-------\n";
    for(auto it = grupos.begin(); it!= grupos.end(); it ++ ) {
        cout << "it->first" << it ->first<< "\n";
    }
    cout << "--------\n";
}

void grupo::printlist(){
    cout << "Grupos:\n";
    cout << "--------\n";
    for(auto it = grupos.begin(); it!=grupos.end();it++){
        cout << "CRN: " << it->second->CRN << "\n";
        cout << "Clave de materia: " << it->second->claveMateria << "\n";
        cout << "Nomina de profesor: " << it->second->nominaProfesor << "\n";
        cout << "Numero de grupo: " << it->second->numGrupo << "\n";
        cout << "Horario: " << it->second->horario << "\n";
    }
    cout << "--------\n";
}

void grupo::writeFile(){
    outfile.open("grupos.txt");
    for(auto it=grupos.begin();it!=grupos.end();it++){
        outfile << it->second->CRN << "\n";
        outfile << it->second->claveMateria << "\n";
        outfile << it->second->nominaProfesor << "\n";
        outfile<< it->second->numGrupo << "\n";
        outfile << it->second->horario << "\n";
    }
    outfile.close();
}

void grupo::addlist(){
    int opc=0;
    //int lineNum = 0 ;
    //cin >> line;
  //  cout << "addList before while\n";
    cout << "ingresa CRN: ";
    while(getline(cin,CRN)){
        overwriteGrupo();
        /*cout << "line:\n";
        outfile << line << "\n";*/
        //cout << ++lineNum << "\n";
        cout<<"Para seguir ingresando datos ingrese 0, sino presione otro numero: ";
        cout << "opc of addlist(): ";
        cin>>opc;
        if(opc!=0)
            break;
        getline(cin,CRN);
        cout << "ingresa CRN: ";
    }
}

void grupo::deletelist(){
    int opc=1;
    string CRN;
    cout << "ingresa CRN a borrar: ";
    getline(cin,CRN);
    grupos.erase(CRN);
    writeFile();
}

void grupo::editlist(){
    int opc=1;
    cout<< "Ingresa CRN a editar: ";
    getline(cin, CRN);
    cout << "grupo.CRN " << CRN << "\n";
    if(grupos.find(CRN)!=grupos.end()){
        overwriteGrupo();
        cout << "grupo editado exitosamente\n";
    }else{
        cout << "CRN no existe\n";
    }
    //infile.close();
}

void grupo::overwriteGrupo(){
    cout << "ingresa clave de materia:";
    getline(cin,claveMateria);
    cout << "ingresa nomina de profesor: ";
    getline(cin,nominaProfesor);
    string numGrupoStr;
    cout << "ingresa numero grupo: ";
    getline(cin,numGrupoStr);
    std::string::size_type sz;
    numGrupo = stoi(numGrupoStr,&sz);
    cout << "ingresa horario: ";
    getline(cin,horario);
    cout << "sobreescribir: " << claveMateria << "\n";
    auto it = grupos.find(CRN);
    grupo * grupoAMeter = new grupo(CRN,claveMateria,nominaProfesor,horario,numGrupo);
    if(it==grupos.end()){
        grupos.insert(make_pair(CRN,grupoAMeter));
    }else{
        it->second=grupoAMeter;
    }
    printlist();
    //cout << "grupos.size(): " << grupos.size()<<"\n";
    writeFile();
}
