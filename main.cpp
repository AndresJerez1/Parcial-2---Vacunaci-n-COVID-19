
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <cstdlib>


using namespace std;

fstream archivo; //Lectura del archivo

void leerArchivo()
  {
    ifstream archivo("estadisticas.txt",ios::in);
    string a;
    archivo.is_open();
    string A[5][7];

    for(int i=0;i<5;i++){

      for(int j=0;j<7;j++){

        archivo >> A[i][j];
        
      }
    }
  
    if (!archivo)
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( EXIT_FAILURE );
    } 

  };


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

void calc_dosis_camiones(int cantidad){
  int dosis[5];
  int camiones[5];

  dosis[0]=cantidad*0.08212076278;
  dosis[1]=cantidad*0.54895456143;
  dosis[2]=cantidad*0.03806423334;
  dosis[3]=cantidad*0.1635116009;
  dosis[4]=cantidad*0.1682709237;

  cout<<"La cantidad de dosis para Barranquilla: "<<dosis[0]<<endl;
  cout<<"La cantidad de dosis para Bogotá "<<dosis[1]<<endl;
  cout<<"La cantidad de dosis para Bucaramanga: "<<dosis[2]<<endl;
  cout<<"La cantidad de dosis para Cali: "<<dosis[3]<<endl;
  cout<<"La cantidad de dosis para Medellín: "<<dosis[4]<<endl;

  camiones[0]=(dosis[0]/2000)+1;
  camiones[1]=(dosis[1]/2000)+1;
  camiones[2]=(dosis[2]/2000)+1;
  camiones[3]=(dosis[3]/2000)+1;
  camiones[4]=(dosis[4]/2000)+1;

  cout<<"\nLa cantidad de camiones para Barranquilla: "<<camiones[0]<<endl;
  cout<<"La cantidad de camiones para Bogotá "<<camiones[1]<<endl;
  cout<<"La cantidad de camiones para Bucaramanga: "<<camiones[2]<<endl;
  cout<<"La cantidad de camiones para Cali: "<<camiones[3]<<endl;
  cout<<"La cantidad de camiones para Medellín: "<<camiones[4]<<endl;
};

void calc_paradas(){

  int paradas[5];

  paradas[0]=(1000.9/120)+1;
  paradas[1]=(0/120);
  paradas[2]=(424.2/120)+1;
  paradas[3]=(452.4/120)+1;
  paradas[4]=(416.4/120)+1;

  cout<<"\nLas paradas necesarias para Barranquilla son: "<<paradas[0]<<endl;
  cout<<"Las paradas necesarias para Bogotá son: "<<paradas[1]<<endl;
  cout<<"Las paradas necesarias para Bucaramanga son: "<<paradas[2]<<endl;
  cout<<"Las paradas necesarias para Cali son: "<<paradas[3]<<endl;
  cout<<"Las paradas necesarias para Medellín son: "<<paradas[4]<<endl;


};

