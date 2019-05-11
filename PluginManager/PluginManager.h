#pragma once
#pragma comment( lib, "bakkesmod.lib" )
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "./imgui/imgui.h"
#include "./bakkesmod/wrappers/PluginManagerWrapper.h"
#include "bakkesmod\plugin\pluginwindow.h"

struct PluginEntry
{
	std::string dllName;
	std::string pluginName;
	std::string version;
	bool loaded = false;
};

class PluginManager : public BakkesMod::Plugin::BakkesModPlugin, public BakkesMod::Plugin::PluginWindow
{
private:
	std::mutex allPluginsVectorMutex;
	std::map<std::string, PluginEntry> allPlugins;
public:
	virtual void onLoad();
	virtual void onUnload();

	/*
	Called whenever a "plugin load/unload/reload" command is executed
	*/
	void OnPluginListUpdated(std::vector<std::string> params);

	/*
	GUI stuff, implementation is in PluginManagerGUI.cpp
	*/
private:
	bool isWindowOpen = false;
	bool isMinimized = false;
	std::string menuTitle = "Plugin manager";
public:
	virtual void Render();
	virtual std::string GetMenuName();
	virtual std::string GetMenuTitle();
	virtual void SetImGuiContext(uintptr_t ctx);
	virtual bool ShouldBlockInput();
	virtual bool IsActiveOverlay();
	virtual void OnOpen();
	virtual void OnClose();
};