#pragma once
#include "game.h"
#include "Vec2.h"


class Particle
{
public:
	Particle();
	virtual ~Particle();

	void Start(Vec2 pos);
	void Update();
	void Draw();

	// 位置情報の取得
	void setPos(Vec2 pos) { m_pos = pos; }

	// 存在するかどうかを返す
	bool getExist() { return m_isExist; }

private:

	// 移動処理
	void Move();

private:

	// 存在するかどうか
	bool m_isExist;

	// 位置情報
	Vec2 m_pos;

	// 移動量
	Vec2 m_vec;
};

