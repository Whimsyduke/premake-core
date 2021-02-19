/**
 * \file   mxml_LoadFile.c
 * \brief  Load a file into an XML node tree.
 * \author Copyright (c) 2002-2014 Jason Perkins and the Premake project
 */

#ifdef PREMAKE_MXML
#include "premake.h"
#include "../../contrib/mxml/mxml.h"

int mxml_SetWrapMargin(lua_State* L)
{
	lua_Integer colum = lua_tointeger(L, 1);
#if PLATFORM_WINDOWS
	mxmlSetWrapMargin((int)colum);
	return 0;
#else
	lua_pushinteger(L, -1);
	lua_pushstring(L, "only support windows");
	return 2;
#endif
}
#endif
