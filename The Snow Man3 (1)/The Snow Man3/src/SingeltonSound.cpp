#include "SingeltonSound.h"
//

void SingeltonSound::doSoundEft(const int & num)
//==========doSoundEft=============
{
	if(num < SOUNDS_EFT)
		m_soundEfcts[num].play();
}
SingeltonSound& SingeltonSound::instance() 
//===============Singelton=============
{
	static SingeltonSound instance;
	return instance;

}
SingeltonSound::SingeltonSound() 
//===============constructor============
{

	loadGameMusic();

	//===================Buffers===================
	m_soundEfcBuf[SELECT_EFT].loadFromFile("select.wav");
	m_soundEfcBuf[COLLECTED_EFT].loadFromFile("coin.wav");
	m_soundEfcBuf[WIN_EFT].loadFromFile("win.wav");
	m_soundEfcBuf[DEAD_EFT].loadFromFile("dead.wav");
	m_soundEfcBuf[GIFT_EFT].loadFromFile("gift.wav");
	m_soundEfcBuf[COLLECT_AMMO_EFT].loadFromFile("collect_ammo.wav");
	m_soundEfcBuf[SUPER_POWER_EFT].loadFromFile("super_power.wav");
	m_soundEfcBuf[BAD_GIFT_COLLECTED_EFT].loadFromFile("bad_gift.wav");
	m_soundEfcBuf[SHOT_EFT].loadFromFile("shot.wav");
	m_soundEfcBuf[MONEY_BAG_EFT].loadFromFile("collected_money_bag.wav");
	
	//===================Sounds===================
	m_soundEfcts[MONEY_BAG_EFT].setBuffer(m_soundEfcBuf[MONEY_BAG_EFT]);
	m_soundEfcts[SELECT_EFT].setBuffer(m_soundEfcBuf[SELECT_EFT]);
	m_soundEfcts[SHOT_EFT].setBuffer(m_soundEfcBuf[SHOT_EFT]);
	m_soundEfcts[COLLECTED_EFT].setBuffer(m_soundEfcBuf[COLLECTED_EFT]);
	m_soundEfcts[WIN_EFT].setBuffer(m_soundEfcBuf[WIN_EFT]);
	m_soundEfcts[DEAD_EFT].setBuffer(m_soundEfcBuf[DEAD_EFT]);
	m_soundEfcts[GIFT_EFT].setBuffer(m_soundEfcBuf[GIFT_EFT]);
	m_soundEfcts[COLLECT_AMMO_EFT].setBuffer(m_soundEfcBuf[COLLECT_AMMO_EFT]);
	m_soundEfcts[SUPER_POWER_EFT].setBuffer(m_soundEfcBuf[SUPER_POWER_EFT]);
	m_soundEfcts[BAD_GIFT_COLLECTED_EFT].setBuffer(m_soundEfcBuf[BAD_GIFT_COLLECTED_EFT]);
}
void SingeltonSound::playMusic(const int& number) 
//===========playMusic=============
{

	if (number < MUSIC) 
	{
		m_musicGame[number].play();
		m_musicGame[number].setLoop(true);
	}

}
void SingeltonSound::pauseMusic(const int& number) 
//===========pauseMusic=============
{
	if (number < MUSIC) 
		m_musicGame[number].pause();
}
void SingeltonSound::loadGameMusic() 
//=============loadGameMusic========
{
	m_musicGame[GAME_MUSIC].openFromFile("game.wav");
	m_musicGame[MENU_MUSIC].openFromFile("menu.wav");
	m_musicGame[MENU_MUSIC].setVolume(28.f);
	m_musicGame[GAME_MUSIC].setVolume(18.f);
}