#pragma once
#include "SoundManager.h"



namespace BohgeEngine
{
	class SoundManagerSL : public SoundManager
	{
	public:
		SoundManagerSL(void);
		~SoundManagerSL(void);
	private:
		virtual void _OnCreate( );
		virtual void _OnDestroy( );
	};
}
