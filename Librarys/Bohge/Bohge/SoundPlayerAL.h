#pragma once
#include "SoundPlayer.h"



namespace BohgeEngine
{
	class SoundPlayerAL : public SoundPlayer
	{
		friend class SoundPlayerFactoryAL;
	private:
		SoundPlayerAL( int hash, int index, SoundResource* res );
		virtual ~SoundPlayerAL(void);
	public:
		virtual void _DoSetVolume( float volume );
		virtual void _DoSetPitch(float pitch);
		virtual void _DoSetPaused( bool ispaused );
		virtual void _DoSetLoop( bool isloop );
		virtual void _DoSetPlay( bool isplay );
		virtual void _DoSet3D( bool is3d );
		virtual void _DoSetSoundPosition( const vector3f& pos, const vector3f& forward, const vector3f& up );
	public:
		virtual void Update();
	};
}
