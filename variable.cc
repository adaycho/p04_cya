// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo variable.cc: clase variable
// Contiene la definición de los métodos de la clase variable,
// asi como su constructor y la sobrecarga de salida
// Referencias:
// Enlaces de interés:

#include "variable.h"

// Constructor
Variable::Variable(int line, std::string text) {
  line_ = line;
  std::string string = text;
  int found;
  if (regex_search(text, kIntSearch) == true) {
    type_ = "INT: ";
    found = string.find("int");
    string = string.substr(found);
  }
  else {
    type_ = "DOUBLE: ";
    found = string.find("double");
    string = string.substr(found);
  }
  std::smatch match;
  found = string.find_first_of(" ");
  string = string.substr(found + 1);
  if (regex_search(string, match, kVSearchName)) {
    name_ = match.str(0);
  }
  found = string.find_first_of("({=;");
  string = string.substr(found);
  is_value_ = false;
  if (regex_search(string, match, kVSearchNumber) == true) {
    value_ = match.str(0);
    is_value_ = true;
  }
}

// Sobrecarga de salida
std::ostream& operator<<(std::ostream& out, const Variable& variable) {
  out << "[Line " << variable.line_ << "] " << variable.type_;
  out << variable.name_;
  if (variable.is_value_){
    out << " = " << variable.value_ ;
  }
  return out;
}
