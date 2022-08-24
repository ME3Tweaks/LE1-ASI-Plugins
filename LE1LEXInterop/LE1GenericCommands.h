#pragma once

#include "../../Shared-ASI/ConsoleCommandParsing.h"

class LE1GenericCommands {
public:
	static bool HandleCommand(char* command)
	{
		// 'CACHEPACKAGE <PackageFileFullPath>'
		// Registers a package so game methods can find it
		if (IsCmd(&command, "CACHEPACKAGE "))
		{
			const auto levelNameStr = string(command);
			auto packName = s2ws(levelNameStr);
			const auto wcharstr = packName.data();

			auto ret = CacheContent(CacheContentWrapperClassPointer, wcharstr, true, true);
			return true;
		}

		// 'CAUSEEVENT <EventName>'
		// Causes a ConsoleEvent to occur in kismet
		if (IsCmd(&command, "CAUSEEVENT "))
		{
			const auto eventName = command;
			//printf(eventName);
			if (const auto player = reinterpret_cast<ABioPlayerController*>(FindObjectOfType(ABioPlayerController::StaticClass())))
			{
				FName foundName;
				StaticVariables::CreateName(s2ws(eventName).c_str(), 0, &foundName);
				player->CauseEvent(foundName);
			}

			return true;
		}

		// 'CAUSEEVENT <EventName>'
		// Causes a ConsoleEvent to occur in kismet
		if (IsCmd(&command, "REMOTEEVENT "))
		{
			const auto eventName = command;
			//printf(eventName);
			if (const auto bioWorldInfo = reinterpret_cast<ABioWorldInfo*>(FindObjectOfType(ABioWorldInfo::StaticClass())))
			{
				FName foundName;
				StaticVariables::CreateName(s2ws(eventName).c_str(), 0, &foundName);
				bioWorldInfo->eventCauseEvent(foundName);
			}
			return true;
		}

		// 'CONSOLECOMMAND <Command String>'
		// Sends a console command to be executed in the context of PlayerController
		if (IsCmd(&command, "CONSOLECOMMAND "))
		{
			const auto conCommand = s2ws(command);
			writeln(L"Console command: %s", conCommand.c_str());

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

			if (const auto player = reinterpret_cast<ASFXPawn_Player*>(FindObjectOfType(ASFXPawn_Player::StaticClass())))
			{
				player->ConsoleCommand(FString(const_cast<wchar_t*>(conCommand.c_str())), false);
			}
			
			return true;
		}

		// 'STREAMLEVELIN <LevelFileName>'
		// Streams a level in and sets it to visible
		if (IsCmd(&command, "STREAMLEVELIN "))
		{
			const auto levelNameStr = command;
			if (const auto cheatMan = reinterpret_cast<UBioCheatManager*>(FindObjectOfType(UBioCheatManager::StaticClass())))
			{
				FName levelName;
				StaticVariables::CreateName(s2ws(levelNameStr).c_str(), 0, &levelName);
				cheatMan->StreamLevelIn(levelName);
			}
			return true;
		}

		// 'STREAMLEVELOUT <LevelFileName>'
		// Streams a level out and removes it from the current level
		if (IsCmd(&command, "STREAMLEVELOUT "))
		{
			const auto levelNameStr = command;
			if (const auto cheatMan = reinterpret_cast<UBioCheatManager*>(FindObjectOfType(UBioCheatManager::StaticClass())))
			{
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