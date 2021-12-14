#pragma once
#include <fstream>
#include <ostream>
#include <streambuf>
#include <sstream>
#include "../LE1-SDK/SdkHeaders.h"

/// <summary>
/// Abstract class for creating custom HUDs similar to StreamingLevelsHUD
/// </summary>
class CustomHUD
{
public:
	bool ShouldDraw = true;
	CustomHUD(LPSTR windowName = "MassEffect")
	{
		_windowName = windowName;
	}
	virtual void Update(UCanvas* canvas)
	{
		_canvas = canvas;
	}
	virtual void Draw() = 0;

protected:
	UCanvas* _canvas;
	float textScale = 1.0f;
	float lineHeight = 12.0f;
	int yIndex;
	LPSTR _windowName;
	void SetTextScale()
	{
		HWND activeWindow = FindWindowA(NULL, _windowName);
		if (activeWindow)
		{
			RECT rcOwner;
			if (GetWindowRect(activeWindow, &rcOwner))
			{
				long width = rcOwner.right - rcOwner.left;
				long height = rcOwner.bottom - rcOwner.top;

				if (width > 2560 && height > 1440)
				{
					textScale = 2.0f;
				}
				else if (width > 1920 && height > 1080)
				{
					textScale = 1.5f;
				}
				else
				{
					textScale = 1.0f;
				}
				lineHeight = 12.0f * textScale;
			}
		}
	}

	void RenderText(std::wstring msg, const float x, const float y, const char r, const char g, const char b, const float alpha)
	{
		if (_canvas)
		{
			_canvas->SetDrawColor(r, g, b, alpha * 255);
			_canvas->SetPos(x, y + 64); //+ is Y start. To prevent overlay on top of the power bar thing
			_canvas->DrawTextW(FString{ const_cast<wchar_t*>(msg.c_str()) }, 1, textScale, textScale, nullptr);
		}
	}

	void RenderTextLine(std::wstring msg, const char r, const char g, const char b, const float alpha)
	{
		RenderText(msg, 5, lineHeight * yIndex, r, g, b, alpha);
		yIndex++;
	}

	void RenderName(const wchar_t* label, FName name)
	{
		wchar_t output[512];
		swprintf_s(output, 512, L"%s: %S", label, name.GetName());
		RenderTextLine(output, 0, 255, 0, 1.0f);
	}

	void RenderString(const wchar_t* label, FString str)
	{
		wchar_t output[512];
		swprintf_s(output, 512, L"%s: %s", label, str.Data);
		RenderTextLine(output, 0, 255, 0, 1.0f);
	}

	void RenderInt(const wchar_t* label, int value)
	{
		wchar_t output[512];
		swprintf_s(output, 512, L"%s: %d", label, value);
		RenderTextLine(output, 0, 255, 0, 1.0f);
	}

	void RenderBool(const wchar_t* label, bool value)
	{
		wchar_t output[512];
		if (value)
		{
			swprintf_s(output, 512, L"%s: %s", label, L"True");
		}
		else
		{
			swprintf_s(output, 512, L"%s: %s", label, L"False");
		}
		RenderTextLine(output, 0, 255, 0, 1.0f);
	}
};

class AppearanceHUD : public CustomHUD
{
public:
	AppearanceHUD() : CustomHUD("MassEffect") { }

	void Update(UCanvas* canvas, ABioPawn* pawn)
	{
		__super::Update(canvas);
		_pawn = pawn;
	}

	void Draw() override
	{
		if (!ShouldDraw) return;

		SetTextScale();
		yIndex = 3;

		RenderTextLine(L"Appearance Profile", 255, 229, 0, 1.0f);
		if (_pawn)
		{
			RenderName(L"Pawn Name", _pawn->Name);
			auto aType = _pawn->m_oBehavior->m_oActorType;
			if (aType)
			{
				RenderString(L"Actor Game Name", aType->ActorGameName);
			}
			yIndex++;
			RenderMeshSection();
			if (aType && aType->IsA(UBioPawnChallengeScaledType::StaticClass()))
			{
				yIndex++;
				RenderAppearanceSection(static_cast<UBioPawnChallengeScaledType*>(aType), _pawn->m_oBehavior->m_oAppearanceType);
			}
		}
		else
		{
			RenderTextLine(L"In Mako", 0, 255, 0, 1.0f);
		}
	}
private:
	ABioPawn* _pawn;

	void RenderMeshSection()
	{
		RenderTextLine(L"Meshes:", 255, 229, 0, 1.0f);
		if (_pawn->m_oHairMesh)
		{
			RenderName(L"Hair Mesh", _pawn->m_oHairMesh->SkeletalMesh->Name);
		}
		if (_pawn->m_oHeadMesh)
		{
			RenderName(L"Head Mesh", _pawn->m_oHeadMesh->SkeletalMesh->Name);
		}
		if (_pawn->m_oHeadGearMesh)
		{
			RenderName(L"Head Gear Mesh", _pawn->m_oHeadGearMesh->SkeletalMesh->Name);
		}
		if (_pawn->m_oFacePlateMesh)
		{
			RenderName(L"Face Plate Mesh", _pawn->m_oFacePlateMesh->SkeletalMesh->Name);
		}
		if (_pawn->m_oVisorMesh)
		{
			RenderName(L"Visor Mesh", _pawn->m_oVisorMesh->SkeletalMesh->Name);
		}
	}

	void RenderAppearanceSection(UBioPawnChallengeScaledType* type, UBioInterface_Appearance* interfaceAppr)
	{
		auto appearance = type->m_oAppearance;
		auto body = appearance->Body;
		auto headGear = body->m_oHeadGearAppearance;
		auto headGearSettings = headGear->m_oSettings;

		auto iApprPawn = reinterpret_cast<UBioInterface_Appearance_Pawn*>(interfaceAppr);

		RenderTextLine(L"Bio_Appr_Character:", 255, 229, 0, 1.0f);
		RenderName(L"Headgear Prefix:", headGear->m_nmPrefix);
		if (iApprPawn)
		{
			auto armorSpecIdx = iApprPawn->m_oSettings->m_oBodySettings->m_eArmorType;
			RenderInt(L"Armor Spec Index", armorSpecIdx);
			auto armorSpec = headGear->m_aArmorSpec[armorSpecIdx];
			if (iApprPawn->m_oSettings->m_oBodySettings->m_oHeadGearSettings)
			{
				auto hgrVslOvr = iApprPawn->m_oSettings->m_oBodySettings->m_oHeadGearSettings->m_eVisualOverride;
				RenderInt(L"Headgear Visual Override Armor Spec", hgrVslOvr);
			}
			// Need good way of determining this index
			auto modelSpecIdx = 2;
			if (modelSpecIdx < armorSpec.m_aModelSpec.Count)
			{
				auto modelSpec = armorSpec.m_aModelSpec.Data[modelSpecIdx];
				RenderInt(L"Hgr ModelSpec Index (currently hardcoded)", modelSpecIdx);
				RenderInt(L"Hgr ModelSpec MaterialConfigCount", modelSpec.m_nMaterialConfigCount);
				RenderBool(L"Hgr ModelSpec bIsHairHidden", modelSpec.m_bIsHairHidden);
				RenderBool(L"Hgr ModelSpec bIsHeadHidden", modelSpec.m_bIsHeadHidden);
				RenderBool(L"Hgr ModelSpec bSuppressFacePlate", modelSpec.m_bSuppressFacePlate);
				RenderBool(L"Hgr ModelSpec bSuppressVisor", modelSpec.m_bSuppressVisor);
			}
		}
	}
};

