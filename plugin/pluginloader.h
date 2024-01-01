/// 负责处理插件加载
/// Container 是一个容器类，用于存储，运行和管理插件

#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <cstdlib>
#include <memory>
#include <string>

// 引入lua的头文件
// 由于qt不允许引入hpp头文件，故需要用 extern "C" 进行声明
extern "C"{
#include "../thirdparty/lua/lua.h"
#include "../thirdparty/lua/lualib.h"
#include "../thirdparty/lua/lauxlib.h"
};

struct PlugInfo
{
    std::string name;
    std::string author;
    std::string version;
    std::string file;
    std::string path;
};

class Container
{
private:
	//初始化lua_State
    lua_State* L = luaL_newstate();
    std::unique_ptr<PlugInfo> info;
public:
    Container(const std::string& file);
    Container();
    ~Container();
};

#endif