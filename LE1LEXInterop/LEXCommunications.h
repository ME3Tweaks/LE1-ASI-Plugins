#pragma once
class LEXCommunications
{
public:
	static bool ProcessEvent(UObject* Context, UFunction* Function, void* Parms, void* Result)
	{
		const auto className = Context->Class->Name.GetName();
		if (strcmp(className, "SeqAct_SendMessageToLEX") == 0)
		{
			if (strcmp(Function->GetFullName(), "Function Engine.SequenceOp.Activated") == 0)
			{
				const auto op = static_cast<USequenceOp*>(Context);
				SendMessageToLEX(op);
			}
		}
		return false; // Other features will not handle this
	}
};