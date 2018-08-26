//
// Created by 瓜不甜 on 2018/8/27.
//

#include <gtest/gtest.h>
#include "../main/XmlParser.h"

namespace {
    TEST(Base_Solution1_test1_Test,test1)
    {
        XmlParser a;
        a.load("setting.xml");
        std::cout<<a.m_file<<std::endl;
        std::cout<<a.m_level<<std::endl;
        std::set<std::string>::iterator i;
        for ( i = a.m_modules.begin(); i != a.m_modules.end(); ++i) {
            std::cout<<*i<<std::endl;
        }

    }
}
