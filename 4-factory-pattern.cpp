#include <iostream>
#include <string>
using namespace std;

class PizzaStore {
    public:
        virtual Pizza createPizza(string type) = 0;
        Pizza orderPizza(string type){
            Pizza pizza = createPizza(type);
            pizza.prepare();
            pizza.cut();
            pizza.box();
            return pizza;
        }
};

class NyPizzaStore : PizzaStore {
    public:
        Pizza createPizza(string type) override {
            if(type == "cheese") return new NyStyledCheesePizza();
        }
};

class Pizza {
    public:
        PizzaIngredientFactory* pizzaIngredientFactory;
        virtual void bake() = 0;
        void cut() = 0;
        virtual void box() = 0;

};

class NyStyledCheesePizza : public Pizza {

};

class PizzaIngredientFactory{
    public:
        Dough* dough;
        Sauce* sauce;
};

class NyPizzaIngredientFactory : PizzaIngredientFactory{
    public:
        NyPizzaIngredientFactory() {
            dough = new ThinDough();
            sauce = new PizzaSauce();
        }
};

class Dough {
    public:
        virtual void name() = 0;
};

class ThinDough : public Dough {
    public:
        void name() override {
            cout << "Thin Dough" << endl;
        }
};

class Sauce {
    public:
        virtual void name() = 0;
};

class PizzaSauce : public Sauce {
    public:
        void name() override {
            cout << "Pizza Sauce" << endl;
        }
};

int main(){
    Dough* thinDough = new ThinDough();
    thinDough->name();
    return 0;
}