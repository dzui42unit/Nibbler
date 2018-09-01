#ifndef NIBBLER_SOUNDWRAPPER_H
#define NIBBLER_SOUNDWRAPPER_H

#include "../libs/sdl/sdl2_mixer/SDL_mixer.h"
#include "../libs/sdl/sdl2/SDL2/SDL_audio.h"
#include "../libs/sdl/sdl2/SDL2/SDL.h"
#include <iostream>

class SoundWrapper
{
private:
	Mix_Music			*bg_music;
	Mix_Chunk 			*eat_sound;
public:
					SoundWrapper();
					~SoundWrapper();
					SoundWrapper(const SoundWrapper &snd);
					SoundWrapper(SoundWrapper &&snd);
	SoundWrapper	&operator=(const SoundWrapper &snd);

	void			playEatSound(void);
	void			playBackgroundMusic(void);
};


#endif //NIBBLER_SOUNDWRAPPER_H
