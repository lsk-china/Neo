#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <cstdlib>
#include <memory>
#include <string>

extern "C"{
#include "../thirdparty/lua/lua.h"
#include "../thirdparty/lua/lualib.h"
#include "../thirdparty/lua/lauxlib.h"
};

enum Type
{
    LSP,
    BROWSER,
    EDITORCHANGE,
    TOOL
};
struct PlugInfo
{
    std::string name;
    std::string author;
    std::string version;
    std::string file;
    std::string path;
    Type type;
};

class Container
{
private:
	//初始化lua_State
    lua_State* L = luaL_newstate();
    std::unique_ptr<PlugInfo> info;
public:
    Container(std::string file);
    Container();
    ~Container();
};

#endif