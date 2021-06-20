#include <iostream>
#include<string>
#include <vector>

class Number{
    std::string name;
    std::string number;
public:
    std::string getName(){
        return name;
    }
    std::string getNumber(){
        return number;
    }
    bool checkNumber(std::string nmb){
        if (nmb[0]=='+' && nmb[1]=='7' && nmb.length()==12){
            return true;
        }
        return false;
    }
    Number* setNum(std::string addName, std::string addNumber){
        Number* num=new Number;
        num->name=addName;
        num->number=addNumber;
        return num;
    }
    Number* setNum1(){
        Number* num=new Number;
        num->name="Ivanov";
        num->number="+79151234567";
        return num;
    }
    Number* setNum2(){
        Number* num=new Number;
        num->name="Ivanor";
        num->number="+79151234568";
        return num;
    }
    Number* setNum3(){
        Number* num=new Number;
        num->name="Ivanrv";
        num->number="+79151234569";
        return num;
    }
    Number* setNum4(){
        Number* num=new Number;
        num->name="Iranov";
        num->number="+79151434567";
        return num;
    }
    Number* setNum5(){
        Number* num=new Number;
        num->name="Ivarov";
        num->number="+79151237567";
        return num;
    }
    //friend  class Phone;
};

class Phone{
    Number* num=new Number;
    std::vector<Number*> phoneList={
            num->setNum1(),
            num->setNum2(),
            num->setNum3(),
            num->setNum4(),
            num->setNum5(),
    };
public:
    void add(std::string addName, std::string addNumber){

        if (num->checkNumber(addNumber)){
            phoneList.push_back(num->setNum(addName,addNumber));
        }
        else{
            std::cout<<"Error! Number should be start at '+7'"<<std::endl;
        }
    }
    void call(std::string call){

        for (int i=0; i < phoneList.size(); i++){
            if (phoneList[i]->getName()==call || phoneList[i]->getNumber()==call){
                    std::cout<<"CALL:"<<phoneList[i]->getName()<<
                    " "<<phoneList[i]->getNumber()<<std::endl;
                    break;
            }
        }
    }
    void sms(std::string sms){

        for (int i=0; i < phoneList.size(); i++) {
            if (phoneList[i]->getName() == sms || phoneList[i]->getNumber() == sms) {
                std::cout << "Massage to::" <<phoneList[i]->getName()<<
                                            " "<<phoneList[i]->getNumber()<<std::endl;
                std::cout<<"Input massage"<<std::endl;
                std::string massage="";
                std::cin.ignore(INT_MAX, '\n');
                std::getline(std::cin, massage);
                if (massage!=""){
                    std::cout<<"Massage "<<massage<<" submitted"<<std::endl;
                }
                else {
                    std::cout<<"Cancel"<<std::endl;
                }break;
            }
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
            std::string addName, addNumber;
            std::cout<<"Input name and number"<<std::endl;
            std::cin>>addName>>addNumber;
            phone->add(addName, addNumber);
        }
        else if(command=="call"){
            std::string call;
            std::cout<<"Name of number which needed?"<<std::endl;
            std::cin>>call;
            phone->call(call);
        }
        else if(command=="sms"){
            std::string sms;
            std::cout<<"Name of number which needed?"<<std::endl;
            std::cin>>sms;
            phone->sms(sms);
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
