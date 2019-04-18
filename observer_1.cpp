#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ManObserver {
        public:
            ManObserver(){}
            virtual ~ManObserver(){}
            virtual void update (string  noti) = 0;
};

class GirlSubject {
    public:
        GirlSubject(){}
        virtual ~GirlSubject(){}
        virtual void addObserver(ManObserver *input) = 0;
        virtual void delObserver(ManObserver *input) = 0;
        virtual void notifyToObserver() = 0;

};

class BeautifulGirl : public GirlSubject {
    private:
        vector<ManObserver *>  man;
        string m_noti;
    public:
        BeautifulGirl(){}
        virtual ~BeautifulGirl(){}
        void addObserver(ManObserver *input){
            if(input != NULL){
                man.push_back(input);
            }
        }

        void delObserver(ManObserver *input){
            for(int i = 0; i <man.size(); i++){
                if(man[i] == input){
                    man.erase(man.begin() + i);
                    break;
                }
            }
        }

        void notifyToObserver(){
            for(int i = 0; i <man.size(); i++){
                if(man[i] != NULL){
                    man[i]->update(m_noti);
                }
            }
        }

        void editInfo(string i_info){
            if(i_info.compare("Married") == 0){
		string tmp = "I have Married";
		m_noti = tmp;
                notifyToObserver();
            }
        }
};

class ManA:public ManObserver{
    public:
        ManA(){}
        virtual ~ManA(){}
        void update(string  i_noti){
            cout <<"Hey" << ","<< i_noti <<"\n";
        }
};

class ManB:public ManObserver{
    public:
        ManB(){}
        virtual ~ManB(){}
        void update(string  i_noti){
            cout <<"Hey" << ","<< i_noti <<"\n";
        }
};


int main()
{
    BeautifulGirl* A = new BeautifulGirl();
    ManA* Boy1 = new ManA();
    ManB* Boy2 = new ManB();

    A->addObserver(Boy1);
    A->addObserver(Boy2);
    A->editInfo("Married");
	

    return 0;
}
