//
// Created by 周天斌 on 2021/12/29.
//

#ifndef CPP_PRACTICE_TV_H
#define CPP_PRACTICE_TV_H
#include "iostream"
class Tv {
public:
    // core 友元类 remote can access Tv private parts
    friend class Remote;
    enum {Off, On};
    enum {MinVal,MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

    Tv(int s = Off, int mc = 125) : state(s), volume(5),
                                    maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state = (state == On)? Off : On; }
    bool ison() const {return state == On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
    void set_input() {input = (input == TV)? DVD : TV;}
    void settings() const;  // display all settings
    void show() const {
        std::cout << state << std::endl;
        std::cout << volume << std::endl;
        std::cout << maxchannel << std::endl;
        std::cout << channel << std::endl;
        std::cout << mode << std::endl;
        std::cout << input << std::endl;
    }
private:
    int state;              // on or off
    int volume;             // assumed to be digitized
    int maxchannel;         // maximum number of channels
    int channel;            // current channel setting
    int mode;               // broadcast or cable
    int input;              // TV or DVD
};

class Remote {
private:
    int mode;
public:
    Remote(int m = Tv::TV) : mode(m) {}
    bool volup(Tv & t) { return t.volup();}
    bool voldown(Tv & t) { return t.voldown();}
    void onoff(Tv & t) { t.onoff(); }
    void chanup(Tv & t) {t.chanup();}
    void chandown(Tv & t) {t.chandown();}
    void set_chan(Tv & t, int c) {t.channel = c;}
    void set_input(Tv & t) {t.set_input();}
};
#endif //CPP_PRACTICE_TV_H
