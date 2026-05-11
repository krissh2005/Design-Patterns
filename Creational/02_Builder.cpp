#include <iostream>
using namespace std;

/*
    Pizza class demonstrates Builder Design Pattern.

    Why Builder Pattern?
    --------------------
    When an object has:
    - Required parameters
    - Multiple optional parameters

    Builder pattern helps create readable and maintainable object creation.
*/

class Pizza
{
public:
    // Forward declaration of Builder class
    class PizzaBuilder;

private:

    // ================= REQUIRED FIELDS =================
    string name;
    int size;

    // ================= OPTIONAL FIELDS =================
    bool extraCheese = false;
    bool thinCrust = false;
    bool addons = false;

    /*
        Private constructor.
        Object can only be created using Builder.
    */
    Pizza(const PizzaBuilder& builder);

public:

    /*
        Nested Builder Class
    */
    class PizzaBuilder
    {
        // Pizza class can access private members
        friend class Pizza;

    private:

        // Required fields
        string name;
        int size;

        // Optional fields
        bool extraCheese = false;
        bool thinCrust = false;
        bool addons = false;

    public:

        /*
            Constructor for required fields
        */
        PizzaBuilder(string name, int size)
        {
            this->name = name;
            this->size = size;
        }

        /*
            Add extra cheese
            Returning reference allows method chaining
        */
        PizzaBuilder& addExtraCheese()
        {
            this->extraCheese = true;
            return *this;
        }

        /*
            Add thin crust
        */
        PizzaBuilder& addThinCrust()
        {
            this->thinCrust = true;
            return *this;
        }

        /*
            Add addons
        */
        PizzaBuilder& addAddOn()
        {
            this->addons = true;
            return *this;
        }

        /*
            Final build method
            Creates Pizza object
        */
        Pizza build()
        {
            return Pizza(*this);
        }
    };

    /*
        Display pizza details
    */
    void showPizza()
    {
        cout << "=========== Pizza Details ===========" << endl;

        cout << "Name          : " << name << endl;
        cout << "Size          : " << size << endl;
        cout << "Extra Cheese  : " << (extraCheese ? "Yes" : "No") << endl;
        cout << "Thin Crust    : " << (thinCrust ? "Yes" : "No") << endl;
        cout << "Addons        : " << (addons ? "Yes" : "No") << endl;

        cout << "=====================================" << endl;
    }
};

/*
    Pizza constructor implementation
    Copies data from Builder object
*/
Pizza::Pizza(const PizzaBuilder& builder)
{
    this->name = builder.name;
    this->size = builder.size;

    this->extraCheese = builder.extraCheese;
    this->thinCrust = builder.thinCrust;
    this->addons = builder.addons;
}

int main()
{
    /*
        Creating Pizza object using Builder Pattern
    */
    Pizza myPizza =
        Pizza::PizzaBuilder("Margherita", 11)
            .addExtraCheese()
            .addThinCrust()
            .addAddOn()
            .build();

    // Print pizza details
    myPizza.showPizza();

    return 0;
}