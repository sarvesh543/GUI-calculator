#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include <string>


void lonedecimalcorrection(std::vector<std::string> &dec);

bool bracketerror(std::string input);

bool divbyzero(std::vector<std::string> inp);

bool isnumber(std::string num);

bool isoperator(std::string opr);

std::string ctos(char A);

void condense(std::vector<std::string> &num_and_opr);

double sum(std::vector<std::string> numbers);

std::string evaluate(std::string input);



#endif // FUNCTIONS_H
