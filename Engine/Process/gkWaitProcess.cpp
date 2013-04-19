/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2013 Thomas Trocha

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

#include "Process/gkWaitProcess.h"
#include "gkLogger.h"

gkWaitProcess::gkWaitProcess(gkScalar timeToWait, gkProcessFunction* func) : m_initialTime(timeToWait),m_timeCounter(timeToWait),m_func(func)
{}

gkWaitProcess::~gkWaitProcess()
{
}


bool gkWaitProcess::isFinished()
{
	if (m_timeCounter <= 0)
		return true;
	else
		return false;
}

void gkWaitProcess::init()
{
	m_timeCounter = m_initialTime;
}
void gkWaitProcess::update(gkScalar delta)
{
	m_timeCounter -= delta;
	if (m_func)
		m_func->update(delta);
}


