#include "displaystring.h"
#include <vector>
#include <string>
#include "functions.h"


// store is a private member of the class
Displaystring::Displaystring()
{}

std::string Displaystring::display(){
// returns the string to be displayed
    return concatenate(storage);
}

// the below functions are to make sure that all inputs that are entered have a valid syntax

void Displaystring::adddecimal(std::string input){
    if(storage[0] == "ERROR"){
        storage = {"0"};
    }
    if(isnumber(storage[storage.size()-1])){
        storage.push_back(input);
    }
}

void Displaystring::addopr(std::string input){
    if(storage[0] == "ERROR"){
        storage = {"0"};
    }
    unsigned int count = 0;
    if(storage[storage.size() - 1] == ")"){
        storage.push_back(input);
    }else if(storage[storage.size() - 1] == "(" && input == "-"){
        storage.push_back(input);
    }else{
        for(unsigned int i = storage.size() - 1 ; i > 0; i--){
            if(isnumber(storage[i]) || storage[i] == "."){
                break;
            }
            count += 1;
        }
        if(count == storage.size()){
            storage = {"0", input};
        }else{
            for(unsigned int i = 0; i < count; i++){
                storage.pop_back();
            }
            storage.push_back(input);
        }
    }

//    if(storage[storage.size() - 1] == "("){
//        if(input =="-"){
//            storage.push_back(input);
//        }else if(isoperator(storage[storage.size()-2]) || isspecialfunc(storage[storage.size()-2])){
//        storage.pop_back();
//        storage.pop_back();
//        storage.push_back(input);
//        }
//     }else if(storage[storage.size()-1] == "-"){
//        if(storage[storage.size()-2] == "("){
//            if(isoperator(storage[storage.size()-3]) || isspecialfunc(storage[storage.size()-3])){
//                storage.pop_back();
//                storage.pop_back();
//                storage.pop_back();
//                storage.push_back(input);
//            }else if(storage.size() == 2){
//                storage.pop_back();
//                storage[storage.size()-1] = '0';
//                storage.push_back(input);
//            }else{
//                storage.pop_back();
//                storage.pop_back();
//                storage.push_back(input);
//            }
//        }
//     }else if(((storage[storage.size()-1] == "(") || storage[storage.size()-1] == ".") && isoperator(storage[storage.size()-2]) && input != "."){
//        storage.pop_back();
//        storage.pop_back();
//        storage.push_back(input);
//     }else if(isoperator(storage[storage.size()-1])){
//        storage.pop_back();
//        storage.push_back(input);
//     }else{
//        storage.push_back(input);
//     }
}

void Displaystring::addfunc(std::string input){
    if(storage[0] == "0" && storage.size() == 1){
        storage[0] = input;
        storage.push_back("(");
    }else if(storage[storage.size()-1] == "(" || isoperator(storage[storage.size()-1])){
        storage.push_back(input);
        storage.push_back("(");
    }else{
        storage.push_back("*");
        storage.push_back(input);
        storage.push_back("(");
    }
}


void Displaystring::addbracket(std::string input){
    if(storage[0] == "ERROR"){
        storage = {"0"};
    }
    if(input == "("){
        if(storage[0] == "0" && storage.size() == 1){
            storage[0] = input;
        }else if(storage[storage.size()-1] == "(" || isoperator(storage[storage.size()-1])){
            storage.push_back(input);
        }else{
            storage.push_back("*");
            storage.push_back(input);
        }
    }else if(input == ")"){
        if(isoperator(storage[storage.size()-1])){
              storage.pop_back();
              storage.push_back(input);
        }else if(storage[storage.size()-1] == "("){
            storage.push_back("0");
            storage.push_back(input);
        }else{
            storage.push_back(input);
        }
    }
}

void Displaystring::addnum(std::string input){
    if(storage[0] == "ERROR"){
        storage = {"0"};
    }
    if(storage.size() == 1 && storage[storage.size()-1] == "0"){
        storage.pop_back();
        storage.push_back(input);
    }else if(storage[storage.size()-1] == ")"){
        storage.push_back("*");
        storage.push_back(input);
    }else{
        storage.push_back(input);
    }
}

// the input functions end here

void Displaystring::cleardisplay(){
//simply sets store to "0" so that display will also be "0" when display function is called
    storage = {"0"};
}

void Displaystring::clearelement(){
// clears a single charecter on display except for if the display is showing "ERROR"
// if only one charecter on display then sets display to "0"
    if(concatenate(storage) == "ERROR"){
        storage = {"0"};
    }else if(!storage.empty() && storage.size() != 1){
        if(isspecialfunc(storage[storage.size() - 2])){
            storage.pop_back();
            storage.pop_back();
        }else{
            storage.pop_back();
        }
    }else if(storage.size() == 1){
        storage = {"0"};
    }
}

void Displaystring::answer(){
// passes the expression stored in storage to be evaluated by evaluate function defined in functions.h    
    std::string temp;
    temp = evaluate(storage);
    storage = splitstring(temp);
}

void Displaystring::setdisplay(std::string todisp){
// used to set display to anything
    storage = {todisp};
}
