//
// Created by 瓜不甜 on 2018/9/1.
//

#ifndef BOOST_TIMER_H
#define BOOST_TIMER_H

#include <iostream>
#include <vector>
#include <boost/timer.hpp>
#include <boost/progress.hpp>


using namespace boost;
class Timer {
public:
    // 测试下这个工具的使用
    void test();

    // 简单的使用
    void test2();

    // 读取文件的时候的展示耗时
    void ReadFile();

};


#endif //BOOST_TIMER_H
