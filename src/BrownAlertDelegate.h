#pragma once

#include "SupremeGDPS.h"

NS_SGDPS_S()

class SGDPS_DLL BrownAlertDelegate : public FLAlertLayer
{
protected:
    CCSize m_pLrSize;
    extension::CCScale9Sprite* m_pBGSprite;

    virtual bool init(
        float width,
        float height,
        float lineSize = 0.75f,
        const char* bg = "GJ_square01.png",
        const char* title = ""
    );
    virtual void setup() = 0;
    virtual void keyDown(cocos2d::enumKeyCodes) override;

    virtual void onClose(cocos2d::CCObject*);
};

NS_SGDPS_E()

