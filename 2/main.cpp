#include <iostream>
#include <map>
#include<string>
class Number{
    std::string name;
    std::string number;
public:
    friend class Phone;
};
std::map<std::string,std::string> fall(){
    std::map<std::string,std::string> fall;
    fall["Ivanov"]="+79151234567";
    fall["Ivanor"]="+79151234568";
    fall["Ivanrv"]="+79151234569";
    fall["Iranov"]="+79151434567";
    fall["Ivarov"]="+79151237567";
    return fall;
}
class Phone{
public:
    Number* num=new Number;
    std::map<std::string,std::string> list=fall();
    void add(){
        std::cout<<"Input name and number"<<std::endl;
        std::cin>>num->name;
        std::cin>>num->number;
        if (num->number[0]=='+' && num->number[1]=='7' && num->number.length()==12){
            list.insert(std::pair<std::string,std::string>(num->name,num->number));
        }
        else{
            std::cout<<"Error! Number should be start at '+7'"<<std::endl;
        }
    }
    void call(){
        std::string some;
        std::cout<<"Name of number?"<<std::endl;
        std::cin>>some;
        if (some=="name"){
            std::cin>>num->name;
            std::cout<<"CALL:"<< list.find(num->name)->first<<" "<<list.find(num->name)->second;
        }
        else if (some=="number"){
            std::cin>>num->number;
            for (std::map<std::string, std::string>:: iterator it = list.begin();
                 it !=list.end(); it++) {
                if (it->second == num->number) {
                    std::cout << "CALL:" << it->first << " " << it->second;
                    break;
                }
            }
        }

    }
    void sms(){
        std::string massage="";
        std::string some;
        std::cout<<"Name of number?"<<std::endl;
        std::cin>>some;
        if (some=="name"){
            std::cin>>num->name;
            std::cout<<"Massage to::"<< list.find(num->name)->first<<" "<<list.find(num->name)->second<<std::endl;
        }
        else if (some=="number"){
            std::cin>>num->number;
            for (std::map<std::string, std::string>:: iterator it = list.begin();
                 it !=list.end(); it++) {
                if (it->second == num->number) {
                    std::cout << "Massage to:" << it->first << " " << it->second<<std::endl;
                    break;
                }
            }
        }
        std::cout<<"Input massage"<<std::endl;
        std::getline(std::cin, massage);
        //std::cin>>massage;
        if (massage!=""){
            std::cout<<"Massage "<<massage<<" submitted"<<std::endl;
        }
        else {
            std::cout<<"Cancel"<<std::endl;
        }

    }
};

int main() {
    std::string command;
    Phone* phone=new Phone;
    for(;;){
        std::cout<<"\nInput command"<<std::endl;
        std::cin>>command;
        if(command=="add"){
            phone->add();
        }
        else if(command=="call"){
            phone->call();
        }
        else if(command=="sms"){
            phone->sms();
        }
        else if(command=="exit"){
            break;
        }
        else{
            continue;
        }
    }
    delete phone;
}
