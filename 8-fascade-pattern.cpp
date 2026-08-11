#include<iostream>
using namespace std;

class Speaker{
    private:
        int volume = 5;
    public:
        void on(){
            cout << "Switching on Speaker" << endl;
        }

        void off(){
            cout << "Switching off Speaker" << endl;
        }

        void setVolume(int n){
            volume = n;
        }
};

class Projector{
    private:
        string size = "4x4";
    public:
        void on(){
            cout << "Switching on Projector" << endl;
        }

        void off(){
            cout << "Switching off Projector" << endl;
        }

        void setScreenSize(string size){
            this->size  =size;
        }
};

class HomeTheater{
    Speaker* speaker;
    Projector* projector;
    public:
        HomeTheater(Speaker* speaker, Projector* projector){
            this->speaker = speaker;
            this->projector = projector;
        }

        void start(string movieName){
            cout << "Playing " + movieName + " ..." << endl;
            speaker->on();
            speaker->setVolume(5);
            projector->on();
            projector->setScreenSize("10x10");
        }

        void turnOff(){
            cout << "Turning off ..."<< endl;
            speaker->off();
            projector->off();
        }
};

int main(){
    Speaker* speaker  = new Speaker();
    Projector* projector = new Projector();
    HomeTheater* homeTheater = new HomeTheater(speaker, projector);
    homeTheater->start("Avengers");
    homeTheater->turnOff();

    return 0;
}