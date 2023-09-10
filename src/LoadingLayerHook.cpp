#include "LoadingLayerHook.h"

NS_SGDPS_S()

void LoadingLayerHook::loadAssetsHook()
{
	matdash::orig<&LoadingLayerHook::loadAssetsHook>(this);

	CCSpriteFrameCache* sfc = CCSpriteFrameCache::sharedSpriteFrameCache();
	CCTextureCache* tc = CCTextureCache::sharedTextureCache();

	sfc->addSpriteFramesWithFile("GJ_badgeSheet.plist", "GJ_badgeSheet.png");
	sfc->addSpriteFramesWithFile("GJ_badgeSheet-hd.plist", "GJ_badgeSheet-hd.png");
	sfc->addSpriteFramesWithFile("GJ_badgeSheet-uhd.plist", "GJ_badgeSheet-uhd.png");
}

void LoadingLayerHook::ApplyHooks()
{
	matdash::add_hook<&LoadingLayerHook::loadAssetsHook>(base + 0x18c8e0);
}

NS_SGDPS_E()