#pragma once

class LE1LiveLevelEditor
{
public:
	static TArray<UObject*> Actors;
	static AActor* SelectedActor;
	static bool DrawLineToSelected;
private:
	static void DumpActors()
	{
		const auto objCount = UObject::GObjObjects()->Count;
		const auto objArray = UObject::GObjObjects()->Data;

		Actors.Count = 0; //clear the array without de-allocating any memory.

		const auto actorClass = AActor::StaticClass();
		for (auto j = 0; j < objCount; j++)
		{
			auto obj = objArray[j];
			if (obj && obj->IsA(actorClass))
			{
				auto actor = static_cast<AActor*>(obj);
				if (actor) {
					const auto name = actor->Name.GetName();
					if (strstr(name, "Default_"))// || actor->bStatic || !actor->bMovable)
					{
						continue;
					}
					Actors.Add(actor); // We will send them to LEX after we bundle it all up
				}
			}
		}

		// This originally used to count first but that was removed for other design issues

		// Tell LEX we're about to send over an actor list, so it can clear it and be ready for new data.
		SendStringToLEX(L"LIVELEVELEDITOR ACTORDUMPSTART");

		// Send the actor information to LEX
		int numSent = 0;
		for (int i = 0; i < Actors.Count; i++)
		{
			auto actor = static_cast<AActor*>(Actors.Data[i]);
			if (actor)
			{
				// String interps in C++ :/
				std::wstringstream ss2; // This is not declared outside the loop cause otherwise it carries forward
				ss2 << "LIVELEVELEDITOR ACTORINFO ";

				const auto name = actor->Name.GetName();
				ss2 << GetContainingMapName(actor) << ":" << name;
				const auto index = actor->Name.Number;
				if (index > 0)
				{
					ss2 << '_' << index - 1;
				}
				if (actor->bStatic || !actor->bMovable)
				{
					ss2 << ":static";
				}

				numSent++;
				SendStringToLEX(ss2.str());
			}
		}

		// Tell LEX we're done.
		SendStringToLEX(L"LIVELEVELEDITOR ACTORDUMPFINISHED");

		// IDK if this is necessary since we are not depending on the SendMessageToLEX() method
		//for (auto i = 0; i < numVarLinks; i++)
		//{

		//	if (op->VariableLinks(i).LinkedVariables.Count == 0)
		//	{
		//		continue;
		//	}
		//	const auto seqVar = op->VariableLinks(i).LinkedVariables(0);
		//	if (!_wcsnicmp(op->VariableLinks(i).LinkDesc.Data, L"Length", 7) && IsA<USeqVar_Int>(seqVar))
		//	{
		//		const auto lenVar = static_cast<USeqVar_Int*>(seqVar);
		//		lenVar->IntValue = Actors.Count;
		//		break;
		//	}
		//}
	}

	static void AccessDumpedActorsList(USequenceOp* const op)
	{
		const auto numVarLinks = op->VariableLinks.Num();
		int index = 0;
		for (auto i = 0; i < numVarLinks; i++)
		{
			if (op->VariableLinks(i).LinkedVariables.Count == 0)
			{
				continue;
			}
			const auto seqVar = op->VariableLinks(i).LinkedVariables(0);
			if (!_wcsnicmp(op->VariableLinks(i).LinkDesc.Data, L"Index", 5) && IsA<USeqVar_Int>(seqVar))
			{
				const auto idxVar = static_cast<USeqVar_Int*>(seqVar);
				index = idxVar->IntValue;
			}
			if (!_wcsnicmp(op->VariableLinks(i).LinkDesc.Data, L"Output Object", 15) && IsA<USeqVar_Object>(seqVar))
			{
				const auto outputVar = static_cast<USeqVar_Object*>(seqVar);
				if (index >= 0 && index < Actors.Count)
				{
					outputVar->ObjValue = Actors(index);
				}
				else
				{
					outputVar->ObjValue = nullptr;
				}
			}
		}
	}

