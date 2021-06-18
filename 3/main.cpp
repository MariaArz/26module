#include <iostream>
class Screen{
    int x,y,a,b;
public:
    bool setXY(int valX, int valY, int valA, int valB){
        if (valX < 0 || valY <0 || valA+valX > 80 || valB+valY > 50){
            return false;
        }
            //std::cout<<"Warning! Wrong coordinate or parameters of screen"<<std::endl;
        return true;
    }
    friend class Func;
};
class Func{
public:
    Screen* scr=new Screen;
    void input(){
        for(;;){
            std::cout<<"Input coordinate and size"<<std::endl;
            std::cin>>scr->x>>scr->y>>scr->a>>scr->b;
            if (scr->setXY(scr->x,scr->y,scr->a,scr->b)){
                break;
            }
            else{
                std::cout<<"Wrong! Try again"<<std::endl;
                continue;
            }
        }
    }
    void move(int vecX, int vecY){
        if (!scr->setXY(scr->x+vecX,scr->y+vecY,scr->a,scr->b)){
            std::cout<<"Warning! Wrong coordinate or parameters of screen"<<std::endl;
        }

        else{
            scr->x+=vecX;
            scr->y+=vecY;
            std::cout<<"New coordinate: x= "<<scr->x<<" and y= "<<scr->y<<std::endl;
        }
    }
    void  resize(){
        int newA, newB;
        std::cout<<"x= "<<scr->x<<" and y= "<<scr->y<<" with parameters a= "<<
        scr->a<<" and b= "<<scr->b<<std::endl;
        for (;;){
            std::cout<<"Input new size"<<std::endl;
            std::cin>>newA>>newB;
            if (scr->setXY(scr->x,scr->y,newA,newB)){
                scr->a=newA;
                scr->b=newB;
                std::cout<<"x= "<<scr->x<<" and y= "<<scr->y<<" with parameters a= "<<
                         scr->a<<" and b= "<<scr->b<<std::endl;
                break;
            }
            else{
                std::cout<<"Wrong new size! Try again"<<std::endl;
                continue;
            }
        }
    }
    void display(){
        for(int i=0; i < 50; i++){
            for(int j=0; j < 80; j++){
                if (j >= scr->x && j <= scr->x+scr->a
                    && i >= scr->y && i <= scr->y+scr->b){
                    std::cout<<"1";
                }
                else std::cout<<"0";
            }
            std::cout<<std::endl;
        }
    }
};

int main() {
    std::string command;
    Func* func=new Func;
    func->input();
    for (;;){
        std::cout<<"Input command"<<std::endl;
        std::cin>>command;
        if(command=="move"){
            int vecX, vecY;
            std::cout<<"Input new coordinate"<<std::endl;
            std::cin>>vecX>>vecY;
            func->move(vecX,vecY);
        }
        else if (command=="resize"){
            func->resize();
        }
        else if (command=="display"){
            func->display();
        }
        else if (command=="close"){
            break;
        }
    }
    return 0;
}
