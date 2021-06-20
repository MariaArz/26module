#include <iostream>
class Screen{
    int length=80, width=50;

public:

    int getLength(){
        return length;
    }
    int getWidth(){
        return width;
    }

};
class Window{
    int x,y,a,b;
    Screen* scr=new Screen;
public:
    bool setXY(int valX, int valY, int valA, int valB){
        if (valX < 0 || valY <0 || valA+valX > scr->getLength() || valB+valY > scr->getWidth()){
            return false;
        }
        return true;
    }
    void size(int X, int Y, int A, int B){
        x=X;
        y=Y;
        a=A;
        b=B;
    }
    int getX(){
        return  x;
    }
    int getY(){
        return  y;
    }
    int getA(){
        return  a;
    }
    int getB(){
        return  b;
    }
};
class Func{
    Window* wind=new Window;
    Screen* scr=new Screen;
public:
    void input(){
        int inX, inY, inA, inB;
        for(;;){
            std::cout<<"Input coordinate and size"<<std::endl;
            std::cin>>inX>>inY>> inA>> inB;
            if (wind->setXY(inX, inY, inA, inB)){
                wind->size(inX, inY, inA, inB);
                break;
            }
            else{
                std::cout<<"Wrong! Try again"<<std::endl;
                continue;
            }
        }
    }
    void move(int vecX, int vecY){
        if (!wind->setXY(wind->getX()+vecX,wind->getY()+vecY,wind->getA(),wind->getB())){
            std::cout<<"Warning! Wrong coordinate or parameters of screen"<<std::endl;
        }

        else{
            wind->size(wind->getX()+vecX,wind->getY()+vecY,wind->getA(),wind->getB());
            std::cout<<"New coordinate: x= "<<wind->getX()<<" and y= "<<wind->getY()<<std::endl;
        }
    }
    void  resize(){
        int newA, newB;
        std::cout<<"x= "<<wind->getX()<<" and y= "<<wind->getY()<<" with size a= "<<
        wind->getA()<<" and b= "<<wind->getB()<<std::endl;
        for (;;){
            std::cout<<"Input new size"<<std::endl;
            std::cin>>newA>>newB;
            if (wind->setXY(wind->getX(),wind->getY(),newA,newB)){
                wind->size(wind->getX(),wind->getY(),newA,newB);
                std::cout<<"x= "<<wind->getX()<<" and y= "<<wind->getY()<<" with parameters a= "<<
                         wind->getA()<<" and b= "<<wind->getB()<<std::endl;
                break;
            }
            else{
                std::cout<<"Wrong new size! Try again"<<std::endl;
                continue;
            }
        }
    }
    void display(){
        for(int i=0; i < scr->getWidth(); i++){
            for(int j=0; j < scr->getLength(); j++){
                if (j >= wind->getX() && j <= wind->getX()+wind->getA()
                    && i >= wind->getY() && i <= wind->getY()+wind->getB()){
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
