#pragma once

class LE1GenericCommands {
public:
	static bool LE1GenericCommands::HandleCommand(char* command)
	{
		// 'CAUSEEVENT <EventName'
		// Causes an event to occur in kismet
		if (startsWith("CAUSEEVENT ", command))
		{
			auto eventName = substr(command, 11, strlen(command) - 13); // +2 for \r\n
			//printf(eventName);
			auto bioWorldInfo = reinterpret_cast<ABioWorldInfo*>(FindObjectOfType(ABioWorldInfo::StaticClass()));
			if (bioWorldInfo)
			{
				FName foundName;
				StaticVariables::CreateName(s2ws(eventName).c_str(), 0, &foundName);
				bioWorldInfo->eventCauseEvent(foundName);
			}
			return true;
		}

		// 'STREAMLEVELIN <LevelFileName>'
		// Streams a level in and sets it to visible
		if (startsWith("STREAMLEVELIN ", command))
		{
			auto levelNameStr = substr(command, 14, strlen(command) - 16); // +2 for \r\n
			auto cheatManObj = FindObjectOfType(UBioCheatManager::StaticClass());
			if (cheatManObj)
			{
				auto cheatMan = reinterpret_cast<UBioCheatManager*>(cheatManObj);
				FName levelName;
				StaticVariables::CreateName(s2ws(levelNameStr).c_str(), 0, &levelName);
				cheatMan->StreamLevelIn(levelName);
			}
			return true;
		}

		// 'STREAMLEVELOUT <LevelFileName>'
		// Streams a level out and removes it from the current level
		if (startsWith("STREAMLEVELOUT ", command))
		{
			auto levelNameStr = substr(command, 15, strlen(command) - 17); // +2 for \r\n
			auto cheatManObj = FindObjectOfType(UBioCheatManager::StaticClass());
			if (cheatManObj)
			{
				auto cheatMan = reinterpret_cast<UBioCheatManager*>(cheatManObj);
				FName levelName;
				StaticVariables::CreateName(s2ws(levelNameStr).c_str(), 0, &levelName);
				cheatMan->StreamLevelOut(levelName);
			}
			return true;
		}

		// We did not handle this command.
		return false;
	}
};