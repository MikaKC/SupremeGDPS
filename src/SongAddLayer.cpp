#include "SongAddLayer.h"
#include "SuccessLayer.h"

NS_SGDPS_S()

void SongAddLayer::setup()
{
	auto winSize = CCDirector::sharedDirector()->getVisibleSize();

	auto songAddButton = CCMenuItemSpriteExtra::create(ButtonSprite::create("Song Add", 120, true, "goldFont.fnt", "GJ_button_05.png", 40, 1.f), this, (SEL_MenuHandler)(&SongAddLayer::onSongAddButtonPressed));

	songAddButton->setPosition(ccp(0, songAddButton->getPositionY() - 65));

	m_pButtonMenu->addChild(songAddButton, 5);
}

void SongAddLayer::onSongAddButtonPressed(cocos2d::CCObject* sender)
{
	SuccessLayer::create(1, 0)->show();
}

SongAddLayer* SongAddLayer::create()
{
	auto pRet = new (std::nothrow) SongAddLayer();

	if (pRet && pRet->init(330, 195, 0.6f, "GJ_square04.png", "Add song"))
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

NS_SGDPS_E()