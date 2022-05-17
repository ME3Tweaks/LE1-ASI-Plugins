#pragma once

class LE1LiveLevelEditor
{
public:
	static TArray<UObject*> Actors;

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

	static void SendActorPositionData(char* mapName, char* actorName)
	{
		writeln(L"Looking for: %hs", actorName);
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
				writeln(L"%hs", name);
				if (strcmp(actorName, name) == 0)
				{
					auto actor = static_cast<AActor*>(obj);
					std::wstringstream ss1;
					ss1 << "LIVELEVELEDITOR ACTORLOC " << actor->Location.X << " " << actor->Location.Y << " " << actor->Location.Z;
					SendStringToLEX(ss1.str());

					std::wstringstream ss2;
					ss2 << "LIVELEVELEDITOR ACTORROT " << actor->Rotation.Pitch << " " << actor->Rotation.Yaw << " " << actor->Rotation.Roll;
					SendStringToLEX(ss2.str());
				}
			}
		}
	}

public:
	// Return false if other features shouldn't be able to also handle this function call
	// Return true if other features should also be able to handle this function call
	static bool ProcessEvent(UObject* Context, UFunction* Function, void* Parms, void* Result)
	{
		auto className = Context->GetName();
		/*if (strcmp(className, "SeqAct_LEXDumpActors") == 0)
		{
			if (!strcmp(Function->GetFullName(), "Function Engine.SequenceOp.Activated"))
			{
				const auto op = static_cast<USequenceOp*>(Context);
				DumpActors(op);
			}
		}
		else*/
		if (strcmp(className, "SeqAct_LEXAccessDumpedActorsList") == 0)
		{
			// What is this used for? -Mgamerz
			if (!strcmp(Function->GetFullName(), "Function Engine.SequenceOp.Activated"))
			{
				const auto op = static_cast<USequenceOp*>(Context);
				AccessDumpedActorsList(op);
				return false;
			}
		}
		/*else if (strcmp(className, "SeqAct_LEXGetPlayerCamPOV") == 0)
		{
			if (strcmp(Function->GetFullName(), "Function Engine.SequenceOp.Activated") == 0)
			{
				const auto op = static_cast<USequenceOp*>(Context);
				GetCamPOV(op);
				return false;
			}
		}*/
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

		if (startsWith("LLE_GET_ACTOR_POSDATA ", command))
		{
			// This is mega jank
			auto commandLen = strlen(command) - 22 - 2; // 22 is command len (plus space), -2 for \r\n
			auto remainingCmd = substr(command, 22, commandLen); // string part after the last one
			auto splitPos = strstr(remainingCmd, " ");
			auto mapName = substr(remainingCmd, 0, splitPos - remainingCmd);
			remainingCmd = remainingCmd + (splitPos - remainingCmd) + 1;
			auto objName = substr(remainingCmd, 0, strlen(remainingCmd));


			SendActorPositionData(mapName, objName);
			return true;
		}

		return false;
	}
};

// Static variable initialization
TArray<UObject*> LE1LiveLevelEditor::Actors = TArray<UObject*>();
