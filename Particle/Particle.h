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

	// ˆÊ’uî•ñ‚Ìæ“¾
	void setPos(Vec2 pos) { m_pos = pos; }

	// ‘¶İ‚·‚é‚©‚Ç‚¤‚©‚ğ•Ô‚·
	bool getExist() { return m_isExist; }

private:

	// ˆÚ“®ˆ—
	void Move();

private:

	// ‘¶İ‚·‚é‚©‚Ç‚¤‚©
	bool m_isExist;

	// ˆÊ’uî•ñ
	Vec2 m_pos;

	// ˆÚ“®—Ê
	Vec2 m_vec;
};

