#include <ctime>
#include <iomanip>
#include <vector>
#include <fstream>
class Track{

    std::string name="unknown";
    int duration=0;
    std::time_t d=std::time(nullptr);
    std::tm* date=localtime(&d);

public:

    std::string getName(){
        return name;
    }
    void getDate(){
        std::cout<<std::put_time(date,"%y/%m/%d")<<std::endl;
    }
    int getDuration(){
        return duration;
    }
    Track* setTrack1(){
        Track* track=new Track;
        track->name = "마.피.아.IntheMorning";
        track->duration = 172;
        track->date->tm_year = 2021;
        track->date->tm_mon = 04;
        track->date->tm_mday = 31;
        return track;
    }
    Track* setTrack2(){
        Track* track=new Track;
        track->name = "Tennis(O:O)";
        track->duration = 219;
        track->date->tm_year = 2021;
        track->date->tm_mon = 04;
        track->date->tm_mday = 31;
        return track;
    }
    Track* setTrack3(){
        Track* track=new Track;
        track->name = "Euphoria";
        track->duration = 229;
        track->date->tm_year = 2018;
        track->date->tm_mon = 8;
        track->date->tm_mday = 24;
        return track;
    }
    Track* setTrack4(){
        Track* track=new Track;
        track->name = "Trivia起:JustDance";
        track->duration = 225;
        track->date->tm_year = 2018;
        track->date->tm_mon = 8;
        track->date->tm_mday = 24;
        return track;
    }
    Track* setTrack5(){
        Track* track=new Track;
        track->name = "Serendipity";
        track->duration = 227;
        track->date->tm_year = 2018;
        track->date->tm_mon = 8;
        track->date->tm_mday = 24;
        return track;
    }
    Track* setTrack6(){
        Track* track=new Track;
        track->name = "DNA";
        track->duration = 224;
        track->date->tm_year = 2018;
        track->date->tm_mon = 8;
        track->date->tm_mday = 24;
        return track;
    }
    Track* setTrack7(){
        Track* track=new Track;
        track->name = "Butter";
        track->duration = 164;
        track->date->tm_year = 2021;
        track->date->tm_mon = 05;
        track->date->tm_mday = 21;
        return track;
    }

};

