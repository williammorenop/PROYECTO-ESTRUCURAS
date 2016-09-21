#include "lugar.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <stdlib.h>

using namespace std;

string cargarArchivo(list<lugar *> &lugars,string nombrearch);
void imprimirLista(list<lugar *> lugars);
string imprimirlinea(int numchar, int longitud);
string imprimirMenu();
int main() {
  int opcion;
  // lugar* a = new lugar("sda", 2, 2.2, 3.2);
  //////////////////////////////////////////////
  /*char u;
  for (int a = 0; a < 300; a++) {
    u = a;
    cout << a << " -> " << u << endl;
  }*/
  /////////////////////////////////////////////

      cout<<imprimirMenu()<<"\nOpcion:  ";
      cin>>opcion;

      list<lugar *> lugares;

      //system("PAUSE");
      //imprimirLista(lugares);
      while (opcion!=7)
      {
        switch (opcion) {
          case 1:
          {
            string nombrearchivo;
            cout<<"Ingrese el nombre del archivo: ";
            cin>>nombrearchivo;
            cout<<cargarArchivo(lugares,nombrearchivo);
            break;
          }
          case 2:
          {
            cout<<"PROXIMAMENTE..."<<endl;
            break;
          }
          case 3:
          {
            cout<<"PROXIMAMENTE..."<<endl;
            break;
          }
          case 4:
          {
            cout<<"PROXIMAMENTE..."<<endl;
            break;
          }
          case 5:
          {
            cout<<"PROXIMAMENTE..."<<endl;
            break;
          }
          case 6:
          {
            cout<<"PROXIMAMENTE..."<<endl;
            break;
          }
          default:
          {
            cout<<(char)173<<"Opcion incorrecta!."<<endl;
          }
        }
        system("PAUSE");
        system("cls");
        cout<<imprimirMenu()<<"\nOpcion:  ";
        cin>>opcion;
      }



  return (0);
}
string imprimirMenu()
{
  string menu="";
  char esi = 201, esd = 187, eii = 200, eid = 188, lv = 186, lh = 205, id = 185,ii = 204;
  menu=menu
       +" "+ esi + imprimirlinea(205, 38) + esd + "\n"
       +" "+ lv + "\t\t\t\t\t" + lv + "\n"
       +" "+ lv + "\t           MENU       \t\t" + lv + "\n"
       +" "+ lv + "\t\t\t\t\t" + lv + "\n"
       +" "+ ii + imprimirlinea(205, 38) + id + "\n"
       +" "+ lv + "  Opcion 1: Cargar. \t\t\t" + lv + "\n"
       +" "+ lv + "  Opcion 2: Cantidad de Sitios. \t" + lv + "\n"
       +" "+ lv + "  Opcion 3: Obtener Sitio. \t\t" + lv + "\n"
       +" "+ lv + "  Opcion 4: Crear Sitio. \t\t" + lv + "\n"
       +" "+ lv + "  Opcion 5: Modificar Sitio. \t\t" + lv + "\n"
       +" "+ lv + "  Opcion 6: Eliminar Sitio. \t\t" + lv + "\n"
       +" "+ lv + "  Opcion 7: Salir. \t\t\t" + lv + "\n"
       +" "+ eii + imprimirlinea(205, 38) + eid + "\n";
  return menu;
  /*char esi = 201, esd = 187, eii = 200, eid = 188, lv = 186, lh = 205, id = 185,ii = 204;
  cout <<" "<< esi << imprimirlinea(205, 38) << esd << endl
       <<" "<< lv << "\t\t\t\t\t" << lv << endl
       <<" "<< lv << "\t           MENU       \t\t" << lv << endl
       <<" "<< lv << "\t\t\t\t\t" << lv << endl
       <<" "<< ii << imprimirlinea(205, 38) << id << endl
       <<" "<< lv << "  Opcion 1: Cargar. \t\t\t" << lv << endl
       <<" "<< lv << "  Opcion 2: Cantidad de Sitios. \t" << lv << endl
       <<" "<< lv << "  Opcion 3: Obtener Sitio. \t\t" << lv << endl
       <<" "<< lv << "  Opcion 4: Crear Sitio. \t\t" << lv << endl
       <<" "<< lv << "  Opcion 5: Modificar Sitio. \t\t" << lv << endl
       <<" "<< lv << "  Opcion 6: Eliminar Sitio. \t\t" << lv << endl
       <<" "<< eii << imprimirlinea(205, 38) << eid << endl;*/
}
string imprimirlinea(int numchar, int longitud) {
  char m = numchar;
  string linea = "";
  for (int w = 0; w < longitud; w++) {
    linea += m;
  }
  return linea;
}
string cargarArchivo(list<lugar *> &lugars,string nombrearch) {

   string x = nombrearch;
    char *y = new char[x.length() + 1];
    strcpy(y, x.c_str());
    cout<<y;
  ifstream archivo(strcat(y));
    delete[] y;
  char linea[100];
  if (archivo) {
    char *token;
    int cant, numtipos;
    archivo.getline(linea, sizeof(linea));
    // cout << linea << endl;
    token = strtok(linea, "\t");
    cant = atoi(token);
    token = strtok(NULL, "\t");
    numtipos = atoi(token);
    // cout<<numtipos<<"---"<<cant<<endl;
    // while (!archivo.eof())                        // WHILE O FOR CUALQUIERA
    for (int w = 0; w < cant; w++) {
      archivo.getline(linea, sizeof(linea));
      // cout << linea << endl;

      // NOMBRE
      token = strtok(linea, "\t");
      char nombre[10], tipo[10], lat[10], lon[10];
      int tipol;
      double latl, lonl;

      //  cout << "token: " << token << endl;
      strcpy(nombre, token);
      string nombrel(nombre);
      // cout << "cadena aux: " << nombrel << endl;
      // TIPO
      token = strtok(NULL, "\t");
      //  cout << "token: " << token << endl;
      strcpy(tipo, token);
      tipol = atoi(tipo);
      if (tipol < 0 && tipol > numtipos) {
        archivo.close();
        return "FALLO!\n";
      }
      // cout << "cadena aux: " << tipol << endl;
      // LAT
      token = strtok(NULL, "\t");
      //  cout << "token: " << token << endl;
      strcpy(lat, token);
      // IPORTANTE: double atof (const char* str);
      latl = atof(lat);
      // cout << "cadena aux: " << latl << endl;
      // lON
      token = strtok(NULL, "\t");
      // cout << "token: " << token << endl;
      strcpy(lon, token);
      lonl = atof(lon);
      // lonl=3.0035847;
      // cout<<endl;
      /* printf("%.7lf",lonl);
       cout<<endl;
       cout << "cadena aux: " << lonl << endl;*/
      lugars.push_back(new lugar(nombrel, tipol, latl, lonl));
    }
  }
  else
  {
    archivo.close();
    return "FALLO. El archivo no existe.\n";
  }
  archivo.close();

  return "EXITO!\n";
}

void imprimirLista(list<lugar *> lugars) {
  for (list<lugar *>::iterator it = lugars.begin(); it != lugars.end(); it++) {
    cout << "-->" << (*it)->getNombre() << endl;
  }
}
