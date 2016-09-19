#include "lugar.h"

lugar::lugar(std::string nombre, int tipo, double lat, double lon) {
  this->nombre = nombre;
  this->tipo = tipo;
  this->lat = lat;
  this->lon = lon;
}

std::string lugar::getNombre() { return this->nombre; }
