#include <iostream>
#include <string>

using Cable = int;

/* Adaptee (source) interface */
class EuropeanSocketInterface
{
public:
    virtual int voltage() = 0;

    virtual Cable live() = 0;
    virtual Cable neutral() = 0;
    virtual Cable earth() = 0;
};

/* Adaptee */
class Socket : public EuropeanSocketInterface
{
public:
    int voltage()
    {
        return 230;
    }

    Cable live()
    {
        return 1;
    }
    Cable neutral()
    {
        return -1;
    }
    Cable earth()
    {
        return 0;
    }
};

/* Target interface */
class USASocketInterface
{
public:
    virtual int voltage() = 0;

    virtual Cable live() = 0;
    virtual Cable neutral() = 0;
};

// we need to have a adapter to for USA socket

class Adapter : public USASocketInterface
{
    EuropeanSocketInterface* socket;

public:
    void plugIn(EuropeanSocketInterface* outlet)
    {
        socket = outlet;
    }

    int voltage()
    {
        return 110;
    }
    Cable live()
    {
        return socket->live();
    }
    Cable neutral()
    {
        return socket->neutral();
    }
};

/* Client */
class ElectricKettle
{
    USASocketInterface* power;

public:
    void plugIn(USASocketInterface* supply)
    {
        power = supply;
    }

    void boil()
    {
        if(power->voltage() > 110)
        {
            std::cout << "Kettle is on fire!" << std::endl;
            return;
        }

        if(power->live() == 1 && power->neutral() == -1)
        {
            std::cout << "Coffee time!" << std::endl;
        }
    }
};

int main()
{
    Socket* EUSocket = new Socket;
    Adapter* adapterToEuSocket = new Adapter;
    ElectricKettle* USkettle = new ElectricKettle;

    /* Pluging in. */
    adapterToEuSocket->plugIn(EUSocket);
    USkettle->plugIn(adapterToEuSocket);

    /* Having coffee */
    USkettle->boil();

    return 0;
}