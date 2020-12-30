#ifndef HISTORY_H
#define HISTORY_H
#include <vector>
#include <string>



class History
{
    std::vector<std::string> mainhistorydata;
    std::vector<std::string> secondaryhistorydata;

public:
    History();
    void addata(std::string main, std::string sec);
    void clearhist();
    int size();
    std::string showmainhistory(int index);
    std::string showsecondaryhistory(int index);
    void removelastdata();
};

#endif // HISTORY_H
