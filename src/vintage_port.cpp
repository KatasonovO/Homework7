#include "vintage_port.h"

VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
: Port(br, "vintage", b)
{
#ifdef DEBUG_INFO
    std::cout << "Create VintagePort object " << std::endl;
#endif
    year = y;
    int nn_length = 0;
    for (int i = 0; nn[i] != '\0'; i++)
    {
        nn_length++;
    }
    nickname = new char[nn_length];
    for (int i = 0; i < nn_length; i++)
    {
        nickname[i] = nn[i];
    }
};

VintagePort::VintagePort(const VintagePort& vp):Port(vp)
{
#ifdef DEBUG_INFO
    std::cout << "Create VintagePort object (copy constructor)" << std::endl;
#endif
    year = vp.year;
    int nn_length = 0;
    for (int i = 0; vp.nickname[i] != '\0'; i++)
    {
        nn_length++;
    }
    nickname = new char[nn_length];
    for (int i = 0; i < nn_length; i++)
    {
        nickname[i] = vp.nickname[i];
    }
};

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if(this == &vp)
    {
        return *this;
    }
    Port::operator=(vp);
    if (nickname) delete[] nickname;
    year = vp.year;
    int nn_length = 0;
    for (int i = 0; vp.nickname[i] != '\0'; i++)
    {
        nn_length++;
    }
    nickname = new char[nn_length];
    for (int i = 0; i < nn_length; i++)
    {
        nickname[i] = vp.nickname[i];
    }
    return *this;
};

void VintagePort::Show(std::string header) const
{
    Port::Show(header);
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Year: " << year << std::endl;
};

std::ostream& VintagePort::print(std::ostream& os) const
{
    os << (Port)*this << ", " << nickname << ", " << year;
    return os;
}

std::ostream& operator << (std::ostream& os, const VintagePort& vp)
{
    return vp.print(os);
}


