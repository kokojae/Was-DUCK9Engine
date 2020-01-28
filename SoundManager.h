#pragma once
class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	static void PlayBGM(std::wstring path)
	{
		std::wstring strTemp;

		mciSendString(L"close BGM", NULL, NULL, NULL);
		strTemp = L"open " + path + L" type mpegvideo alias BGM";
		mciSendString(strTemp.c_str(), NULL, NULL, NULL);
		mciSendString(L"play BGM notify repeat", NULL, NULL, NULL);
	}

	static void PlaySFX(std::wstring path)
	{
		PlaySound(path.c_str(), NULL, SND_ASYNC);
	}
};

