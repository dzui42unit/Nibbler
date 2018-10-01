#ifndef NIBBLER_SOUNDWRAPPER_H
#define NIBBLER_SOUNDWRAPPER_H

#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_audio.h"
#include "SDL2/SDL.h"
#include <iostream>
#include "InterfaceSoundLib.h"

class SoundWrapper : public InterfaceSoundLib
{
private:
	Mix_Music			*bg_music;
	Mix_Chunk 			*eat_sound;
	Mix_Chunk			*game_over_sound;
	Mix_Chunk			*bonus_fruit_appears_sound;
public:
					SoundWrapper();
					~SoundWrapper();
					SoundWrapper(const SoundWrapper &snd);
					SoundWrapper(SoundWrapper &&snd);
	SoundWrapper	&operator=(const SoundWrapper &snd);

	void			playEatSound(void) final ;
	void			playBackgroundMusic(void) final ;
	void			playGameOverSound(void) final ;
	void			playBonusFruitAppearsSound(void) final ;
};

extern "C" {
	SoundWrapper      *createSoundWrapper(void);
	void                deleteSoundWrapper(SoundWrapper *lib);
}


#endif //NIBBLER_SOUNDWRAPPER_H
