#include <iostream>
using namespace std;

// ======================================================
// Product Interface
// ------------------------------------------------------
// This is the common interface for all transport types.
// Every transport class must implement deliver().
// ======================================================
class Transport
{
public:
    virtual void deliver() = 0;

    // Virtual destructor ensures proper cleanup
    // when deleting derived objects using base pointer.
    virtual ~Transport() = default;
};

// ======================================================
// Concrete Product : Truck
// ------------------------------------------------------
// Represents road transport.
// ======================================================
class Truck : public Transport
{
public:
    // Override deliver() for Truck-specific behavior
    void deliver() override
    {
        cout << "Delivering via Truck\n";
    }
};

// ======================================================
// Concrete Product : Sea
// ------------------------------------------------------
// Represents sea transport.
// ======================================================
class Sea : public Transport
{
public:
    // Override deliver() for Sea-specific behavior
    void deliver() override
    {
        cout << "Delivering via Sea\n";
    }
};

// ======================================================
// Creator Class
// ------------------------------------------------------
// Declares the Factory Method createTransport().
//
// Child classes will decide which concrete object
// should be created.
//
// Also contains business logic:
// deliverMyProduct()
// ======================================================
class Logistic
{
public:

    // Factory Method
    // Pure virtual function forcing subclasses
    // to create specific transport objects.
    virtual Transport* createTransport() = 0;

    virtual ~Logistic() = default;

    // Common business logic
    void deliverMyProduct()
    {
        // Create transport object using factory method
        Transport* obj = createTransport();

        // Use transport object
        obj->deliver();

        // Free memory to avoid memory leak
        delete obj;
    }
};

// ======================================================
// Concrete Creator : TruckLogistic
// ------------------------------------------------------
// Creates Truck objects.
// ======================================================
class TruckLogistic : public Logistic
{
public:

    // Factory Method implementation
    Transport* createTransport() override
    {
        return new Truck();
    }
};

// ======================================================
// Concrete Creator : SeaLogistic
// ------------------------------------------------------
// Creates Sea objects.
// ======================================================
class SeaLogistic : public Logistic
{
public:

    // Factory Method implementation
    Transport* createTransport() override
    {
        return new Sea();
    }
};

// ======================================================
// Main Function
// ======================================================
int main()
{
    // Base class pointer
    Logistic* obj;

    // Create Sea logistics object
    obj = new SeaLogistic();

    // Calls business logic
    // Internally creates Sea transport
    obj->deliverMyProduct();

    // Cleanup
    delete obj;

    return 0;
}