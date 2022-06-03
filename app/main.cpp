#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Response.h"



/**
 * Función que muestra los participantes del grupo
 */
void participantes();

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char** argv) {

    /**
     * Incluir acá la lógica del programa
     * 
     */
    if (argc > 1) {
        std::ifstream csv(argv[1]);
        if (csv.is_open()) {
            std::string header;
            std::getline(csv, header);
            
            std::ofstream outCsv("resultado.csv");
            for(std::string line; std::getline(csv,line);) {
                Response response(line);
                outCsv << response.GetResult() << std::endl;
            }
            outCsv.close();
        }
        csv.close();
    } else {
        // Mostrar los integrantes
        participantes();
    }
    return EXIT_SUCCESS;
}

void participantes() {
    std::cout << std::endl << "=== Taller 01 ===" << std::endl;
    std::cout << std::endl << "Sebastián Salazar Molina" << std::endl;
}