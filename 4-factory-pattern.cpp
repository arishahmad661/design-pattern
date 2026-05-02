#include<iostream>
using namespace std;

class Dough{
    public:
        virtual string getName() = 0;
        virtual ~Dough() = default;
};

class ThickCrustDough : public Dough{
    public:
        string getName() override { return "Thick Crust Dough";}
};

class ThinCrustDough : public Dough{
    public:
        string getName() override { return "Thin Crust Dough";}
};


class Sauce{
    public:
        virtual string getName() = 0;
        virtual ~Sauce() = default;
};

class MarinaraSauce : public Sauce{
    public:
        string getName() override { return "Marinara Sauce"; }
};

class PlumTomatoSauce : public Sauce{
    public:
        string getName() override { return "Plum Tomato Sauce"; }
};


class Cheese{
    public:
        virtual string getName() = 0;
        virtual ~Cheese() = default;
};

class ReggianoCheese : public Cheese{
    public:
        virtual string getName(){
            return "Reggiano Cheese";
        }
};

class MozzarellaCheese : public Cheese{
    public:
        virtual string getName(){
            return "Mozzarella Cheese";
        }
};


class PizzaIngredientFactory{
    public:
        virtual Dough* createDough() = 0;
        virtual Sauce* createSauce() = 0;
        virtual Cheese* createCheese() = 0;
        virtual ~PizzaIngredientFactory() = default;
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory{
    public:
        Dough* createDough() override { return new ThickCrustDough(); }
        Sauce* createSauce() override { return new MarinaraSauce(); }
        Cheese* createCheese() override { return new ReggianoCheese(); }
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory{
    public:
        Dough* createDough() override { return new ThinCrustDough(); }
        Sauce* createSauce() override { return new PlumTomatoSauce(); }
        Cheese* createCheese() override { return new MozzarellaCheese(); }
};

class Pizza{
    protected:
        string name;
        Dough* dough = nullptr;
        Sauce* sauce = nullptr;
        Cheese* cheese = nullptr;

    public:
        virtual void prepare() = 0;

        virtual void bake(){
            cout << "Baking fro 30 mins...\n";
        }

        virtual void cut(){
            cout << "Cutting the pizza\n";
        }

        virtual void box(){
            cout << "Boxing the pizza\n";
        }

        string getName(){
            return name;
        }

        virtual ~Pizza(){
            delete dough;
            delete sauce;
            delete cheese;
        }
};

class CheesePizza : public Pizza { 
    PizzaIngredientFactory* pizzaIngredientFactory;

    public:
        CheesePizza(PizzaIngredientFactory* pifactory) : pizzaIngredientFactory(pifactory){
            name = "Cheese Pizza";
        }

        void prepare() override {
            cout << "Preparing " << name << "\n";
            dough = pizzaIngredientFactory->createDough();
            sauce = pizzaIngredientFactory->createSauce();
            cheese = pizzaIngredientFactory->createCheese();

            cout << " Dough: " << dough->getName() << "\n";
            cout << " Sauce: " << sauce->getName() << "\n";
            cout << " Cheese: " << cheese->getName() << "\n";
        }
};

class PepperoniPizza : public Pizza { 
    PizzaIngredientFactory* pizzaIngredientFactory;

    public:
        PepperoniPizza(PizzaIngredientFactory* pifactory) : pizzaIngredientFactory(pifactory){
            name = "Cheese Pizza";
        }

        void prepare() override {
            cout << "Preparing " << name << "\n";
            dough = pizzaIngredientFactory->createDough();
            sauce = pizzaIngredientFactory->createSauce();
            cheese = pizzaIngredientFactory->createCheese();

            cout << " Dough: " << dough->getName() << "\n";
            cout << " Sauce: " << sauce->getName() << "\n";
            cout << " Cheese: " << cheese->getName() << "\n";
        }
};

class PizzaStore{
    public:
        virtual Pizza* createPizza(string pizzaName) = 0;

        Pizza* orderPizza(string pizzaName){
            Pizza* pizza = createPizza(pizzaName);
            cout << "Making a " << pizza->getName() << "\n";
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
            return pizza;
        }

        virtual ~PizzaStore() = default;
};

class NYPizzaStore : public PizzaStore{
    NYPizzaIngredientFactory factory;
    public:
        Pizza* createPizza(string type) override {
            if(type == "cheese") return new CheesePizza(&factory);
            else if(type == "pepperoni") return new PepperoniPizza(&factory);
            else return nullptr;
        }
};

class ChicagoPizzaStore : public PizzaStore{
    NYPizzaIngredientFactory factory;
    public:
        Pizza* createPizza(string type) override {
            if(type == "cheese") return new CheesePizza(&factory);
            else if(type == "pepperoni") return new PepperoniPizza(&factory);
            else return nullptr;
        }
};


int main(){
    NYPizzaStore nyStore;
    ChicagoPizzaStore chicagoStore;

    Pizza* p1 = nyStore.orderPizza("cheese");
    cout << "\n";
    Pizza* p2 = nyStore.orderPizza("pepperoni");
    cout << "\n";

    delete p1;
    delete p2;
    
    return 0;
}