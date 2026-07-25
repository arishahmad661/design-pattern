#include<iostream>
#include<vector>
using namespace std;

class ICommand{
    public:
        ICommand(){}
        virtual void execute() = 0;
        virtual void undo() = 0;
        virtual ~ICommand() = default;
};
class IObject {
    public:
        virtual void on() = 0;
        virtual void off() = 0;
        virtual ~IObject() = default;
};
class Light : public IObject{
    public:
        Light(){}
        void on() override {
            cout << "Light is on..." << endl;
        }
        void off() override {
            cout << "Light is off..." << endl;
        }

};

class NoCommand : public ICommand{
    public:
        NoCommand(){}
        void execute() override {
            cout << "No command to execute" << endl;
        }
        void undo() override {
            cout << "No command to undo" << endl;
        }
};

class LightOnCommand : public ICommand{
    Light* light;
    public:
        LightOnCommand(Light* light){
            this->light = light;
        }
        void execute() override {
            light->on();
        }
        
        void undo() override {
            light->off();
        }
};

class LightOffCommand : public ICommand{
    IObject* light;
    public:
        LightOffCommand(IObject* light){
            this->light = light;
        }
        void execute() override {
            light->off();
        }
        
        void undo() override {
            light->on();
        }
};

class Remote{
    private:
        ICommand* onCommands[7];
        ICommand* offCommands[7];
        ICommand* undoCommand = new NoCommand();
    public:
        Remote(){
            for (int i = 0; i < 7; i++) {
                onCommands[i] = new NoCommand();
                offCommands[i] = new NoCommand();
            }
        }

        void setCommand(int slot, ICommand* onCommand, ICommand* offCommand){
            onCommands[slot] = onCommand;
            offCommands[slot] = offCommand;
        }

        void onButtonPushed(int slot){
            onCommands[slot]->execute();
            undoCommand = onCommands[slot];
        }

        void offButtonPushed(int slot){
            offCommands[slot]->execute();
            undoCommand = offCommands[slot];
        }

        void undo(){
            undoCommand->undo();
        }
};

int main(){
    Light* light = new Light();
    ICommand* lightOffCommand = new LightOffCommand(light);
    ICommand* lightOnCommand = new LightOnCommand(light);

    Remote* remote = new Remote();
    remote->setCommand(1, lightOnCommand, lightOffCommand);
    remote->offButtonPushed(1);
    remote->onButtonPushed(1);
    remote->undo();
    
    return 0;
}