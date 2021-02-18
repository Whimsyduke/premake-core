require "mxml"
s = _PREMAKE_VERSION
xml = mxml.LoadFile("C:/Code/GitHub/premake/tests/test.xml", mxml.MXML_OPAQUE_CALLBACK)
success = mxml.SaveFile(xml, "test1.xml", mxml.MXML_NO_CALLBACK)