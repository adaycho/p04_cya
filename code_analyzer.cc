// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo code_analyzer.cc: clase code_analyzer
// Contiene la definición de los métodos de la clase code_analyzer, así
// como su constructor
// Referencias:
// Enlaces de interés:

#include "code_analyzer.h"

// Constructor
Code_Analyzer::Code_Analyzer(std::string program) {
  std::ifstream infile(program);
  program_ = program;
  std::string target;
  description_ = Comment (0, "No description");
  main_ = false;
  while (getline(infile, target)) {
    text_.push_back(target);
    if (regex_search(target, kComment) == true) {
      int found = target.find_first_of("//");
      Comment new_comment(text_.size(), target.substr(found));
      comments_.push_back(new_comment);
    }
    else if (regex_search(target, kMultiCommentStart) == true) {
      std::string string;
      int start = text_.size();
      while (regex_search(target, kMultiCommentFinish) == false) {
        string+= "\n" + target;
        getline(infile, target);
        text_.push_back(target);
      }
      string+= "\n" + target;
      int found = string.find("/*");
      string = string.substr(found);
      found = string.find("*/");
      Comment new_comment(start, text_.size(), string.substr(0, found + 2));
      comments_.push_back(new_comment);
      if (start == 1) {
        description_ = new_comment;
      }
    }

    if (regex_search(target, kSearchLoop) == true) {
      Statement new_statement(text_.size(), target);
      statements_.push_back(new_statement);
    }
    
    if (regex_search(target, kMainSearch) == true) {
        main_ = true;
    }
    else if (regex_search(target, kIntDoubleSearch) == true) {
      Variable new_variable(text_.size(), target);
      variables_.push_back(new_variable);
    }
  }
  infile.close();
}

// Función dedicada a guardar la información en un archivo
void Code_Analyzer::Save(const std::string file) {
  std::ofstream outfile(file);
  outfile << "PROGRAM: " << program_ << std::endl << std::endl;

  outfile << "DESCRIPTION: " << std::endl << description_;
  outfile << std::endl << std::endl;

  outfile << "STATEMENTS: " << std::endl;
  for (int i = 0; i < statements_.size(); ++i) {
    outfile << statements_[i] << std::endl;
  }
  outfile << std::endl;

  outfile << "VARIABLES: " << std::endl;
  for (int i = 0; i < variables_.size(); ++i) {
    outfile << variables_[i] << std::endl;
  }
  outfile << std::endl;

  outfile << "MAIN: ";
  if (main_) {
    outfile << "True" << std::endl << std::endl;
  }
  else {
    outfile << "False" << std::endl << std::endl;
  }
  outfile << "COMMENTS: " << std::endl;
  for (int i = 0; i < comments_.size(); ++i) {
    if (comments_[i].Get_Text() == description_.Get_Text()) {
      outfile << description_.Get_Lines() << ": DESCRIPTION" << std::endl;

    }
    else {
      outfile << comments_[i] << std::endl;
    }
  }
  outfile.close();
}
