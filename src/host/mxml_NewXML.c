/**
 * \file   mxml_LoadFile.c
 * \brief  Load a file into an XML node tree.
 * \author Copyright (c) 2002-2014 Jason Perkins and the Premake project
 */

#ifdef PREMAKE_MXML
#include "premake.h"
#include "../../contrib/mxml/mxml.h"

int mxml_NewXML(lua_State* L)
{
	const char* name = luaL_checkstring(L, 1);
#if PLATFORM_WINDOWS
	mxml_node_t* node = mxmlNewXML(name);
	lua_pushlightuserdata(L, node);
	return 1;
#else
	lua_pushinteger(L, -1);
	lua_pushstring(L, "only support windows");
	return 2;
#endif
}
#endif