void orden_tiempo(int cantidad){
  int persalud, mayores, resto;
  float personal[5],vac_hora_per[5],tiempo[5];

  ifstream archivo("estadisticas.txt",ios::in);
  string a;
  archivo.is_open();
  int A[5][7];

  for(int i=0;i<5;i++){

    for(int j=0;j<7;j++){

      archivo >> A[i][j];

      A[0][4]=90000;
      A[1][4]=200000;
      A[2][4]=50000;
      A[3][4]=100000;
      A[4][4]=120000;

      A[0][5]=136400;
      A[1][5]=921800;
      A[2][5]=63900;
      A[3][5]=274500;
      A[4][5]=282500;

      A[0][1]=1239804;
      A[1][1]=8380801;
      A[2][1]=581130;
      A[3][1]=2496346;
      A[4][1]=2569007;
    }
  }

  if(cantidad>(A[0][4]+A[0][5])){
    cout<<"\nEn Barranquilla: ";
    cout<<"Se vacunarán "<<(A[0][4]+A[0][5])<<" personas mayores de 70 años y pertenecientes al personal de salud y "<< (cantidad-(A[0][4]+A[0][5]))<<" del resto"<<endl;
  }else if(cantidad>A[0][4]&&(cantidad<(A[0][4]+A[0][5]))){
     cout<<"\nEn Barranquilla: ";
      cout<<"Se vacunarán "<<A[0][4]<<" personas pertenecientes al personal de salud y "<<(cantidad-A[0][4])<<" personas mayores de 70 años"<<endl;
  }else if(cantidad<A[0][4]){
      cout<<"\nEn Barranquilla: ";
      cout<<"Se vacunarán "<<cantidad<<" personas pertenecientes al personal de salud"<<endl;
  }

  if(cantidad>(A[1][4]+A[1][5])){
    cout<<"\nEn Bogotá: ";
    cout<<"Se vacunarán "<<(A[1][4]+A[1][5])<<" personas mayores de 70 años y pertenecientes al personal de salud y "<< (cantidad-(A[1][4]+A[1][5]))<<" del resto"<<" del resto"<<endl;
  }else if(cantidad>A[1][4]&&(cantidad<(A[1][4]+A[1][5]))){
    cout<<"\nEn Bogotá: ";
    cout<<"Se vacunarán "<<A[1][4]<<" personas pertenecientes al personal de salud y "<<(cantidad-A[1][4])<<" personas mayores de 70 años"<<endl;
  }else if(cantidad<A[1][4]){
    cout<<"\nEn Bogotá: ";
    cout<<"Se vacunarán "<<cantidad<<" personas pertenecientes al personal de salud"<<endl;
  }

  if(cantidad>(A[2][4]+A[2][5])){
    cout<<"\nEn Bucaramanga: ";
    cout<<"Se vacunarán "<<(A[2][4]+A[2][5])<<" personas mayores de 70 años y pertenecientes al personal de salud y "<< (cantidad-(A[2][4]+A[2][5]))<<" del resto"<<endl;
  }else if(cantidad>A[2][4]&&(cantidad<(A[2][4]+A[2][5]))){
    cout<<"\nEn Bucaramanga: ";
    cout<<"Se vacunarán "<<A[2][4]<<" personas pertenecientes al personal de salud y "<<(cantidad-A[2][4])<<" personas mayores de 70 años"<<endl;
  }else if(cantidad<A[2][4]){
    cout<<"\nEn Bucaramanga: ";
    cout<<"Se vacunarán "<<cantidad<<" personas pertenecientes al personal de salud"<<endl;
  }

  if(cantidad>(A[3][4]+A[3][5])){
    cout<<"\nEn Cali: ";
    cout<<"Se vacunarán "<<(A[3][4]+A[3][5])<<" personas mayores de 70 años y pertenecientes al personal de salud y "<< (cantidad-(A[3][4]+A[3][5]))<<" del resto"<<endl;
  }else if(cantidad>A[3][4]&&(cantidad<(A[3][4]+A[3][5]))){
    cout<<"\nEn Cali: ";
    cout<<"Se vacunarán "<<A[3][4]<<" personas pertenecientes al personal de salud y "<<(cantidad-A[3][4])<<" personas mayores de 70 años"<<endl;
  }else if(cantidad<A[3][4]){
    cout<<"\nEn Cali: ";
    cout<<"Se vacunarán "<<cantidad<<" personas pertenecientes al personal de salud"<<endl;
  }

  if(cantidad>(A[4][4]+A[4][5])){
    cout<<"\nEn Medellín: ";
    cout<<"Se vacunarán "<<(A[4][4]+A[4][5])<<" personas mayores de 70 años y pertenecientes al personal de salud y "<<(cantidad-(A[4][4]+A[4][5]))<<" del resto"<<endl;

    }else if(cantidad>A[4][4]&&(cantidad<(A[4][4]+A[4][5]))){
      cout<<"\nEn Medellín: ";
      cout<<"Se vacunarán "<<A[4][4]<<" personas pertenecientes al personal de salud y "<<(cantidad-A[4][4])<<" personas mayores de 70 años"<<endl;
    }else if(cantidad<A[4][4]){
      cout<<"\nEn Medellín: ";
      cout<<"Se vacunarán "<<cantidad<<" personas pertenecientes al personal de salud\n"<<endl;
    }

    cout<<"\nLos siguientes son los tiempos que se gastarán en aplicar todas las vacunas en cada ciudad: \n";

    for(int k=0;k<5;k++){
      personal[k]=0.3*(A[k][4]);

      vac_hora_per[k]=personal[k]*15;

      tiempo[k]=cantidad/(vac_hora_per[k]);

    }
    /*personal[0]=(0.3)*(A[0][4]);
    personal[1]=(0.3)*(A[1][4]);
    personal[2]=(0.3)*(A[2][4]);
    personal[3]=(0.3)*(A[3][4]);
    personal[4]=(0.3)*(A[4][4]);

    vac_hora_per[0]=(personal[0])*15;
    vac_hora_per[1]=(personal[1])*15;
    vac_hora_per[2]=(personal[2])*15;
    vac_hora_per[3]=(personal[3])*15;
    vac_hora_per[4]=(personal[4])*15;

    tiempo[0]=cantidad/(vac_hora_per[0]);
    tiempo[1]=cantidad/(vac_hora_per[1]);
    tiempo[2]=cantidad/(vac_hora_per[2]);
    tiempo[3]=cantidad/(vac_hora_per[3]);
    tiempo[4]=cantidad/(vac_hora_per[4]);*/

    cout<<"\nEl tiempo que tardará Barranquilla en aplicar todas las vacunas será: "<<tiempo[0]<<" horas"<<endl;
    cout<<"El tiempo que tardará Bogotá en aplicar todas las vacunas será: "<<tiempo[1]<<" horas"<<endl;
    cout<<"El tiempo que tardará Bucaramanga en aplicar todas las vacunas será: "<<tiempo[2]<<" horas"<<endl;
    cout<<"El tiempo que tardará Cali en aplicar todas las vacunas será: "<<tiempo[3]<<" horas"<<endl;
    cout<<"El tiempo que tardará Medellín en aplicar todas las vacunas será: "<<tiempo[4]<<" horas"<<endl;


};




