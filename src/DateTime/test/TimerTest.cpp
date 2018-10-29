//
// Created by 瓜不甜 on 2018/9/1.
//
#include <gtest/gtest.h>
#include "Timer.h"
namespace {
    TEST(Time_Test_test1_Test,test1)
    {
        Timer a;
        a.test();
    }

    TEST(Time_Test_test2_Test,test1)
    {
        Timer a;
        a.test2();
    }

    TEST(Time_Test_test3_Test,test1)
    {
        Timer a;
        a.ReadFile();
    }

}
