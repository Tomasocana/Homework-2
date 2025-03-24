#include "time.h"
#include <iomanip>

using namespace std;

int main(){
    //a
    Time t1;
    t1.showTime();
    //b
    Time t2(9);
    t2.showTime();
    //c
    Time t3(12, 30);
    t3.showTime();
    //d
    Time t4(12, 30, 45);
    t4.showTime();
    //e
    Time t5(12, 30, 45, "p.m.");
    t5.showTime();
    return 0;
}