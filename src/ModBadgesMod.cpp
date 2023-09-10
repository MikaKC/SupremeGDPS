#include "ModBadgesMod.h"

NS_SGDPS_S()

DWORD ModBadgesMod::libcocosbase = (DWORD)GetModuleHandleA("libcocos2d.dll");

DWORD ModBadgesMod::createMenu = base + 0x18EE0;

DWORD ModBadgesMod::createWithSprite = base + 0x282284;
DWORD ModBadgesMod::createWithSprite_ = (DWORD)createWithSprite;

DWORD ModBadgesMod::operatorPlus = base + 0x282278;
DWORD ModBadgesMod::operatorPlus_ = (DWORD)operatorPlus;

DWORD ModBadgesMod::sharedDirector = base + 0x282270;
DWORD ModBadgesMod::sharedDirector_ = (DWORD)sharedDirector;

DWORD ModBadgesMod::retLoadModBadges = base + 0x211191;
DWORD ModBadgesMod::retLoadModBadges2 = base + 0x5FA2B;
char ModBadgesMod::modBadgesStringChar[20] = "modBadge_01_001.png";
DWORD ModBadgesMod::modBadgesString = (DWORD)modBadgesStringChar;

void ModBadgesMod::placeJMP(BYTE* address, DWORD jumpTo, DWORD length)
{
	DWORD oldProtect, newProtect, relativeAddress;
	VirtualProtect(address, length, PAGE_EXECUTE_READWRITE, &oldProtect);
	relativeAddress = (DWORD)(jumpTo - (DWORD)address) - 5;
	*address = 0xE9;
	*((DWORD*)(address + 0x1)) = relativeAddress;
	for (DWORD x = 0x5; x < length; x++)
	{
		*(address + x) = 0x90;
	}
	VirtualProtect(address, length, oldProtect, &newProtect);
}

void ModBadgesMod::writeByte(BYTE* address, BYTE content)
{
	DWORD oldProtect, newProtect;
	VirtualProtect(address, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
	*address = content;
	VirtualProtect(address, 1, oldProtect, &newProtect);
}

__declspec(naked) void loadModBadges()
{

	__asm {

		pushad
		mov eax, [eax + 0x000001D4]
		add eax, 48
		mov ecx, ModBadgesMod::modBadgesString
		add ecx, 10
		mov[ecx], al
		inc ecx
		mov dword ptr[ecx], 0x3130305F
		popad
		push ModBadgesMod::modBadgesString
		call dword ptr[ModBadgesMod::createWithSprite]
		jmp[ModBadgesMod::retLoadModBadges]

	}
}

__declspec(naked) void loadModBadges2()
{

	__asm {

		pushad
		mov eax, [eax + 0x00000154]
		add eax, 48
		mov ecx, ModBadgesMod::modBadgesString
		add ecx, 10
		mov[ecx], al
		inc ecx
		mov dword ptr[ecx], 0x3130305F
		popad
		push ModBadgesMod::modBadgesString
		call dword ptr[ModBadgesMod::createWithSprite]
		jmp[ModBadgesMod::retLoadModBadges2]

	}
}

__declspec(naked) void loadPointer()
{

	__asm {

		pushad
		mov eax, ModBadgesMod::createWithSprite_
		mov eax, [eax]
		mov[ModBadgesMod::createWithSprite], eax
		mov eax, ModBadgesMod::operatorPlus_
		mov eax, [eax]
		mov[ModBadgesMod::operatorPlus], eax
		mov eax, ModBadgesMod::sharedDirector_
		mov eax, [eax]
		mov[ModBadgesMod::sharedDirector], eax
		popad
		ret

	}
}

void ModBadgesMod::ApplyHooks()
{
	loadPointer();
	placeJMP((BYTE*)gd::base + 0x211187, (DWORD)loadModBadges, 0x5);
	placeJMP((BYTE*)gd::base + 0x5FA21, (DWORD)loadModBadges2, 0x5);
	writeByte((BYTE*)gd::base + 0x49762, 11);
}

NS_SGDPS_E()