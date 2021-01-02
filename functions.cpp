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

bool isspecialfunc(std::string func){
    if(func == "ln" || func == "log" || func == "sin" || func == "cos" || func == "tan"){
        return true;
    }
    return false;
}

int exponent_log_error(std::vector<std::string> exp){
    for(unsigned int i = 0; i < exp.size() - 1; i++){
        if(exp[i] == "^" && exp[i-1][0] == '-'){
            return 1;
        }
        if((exp[i] == "ln" || exp[i] == "log") && stod(exp[i+1]) <= 0.00000000000000000001){
            return -1;
        }
    }
    return 0;
}

bool isoperator(std::string opr){
//checks if entered str is a operator
//used in displaystring class addtodisplay function
    if(opr == "*" || opr == "/" || opr == "+" || opr == "-" || opr == "^"){
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

void condensemultdiv(std::vector<std::string> &num_and_opr){
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

void condenseexp(std::vector<std::string> &power){
// evaluates exponentiation in the vector
    double result;
    for(unsigned int i = 0; i < power.size(); i++){
        if(power[i] == "^"){
            if(power[i-1][0] == '-'){
                result = pow( stod(power[i-1].substr(1, power[i-1].length() - 1)), stod(power[i+1]))*cos(M_PI * stod(power[i+1]));
                power.erase(power.begin()+i);
                power.erase(power.begin()+i);
                power[i-1] = std::to_string(result);
            }else{
                result = pow( stod(power[i-1]), stod(power[i+1]));
                power.erase(power.begin()+i);
                power.erase(power.begin()+i);
                power[i-1] = std::to_string(result);
            }
            i -= 1;
        }else if(power.size() == i + 1){
            break;
        }
    }
}

void condensefunc(std::vector<std::string> &func){
//evaluates special functions
    double result;
    for(unsigned int i = 0; i < func.size(); i++){
        if(func[i] == "ln"){
            result = log(stod(func[i+1]));
            func.erase(func.begin()+i);
            func[i] = std::to_string(result);
            i -= 1;
        }else if(func[i] == "log"){
            result = log10(stod(func[i+1]));
            func.erase(func.begin()+i);
            func[i] = std::to_string(result);
            i -= 1;
        }else if(func[i] == "sin"){
            result = sin(stod(func[i+1]));
            func.erase(func.begin()+i);
            func[i] = std::to_string(result);
            i -= 1;
        }else if(func[i] == "cos"){
            result = cos(stod(func[i+1]));
            func.erase(func.begin()+i);
            func[i] = std::to_string(result);
            i -= 1;
        }else if(func[i] == "tan"){
            result = tan(stod(func[i+1]));
            func.erase(func.begin()+i);
            func[i] = std::to_string(result);
            i -= 1;
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

    std::string temp;
    int errorresult;
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
            if(input[i] == "*" || input[i] == "/" || input[i] == "^"){
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
            }else if(isspecialfunc(input[i])){
                store.push_back(input[i]);
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
                        temp = evaluate(subvector(input, i+1 , j-1));
                        if(temp == "POWERROR"){
                            return "POWERROR";
                        }else if(temp == "LOGERROR"){
                            return "LOGERROR";
                        }else if(temp == "DIVBYZERO"){
                            return "DIVBYZERO";
                        }
                        if(stod(temp) < 0){
                            if(minusind == "-"){
                                store.push_back(std::to_string(-stod(temp)));
                            }else{                 
                                store.push_back(std::to_string(stod(temp)));
                            }
                        }else{
                            store.push_back(minusind.append(evaluate(subvector(input, i+1 , j-1))));
                        }
                        i = j + 1;
                        prevend = j + 2;
                        if(j < input.size()-1){
                            if(input[j + 1] == "*" || input[j + 1] == "/" || input[j+1] == "^"){
                                store.push_back(input[j + 1]);
                            }
                            if(isspecialfunc(input[j+2])){
                                store.push_back(input[j+2]);
                                prevend = j + 3;
                                i = j+2;
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
    errorresult = exponent_log_error(store);
    if(errorresult == 1){
        return "POWERROR";
    }else if(errorresult == -1){
        return "LOGERROR";
    }
    condensefunc(store);
    condenseexp(store);
    if(divbyzero(store)){
        return "DIVBYZERO";
    }
    lonedecimalcorrection(store);
    condensemultdiv(store);
    result = std::to_string(sum(store));
    return result;
}
