//
// Created by 瓜不甜 on 2018/9/1.
//


#include "Timer.h"


void Timer::test() {
    timer t;
    // 这里是指，有这么大的时间的长度，然后，才会归零，或者溢出的
    std::cout<<"最大的计量时间"<<t.elapsed_max()/3600<<"h(小时)"<<std::endl;
    std::cout<<"最小的计量时间"<<t.elapsed_min()<<"s(秒)"<<std::endl;
}

void Timer::test2() {
    timer t;
    t.restart();
    int count=100000;
    while (count--)
    {
        std::cout<<"count"<<count<<std::endl;
    }
    std::cout<<"消耗的时间是:"<<t.elapsed()<<"s(秒)"<<std::endl;

}
