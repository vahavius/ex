#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Observerable;

class BaseItemInfo {
    public:
        BaseItemInfo(){}
        ~BaseItemInfo(){};
};

class Observer {
    public:
        Observer(){}
        virtual ~Observer(){}
        virtual void update(Observerable *o, BaseItemInfo* itm) = 0;
};

class Observerable {
    public:
        Observerable(){}
        virtual ~Observerable(){}
        virtual void addApp(Observer* o) = 0; 
        virtual void delApp(Observer* o) = 0;
        virtual void notifyApp() = 0;
};

class Alarm : public Observerable{
    private:
        vector<Observer *> apps;
        string alarmString;
        string alarmTime;
    public:
        Alarm(){}
        virtual ~Alarm(){}
        string getAlarmString(){
            return alarmString;
        }

        string getAlarmTime(){
            return alarmTime;
        }

        void addApp(Observer* o){
            if(o != NULL){
                apps.push_back(o);
            }
        }

        void delApp(Observer* o){
            for(int i = 0; i < apps.size(); i++){
                if(apps[i] == o){
                    apps.erase(apps.begin() + i);
                    break;
                }
            }
        }

        void notifyApp(){
            //cout << "Go notifyApp, and vector size is :" << apps.size() << "\n" ;
            for(int i = 0; i < apps.size(); i++){
                //cout <<"In for loop\n";
                if(apps[i] != NULL){
                    apps[i]->update(this, NULL);
                }
            }
        }

        void editInfo(string i_alarmString, string i_alarmTime){
            this->alarmString = i_alarmString;
            this->alarmTime = i_alarmTime;
            //cout << "Go editInfo\n";
            notifyApp();
        }

};

class AbcApp : public Observer{
    public:
        AbcApp(){}
        virtual ~AbcApp(){}
        void update(Observerable* o, BaseItemInfo* itm){
            cout <<"AbcApp : " << ((Alarm*)o)->getAlarmString() << " and time :" << ((Alarm*)o)->getAlarmTime() << "\n";
        }
};

class DefApp : public Observer{
    public:
        DefApp(){}
        virtual ~DefApp(){}
        void update(Observerable* o, BaseItemInfo* itm){
            cout <<"DefApp : " << ((Alarm*)o)->getAlarmString() << " and time :" << ((Alarm*)o)->getAlarmTime() << "\n";
        }
};


int main()
{
    Alarm* alarm = new Alarm();

    AbcApp* x = new AbcApp();
    DefApp* y = new DefApp();

    alarm->addApp(x);
    alarm->addApp(y);
    //cout <<"Input:\n";
    alarm->editInfo("Wake-up now", "12:00PM");
    
    return 0;
}