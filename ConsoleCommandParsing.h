#pragma once

//if cmdRef starts with cmdName (case insensitive), returns true and advances cmdRef past cmdName
bool IsCmd(wchar_t** cmdRef, wchar_t* cmdName)
{
	wchar_t* cmd = *cmdRef;
	int i = 0;
	for (int j = 0; cmdName[j] != '\0'; ++i, ++j)
	{
		if (std::toupper(cmd[i]) != std::toupper(cmdName[j]))
		{
			return false;
		}
	}
	/*while (cmd[i] == ' ' || cmd[i] == '\t')
	{
		++i;
	}*/
	*cmdRef = cmd + i;
	return true;
}