#include "RankingDispScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

RankingDispScene::RankingdispScene() :background_image(NULL), ranking(nullptr)
{

}

RankingDispScene::~RankingDispScene()
{

}

//����������
void RankingDispScene::Initialize()
{
	//�摜�̓ǂݍ���
	background_image = LoadGraph("Resource/images/Ranking.bmp");

	//�G���[�`�F�b�N
	if (background_image == -1)
	{
		throw("Resource/images/Ranking.bmp������܂���");
	}

	//�����L���O�����擾
	ranking = new RankingData;
	ranking->Initialize();
}

//�X�V����
eSceneType RnkingDispScene::Update()
{
	//B�{�^�������ꂽ��A�^�C�g���ɖ߂�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_TITLE;
	}
	return GetNowScene();
}

//�`�揈��
void RankingDispScene::Finalize()
{
	//�ǂݍ��񂾉摜�̍폜
	DeleteGraph(background_image);

	//���I�������̉���
	ranking->Finalize();
	dalete ranking;
}

//���݂̃V�[�������擾
eSceneType RankingDispScene::GetNowScene() const
{
	return eSceneType::E_RANKING_DISP;
}