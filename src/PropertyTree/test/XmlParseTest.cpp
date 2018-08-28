//
// Created by 瓜不甜 on 2018/8/27.
//

#include <gtest/gtest.h>
#include "XmlParser.h"

namespace {
    TEST(Base_Solution1_test1_Test,test1)
    {
        XmlParser a;
        a.load("../resource/setting.xml");
        std::cout<<a.m_file<<std::endl;
        std::cout<<a.m_level<<std::endl;
        std::set<std::string>::iterator i;
        for ( i = a.m_modules.begin(); i != a.m_modules.end(); ++i) {
            std::cout<<*i<<std::endl;
        }
    }

	TEST(Base_Solution1_test1_Test,test2)
	{
		XmlParser a;
		a.m_file="ewqeqw";
		a.m_level=1;
		std::set<std::string> i ;
		i.insert("231");
		i.insert("31");
		i.insert("312");
		i.insert("312");
		i.insert("312");
		a.m_modules=i;
		a.save("../resource/setting2.xml");
//		std::cout<<a.m_file<<std::endl;
//		std::cout<<a.m_level<<std::endl;
//		std::set<std::string>::iterator i;
//		for ( i = a.m_modules.begin(); i != a.m_modules.end(); ++i) {
//			std::cout<<*i<<std::endl;
//		}
	}
}
