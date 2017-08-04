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
#pragma once
#include "Framework/FunctionRegister.h"
#include "Framework/IScriptSystem.h"
#include "Framework/ClassRegister.h"
#include "Framework/ScriptValue.h"
#include "UILabel.h"



namespace BGUI
{
	//-------------------------------------------------------------------------------------------------------
	static void UILabel_ReplaceTexture( UILabel* ui, char* path )
	{
		ui->ReplaceTexture( path );
	}
	//-------------------------------------------------------------------------------------------------------
	static void Register_UILabel( BohgeEngine::IScriptSystem& sys )
	{
		BohgeEngine::ClassRegister sc;
		sc.ClassType( &UILabel::RTTI(), &UIWidget::RTTI() );
		{
			BohgeEngine::FunctionRegister sf;
			sf.Arguments( sys, &BohgeEngine::String::RTTI() );
			sf.Function( &BGUI::UILabel_ReplaceTexture, "ReplaceTexture" );
			sc.ClassFunction( sf );
		}
		sys.RegisterClass( sc );
	}
}