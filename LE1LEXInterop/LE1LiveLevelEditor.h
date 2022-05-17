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
				const auto name = actor->Name.GetName();
				if (strstr(name, "Default_"))// || actor->bStatic || !actor->bMovable)
				{
					continue;
				}
				Actors.Add(actor); // We will send them to LEX after we bundle it all up
			}
		}

		// Tell LEX how many actors we are sending over, so it knows when it's received them all.
		std::wstringstream ss;
		ss << "LIVELEVELEDITOR ACTORDUMPCOUNT " << Actors.Count;
		SendStringToLEX(ss.str());

		// Send the actor information to LEX
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

				SendStringToLEX(ss2.str());
			}
		}

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

		return false;
	}
};

// Static variable initialization
TArray<UObject*> LE1LiveLevelEditor::Actors = TArray<UObject*>();
