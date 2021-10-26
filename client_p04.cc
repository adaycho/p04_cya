// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Aday Chocho Aisa
// Correo: alu0101437538@ull.edu.es
// Fecha: 09/10/2021
// Archivo client_p04.cc: programa cliente.
// Contiene la función main del proyecto que usa la clase code_analyzer
// para analizar un fichero de código pasado por parámetros y guardarlo
// en otro fichero
// Referencias:
// Enlaces de interés:


#include "code_analyzer.h"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Error en la ejecución del programa. Se ejecuta de la "
    << "siguiente manera: " << std::endl;
    std::cout << argv[0] << " code.cc codesheme.txt" << std::endl;
    std::cout << "code.cc -> Programa a analizar" << std::endl;
    std::cout << "codescheme.txt -> Fichero de salida" << std::endl;
  }
  else {
    Code_Analyzer file(argv[1]);
    file.Save(argv[2]);
  }
  return 0;
}