#include "port.h"

Port::Port(const char* br, const char* st , int b):bottles(b)
{
#ifdef DEBUG_INFO
    std::cout << "Create Port object" << std::endl;
#endif
    int brand_length = 0;
    int i = 0;
    for ( ;i < style_length && st[i] != '\0'; i++)
    {
        style[i] = st[i];
    }
    for (; i < style_length ; i++)
    {
        style[i] = '\0';
    }

    for (int i = 0; br[i] != '\0'; i++)
    {
        brand_length++;
    }
    brand = new char[brand_length];
    for (int i = 0; i < brand_length; i++)
    {
        brand[i] = br[i];
    }
}

Port::Port(const Port& p)
{
#ifdef DEBUG_INFO
    std::cout << "Create Port object (copy constructor)" << std::endl;
#endif
    bottles = p.bottles;
    int brand_length = 0;
    for (int i = 0; i < p.style_length; i++)
    {
        style[i] = p.style[i];
    }
    for (int i = 0; p.brand[i] != '\0'; i++)
    {
        brand_length++;
    }
    brand = new char[brand_length];
    for (int i = 0; i < brand_length; i++)
    {
        brand[i] = p.brand[i];
    }
}

Port& Port::operator = (const Port& p)
{
    if (this == &p)
        return *this;

    if (brand) delete[] brand;

    bottles = p.bottles;
    int brand_length = 0;
    for (int i = 0; i < p.style_length; i++)
    {
        style[i] = p.style[i];
    }
    for (int i = 0; p.brand[i] != '\0'; i++)
    {
        brand_length++;
    }
    brand = new char[brand_length];
    for (int i = 0; i < brand_length; i++)
    {
        brand[i] = p.brand[i];
    }
    return *this;
}

Port::~Port()
{
#ifdef DEBUG_INFO
    std::cout << "Delete Port object" << std::endl;
#endif
    delete [] brand;
}

Port& Port::operator +=(int b)
{
    bottles +=b;
    return *this;
}

Port& Port::operator -=(int b)
{
    bottles -=b;
    return *this;
};

void Port::Show(std::string header) const
{
    std::cout << "-------- " << header << " --------" << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Kind: " << style << std::endl;
    std::cout << "Bottles: " << bottles << std::endl;
};

std::ostream& Port::print(std::ostream& os) const
{
    os << brand << ", " << style << ", " << bottles;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Port& p)
{
    return p.print(os);
}
