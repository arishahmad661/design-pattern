#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Observer{
    public:
        virtual void update() = 0;
        virtual ~Observer() = default;
};

class Display{
    public:
        virtual void display() = 0;
        virtual ~Display() = default;
};

class Subject{
    public:
        virtual void addObserver(Observer*) = 0;
        virtual void removeObserver(Observer*) = 0;
        virtual void notify() = 0;
        virtual ~Subject() = default;
        
};


class WeatherStation : public Subject{
    private:
        double temp, pressure, humidity;
        vector<Observer*> observers;
    public:
        WeatherStation(): temp(22.22), pressure(33.33), humidity(44.44){
            observers = {};
        }

        void addObserver(Observer* ob) override {
            observers.push_back(ob);
        }

        void removeObserver(Observer* ob) override {
            observers.erase(remove(observers.begin(), observers.end(), ob), observers.end());
        }

        void notify() override {
            for(auto* ob: observers){
                ob->update();
            }
        }

        void setMeasurement(double t, double p, double h){
            temp = t;
            pressure = p;
            humidity = h;
            notify();
        }

        double getTemp(){
            return temp; 
        }

        double getPressure(){
            return pressure;
        }

        double getHumidity(){
            return humidity;
        }
};

class StatsDisplay : public Observer, Display{
    private:
        WeatherStation* weatherStation;
        double temp, pressure, humidity;
    public:
        StatsDisplay(WeatherStation* weatherStation){
            this->weatherStation = weatherStation;
            weatherStation->addObserver(this);
        }

        void update() override {
            temp = weatherStation->getTemp();
            pressure = weatherStation->getPressure();
            humidity = weatherStation->getHumidity();
            display();
        }

        void display() override {
            cout << "Stats Display: " << endl;
            cout << "The temp is " << temp << ", the pressure is " << pressure << ", and the humidity is " << humidity << "." << endl;
            cout << endl;
        }
};

class TempDisplay : public Observer, Display{
    private:
        WeatherStation* weatherStation;
        double temp, pressure, humidity;
    public:
        TempDisplay(WeatherStation* weatherStation){
            this->weatherStation = weatherStation;
            weatherStation->addObserver(this);
        }

        void update() override {
            temp = weatherStation->getTemp();
            pressure = weatherStation->getPressure();
            humidity = weatherStation->getHumidity();
            display();
        }

        void display() override {
            cout << "Temp Display: " << endl;
            cout << "The temp is " << temp << endl;
            cout << endl;
        }
};


int main(){
    WeatherStation* weatherStation = new WeatherStation();
    StatsDisplay* statsDisplay = new StatsDisplay(weatherStation);
    TempDisplay* tempDisplay = new TempDisplay(weatherStation);

    statsDisplay->display();
    tempDisplay->display();

    weatherStation->setMeasurement(111,222,333);
    weatherStation->setMeasurement(444,555,666);
    weatherStation->setMeasurement(777,888,999);

    statsDisplay->display();
    tempDisplay->display();

    delete statsDisplay;
    delete weatherStation;
    
    return 0;
}