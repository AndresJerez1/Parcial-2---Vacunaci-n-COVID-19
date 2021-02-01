
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


void city1(){
  ifstream archivo("estadisticas.txt",ios::in);
    string a;
    archivo.is_open();
    string A[5][7];

    for(int i=0;i<5;i++){

      for(int j=0;j<7;j++){

        archivo >> A[i][j];
        cout<<left<<setw(20)<<A[0][j];
  
      }
    }

    
};

void city2(){
  ifstream archivo("estadisticas.txt",ios::in);
    string a;
    archivo.is_open();
    string A[5][7];

    for(int i=0;i<5;i++){

      for(int j=0;j<7;j++){

        archivo >> A[i][j];
        cout<<left<<setw(20)<<A[1][j];
  
      }
    }

    
};

void city3(){
  ifstream archivo("estadisticas.txt",ios::in);
    string a;
    archivo.is_open();
    string A[5][7];

    for(int i=0;i<5;i++){

      for(int j=0;j<7;j++){

        archivo >> A[i][j];
        cout<<left<<setw(20)<<A[2][j];
  
      }
    }

    
};

void city4(){
  ifstream archivo("estadisticas.txt",ios::in);
    string a;
    archivo.is_open();
    string A[5][7];

    for(int i=0;i<5;i++){

      for(int j=0;j<7;j++){

        archivo >> A[i][j];
        cout<<left<<setw(20)<<A[3][j];
  
      }
    }

    
};

void city5(){
  ifstream archivo("estadisticas.txt",ios::in);
    string a;
    archivo.is_open();
    string A[5][7];

    for(int i=0;i<5;i++){

      for(int j=0;j<7;j++){

        archivo >> A[i][j];
        cout<<left<<setw(20)<<A[4][j];
  
      }
    }

    
};


/*while(!archivo.eof()){
        archivo >>ciudad>>n_habitantes>>n_contagiados>>n_hospitales>>n_persalud>>n_adultomayor>>distancia;
        cout<<"Ciudad"<<setw(20)<<"No. Habitantes"<<setw(20)<<"No. Contagiados"<<setw(20)<<"No. Hospitales"<<setw(20)<<"No. Personal salud"<<setw(20)<<"No. Adultos +70"<<setw(20)<<"Distancia (Km)"<<endl;
        cout<<endl;
        cout<<ciudad<<setw(10)<<n_habitantes<<setw(20)<<n_contagiados<<setw(20)<<n_hospitales<<setw(20)<<n_persalud<<setw(20)<<distancia;
        cout<<endl;
      }*/
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
      cout<<"Se vacunarán "<<cantidad<<" personas pertenecientes al personal de salud"<<endl;
    }

    int personal[5],vac_hora_per[5],tiempo[5];

    personal[0]=(0.3)*A[0][4];
    personal[1]=(0.3)*A[1][4];
    personal[2]=(0.3)*A[2][4];
    personal[3]=(0.3)*A[3][4];
    personal[4]=(0.3)*A[4][4];

    vac_hora_per[0]=personal[0]*15;
    vac_hora_per[1]=personal[1]*15;
    vac_hora_per[2]=personal[2]*15;
    vac_hora_per[3]=personal[3]*15;
    vac_hora_per[4]=personal[4]*15;

    tiempo[0]=cantidad/vac_hora_per[0];
    tiempo[1]=cantidad/vac_hora_per[1];
    tiempo[2]=cantidad/vac_hora_per[2];
    tiempo[3]=cantidad/vac_hora_per[3];
    tiempo[4]=cantidad/vac_hora_per[4];

    cout<<"El tiempo que tardará Barranquilla en aplicar todas las vacunas será: "<<tiempo[0]<<" horas"<<endl;
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

  
  /*cout <<"Seleccione la opción que quiere ver "<<endl
      << "1. Ciudades con más de 600 hospitales:"<< endl
      << "2. Ciudades con más de 400 Km de didstancia a Bogotá"<<endl;
  cin >> selector;*/


  //while(!archivo.eof()){
    //archivo >>ciudad>>n_habitantes>>n_contagiados>>n_hospitales>>n_persalud>>n_adultomayor>>distancia; //orden de lectura 
  
    /*switch(selector){
      case 1:
        if(n_hospitales>600)
          cout <<left << setw(15)<<ciudad<<left << setw(10)<<n_hospitales <<endl;
        break;

      case 2:
        if(distancia>400)
          cout <<left << setw(15)<<ciudad<<left << setw(10)<<distancia <<endl;
        break;
    }

  };*/

  //MENÚ
  cout<<"Seleccione la opción que desea realizar: ";
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
          city1();
          break;
        case 2:
          city2();
          break;
        case 3:
          city3();
          break;
        case 4:
          city4();
          break;
        case 5:
          city5();
          break;
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


