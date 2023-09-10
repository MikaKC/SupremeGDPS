#include "BrownAlertDelegate.h"

NS_SGDPS_S()

bool BrownAlertDelegate::init(float _w, float _h, float lineSize, const char* _spr, const char* _title) {
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    this->m_pLrSize = CCSize{ _w, _h };

    if (!this->initWithColor({ 0, 0, 0, 105 })) return false;
    this->m_pLayer = CCLayer::create();
    this->addChild(this->m_pLayer);

    auto bg = extension::CCScale9Sprite::create(_spr, { 0.0f, 0.0f, 80.0f, 80.0f });
    bg->setContentSize(this->m_pLrSize);
    bg->setPosition(winSize.width / 2, winSize.height / 2);
    this->m_pLayer->addChild(bg);
    this->m_pBGSprite = bg;

    this->m_pButtonMenu = CCMenu::create();
    this->m_pLayer->addChild(this->m_pButtonMenu, 1);

    if (sizeof _title > 0) {
        auto userName = CCLabelBMFont::create(_title, "bigFont.fnt");
        userName->setPosition({ 0, (m_pLrSize.height / 2) - 22 });
        userName->setScale(0.85f);
        m_pButtonMenu->addChild(userName);

        auto separator = CCSprite::createWithSpriteFrameName("floorLine_001.png");
        separator->setPosition({ 0, (m_pLrSize.height / 2) - 46 });
        separator->setScaleX(lineSize);
        separator->setOpacity(100);
        m_pButtonMenu->addChild(separator);
    }

    setup();

    CCDirector::sharedDirector()->getTouchDispatcher()->incrementForcePrio(2);
    this->registerWithTouchDispatcher();

    auto closeSpr = CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
    closeSpr->setScale(1.0f);

    auto closeBtn = CCMenuItemSpriteExtra::create(
        closeSpr,
        this,
        (SEL_MenuHandler)&BrownAlertDelegate::onClose
    );
    closeBtn->setUserData(reinterpret_cast<void*>(this));

    this->m_pButtonMenu->addChild(closeBtn);

    closeBtn->setPosition(-_w / 2 + 10, _h / 2 - 10);

    this->setKeypadEnabled(true);
    this->setTouchEnabled(true);

    return true;
}

void BrownAlertDelegate::keyDown(enumKeyCodes key) {
    if (key == KEY_Escape)
        return onClose(nullptr);
    if (key == KEY_Space)
        return;

    return FLAlertLayer::keyDown(key);
}

void BrownAlertDelegate::onClose(CCObject* pSender) {
    this->setKeyboardEnabled(false);
    this->removeFromParentAndCleanup(true);
};

NS_SGDPS_E()