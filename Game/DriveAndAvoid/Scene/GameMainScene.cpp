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

 //初期化処理
 void GameMainScene::Initialize()
 {
	 //高得点値を読み込む
	 ReadHighScore();

	 //画像の読み込み
	 back_ground = LoadGraph("Resource/images/back.bmp");
	 barrier_image = LoadGraph("Resource/images/barrier.png");
	 int result = LoadDivGraph("Resource/miages/car.bmp", 3, 3, 1, 63, 120, enemy_image);

	 //エラーチェック
	 if (back_ground == -1)
	 {
		 throw("Resource/images/back.bmpがありません\n");
	 }

	 if (result == -1)
	 {
		 throw("Resource / images / car.bmpがありません\n");
	 }

	 if (barrier_image == -1)
	 {
		 throw("Resource/images/barrier.pngがありません\n");
	 }

	 //オブジェクトの生成
	 player = new Player;
	 enemy = new Enemy * [10];

	 //オブジェクトの初期化
	 player->Initialize();

	 for (int i = 0; i < 10; i++)
	 {
		 enemy[i] = nullptr;
	 }
 }

 //更新処理
 eSceneType GameMainScene::Update()
 {
	 //プレイヤーの更新
	 player->Update();

	 //移動距離の更新
	 mileage += (int)player->GetSpeed
	 () + 5;

	 //敵生成処理
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
	 //てきの更新と当たり判定チェック
	 for (int i = 0; i < 10; i++)
	 {
		 if (enemy[i] != nullptr)
		 {
			 enemy[i]->Update(player->GetSpeed());

			 //画面外に言ったら、敵を削除してスコア加算
			 if (enemy[i]->GetLocation().y >= 640.0f)
			 {
				 enemy_count[enemy[i]->Gettype()]++;
				 enemy[i]->Finalize();
				 delete enemy[i];
				 enemy[i] = nullptr;
			 }
			 //当たり判定の確認
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

	 //プレイヤーの燃料か体力が０未満なら、リザルトに遷移する
	 if (player->getFuel() < 0.0f || player->gethHp() < 0.0f)
	 {
		 return eScenetype::E_RESULT;
	 }
	 return GetNowScene();
 }

 //描画処理
 void GameMainScene::Draw() const
 {
	 //背景描画の描画
	 DrawGraph(0, mileage % 480 - 480, back_ground, TRUE);
	 DrawGraph(0, mileage % 480, back_ground, TRUE);

	 //敵の描画
	 for (int i = 0; i < 10; i++)
	 {
		 if (enemy[i] != nullptr)
		 {
			 enemy[i]->Draw();
		 }
	 }

	 //プレイヤーの描画
	 player->Draw();

	 //UIの描画
	 DrawBox(500, 0, 640, 480, GetColor(0, 130, 0), TRUE);
	 SetFontsize(16);
	 DrawFormatString(510, 20, GetColor(0, 0, 0), "ハイスコア");
	 DrawFormatString(560, 40, GetColor(255, 255, 255), "%08d", high_score);
	 DrawFormatString(510, 80, GetColor(0, 0, 0), "避けた数");
	 for (int i = 0; i < 3; i++)
	 {
		 DrawRotaGraph(523 + (i * 50), 120, 0.3, 0, enemy_image[i], TRUE, FALSE);
		 DrawFormatString(510 + (i * 50), 140, GetColor(255, 255, 255), "%03d", enemy_count[i]);
	 }
	 DrawformatString(510, 200, GetColor(0, 0, 0), "走行距離");
		
 }