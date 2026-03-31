class Vehicle {
public:
    virtual string getType() = 0;
};

class Car : public Vehicle {
public:
    string getType() override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    string getType() override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    string getType() override {
        return "Truck";
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
};

class CarFactory : public VehicleFactory {
    virtual Vehicle* createVehicle() {
        return new Car();
    }
};

class BikeFactory : public VehicleFactory {
    virtual Vehicle* createVehicle() {
        return new Bike();    
    }
};

class TruckFactory : public VehicleFactory {
    virtual Vehicle* createVehicle() {
        return new Truck();    
    }
};
