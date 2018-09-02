#ifndef NIBBLER_INTERFACESOUNDLIB_H
#define NIBBLER_INTERFACESOUNDLIB_H

class InterfaceSoundLib
{
public:
      InterfaceSoundLib() = default;
    virtual ~InterfaceSoundLib() {};
    InterfaceSoundLib(const InterfaceSoundLib &snd) = delete;
    InterfaceSoundLib(InterfaceSoundLib &&snd) = delete;
    InterfaceSoundLib	&operator=(const InterfaceSoundLib &snd) = delete;

    virtual void			playEatSound(void) = 0;
    virtual void			playBackgroundMusic(void) = 0;
    virtual void			playGameOverSound(void) = 0;
    virtual void			playBonusFruitAppearsSound(void) = 0;
};

#endif //NIBBLER_INTERFACESOUNDLIB_H
