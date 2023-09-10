#pragma once
#include "BrownAlertDelegate.h"

NS_SGDPS_S()

class SGDPS_DLL ToolsLayer : public BrownAlertDelegate
{
private:
	
	CCMenuItemSpriteExtra* cronButton;
	CCMenuItemSpriteExtra* songAddButton;
	CCMenuItemSpriteExtra* banPromptButton;

	void onCronButtonPressed(cocos2d::CCObject*);
	void onBanPromptButtonPressed(cocos2d::CCObject*);
	void onSongAddButtonPressed(cocos2d::CCObject*);

public:
	void setup() override;

	static ToolsLayer* create();
};

NS_SGDPS_E()

