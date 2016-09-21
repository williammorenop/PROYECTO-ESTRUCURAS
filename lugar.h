

#ifndef LUGAR
#define LUGAR
#include <iostream>

//#define RADIOTIERRA 6378;

class lugar {
private:
  std::string nombre;
  int tipo;
  double lat;
  double lon;
  double latrad;
  double lonrad;

public:
  lugar(std::string nombre, int tipo, double lat, double lon);
  ~lugar();
  std::string getNombre();
  int getTipo();
  double toRadian(double grados);
  double calularDistanciaKm(double latm,double lonm);
  /*void setnombre(string const aux);
  void settipo(int const aux);
  void setlat(double const aux);
  void setlon(double const aux);*/


  double getLat();
  double getLon();
};

#include "lugar.hxx"
#endif
