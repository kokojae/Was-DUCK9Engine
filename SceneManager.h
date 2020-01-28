#pragma once
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static enum Scene
	{
		Main, Intro, Stage1, Stage2, Stage3, Ending, Option
	};

	static Scene current_scene;

	static void LoadScene(Scene scene, bool camera_clear = true);
};
