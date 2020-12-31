#include "history.h"
#include <vector>
#include <string>

// mainhistorydata and secdoryhistorydata are private vectors of class
//to store history of maindisplay and secdisplay respectively
//the functions are straightforward

History::History()
{}

void History::addata(std::string main, std::string sec){
    mainhistorydata.insert(mainhistorydata.begin(), main);
    secondaryhistorydata.insert(secondaryhistorydata.begin(), sec);
}

int History::size(){
    return mainhistorydata.size();
}

std::string History::showmainhistory(int index){
    return mainhistorydata[index];
}

std::string History::showsecondaryhistory(int index){
    return secondaryhistorydata[index];
}

void History::clearhist(){
    mainhistorydata.clear();
    secondaryhistorydata.clear();
}

void History::removelastdata(){
    if(size() > 4){
        mainhistorydata.pop_back();
        secondaryhistorydata.pop_back();
    }
}
