#pragma once
#include "SceneBase.h"
#include <memory>


class Particle;
class SceneMain : public SceneBase
{
public:
	// �p�[�e�B�N���̍ő吔
	static constexpr int kParticleMaxNum = 64;


public:
	SceneMain();

	virtual ~SceneMain();


	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

public:

	// �p�[�e�B�N���̐���
	void CreateParticl();

private:

	// �p�[�e�B�N�����o�����ǂ���
	void ParticlSet();

private:
	// �N���X�|�C���^
	std::shared_ptr<Particle>m_pParticle[kParticleMaxNum];

};