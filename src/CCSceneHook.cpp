#include "CCSceneHook.h"
#include "ToolsLayer.h"

NS_SGDPS_S()

void CCSceneHook::ApplyHooks()
{
	auto initHookAddress = GetProcAddress(GetModuleHandleA("libcocos2d.dll"), "?init@CCLayer@cocos2d@@UAE_NXZ");
	matdash::add_hook<&CCSceneHook::initHook>(initHookAddress);
}

bool CCSceneHook::initHook()
{
	if (!matdash::orig<&CCSceneHook::initHook>(this)) return false;

	CCDirector::sharedDirector()->getKeyboardDispatcher()->addDelegate(this);

	return true;
}

void CCSceneHook::keyDown(enumKeyCodes key)
{
	switch (key)
	{
	case enumKeyCodes::KEY_RightContol:
		ToolsLayer::create()->show();
		break;
	}
}

NS_SGDPS_E()