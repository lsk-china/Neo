#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include "include/lua/lua.h"
#include "include/lua/lualib.h"
#include "include/lua/lauxlib.h"

class Container
{
	//初始化lua_State
    lua_State* L = luaL_newstate();
};

#endif