	// Gets an actor with the specified full name from the specified map file in memory
	static void UpdateSelectedActor(char* mapName, char* actorName) {
		//writeln(L"Selecting act for: %hs", actorName);
		const auto objCount = UObject::GObjObjects()->Count;
		const auto objArray = UObject::GObjObjects()->Data;

		const auto actorClass = AActor::StaticClass();
		for (auto j = 0; j < objCount; j++)
		{
			auto obj = objArray[j];
			if (obj && obj->IsA(actorClass)) {
				auto objMapName = GetContainingMapName(obj);
				if (_strcmpi(mapName, objMapName) != 0)
					continue; // Go to next object.

				auto name = obj->GetFullName(false);
				//writeln(L"%hs", name);
				if (strcmp(actorName, name) == 0)
				{
					SendStringToLEX(L"LIVELEVELEDITOR ACTORSELECTED"); // We have selected an actor
					SelectedActor = static_cast<AActor*>(obj);
					return;
				}
			}
		}

		SendStringToLEX(L"LIVELEVELEDITOR ACTORSELECTED"); // We didn't find an actor but we finished the selection routine.
		SelectedActor = nullptr; // Didn't find!
	}

	static void SendActorData()
	{
		if (SelectedActor) {
			std::wstringstream ss1;
			ss1 << "LIVELEVELEDITOR ACTORLOC " << SelectedActor->Location.X << " " << SelectedActor->Location.Y << " " << SelectedActor->Location.Z;
			SendStringToLEX(ss1.str());

			std::wstringstream ss2;
			ss2 << "LIVELEVELEDITOR ACTORROT " << SelectedActor->Rotation.Pitch << " " << SelectedActor->Rotation.Yaw << " " << SelectedActor->Rotation.Roll;
			SendStringToLEX(ss2.str());

			std::wstringstream ss3;
			ss3 << "LIVELEVELEDITOR ACTORDS3D " << SelectedActor->DrawScale3D.X << " " << SelectedActor->DrawScale3D.Y << " " << SelectedActor->DrawScale3D.Z;
			SendStringToLEX(ss3.str());
		}
	}

	static void SetActorPosition(float x, float y, float z)
	{
		if (SelectedActor) {
			FVector f;
			f.X = x;
			f.Y = y;
			f.Z = z;
			SelectedActor->SetLocation(f);
		}
	}

	static void SetActorRotation(int pitch, int yaw, int roll)
	{
		if (SelectedActor) {
			FRotator f;
			f.Pitch = pitch;
			f.Yaw = yaw;
			f.Roll = roll;
			SelectedActor->SetRotation(f);
		}
	}

	static void SetActorDrawScale3D(float scaleX, float scaleY, float scaleZ)
	{
		if (SelectedActor) {
			FVector f;
			f.X = scaleX;
			f.Y = scaleY;
			f.Z = scaleZ;
			SelectedActor->SetDrawScale3D(f);
		}
	}


	// Parses the input string (starting at pos) and returns the lookup string, also returning the end position
	// (as an offset) from the beginning position of the string.
	static int GetActorInfoFromIDString(char* inputString, char*& outMapName, char*& outFullPath)
	{
		// Parse 2 parts: Filename, ObjectPath
		int mapNameLen = 0;
		while (*(inputString + mapNameLen) != ' ')
		{
			mapNameLen++;
		}

		outMapName = substr(inputString, 0, mapNameLen);

		// Remember to +1 to skip the space.
		int fullPathLen = 0;

		while (*(inputString + mapNameLen + fullPathLen + 1) != ' ')
		{
			fullPathLen++;
		}

		outFullPath = substr(inputString, mapNameLen + 1, fullPathLen);

		return mapNameLen + 1 + fullPathLen; // 'mapName Full.Path.Here'
	}


public:
	// Return true if other features should also be able to handle this function call
	// Return false if other features shouldn't be able to also handle this function call
	static bool ProcessEvent(UObject* Context, UFunction* Function, void* Parms, void* Result)
	{
		if (SelectedActor == nullptr)
			return true; // We have nothing to handle here

		// PostRender
		auto funcName = Function->GetName();
		if (strcmp(funcName, "PostRender") == 0 )
		{
			auto hud = reinterpret_cast<ABioHUD*>(Context);
			if (hud != nullptr)
			{
				hud->FlushPersistentDebugLines(); // Clear it out
				hud->DrawDebugLine(SharedData::cachedPlayerPosition, SelectedActor->Location, 255, 255, 255, TRUE);
			}
		}
		return true;
	}

