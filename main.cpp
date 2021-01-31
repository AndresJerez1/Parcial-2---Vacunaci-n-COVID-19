
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <cstdlib>


using namespace std;

float entrada(){                      //Función usada para las entradas
  float i;
  cin >> i;
  while(!cin.good()){                         
    cout << "Entrada no valida" << endl;
    cin.clear();
    cin.ignore(10000,'\n');
    cin >> i; 
  }
  return i;
}

class vacunas{

};

int main() {
  
  int eleccion, n_habitantes, n_contagiados, n_hospitales, n_persalud, n_adultomayor, distancia, selector;
  string ciudad;

  ifstream archivo("estadisticas.txt",ios::in); //Lectura del archivo

  while(!archivo.eof()){
    archivo>>ciudad>>n_habitantes>>n_contagiados>>n_hospitales>>n_persalud>>n_adultomayor>>distancia; //orden de lectura 

  }

  cout<<"Si quiere ver las ciudades con mas de 500 km de distancia presione 7"<<endl;
  cin>>selector;
  switch(selector){
    case 7:
      if(distancia>500){
        cout <<left << setw(15)<<ciudad<<left << setw(10)<<distancia <<endl;
      }
      break;
    default:
      break;
  }

  /*cout<<"Seleccione la opción que desea realizar: ";
  cout<<"\n1.Actualizar número de contagiados";
  cout<<"\n2.Revisar estadisticas por ciudad";
  cout<<"\n3.Ingresar número de vacunas y ejecutar el programa\n";
  eleccion=entrada();
  while(eleccion <= 0 || eleccion >= 4){
        cout << "Opcion no valida!\nIngrese nuevamente su elección" << endl;
        eleccion = entrada();
  }
  
  
  switch(eleccion){
    case 1:
    

    case 2:


    case 3:


    default:

  }*/


}