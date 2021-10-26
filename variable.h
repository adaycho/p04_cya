// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo variable.h: clase variable
// Contiene la declaración de la clase variable
// Referencias:
// Enlaces de interés:


#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <regex>

const std::regex kIntDoubleSearch("\\s+?int|double .*");
const std::regex kIntSearch("\\s*int.*");
const std::regex kVSearchName("[a-zA-Z0-9_-]+");
const std::regex kVSearchNumber("[0-9.]+");

// Clase dedicada a almacenar la información de las variables
class Variable {
 public:
  Variable(int line, std::string text);
  Variable() : line_(), type_(), name_(), value_() {};

  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& out, const Variable& variable);
  
 private:
  int line_;
  std::string type_;
  std::string name_;
  bool is_value_;
  std::string value_;
};

#endif