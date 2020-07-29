#pragma once
#include <iostream>

class Port {
private:
    char* brand;
    static const int style_length = 20;
    char style[style_length]; // e.g. tawny, ruby, vintage
    int bottles;

public:
    Port(const char* br = "none", const char* st = "none", int b = 0);
    Port(const Port& p);
    virtual ~Port();// { delete [] brand; }

    virtual std::ostream& print(std::ostream& os) const;

    Port& operator= (const Port & p);
    Port& operator+= (int b) ; // adds b to bottles
    Port& operator-= (int b); // subtracts b from bottles, if possible

    inline int BottleCount() const { return bottles; }
    virtual void Show(std::string header = "") const;

    friend std::ostream& operator<< (std::ostream& os, const Port& p);
};
