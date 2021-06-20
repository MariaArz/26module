#include <iostream>
#include <vector>
#include "track-list.h"




class Player{
    std::vector<Track*> songs;
    int on=-1;


public:



    void add(Track* track){
        songs.push_back(track);
    }


    void play(){
        int n;
        std::cout<<"\nInput song's number";
        std::cin>>n;
        if (n > songs.size()){
            n=songs.size()-n;

        }
        if (on==-1){
            std::cout<<"\nPlay: "<<songs[n]->getName()<<" "<<songs[n]->getDuration()<<" s. ";
            songs[n]->getDate();
            on=n;
        }
    }
    void pause(){
        if (on!=-1){
            std::cout<<"Pause: "<<songs[on]->getName()<<" "<<songs[on]->getDuration()<<" s. ";
            songs[on]->getDate();
            on=-1;
        }
    }
    void next(){
        std::cout<<"Next: "<<songs[std::rand()%(sizeof(songs)/sizeof(songs[0])+1)]->getName()<<
        " "<<songs[std::rand()%(sizeof(songs)/sizeof(songs[0])+1)]->getDuration()<<" s. ";
        songs[std::rand()%(sizeof(songs)/sizeof(songs[0])+1)]->getDate();

            on=std::rand()%(sizeof(songs)/sizeof(songs[0])+1);

    }
    void stop(){
        int checkStop=0;
        if (on!=-1 && checkStop==0){
            std::cout<<"Stop: "<<songs[on]->getName()<<" "<<songs[on]->getDuration()<<" s .";
            songs[on]->getDate();
            on=-1;
            checkStop=1;
        }
        else{
            std::cout<<"Stop nothing"<<std::endl;
        }
    }
};
int main() {
    Track* track=new Track;
    std::string command;
    Player* player= new Player;
    player->add(track->setTrack1());
    player->add(track->setTrack2());
    player->add(track->setTrack3());
    player->add(track->setTrack4());
    player->add(track->setTrack5());
    player->add(track->setTrack6());
    player->add(track->setTrack7());
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
