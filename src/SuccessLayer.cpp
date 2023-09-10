#include "SuccessLayer.h"

NS_SGDPS_S()

void SuccessLayer::setup()
{
	std::map<int, std::string> strings = {
		{ 0, "Cron.php" },
		{ 1, "Song Add" },
		{ 2, "Ban" },
		{ 3, "Unban" }
	};

	auto text = CCLabelBMFont::create(std::format("{} {}!", strings.at(_pRequestID), (_pIconType == 1 ? "ran successfully" : "ran unsuccessfully")).c_str(), "chatFont.fnt");
	text->setPositionY(-44.f);

	auto checkmark = _pIconType == 1 ? CCSprite::createWithSpriteFrameName("GJ_completesIcon_001.png") : CCSprite::createWithSpriteFrameName("exMark_001.png");
	checkmark->setPositionY(-5.f);
	_pIconType == 1 ? checkmark->setScale(1.6f) : checkmark->setScale(1.f);

	m_pButtonMenu->addChild(text);
	m_pButtonMenu->addChild(checkmark);
}

SuccessLayer* SuccessLayer::create(unsigned int requestID, unsigned int iconType)
{
	auto pRet = new (std::nothrow) SuccessLayer(requestID, iconType);
	
	if (pRet && pRet->init(250, 150, 0.5f, "GJ_square02.png", "Success"))
	{
		pRet->autorelease();
		return pRet;
	}
	
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

NS_SGDPS_E()