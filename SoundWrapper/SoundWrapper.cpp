
#include "SoundWrapper.h"

/*
 *	Default constructor
 */

SoundWrapper::SoundWrapper()
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		std::cout << "ERROR: SDL_INIT_AUDIO" << std::endl;
		exit(0);
	}

	if( Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1 )
	{
		std::cout << "ERROR: Mix_OpenAudio" << std::endl;
		exit(0);
	}

	eat_sound = Mix_LoadWAV("sounds/1.wav");
	if (eat_sound == NULL)
	{
		std::cout << "ERROR: Mix_LoadWAV" << std::endl;
		exit(0);
	}

	bg_music = Mix_LoadMUS("sounds/main.wav");
	if (bg_music == NULL)
	{
		std::cout << "ERROR: Mix_LoadMUS" << std::endl;
		exit(0);
	}

	game_over_sound = 	Mix_LoadWAV("sounds/game_over.wav");
	if (game_over_sound == NULL)
	{
		std::cout << "ERROR: Mix_LoadMUS" << std::endl;
		exit(0);
	}
	Mix_VolumeMusic(20);
}

/*
 *	Destructor that frees all the resources allocated
 */

SoundWrapper::~SoundWrapper()
{
	if (eat_sound)
		Mix_FreeChunk(eat_sound);
	if (bg_music)
		Mix_FreeMusic(bg_music);
	if (game_over_sound)
		Mix_FreeChunk(game_over_sound);
	Mix_CloseAudio();
}

/*
 *	Copy constructor
 */

SoundWrapper::SoundWrapper(const SoundWrapper &snd)
{
	eat_sound = snd.eat_sound;
	bg_music = snd.bg_music;
	game_over_sound = snd.game_over_sound;
}

/*
 * 	Move constructor
 */

SoundWrapper::SoundWrapper(SoundWrapper &&snd)
{
	eat_sound = snd.eat_sound;
	bg_music = snd.bg_music;
	game_over_sound = snd.game_over_sound;
	snd.game_over_sound = nullptr;
	snd.eat_sound = nullptr;
	snd.bg_music = nullptr;
	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096);
}

/*
 *	Copy assignment operator
 */

SoundWrapper	&SoundWrapper::operator=(const SoundWrapper &snd)
{
	eat_sound = snd.eat_sound;
	bg_music = snd.bg_music;
	game_over_sound = snd.game_over_sound;
	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096);
	return (*this);
}

/*
 *	Method that plays eat sound
 */

void			SoundWrapper::playEatSound(void)
{
	Mix_PlayChannel(-1, eat_sound, 0);
}

/*
 *	Method that plays
 */

void			SoundWrapper::playBackgroundMusic(void)
{
	Mix_PlayMusic(bg_music, -1);
}

/*
 *	Method to play game over sound
 */

void			SoundWrapper::playGameOverSound(void)
{
	Mix_HaltMusic();
	Mix_PlayChannel(-1, game_over_sound, 0);
}
