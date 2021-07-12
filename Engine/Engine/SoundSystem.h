#pragma once


// BGM, Effect Sound

class SoundSystem final
{
public:

	SoundSystem();
	SoundSystem(const string& soundFilePath, bool loop = false);
	SoundSystem(const SoundSystem&) = delete;
	SoundSystem& operator=(const SoundSystem&) = delete;
	~SoundSystem();

private:

	string filePath{};

	Sound* BGMsound = nullptr;
	SoundBuffer* BGMsoundBuffer = nullptr;

	float BGMvolume = 10.f;
	bool loop = false;

	map<string, Sound*> effectSound;
	map<string, SoundBuffer*> effectSoundBuffer;

	float effectVolume = 15.f;

	const float volumeDistance = 5.f;

private:

	void Init();

public:

	void Destroy();

	void AddEffectSound(const string& soundFilePath, const string& effectName);
	void EffectPlay(const string& effectName);

	void VolumeDown();
	void VolumeUp();

	void EffectVolumeDown();
	void EffectVolumeUp();

	void Play();
	void Pause();
	void Stop();

};

