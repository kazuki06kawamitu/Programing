#pragma once

#include "../Utility/Vector2D.h"

class barrier
{
private:
	int image;   //バリア画像
	float life_span;  //バリア寿命

public:
	Barrier();
	~Barrier();

	void Draw(const Vector2D& location);  //描画処理
	bool IsFinished(float speed);
};