#include "framework.h"
#include "SoundSystem.h"

SoundSystem::SoundSystem()
{
	Init();
}

SoundSystem::SoundSystem(const string& soundFilePath, bool loop)
	:filePath(soundFilePath), loop(loop)
{
	Init();
}

SoundSystem::~SoundSystem()
{

}

void SoundSystem::Init()
{
	BGMsound = new Sound;
	BGMsoundBuffer = new SoundBuffer;

	if (!BGMsoundBuffer->loadFromFile(filePath))
	{
		cout << " not load sound -" << filePath << endl;
	}

	BGMsound->setBuffer(*BGMsoundBuffer);
	BGMsound->setVolume(this->BGMvolume);
	BGMsound->setLoop(this->loop);
}

void SoundSystem::Destroy()
{
	DELETE(BGMsoundBuffer);
	DELETE(BGMsound);

	for (auto& s : effectSound)
	{
		DELETE(s.second);
	}
	effectSound.clear();

	for (auto& sb : effectSoundBuffer)
	{
		DELETE(sb.second);
	}
	effectSoundBuffer.clear();
}

void SoundSystem::AddEffectSound(const string& soundFilePath, const string& effectName)
{
	effectSound[effectName] = new Sound;
	effectSoundBuffer[effectName] = new SoundBuffer;

	if (!effectSoundBuffer[effectName]->loadFromFile(soundFilePath))
	{
		cout << " not load sound -" << soundFilePath << endl;
	}

	effectSound[effectName]->setBuffer(*effectSoundBuffer[effectName]);
	effectSound[effectName]->setVolume(effectVolume);
	effectSound[effectName]->setLoop(false);

}

void SoundSystem::EffectPlay(const string& effectName)
{
	effectSound[effectName]->play();
}

void SoundSystem::VolumeDown()
{
	if (BGMvolume > 5.f)
	{
		BGMvolume -= this->volumeDistance;
		BGMsound->setVolume(BGMvolume);
	}
}

void SoundSystem::VolumeUp()
{
	if (BGMvolume < 100.f)
	{
		BGMvolume += this->volumeDistance;
		BGMsound->setVolume(BGMvolume);
	}
}

void SoundSystem::EffectVolumeDown()
{
	if (effectVolume > 5.f)
	{
		for (auto& s : effectSound)
		{
			effectVolume -= volumeDistance;
			s.second->setVolume(effectVolume);
		}
	}
}

void SoundSystem::EffectVolumeUp()
{
	if (effectVolume < 100.f)
	{
		for (auto& s : effectSound)
		{
			effectVolume += volumeDistance;
			s.second->setVolume(effectVolume);
		}
	}
}

void SoundSystem::Play()
{
	BGMsound->play();
}

void SoundSystem::Pause()
{
	BGMsound->pause();
}

void SoundSystem::Stop()
{
	BGMsound->stop();
}
