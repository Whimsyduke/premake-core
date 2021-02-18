project "mxmlstat-lib"
	language    "C"
	kind        "StaticLib"
	defines     { "_LIB" }
	warnings    "off"

	includedirs { "vcnet" }

	files
	{
		"**.h",
		"**.c"
	}	
	
	excludes
	{
		"vcnet/config.h",
	}

	filter "system:windows"
		defines { "_WIN32" }
