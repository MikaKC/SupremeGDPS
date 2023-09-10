#pragma once
#include "SupremeGDPS.h"

NS_SGDPS_S()

class SGDPS_DLL LoadingLayerHook : public LoadingLayer
{
public:

	void loadAssetsHook();

	static void ApplyHooks();
};

NS_SGDPS_E()

