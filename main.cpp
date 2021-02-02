
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <cstdlib>


using namespace std;

fstream archivo; 

void leerArchivo()  //Lectura del archivo
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

void calculos(int cantidad){    //Función global de los cálculos

  int dosis[5];
  int camiones[5];
  int paradas[5];
  int tiempo_dias[5];
  int persalud, mayores, resto;
  float personal[5],vac_hora_per[5],tiempo[5];

  ifstream archivo("estadisticas.txt",ios::in);
  archivo.is_open();
  int A[5][7];

  for(int i=0;i<5;i++){

    for(int j=0;j<7;j++){

      archivo >> A[i][j];   //Matriz del archivo con las estadisticas

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

  cout<<"--------------------------------------------------DOSIS--------------------------------------------------"<<endl;
   //Esos valores son la razón entre habitantes de cada ciudad respecto a la suma de las 5 poblaciones
  dosis[0]=cantidad*0.083;
  dosis[1]=cantidad*0.548;
  dosis[2]=cantidad*0.038;
  dosis[3]=cantidad*0.163;
  dosis[4]=cantidad*0.168;

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

  cout<<"\n\n--------------------------------------------------CAMIONES--------------------------------------------------"<<endl;

  cout<<"\nLa cantidad de camiones para Barranquilla: "<<camiones[0]<<endl;
  cout<<"La cantidad de camiones para Bogotá "<<camiones[1]<<endl;
  cout<<"La cantidad de camiones para Bucaramanga: "<<camiones[2]<<endl;
  cout<<"La cantidad de camiones para Cali: "<<camiones[3]<<endl;
  cout<<"La cantidad de camiones para Medellín: "<<camiones[4]<<endl;

  paradas[0]=(1000.9/120)+1;
  paradas[1]=(0/120);
  paradas[2]=(424.2/120)+1;
  paradas[3]=(452.4/120)+1;
  paradas[4]=(416.4/120)+1;

  cout<<"\n\n--------------------------------------------------PARADAS--------------------------------------------------"<<endl;

  cout<<"\nLas paradas necesarias para Barranquilla son: "<<paradas[0]<<endl;
  cout<<"Las paradas necesarias para Bogotá son: "<<paradas[1]<<endl;
  cout<<"Las paradas necesarias para Bucaramanga son: "<<paradas[2]<<endl;
  cout<<"Las paradas necesarias para Cali son: "<<paradas[3]<<endl;
  cout<<"Las paradas necesarias para Medellín son: "<<paradas[4]<<endl;

   cout<<"\n\n-----------------------------------------------ORDEN DE VACUNACIÓN-----------------------------------------------"<<endl;

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
    cout<<"En Bogotá: ";
    cout<<"Se vacunarán "<<(A[1][4]+A[1][5])<<" personas mayores de 70 años y pertenecientes al personal de salud y "<< (cantidad-(A[1][4]+A[1][5]))<<" del resto"<<" del resto"<<endl;
  }else if(cantidad>A[1][4]&&(cantidad<(A[1][4]+A[1][5]))){
    cout<<"En Bogotá: ";
    cout<<"Se vacunarán "<<A[1][4]<<" personas pertenecientes al personal de salud y "<<(cantidad-A[1][4])<<" personas mayores de 70 años"<<endl;
  }else if(cantidad<A[1][4]){
    cout<<"En Bogotá: ";
    cout<<"Se vacunarán "<<cantidad<<" personas pertenecientes al personal de salud"<<endl;
  }

  if(cantidad>(A[2][4]+A[2][5])){
    cout<<"En Bucaramanga: ";
    cout<<"Se vacunarán "<<(A[2][4]+A[2][5])<<" personas mayores de 70 años y pertenecientes al personal de salud y "<< (cantidad-(A[2][4]+A[2][5]))<<" del resto"<<endl;
  }else if(cantidad>A[2][4]&&(cantidad<(A[2][4]+A[2][5]))){
    cout<<"En Bucaramanga: ";
    cout<<"Se vacunarán "<<A[2][4]<<" personas pertenecientes al personal de salud y "<<(cantidad-A[2][4])<<" personas mayores de 70 años"<<endl;
  }else if(cantidad<A[2][4]){
    cout<<"En Bucaramanga: ";
    cout<<"Se vacunarán "<<cantidad<<" personas pertenecientes al personal de salud"<<endl;
  }

  if(cantidad>(A[3][4]+A[3][5])){
    cout<<"En Cali: ";
    cout<<"Se vacunarán "<<(A[3][4]+A[3][5])<<" personas mayores de 70 años y pertenecientes al personal de salud y "<< (cantidad-(A[3][4]+A[3][5]))<<" del resto"<<endl;
  }else if(cantidad>A[3][4]&&(cantidad<(A[3][4]+A[3][5]))){
    cout<<"En Cali: ";
    cout<<"Se vacunarán "<<A[3][4]<<" personas pertenecientes al personal de salud y "<<(cantidad-A[3][4])<<" personas mayores de 70 años"<<endl;
  }else if(cantidad<A[3][4]){
    cout<<"En Cali: ";
    cout<<"Se vacunarán "<<cantidad<<" personas pertenecientes al personal de salud"<<endl;
  }

  if(cantidad>(A[4][4]+A[4][5])){
    cout<<"En Medellín: ";
    cout<<"Se vacunarán "<<(A[4][4]+A[4][5])<<" personas mayores de 70 años y pertenecientes al personal de salud y "<<(cantidad-(A[4][4]+A[4][5]))<<" del resto\n"<<endl;

    }else if(cantidad>A[4][4]&&(cantidad<(A[4][4]+A[4][5]))){
      cout<<"En Medellín: ";
      cout<<"Se vacunarán "<<A[4][4]<<" personas pertenecientes al personal de salud y "<<(cantidad-A[4][4])<<" personas mayores de 70 años\n"<<endl;
    }else if(cantidad<A[4][4]){
      cout<<"En Medellín: ";
      cout<<"Se vacunarán "<<cantidad<<" personas pertenecientes al personal de salud\n"<<endl;
    }

    cout<<"\nLos siguientes son los tiempos que se gastarán en aplicar todas las vacunas en cada ciudad: \n";

    for(int k=0;k<5;k++){    //Cálculo del tiempo en aplicar las vacunas

      personal[k]=0.3*(A[k][4]);
      vac_hora_per[k]=personal[k]*15;
      tiempo[k]=cantidad/(vac_hora_per[k]);
      tiempo_dias[k]=(tiempo[k]/24)+1;

    }
    
    cout<<"\n\n------------------------------------------TIEMPO DE VACUNACIÓN (HORAS)------------------------------------------"<<endl;

    cout<<"\nEl tiempo que tardará Barranquilla en aplicar todas las vacunas será: "<<tiempo[0]<<" horas y "<<tiempo_dias[0]<<" días laborales"<<endl;
    cout<<"El tiempo que tardará Bogotá en aplicar todas las vacunas será: "<<tiempo[1]<<" horas y "<<tiempo_dias[1]<<" días laborales"<<endl;
    cout<<"El tiempo que tardará Bucaramanga en aplicar todas las vacunas será: "<<tiempo[2]<<" horas y "<<tiempo_dias[2]<<" días laborales"<<endl;
    cout<<"El tiempo que tardará Cali en aplicar todas las vacunas será: "<<tiempo[3]<<" horas y "<<tiempo_dias[3]<<" días laborales"<<endl;
    cout<<"El tiempo que tardará Medellín en aplicar todas las vacunas será: "<<tiempo[4]<<" horas y "<<tiempo_dias[4]<<" días laborales"<<endl;

    ofstream datos;
    datos.open("Datos_calculados.txt");
    datos<<"**********************************************************************************************************************************************\n";
    datos<<"NÚMERO DE VACUNAS: "<<setw(10)<<cantidad<<endl;
    cout<<endl;
    cout<<endl; 
    datos<<left<<setw(25)<<"CIUDAD"<<left<<setw(25)<<"DOSIS"<<left<<setw(25)<<"CAMIONES"<<left<<setw(25)<<"PARADAS"<<left<<setw(25)<<"TIEMPO(Horas)"<<left<<setw(25)<<"TIEMPO(Días)"<<endl;
    datos<<left<<setw(25)<<"Barranquilla"<<left<<setw(25)<<dosis[0]<<left<<setw(25)<<camiones[0]<<left<<setw(25)<<paradas[0]<<left<<setw(25)<<tiempo[0]<<left<<setw(25)<<tiempo_dias[0]<<endl;
    datos<<left<<setw(25)<<"Bogotá"<<left<<setw(25)<<dosis[1]<<left<<setw(25)<<camiones[1]<<left<<setw(25)<<paradas[1]<<left<<setw(25)<<tiempo[1]<<left<<setw(25)<<tiempo_dias[1]<<endl;
    datos<<left<<setw(25)<<"Bucaramanga"<<left<<setw(25)<<dosis[2]<<left<<setw(25)<<camiones[2]<<left<<setw(25)<<paradas[2]<<left<<setw(25)<<tiempo[2]<<left<<setw(25)<<tiempo_dias[2]<<endl;
    datos<<left<<setw(25)<<"Cali"<<left<<setw(25)<<dosis[3]<<left<<setw(25)<<camiones[3]<<left<<setw(25)<<paradas[3]<<left<<setw(25)<<tiempo[3]<<left<<setw(25)<<tiempo_dias[3]<<endl;
    datos<<left<<setw(25)<<"Medellín"<<left<<setw(25)<<dosis[4]<<left<<setw(25)<<camiones[4]<<left<<setw(25)<<paradas[4]<<left<<setw(25)<<tiempo[4]<<left<<setw(25)<<tiempo_dias[4]<<endl;
        
    datos<<"**********************************************************************************************************************************************";
    datos.close();
};


int main() {
  
  char salir;
  int eleccion, opcion1, opcion2, n_habitantes,n_contagiados, n_hospitales, n_persalud, n_adultomayor, selector=0, counter=0,x;
  string ciudad;
  float distancia, tabla;
  float A[5][7];

  leerArchivo();

  for(int i=0;i<5;i++){

    for(int j=0;j<7;j++){

      archivo >> A[i][j];   //Matríz de las estadisticas
     
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

  cout<<"Buen día, este programa le ayudará a ver la situación actual del covid 19 en 5 ciudades de Colombia, analizar algunos procesos y ejecutar una simulación de la distribución de un determinado número de vacunas en dichas ciudades. Espero sea de su utilidad el programa, muchas gracias por usarlo\n"<<endl;


  //*************************MENÚ*****************************************
  
     
  while(salir!='0'){

    cout<<"\nSi quiere ejecutar el programa, presione cualquier tecla y ejecutelo.\n(Si quiere salir del programa presione la tecla 0)   "<<endl;           //Opciones para ingresar o vender producto
    cin>>salir;
    cout<<endl;

    if(salir=='0'){
      break;
    }

    cout<<"Seleccione la opción que desea realizar: ";
    cout<<"\n1.Actualizar número de contagiados";
    cout<<"\n2.Revisar estadisticas por ciudad";
    cout<<"\n3.Ingresar número de vacunas y ejecutar el programa\n";
    eleccion=entrada();

    if(eleccion < 0 || eleccion >4){
      cout << "Opcion no valida!\nIngrese nuevamente su elección" << endl;
      eleccion = entrada();
    }

    switch(eleccion){

      case 1:  //Actualizar los contagiados
        cout<<"\nA qué ciudad quiere actualizarle el número de contagiados: \n";
        cout<<left<<setw(15)<<"1. Barranquilla: "<<A[0][2]<<" contagiados\n";
        cout<<left<<setw(15)<<"2. Bogotá: "<<A[1][2]<<" contagiados\n";
        cout<<left<<setw(15)<<"3. Bucaramanga: "<<A[2][2]<<" contagiados\n";
        cout<<left<<setw(15)<<"4. Cali "<<A[3][2]<<" contagiados\n";
        cout<<left<<setw(15)<<"5. Medellín: "<<A[3][2]<<" contagiados\n";
        opcion1=entrada();

        switch(opcion1){
          case 1:
          cout<<"Ingrese el nuevo número de contagiados: \n";
          A[0][2]=entrada();
          if(A[0][2]>A[0][1]){
            cout<<"Valor inválido, el número de contagiados no puede ser mayor a la población.\nPor favor ingrese un valor válido"<<endl;
            opcion1=entrada();
          }else{
            cout<<left<<setw(15)<<"1. Barranquilla: "<<A[0][2]<<" contagiados\n";
          }
          break;

          case 2:
          cout<<"Ingrese el nuevo número de contagiados: \n";
          A[1][2]=entrada();
          if(A[1][2]>A[1][1]){
            cout<<"Valor inválido, el número de contagiados no puede ser mayor a la población.\nPor favor ingrese un valor válido"<<endl;
            opcion1=entrada();
          }else{         
            cout<<left<<setw(15)<<"2. Bogotá: "<<A[1][2]<<" contagiados\n";
          }
          break;

          case 3:
          cout<<"Ingrese el nuevo número de contagiados: \n";
          A[2][2]=entrada();
          if(A[2][2]>A[2][1]){
            cout<<"Valor inválido, el número de contagiados no puede ser mayor a la población.\nPor favor ingrese un valor válido"<<endl;
            opcion1=entrada();
          }else{         
            cout<<left<<setw(15)<<"3. Bucaramanga: "<<A[2][2]<<" contagiados\n";
          }
          break;

          case 4:
          cout<<"Ingrese el nuevo número de contagiados: \n";
          A[3][2]=entrada();
          if(A[3][2]>A[3][1]){
            cout<<"Valor inválido, el número de contagiados no puede ser mayor a la población.\nPor favor ingrese un valor válido"<<endl;
            opcion1=entrada();
          }else{         
            cout<<left<<setw(15)<<"4. Cali: "<<A[3][2]<<" contagiados\n";
          }
          break;

          case 5:
          cout<<"Ingrese el nuevo número de contagiados: \n";
          A[4][2]=entrada();
          if(A[4][2]>A[4][1]){
            cout<<"Valor inválido, el número de contagiados no puede ser mayor a la población.\nPor favor ingrese un valor válido"<<endl;
            opcion1=entrada();
          }else{         
            cout<<left<<setw(15)<<"5. Medellín: "<<A[4][2]<<" contagiados\n";
          }
          break;
        }
        cout<<endl;
        break;

      case 2:  //Ver la tabla para cada ciudad
        cout<<"Elija la ciudad que quiere revisar: ";
        cout<<"\n1. Barranquilla ";
        cout<<"\n2. Bogotá ";
        cout<<"\n3. Bucaramanga ";
        cout<<"\n4. Cali ";
        cout<<"\n5. Medellín \n\n";
        opcion2=entrada();
        
        cout<<"**************************************************************************************************************************************************\n";
        switch(opcion2){
          case 1:
          
            cout<<left<<setw(20)<<"CIUDAD"<<left<<setw(20)<<"# HABITANTES"<<left<<setw(20)<<"# CONTAGIADOS"<<left<<setw(20)<<"# HOSPITALES"<<left<<setw(20)<<"# PERSONAL SALUD"<<left<<setw(20)<<"# A. MAYORES(+70)"<<left<<setw(20)<<"DISTANCIA A BÓGOTA (KM\n)"<<endl;
            cout<<left<<setw(20)<<"Barranquilla"<<left<<setw(20)<<A[0][1]<<left<<setw(20)<<A[0][2]<<left<<setw(20)<<A[0][3]<<left<<setw(25)<<A[0][4]<<left<<setw(20)<<A[0][5]<<left<<setw(25)<<A[0][6];
            break;
          
          case 2:
          
           cout<<left<<setw(20)<<"CIUDAD"<<left<<setw(20)<<"# HABITANTES"<<left<<setw(20)<<"# CONTAGIADOS"<<left<<setw(20)<<"# HOSPITALES"<<left<<setw(20)<<"# PERSONAL SALUD"<<left<<setw(20)<<"# A. MAYORES(+70)"<<left<<setw(20)<<"DISTANCIA A BÓGOTA (KM)\n"<<endl;
            cout<<left<<setw(20)<<"Bogotá"<<left<<setw(20)<<A[1][1]<<left<<setw(20)<<A[1][2]<<left<<setw(20)<<A[1][3]<<left<<setw(25)<<A[1][4]<<left<<setw(20)<<A[1][5]<<left<<setw(25)<<A[1][6];
            break;
        
          case 3:
          
           cout<<left<<setw(20)<<"CIUDAD"<<left<<setw(20)<<"# HABITANTES"<<left<<setw(20)<<"# CONTAGIADOS"<<left<<setw(20)<<"# HOSPITALES"<<left<<setw(20)<<"# PERSONAL SALUD"<<left<<setw(20)<<"# A. MAYORES(+70)"<<left<<setw(20)<<"DISTANCIA A BÓGOTA (KM)\n"<<endl;
            cout<<left<<setw(20)<<"Bucaramanga"<<left<<setw(20)<<A[2][1]<<left<<setw(20)<<A[2][2]<<left<<setw(20)<<A[2][3]<<left<<setw(25)<<A[2][4]<<left<<setw(20)<<A[2][5]<<left<<setw(25)<<A[2][6];
            break;
          
          case 4:
          
            cout<<left<<setw(20)<<"CIUDAD"<<left<<setw(20)<<"# HABITANTES"<<left<<setw(20)<<"# CONTAGIADOS"<<left<<setw(20)<<"# HOSPITALES"<<left<<setw(20)<<"# PERSONAL SALUD"<<left<<setw(20)<<"# A. MAYORES(+70)"<<left<<setw(20)<<"DISTANCIA A BÓGOTA (KM)\n"<<endl;
            cout<<left<<setw(20)<<"Cali"<<left<<setw(20)<<A[3][1]<<left<<setw(20)<<A[3][2]<<left<<setw(20)<<A[3][3]<<left<<setw(25)<<A[3][4]<<left<<setw(20)<<A[3][5]<<left<<setw(25)<<A[3][6];
            break;
          
          case 5:
          
            cout<<left<<setw(20)<<"CIUDAD"<<left<<setw(20)<<"# HABITANTES"<<left<<setw(20)<<"# CONTAGIADOS"<<left<<setw(20)<<"# HOSPITALES"<<left<<setw(20)<<"# PERSONAL SALUD"<<left<<setw(20)<<"# A. MAYORES(+70)"<<left<<setw(20)<<"DISTANCIA A BÓGOTA (KM)\n"<<endl;
            cout<<left<<setw(20)<<"Medellín"<<left<<setw(20)<<A[4][1]<<left<<setw(20)<<A[4][2]<<left<<setw(20)<<A[4][3]<<left<<setw(25)<<A[4][4]<<left<<setw(20)<<A[4][5]<<left<<setw(25)<<A[4][6];
            break;
        }
          cout<<endl;
          break;

        
      case 3:   //Realizar los cálculos y crear el txt

        cout<<"**************************************************************************************************************************************************\n";
        cout<<"Ingrese el número de dosis de la vacuna que se van a distribuir \n";
        x=entrada();
        calculos(x);
        cout<<endl;
        break;
    }
    cout<<"**************************************************************************************************************************************************\n";
    
  }
  cout<<"El programa ha finalizado. Gracias por usarlo"<<endl;
}


