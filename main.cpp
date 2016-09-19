#include "lugar.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <stdlib.h>

using namespace std;

string cargarArchivo(list<lugar *> &lugars); // mientras testeamos no recibe
                                             // argumentos en un futuro recibe
                                             // el nombre del archivo
void imprimirLista(list<lugar *> lugars);
int main() {

  // lugar* a = new lugar("sda", 2, 2.2, 3.2);

  list<lugar *> lugares;
  cout << cargarArchivo(lugares);
  system("PAUSE");
  imprimirLista(lugares);

  return (0);
}
string cargarArchivo(list<lugar *> &lugars) {
  ifstream archivo("sample1.in");
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
  archivo.close();

  return "EXITO!\n";
}

void imprimirLista(list<lugar *> lugars) {
  for (list<lugar *>::iterator it = lugars.begin(); it != lugars.end(); it++) {
    cout << "-->" << (*it)->getNombre() << endl;
  }
}
