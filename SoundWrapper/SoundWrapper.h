//
// Created by Dmytro Zui on 8/27/18.
//

#ifndef NIBBLER_SOUNDWRAPPER_H
#define NIBBLER_SOUNDWRAPPER_H

#include "../libs/sdl/sdl2_mixer/SDL_mixer.h"
#include "../libs/sdl/sdl2/SDL2/SDL_audio.h"
#include "../libs/sdl/sdl2/SDL2/SDL.h"


class SoundWrapper
{
private:
	Mix_Chunk 			*wave;
public:
					SoundWrapper();
					~SoundWrapper();
					SoundWrapper(const SoundWrapper &snd);
					SoundWrapper(SoundWrapper &&snd);
	SoundWrapper	&operator=(const SoundWrapper &snd);

	void			playEatSound();
};


#endif //NIBBLER_SOUNDWRAPPER_H
