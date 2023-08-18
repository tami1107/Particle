#include "DxLib.h"

#include "SceneMain.h"
#include "SceneTitle.h"
#include "Pad.h"
#include "Particle.h"


namespace
{
	// パーティクルの量
	constexpr int kParticleVal = 16;

	// パーティクルを出す座標
	constexpr float kParticlePosX = Game::kScreenWidth / 2;
	constexpr float kParticlePosY = Game::kScreenHeight / 2;


}


SceneMain::SceneMain()
{
	// クラスを作成
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

	// パーティクルを出すかどうか
	ParticlSet();


	// パーティクルのアップデート
	for (auto& particle : m_pParticle)
	{
		particle->Update();
	}


	// タイトルに戻る必要がないのでここは処理をしない
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
	// パーティクルを描画
	for (auto& particle : m_pParticle)
	{
		particle->Draw();
	}

	// テキスト描画
	DrawString(0, 0, "パーティクルを出すプログラム", 0xffffff);
	DrawString(0, 15*2, "スペースキーでパーティクルを出す", 0xff0000);

}

void SceneMain::CreateParticl()
{
	// パーティクルカウント
	int particlCount = 0;

	// パーティクルの位置
	Vec2 pos = Vec2(kParticlePosX, kParticlePosY);

	// すべてのパーティクルを見る
	for (auto& particle : m_pParticle)
	{
		// 存在していないパーティクルを探す
		if (!particle->getExist())
		{
			// パーティクルを出す
			particle->Start(pos);

			// パーティクルを出した回数足していく
			particlCount++;
		}

		// パーティクルを出した回数がkParticleValを超えたら処理を終える
		if (particlCount >= kParticleVal)
		{
			// 処理の終了
			return;
		}
	}

	// 処理の終了
	return;
}

void SceneMain::ParticlSet()
{

	// キーを押したとき、パーティクルを出す
	if (Pad::isTrigger(PAD_INPUT_10))
	{
		// パーティクルを出す
		CreateParticl();
	}
}
