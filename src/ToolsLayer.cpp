#include "ToolsLayer.h"

#include "BanPromptLayer.h"
#include "SongAddLayer.h"
#include "SuccessLayer.h"

NS_SGDPS_S()

void ToolsLayer::setup()
{
	auto winSize = CCDirector::sharedDirector()->getVisibleSize();

	cronButton = CCMenuItemSpriteExtra::create(ButtonSprite::create("Cron.php", 120, true, "bigFont.fnt", "GJ_button_05.png", 35, 0.75f), this, (SEL_MenuHandler)(&ToolsLayer::onCronButtonPressed));
	songAddButton = CCMenuItemSpriteExtra::create(ButtonSprite::create("Song Add", 120, true, "bigFont.fnt", "GJ_button_05.png", 35, 0.75f), this, (SEL_MenuHandler)(&ToolsLayer::onSongAddButtonPressed));
	banPromptButton = CCMenuItemSpriteExtra::create(ButtonSprite::create("Ban Prompt", 120, true, "bigFont.fnt", "GJ_button_05.png", 35, 0.75f), this, (SEL_MenuHandler)(&ToolsLayer::onBanPromptButtonPressed));

	cronButton->setPosition(ccp(-70.f, cronButton->getPositionY() + 25));
	songAddButton->setPosition(ccp(-70.f, songAddButton->getPositionY() - 20));
	banPromptButton->setPosition(ccp(-70.f, banPromptButton->getPositionY() - 65));

	m_pButtonMenu->addChild(cronButton, 5);
	m_pButtonMenu->addChild(songAddButton, 5);
	m_pButtonMenu->addChild(banPromptButton, 5);

	auto bgSprite = extension::CCScale9Sprite::create("square02_001.png", { 0, 0, 80, 80 });

	bgSprite->setContentSize({ 297, 158 });
	bgSprite->setOpacity(105);

	bgSprite->setPosition(284.f, 138.f);

	m_pLayer->addChild(bgSprite, 0);
}


void ToolsLayer::onCronButtonPressed(cocos2d::CCObject*)
{
	SuccessLayer::create(0, 0)->show();
}

void ToolsLayer::onBanPromptButtonPressed(cocos2d::CCObject*)
{
	BanPromptLayer::create()->show();
}

void ToolsLayer::onSongAddButtonPressed(cocos2d::CCObject*)
{
	SongAddLayer::create()->show();
}

ToolsLayer* ToolsLayer::create()
{
	auto pRet = new (std::nothrow) ToolsLayer();

	if (pRet && pRet->init(350, 225, 0.75f, "GJ_square02.png", "Tools"))
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

NS_SGDPS_E()