#include "GameMainScene.h"
#include "../Object/RankingData.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene() : high_score(0), back_ground(NULL),
barrier_image(NULL), mileage(0), player(nullptr),

enemy(nullptr)
{
	for (int i = 0; i < 3; i++)
	{
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
}

 GameMainSceneScene::~GaneMainscene()
{

}

 //����������
 void GameMainScene::Initialize()
 {
	 //�����_�l��ǂݍ���
	 ReadHighScore();

	 //�摜�̓ǂݍ���
	 back_ground = LoadGraph("Resource/images/back.bmp");
	 barrier_image = LoadGraph("Resource/images/barrier.png");
	 int result = LoadDivGraph("Resource/miages/car.bmp", 3, 3, 1, 63, 120, enemy_image);

	 //�G���[�`�F�b�N
	 if (back_ground == -1)
	 {
		 throw("Resource/images/back.bmp������܂���\n");
	 }

	 if (result == -1)
	 {
		 throw("Resource / images / car.bmp������܂���\n");
	 }

	 if (barrier_image == -1)
	 {
		 throw("Resource/images/barrier.png������܂���\n");
	 }

	 //�I�u�W�F�N�g�̐���
	 player = new Player;
	 enemy = new Enemy * [10];

	 //�I�u�W�F�N�g�̏�����
	 player->Initialize();

	 for (int i = 0; i < 10; i++)
	 {
		 enemy[i] = nullptr;
	 }
 }

 //�X�V����
 eSceneType GameMainScene::Update()
 {
	 //�v���C���[�̍X�V
	 player->Update();

	 //�ړ������̍X�V
	 mileage += (int)player->GetSpeed
	 () + 5;

	 //�G��������
	 if (mileage / 20 % 100 == 0)
	 {
		 for (int i = 0; i < 10; i++)
		 {
			 if (enemy[i] = nullptr)
			 {
				 int type = GetRand(3) % 3;
				 enemy[i] = new enemy(type, enemy_image[type]);
				 enemy[i]->Initialize();
				 break;
			 }
		 }
	 }
	 //�Ă��̍X�V�Ɠ����蔻��`�F�b�N
	 for (int i = 0; i < 10; i++)
	 {
		 if (enemy[i] != nullptr)
		 {
			 enemy[i]->Update(player->GetSpeed());

			 //��ʊO�Ɍ�������A�G���폜���ăX�R�A���Z
			 if (enemy[i]->GetLocation().y >= 640.0f)
			 {
				 enemy_count[enemy[i]->Gettype()]++;
				 enemy[i]->Finalize();
				 delete enemy[i];
				 enemy[i] = nullptr;
			 }
			 //�����蔻��̊m�F
			 if (IsHitCheck(player, enemy[i]))
			 {
				 player->SetActive(false);
				 player->DecreaseHp(-50.0f);
				 emey[i]->Finalize();
				 delete enemy[i];
				 enemy[i] = nullptr;
			 }
		 }
	 }

	 //�v���C���[�̔R�����̗͂��O�����Ȃ�A���U���g�ɑJ�ڂ���
	 if (player->getFuel() < 0.0f || player->gethHp() < 0.0f)
	 {
		 return eScenetype::E_RESULT;
	 }
	 return GetNowScene();
 }

 //�`�揈��
 void GameMainScene::Draw() const
 {
	 //�w�i�`��̕`��
	 DrawGraph(0, mileage % 480 - 480, back_ground, TRUE);
	 DrawGraph(0, mileage % 480, back_ground, TRUE);

	 //�G�̕`��
	 for (int i = 0; i < 10; i++)
	 {
		 if (enemy[i] != nullptr)
		 {
			 enemy[i]->Draw();
		 }
	 }

	 //�v���C���[�̕`��
	 player->Draw();

	 //UI�̕`��
	 DrawBox(500, 0, 640, 480, GetColor(0, 130, 0), TRUE);
	 SetFontsize(16);
	 DrawFormatString(510, 20, GetColor(0, 0, 0), "�n�C�X�R�A");
	 DrawFormatString(560, 40, GetColor(255, 255, 255), "%08d", high_score);
	 DrawFormatString(510, 80, GetColor(0, 0, 0), "��������");
	 for (int i = 0; i < 3; i++)
	 {
		 DrawRotaGraph(523 + (i * 50), 120, 0.3, 0, enemy_image[i], TRUE, FALSE);
		 DrawFormatString(510 + (i * 50), 140, GetColor(255, 255, 255), "%03d", enemy_count[i]);
	 }
	 DrawformatString(510, 200, GetColor(0, 0, 0), "���s����");
		
 }