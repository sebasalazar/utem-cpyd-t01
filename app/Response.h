#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#define QUESTION_01 (char) 'A'
#define QUESTION_02 (char) 'E'
#define QUESTION_03 (char) 'C'
#define QUESTION_04 (char) 'B'
#define QUESTION_05 (char) 'B'
#define QUESTION_06 (char) 'D'
#define QUESTION_07 (char) 'A'
#define QUESTION_08 (char) 'B'
#define QUESTION_09 (char) 'E'
#define QUESTION_10 (char) 'C'
#define QUESTION_11 (char) 'B'
#define QUESTION_12 (char) 'D'
#define IGNORATION (char) '-'

#define GOOD_SCORE 0.5
#define BAD_SCORE -0.12

class Response {
public:
    Response();
    Response(std::string line);
    Response(const Response& orig);
    virtual ~Response();
    std::string GetResult();
    bool isValid();
private:
    std::string studentToken;
    char q01;
    char q02;
    char q03;
    char q04;
    char q05;
    char q06;
    char q07;
    char q08;
    char q09;
    char q10;
    char q11;
    char q12;
    int goods;
    int bads;
    int omitted;
    double score;
    double grade;
    bool valid;
};

#endif /* RESPONSE_H */

