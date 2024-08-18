#pragma once
#include "Const.h"
#include <SFML/Audio.hpp>
class SingeltonSound
{
public:

	~SingeltonSound() = default;
	static SingeltonSound& instance();
	void doSoundEft(const int&);
	void playMusic(const int&);
	void pauseMusic(const int&);

private:
	void loadGameMusic();
	sf::SoundBuffer m_soundEfcBuf[SOUNDS_EFT];
	sf::Sound m_soundEfcts[SOUNDS_EFT];
	SingeltonSound();
	SingeltonSound(const SingeltonSound&) = default;
	SingeltonSound& operator=(const SingeltonSound&) = default;
	sf::Music m_musicGame[MUSIC];

};

