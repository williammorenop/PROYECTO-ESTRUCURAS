

#ifndef LUGAR
#define LUGAR
#include <iostream>

class lugar {
private:
  std::string nombre;
  int tipo;
  double lat;
  double lon;

public:
  lugar(std::string nombre, int tipo, double lat, double lon);
  ~lugar();
  std::string getNombre();
  /*void setnombre(string const aux);
  void settipo(int const aux);
  void setlat(double const aux);
  void setlon(double const aux);

  int Gettipo();
  double Getlat();
  double Getlon();*/
};

#include "lugar.hxx"
#endif
