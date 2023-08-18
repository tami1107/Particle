#pragma once
#include "SceneBase.h"
#include <memory>


class Particle;
class SceneMain : public SceneBase
{
public:
	// パーティクルの最大数
	static constexpr int kParticleMaxNum = 64;


public:
	SceneMain();

	virtual ~SceneMain();


	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

public:

	// パーティクルの生成
	void CreateParticl();

private:

	// パーティクルを出すかどうか
	void ParticlSet();

private:
	// クラスポインタ
	std::shared_ptr<Particle>m_pParticle[kParticleMaxNum];

};