#pragma once
#pragma warning(disable: 4251)

#include <matdash.hpp>
#include <matdash/minhook.hpp>

#include <Windows.h>
#include <iostream>
#include <vector>
#include <functional>

#include <gd.h>

// namespaces
using namespace cocos2d;
using namespace gd;

#define USING_SUPREME() using namespace SupremeGDPS
#define NS_SGDPS_S() namespace SupremeGDPS {
#define NS_SGDPS_E() }

#define EXPORT_SUPREME

#ifdef EXPORT_SUPREME
	#define SGDPS_DLL	__declspec(dllexport)
#else
	#define SGDPS_DLL	__declspec(dllimport)
#endif
