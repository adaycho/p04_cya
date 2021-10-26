// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo comment.cc: clase comment
// Contiene la definición de los métodos de la clase comment, asi como
// su constructor y la sobrecarga de salida
// Referencias:
// Enlaces de interés:

#include "comment.h"

// Constructores
Comment::Comment(const int start, const int finish, const std::string text) {
  start_ = start;
  finish_ = finish;
  text_ = text;
}
Comment::Comment(const int line, const std::string comment) {
  start_ = line;
  finish_ = line;
  text_ = comment;
}

//Getter de las lineas que ocupa un comentario
std::string Comment::Get_Lines() const{
  std::string string;
  if (start_ == finish_) {
    string += "[Line " + std::to_string(finish_) + "]";
  }
  else {
    string += "[Lines " + std::to_string(start_) + "-";
    string += std::to_string(finish_) + "]";
  }
  return string;
}

// Getter del texto
std::string Comment::Get_Text() const {
  return text_;
}

// Sobrecarga de salida
std::ostream& operator<<(std::ostream& out, const Comment& comment) {
  if (comment.start_ == comment.finish_ && comment.start_ == 0) {
    out << comment.text_;
  }
  else if (comment.start_ == comment.finish_) {
    out << "[Line " << comment.start_ << "] " << comment.text_;
  }
  else {
    out << "[Lines " << comment.start_ << "-" << comment.finish_  << "]: ";
    out << comment.text_;
  }
  return out;
}