#pragma once
#include <string>
#include <iostream>

//class VehicleBuilder;

class Vehicle
{
    //friend class VehicleBuilder;
    //friend class BuildCar<CVehicleBuilder>;

public:
    virtual ~Vehicle()
    {
        std::cout << "Vehicle destroyed\n";
    }

    //static Builder create();

    friend std::ostream&
    operator<<(std::ostream& os, const Vehicle& obj)
    {
        return os
               << "color is: " << obj.m_color
               << " with the price: " << obj.m_price;
    }

    Vehicle()
    {
        std::cout << "Vehicle created\n";
    }
    void setColor(const std::string& color)
    {
        m_color = color;
    }
    void setPrice(const std::string& price)
    {
        m_price = price;
    }

private:
    std::string m_color;
    std::string m_price;
};

//class CarBuilder;
class BuildCar;

class Car : public Vehicle
{
    //friend class CarBuilder;
    friend class BuildCar;

public:
    ~Car() override
    {
        std::cout << "Car destroyed\n";
    }

    //static Builder create();

    friend std::ostream& operator<<(std::ostream& os, const Car& obj)
    {
        return os << "brand is: " << obj.m_brand
                  << " with engine power: " << obj.m_enginePower
                  << static_cast<Vehicle>(obj);
    }

    Car()
    {
        std::cout << "Car created\n";
    }

    void setBrand(const std::string& brand)
    {
        m_brand = brand;
    }
    void setPower(const std::string& power)
    {
        m_enginePower = power;
    }

private:
    std::string m_brand;
    std::string m_enginePower;
    int m_doorNumber;
};
