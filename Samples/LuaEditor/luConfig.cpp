/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2010 harkon.kr

    Contributor(s): none yet.
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/

#include "StdAfx.h"
#include "luConfig.h"

UT_IMPLEMENT_SINGLETON(luConfig)

gkString luConfig::getRuntimePath()
{
#ifdef _DEBUG
#ifdef WIN32
	return getString("app.debug_runtime.win32_path"); 
#else
	return getString("app.debug_runtime.linux_path");
#endif
#else
#ifdef WIN32
	return getString("app.runtime.win32_path"); 
#else
	return getString("app.runtime.linux_path");
#endif
#endif
}

wxColour luConfig::getColor(const gkString& name, const wxColour& defValue)
{
	liIntVec vec = getIntVec(name);
	if (vec.size() != 3)
		return defValue;

	return wxColour(vec[0], vec[1], vec[2]);
}
