#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include <string>

bool isnumber(std::string num);

int exponent_log_error(std::vector<std::string> exp);

std::vector<std::string> subvector(std::vector<std::string> &vect, int index1, int index2);

bool isoperator(std::string opr);

bool isspecialfunc(std::string func);

void lonedecimalcorrection(std::vector<std::string> &dec);

bool bracketerror(std::string input);

bool divbyzero(std::vector<std::string> inp);

std::string concatenate(std::vector<std::string> vect);

std::vector<std::string> splitstring(std::string str);

std::string ctos(char A);

void condensemultdiv(std::vector<std::string> &num_and_opr);

void condensefunc(std::vector<std::string> &func);

void condenseexp(std::vector<std::string> &power);

double sum(std::vector<std::string> numbers);

std::string evaluate(std::vector<std::string> vect);




#endif // FUNCTIONS_H
