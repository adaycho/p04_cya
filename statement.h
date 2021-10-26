// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo statement.h: clase statement
// Contiene la declaración de la clase statement
// Referencias:
// Enlaces de interés:

#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <regex>

const std::regex kSearchLoop("for|while \\s*?(.+)");
const std::regex kSearchFor("for\\s*?(.+)");
const std::regex kSearchWhile("while\\s*?(.+)");

// Clase dedicada a almacenar la información de los bucles
class Statement {
 public:
  // Constructores
  Statement() : line_(), type_() {};
  Statement(const int line, const std::string text);

  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& out, const Statement& statement);
  
 private:
  int line_;
  std::string type_;
};

#endif