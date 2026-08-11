#include<iostream>
using namespace std;

class Duck{
    public:
        virtual void quack() = 0;
        virtual void fly() = 0;
};

class Turkey{
    public:
        virtual void gobble() = 0;
        virtual void fly() = 0;
};

class MallardDuck : public Duck{
    public:
        void fly() override {
            cout << "Mallard  Duck Flies" << endl;
        }

        void quack() override {
            cout << "Mallard Duck Quacks" << endl;
        }
};

class WildTurkey : public Turkey{
    public:
        void fly() override {
            cout << "Wild Turkey Flies" << endl;
        }

        void gobble() override {
            cout << "Wild Turkey Gobbles" << endl;
        }
};

class TurkeyAdapter : public Duck{
    private:
        Turkey* turkey;
    public:
        TurkeyAdapter(Turkey* turkey){
            this->turkey = turkey;
        }

        void fly() override {
            turkey->fly();
        }

        void quack() override{
            turkey->gobble();
        }

};

int main(){
    Turkey* wildTurkey = new WildTurkey();
    Duck* turkeyAdapter = new TurkeyAdapter(wildTurkey);

    turkeyAdapter->fly();
    turkeyAdapter->quack();

    return 0;
}