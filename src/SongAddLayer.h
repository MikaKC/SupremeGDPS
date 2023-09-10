#pragma once
#include "BrownAlertDelegate.h"

NS_SGDPS_S()

class SGDPS_DLL SongAddLayer : public BrownAlertDelegate
{
private:
	void onSongAddButtonPressed(cocos2d::CCObject*);
public:
	void setup() override;

	static SongAddLayer* create();
};

NS_SGDPS_E()

