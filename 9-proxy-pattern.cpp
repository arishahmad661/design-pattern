#include<iostream>
using namespace std;

class ISubject{
    public:
        virtual void request() = 0;
        virtual ~ISubject() {}
};

class HeavyLoader : public ISubject{
    string imageName;
    public:
        HeavyLoader(string img){
            imageName = img;
        }

        void request() override {
            cout << "Heavy Loader request processing..." << endl;
        }
};

class VirtualProxy : public ISubject{
    private:
        ISubject* heavyLoader = nullptr;
        string img;
    public:
        VirtualProxy(string img){
            this->img = img;
        }

        void request() override {
            cout << "Virtual proxy processing request..." << endl;
            if(!heavyLoader){
                heavyLoader = new HeavyLoader(img);
            }
            heavyLoader->request();
        }
};

class BankAccount : public ISubject{
    public:
        void request() override {
            cout << "Withdraw in process..." << endl;
        }
};

class ProtectionProxy : public ISubject{
    private:
        ISubject* bankAccount = nullptr;
        string userType;
    public:
        ProtectionProxy(ISubject* bankAccount, string userType){
            this->bankAccount = bankAccount;
            this->userType = userType;
        }

        void request() override {
            cout << "Checking protection..." << endl;
            if(userType == "owner"){
                bankAccount->request();
            }else{
                cout << "Checking failed..." << endl;
            }
        }
};

class RemoteService : public ISubject{
    public:
        void request() override {
            cout << "Remote service accessed..." << endl;
        }
};

class RemoteProxy : public ISubject{
    private:
        ISubject* fetchRemoteServiceInstance(){
            static RemoteService instance;
            return &instance;
        }
    public:
        void request() override {
            cout << "Accesssign remote service..." << endl;

            ISubject* remoteService = fetchRemoteServiceInstance();
            remoteService->request();
        }
};

int main(){
    ISubject* subject = new VirtualProxy("file.png");
    subject->request();

    ISubject* bank = new BankAccount();
    ISubject* protectionProxy1 = new ProtectionProxy(bank, "owner");
    ISubject* protectionProxy2 = new ProtectionProxy(bank, "theif");
    protectionProxy1->request();
    protectionProxy2->request();

    ISubject* remoteProxy = new RemoteProxy();
    remoteProxy->request();

    return 0;
}