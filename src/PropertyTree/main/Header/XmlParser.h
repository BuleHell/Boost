//
// Created by 瓜不甜 on 2018/8/26.
//

#ifndef BOOST_XMLPARSER_H
#define BOOST_XMLPARSER_H
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>
namespace pt = boost::property_tree;

class XmlParser {

public:
        std::string m_file;               // log filename
        int m_level;                      // debug level
        std::set<std::string> m_modules;  // modules where logging is enabled

        void load(const std::string &filename);
        void save(const std::string &filename);
};


#endif

//BOOST_XMLPARSER_H
