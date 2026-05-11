/******************************************************************************
    ABSTRACT FACTORY DESIGN PATTERN
    --------------------------------

    Problem:
    --------
    We want to create families of related objects without exposing
    the concrete classes to the client.

    Example:
    --------
    Furniture families:
        1. Victorian Furniture
        2. Modern Furniture

    Each family contains:
        - Chair
        - Table

    Benefits:
    ---------
    1. Client code depends only on interfaces.
    2. Easy to add new furniture families.
    3. Promotes loose coupling.
    4. Centralized object creation.

*******************************************************************************/

#include <iostream>
#include <memory>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//                              CHAIR INTERFACE
///////////////////////////////////////////////////////////////////////////////

/*
    Abstract Product: Chair

    All chair types must implement:
        - material information
        - provider information

    IMPORTANT:
    -----------
    Always provide a virtual destructor in polymorphic base classes.
*/
class Chair
{
public:
    virtual ~Chair() = default;

    virtual void material() const = 0;
    virtual void provider() const = 0;
};

///////////////////////////////////////////////////////////////////////////////
//                        VICTORIAN CHAIR IMPLEMENTATION
///////////////////////////////////////////////////////////////////////////////

class VictorianChair : public Chair
{
public:
    VictorianChair()
    {
        cout << "Creating Victorian Chair\n";
    }

    ~VictorianChair() override = default;

    void material() const override
    {
        cout << "Material: Premium Wood\n";
    }

    void provider() const override
    {
        cout << "Provider: Victorian Furniture Factory\n";
    }
};

///////////////////////////////////////////////////////////////////////////////
//                          MODERN CHAIR IMPLEMENTATION
///////////////////////////////////////////////////////////////////////////////

class ModernChair : public Chair
{
public:
    ModernChair()
    {
        cout << "Creating Modern Chair\n";
    }

    ~ModernChair() override = default;

    void material() const override
    {
        cout << "Material: Steel and Glass\n";
    }

    void provider() const override
    {
        cout << "Provider: Modern Furniture Factory\n";
    }
};

///////////////////////////////////////////////////////////////////////////////
//                              TABLE INTERFACE
///////////////////////////////////////////////////////////////////////////////

/*
    Abstract Product: Table
*/
class Table
{
public:
    virtual ~Table() = default;

    virtual void material() const = 0;
    virtual void provider() const = 0;
};

///////////////////////////////////////////////////////////////////////////////
//                        VICTORIAN TABLE IMPLEMENTATION
///////////////////////////////////////////////////////////////////////////////

class VictorianTable : public Table
{
public:
    VictorianTable()
    {
        cout << "Creating Victorian Table\n";
    }

    ~VictorianTable() override = default;

    void material() const override
    {
        cout << "Material: Solid Oak Wood\n";
    }

    void provider() const override
    {
        cout << "Provider: Victorian Furniture Factory\n";
    }
};

///////////////////////////////////////////////////////////////////////////////
//                          MODERN TABLE IMPLEMENTATION
///////////////////////////////////////////////////////////////////////////////

class ModernTable : public Table
{
public:
    ModernTable()
    {
        cout << "Creating Modern Table\n";
    }

    ~ModernTable() override = default;

    void material() const override
    {
        cout << "Material: Tempered Glass\n";
    }

    void provider() const override
    {
        cout << "Provider: Modern Furniture Factory\n";
    }
};

///////////////////////////////////////////////////////////////////////////////
//                         ABSTRACT FACTORY INTERFACE
///////////////////////////////////////////////////////////////////////////////

/*
    Abstract Factory

    Responsible for creating families of products.
*/
class FurnitureFactory
{
public:
    virtual ~FurnitureFactory() = default;

    virtual unique_ptr<Chair> createChair() const = 0;
    virtual unique_ptr<Table> createTable() const = 0;
};

///////////////////////////////////////////////////////////////////////////////
//                      VICTORIAN FACTORY IMPLEMENTATION
///////////////////////////////////////////////////////////////////////////////

class VictorianFactory : public FurnitureFactory
{
public:
    VictorianFactory()
    {
        cout << "\nVictorian Factory Initialized\n";
    }

    ~VictorianFactory() override = default;

    unique_ptr<Chair> createChair() const override
    {
        return make_unique<VictorianChair>();
    }

    unique_ptr<Table> createTable() const override
    {
        return make_unique<VictorianTable>();
    }
};

///////////////////////////////////////////////////////////////////////////////
//                        MODERN FACTORY IMPLEMENTATION
///////////////////////////////////////////////////////////////////////////////

class ModernFactory : public FurnitureFactory
{
public:
    ModernFactory()
    {
        cout << "\nModern Factory Initialized\n";
    }

    ~ModernFactory() override = default;

    unique_ptr<Chair> createChair() const override
    {
        return make_unique<ModernChair>();
    }

    unique_ptr<Table> createTable() const override
    {
        return make_unique<ModernTable>();
    }
};

///////////////////////////////////////////////////////////////////////////////
//                          CLIENT CODE
///////////////////////////////////////////////////////////////////////////////

/*
    Client only depends on abstractions:
        - FurnitureFactory
        - Chair
        - Table

    Client does NOT know:
        - VictorianChair
        - ModernChair
        - VictorianTable
        - ModernTable
*/
void createFurniture(const FurnitureFactory& factory)
{
    // Create family objects
    auto chair = factory.createChair();
    auto table = factory.createTable();

    cout << "\n--- Chair Details ---\n";
    chair->material();
    chair->provider();

    cout << "\n--- Table Details ---\n";
    table->material();
    table->provider();

    cout << "\n=============================\n";
}

///////////////////////////////////////////////////////////////////////////////
//                                  MAIN
///////////////////////////////////////////////////////////////////////////////

int main()
{
    // Create Victorian furniture family
    VictorianFactory victorianFactory;
    createFurniture(victorianFactory);

    // Create Modern furniture family
    ModernFactory modernFactory;
    createFurniture(modernFactory);

    return 0;
}