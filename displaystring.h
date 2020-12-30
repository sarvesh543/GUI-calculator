#ifndef DISPLAYSTRING_H
#define DISPLAYSTRING_H
#include <string>

class Displaystring
{
    std::string store = "0";

    public:
        Displaystring();
        std::string display();
        void addtodisplay(std::string input);
        void cleardisplay();
        void clearelement();
        void answer();
        void setdisplay(std::string todisp);

};

#endif // DISPLAYSTRING_H
