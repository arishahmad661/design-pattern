#include<iostream>
using namespace std;

class ITv {
    public:
        virtual void on() = 0;
        virtual void off() = 0;
        virtual void setChannel(int number) = 0;
        virtual ~ITv() {}
};

class Tv : public ITv{
    public:
        void on() override {
            cout << "Switching on tv..." << endl;
        }

        void off() override {
            cout << "Switching off tv..." << endl;
        }

        void setChannel(int number) override {
            cout << "Setting channel to " << number << "..." << endl;
        }

};

class AbstractRemote {
    protected:
        ITv* tv;
    public:
        AbstractRemote(ITv* tv){
            this->tv = tv;
        }
        void on(){
            tv->on();
        };
        void off(){
            tv->off();
        };
        virtual void setChannel(int number) = 0;
        virtual ~AbstractRemote() {}
};

class Remote : public AbstractRemote {
    public:
        Remote(ITv* tv) : AbstractRemote(tv) {}
        void setChannel(int number) override {
            tv->setChannel(number);
        }
};

int main(){
    ITv* tv = new Tv();
    AbstractRemote* remote = new Remote(tv);

    tv->on();
    tv->setChannel(2);
    tv->off();

    return 0;
}
