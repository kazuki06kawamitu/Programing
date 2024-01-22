#pragma once

#include "SceneBase.h"

class ResultScene :public SceneBase
{
private:
	int back_ground;  //�w�i�摜
	int score;        //�X�R�A
	int enemy_count[3];  //�G�̃J�E���g
	int ememy_image[3];  //�G�摜

public:
	ResultScene();
	virtual ~ResultScene();

	virtual void initialize() override;
	virtual eSceneType Upfate() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:
	void ReadResultData();
};