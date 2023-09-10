#include "BanPromptLayer.h"
#include "SuccessLayer.h"

NS_SGDPS_S()

std::string GetSpriteState(bool a)
{
	return a ? "GJ_checkOn_001.png" : "GJ_checkOff_001.png";
}

void BanPromptLayer::setup()
{
	auto winSize = CCDirector::sharedDirector()->getVisibleSize();

	_pBanTogglerOn = true;
	_pUnbanTogglerOn = false;
	
	_pBanButtonSprite = ButtonSprite::create("Ban", 120, true, "goldFont.fnt", "GJ_button_05.png", 40, 1.f);
	_pBanButton = CCMenuItemSpriteExtra::create(_pBanButtonSprite, this, (SEL_MenuHandler)(&BanPromptLayer::onBanButtonPressed));

	_pBanButton->setPosition(ccp(0, _pBanButton->getPositionY() - 65));

	_pBanToggler = CCMenuItemSpriteExtra::create(
		CCSprite::createWithSpriteFrameName(GetSpriteState(this->_pBanTogglerOn).c_str()),
		this, 
		menu_selector(BanPromptLayer::onBanTogglerPressed)
	);

	_pUnbanToggler = CCMenuItemSpriteExtra::create(
		CCSprite::createWithSpriteFrameName(GetSpriteState(this->_pUnbanTogglerOn).c_str()),
		this,
		menu_selector(BanPromptLayer::onUnbanTogglerPressed)
	);

	_pBanToggler->setPosition({-147.f, 42.f});
	_pUnbanToggler->setPosition({ -147.f, 0.f });

	auto banTitle = CCLabelBMFont::create("Ban", "bigFont.fnt", 40.f, CCTextAlignment::kCCTextAlignmentLeft);
	banTitle->setPosition({ 171.f, winSize.height / 2 + 42 });
	banTitle->setScale(0.5f);

	auto unbanTitle = CCLabelBMFont::create("Unban", "bigFont.fnt", 40.f, CCTextAlignment::kCCTextAlignmentLeft);
	unbanTitle->setPosition({ 180.f, winSize.height / 2 });
	unbanTitle->setScale(0.5f);

	m_pLayer->addChild(banTitle);
	m_pLayer->addChild(unbanTitle);

	m_pButtonMenu->addChild(_pBanToggler, 5);
	m_pButtonMenu->addChild(_pUnbanToggler, 5);
	m_pButtonMenu->addChild(_pBanButton, 5);

}

void BanPromptLayer::onBanButtonPressed(cocos2d::CCObject* pSender)
{
	SuccessLayer::create(_pBanTogglerOn ? 2 : 3, 1)->show();
}

void BanPromptLayer::onBanTogglerPressed(cocos2d::CCObject* pSender)
{
	if (_pBanTogglerOn) return;

	_pUnbanTogglerOn = !_pUnbanTogglerOn;
	_pBanTogglerOn = true;
	
	static_cast<CCSprite*>(_pUnbanToggler->getChildren()->objectAtIndex(0))->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(GetSpriteState(this->_pUnbanTogglerOn).c_str()));
	static_cast<CCSprite*>(_pBanToggler->getChildren()->objectAtIndex(0))->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(GetSpriteState(this->_pBanTogglerOn).c_str()));

	_pBanButtonSprite->setString("Ban");

	CC_UNUSED_PARAM(pSender);
}

void BanPromptLayer::onUnbanTogglerPressed(cocos2d::CCObject* pSender)
{
	if (_pUnbanTogglerOn) return;

	_pBanTogglerOn = !_pBanTogglerOn;
	_pUnbanTogglerOn = true;

	static_cast<CCSprite*>(_pUnbanToggler->getChildren()->objectAtIndex(0))->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(GetSpriteState(this->_pUnbanTogglerOn).c_str()));
	static_cast<CCSprite*>(_pBanToggler->getChildren()->objectAtIndex(0))->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(GetSpriteState(this->_pBanTogglerOn).c_str()));

	_pBanButtonSprite->setString("Unban");

	CC_UNUSED_PARAM(pSender);
}

BanPromptLayer* BanPromptLayer::create()
{
	auto pRet = new (std::nothrow) BanPromptLayer();

	if (pRet && pRet->init(350, 225, 0.6f, "GJ_square04.png", "Ban/Unban"))
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

NS_SGDPS_E()