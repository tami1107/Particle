#include "SceneManager.h"
#include <cassert>

#include "SceneTitle.h"
#include "SceneMain.h"
#include "Pad.h"

SceneManager::SceneManager()
{
	m_pScene = nullptr;
}
SceneManager::~SceneManager()
{

}

void SceneManager::init()
{
	m_pScene = new SceneMain;
	m_pScene->init();
}

void SceneManager::end()
{
	assert(m_pScene);
	if (!m_pScene)	return;

	m_pScene->end();
	delete m_pScene;
}

void SceneManager::update()
{
	assert(m_pScene);
	if (!m_pScene)	return;

	// �p�b�h�̃A�b�v�f�[�g����
	Pad::update();

	SceneBase* pScene = m_pScene->update();
	if (pScene != m_pScene)
	{
		// �O�̃V�[���̏I������
		m_pScene->end();
		delete m_pScene;

		m_pScene = pScene;
		m_pScene->init();
	}
}

void SceneManager::draw()
{
	assert(m_pScene);
	if (!m_pScene)	return;
	m_pScene->draw();
}