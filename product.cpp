#include "product.h"
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

Product::Product(const std::string& name, double mass, double temperature, double maxTemperature, double minTemperature, double heatCapacity) :
    name_(name),
    mass_(mass),
    temperature_(temperature),
    maxTemperature_(maxTemperature),
    minTemperature_(minTemperature),
    state_(NORMAL),
    heatCapacity_(heatCapacity)
{
    updateState();
}

std::string Product::getName() const {
    return name_;
}

double Product::getMass() const {
    return mass_;
}

double Product::getTemperature() const {
    return temperature_;
}

double Product::getMaxTemperature() const {
    return maxTemperature_;
}

double Product::getMinTemperature() const {
    return minTemperature_;
}

ProductState Product::getState() const {
    return state_;
}

double Product::getHeatCapacity() const {
    return heatCapacity_;
}

void Product::transferHeatEnergy(double energy) { // Изменено на double
    temperature_ += energy / (mass_ * heatCapacity_);
    updateState();
}

void Product::updateState() {
    if (temperature_ > maxTemperature_) {
        state_ = OVERHEATED;
    }
    else if (temperature_ < minTemperature_) {
        state_ = FROZEN;
    }
    else {
        state_ = NORMAL;
    }
}