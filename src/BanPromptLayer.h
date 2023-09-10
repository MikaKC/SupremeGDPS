#pragma once

#include "BrownAlertDelegate.h"

NS_SGDPS_S()

class SGDPS_DLL BanPromptLayer : public BrownAlertDelegate
{
private:
	CCMenuItemSpriteExtra* _pBanButton;
	ButtonSprite* _pBanButtonSprite;

	// radio buttons
	CCMenuItemSpriteExtra* _pBanToggler;
	CCMenuItemSpriteExtra* _pUnbanToggler;

	bool _pBanTogglerOn;
	bool _pUnbanTogglerOn;

	void onBanButtonPressed(cocos2d::CCObject*);

	void onBanTogglerPressed(cocos2d::CCObject*);
	void onUnbanTogglerPressed(cocos2d::CCObject*);

public:
	void setup() override;

	static BanPromptLayer* create();
};

NS_SGDPS_E()