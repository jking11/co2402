#include <iostream>
#include <typeinfo>

using namespace std;


class Cow {
public:
    virtual void moo() 
    {
        cout << "Moo!!" << endl;
    }
};


class AttackCow : public Cow {      // A Cow with built-in gun
private:
    int bullets = 10;
public:
    void moo() override
    {
        cout << "Raaaaar!!" << endl;
    }
    virtual void shoot()
    {
        cout << "Bang!" << endl;
        bullets--;
    }
};


int main() {

    Cow annie;
    annie.moo();

    AttackCow bertie;
    bertie.moo();
    bertie.shoot();

    Cow cowOfTheMonth;
    cowOfTheMonth = bertie;
    cowOfTheMonth.moo();    // Allowed, because cowOfTheMonth is a Cow
    //cowOfTheMonth.shoot();  // Not allowed, because we can't access the extra features

    //AttackCow secretCow;    // Cannot do polymorphism in reverse
    //secretCow = annie;
    //secretCow.moo();
    //secretCow.shoot();

}