int main() {
  
  int eleccion, opcion,n_habitantes,n_contagiados, n_hospitales, n_persalud, n_adultomayor, selector=0, counter=0,x;
  string ciudad;
  float distancia, tabla;
  float A[5][7];

  leerArchivo();

  for(int i=0;i<5;i++){

    for(int j=0;j<7;j++){

      archivo >> A[i][j];
     
      A[0][1]=1239804;
      A[1][1]=8380801;
      A[2][1]=581130;
      A[3][1]=2496346;
      A[4][1]=2569007;

      A[0][2]=110000;
      A[1][2]=611000;
      A[2][2]=83000;
      A[3][2]=173000;
      A[4][2]=325000;

      A[0][3]=724;
      A[1][3]=2274;
      A[2][3]=261;
      A[3][3]=850;
      A[4][3]=900;

      A[0][4]=90000;
      A[1][4]=200000;
      A[2][4]=50000;
      A[3][4]=100000;
      A[4][4]=120000;

      A[0][5]=136400;
      A[1][5]=921800;
      A[2][5]=63900;
      A[3][5]=274500;
      A[4][5]=282500;

      A[0][6]=1000.9;
      A[1][6]=0;
      A[2][6]=424.2;
      A[3][6]=452.4;
      A[4][6]=416.4;

    }
  };

  cout<<"Buen día, este programa le ayudará a ver la situación actual del covid 19 en 5 ciudades de Colombia, analizar algunos procesos y ejecutar una simulación de la distribución de un determinado número de vacunas en dichas ciudades. Espero sea de su utilidad el programa, muchas gracias por usarlo"<<endl;


  //*************************MENÚ*****************************************
  
  while(eleccion!=0){
    cout<<"Seleccione la opción que desea realizar: ";
    cout<<"\n1.Actualizar número de contagiados";
    cout<<"\n2.Revisar estadisticas por ciudad";
    cout<<"\n3.Ingresar número de vacunas y ejecutar el programa\n";
    eleccion=entrada();

    if(eleccion==0){
      cout<<"El programa ha finalizado. Gracias por usarlo"<<endl;
    }
    if(eleccion < 0 || eleccion >= 4){
        cout << "Opcion no valida!\nIngrese nuevamente su elección" << endl;
        eleccion = entrada();
    }
  
    switch(eleccion){
      case 1:
        cout<<"Ingrese el nuevo número de contagiados";
        break;

      case 2:
        cout<<"Elija la ciudad que quiere revisar: ";
        cout<<"\n1. Barranquilla ";
        cout<<"\n2. Bogotá ";
        cout<<"\n3. Bucaramanga ";
        cout<<"\n4. Cali ";
        cout<<"\n5. Medellín ";
        opcion=entrada();
        
        switch(opcion){
          case 1:
          {
            cout<<"CIUDAD"<<left<<setw(20)<<"# HABITANTES"<<left<<setw(20)<<"# CONTAGIADOS"<<left<<setw(20)<<"# HOSPITALES"<<left<<setw(20)<<"# PERSONAL SALUD"<<left<<setw(20)<<"# A. MAYORES(+70)"<<left<<setw(20)<<"DISTANCIA A BÓGOTA (KM\n)"<<endl;
            cout<<"Barranquilla"<<left<<setw(20)<<A[0][1]<<left<<setw(20)<<A[0][2]<<left<<setw(20)<<A[0][3]<<left<<setw(20)<<A[0][4]<<left<<setw(20)<<A[0][5]<<left<<setw(25)<<A[0][6];
            break;
          }
          case 2:
          {
            cout<<"CIUDAD"<<left<<setw(20)<<"# HABITANTES"<<left<<setw(20)<<"# CONTAGIADOS"<<left<<setw(20)<<"# HOSPITALES"<<left<<setw(20)<<"# PERSONAL SALUD"<<left<<setw(20)<<"# A. MAYORES(+70)"<<left<<setw(20)<<"DISTANCIA A BÓGOTA (KM)\n"<<endl;
            cout<<"Bogotá"<<left<<setw(20)<<A[1][1]<<left<<setw(20)<<A[1][2]<<left<<setw(20)<<A[1][3]<<left<<setw(20)<<A[1][4]<<left<<setw(20)<<A[1][5]<<left<<setw(25)<<A[1][6];
            break;
          }
          case 3:
          {
            cout<<"CIUDAD"<<left<<setw(20)<<"# HABITANTES"<<left<<setw(20)<<"# CONTAGIADOS"<<left<<setw(20)<<"# HOSPITALES"<<left<<setw(20)<<"# PERSONAL SALUD"<<left<<setw(20)<<"# A. MAYORES(+70)"<<left<<setw(20)<<"DISTANCIA A BÓGOTA (KM)\n"<<endl;
            cout<<"Bucaramanga"<<left<<setw(20)<<A[2][1]<<left<<setw(20)<<A[2][2]<<left<<setw(20)<<A[2][3]<<left<<setw(20)<<A[2][4]<<left<<setw(20)<<A[2][5]<<left<<setw(25)<<A[2][6];
            break;
          }
          case 4:
          {
            cout<<"CIUDAD"<<left<<setw(20)<<"# HABITANTES"<<left<<setw(20)<<"# CONTAGIADOS"<<left<<setw(20)<<"# HOSPITALES"<<left<<setw(20)<<"# PERSONAL SALUD"<<left<<setw(20)<<"# A. MAYORES(+70)"<<left<<setw(20)<<"DISTANCIA A BÓGOTA (KM)\n"<<endl;
            cout<<"Cali"<<left<<setw(20)<<A[3][1]<<left<<setw(20)<<A[3][2]<<left<<setw(20)<<A[3][3]<<left<<setw(20)<<A[3][4]<<left<<setw(20)<<A[3][5]<<left<<setw(25)<<A[3][6];
            break;
          }
          case 5:
          {
            cout<<"CIUDAD"<<left<<setw(20)<<"# HABITANTES"<<left<<setw(20)<<"# CONTAGIADOS"<<left<<setw(20)<<"# HOSPITALES"<<left<<setw(20)<<"# PERSONAL SALUD"<<left<<setw(20)<<"# A. MAYORES(+70)"<<left<<setw(20)<<"DISTANCIA A BÓGOTA (KM)\n"<<endl;
            cout<<"Medellín"<<left<<setw(20)<<A[4][1]<<left<<setw(20)<<A[4][2]<<left<<setw(20)<<A[4][3]<<left<<setw(20)<<A[4][4]<<left<<setw(20)<<A[4][5]<<left<<setw(25)<<A[4][6];
            break;
          }
          default:
            cout<<"Ingrese un valor válido"<<endl;
        }
        break;
        
      case 3:
        cout<<"Ingrese el número de dosis de la vacuna que se van a distribuir \n";
        x=entrada();
        calc_dosis_camiones(x);
        calc_paradas();
        orden_tiempo(x);
        break;
    }
  }
  cout<<"El programa ha finalizado. Gracias por usarlo"<<endl;
}


