#include "cSettings.h"

cSettings* cSettings::mainSettings = nullptr;

cSettings::cSettings() {
	mainSettings = this;
	channels = new ChannelSet();
	hudOptions.set();
}

bool ChannelSet::set(int id, bool chat, bool voice)
{
	switch (id)
	{
	default:
		return false;
	case 0:
		global.chat = chat;
		global.voice = voice;
		break;
	case 1:
		side.chat = chat;
		side.voice = voice;
		break;
	case 2:
		command.chat = chat;
		command.voice = voice;
		break;
	case 3:
		group.chat = chat;
		group.voice = voice;
		break;
	case 4:
		vehicle.chat = chat;
		vehicle.voice = voice;
		break;
	case 5:
		direct.voice = voice;
		break;
	}
	return true;
}
