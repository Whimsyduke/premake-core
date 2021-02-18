/**
 * \file   mxml_LoadFile.c
 * \brief  Load a file into an XML node tree.
 * \author Copyright (c) 2002-2014 Jason Perkins and the Premake project
 */

#ifdef PREMAKE_MXML
#include "premake.h"
#include "../../contrib/mxml/mxml.h"

int mxml_SaveFile(lua_State* L)
{
	mxml_node_t* node = (mxml_node_t*)lua_touserdata(L, 1);
	const char* path = luaL_checkstring(L, 2);
	mxml_save_cb_t* cb = (mxml_save_cb_t*) lua_touserdata(L, 2);
#if PLATFORM_WINDOWS
	FILE* file;
	wchar_t wide_path[PATH_MAX];
	if (MultiByteToWideChar(CP_UTF8, 0, path, -1, wide_path, PATH_MAX) == 0)
	{
		lua_pushinteger(L, -1);
		lua_pushstring(L, "unable to encode path");
		return 2;
	}
	file = _wfopen(wide_path, L"w");
	if (file == NULL)
	{
		lua_pushinteger(L, -1);
		lua_pushstring(L, "unable to open path");
		return 2;
	}
	int success = mxmlSaveFile(node, file, cb);
	fclose(file);
	lua_pushboolean(L, success);
	return 1;
#else
	lua_pushinteger(L, -1);
	lua_pushstring(L, "only support windows");
	return 2;
#endif
}
#endif
