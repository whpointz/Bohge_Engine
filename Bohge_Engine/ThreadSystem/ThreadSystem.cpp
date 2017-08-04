//////////////////////////////////////////////////////////////////////////////////////
//
//						The Bohge Engine License (BEL)
//
//	Copyright (c) 2011-2014 Peng Zhao
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in 
//	all copies or substantial portions of the Software. And the logo of 
//	Bohge Engine shall be displayed full screen for more than 3 seconds 
//	when the software is started. Copyright holders are allowed to develop 
//	game edit based on Bohge Engine, The edit must be released under the MIT 
//	open source license if it is going to be published. In no event shall 
//	copyright holders be prohibited from using any code of Bohge Engine 
//	to develop any other analogous game engines.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//
//////////////////////////////////////////////////////////////////////////////////////
#include "Framework/Framework.h"
#include "ThreadSpecific.h"
#include "JobDispatcher.h"
#include "JobThreadPool.h"
#include "ThreadSystem.h"
#include "ThreadRWLock.h"
#include "ThreadMutex.h"
#include "ThreadEvent.h"



using namespace BohgeEngine;

namespace ThreadSystemPlugin
{
	//---------------------------------------------------------------------------------------------------------
	ThreadSystem::ThreadSystem(void)
	{
	}
	//---------------------------------------------------------------------------------------------------------
	ThreadSystem::~ThreadSystem(void)
	{
	}
	//---------------------------------------------------------------------------------------------------------
	void ThreadSystem::RegistEvent( BohgeEngine::Framework& framework )
	{
		framework.RegisterEventListener( FrameworkEvent::ET_RENDER_ON_ENTRY, MEMBER_FUNC_PTR( &ThreadSystem::OnFrameworkEntry ) );
		framework.RegisterEventListener( FrameworkEvent::ET_RENDER_ON_EXIT, MEMBER_FUNC_PTR( &ThreadSystem::OnFrameworkExit ) );
	}
	//---------------------------------------------------------------------------------------------------------
	void ThreadSystem::OnFrameworkEntry( float time, BohgeEngine::Framework& framework )
	{
		JobThreadPool::Create();
	}
	//---------------------------------------------------------------------------------------------------------
	void ThreadSystem::OnFrameworkExit( float time, BohgeEngine::Framework& framework )
	{
		JobThreadPool::Destroy();
	}
	//---------------------------------------------------------------------------------------------------------
	BohgeEngine::IThreadEntity* ThreadSystem::_DoThreadEntityFactory( BohgeEngine::ThreadProperty::EntityType et ) const
	{
		switch( et )
		{
		case ThreadProperty::ET_EVENT: return NEW ThreadEvent;
		case ThreadProperty::ET_MUTEX: return NEW ThreadMutex;
		case ThreadProperty::ET_RWLOCK: return NEW ThreadRWLock;
		case ThreadProperty::ET_JOB_DISPATCHER: return NEW JobDispatcher;
		case ThreadProperty::ET_THREAD_SPECIFIC: return NEW ThreadSpecific;
		default: ASSERT(false); return NULL;
		}
		return NULL;
	}
	//---------------------------------------------------------------------------------------------------------
	void ThreadSystem::_DoRecycleBin( BohgeEngine::IThreadEntity* te ) const
	{
		SAFE_DELETE( te );
	}
}
