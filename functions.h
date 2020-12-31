#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include <string>

bool isnumber(std::string num);

std::vector<std::string> subvector(std::vector<std::string> &vect, int index1, int index2);

bool isoperator(std::string opr);

void lonedecimalcorrection(std::vector<std::string> &dec);

bool bracketerror(std::string input);

bool divbyzero(std::vector<std::string> inp);

std::string concatenate(std::vector<std::string> vect);

std::vector<std::string> splitstring(std::string str);

std::string ctos(char A);

void condense(std::vector<std::string> &num_and_opr);

double sum(std::vector<std::string> numbers);

std::string evaluate(std::vector<std::string> vect);




#endif // FUNCTIONS_H
