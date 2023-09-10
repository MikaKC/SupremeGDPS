#pragma once

#include "SupremeGDPS.h"

NS_SGDPS_S()

namespace ModBadgesMod
{
	extern DWORD libcocosbase;

	extern DWORD createMenu;

	extern DWORD createWithSprite;
	extern DWORD createWithSprite_;

	extern DWORD operatorPlus;
	extern DWORD operatorPlus_;

	extern DWORD sharedDirector;
	extern DWORD sharedDirector_;

	extern DWORD retLoadModBadges;
	extern DWORD retLoadModBadges2;
	extern char modBadgesStringChar[20];
	extern DWORD modBadgesString;

	void ApplyHooks();
	extern void writeByte(BYTE* address, BYTE content);
	extern void placeJMP(BYTE* address, DWORD jumpTo, DWORD length);
};

NS_SGDPS_E()