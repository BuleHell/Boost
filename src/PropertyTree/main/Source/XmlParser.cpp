//
// Created by 瓜不甜 on 2018/8/26.
//

#include "XmlParser.h"

// 获得文件
void XmlParser::load(const std::string &filename) {

    // 创建ptree对象
    pt::ptree tree;

    // 读取XML文件到tree对象
    pt::read_xml(filename, tree);

    // 通过路径获取元素：强制的类型
    // 如果找不到对应的元素，就会抛出异常：
    // 对于异常，我们可以抛出，也可以直接捕获，然后打印日志之类
    m_file = tree.get<std::string>("debug.filename");

    // 通过路径获取元素：没有类型
    // 获取的类型会被转化为对应的类型：如果没有对应的类型，会被转化为默认的类型
    m_level = tree.get("debug.level", 0);


    // Use get_child to find the node containing the modules, and iterate over
    // its children. If the path cannot be resolved, get_child throws.
    // A C++11 for-range loop would also work.
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("debug.modules"))
                {
                    // The data function is used to access the data stored in a node.
                    m_modules.insert(v.second.data());
                }

}

void XmlParser::save(const std::string &filename) {
    // Create an empty property tree object.
    pt::ptree tree;

    // Put the simple values into the tree. The integer is automatically
    // converted to a string. Note that the "debug" node is automatically
    // created if it doesn't exist.
    tree.put("debug.filename", m_file);
    tree.put("debug.level", m_level);

    // Add all the modules. Unlike put, which overwrites existing nodes, add
    // adds a new node at the lowest level, so the "modules" node will have
    // multiple "module" children.
    BOOST_FOREACH(const std::string &name, m_modules)
                    tree.add("debug.modules.module", name);

    // Write property tree to XML file
    pt::write_xml(filename, tree);
}