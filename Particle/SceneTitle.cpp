#include "DxLib.h"

#include "SceneTitle.h"
#include "SceneMain.h"
#include "Pad.h"


SceneTitle::SceneTitle() :
	m_isEnd(false)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::init()
{


	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		// Main�ɐ؂�ւ�
		return(new SceneMain);
	}

	return this;
}

void SceneTitle::draw()
{
	DrawString(0, 0, "�^�C�g�����", GetColor(255, 255, 255));
}