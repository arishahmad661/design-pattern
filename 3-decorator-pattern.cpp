#include<iostream>
#include<string>
using namespace std;

class Beverage{
    protected: 
        string description = "Unkown Beverage";
    public:
        virtual double cost() = 0;

        virtual string getDescription(){
            return description;
        };

        virtual ~Beverage() = default;
};

class CondimentDecorator : public Beverage{
    public:
        virtual string getDescription() = 0;
};

class HouseBlend : public Beverage{
    public:
        HouseBlend(){
            description = "House Blend";
        }
        double cost() override {
            return 0.89;
        }
};

class Espresso : public Beverage{
    public:
        Espresso(){
            description = "Espresso";
        }
        double cost() override {
            return 1.99;
        }
};

class Mocha : public CondimentDecorator{
    private:
        Beverage* beverage;

    public:
        Mocha(Beverage* b){
            this->beverage = b;
        };

        double cost() override {
            return beverage->cost() + 0.20;
        }

        string getDescription() override {
            return beverage->getDescription() + ", Mocha";
        }
};

int main(){
    Beverage* beverage = new Espresso();
    cout << beverage->cost() << endl;
    cout << beverage->getDescription() << endl;

    Beverage* beverage2 = new Mocha(beverage);
    cout << beverage2->cost() << endl;
    cout << beverage2->getDescription() << endl;

    return 0;
}