	// Return true if handled.
	// Return false if not handled.
	static bool HandleCommand(char* command)
	{
		if (startsWith("LLE_TEST_ACTIVE", command))
		{
			// We can receive this command, so we are ready
			SendStringToLEX(L"LIVELEVELEDITOR READY");
			return true;
		}

		if (startsWith("LLE_DUMP_ACTORS", command))
		{
			DumpActors();
			return true;
		}

		//if (startsWith("LLE_GET_ACTOR_POSDATA ", command))
		//{
		//	// This is mega jank
		//	auto commandLen = strlen(command) - 22 - 2; // 22 is command len (plus space), -2 for \r\n
		//	auto remainingCmd = substr(command, 22, commandLen); // string part after the last one
		//	auto splitPos = strstr(remainingCmd, " ");
		//	auto mapName = substr(remainingCmd, 0, splitPos - remainingCmd);
		//	remainingCmd = remainingCmd + (splitPos - remainingCmd) + 1;
		//	auto objName = substr(remainingCmd, 0, strlen(remainingCmd));


		//	SendActorPositionData(mapName, objName);
		//	return true;
		//}

		if (startsWith("LLE_SELECT_ACTOR ", command))
		{
			auto subCommand = command + 17;
			char* mapName = nullptr;
			char* objName = nullptr;
			GetActorInfoFromIDString(subCommand, mapName, objName);
			UpdateSelectedActor(mapName, objName);
			return true;
		}

		if (startsWith("LLE_GET_ACTOR_POSDATA", command))
		{
			SendActorData();
			return true;
		}

		if (startsWith("LLE_UPDATE_ACTOR_POS ", command))
		{
			auto subCommand = command + 21;

			// Get the values
			std::string s = subCommand;
			auto posX = std::stof(s.substr(0, s.find(' ')));
			s = s.substr(s.find(' ') + 1);

			auto posY = std::stof(s.substr(0, s.find(' ')));

			s = s.substr(s.find(' ') + 1);
			auto posZ = std::stof(s.substr(0, s.find(' ')));

			SetActorPosition(posX, posY, posZ);
			return true;
		}

		if (startsWith("LLE_UPDATE_ACTOR_ROT ", command))
		{
			// This is mega jank
			auto subCommand = command + 21;

			std::string s = subCommand;
			auto pitch = std::stoi(s.substr(0, s.find(' ')));
			s = s.substr(s.find(' ') + 1);

			auto yaw = std::stoi(s.substr(0, s.find(' ')));

			s = s.substr(s.find(' ') + 1);
			auto roll = std::stoi(s.substr(0, s.find(' ')));

			SetActorRotation(pitch, yaw, roll);
			return true;
		}

		if (startsWith("LLE_SET_ACTOR_DRAWSCALE3D ", command))
		{
			// This is mega jank
			auto subCommand = command + 26;

			// Get the values
			std::string s = subCommand;
			auto scaleX = std::stof(s.substr(0, s.find(' ')));
			s = s.substr(s.find(' ') + 1);

			auto scaleY = std::stof(s.substr(0, s.find(' ')));

			s = s.substr(s.find(' ') + 1);
			auto scaleZ = std::stof(s.substr(0, s.find(' ')));

			SetActorDrawScale3D(scaleX, scaleY, scaleZ);
			return true;
		}

		return false;
	}
};

// Static variable initialization
TArray<UObject*> LE1LiveLevelEditor::Actors = TArray<UObject*>();
AActor* LE1LiveLevelEditor::SelectedActor = nullptr;
bool LE1LiveLevelEditor::DrawLineToSelected = true;