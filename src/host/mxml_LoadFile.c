/**
 * \file   mxml_LoadFile.c
 * \brief  Load a file into an XML node tree.
 * \author Copyright (c) 2002-2014 Jason Perkins and the Premake project
 */

#ifdef PREMAKE_MXML
#include "premake.h"
#include "../../contrib/mxml/mxml.h"

int mxml_LoadFile(lua_State* L)
{
	const char* path = luaL_checkstring(L, 1);
	mxml_load_cb_t* cb = (mxml_load_cb_t)lua_touserdata(L, 2);
	if (do_isfile(L, path))
	{
#if PLATFORM_WINDOWS
		FILE* file;
		wchar_t wide_path[PATH_MAX];
		if (MultiByteToWideChar(CP_UTF8, 0, path, -1, wide_path, PATH_MAX) == 0)
		{
			lua_pushinteger(L, -1);
			lua_pushstring(L, "unable to encode path");
			return 2;
		}
		file = _wfopen(wide_path, L"r");
		if (file == NULL)
		{
			lua_pushinteger(L, -1);
			lua_pushstring(L, "unable to open path");
			return 2;
		}
		mxml_node_t* node = mxmlLoadFile(NULL, file, cb);
		fclose(file);
		lua_pushlightuserdata(L, node);
		return 1;
#else
		lua_pushinteger(L, -1);
		lua_pushstring(L, "only support windows");
		return 2;
#endif
	}
	else
	{
		lua_pushinteger(L, -1);
		lua_pushstring(L, "path is not file");
		return 2;
	}
}
#endif
