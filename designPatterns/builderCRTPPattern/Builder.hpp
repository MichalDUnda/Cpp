#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "Vehicle.h"

/*
class VehicleBuilder
{
public:
    explicit VehicleBuilder(std::shared_ptr<Vehicle>& vehicle)
        : vehicle(std::move(vehicle))
        , vehicleRef(*vehicle.get())
    {
    }

    explicit VehicleBuilder(Vehicle& vehicle)
        : vehicleRef(vehicle)
    {
    }

    VehicleBuilder& setColor(const std::string& color)
    {
        if(vehicle)
        {
            vehicle->m_color = color;
        }
        else
        {
            vehicleRef.m_color = color;
        }
        return *this;
    }

    VehicleBuilder& setPrice(const std::string& price)
    {
        if(vehicle)
        {
            vehicle->m_price = price;
        }
        else
        {
            vehicleRef.m_price = price;
        }
        return *this;
    }



private:
    std::shared_ptr<Vehicle> vehicle;
    Vehicle& vehicleRef;
};

class CarBuilder : VehicleBuilder
{
    using self = CarBuilder;

public:
    explicit CarBuilder(std::shared_ptr<Car>& car)
        : VehicleBuilder(*car.get())
        , car(std::move(car))
    {
    }
    self& setBrand(const std::string& brand)
    {
        car->m_brand = brand;
        return *this;
    }

    self& withEnginePower(const std::string& power)
    {
        car->m_enginePower = power;
        return *this;
    }

    std::shared_ptr<Car> build()
    {
        return std::move(car);
    }

private:
    std::shared_ptr<Car> car;
};

class MainBuilder
{
public:
    static CarBuilder createCar()
    {
        auto car = std::make_shared<Car>();
        return CarBuilder(car);
    }
};*/

//crtp
template <typename T>
class CVehicleBuilder
{
private:
    T& _derived()
    {
        return *static_cast<T*>(this);
    }

public:
    T& withColor(const std::string& color)
    {
        _derived().getObj().setColor(color);
        return _derived();
    }

    T& withPrice(const std::string& price)
    {
        _derived().getObj().setPrice(price);
        return _derived();
    }
};

template <typename T>
class CCArBuilder
{
private:
    T& _derived()
    {
        return *static_cast<T*>(this);
    }

public:
    T& ofBrand(const std::string& brand)
    {
        _derived().getObj().setBrand(brand);
        return _derived();
    }

    T& withEnginePower(const std::string& power)
    {
        _derived().getObj().setPower(power);
        return _derived();
    }
};

class BuildCar : public CCArBuilder<BuildCar>,
                 public CVehicleBuilder<BuildCar>
{
public:
    Car build()
    {
        return std::move(obj);
    }
    Car& getObj()
    {
        return obj;
    }

private:
    Car obj;
};
