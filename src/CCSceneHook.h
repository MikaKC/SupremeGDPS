#pragma once
#include "SupremeGDPS.h"

NS_SGDPS_S()

class SGDPS_DLL CCSceneHook : public CCLayer
{
private:
	CCPoint _pFirstTouchPoint;

public:
	bool initHook();

	virtual void keyDown(cocos2d::enumKeyCodes code);

	static void ApplyHooks();
};

NS_SGDPS_E()