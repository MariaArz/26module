#include <iostream>
#include <ctime>
#include <vector>


class Track{

    std::string name="unknown";
    int duration=0;
    std::time_t d=std::time(nullptr);
    std::tm* date=localtime(&d);

public:
    friend std::vector<Track*> setSongs();

    std::string getName(){
        return name;
    }
    void getDate(){
        std::cout<<std::asctime(date)<<std::endl;
    }
    int getDuration(){
        return duration;
    }

};
std::vector<Track*> setSongs(){
    Track* track=new Track;
    std::vector<Track*> s;
    track->name= "마.피.아.IntheMorning";
    track->duration = 172;
    track->date->tm_year = 2021;
    track->date->tm_mon = 04;
    track->date->tm_mday = 31;
    s.push_back(track);
    Track* track1=new Track;
    track1->name = "Tennis(O:O)";
    track1->duration = 219;
    track1->date->tm_year = 2021;
    track1->date->tm_mon = 04;
    track1->date->tm_mday = 31;
    s.push_back(track1);
    Track* track2=new Track;
    track2->name = "Euphoria";
    track2->duration = 229;
    track2->date->tm_year = 2018;
    track2->date->tm_mon = 8;
    track2->date->tm_mday = 24;
    s.push_back(track2);
    Track* track3=new Track;
    track3->name = "Trivia起:JustDance";
    track3->duration = 225;
    track3->date->tm_year = 2018;
    track3->date->tm_mon = 8;
    track3->date->tm_mday = 24;
    s.push_back(track3);
    Track* track4=new Track;
    track4->name = "Serendipity";
    track4->duration = 227;
    track4->date->tm_year = 2018;
    track4->date->tm_mon = 8;
    track4->date->tm_mday = 24;
    s.push_back(track4);
    Track* track5=new Track;
    track5->name = "DNA";
    track5->duration = 224;
    track5->date->tm_year = 2018;
    track5->date->tm_mon = 8;
    track5->date->tm_mday = 24,
    s.push_back(track5);
    Track* track6=new Track;
    track6->name = "Butter";
    track6->duration = 164;
    track6->date->tm_year = 2021;
    track6->date->tm_mon = 05;
    track6->date->tm_mday = 21;
    s.push_back(track6);
    return s;
}

class Player{


public:


    std::vector<Track*> songs=setSongs();

    int on=sizeof(songs);

    void play(){
        int n;
        std::cout<<"\nInput song's number";
        std::cin>>n;
        if (n > sizeof(songs)){
            n=sizeof(songs)-n;

        }
        if (on==sizeof(songs)){
            std::cout<<"\nPlay: "<<songs[n]->getName()<<" "<<songs[n]->getDuration()<<" s. ";
            songs[n]->getDate();
            on=n;
        }
    }
    void pause(){
        if (on!=sizeof(songs)){
            std::cout<<"Pause: "<<songs[on]->getName()<<" "<<songs[on]->getDuration()<<" s. ";
            songs[on]->getDate();
            on=sizeof(songs);
        }
    }
    void next(){
        std::cout<<"Next: "<<songs[std::rand()%(sizeof(songs)/sizeof(songs[0])+1)]->getName()<<
        " "<<songs[std::rand()%(sizeof(songs)/sizeof(songs[0])+1)]->getDuration()<<" s. ";
        songs[std::rand()%(sizeof(songs)/sizeof(songs[0])+1)]->getDate();

            on=std::rand()%(sizeof(songs)/sizeof(songs[0])+1);
            std::cout<<on;

    }
    void stop(){
        int checkStop=0;
        if (on!=sizeof(songs) && checkStop==0){
            std::cout<<"Stop: "<<songs[on]->getName()<<" "<<songs[on]->getDuration()<<" s .";
            songs[on]->getDate();

            on=sizeof(songs);
            checkStop=1;
        }
        else{
            std::cout<<"Stop nothing"<<std::endl;
        }
    }
};
int main() {
    std::string command;
    Player* player= new Player;

    for(;;){
        std::cout<<"\nInput command";
        std::cin>>command;
        if (command=="play"){
            player->play();
        }
        else if (command=="pause"){
            player->pause();
        }
        else if (command=="next"){
            player->next();
        }
        else if (command=="stop"){
            player->stop();
        }
        else if (command=="exit"){
            break;
        }
    }
    delete player;
    return 0;
}
