#pragma once

#include "../LE1-SDK/Interface.h"
#include "../LE1-SDK/Common.h"
#include "../LE1-SDK/SdkHeaders.h"

/// <summary>
/// Gets objects in memory of a specific class type. Returns a TArray with objects that can be casted to that type.
/// </summary>
/// <param name="type"></param>
/// <returns></returns>
TArray<UObject*> FindObjectsOfType(UClass* type)
{
	TArray<UObject*> foundObjects;
	const auto objCount = UObject::GObjObjects()->Count;
	const auto objArray = UObject::GObjObjects()->Data;
	for (auto j = 0; j < objCount; j++)
	{
		auto obj = objArray[j];
		if (obj && obj->IsA(type))
		{
			const auto name = obj->Name.GetName();
			if (strstr(name, "Default_"))// || actor->bStatic || !actor->bMovable)
			{
				continue;
			}
			foundObjects.Add(obj);
		}
	}
	return foundObjects;
}

/// <summary>
/// Gets the first object in memory of the specified type. Ensure you check for NULL.
/// </summary>
/// <param name="type"></param>
/// <returns></returns>
UObject* FindObjectOfType(UClass* type)
{
	const auto objCount = UObject::GObjObjects()->Count;
	const auto objArray = UObject::GObjObjects()->Data;
	for (auto j = 0; j < objCount; j++)
	{
		auto obj = objArray[j];
		if (obj && obj->IsA(type))
		{
			const auto name = obj->Name.GetName();
			if (strstr(name, "Default_"))// || actor->bStatic || !actor->bMovable)
			{
				continue;
			}
			return obj;
		}
	}
	return NULL;
}