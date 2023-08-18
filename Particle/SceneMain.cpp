#include "DxLib.h"

#include "SceneMain.h"
#include "SceneTitle.h"
#include "Pad.h"
#include "Particle.h"


namespace
{
	// �p�[�e�B�N���̗�
	constexpr int kParticleVal = 16;

	// �p�[�e�B�N�����o�����W
	constexpr float kParticlePosX = Game::kScreenWidth / 2;
	constexpr float kParticlePosY = Game::kScreenHeight / 2;


}


SceneMain::SceneMain()
{
	// �N���X���쐬
	for (auto& particle : m_pParticle)
	{
		particle = std::make_shared<Particle>();
	}
}

SceneMain::~SceneMain()
{
}

void SceneMain::init()
{
}

SceneBase* SceneMain::update()
{

	// �p�[�e�B�N�����o�����ǂ���
	ParticlSet();


	// �p�[�e�B�N���̃A�b�v�f�[�g
	for (auto& particle : m_pParticle)
	{
		particle->Update();
	}


	// �^�C�g���ɖ߂�K�v���Ȃ��̂ł����͏��������Ȃ�
#if false
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		return (new SceneTitle);
	}
#endif

	return this;
}

void SceneMain::draw()
{
	// �p�[�e�B�N����`��
	for (auto& particle : m_pParticle)
	{
		particle->Draw();
	}

	// �e�L�X�g�`��
	DrawString(0, 0, "�p�[�e�B�N�����o���v���O����", 0xffffff);
	DrawString(0, 15*2, "�X�y�[�X�L�[�Ńp�[�e�B�N�����o��", 0xff0000);

}

void SceneMain::CreateParticl()
{
	// �p�[�e�B�N���J�E���g
	int particlCount = 0;

	// �p�[�e�B�N���̈ʒu
	Vec2 pos = Vec2(kParticlePosX, kParticlePosY);

	// ���ׂẴp�[�e�B�N��������
	for (auto& particle : m_pParticle)
	{
		// ���݂��Ă��Ȃ��p�[�e�B�N����T��
		if (!particle->getExist())
		{
			// �p�[�e�B�N�����o��
			particle->Start(pos);

			// �p�[�e�B�N�����o�����񐔑����Ă���
			particlCount++;
		}

		// �p�[�e�B�N�����o�����񐔂�kParticleVal�𒴂����珈�����I����
		if (particlCount >= kParticleVal)
		{
			// �����̏I��
			return;
		}
	}

	// �����̏I��
	return;
}

void SceneMain::ParticlSet()
{

	// �L�[���������Ƃ��A�p�[�e�B�N�����o��
	if (Pad::isTrigger(PAD_INPUT_10))
	{
		// �p�[�e�B�N�����o��
		CreateParticl();
	}
}
