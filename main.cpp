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
string imprimirGracias();
void cantidadSitios(list<lugar *> lugars,string tipo);
int cantidadTotal(list<lugar *> lugars);

void obtenerSitio(list<lugar *> lugars,double x,double y);

void crearSitio(list<lugar *> &lugars,string nombretemp,int tipotemp,double lattemp,double lontemp);

void modificarSitio(list<lugar *> &lugars,string newname,int newtipo,double lat,double lon,double newlat,double newlon);
list<lugar *>::iterator obtenerSitio2(list<lugar *> &lugars,double x,double y);

void eliminarSitio(list<lugar *> &lugars,double lat,double lon);
int main()
{
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
        switch (opcion)
        {
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
            string tipo;
            cout<<"Ingrese el tipo de sitio(ingrese 'T' si desea todos): ";
            cin>>tipo;
            if(tipo=="T")
            {
                cout<<"Cantidad Sitios: "<<cantidadTotal(lugares)<<endl;
            }
            else
            {
                cantidadSitios(lugares,tipo);
            }

            break;
        }
        case 3:
        {
            double x,y;
            cout<<"Ingrese lat seguido de la lon: ";
            cin>>x>>y;
            //cout<<x<<" "<<y;
            obtenerSitio(lugares, x, y);
            break;
        }
        case 4:
        {
            string nombretemp;
            int tipotemp;
            double lattemp,lontemp;
            cout<<"Ingrese el nombre, tipo, lat y lon del sitio: (Example:Plaza 2 35.3 45.6)"<<endl;
            cin>>nombretemp>>tipotemp>>lattemp>>lontemp;
            crearSitio(lugares,nombretemp,tipotemp,lattemp,lontemp);
            break;
        }
        case 5:
        {
            string nuevonombre;
            int nuevotipo;
            double lon, lat, nuevalat,nuevalon;
            cout<<"Ingrese lat, lon, nuevo nombre, nuevo tipo, nueva lat, nueva lon seguido de ENTER:"<<endl;
            cin>>lat>>lon>>nuevonombre>>nuevotipo>>nuevalat>>nuevalon;
            modificarSitio(lugares,nuevonombre,nuevotipo,lat,lon,nuevalat,nuevalon);
            break;
        }
        case 6:
        {
            cout<<"Ingrese lat y lon: ";
            int latelim, longelim;
            cin>>latelim>>longelim;
            eliminarSitio( lugares,latelim,longelim);
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

    cout<<imprimirGracias();


    return (0);
}
void eliminarSitio(list<lugar *> &lugars,double lat,double lon)
{
    if(!lugars.empty())
    {
        list<lugar *>::iterator eliminado=obtenerSitio2(lugars,lat,lon);
        cout<<"El sitio "<<(*eliminado)->getNombre()<<" en las coordenadas ("<<(*eliminado)->getLat()<<","<<(*eliminado)->getLon()<<") ha sido eliminado."<<endl;
        lugars.erase(eliminado);
    }
    else
    {
        cout<<"No se han ingresado lugares."<<endl;
    }



}

void modificarSitio(list<lugar *> &lugars,string newname,int newtipo,double lat,double lon,double newlat,double newlon)
{
    if(!lugars.empty())
    {
        list<lugar*>::iterator elmodificado =obtenerSitio2(lugars,lat,lon);
        cout<< "La informacion del Sitio "<< (*elmodificado)->getNombre();
        (*elmodificado)->setNombre(newname);
        (*elmodificado)->setTipo(newtipo);
        (*elmodificado)->setLat(newlat);
        (*elmodificado)->setLon(newlon);

        cout<<" se ha actualizado a: "<<newname<<" de tipo "<<newtipo<<", con coordenadas ("<<newlat<<","<<newlon<<")."<<endl ;
    }
    else
    {
        cout<<"No se han ingresado lugares."<<endl;
    }
}

string imprimirGracias()
{
    string gracias="";
    char esi = 201, esd = 187, eii = 200, eid = 188, lv = 186, lh = 205, id = 185,ii = 204;
    gracias=gracias
            +"\n "+ esi + imprimirlinea(205, 38) + esd + "\n"
            +" "+ lv + "\t\t\t\t\t" + lv + "\n"
            +" "+ lv + "      GRACIAS POR PREFERIRNOS.       \t" + lv + "\n"
            +" "+ lv + "\t\t\t\t\t" + lv + "\n"
            +" "+ eii + imprimirlinea(205, 38) + eid + "\n";
    return gracias;
}

void crearSitio(list<lugar *> &lugars,string nombretemp,int tipotemp,double lattemp,double lontemp)
{
    lugars.push_back(new lugar(nombretemp,tipotemp,lattemp,lontemp));
    cout<<"El sitio de tipo "<<tipotemp<<" en ("<<lattemp<<","<<lontemp<<") ha sido creado."<<endl;

}

void obtenerSitio(list<lugar *> lugars,double x,double y)
{
    if(!lugars.empty())
    {
        double distancia;
        string nombre;
        int tipo;
        double lat;
        double lon;
        for (list<lugar *>::iterator it = lugars.begin(); it != lugars.end(); it++)
        {
            if(it==lugars.begin())
            {
                distancia=(*it)->calularDistanciaKm(x,y);
                nombre=(*it)->getNombre();
                tipo=(*it)->getTipo();
                lat=(*it)->getLat();
                lon=(*it)->getLon();
            }
            else
            {
                if((*it)->calularDistanciaKm(x,y)<distancia)
                {
                    distancia=(*it)->calularDistanciaKm(x,y);
                    nombre=(*it)->getNombre();
                    tipo=(*it)->getTipo();
                    lat=(*it)->getLat();
                    lon=(*it)->getLon();
                }
            }
        }
        cout<<"El sitio turistico mas cercano se encuentra a "<<distancia<<" metros. Su nombre es "<<nombre<<", es de tipo "<<tipo<<" y se ubica en ("<<lat<<","<<lon<<").\n";

    }
    else
    {
        cout<<"No se han ingresado lugares."<<endl;
    }
}

list<lugar *>::iterator obtenerSitio2(list<lugar *> &lugars,double x,double y)
{
    double distancia;
    string nombre;
    int tipo;
    double lat;
    double lon;
    list<lugar *>::iterator aux;
    for (list<lugar *>::iterator it = lugars.begin(); it != lugars.end(); it++)
    {
        if(it==lugars.begin())
        {
            distancia=(*it)->calularDistanciaKm(x,y);
            aux=it;
        }
        else
        {
            if((*it)->calularDistanciaKm(x,y)<distancia)
            {
                aux=it;
            }
        }
    }
    return aux;
}

void cantidadSitios(list<lugar *> lugars,string tipo)
{
    int cont=0;
    int tipoint=atoi(tipo.c_str());
    for (list<lugar *>::iterator it = lugars.begin(); it != lugars.end(); it++)
    {
        if((*it)->getTipo()==tipoint)
        {
            cont++;
        }
    }
    if(cont==0)
    {
        cout <<"No hay sitios de tipo: "<<tipo<<"\n";
    }
    else
    {
        cout<<"Hay "<<cont<<" sitios de tipo "<<tipo<<"\n";
    }
}
int cantidadTotal(list<lugar *> lugars)
{
    return lugars.size();
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
string imprimirlinea(int numchar, int longitud)
{
    char m = numchar;
    string linea = "";
    for (int w = 0; w < longitud; w++)
    {
        linea += m;
    }
    return linea;
}
string cargarArchivo(list<lugar *> &lugars,string nombrearch)
{
    //http://www.cplusplus.com/forum/general/100714/
    ////////////////////////////////////////////////
    char *y = new char[nombrearch.length() /*+ 1*/];
    strcpy(y, nombrearch.c_str());
    ///////////////////////////////////////////////////
    ifstream archivo(y);
    char linea[100];
    if (archivo)
    {
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
        for (int w = 0; w < cant; w++)
        {
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
            if (tipol < 0 && tipol > numtipos)
            {
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
    delete[] y;
    return "EXITO!\n";
}

void imprimirLista(list<lugar *> lugars)
{
    for (list<lugar *>::iterator it = lugars.begin(); it != lugars.end(); it++)
    {
        cout << "-->" << (*it)->getNombre() << endl;
    }
}
