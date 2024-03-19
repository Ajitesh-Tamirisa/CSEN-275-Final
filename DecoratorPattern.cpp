#include <iostream>

class Car {
public:
  virtual double getRentalCost() const = 0;
};

class Decorator : public Car {
public:
  Decorator(Car* decoratedCar) : decoratedCar(decoratedCar) {}

  virtual double getRentalCost() const override {
    return decoratedCar->getRentalCost();
  }

private:
  Car* decoratedCar;
};

class GPSDecorator : public Decorator {
public:
  GPSDecorator(Car* decoratedCar, double gpsCost) : Decorator(decoratedCar), gpsCost_(gpsCost) {}

  double getRentalCost() const override {
    return Decorator::getRentalCost() + gpsCost_;
  }

private:
  double gpsCost_;
};

class ChildSeatDecorator : public Decorator {
public:
  ChildSeatDecorator(Car* decoratedCar, double childSeatCost) : Decorator(decoratedCar), childSeatCost_(childSeatCost) {}

  double getRentalCost() const override {
    return Decorator::getRentalCost() + childSeatCost_;
  }

private:
  double childSeatCost_;
};

class EconomyCar : public Car {
public:
  double getRentalCost() const override {
    return 30.0; // Base rental cost for economy car
  }
};

// Example usage
int main() {
  Car* baseCar = new EconomyCar();

  Car* carWithGPS = new GPSDecorator(baseCar, 20.0);

  Car* carWithGPSAndSeat = new ChildSeatDecorator(carWithGPS, 10.0);

  std::cout << "Economy car rental cost: $" << baseCar->getRentalCost() << std::endl;
  std::cout << "Car with GPS rental cost: $" << carWithGPS->getRentalCost() << std::endl;
  std::cout << "Car with GPS and Child Seat rental cost: $" << carWithGPSAndSeat->getRentalCost() << std::endl;

  return 0;
}
