#include<iostream>
using namespace std;

class CaffinatedDrink {
    public:
        void boildWater(){
            cout << "Water is boiling..." << endl;
        }

        virtual void addCaffinatedSubstance() = 0;

        virtual void addCondiments() = 0;

        void serve(){
            cout << "Drink is beign served..." << endl;
        }

        void prepare(){
            boildWater();
            addCaffinatedSubstance();
            addCondiments();
            serve();
        }
};

class Coffee : public CaffinatedDrink{
    public:
        void addCaffinatedSubstance() override {
            cout << "Adding coffee..." << endl;
        }

        void addCondiments() override {
            cout << "Adding milk and sugar..." << endl;
        }
};

class Tea : public CaffinatedDrink{
    public:
        void addCaffinatedSubstance() override {
            cout << "Adding Tea..." << endl;
        }

        void addCondiments() override {
            cout << "Adding lemons and sugar..." << endl;
        }
};

int main(){
    CaffinatedDrink* tea = new Tea();
    tea->prepare();

    CaffinatedDrink* coffee = new Coffee();
    coffee->prepare();

    return 0;
}