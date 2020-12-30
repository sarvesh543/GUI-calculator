#include "displaystring.h"
#include <vector>
#include <string>
#include "functions.h"


// store is a private member of the class
Displaystring::Displaystring()
{}

std::string Displaystring::display(){
// returns the string to be displayed
    return store;
}

void Displaystring::addtodisplay(std::string input){
// this giant if else block is to make sure that the expression entered by user is mathematically valid
// it takes string input and appends it to the private string store

    if(store == "ERROR"){
        store = "0";
    }
    if((store[0] == '0' && store.length() == 1)){
        if(isnumber(input) || input == "("){
            store = input;
        }else if((isoperator(input) || input == ".") && input != "("){
            store.append(input);
        }
    }else{
        if((isoperator(ctos(store[store.length()-1])) || ctos(store[store.length()-1]) == ".") && !isnumber(input) && input != "("){
            if(store[store.length()-1] == '-' && store[store.length()-2] == '('){
                if(isoperator(ctos(store[store.length()-3]))){
                    store.erase(store.length()-1);
                    store.erase(store.length()-1);
                    store.erase(store.length()-1);
                    store.append(input);
                }else if(store.length() == 2){
                    store.erase(store.length()-1);
                    store[store.length()-1] = '0';
                    store.append(input);
                }else{
                    store.erase(store.length()-1);
                    store.erase(store.length()-1);
                    store.append(input);
                }
            }else if(store[store.length()-1] == '(' && input == "-"){
                store.append(input);
            }else if(store[store.length()-1] == '(' && input == ")"){
                store.append("0)");
            }else if((store[store.length()-1] == '(' || store[store.length()-1] == '.') && isoperator(ctos(store[store.length()-2])) && input != "."){
                store.erase(store.length()-1);
                store.erase(store.length()-1);
                store.append(input);
            }else if(store[store.length()-1] == ')'){
                store.append(input);
            }else{
                store.erase(store.length() - 1);
                store.append(input);
            }
        }else{
            if(input == "(" && (store[store.length()-1] == ')' || isnumber(ctos(store[store.length()-1])))){
                store.append("*(");
            }else if(input == "(" && store[store.length()-1] == '.'){
                store[store.length()-1] = '*';
                store.append(input);
            }else if(isnumber(input) && store[store.length()-1] == ')'){
                store.append("*");
                store.append(input);
            }else{
                store.append(input);
            }
        }
    }
}

void Displaystring::cleardisplay(){
//simply sets store to "0" so that display will also be "0" when display function is called
    store = "0";
}

void Displaystring::clearelement(){
// clears a single charecter on display except for if the display is showing "ERROR"
// if only one charecter on display then sets display to "0"
    if(store == "ERROR"){
        store = "0";
    }else if(!store.empty() && store.length() != 1){
        store.erase(store.length() - 1);
    }else if(store.length() == 1){
        store = "0";
    }
}

void Displaystring::answer(){
// passes the expression stored in store to be evaluated by evaluate function defined in functions.h
    std::string temp;
    temp = evaluate(store);
    store = temp;
}

void Displaystring::setdisplay(std::string todisp){
// used to set display to anything
    store = todisp;
}
