#pragma once
#include "port.h"

class VintagePort : public Port { // style always == "vintage"
private:
    char* nickname; // like "The Noble", "Old Velvet", etc.
    int year; // year of bottling
public:
    //VintagePort();
    VintagePort(const char* br = "none", int b = 0, const char* nn = "none", int y = 0);
    VintagePort(const VintagePort& vp);
    ~VintagePort() {
    #ifdef DEBUG_INFO
        std::cout << "Delete VintagePort object" << std::endl;
    #endif
        delete [] nickname;
    }

    virtual std::ostream& print(std::ostream& os) const;

    VintagePort & operator=(const VintagePort & vp);
    virtual void Show(std::string header = "") const;
    friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};


