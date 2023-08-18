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

	// �ʒu���̎擾
	void setPos(Vec2 pos) { m_pos = pos; }

	// ���݂��邩�ǂ�����Ԃ�
	bool getExist() { return m_isExist; }

private:

	// �ړ�����
	void Move();

private:

	// ���݂��邩�ǂ���
	bool m_isExist;

	// �ʒu���
	Vec2 m_pos;

	// �ړ���
	Vec2 m_vec;
};

