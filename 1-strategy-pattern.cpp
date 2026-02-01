#include<iostream>
using namespace std;

class FlyBehaviour{
    public:
        virtual void fly() = 0;
        virtual ~FlyBehaviour() = default;
};

class NoFlyBehaviour : public FlyBehaviour{
    public:
        void fly() override {
            cout << "The duck does not fly." << endl;
        }
};

class QuackBehaviour{
    public:
        virtual void quack() = 0;
        virtual ~QuackBehaviour() = default;
};

class SqueakQuakBegaviour : public QuackBehaviour{
    public:
        void quack() override {
            cout << "The duck squeak." << endl;
        }
};


class Duck{
    protected:
        FlyBehaviour* fb;
        QuackBehaviour* qb;
    public:
        Duck(): fb(nullptr), qb(nullptr) {}
        void setFlybehaviour(FlyBehaviour* fbb){
            fb = fbb;
        }
        
        void setQuackbehaviour(QuackBehaviour* qbb){
            qb = qbb;
        }

        virtual void display() = 0;

        void displayFlyBehaviour(){
            if(fb) fb -> fly();
        }

        void displayQuackBehaviour(){
            if(qb) qb -> quack();
        }

        virtual ~Duck() = default;
};

class MallardDuck : public Duck{
    public:
        MallardDuck() {
            fb = new NoFlyBehaviour();
            qb = new SqueakQuakBegaviour();
        }

        void display() override {
            cout << "Show casing mallard duck." << endl;
        }

        ~MallardDuck(){
            delete fb;
            delete qb;
        }
};

int main(){
    Duck* duck = new MallardDuck();
    duck -> display();
    duck -> displayFlyBehaviour();
    duck -> displayQuackBehaviour();

    delete duck;
    return 0;
}