#ifndef DISPLAYSTRING_H
#define DISPLAYSTRING_H
#include <string>
#include <vector>

class Displaystring
{
    std::string store = "0";
    std::vector<std::string> storage = {"0"};

    public:
        Displaystring();
        std::string display();
        void addtodisplay(std::string input);
        void addbracket(std::string input);       
        void addopr(std::string input);
        void addfunc(std::string input);
        void addnum(std::string input);
        void adddecimal(std::string input);
        void cleardisplay();
        void clearelement();
        void answer();
        void setdisplay(std::string todisp);

};

#endif // DISPLAYSTRING_H
