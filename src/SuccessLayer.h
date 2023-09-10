#pragma once

#include "BrownAlertDelegate.h"

NS_SGDPS_S()

class SGDPS_DLL SuccessLayer : public BrownAlertDelegate
{
private:
	unsigned int _pRequestID;
	unsigned int _pIconType;

public:
	SuccessLayer(unsigned int requestID, unsigned int iconType) : _pRequestID(requestID), _pIconType(iconType) { }
	~SuccessLayer() { }

	void setup() override;

	static SuccessLayer* create(unsigned int requestID, unsigned int iconType);
};

NS_SGDPS_E()