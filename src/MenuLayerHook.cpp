#include "MenuLayerHook.h"
#include "ToolsLayer.h"

NS_SGDPS_S()

bool MenuLayerHook::initHook()
{
	if (!matdash::orig<&MenuLayerHook::initHook>(this)) return false;

	auto winSize = CCDirector::sharedDirector()->getVisibleSize();
	auto optionsMenu = CCMenu::create();

	optionsMenu->setPosition({ winSize.width - 30, winSize.height - 30 });
	
	auto toolsButton = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png"), this, (SEL_MenuHandler)(&MenuLayerHook::onOptionsPressed));
	optionsMenu->addChild(toolsButton);

	this->addChild(optionsMenu);

	return true;
}

void MenuLayerHook::onOptionsPressed(CCObject* pSender)
{
	ToolsLayer::create()->show();
}

void MenuLayerHook::ApplyHooks()
{
	matdash::add_hook<&MenuLayerHook::initHook>(base + 0x1907B0);
	std::cout << "Hooked MenuLayer::init" << std::endl;
}

NS_SGDPS_E()