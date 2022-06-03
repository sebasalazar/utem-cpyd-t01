#include <iomanip>

#include "Response.h"

Response::Response() {
    this->studentToken = "";
    this->q01 = '-';
    this->q02 = '-';
    this->q03 = '-';
    this->q04 = '-';
    this->q05 = '-';
    this->q06 = '-';
    this->q07 = '-';
    this->q08 = '-';
    this->q09 = '-';
    this->q10 = '-';
    this->q11 = '-';
    this->q12 = '-';
    this->goods = 0;
    this->bads = 0;
    this->omitted = 12;
    this->score = 0.0;
    this->grade = 1.0;
    this->valid = false;
}

Response::Response(std::string line) {
    try {
        // Asumo que alerta de spoiler (sala mal)
        // LINE: "2fda1bb7-41fc-472e-a2b7-df4728aac7e4";"E";"B";"B";"E";"E";"C";"A";"D";"A";"E";"B";"E"
        this->valid = false;
        if (!line.empty()) {
            // quitar el caracter '"' de la cadena (string)
            line.erase(std::remove(line.begin(), line.end(), '"'), line.end());
            // LINE: 2fda1bb7-41fc-472e-a2b7-df4728aac7e4;E;B;B;E;E;C;A;D;A;E;B;E

            // pasar de ';' -> ' '
            std::replace(line.begin(), line.end(), ';', ' ');
            // LINE: 2fda1bb7-41fc-472e-a2b7-df4728aac7e4 E B B E E C A D A E B E

            // Pasamos la línea a un arreglo
            std::vector<std::string> columns;
            std::stringstream ss(line);
            std::string current;
            while (ss >> current) {
                // current:  2fda1bb7-41fc-472e-a2b7-df4728aac7e4 
                columns.push_back(current);
            }

            this->studentToken = columns.at(0);
            this->q01 = columns.at(1).at(0);
            this->q02 = columns.at(2).at(0);
            this->q03 = columns.at(3).at(0);
            this->q04 = columns.at(4).at(0);
            this->q05 = columns.at(5).at(0);
            this->q06 = columns.at(6).at(0);
            this->q07 = columns.at(7).at(0);
            this->q08 = columns.at(8).at(0);
            this->q09 = columns.at(9).at(0);
            this->q10 = columns.at(10).at(0);
            this->q11 = columns.at(11).at(0);
            this->q12 = columns.at(12).at(0);

            // liberamos memoria
            columns.clear();

            int goodSum = 0;
            int badSum = 0;
            int omittedSum = 0;

            // Revisión de preguntas
            if (this->q01 == QUESTION_01) {
                goodSum += 1;
            } else if (this->q01 == IGNORATION) {
                omittedSum += 1;
            } else {
                badSum += 1;
            }

            if (this->q02 == QUESTION_02) {
                goodSum += 1;
            } else if (this->q02 == IGNORATION) {
                omittedSum += 1;
            } else {
                badSum += 1;
            }

            if (this->q03 == QUESTION_03) {
                goodSum += 1;
            } else if (this->q03 == IGNORATION) {
                omittedSum += 1;
            } else {
                badSum += 1;
            }

            if (this->q04 == QUESTION_04) {
                goodSum += 1;
            } else if (this->q04 == IGNORATION) {
                omittedSum += 1;
            } else {
                badSum += 1;
            }

            if (this->q05 == QUESTION_05) {
                goodSum += 1;
            } else if (this->q05 == IGNORATION) {
                omittedSum += 1;
            } else {
                badSum += 1;
            }

            if (this->q06 == QUESTION_06) {
                goodSum += 1;
            } else if (this->q06 == IGNORATION) {
                omittedSum += 1;
            } else {
                badSum += 1;
            }

            if (this->q07 == QUESTION_07) {
                goodSum += 1;
            } else if (this->q07 == IGNORATION) {
                omittedSum += 1;
            } else {
                badSum += 1;
            }

            if (this->q08 == QUESTION_08) {
                goodSum += 1;
            } else if (this->q08 == IGNORATION) {
                omittedSum += 1;
            } else {
                badSum += 1;
            }

            if (this->q09 == QUESTION_09) {
                goodSum += 1;
            } else if (this->q09 == IGNORATION) {
                omittedSum += 1;
            } else {
                badSum += 1;
            }

            if (this->q10 == QUESTION_10) {
                goodSum += 1;
            } else if (this->q10 == IGNORATION) {
                omittedSum += 1;
            } else {
                badSum += 1;
            }

            if (this->q11 == QUESTION_11) {
                goodSum += 1;
            } else if (this->q11 == IGNORATION) {
                omittedSum += 1;
            } else {
                badSum += 1;
            }

            if (this->q12 == QUESTION_12) {
                goodSum += 1;
            } else if (this->q12 == IGNORATION) {
                omittedSum += 1;
            } else {
                badSum += 1;
            }

            // Contar
            this->goods = goodSum;
            this->bads = badSum;
            this->omitted = omittedSum;
            this->score = ((goodSum * GOOD_SCORE) + (badSum * BAD_SCORE));
            this->grade = 1 + this->score;
            this->valid = true;
        }
    } catch (...) {
        std::cerr << "Error al parsear linea de entrada" << std::endl;
        Response();
    }
}

Response::Response(const Response& orig) {
    this->studentToken = orig.studentToken;
    this->q01 = orig.q01;
    this->q02 = orig.q02;
    this->q03 = orig.q03;
    this->q04 = orig.q04;
    this->q05 = orig.q05;
    this->q06 = orig.q06;
    this->q07 = orig.q07;
    this->q08 = orig.q08;
    this->q09 = orig.q09;
    this->q10 = orig.q10;
    this->q11 = orig.q11;
    this->q12 = orig.q12;
    this->goods = orig.goods;
    this->bads = orig.bads;
    this->omitted = orig.omitted;
    this->score = orig.score;
    this->grade = orig.grade;
    this->valid = orig.valid;
}

Response::~Response() {
}

std::string Response::GetResult() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << this->grade;
    std::string gradeStr = stream.str();

    std::string out = "\"" + this->studentToken + "\";"
            + "\"" + std::to_string(this->goods) + "\";"
            + "\"" + std::to_string(this->bads) + "\";"
            + "\"" + std::to_string(this->omitted) + "\";"
            + "\"" + std::to_string(this->score) + "\";"
            + "\"" + gradeStr + "\"";
    return out;
}

bool Response::isValid() {
    return valid;
}