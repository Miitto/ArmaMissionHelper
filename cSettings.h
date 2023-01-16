#pragma once

#include <wx/wx.h>
#include <bitset>


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
};