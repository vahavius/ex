#include <iostream>
#include <string>
#include <vector>

using namespace std;

class OderCommand {
    public:
        OderCommand(){}
        virtual ~OderCommand(){}
        virtual void execute() = 0;
    
};

class PizzaChefReceiver{
    public:
        PizzaChefReceiver(){}
        ~PizzaChefReceiver(){}
        void makePizza(){
            cout << "I'm making pizza\n";
        }

};
class SteakChefReceiver{
    public:
        SteakChefReceiver(){}
        ~SteakChefReceiver(){}
        void makeSteak(){
            cout << "I'm making steak\n";
        }

};

class PizzaConcreteCommand : public OderCommand {
    public:
        PizzaChefReceiver *chef;
        PizzaConcreteCommand(){
            chef = new PizzaChefReceiver();
        }
        ~PizzaConcreteCommand(){
            delete chef;
        }

        void execute(){
            chef->makePizza();
        }

        string toString(){
            return "pizza";
        }
};

class SteakConcreteCommand : public OderCommand {
    public:
        SteakChefReceiver *steak;
        SteakConcreteCommand(){
            steak = new SteakChefReceiver();
        }
        ~SteakConcreteCommand(){
            delete steak;
        }

        void execute(){
            steak->makeSteak();
        }

        string toString(){
            return "steak";
        }
};

class WaiterInvoke{
    public:
        WaiterInvoke(){}
        ~WaiterInvoke(){}
        void takeOderPizza(PizzaConcreteCommand *m_oder){
            cout << "Waiter take new order " << m_oder->toString() << "\n";
            m_oder->execute();
        }
        void takeOderSteak(SteakConcreteCommand *m_oder){
            cout << "Waiter take new order " << m_oder->toString() << "\n";
            m_oder->execute();
        }
};

class CustomerClient{
    public:
        WaiterInvoke *waiter;
        CustomerClient(){}
        ~CustomerClient(){}
        CustomerClient(WaiterInvoke *m_waiter){
            waiter = m_waiter;
        }

        void request(string requests){
            PizzaConcreteCommand *oderspizza;
            SteakConcreteCommand *oderssteak;
            if(requests.compare("pizza") == 0){
                oderspizza = new PizzaConcreteCommand();
                waiter->takeOderPizza(oderspizza);
            }
            else {
                oderssteak = new SteakConcreteCommand();
                waiter->takeOderSteak(oderssteak);
            }
        }
};

int main()
{
    WaiterInvoke *waiter;

    waiter = new WaiterInvoke();
    CustomerClient *client = new CustomerClient(waiter);
    client->request("pizza");
    client->request("steak");

    return 0;
}