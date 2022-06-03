#include <iostream>
#include <cstdlib>
#include <fstream>
#include <mpi/mpi.h>
#include "Response.h"

#define LEADER 0
#define READ_TASK 13
#define WRITE_TASK 17
#define DATA_SIZE 256

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
    MPI::Init(argc, argv);
    /**
     * Incluir acá la lógica del programa
     * 
     */
    if (argc > 1) {
        const int processors = MPI::COMM_WORLD.Get_size();
        const int me = MPI::COMM_WORLD.Get_rank();
        if (processors > 1) {
            if (me == LEADER) {
                int destination = 0;

                std::ifstream csv(argv[1]);
                if (csv.is_open()) {
                    std::string header;
                    std::getline(csv, header);

                    std::ofstream outCsv("resultado.csv");
                    for (std::string line; std::getline(csv, line);) {
                        if (!line.empty()) {
                            destination += 1;
                            if (destination >= processors) {
                                destination = 1;
                            }

                            // Enviamos a los seguidores
                            MPI::COMM_WORLD.Send(line.c_str(), line.size(), MPI::CHAR, destination, READ_TASK);

                            // Recibir
                            char* data = new char[DATA_SIZE + 1];
                            MPI::COMM_WORLD.Recv(data, DATA_SIZE, MPI::CHAR, destination, WRITE_TASK);
                            outCsv << data << std::endl;
                            delete [] data;
                        }

                    }

                    std::string terminate("");
                    for (int p = 1; p < processors; p++) {
                        MPI::COMM_WORLD.Isend(terminate.c_str(), terminate.size(), MPI::CHAR, p, READ_TASK);
                    }

                    outCsv.close();
                }
                csv.close();
            } else {
                // Código de los equipos seguidores
                bool next = true;
                while (next) {
                    std::cout << "[P" << me << "] esperando datos " << std::endl;
                    MPI::Status responseStatus;
                    char* data = new char[DATA_SIZE + 1]();

                    MPI::Request request = MPI::COMM_WORLD.Irecv(data, DATA_SIZE, MPI::CHAR, LEADER, READ_TASK);
                    request.Wait(responseStatus);

                    std::string dataLine(data);
                    Response response(dataLine);
                    if (response.isValid()) {
                        std::string result = response.GetResult();
                        MPI::COMM_WORLD.Send(result.c_str(), result.size(), MPI::CHAR, LEADER, WRITE_TASK);
                        std::cout << "[P" << me << "] envió " << result << std::endl;
                        next = true;
                    } else {
                        next = false;
                    }

                    delete [] data;
                }

                std::cout << "[P" << me << "] TERMINE! " << std::endl;
            }
        } else {
            // Mostrar los integrantes
            participantes();
        }
    }
    MPI::Finalize();
    return EXIT_SUCCESS;
}

void participantes() {
    std::cout << std::endl << "=== Taller 01 ===" << std::endl;
    std::cout << std::endl << "Sebastián Salazar Molina" << std::endl;
}