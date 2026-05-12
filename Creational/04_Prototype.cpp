#include <iostream>
#include <string>

using namespace std;

// ======================================================
// Prototype Interface
// ------------------------------------------------------
// Declares clone() method that all prototypes
// must implement.
// ======================================================
class Enemy
{
public:

    // Clone method
    virtual Enemy* clone() = 0;

    // Common behavior
    virtual void showDetails() = 0;

    virtual ~Enemy() = default;
};

// ======================================================
// Concrete Prototype
// ------------------------------------------------------
// Zombie class implementing cloning.
// ======================================================
class Zombie : public Enemy
{
private:
    string type;
    int health;

public:

    // Constructor
    Zombie(string t, int h)
    {
        type = t;
        health = h;
    }

    // Copy Constructor
    // Used internally during cloning
    Zombie(const Zombie& obj)
    {
        type = obj.type;
        health = obj.health;
    }

    // Clone current object
    Enemy* clone() override
    {
        // Create copy using copy constructor
        return new Zombie(*this);
    }

    // Display object details
    void showDetails() override
    {
        cout << "Zombie Type : " << type << endl;
        cout << "Health      : " << health << endl;
        cout << "--------------------------\n";
    }
};

// ======================================================
// Main Function
// ======================================================
int main()
{
    // Create original object
    Enemy* originalZombie =
        new Zombie("Fast Zombie", 100);

    // Clone original object
    Enemy* clonedZombie1 =
        originalZombie->clone();

    Enemy* clonedZombie2 =
        originalZombie->clone();

    // Display details
    cout << "Original Zombie\n";
    originalZombie->showDetails();

    cout << "Cloned Zombie 1\n";
    clonedZombie1->showDetails();

    cout << "Cloned Zombie 2\n";
    clonedZombie2->showDetails();

    // Cleanup memory
    delete originalZombie;
    delete clonedZombie1;
    delete clonedZombie2;

    return 0;
}