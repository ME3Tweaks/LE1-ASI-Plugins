#pragma once

class LE1GenericCommands {
public:
	static bool LE1GenericCommands::HandleCommand(char* command)
	{
		// 'CACHEPACKAGE <PackageFileFullPath>'
		// Registers a package so game methods can find it
		if (startsWith("CACHEPACKAGE ", command))
		{
			auto levelNameStr = substr(command, 13, strlen(command) - 13);
			const auto str = string(levelNameStr);
			auto packName = s2ws(str);
			auto wcharstr = packName.data();

			auto ret = CacheContent(CacheContentWrapperClassPointer, wcharstr, true, true);
			return true;
		}

		// 'CAUSEEVENT <EventName>'
		// Causes a ConsoleEvent to occur in kismet
		if (startsWith("CAUSEEVENT ", command))
		{
			auto eventName = substr(command, 11, strlen(command) - 11);
			//printf(eventName);
			auto player = reinterpret_cast<ABioPlayerController*>(FindObjectOfType(ABioPlayerController::StaticClass()));
			if (player)
			{
				FName foundName;
				StaticVariables::CreateName(s2ws(eventName).c_str(), 0, &foundName);
				player->CauseEvent(foundName);
			}

			return true;
		}

		// 'CAUSEEVENT <EventName>'
		// Causes a ConsoleEvent to occur in kismet
		if (startsWith("REMOTEEVENT ", command))
		{
			auto eventName = substr(command, 12, strlen(command) - 12);
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

		// 'CONSOLECOMMAND <Command String>'
		// Sends a console command to be executed in the context of PlayerController
		if (startsWith("CONSOLECOMMAND ", command))
		{
			auto conCommandRaw = substr(command, 15, strlen(command) - 15);
			auto conCommand = const_cast<wchar_t*>(CharToWideMUSTDEALLOCATEAFTERUSE(conCommandRaw));
			writeln(L"Console command: %s", conCommand);

			//printf(eventName);
			/*auto playerController = reinterpret_cast<APlayerController*>(FindObjectOfType(APlayerController::StaticClass()));
			if (playerController)
			{
				playerController->ConsoleCommand(conCommand, false);
			}

			auto console = reinterpret_cast<UConsole*>(FindObjectOfType(UConsole::StaticClass()));
			if (console)
			{
				console->ConsoleCommand(conCommand);
			}

			auto viewport = reinterpret_cast<UGameViewportClient*>(FindObjectOfType(UGameViewportClient::StaticClass()));
			if (viewport)
			{
				viewport->ConsoleCommand(conCommand);
			}*/

			auto player = reinterpret_cast<ASFXPawn_Player*>(FindObjectOfType(ASFXPawn_Player::StaticClass()));
			if (player)
			{
				player->ConsoleCommand(conCommand, false);
			}

			delete[] conCommand;
			return true;
		}

		// 'STREAMLEVELIN <LevelFileName>'
		// Streams a level in and sets it to visible
		if (startsWith("STREAMLEVELIN ", command))
		{
			auto levelNameStr = substr(command, 14, strlen(command) - 14);
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
			auto levelNameStr = substr(command, 15, strlen(command) - 15);
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