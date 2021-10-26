// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo code_analyzer.h: clase code_analyzer
// Contiene la declaración de la clase code_analyzer
// Referencias:
// Enlaces de interés:

#ifndef CODE_ANALYZER_H
#define CODE_ANALYZER_H

#include <fstream>
#include <iostream>
#include <regex>
#include "comment.h"
#include "variable.h"
#include "statement.h"

const std::regex kComment("//.*");
const std::regex kMultiCommentStart("/\\*.*");
const std::regex kMultiCommentFinish(".*\\*/");
const std::regex kMainSearch("int main");

// Clase dedicada a analizar el archivo de entrada
class Code_Analyzer {
 public:
  // Constructores
  Code_Analyzer(std::string program);

  // Funciones
  void Save(const std::string file);

 private:
  std::vector<std::string> text_;
  std::string program_;
  Comment description_;
  std::vector<Variable> variables_;
  std::vector<Statement> statements_;
  std::vector<Comment> comments_;
  bool main_;
};

#endif