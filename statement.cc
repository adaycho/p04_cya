// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo statement.cc: clase statement
// Contiene la definición de la sobrecarga y el constructor de la
// clase statement
// Referencias:
// Enlaces de interés:

#include "statement.h"

// Constructor
Statement::Statement(const int line, const std::string text) {
  line_ = line;
  if (regex_search(text, kSearchFor) == true) {
    type_ = "for";
  }
  else if (regex_search(text, kSearchWhile) == true) {
    type_ = "while";
  }
}

// Sobrecarga de salida
std::ostream& operator<<(std::ostream& out, const Statement& statement) {
  out << "[Lines " << statement.line_ << "] ";
  if (statement.type_ == "for" || statement.type_ == "while") {
    out << "LOOP : " << statement.type_;
  }
  return out;
}
