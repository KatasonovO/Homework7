#include <iostream>
#include "vintage_port.h"

int main()
{
    int SIZE_P = 5;
    Port* vine[SIZE_P];

    std::cout << " ----  Homework 7 ----" << std::endl;
    for (int i = 0; i < SIZE_P; i ++)
    {
        if (i == (SIZE_P -1)) {vine[i] = new VintagePort("VintagePortBrand", i*SIZE_P, "VPName", 1000 + i);}
        else vine[i] = new Port("PortBrand", "ruby", i);
    }

    std::cout << " ----  Show records using Show() ----" << std::endl;
    for (int i = 0; i < SIZE_P; i ++)
    {
        vine[i]->Show(" Record " + std::to_string(i));
    }

    std::cout << " ----  Show records using << ----" << std::endl;
    for (int i = 0; i < SIZE_P; i ++)
    {
        std::cout << *(vine[i]) << std::endl;
    }

    return 0;
}
