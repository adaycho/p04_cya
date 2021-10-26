// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo comment.h: clase comment
// Contiene la declaración de la clase comment
// Referencias:
// Enlaces de interés:

#ifndef COMMENT_H
#define COMMENT_h

#include <string>
#include <vector>
#include <fstream>

// Clase dedicada a almacenar los comentarios
class Comment {
 public:
  // Constructores
  Comment(const int start, const int finish, const std::string text);
  Comment(const int line, const std::string text);
  Comment() : start_(), finish_(), text_() {};

  // Funciones
  std::string Get_Lines() const;
  std::string Get_Text() const;

  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& out, const Comment& comment);

 private:
  int start_;
  int finish_;
  std::string text_;
};

#endif