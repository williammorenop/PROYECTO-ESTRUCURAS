#include "lugar.h"
#include <cmath>




lugar::lugar(std::string nombre, int tipo, double lat, double lon) {
  this->nombre = nombre;
  this->tipo = tipo;
  this->lat = lat;
  this->lon = lon;
  this->latrad=toRadian(lat);
  this->lonrad=toRadian(lon);
}

std::string lugar::getNombre(){
return this->nombre;
}

int lugar::getTipo()
{
    return this->tipo;
}

double lugar::toRadian(double grados)
{
    double res=(((2)*M_PI)*grados)/360;
    return res;


}

double lugar::getLat()
{

    return this->lat;
}

double lugar::getLon()
{

    return this->lon;
}

double lugar::calularDistanciaKm(double latm,double lonm)
{
    double diflat=toRadian(this->lat - latm);
    double diflon=toRadian(this->lon - lonm);
    double a=sin(diflat/2)+cos(toRadian(latm))*cos(latrad)*pow(sin(diflon/2),2);
    double c=2*atan2(sqrt(a),sqrt(1-a));
    double distanciaKm=6378*c;
    double distanciaM=distanciaKm*1000;
    return distanciaM;
}
