#include<iostream>
#include<mutex>

using namespace std;

class Singleton {
    private:
        Singleton (){}
        Singleton(const Singleton&) = delete;
        Singleton& operator = (const Singleton&) = delete;
    public:
        static Singleton& getInstance(){
            static Singleton obj;
            return obj;
        }

        void doSomething(){
            cout << "Do Something." << endl;
        }
};

int main(){
    Singleton::getInstance().doSomething();
    return 0;
}