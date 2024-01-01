#include "pluginloader.h"

Container::Container(){
    luaL_openlibs(L);
}

Container::Container(const std::string& file)
{
    luaL_openlibs(L);
    luaL_dofile(L, file.c_str());
}

Container::~Container()
{
    // 释放lua虚拟机实例
    lua_close(L);
}