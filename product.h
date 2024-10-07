#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

enum ProductState {
    NORMAL,
    OVERHEATED,
    FROZEN
};

class Product {
public:
    // ����������� �� ���������
    Product() : name_(""), mass_(0), temperature_(0), maxTemperature_(0), minTemperature_(0), state_(NORMAL), heatCapacity_(0) {}

    // ����������� � �����������
    Product(const std::string& name, double mass, double temperature, double maxTemperature, double minTemperature, double heatCapacity);

    // ������ �������
    std::string getName() const;
    double getMass() const;
    double getTemperature() const;
    double getMaxTemperature() const;
    double getMinTemperature() const;
    ProductState getState() const;
    double getHeatCapacity() const;

    // ����� ��� �������� �������� �������
    void transferHeatEnergy(double energy);

private:
    std::string name_;
    double mass_;
    double temperature_; // �������� �� double
    double maxTemperature_;
    double minTemperature_;
    ProductState state_;
    double heatCapacity_;

    // ��������� ����� ��� ���������� ���������
    void updateState();
};

#endif
