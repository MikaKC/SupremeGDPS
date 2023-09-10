#pragma once

#include "SupremeGDPS.h"

NS_SGDPS_S()

class SGDPS_DLL MenuLayerHook : public MenuLayer
{
public:
	bool initHook();

	static void ApplyHooks();

	void onOptionsPressed(cocos2d::CCObject* pSender);

};

NS_SGDPS_E()