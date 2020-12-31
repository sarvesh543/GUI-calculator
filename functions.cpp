#include "functions.h"
#include <vector>
#include <string>
#include <cmath>

bool isnumber(std::string num){
//checks if entered str is a digit
//used in displaystring class addtodisplay function
    if(num == "0" || num == "1" || num == "2" || num == "3" || num == "4" || num == "5" || num == "6" || num == "7" || num == "8" || num == "9"){
        return true;
    }
    return false;
}

bool isoperator(std::string opr){
//checks if entered str is a operator
//used in displaystring class addtodisplay function
    if(opr == "*" || opr == "/" || opr == "+" || opr == "-"){
        return true;
    }
    return false;
}

std::vector<std::string> subvector(std::vector<std::string> &vect, int index1, int index2){
//takes a vector and gives out a subvector from index1 to index2
    std::vector<std::string> out;
    for(int i = index1; i <= index2; i++){
        out.push_back(vect[i]);
    }
    return out;
}

std::string concatenate(std::vector<std::string> vect){
//joins all strings in a string vector into one string and outputs it
    std::string s = "";
    for(unsigned int i = 0; i < vect.size(); i++){
        s.append(vect[i]);
    }
    return s;
}

std::vector<std::string> splitstring(std::string str){
//takes a string and splits it into characters which are converted to strings and stored in a string vector
    std::vector<std::string> temp;
    for(unsigned int i = 0; i < str.length(); i++){
        temp.push_back(ctos(str[i]));
    }
    return temp;
}

void lonedecimalcorrection(std::vector<std::string> &dec){
//takes a string vector containing numbers and * andd / as input
//if * or / is followed by a num with a decimal at start
//then this function adds 0 before decimal in that number
    std::string temp1;
    std::string temp2 = "0";
    for(unsigned int i = 0;i < dec.size(); i++){
        if(dec[i][0] == '.'){
            temp1 = dec[i];
            dec[i] = temp2.append(temp1);

        }
    }
}

bool bracketerror(std::string input){
//checks for invalid bracket syntax before string is evaluated
    int brkcount = 0;
    for(unsigned int i = 0; i < input.length(); i++){
        if(input[i] == '('){
            brkcount += 1;
        }else if(input[i] == ')'){
            brkcount -= 1;
        }
        if(brkcount < 0){
            return true;     //if any close bracket comes before open bracket which is invalid syntax
        }                    //then bracket count becomes negative
    }
    if(brkcount > 0){
        return true;         //if at end of string brkcount is non zero then it indicates a bracket error
    }                        //as the number of open brackets does not equal close brackets
    return false;            //if none of above are true at end of string then there is no bracket error
}

bool divbyzero(std::vector<std::string> inp){
//takes a string vector containing num,*,/
//if a string "0" is preceded by / symbol then it is div by zero error;
    for(unsigned int i = 0; i < inp.size(); i++){
        double temp;
        if(inp[i] == "/"){
            temp = fabs(stod(inp[i+1]));
            if(temp - floor(temp) < 0.0000000000000001 && floor(temp) == 0){
                return true;
            }
        }
    }
    return false;
}

std::string ctos(char A){
//converts a char into a string
//this was needed because string indexing returns a char but needed to be compared to strings in a lot of places
    std::string out = "a";
    out[0] = A;
    return out;
}

void condense(std::vector<std::string> &num_and_opr){
//takes a string vector containing num,*,/
// for * or / the function evaluates the number before and after operator with operator and replaces all
// three with the evaluated output
    double result;
    for(unsigned int i = 0; i < num_and_opr.size(); i++){

        if(num_and_opr[i] == "*"){

            result = stod(num_and_opr[i-1])*stod(num_and_opr[i+1]);

            num_and_opr.erase(num_and_opr.begin()+i);
            num_and_opr.erase(num_and_opr.begin()+i);

            num_and_opr[i-1] = std::to_string(result);
            i -= 1;

        }else if(num_and_opr[i] == "/"){
            result = stod(num_and_opr[i-1])/stod(num_and_opr[i+1]);
            num_and_opr.erase(num_and_opr.begin()+i);
            num_and_opr.erase(num_and_opr.begin()+i);
            num_and_opr[i-1] = std::to_string(result);
            i -= 1;

        }else if(num_and_opr.size() == i + 1){
            break;
        }
    }
}

double sum(std::vector<std::string> numbers){
//takes a string vector with num and adds them all up to give a double
    double result = 0;
    for(unsigned int i = 0; i < numbers.size(); i++){
        result += stod(numbers[i]);
    }
    return result;
}

std::string evaluate(std::vector<std::string> vect){
//equation parser
//takes input string and gives the output num in form of string
//uses recursion to evaluate brackets
//returns DIVBYZERO if division with zero error happens
    std::vector<std::string> input = vect;

    double temp;
    std::string result;
    std::vector<std::string> store;
    int prevend = 0;
    std::string minusind = "";
    int bracketcount = 0;
    for(unsigned int i = 0; i < input.size(); i++){
            if(prevend > 0){
                if(input[abs(prevend - 1)] == "-"){
                    minusind = "-";
                }
            }
            if(input[i] == "*" || input[i] == "/"){       
                store.push_back(minusind.append(concatenate(subvector(input, prevend, i - 1))));
                store.push_back(input[i]);
                prevend = i + 1;
                minusind = "";
            }else if(input[i] == "+" || input[i] == "-"){
                if(input[i] == "-" && i == 0){
                }else{
                    store.push_back(minusind.append(concatenate(subvector(input, prevend, i - 1))));
                }
                prevend = i + 1;
                minusind = "";
            }else if(input[i] == "("){
                bracketcount += 1;
                for(unsigned int j = i + 1; j < input.size(); j++){
                    if(input[j] == "("){
                        bracketcount += 1;
                    }else if(input[j] == ")"){
                        bracketcount -= 1;
                    }
                    if(bracketcount == 0){
                        if(evaluate(subvector(input, i+1 , j-1)) == "DIVBYZERO"){
                            return "DIVBYZERO";
                        }
                        temp = stod(evaluate(subvector(input, i+1 , j-1)));
                        if(temp < 0){
                            if(minusind == "-"){
                                store.push_back(std::to_string(-temp));
                            }else{                 
                                store.push_back(std::to_string(temp));
                            }
                        }else{
                            store.push_back(minusind.append(evaluate(subvector(input, i+1 , j-1))));
                        }
                        i = j + 1;
                        prevend = j + 2;
                        if(j < input.size()-1){
                            if(input[j + 1] == "*" || input[j + 1] == "/"){
                                store.push_back(input[j + 1]);
                            }
                        }
                        minusind = "";
                        break;
                    }
                }
            }else if(i == input.size()-1){
                store.push_back(minusind.append(concatenate(subvector(input, prevend, i))));
                prevend = i + 1;
                minusind = "";
            }
    }
    if(divbyzero(store)){
        return "DIVBYZERO";
    }
    lonedecimalcorrection(store);
    condense(store);
    result = std::to_string(sum(store));
    return result;
}
