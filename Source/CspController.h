/*
 *  This file is part of ConPianist. See <https://github.com/hugbug/conpianist>.
 *
 *  Copyright (C) 2018 Andrey Prygunkov <hugbug@users.sourceforge.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class CspController
{
public:
	void Init(AudioDeviceManager* audioDeviceManager, const String& remoteIp);
	void SwitchLocalControl(bool enabled);
	bool UploadSong(const File& file);
	void Play();
	void Pause();
	void Guide(bool enable);
	void StreamLights(bool enable);

private:
	AudioDeviceManager* m_audioDeviceManager;
	String m_remoteIp;

	void SendSysExMessage(const String& command);
	void SendCspMessage(const String& command, const char* category = nullptr);
};
