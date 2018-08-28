
#include "SoundWrapper.h"

#include <iostream>

SoundWrapper::SoundWrapper()
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		std::cout << "ERROR: SDL_INIT_AUDIO" << std::endl;
		exit(0);
	}

	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
	{
		std::cout << "ERROR: Mix_OpenAudio" << std::endl;
		exit(0);
	}

	wave = Mix_LoadWAV("sounds/1.wav");
	if (wave == NULL)
	{
		std::cout << "ERROR: Mix_LoadWAV" << std::endl;
		exit(0);
	}

}

SoundWrapper::~SoundWrapper()
{
	if (wave)
		Mix_FreeChunk(wave);
	Mix_CloseAudio();
}

SoundWrapper::SoundWrapper(const SoundWrapper &snd)
{
	wave = snd.wave;
}

SoundWrapper::SoundWrapper(SoundWrapper &&snd)
{
	wave = snd.wave;
	snd.wave = nullptr;
	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096);
}

SoundWrapper	&SoundWrapper::operator=(const SoundWrapper &snd)
{
	wave = snd.wave;
	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096);
	return (*this);
}

void			SoundWrapper::playEatSound(void)
{
	Mix_PlayChannel(-1, wave, 0);
}
