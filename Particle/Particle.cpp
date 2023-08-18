#include "Particle.h"


namespace
{
	// �T�C�Y
	constexpr int kCircleSize = 2;
	// �d��	
	constexpr float kGravity = 0.2f;

	// Y���W�̈ړ�����
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
	// ���݂�^����
	m_isExist = true;

	// ���W�̑��
	m_pos = Vec2(pos);

	// �ړ���
	m_vec.x = static_cast<float>(GetRand(6) - 3);
	m_vec.y = static_cast<float>(GetRand(2) - 1);
}

void Particle::Update()
{
	// ���݂��Ȃ���Ώ������s��Ȃ�
	if (!m_isExist)	return;
	
	// �ړ�����
	Move();
}

void Particle::Draw()
{
	// ���݂��Ȃ���Ώ������s��Ȃ�
	if (!m_isExist)	return;

	// �p�[�e�B�N���`��
	DrawCircle(m_pos.x, m_pos.y, kCircleSize, 0xff0000, false);
}

void Particle::Move()
{
	// �d�͂�^����
	m_vec.y += kGravity;

	// �x�N�g���̉��Z
	m_pos += m_vec;


	if (m_pos.y >= kLimitPosY)
	{
		// ���݂�����
		m_isExist = false;
	}


}
