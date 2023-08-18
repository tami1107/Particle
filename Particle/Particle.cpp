#include "Particle.h"


namespace
{
	// サイズ
	constexpr int kCircleSize = 2;
	// 重力	
	constexpr float kGravity = 0.2f;

	// Y座標の移動制限
	constexpr float kLimitPosY = Game::kScreenHeight;
}

Particle::Particle():
	m_isExist(false),
	m_pos(Vec2()),
	m_vec(Vec2())
{
}

Particle::~Particle()
{
}


void Particle::Start(Vec2 pos)
{
	// 存在を与える
	m_isExist = true;

	// 座標の代入
	m_pos = Vec2(pos);

	// 移動量
	m_vec.x = static_cast<float>(GetRand(6) - 3);
	m_vec.y = static_cast<float>(GetRand(2) - 1);
}

void Particle::Update()
{
	// 存在しなければ処理を行わない
	if (!m_isExist)	return;
	
	// 移動処理
	Move();
}

void Particle::Draw()
{
	// 存在しなければ処理を行わない
	if (!m_isExist)	return;

	// パーティクル描画
	DrawCircle(m_pos.x, m_pos.y, kCircleSize, 0xff0000, false);
}

void Particle::Move()
{
	// 重力を与える
	m_vec.y += kGravity;

	// ベクトルの加算
	m_pos += m_vec;


	if (m_pos.y >= kLimitPosY)
	{
		// 存在を消す
		m_isExist = false;
	}


}
