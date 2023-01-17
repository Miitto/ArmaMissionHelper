#pragma once

#include <wx/wx.h>
#include <bitset>

#include "cLoadout.h"

class Channel {
public:
	Channel(int i = 0, bool c = true, bool v = true) {
		id = i;
		chat = c;
		voice = v;
	}
	void disableChat() {
		chat = false;
	}
	void enableChat() {
		chat = true;
	}
	void toggleChat() {
		chat = !chat;
	}
	void disableVoice() {
		voice = false;
	}
	void enableVoice() {
		voice = true;
	}
	void toggleVoice() {
		voice = !voice;
	}

	int id;
	bool chat;
	bool voice;
};

class ChannelSet {
public:
	Channel global = Channel(0, true, true);
	Channel side = Channel(1, true, true);
	Channel command = Channel(2, true, true);
	Channel group = Channel(3, true, true);
	Channel vehicle = Channel(4, true, true);
	Channel direct = Channel(5, false, true);

	bool set(int id, bool chat, bool voice);
};

class cSettings
{
public:

	cSettings();
	static cSettings* mainSettings;

	static cSettings* getMain() {
		return mainSettings;
	}


	// Vars
	wxString gameType = "COOP";
	int minPlayers = 1;
	int maxPlayers = 30;

	int respawnType = 3;
	int respawnOnStart = -1;

	std::bitset<11> hudOptions;

	bool showMap = false;
	int corpseMode = 2;

	bool disableAI = true;

	int adminConsole = 1;

	ChannelSet* channels;

	bool showCompass = true;
	bool showGPS = true;
	bool showWatch = true;
	bool groupIndicator = false;
	bool showUAVFeed = true;
	bool aiKills = false;

	int corpseLimit = 15;
	int corpseMinTime = 10;
	int corpseMaxTime = 3600;

	int wreckMode = 2;
	int wreckLimit = 15;
	int wreckMinTime = 10;
	int wreckMaxTime = 36000;

	int minPlayerDistance = 0;

	bool respawnButton = true;

	bool respawnDialog = true;

	int respawnDelay = 5;
	int vehRespawnDelay = 5;

	int reviveMode = 0;
	int damageModel = 0;

	bool medicNeeded = false;
	bool fakConsumed = true;

	int reviveItem = 2;
	int reviveTime = 6;
	int medicMult = 2;
	int forceRespawnDelay = 3;
	int bleedOutTime = 120;

	cLoadoutDir* loadouts;
};