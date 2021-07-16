/*
#############################################################################################
# Mass Effect 1 (Legendary Edition) (2.0.0.48602) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: SFXOnlineFoundation_functions.h
# ========================================================================================= #
# Credits: uNrEaL, Tamimego, SystemFiles, R00T88, _silencer, the1domo, K@N@VEL
# Thanks: HOOAH07, lowHertz
# Forums: www.uc-forum.com, www.gamedeception.net
#############################################################################################
*/


#pragma once
#include <Windows.h>
#include <cstdio>
#include "../SdkInitializer.h"



#ifdef _MSC_VER
	#pragma pack ( push, 0x4 )
#endif

/*
# ========================================================================================= #
# Functions
# ========================================================================================= #
*/

// Function SFXOnlineFoundation.SFXOnlineEvent.Update
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineEvent::Update ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnUpdate = NULL;

	if ( ! pFnUpdate )
		pFnUpdate = (UFunction*) UObject::GObjObjects()->Data[ 38516 ];

	USFXOnlineEvent_execUpdate_Parms Update_Parms;
	Update_Parms.oEvent = oEvent;

	pFnUpdate->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnUpdate, &Update_Parms, NULL );

	pFnUpdate->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.IsComplete
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineEvent::IsComplete ( )
{
	static UFunction* pFnIsComplete = NULL;

	if ( ! pFnIsComplete )
		pFnIsComplete = (UFunction*) UObject::GObjObjects()->Data[ 38514 ];

	USFXOnlineEvent_execIsComplete_Parms IsComplete_Parms;

	pFnIsComplete->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsComplete, &IsComplete_Parms, NULL );

	pFnIsComplete->FunctionFlags |= 0x400;

	return IsComplete_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.IsPending
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineEvent::IsPending ( )
{
	static UFunction* pFnIsPending = NULL;

	if ( ! pFnIsPending )
		pFnIsPending = (UFunction*) UObject::GObjObjects()->Data[ 38512 ];

	USFXOnlineEvent_execIsPending_Parms IsPending_Parms;

	pFnIsPending->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsPending, &IsPending_Parms, NULL );

	pFnIsPending->FunctionFlags |= 0x400;

	return IsPending_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.CompleteAndSucceeded
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineEvent::CompleteAndSucceeded ( )
{
	static UFunction* pFnCompleteAndSucceeded = NULL;

	if ( ! pFnCompleteAndSucceeded )
		pFnCompleteAndSucceeded = (UFunction*) UObject::GObjObjects()->Data[ 38510 ];

	USFXOnlineEvent_execCompleteAndSucceeded_Parms CompleteAndSucceeded_Parms;

	pFnCompleteAndSucceeded->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCompleteAndSucceeded, &CompleteAndSucceeded_Parms, NULL );

	pFnCompleteAndSucceeded->FunctionFlags |= 0x400;

	return CompleteAndSucceeded_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.HasTimedOut
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineEvent::HasTimedOut ( )
{
	static UFunction* pFnHasTimedOut = NULL;

	if ( ! pFnHasTimedOut )
		pFnHasTimedOut = (UFunction*) UObject::GObjObjects()->Data[ 38508 ];

	USFXOnlineEvent_execHasTimedOut_Parms HasTimedOut_Parms;

	pFnHasTimedOut->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnHasTimedOut, &HasTimedOut_Parms, NULL );

	pFnHasTimedOut->FunctionFlags |= 0x400;

	return HasTimedOut_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.IsTimeoutEnabled
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineEvent::IsTimeoutEnabled ( )
{
	static UFunction* pFnIsTimeoutEnabled = NULL;

	if ( ! pFnIsTimeoutEnabled )
		pFnIsTimeoutEnabled = (UFunction*) UObject::GObjObjects()->Data[ 38506 ];

	USFXOnlineEvent_execIsTimeoutEnabled_Parms IsTimeoutEnabled_Parms;

	pFnIsTimeoutEnabled->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsTimeoutEnabled, &IsTimeoutEnabled_Parms, NULL );

	pFnIsTimeoutEnabled->FunctionFlags |= 0x400;

	return IsTimeoutEnabled_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.DisableTimeout
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void USFXOnlineEvent::DisableTimeout ( )
{
	static UFunction* pFnDisableTimeout = NULL;

	if ( ! pFnDisableTimeout )
		pFnDisableTimeout = (UFunction*) UObject::GObjObjects()->Data[ 38505 ];

	USFXOnlineEvent_execDisableTimeout_Parms DisableTimeout_Parms;

	pFnDisableTimeout->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnDisableTimeout, &DisableTimeout_Parms, NULL );

	pFnDisableTimeout->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.EnableTimeout
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void USFXOnlineEvent::EnableTimeout ( )
{
	static UFunction* pFnEnableTimeout = NULL;

	if ( ! pFnEnableTimeout )
		pFnEnableTimeout = (UFunction*) UObject::GObjObjects()->Data[ 38504 ];

	USFXOnlineEvent_execEnableTimeout_Parms EnableTimeout_Parms;

	pFnEnableTimeout->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnEnableTimeout, &EnableTimeout_Parms, NULL );

	pFnEnableTimeout->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.SetTimeout
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// float                          fEventTimeout                  ( CPF_Parm )

void USFXOnlineEvent::SetTimeout ( float fEventTimeout )
{
	static UFunction* pFnSetTimeout = NULL;

	if ( ! pFnSetTimeout )
		pFnSetTimeout = (UFunction*) UObject::GObjObjects()->Data[ 38502 ];

	USFXOnlineEvent_execSetTimeout_Parms SetTimeout_Parms;
	SetTimeout_Parms.fEventTimeout = fEventTimeout;

	pFnSetTimeout->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetTimeout, &SetTimeout_Parms, NULL );

	pFnSetTimeout->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.GetTimeout
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

float USFXOnlineEvent::GetTimeout ( )
{
	static UFunction* pFnGetTimeout = NULL;

	if ( ! pFnGetTimeout )
		pFnGetTimeout = (UFunction*) UObject::GObjObjects()->Data[ 38500 ];

	USFXOnlineEvent_execGetTimeout_Parms GetTimeout_Parms;

	pFnGetTimeout->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetTimeout, &GetTimeout_Parms, NULL );

	pFnGetTimeout->FunctionFlags |= 0x400;

	return GetTimeout_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.SetErrorString
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FString                 sMessage                       ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineEvent::SetErrorString ( struct FString sMessage )
{
	static UFunction* pFnSetErrorString = NULL;

	if ( ! pFnSetErrorString )
		pFnSetErrorString = (UFunction*) UObject::GObjObjects()->Data[ 38498 ];

	USFXOnlineEvent_execSetErrorString_Parms SetErrorString_Parms;
	memcpy ( &SetErrorString_Parms.sMessage, &sMessage, 0x10 );

	pFnSetErrorString->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetErrorString, &SetErrorString_Parms, NULL );

	pFnSetErrorString->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.GetErrorString
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct FString USFXOnlineEvent::GetErrorString ( )
{
	static UFunction* pFnGetErrorString = NULL;

	if ( ! pFnGetErrorString )
		pFnGetErrorString = (UFunction*) UObject::GObjObjects()->Data[ 38496 ];

	USFXOnlineEvent_execGetErrorString_Parms GetErrorString_Parms;

	pFnGetErrorString->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetErrorString, &GetErrorString_Parms, NULL );

	pFnGetErrorString->FunctionFlags |= 0x400;

	return GetErrorString_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.SetErrorCode
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            nCode                          ( CPF_Parm )

void USFXOnlineEvent::SetErrorCode ( int nCode )
{
	static UFunction* pFnSetErrorCode = NULL;

	if ( ! pFnSetErrorCode )
		pFnSetErrorCode = (UFunction*) UObject::GObjObjects()->Data[ 38494 ];

	USFXOnlineEvent_execSetErrorCode_Parms SetErrorCode_Parms;
	SetErrorCode_Parms.nCode = nCode;

	pFnSetErrorCode->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetErrorCode, &SetErrorCode_Parms, NULL );

	pFnSetErrorCode->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.GetErrorCode
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineEvent::GetErrorCode ( )
{
	static UFunction* pFnGetErrorCode = NULL;

	if ( ! pFnGetErrorCode )
		pFnGetErrorCode = (UFunction*) UObject::GObjObjects()->Data[ 38492 ];

	USFXOnlineEvent_execGetErrorCode_Parms GetErrorCode_Parms;

	pFnGetErrorCode->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetErrorCode, &GetErrorCode_Parms, NULL );

	pFnGetErrorCode->FunctionFlags |= 0x400;

	return GetErrorCode_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.SetStatus
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  eNewStatus                     ( CPF_Parm )

void USFXOnlineEvent::SetStatus ( unsigned char eNewStatus )
{
	static UFunction* pFnSetStatus = NULL;

	if ( ! pFnSetStatus )
		pFnSetStatus = (UFunction*) UObject::GObjObjects()->Data[ 38490 ];

	USFXOnlineEvent_execSetStatus_Parms SetStatus_Parms;
	SetStatus_Parms.eNewStatus = eNewStatus;

	pFnSetStatus->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetStatus, &SetStatus_Parms, NULL );

	pFnSetStatus->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.GetStatus
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char USFXOnlineEvent::GetStatus ( )
{
	static UFunction* pFnGetStatus = NULL;

	if ( ! pFnGetStatus )
		pFnGetStatus = (UFunction*) UObject::GObjObjects()->Data[ 38488 ];

	USFXOnlineEvent_execGetStatus_Parms GetStatus_Parms;

	pFnGetStatus->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetStatus, &GetStatus_Parms, NULL );

	pFnGetStatus->FunctionFlags |= 0x400;

	return GetStatus_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.SetOutcome
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  eStatusFinished                ( CPF_Parm )

void USFXOnlineEvent::SetOutcome ( unsigned char eStatusFinished )
{
	static UFunction* pFnSetOutcome = NULL;

	if ( ! pFnSetOutcome )
		pFnSetOutcome = (UFunction*) UObject::GObjObjects()->Data[ 38486 ];

	USFXOnlineEvent_execSetOutcome_Parms SetOutcome_Parms;
	SetOutcome_Parms.eStatusFinished = eStatusFinished;

	pFnSetOutcome->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetOutcome, &SetOutcome_Parms, NULL );

	pFnSetOutcome->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.GetOutcome
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char USFXOnlineEvent::GetOutcome ( )
{
	static UFunction* pFnGetOutcome = NULL;

	if ( ! pFnGetOutcome )
		pFnGetOutcome = (UFunction*) UObject::GObjObjects()->Data[ 38484 ];

	USFXOnlineEvent_execGetOutcome_Parms GetOutcome_Parms;

	pFnGetOutcome->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOutcome, &GetOutcome_Parms, NULL );

	pFnGetOutcome->FunctionFlags |= 0x400;

	return GetOutcome_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.SetEventId
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            nNewEventId                    ( CPF_Parm )

void USFXOnlineEvent::SetEventId ( int nNewEventId )
{
	static UFunction* pFnSetEventId = NULL;

	if ( ! pFnSetEventId )
		pFnSetEventId = (UFunction*) UObject::GObjObjects()->Data[ 38482 ];

	USFXOnlineEvent_execSetEventId_Parms SetEventId_Parms;
	SetEventId_Parms.nNewEventId = nNewEventId;

	pFnSetEventId->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetEventId, &SetEventId_Parms, NULL );

	pFnSetEventId->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.GetEventId
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineEvent::GetEventId ( )
{
	static UFunction* pFnGetEventId = NULL;

	if ( ! pFnGetEventId )
		pFnGetEventId = (UFunction*) UObject::GObjObjects()->Data[ 38480 ];

	USFXOnlineEvent_execGetEventId_Parms GetEventId_Parms;

	pFnGetEventId->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetEventId, &GetEventId_Parms, NULL );

	pFnGetEventId->FunctionFlags |= 0x400;

	return GetEventId_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.SetEventType
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  eNewEventType                  ( CPF_Parm )

void USFXOnlineEvent::SetEventType ( unsigned char eNewEventType )
{
	static UFunction* pFnSetEventType = NULL;

	if ( ! pFnSetEventType )
		pFnSetEventType = (UFunction*) UObject::GObjObjects()->Data[ 38478 ];

	USFXOnlineEvent_execSetEventType_Parms SetEventType_Parms;
	SetEventType_Parms.eNewEventType = eNewEventType;

	pFnSetEventType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetEventType, &SetEventType_Parms, NULL );

	pFnSetEventType->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent.GetEventType
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char USFXOnlineEvent::GetEventType ( )
{
	static UFunction* pFnGetEventType = NULL;

	if ( ! pFnGetEventType )
		pFnGetEventType = (UFunction*) UObject::GObjObjects()->Data[ 38476 ];

	USFXOnlineEvent_execGetEventType_Parms GetEventType_Parms;

	pFnGetEventType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetEventType, &GetEventType_Parms, NULL );

	pFnGetEventType->FunctionFlags |= 0x400;

	return GetEventType_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent_Integer.SetInteger
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            nInteger                       ( CPF_Parm )

void USFXOnlineEvent_Integer::SetInteger ( int nInteger )
{
	static UFunction* pFnSetInteger = NULL;

	if ( ! pFnSetInteger )
		pFnSetInteger = (UFunction*) UObject::GObjObjects()->Data[ 39983 ];

	USFXOnlineEvent_Integer_execSetInteger_Parms SetInteger_Parms;
	SetInteger_Parms.nInteger = nInteger;

	pFnSetInteger->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetInteger, &SetInteger_Parms, NULL );

	pFnSetInteger->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent_Integer.GetInteger
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineEvent_Integer::GetInteger ( )
{
	static UFunction* pFnGetInteger = NULL;

	if ( ! pFnGetInteger )
		pFnGetInteger = (UFunction*) UObject::GObjObjects()->Data[ 39981 ];

	USFXOnlineEvent_Integer_execGetInteger_Parms GetInteger_Parms;

	pFnGetInteger->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetInteger, &GetInteger_Parms, NULL );

	pFnGetInteger->FunctionFlags |= 0x400;

	return GetInteger_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent_String.SetStringData
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FString                 sStringData                    ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineEvent_String::SetStringData ( struct FString sStringData )
{
	static UFunction* pFnSetStringData = NULL;

	if ( ! pFnSetStringData )
		pFnSetStringData = (UFunction*) UObject::GObjObjects()->Data[ 39988 ];

	USFXOnlineEvent_String_execSetStringData_Parms SetStringData_Parms;
	memcpy ( &SetStringData_Parms.sStringData, &sStringData, 0x10 );

	pFnSetStringData->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetStringData, &SetStringData_Parms, NULL );

	pFnSetStringData->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent_String.GetStringData
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct FString USFXOnlineEvent_String::GetStringData ( )
{
	static UFunction* pFnGetStringData = NULL;

	if ( ! pFnGetStringData )
		pFnGetStringData = (UFunction*) UObject::GObjObjects()->Data[ 39986 ];

	USFXOnlineEvent_String_execGetStringData_Parms GetStringData_Parms;

	pFnGetStringData->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetStringData, &GetStringData_Parms, NULL );

	pFnGetStringData->FunctionFlags |= 0x400;

	return GetStringData_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent_Notification.SetPriority
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            nPriority                      ( CPF_Parm )

void USFXOnlineEvent_Notification::SetPriority ( int nPriority )
{
	static UFunction* pFnSetPriority = NULL;

	if ( ! pFnSetPriority )
		pFnSetPriority = (UFunction*) UObject::GObjObjects()->Data[ 39997 ];

	USFXOnlineEvent_Notification_execSetPriority_Parms SetPriority_Parms;
	SetPriority_Parms.nPriority = nPriority;

	pFnSetPriority->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetPriority, &SetPriority_Parms, NULL );

	pFnSetPriority->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent_Notification.GetPriority
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineEvent_Notification::GetPriority ( )
{
	static UFunction* pFnGetPriority = NULL;

	if ( ! pFnGetPriority )
		pFnGetPriority = (UFunction*) UObject::GObjObjects()->Data[ 39995 ];

	USFXOnlineEvent_Notification_execGetPriority_Parms GetPriority_Parms;

	pFnGetPriority->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetPriority, &GetPriority_Parms, NULL );

	pFnGetPriority->FunctionFlags |= 0x400;

	return GetPriority_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEvent_Notification.SetImageName
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FString                 sImageName                     ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineEvent_Notification::SetImageName ( struct FString sImageName )
{
	static UFunction* pFnSetImageName = NULL;

	if ( ! pFnSetImageName )
		pFnSetImageName = (UFunction*) UObject::GObjObjects()->Data[ 39993 ];

	USFXOnlineEvent_Notification_execSetImageName_Parms SetImageName_Parms;
	memcpy ( &SetImageName_Parms.sImageName, &sImageName, 0x10 );

	pFnSetImageName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetImageName, &SetImageName_Parms, NULL );

	pFnSetImageName->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineEvent_Notification.GetImageName
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct FString USFXOnlineEvent_Notification::GetImageName ( )
{
	static UFunction* pFnGetImageName = NULL;

	if ( ! pFnGetImageName )
		pFnGetImageName = (UFunction*) UObject::GObjObjects()->Data[ 39991 ];

	USFXOnlineEvent_Notification_execGetImageName_Parms GetImageName_Parms;

	pFnGetImageName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetImageName, &GetImageName_Parms, NULL );

	pFnGetImageName->FunctionFlags |= 0x400;

	return GetImageName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEventList.GetNextTimedOutEvent
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class USFXOnlineEvent* USFXOnlineEventList::GetNextTimedOutEvent ( )
{
	static UFunction* pFnGetNextTimedOutEvent = NULL;

	if ( ! pFnGetNextTimedOutEvent )
		pFnGetNextTimedOutEvent = (UFunction*) UObject::GObjObjects()->Data[ 40030 ];

	USFXOnlineEventList_execGetNextTimedOutEvent_Parms GetNextTimedOutEvent_Parms;

	pFnGetNextTimedOutEvent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetNextTimedOutEvent, &GetNextTimedOutEvent_Parms, NULL );

	pFnGetNextTimedOutEvent->FunctionFlags |= 0x400;

	return GetNextTimedOutEvent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEventList.RemoveEvent
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

bool USFXOnlineEventList::RemoveEvent ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnRemoveEvent = NULL;

	if ( ! pFnRemoveEvent )
		pFnRemoveEvent = (UFunction*) UObject::GObjObjects()->Data[ 40027 ];

	USFXOnlineEventList_execRemoveEvent_Parms RemoveEvent_Parms;
	RemoveEvent_Parms.oEvent = oEvent;

	pFnRemoveEvent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnRemoveEvent, &RemoveEvent_Parms, NULL );

	pFnRemoveEvent->FunctionFlags |= 0x400;

	return RemoveEvent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEventList.FindEventByType
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eEventType                     ( CPF_Parm )
// int                            nEventId                       ( CPF_Parm )

int USFXOnlineEventList::FindEventByType ( unsigned char eEventType, int nEventId )
{
	static UFunction* pFnFindEventByType = NULL;

	if ( ! pFnFindEventByType )
		pFnFindEventByType = (UFunction*) UObject::GObjObjects()->Data[ 40023 ];

	USFXOnlineEventList_execFindEventByType_Parms FindEventByType_Parms;
	FindEventByType_Parms.eEventType = eEventType;
	FindEventByType_Parms.nEventId = nEventId;

	pFnFindEventByType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnFindEventByType, &FindEventByType_Parms, NULL );

	pFnFindEventByType->FunctionFlags |= 0x400;

	return FindEventByType_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEventList.FindEvent
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

int USFXOnlineEventList::FindEvent ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnFindEvent = NULL;

	if ( ! pFnFindEvent )
		pFnFindEvent = (UFunction*) UObject::GObjObjects()->Data[ 40020 ];

	USFXOnlineEventList_execFindEvent_Parms FindEvent_Parms;
	FindEvent_Parms.oEvent = oEvent;

	pFnFindEvent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnFindEvent, &FindEvent_Parms, NULL );

	pFnFindEvent->FunctionFlags |= 0x400;

	return FindEvent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEventList.GetEventAtIndex
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nEventIndex                    ( CPF_Parm )

class USFXOnlineEvent* USFXOnlineEventList::GetEventAtIndex ( int nEventIndex )
{
	static UFunction* pFnGetEventAtIndex = NULL;

	if ( ! pFnGetEventAtIndex )
		pFnGetEventAtIndex = (UFunction*) UObject::GObjObjects()->Data[ 40017 ];

	USFXOnlineEventList_execGetEventAtIndex_Parms GetEventAtIndex_Parms;
	GetEventAtIndex_Parms.nEventIndex = nEventIndex;

	pFnGetEventAtIndex->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetEventAtIndex, &GetEventAtIndex_Parms, NULL );

	pFnGetEventAtIndex->FunctionFlags |= 0x400;

	return GetEventAtIndex_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEventList.GetEvent
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

class USFXOnlineEvent* USFXOnlineEventList::GetEvent ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnGetEvent = NULL;

	if ( ! pFnGetEvent )
		pFnGetEvent = (UFunction*) UObject::GObjObjects()->Data[ 40014 ];

	USFXOnlineEventList_execGetEvent_Parms GetEvent_Parms;
	GetEvent_Parms.oEvent = oEvent;

	pFnGetEvent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetEvent, &GetEvent_Parms, NULL );

	pFnGetEvent->FunctionFlags |= 0x400;

	return GetEvent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineEventList.AddEvent
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

bool USFXOnlineEventList::AddEvent ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnAddEvent = NULL;

	if ( ! pFnAddEvent )
		pFnAddEvent = (UFunction*) UObject::GObjObjects()->Data[ 40011 ];

	USFXOnlineEventList_execAddEvent_Parms AddEvent_Parms;
	AddEvent_Parms.oEvent = oEvent;

	pFnAddEvent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnAddEvent, &AddEvent_Parms, NULL );

	pFnAddEvent->FunctionFlags |= 0x400;

	return AddEvent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponent.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName UISFXOnlineComponent::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 38098 ];

	UISFXOnlineComponent_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponent.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponent::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 38097 ];

	UISFXOnlineComponent_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponent.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void UISFXOnlineComponent::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 38095 ];

	UISFXOnlineComponent_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentAPI.Idle
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UISFXOnlineComponentAPI::Idle ( )
{
	static UFunction* pFnIdle = NULL;

	if ( ! pFnIdle )
		pFnIdle = (UFunction*) UObject::GObjObjects()->Data[ 38115 ];

	UISFXOnlineComponentAPI_execIdle_Parms Idle_Parms;

	pFnIdle->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIdle, &Idle_Parms, NULL );

	pFnIdle->FunctionFlags |= 0x400;

	return Idle_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentAchievement.GetTitleAchievementID
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            Index                          ( CPF_Parm )
// int                            SetIndex                       ( CPF_Parm | CPF_OutParm )

int UISFXOnlineComponentAchievement::GetTitleAchievementID ( int Index, int* SetIndex )
{
	static UFunction* pFnGetTitleAchievementID = NULL;

	if ( ! pFnGetTitleAchievementID )
		pFnGetTitleAchievementID = (UFunction*) UObject::GObjObjects()->Data[ 38111 ];

	UISFXOnlineComponentAchievement_execGetTitleAchievementID_Parms GetTitleAchievementID_Parms;
	GetTitleAchievementID_Parms.Index = Index;

	pFnGetTitleAchievementID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetTitleAchievementID, &GetTitleAchievementID_Parms, NULL );

	pFnGetTitleAchievementID->FunctionFlags |= 0x400;

	if ( SetIndex )
		*SetIndex = GetTitleAchievementID_Parms.SetIndex;

	return GetTitleAchievementID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentAchievement.GetPlatformAchievementID
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            Index                          ( CPF_Parm )
// int                            SetIndex                       ( CPF_Parm | CPF_OutParm )

int UISFXOnlineComponentAchievement::GetPlatformAchievementID ( int Index, int* SetIndex )
{
	static UFunction* pFnGetPlatformAchievementID = NULL;

	if ( ! pFnGetPlatformAchievementID )
		pFnGetPlatformAchievementID = (UFunction*) UObject::GObjObjects()->Data[ 38107 ];

	UISFXOnlineComponentAchievement_execGetPlatformAchievementID_Parms GetPlatformAchievementID_Parms;
	GetPlatformAchievementID_Parms.Index = Index;

	pFnGetPlatformAchievementID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetPlatformAchievementID, &GetPlatformAchievementID_Parms, NULL );

	pFnGetPlatformAchievementID->FunctionFlags |= 0x400;

	if ( SetIndex )
		*SetIndex = GetPlatformAchievementID_Parms.SetIndex;

	return GetPlatformAchievementID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentAchievement.IsGranted
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

bool UISFXOnlineComponentAchievement::IsGranted ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnIsGranted = NULL;

	if ( ! pFnIsGranted )
		pFnIsGranted = (UFunction*) UObject::GObjObjects()->Data[ 38103 ];

	UISFXOnlineComponentAchievement_execIsGranted_Parms IsGranted_Parms;
	IsGranted_Parms.LocalUserNum = LocalUserNum;
	IsGranted_Parms.AchievementId = AchievementId;

	pFnIsGranted->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsGranted, &IsGranted_Parms, NULL );

	pFnIsGranted->FunctionFlags |= 0x400;

	return IsGranted_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentAchievement.Grant
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

void UISFXOnlineComponentAchievement::Grant ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnGrant = NULL;

	if ( ! pFnGrant )
		pFnGrant = (UFunction*) UObject::GObjObjects()->Data[ 38100 ];

	UISFXOnlineComponentAchievement_execGrant_Parms Grant_Parms;
	Grant_Parms.LocalUserNum = LocalUserNum;
	Grant_Parms.AchievementId = AchievementId;

	pFnGrant->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGrant, &Grant_Parms, NULL );

	pFnGrant->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.GetConnectMode
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char UISFXOnlineComponentLogin::GetConnectMode ( )
{
	static UFunction* pFnGetConnectMode = NULL;

	if ( ! pFnGetConnectMode )
		pFnGetConnectMode = (UFunction*) UObject::GObjObjects()->Data[ 38246 ];

	UISFXOnlineComponentLogin_execGetConnectMode_Parms GetConnectMode_Parms;

	pFnGetConnectMode->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetConnectMode, &GetConnectMode_Parms, NULL );

	pFnGetConnectMode->FunctionFlags |= 0x400;

	return GetConnectMode_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.GetUIState
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char UISFXOnlineComponentLogin::GetUIState ( )
{
	static UFunction* pFnGetUIState = NULL;

	if ( ! pFnGetUIState )
		pFnGetUIState = (UFunction*) UObject::GObjObjects()->Data[ 38244 ];

	UISFXOnlineComponentLogin_execGetUIState_Parms GetUIState_Parms;

	pFnGetUIState->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetUIState, &GetUIState_Parms, NULL );

	pFnGetUIState->FunctionFlags |= 0x400;

	return GetUIState_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.CanShowPresenceInformation
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_OptionalParm | CPF_Parm )

unsigned char UISFXOnlineComponentLogin::CanShowPresenceInformation ( int nUserIndex )
{
	static UFunction* pFnCanShowPresenceInformation = NULL;

	if ( ! pFnCanShowPresenceInformation )
		pFnCanShowPresenceInformation = (UFunction*) UObject::GObjObjects()->Data[ 38241 ];

	UISFXOnlineComponentLogin_execCanShowPresenceInformation_Parms CanShowPresenceInformation_Parms;
	CanShowPresenceInformation_Parms.nUserIndex = nUserIndex;

	pFnCanShowPresenceInformation->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanShowPresenceInformation, &CanShowPresenceInformation_Parms, NULL );

	pFnCanShowPresenceInformation->FunctionFlags |= 0x400;

	return CanShowPresenceInformation_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.CanViewPlayerProfiles
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_OptionalParm | CPF_Parm )

unsigned char UISFXOnlineComponentLogin::CanViewPlayerProfiles ( int nUserIndex )
{
	static UFunction* pFnCanViewPlayerProfiles = NULL;

	if ( ! pFnCanViewPlayerProfiles )
		pFnCanViewPlayerProfiles = (UFunction*) UObject::GObjObjects()->Data[ 38238 ];

	UISFXOnlineComponentLogin_execCanViewPlayerProfiles_Parms CanViewPlayerProfiles_Parms;
	CanViewPlayerProfiles_Parms.nUserIndex = nUserIndex;

	pFnCanViewPlayerProfiles->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanViewPlayerProfiles, &CanViewPlayerProfiles_Parms, NULL );

	pFnCanViewPlayerProfiles->FunctionFlags |= 0x400;

	return CanViewPlayerProfiles_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.CanPurchaseContent
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_OptionalParm | CPF_Parm )

unsigned char UISFXOnlineComponentLogin::CanPurchaseContent ( int nUserIndex )
{
	static UFunction* pFnCanPurchaseContent = NULL;

	if ( ! pFnCanPurchaseContent )
		pFnCanPurchaseContent = (UFunction*) UObject::GObjObjects()->Data[ 38235 ];

	UISFXOnlineComponentLogin_execCanPurchaseContent_Parms CanPurchaseContent_Parms;
	CanPurchaseContent_Parms.nUserIndex = nUserIndex;

	pFnCanPurchaseContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPurchaseContent, &CanPurchaseContent_Parms, NULL );

	pFnCanPurchaseContent->FunctionFlags |= 0x400;

	return CanPurchaseContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.CanDownloadUserContent
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_OptionalParm | CPF_Parm )

unsigned char UISFXOnlineComponentLogin::CanDownloadUserContent ( int nUserIndex )
{
	static UFunction* pFnCanDownloadUserContent = NULL;

	if ( ! pFnCanDownloadUserContent )
		pFnCanDownloadUserContent = (UFunction*) UObject::GObjObjects()->Data[ 38232 ];

	UISFXOnlineComponentLogin_execCanDownloadUserContent_Parms CanDownloadUserContent_Parms;
	CanDownloadUserContent_Parms.nUserIndex = nUserIndex;

	pFnCanDownloadUserContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanDownloadUserContent, &CanDownloadUserContent_Parms, NULL );

	pFnCanDownloadUserContent->FunctionFlags |= 0x400;

	return CanDownloadUserContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.CanCommunicate
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_OptionalParm | CPF_Parm )

unsigned char UISFXOnlineComponentLogin::CanCommunicate ( int nUserIndex )
{
	static UFunction* pFnCanCommunicate = NULL;

	if ( ! pFnCanCommunicate )
		pFnCanCommunicate = (UFunction*) UObject::GObjObjects()->Data[ 38229 ];

	UISFXOnlineComponentLogin_execCanCommunicate_Parms CanCommunicate_Parms;
	CanCommunicate_Parms.nUserIndex = nUserIndex;

	pFnCanCommunicate->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanCommunicate, &CanCommunicate_Parms, NULL );

	pFnCanCommunicate->FunctionFlags |= 0x400;

	return CanCommunicate_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.CanPlayOnline
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_OptionalParm | CPF_Parm )

unsigned char UISFXOnlineComponentLogin::CanPlayOnline ( int nUserIndex )
{
	static UFunction* pFnCanPlayOnline = NULL;

	if ( ! pFnCanPlayOnline )
		pFnCanPlayOnline = (UFunction*) UObject::GObjObjects()->Data[ 38226 ];

	UISFXOnlineComponentLogin_execCanPlayOnline_Parms CanPlayOnline_Parms;
	CanPlayOnline_Parms.nUserIndex = nUserIndex;

	pFnCanPlayOnline->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPlayOnline, &CanPlayOnline_Parms, NULL );

	pFnCanPlayOnline->FunctionFlags |= 0x400;

	return CanPlayOnline_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.EnterCDKey
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 sKey                           ( CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentLogin::EnterCDKey ( struct FString sKey )
{
	static UFunction* pFnEnterCDKey = NULL;

	if ( ! pFnEnterCDKey )
		pFnEnterCDKey = (UFunction*) UObject::GObjObjects()->Data[ 38224 ];

	UISFXOnlineComponentLogin_execEnterCDKey_Parms EnterCDKey_Parms;
	memcpy ( &EnterCDKey_Parms.sKey, &sKey, 0x10 );

	pFnEnterCDKey->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnEnterCDKey, &EnterCDKey_Parms, NULL );

	pFnEnterCDKey->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.OnDownloadOffersUICompleted
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentLogin::OnDownloadOffersUICompleted ( )
{
	static UFunction* pFnOnDownloadOffersUICompleted = NULL;

	if ( ! pFnOnDownloadOffersUICompleted )
		pFnOnDownloadOffersUICompleted = (UFunction*) UObject::GObjObjects()->Data[ 38223 ];

	UISFXOnlineComponentLogin_execOnDownloadOffersUICompleted_Parms OnDownloadOffersUICompleted_Parms;

	pFnOnDownloadOffersUICompleted->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnDownloadOffersUICompleted, &OnDownloadOffersUICompleted_Parms, NULL );

	pFnOnDownloadOffersUICompleted->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.OnDLCInfoLoaded
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentLogin::OnDLCInfoLoaded ( )
{
	static UFunction* pFnOnDLCInfoLoaded = NULL;

	if ( ! pFnOnDLCInfoLoaded )
		pFnOnDLCInfoLoaded = (UFunction*) UObject::GObjObjects()->Data[ 38222 ];

	UISFXOnlineComponentLogin_execOnDLCInfoLoaded_Parms OnDLCInfoLoaded_Parms;

	pFnOnDLCInfoLoaded->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnDLCInfoLoaded, &OnDLCInfoLoaded_Parms, NULL );

	pFnOnDLCInfoLoaded->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.OpenCerberusUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentLogin::OpenCerberusUI ( )
{
	static UFunction* pFnOpenCerberusUI = NULL;

	if ( ! pFnOpenCerberusUI )
		pFnOpenCerberusUI = (UFunction*) UObject::GObjObjects()->Data[ 38221 ];

	UISFXOnlineComponentLogin_execOpenCerberusUI_Parms OpenCerberusUI_Parms;

	pFnOpenCerberusUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOpenCerberusUI, &OpenCerberusUI_Parms, NULL );

	pFnOpenCerberusUI->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.CheckEntitlement
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FString                 sGroup                         ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sTag                           ( CPF_Parm | CPF_NeedCtorLink )

bool UISFXOnlineComponentLogin::CheckEntitlement ( struct FString sGroup, struct FString sTag )
{
	static UFunction* pFnCheckEntitlement = NULL;

	if ( ! pFnCheckEntitlement )
		pFnCheckEntitlement = (UFunction*) UObject::GObjObjects()->Data[ 38217 ];

	UISFXOnlineComponentLogin_execCheckEntitlement_Parms CheckEntitlement_Parms;
	memcpy ( &CheckEntitlement_Parms.sGroup, &sGroup, 0x10 );
	memcpy ( &CheckEntitlement_Parms.sTag, &sTag, 0x10 );

	pFnCheckEntitlement->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCheckEntitlement, &CheckEntitlement_Parms, NULL );

	pFnCheckEntitlement->FunctionFlags |= 0x400;

	return CheckEntitlement_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.IsCerberusMember
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UISFXOnlineComponentLogin::IsCerberusMember ( )
{
	static UFunction* pFnIsCerberusMember = NULL;

	if ( ! pFnIsCerberusMember )
		pFnIsCerberusMember = (UFunction*) UObject::GObjObjects()->Data[ 38215 ];

	UISFXOnlineComponentLogin_execIsCerberusMember_Parms IsCerberusMember_Parms;

	pFnIsCerberusMember->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsCerberusMember, &IsCerberusMember_Parms, NULL );

	pFnIsCerberusMember->FunctionFlags |= 0x400;

	return IsCerberusMember_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.DisablePersona
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 sPersonaNonGrata               ( CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentLogin::DisablePersona ( struct FString sPersonaNonGrata )
{
	static UFunction* pFnDisablePersona = NULL;

	if ( ! pFnDisablePersona )
		pFnDisablePersona = (UFunction*) UObject::GObjObjects()->Data[ 38213 ];

	UISFXOnlineComponentLogin_execDisablePersona_Parms DisablePersona_Parms;
	memcpy ( &DisablePersona_Parms.sPersonaNonGrata, &sPersonaNonGrata, 0x10 );

	pFnDisablePersona->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnDisablePersona, &DisablePersona_Parms, NULL );

	pFnDisablePersona->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.CreatePersona
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 sPersonaName                   ( CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentLogin::CreatePersona ( struct FString sPersonaName )
{
	static UFunction* pFnCreatePersona = NULL;

	if ( ! pFnCreatePersona )
		pFnCreatePersona = (UFunction*) UObject::GObjObjects()->Data[ 38211 ];

	UISFXOnlineComponentLogin_execCreatePersona_Parms CreatePersona_Parms;
	memcpy ( &CreatePersona_Parms.sPersonaName, &sPersonaName, 0x10 );

	pFnCreatePersona->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCreatePersona, &CreatePersona_Parms, NULL );

	pFnCreatePersona->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SelectPersona
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 sPersonaName                   ( CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentLogin::SelectPersona ( struct FString sPersonaName )
{
	static UFunction* pFnSelectPersona = NULL;

	if ( ! pFnSelectPersona )
		pFnSelectPersona = (UFunction*) UObject::GObjObjects()->Data[ 38209 ];

	UISFXOnlineComponentLogin_execSelectPersona_Parms SelectPersona_Parms;
	memcpy ( &SelectPersona_Parms.sPersonaName, &sPersonaName, 0x10 );

	pFnSelectPersona->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSelectPersona, &SelectPersona_Parms, NULL );

	pFnSelectPersona->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.AcceptTOS
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned long                  bAccepted                      ( CPF_Parm )

void UISFXOnlineComponentLogin::AcceptTOS ( unsigned long bAccepted )
{
	static UFunction* pFnAcceptTOS = NULL;

	if ( ! pFnAcceptTOS )
		pFnAcceptTOS = (UFunction*) UObject::GObjObjects()->Data[ 38207 ];

	UISFXOnlineComponentLogin_execAcceptTOS_Parms AcceptTOS_Parms;
	AcceptTOS_Parms.bAccepted = bAccepted;

	pFnAcceptTOS->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnAcceptTOS, &AcceptTOS_Parms, NULL );

	pFnAcceptTOS->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.Disconnect
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentLogin::Disconnect ( )
{
	static UFunction* pFnDisconnect = NULL;

	if ( ! pFnDisconnect )
		pFnDisconnect = (UFunction*) UObject::GObjObjects()->Data[ 38206 ];

	UISFXOnlineComponentLogin_execDisconnect_Parms Disconnect_Parms;

	pFnDisconnect->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnDisconnect, &Disconnect_Parms, NULL );

	pFnDisconnect->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SubmitStore
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct TArray<int>             aiChosen                       ( CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentLogin::SubmitStore ( struct TArray<int> aiChosen )
{
	static UFunction* pFnSubmitStore = NULL;

	if ( ! pFnSubmitStore )
		pFnSubmitStore = (UFunction*) UObject::GObjObjects()->Data[ 38203 ];

	UISFXOnlineComponentLogin_execSubmitStore_Parms SubmitStore_Parms;
	memcpy ( &SubmitStore_Parms.aiChosen, &aiChosen, 0x10 );

	pFnSubmitStore->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubmitStore, &SubmitStore_Parms, NULL );

	pFnSubmitStore->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SubmitCreateNucleusAccountEx
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 sEmail                         ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sPassword                      ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bEAProducts                    ( CPF_Parm )
// unsigned long                  bThirdParty                    ( CPF_Parm )
// unsigned long                  bBioWareProducts               ( CPF_Parm )
// struct FString                 i_sCountryCode                 ( CPF_Parm | CPF_NeedCtorLink )
// int                            BirthDay                       ( CPF_Parm )
// int                            BirthMonth                     ( CPF_Parm )
// int                            BirthYear                      ( CPF_Parm )
// struct FString                 i_sLanguageCode                ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bSubmit                        ( CPF_Parm )

void UISFXOnlineComponentLogin::SubmitCreateNucleusAccountEx ( struct FString sEmail, struct FString sPassword, unsigned long bEAProducts, unsigned long bThirdParty, unsigned long bBioWareProducts, struct FString i_sCountryCode, int BirthDay, int BirthMonth, int BirthYear, struct FString i_sLanguageCode, unsigned long bSubmit )
{
	static UFunction* pFnSubmitCreateNucleusAccountEx = NULL;

	if ( ! pFnSubmitCreateNucleusAccountEx )
		pFnSubmitCreateNucleusAccountEx = (UFunction*) UObject::GObjObjects()->Data[ 38191 ];

	UISFXOnlineComponentLogin_execSubmitCreateNucleusAccountEx_Parms SubmitCreateNucleusAccountEx_Parms;
	memcpy ( &SubmitCreateNucleusAccountEx_Parms.sEmail, &sEmail, 0x10 );
	memcpy ( &SubmitCreateNucleusAccountEx_Parms.sPassword, &sPassword, 0x10 );
	SubmitCreateNucleusAccountEx_Parms.bEAProducts = bEAProducts;
	SubmitCreateNucleusAccountEx_Parms.bThirdParty = bThirdParty;
	SubmitCreateNucleusAccountEx_Parms.bBioWareProducts = bBioWareProducts;
	memcpy ( &SubmitCreateNucleusAccountEx_Parms.i_sCountryCode, &i_sCountryCode, 0x10 );
	SubmitCreateNucleusAccountEx_Parms.BirthDay = BirthDay;
	SubmitCreateNucleusAccountEx_Parms.BirthMonth = BirthMonth;
	SubmitCreateNucleusAccountEx_Parms.BirthYear = BirthYear;
	memcpy ( &SubmitCreateNucleusAccountEx_Parms.i_sLanguageCode, &i_sLanguageCode, 0x10 );
	SubmitCreateNucleusAccountEx_Parms.bSubmit = bSubmit;

	pFnSubmitCreateNucleusAccountEx->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubmitCreateNucleusAccountEx, &SubmitCreateNucleusAccountEx_Parms, NULL );

	pFnSubmitCreateNucleusAccountEx->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SubmitEmailPasswordMismatch
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 Email                          ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Password                       ( CPF_Parm | CPF_NeedCtorLink )
// int                            eReturnCode                    ( CPF_Parm )

void UISFXOnlineComponentLogin::SubmitEmailPasswordMismatch ( struct FString Email, struct FString Password, int eReturnCode )
{
	static UFunction* pFnSubmitEmailPasswordMismatch = NULL;

	if ( ! pFnSubmitEmailPasswordMismatch )
		pFnSubmitEmailPasswordMismatch = (UFunction*) UObject::GObjObjects()->Data[ 38187 ];

	UISFXOnlineComponentLogin_execSubmitEmailPasswordMismatch_Parms SubmitEmailPasswordMismatch_Parms;
	memcpy ( &SubmitEmailPasswordMismatch_Parms.Email, &Email, 0x10 );
	memcpy ( &SubmitEmailPasswordMismatch_Parms.Password, &Password, 0x10 );
	SubmitEmailPasswordMismatch_Parms.eReturnCode = eReturnCode;

	pFnSubmitEmailPasswordMismatch->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubmitEmailPasswordMismatch, &SubmitEmailPasswordMismatch_Parms, NULL );

	pFnSubmitEmailPasswordMismatch->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SubmitMessageBox
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            eReturnCode                    ( CPF_Parm )

void UISFXOnlineComponentLogin::SubmitMessageBox ( int eReturnCode )
{
	static UFunction* pFnSubmitMessageBox = NULL;

	if ( ! pFnSubmitMessageBox )
		pFnSubmitMessageBox = (UFunction*) UObject::GObjObjects()->Data[ 38185 ];

	UISFXOnlineComponentLogin_execSubmitMessageBox_Parms SubmitMessageBox_Parms;
	SubmitMessageBox_Parms.eReturnCode = eReturnCode;

	pFnSubmitMessageBox->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubmitMessageBox, &SubmitMessageBox_Parms, NULL );

	pFnSubmitMessageBox->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SubmitRedeemCode
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned long                  bContinue                      ( CPF_Parm )
// struct FString                 i_sCode                        ( CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentLogin::SubmitRedeemCode ( unsigned long bContinue, struct FString i_sCode )
{
	static UFunction* pFnSubmitRedeemCode = NULL;

	if ( ! pFnSubmitRedeemCode )
		pFnSubmitRedeemCode = (UFunction*) UObject::GObjObjects()->Data[ 38182 ];

	UISFXOnlineComponentLogin_execSubmitRedeemCode_Parms SubmitRedeemCode_Parms;
	SubmitRedeemCode_Parms.bContinue = bContinue;
	memcpy ( &SubmitRedeemCode_Parms.i_sCode, &i_sCode, 0x10 );

	pFnSubmitRedeemCode->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubmitRedeemCode, &SubmitRedeemCode_Parms, NULL );

	pFnSubmitRedeemCode->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SubmitCerberusWelcomeMessage
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentLogin::SubmitCerberusWelcomeMessage ( )
{
	static UFunction* pFnSubmitCerberusWelcomeMessage = NULL;

	if ( ! pFnSubmitCerberusWelcomeMessage )
		pFnSubmitCerberusWelcomeMessage = (UFunction*) UObject::GObjObjects()->Data[ 38181 ];

	UISFXOnlineComponentLogin_execSubmitCerberusWelcomeMessage_Parms SubmitCerberusWelcomeMessage_Parms;

	pFnSubmitCerberusWelcomeMessage->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubmitCerberusWelcomeMessage, &SubmitCerberusWelcomeMessage_Parms, NULL );

	pFnSubmitCerberusWelcomeMessage->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SubmitCerberusIntro
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            eReturnCode                    ( CPF_Parm )

void UISFXOnlineComponentLogin::SubmitCerberusIntro ( int eReturnCode )
{
	static UFunction* pFnSubmitCerberusIntro = NULL;

	if ( ! pFnSubmitCerberusIntro )
		pFnSubmitCerberusIntro = (UFunction*) UObject::GObjObjects()->Data[ 38179 ];

	UISFXOnlineComponentLogin_execSubmitCerberusIntro_Parms SubmitCerberusIntro_Parms;
	SubmitCerberusIntro_Parms.eReturnCode = eReturnCode;

	pFnSubmitCerberusIntro->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubmitCerberusIntro, &SubmitCerberusIntro_Parms, NULL );

	pFnSubmitCerberusIntro->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SubmitNucleusWelcomeMessage
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentLogin::SubmitNucleusWelcomeMessage ( )
{
	static UFunction* pFnSubmitNucleusWelcomeMessage = NULL;

	if ( ! pFnSubmitNucleusWelcomeMessage )
		pFnSubmitNucleusWelcomeMessage = (UFunction*) UObject::GObjObjects()->Data[ 38178 ];

	UISFXOnlineComponentLogin_execSubmitNucleusWelcomeMessage_Parms SubmitNucleusWelcomeMessage_Parms;

	pFnSubmitNucleusWelcomeMessage->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubmitNucleusWelcomeMessage, &SubmitNucleusWelcomeMessage_Parms, NULL );

	pFnSubmitNucleusWelcomeMessage->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SubmitCreateNucleusAccount
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 sEmail                         ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sPassword                      ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bEAProducts                    ( CPF_Parm )
// unsigned long                  bThirdParty                    ( CPF_Parm )
// unsigned long                  bBioWareProducts               ( CPF_Parm )
// unsigned long                  bSubmit                        ( CPF_Parm )

void UISFXOnlineComponentLogin::SubmitCreateNucleusAccount ( struct FString sEmail, struct FString sPassword, unsigned long bEAProducts, unsigned long bThirdParty, unsigned long bBioWareProducts, unsigned long bSubmit )
{
	static UFunction* pFnSubmitCreateNucleusAccount = NULL;

	if ( ! pFnSubmitCreateNucleusAccount )
		pFnSubmitCreateNucleusAccount = (UFunction*) UObject::GObjObjects()->Data[ 38171 ];

	UISFXOnlineComponentLogin_execSubmitCreateNucleusAccount_Parms SubmitCreateNucleusAccount_Parms;
	memcpy ( &SubmitCreateNucleusAccount_Parms.sEmail, &sEmail, 0x10 );
	memcpy ( &SubmitCreateNucleusAccount_Parms.sPassword, &sPassword, 0x10 );
	SubmitCreateNucleusAccount_Parms.bEAProducts = bEAProducts;
	SubmitCreateNucleusAccount_Parms.bThirdParty = bThirdParty;
	SubmitCreateNucleusAccount_Parms.bBioWareProducts = bBioWareProducts;
	SubmitCreateNucleusAccount_Parms.bSubmit = bSubmit;

	pFnSubmitCreateNucleusAccount->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubmitCreateNucleusAccount, &SubmitCreateNucleusAccount_Parms, NULL );

	pFnSubmitCreateNucleusAccount->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SubmitParentEmail
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned long                  bContinue                      ( CPF_Parm )
// struct FString                 ParentEmail                    ( CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentLogin::SubmitParentEmail ( unsigned long bContinue, struct FString ParentEmail )
{
	static UFunction* pFnSubmitParentEmail = NULL;

	if ( ! pFnSubmitParentEmail )
		pFnSubmitParentEmail = (UFunction*) UObject::GObjObjects()->Data[ 38168 ];

	UISFXOnlineComponentLogin_execSubmitParentEmail_Parms SubmitParentEmail_Parms;
	SubmitParentEmail_Parms.bContinue = bContinue;
	memcpy ( &SubmitParentEmail_Parms.ParentEmail, &ParentEmail, 0x10 );

	pFnSubmitParentEmail->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubmitParentEmail, &SubmitParentEmail_Parms, NULL );

	pFnSubmitParentEmail->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SubmitNucleusLogin
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 Email                          ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Password                       ( CPF_Parm | CPF_NeedCtorLink )
// unsigned char                  eReturnCode                    ( CPF_Parm )

void UISFXOnlineComponentLogin::SubmitNucleusLogin ( struct FString Email, struct FString Password, unsigned char eReturnCode )
{
	static UFunction* pFnSubmitNucleusLogin = NULL;

	if ( ! pFnSubmitNucleusLogin )
		pFnSubmitNucleusLogin = (UFunction*) UObject::GObjObjects()->Data[ 38164 ];

	UISFXOnlineComponentLogin_execSubmitNucleusLogin_Parms SubmitNucleusLogin_Parms;
	memcpy ( &SubmitNucleusLogin_Parms.Email, &Email, 0x10 );
	memcpy ( &SubmitNucleusLogin_Parms.Password, &Password, 0x10 );
	SubmitNucleusLogin_Parms.eReturnCode = eReturnCode;

	pFnSubmitNucleusLogin->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubmitNucleusLogin, &SubmitNucleusLogin_Parms, NULL );

	pFnSubmitNucleusLogin->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SubmitIntroPage
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned long                  bContinue                      ( CPF_Parm )
// unsigned long                  bSimulated                     ( CPF_Parm )

void UISFXOnlineComponentLogin::SubmitIntroPage ( unsigned long bContinue, unsigned long bSimulated )
{
	static UFunction* pFnSubmitIntroPage = NULL;

	if ( ! pFnSubmitIntroPage )
		pFnSubmitIntroPage = (UFunction*) UObject::GObjObjects()->Data[ 38161 ];

	UISFXOnlineComponentLogin_execSubmitIntroPage_Parms SubmitIntroPage_Parms;
	SubmitIntroPage_Parms.bContinue = bContinue;
	SubmitIntroPage_Parms.bSimulated = bSimulated;

	pFnSubmitIntroPage->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubmitIntroPage, &SubmitIntroPage_Parms, NULL );

	pFnSubmitIntroPage->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.Connect
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  connectMode                    ( CPF_Parm )

void UISFXOnlineComponentLogin::Connect ( unsigned char connectMode )
{
	static UFunction* pFnConnect = NULL;

	if ( ! pFnConnect )
		pFnConnect = (UFunction*) UObject::GObjObjects()->Data[ 38159 ];

	UISFXOnlineComponentLogin_execConnect_Parms Connect_Parms;
	Connect_Parms.connectMode = connectMode;

	pFnConnect->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnConnect, &Connect_Parms, NULL );

	pFnConnect->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.GoBackInUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentLogin::GoBackInUI ( )
{
	static UFunction* pFnGoBackInUI = NULL;

	if ( ! pFnGoBackInUI )
		pFnGoBackInUI = (UFunction*) UObject::GObjObjects()->Data[ 38158 ];

	UISFXOnlineComponentLogin_execGoBackInUI_Parms GoBackInUI_Parms;

	pFnGoBackInUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGoBackInUI, &GoBackInUI_Parms, NULL );

	pFnGoBackInUI->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.Cancel
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentLogin::Cancel ( )
{
	static UFunction* pFnCancel = NULL;

	if ( ! pFnCancel )
		pFnCancel = (UFunction*) UObject::GObjObjects()->Data[ 38157 ];

	UISFXOnlineComponentLogin_execCancel_Parms Cancel_Parms;

	pFnCancel->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCancel, &Cancel_Parms, NULL );

	pFnCancel->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.GetUserId
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FUniqueNetId            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FUniqueNetId UISFXOnlineComponentLogin::GetUserId ( )
{
	static UFunction* pFnGetUserId = NULL;

	if ( ! pFnGetUserId )
		pFnGetUserId = (UFunction*) UObject::GObjObjects()->Data[ 38155 ];

	UISFXOnlineComponentLogin_execGetUserId_Parms GetUserId_Parms;

	pFnGetUserId->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetUserId, &GetUserId_Parms, NULL );

	pFnGetUserId->FunctionFlags |= 0x400;

	return GetUserId_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.GetPersonaName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct FString UISFXOnlineComponentLogin::GetPersonaName ( )
{
	static UFunction* pFnGetPersonaName = NULL;

	if ( ! pFnGetPersonaName )
		pFnGetPersonaName = (UFunction*) UObject::GObjObjects()->Data[ 38153 ];

	UISFXOnlineComponentLogin_execGetPersonaName_Parms GetPersonaName_Parms;

	pFnGetPersonaName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetPersonaName, &GetPersonaName_Parms, NULL );

	pFnGetPersonaName->FunctionFlags |= 0x400;

	return GetPersonaName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.HasInternetConnection
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UISFXOnlineComponentLogin::HasInternetConnection ( )
{
	static UFunction* pFnHasInternetConnection = NULL;

	if ( ! pFnHasInternetConnection )
		pFnHasInternetConnection = (UFunction*) UObject::GObjObjects()->Data[ 38151 ];

	UISFXOnlineComponentLogin_execHasInternetConnection_Parms HasInternetConnection_Parms;

	pFnHasInternetConnection->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnHasInternetConnection, &HasInternetConnection_Parms, NULL );

	pFnHasInternetConnection->FunctionFlags |= 0x400;

	return HasInternetConnection_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.IsConnectedTo3rdPartyOnlineService
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UISFXOnlineComponentLogin::IsConnectedTo3rdPartyOnlineService ( )
{
	static UFunction* pFnIsConnectedTo3rdPartyOnlineService = NULL;

	if ( ! pFnIsConnectedTo3rdPartyOnlineService )
		pFnIsConnectedTo3rdPartyOnlineService = (UFunction*) UObject::GObjObjects()->Data[ 38149 ];

	UISFXOnlineComponentLogin_execIsConnectedTo3rdPartyOnlineService_Parms IsConnectedTo3rdPartyOnlineService_Parms;

	pFnIsConnectedTo3rdPartyOnlineService->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsConnectedTo3rdPartyOnlineService, &IsConnectedTo3rdPartyOnlineService_Parms, NULL );

	pFnIsConnectedTo3rdPartyOnlineService->FunctionFlags |= 0x400;

	return IsConnectedTo3rdPartyOnlineService_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.HasAccountFor3rdPartyOnlineService
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UISFXOnlineComponentLogin::HasAccountFor3rdPartyOnlineService ( )
{
	static UFunction* pFnHasAccountFor3rdPartyOnlineService = NULL;

	if ( ! pFnHasAccountFor3rdPartyOnlineService )
		pFnHasAccountFor3rdPartyOnlineService = (UFunction*) UObject::GObjObjects()->Data[ 38147 ];

	UISFXOnlineComponentLogin_execHasAccountFor3rdPartyOnlineService_Parms HasAccountFor3rdPartyOnlineService_Parms;

	pFnHasAccountFor3rdPartyOnlineService->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnHasAccountFor3rdPartyOnlineService, &HasAccountFor3rdPartyOnlineService_Parms, NULL );

	pFnHasAccountFor3rdPartyOnlineService->FunctionFlags |= 0x400;

	return HasAccountFor3rdPartyOnlineService_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.IsSignedIn
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UISFXOnlineComponentLogin::IsSignedIn ( )
{
	static UFunction* pFnIsSignedIn = NULL;

	if ( ! pFnIsSignedIn )
		pFnIsSignedIn = (UFunction*) UObject::GObjObjects()->Data[ 38145 ];

	UISFXOnlineComponentLogin_execIsSignedIn_Parms IsSignedIn_Parms;

	pFnIsSignedIn->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsSignedIn, &IsSignedIn_Parms, NULL );

	pFnIsSignedIn->FunctionFlags |= 0x400;

	return IsSignedIn_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.IsConnected
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UISFXOnlineComponentLogin::IsConnected ( )
{
	static UFunction* pFnIsConnected = NULL;

	if ( ! pFnIsConnected )
		pFnIsConnected = (UFunction*) UObject::GObjObjects()->Data[ 38143 ];

	UISFXOnlineComponentLogin_execIsConnected_Parms IsConnected_Parms;

	pFnIsConnected->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsConnected, &IsConnected_Parms, NULL );

	pFnIsConnected->FunctionFlags |= 0x400;

	return IsConnected_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.SwitchActiveUserIndex
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            nNewIndex                      ( CPF_Parm )

void UISFXOnlineComponentLogin::SwitchActiveUserIndex ( int nNewIndex )
{
	static UFunction* pFnSwitchActiveUserIndex = NULL;

	if ( ! pFnSwitchActiveUserIndex )
		pFnSwitchActiveUserIndex = (UFunction*) UObject::GObjObjects()->Data[ 38141 ];

	UISFXOnlineComponentLogin_execSwitchActiveUserIndex_Parms SwitchActiveUserIndex_Parms;
	SwitchActiveUserIndex_Parms.nNewIndex = nNewIndex;

	pFnSwitchActiveUserIndex->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSwitchActiveUserIndex, &SwitchActiveUserIndex_Parms, NULL );

	pFnSwitchActiveUserIndex->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.GetActiveUserIndex
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int UISFXOnlineComponentLogin::GetActiveUserIndex ( )
{
	static UFunction* pFnGetActiveUserIndex = NULL;

	if ( ! pFnGetActiveUserIndex )
		pFnGetActiveUserIndex = (UFunction*) UObject::GObjObjects()->Data[ 38139 ];

	UISFXOnlineComponentLogin_execGetActiveUserIndex_Parms GetActiveUserIndex_Parms;

	pFnGetActiveUserIndex->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetActiveUserIndex, &GetActiveUserIndex_Parms, NULL );

	pFnGetActiveUserIndex->FunctionFlags |= 0x400;

	return GetActiveUserIndex_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentLogin.GetLoginStatus
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char UISFXOnlineComponentLogin::GetLoginStatus ( )
{
	static UFunction* pFnGetLoginStatus = NULL;

	if ( ! pFnGetLoginStatus )
		pFnGetLoginStatus = (UFunction*) UObject::GObjObjects()->Data[ 38137 ];

	UISFXOnlineComponentLogin_execGetLoginStatus_Parms GetLoginStatus_Parms;

	pFnGetLoginStatus->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetLoginStatus, &GetLoginStatus_Parms, NULL );

	pFnGetLoginStatus->FunctionFlags |= 0x400;

	return GetLoginStatus_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentNotification.GetTargetOfferInfo
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FSFXOnlineTargetOfferInfo ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// unsigned char                  nSource                        ( CPF_Parm )

struct FSFXOnlineTargetOfferInfo UISFXOnlineComponentNotification::GetTargetOfferInfo ( unsigned char nSource )
{
	static UFunction* pFnGetTargetOfferInfo = NULL;

	if ( ! pFnGetTargetOfferInfo )
		pFnGetTargetOfferInfo = (UFunction*) UObject::GObjObjects()->Data[ 38296 ];

	UISFXOnlineComponentNotification_execGetTargetOfferInfo_Parms GetTargetOfferInfo_Parms;
	GetTargetOfferInfo_Parms.nSource = nSource;

	pFnGetTargetOfferInfo->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetTargetOfferInfo, &GetTargetOfferInfo_Parms, NULL );

	pFnGetTargetOfferInfo->FunctionFlags |= 0x400;

	return GetTargetOfferInfo_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentNotification.HasUserPurchasedAnOffer
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FSFXOnline_OfferID      aOfferId                       ( CPF_Parm )

unsigned char UISFXOnlineComponentNotification::HasUserPurchasedAnOffer ( struct FSFXOnline_OfferID aOfferId )
{
	static UFunction* pFnHasUserPurchasedAnOffer = NULL;

	if ( ! pFnHasUserPurchasedAnOffer )
		pFnHasUserPurchasedAnOffer = (UFunction*) UObject::GObjObjects()->Data[ 38293 ];

	UISFXOnlineComponentNotification_execHasUserPurchasedAnOffer_Parms HasUserPurchasedAnOffer_Parms;
	memcpy ( &HasUserPurchasedAnOffer_Parms.aOfferId, &aOfferId, 0x8 );

	pFnHasUserPurchasedAnOffer->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnHasUserPurchasedAnOffer, &HasUserPurchasedAnOffer_Parms, NULL );

	pFnHasUserPurchasedAnOffer->FunctionFlags |= 0x400;

	return HasUserPurchasedAnOffer_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentNotification.DownloadOffers
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct TArray<struct FSFXOnline_OfferID> aOfferIds                      ( CPF_Parm | CPF_NeedCtorLink )

bool UISFXOnlineComponentNotification::DownloadOffers ( struct TArray<struct FSFXOnline_OfferID> aOfferIds )
{
	static UFunction* pFnDownloadOffers = NULL;

	if ( ! pFnDownloadOffers )
		pFnDownloadOffers = (UFunction*) UObject::GObjObjects()->Data[ 38289 ];

	UISFXOnlineComponentNotification_execDownloadOffers_Parms DownloadOffers_Parms;
	memcpy ( &DownloadOffers_Parms.aOfferIds, &aOfferIds, 0x10 );

	pFnDownloadOffers->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnDownloadOffers, &DownloadOffers_Parms, NULL );

	pFnDownloadOffers->FunctionFlags |= 0x400;

	return DownloadOffers_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentNotification.GetOfferKeyIfEntitled
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// int                            internalId                     ( CPF_Parm )

struct FString UISFXOnlineComponentNotification::GetOfferKeyIfEntitled ( int internalId )
{
	static UFunction* pFnGetOfferKeyIfEntitled = NULL;

	if ( ! pFnGetOfferKeyIfEntitled )
		pFnGetOfferKeyIfEntitled = (UFunction*) UObject::GObjObjects()->Data[ 38286 ];

	UISFXOnlineComponentNotification_execGetOfferKeyIfEntitled_Parms GetOfferKeyIfEntitled_Parms;
	GetOfferKeyIfEntitled_Parms.internalId = internalId;

	pFnGetOfferKeyIfEntitled->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOfferKeyIfEntitled, &GetOfferKeyIfEntitled_Parms, NULL );

	pFnGetOfferKeyIfEntitled->FunctionFlags |= 0x400;

	return GetOfferKeyIfEntitled_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentNotification.GetGrantingOffers
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct TArray<struct FSFXOfferDescriptor> ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct TArray<struct FSFXOfferDescriptor> UISFXOnlineComponentNotification::GetGrantingOffers ( )
{
	static UFunction* pFnGetGrantingOffers = NULL;

	if ( ! pFnGetGrantingOffers )
		pFnGetGrantingOffers = (UFunction*) UObject::GObjObjects()->Data[ 38283 ];

	UISFXOnlineComponentNotification_execGetGrantingOffers_Parms GetGrantingOffers_Parms;

	pFnGetGrantingOffers->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetGrantingOffers, &GetGrantingOffers_Parms, NULL );

	pFnGetGrantingOffers->FunctionFlags |= 0x400;

	return GetGrantingOffers_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentNotification.GetEntitledDLCInfo
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct TArray<struct FSFXOfferDescriptor> ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct TArray<struct FSFXOfferDescriptor> UISFXOnlineComponentNotification::GetEntitledDLCInfo ( )
{
	static UFunction* pFnGetEntitledDLCInfo = NULL;

	if ( ! pFnGetEntitledDLCInfo )
		pFnGetEntitledDLCInfo = (UFunction*) UObject::GObjObjects()->Data[ 38280 ];

	UISFXOnlineComponentNotification_execGetEntitledDLCInfo_Parms GetEntitledDLCInfo_Parms;

	pFnGetEntitledDLCInfo->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetEntitledDLCInfo, &GetEntitledDLCInfo_Parms, NULL );

	pFnGetEntitledDLCInfo->FunctionFlags |= 0x400;

	return GetEntitledDLCInfo_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentNotification.RefreshEntitlementFlags
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentNotification::RefreshEntitlementFlags ( )
{
	static UFunction* pFnRefreshEntitlementFlags = NULL;

	if ( ! pFnRefreshEntitlementFlags )
		pFnRefreshEntitlementFlags = (UFunction*) UObject::GObjObjects()->Data[ 38279 ];

	UISFXOnlineComponentNotification_execRefreshEntitlementFlags_Parms RefreshEntitlementFlags_Parms;

	pFnRefreshEntitlementFlags->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnRefreshEntitlementFlags, &RefreshEntitlementFlags_Parms, NULL );

	pFnRefreshEntitlementFlags->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentNotification.GetEntitlementGroups
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct TArray<struct FSFXOnlineEntitlementGroupInfo> ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct TArray<struct FSFXOnlineEntitlementGroupInfo> UISFXOnlineComponentNotification::GetEntitlementGroups ( )
{
	static UFunction* pFnGetEntitlementGroups = NULL;

	if ( ! pFnGetEntitlementGroups )
		pFnGetEntitlementGroups = (UFunction*) UObject::GObjObjects()->Data[ 38276 ];

	UISFXOnlineComponentNotification_execGetEntitlementGroups_Parms GetEntitlementGroups_Parms;

	pFnGetEntitlementGroups->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetEntitlementGroups, &GetEntitlementGroups_Parms, NULL );

	pFnGetEntitlementGroups->FunctionFlags |= 0x400;

	return GetEntitlementGroups_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentNotification.GetDaysSinceCerberusRegistration
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int UISFXOnlineComponentNotification::GetDaysSinceCerberusRegistration ( )
{
	static UFunction* pFnGetDaysSinceCerberusRegistration = NULL;

	if ( ! pFnGetDaysSinceCerberusRegistration )
		pFnGetDaysSinceCerberusRegistration = (UFunction*) UObject::GObjObjects()->Data[ 38274 ];

	UISFXOnlineComponentNotification_execGetDaysSinceCerberusRegistration_Parms GetDaysSinceCerberusRegistration_Parms;

	pFnGetDaysSinceCerberusRegistration->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetDaysSinceCerberusRegistration, &GetDaysSinceCerberusRegistration_Parms, NULL );

	pFnGetDaysSinceCerberusRegistration->FunctionFlags |= 0x400;

	return GetDaysSinceCerberusRegistration_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentNotification.IsCalendarUnlockEarned
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nDay                           ( CPF_Parm )

bool UISFXOnlineComponentNotification::IsCalendarUnlockEarned ( int nDay )
{
	static UFunction* pFnIsCalendarUnlockEarned = NULL;

	if ( ! pFnIsCalendarUnlockEarned )
		pFnIsCalendarUnlockEarned = (UFunction*) UObject::GObjObjects()->Data[ 38271 ];

	UISFXOnlineComponentNotification_execIsCalendarUnlockEarned_Parms IsCalendarUnlockEarned_Parms;
	IsCalendarUnlockEarned_Parms.nDay = nDay;

	pFnIsCalendarUnlockEarned->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsCalendarUnlockEarned, &IsCalendarUnlockEarned_Parms, NULL );

	pFnIsCalendarUnlockEarned->FunctionFlags |= 0x400;

	return IsCalendarUnlockEarned_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentNotification.RequestServerInfo
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentNotification::RequestServerInfo ( )
{
	static UFunction* pFnRequestServerInfo = NULL;

	if ( ! pFnRequestServerInfo )
		pFnRequestServerInfo = (UFunction*) UObject::GObjObjects()->Data[ 38270 ];

	UISFXOnlineComponentNotification_execRequestServerInfo_Parms RequestServerInfo_Parms;

	pFnRequestServerInfo->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnRequestServerInfo, &RequestServerInfo_Parms, NULL );

	pFnRequestServerInfo->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentNotification.RequestData
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentNotification::RequestData ( )
{
	static UFunction* pFnRequestData = NULL;

	if ( ! pFnRequestData )
		pFnRequestData = (UFunction*) UObject::GObjObjects()->Data[ 38269 ];

	UISFXOnlineComponentNotification_execRequestData_Parms RequestData_Parms;

	pFnRequestData->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnRequestData, &RequestData_Parms, NULL );

	pFnRequestData->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.GetRebootUserData
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int UISFXOnlineComponentPlatform::GetRebootUserData ( )
{
	static UFunction* pFnGetRebootUserData = NULL;

	if ( ! pFnGetRebootUserData )
		pFnGetRebootUserData = (UFunction*) UObject::GObjObjects()->Data[ 38378 ];

	UISFXOnlineComponentPlatform_execGetRebootUserData_Parms GetRebootUserData_Parms;

	pFnGetRebootUserData->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetRebootUserData, &GetRebootUserData_Parms, NULL );

	pFnGetRebootUserData->FunctionFlags |= 0x400;

	return GetRebootUserData_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.WasRebootedFromOSCodeRedemptionUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UISFXOnlineComponentPlatform::WasRebootedFromOSCodeRedemptionUI ( )
{
	static UFunction* pFnWasRebootedFromOSCodeRedemptionUI = NULL;

	if ( ! pFnWasRebootedFromOSCodeRedemptionUI )
		pFnWasRebootedFromOSCodeRedemptionUI = (UFunction*) UObject::GObjObjects()->Data[ 38376 ];

	UISFXOnlineComponentPlatform_execWasRebootedFromOSCodeRedemptionUI_Parms WasRebootedFromOSCodeRedemptionUI_Parms;

	pFnWasRebootedFromOSCodeRedemptionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWasRebootedFromOSCodeRedemptionUI, &WasRebootedFromOSCodeRedemptionUI_Parms, NULL );

	pFnWasRebootedFromOSCodeRedemptionUI->FunctionFlags |= 0x400;

	return WasRebootedFromOSCodeRedemptionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.ShowCodeRedemptionUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            UserData                       ( CPF_Parm )

bool UISFXOnlineComponentPlatform::ShowCodeRedemptionUI ( int UserData )
{
	static UFunction* pFnShowCodeRedemptionUI = NULL;

	if ( ! pFnShowCodeRedemptionUI )
		pFnShowCodeRedemptionUI = (UFunction*) UObject::GObjObjects()->Data[ 38373 ];

	UISFXOnlineComponentPlatform_execShowCodeRedemptionUI_Parms ShowCodeRedemptionUI_Parms;
	ShowCodeRedemptionUI_Parms.UserData = UserData;

	pFnShowCodeRedemptionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowCodeRedemptionUI, &ShowCodeRedemptionUI_Parms, NULL );

	pFnShowCodeRedemptionUI->FunctionFlags |= 0x400;

	return ShowCodeRedemptionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.ShowStoreUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UISFXOnlineComponentPlatform::ShowStoreUI ( )
{
	static UFunction* pFnShowStoreUI = NULL;

	if ( ! pFnShowStoreUI )
		pFnShowStoreUI = (UFunction*) UObject::GObjObjects()->Data[ 38371 ];

	UISFXOnlineComponentPlatform_execShowStoreUI_Parms ShowStoreUI_Parms;

	pFnShowStoreUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowStoreUI, &ShowStoreUI_Parms, NULL );

	pFnShowStoreUI->FunctionFlags |= 0x400;

	return ShowStoreUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.GetOnlineXuid
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_Parm )
// struct FUniqueNetId            oUserXuid                      ( CPF_Parm | CPF_OutParm )

bool UISFXOnlineComponentPlatform::GetOnlineXuid ( int nUserIndex, struct FUniqueNetId* oUserXuid )
{
	static UFunction* pFnGetOnlineXuid = NULL;

	if ( ! pFnGetOnlineXuid )
		pFnGetOnlineXuid = (UFunction*) UObject::GObjObjects()->Data[ 38367 ];

	UISFXOnlineComponentPlatform_execGetOnlineXuid_Parms GetOnlineXuid_Parms;
	GetOnlineXuid_Parms.nUserIndex = nUserIndex;

	pFnGetOnlineXuid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOnlineXuid, &GetOnlineXuid_Parms, NULL );

	pFnGetOnlineXuid->FunctionFlags |= 0x400;

	if ( oUserXuid )
		memcpy ( oUserXuid, &GetOnlineXuid_Parms.oUserXuid, 0x8 );

	return GetOnlineXuid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.GetOfflineXuid
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_Parm )
// struct FUniqueNetId            oUserXuid                      ( CPF_Parm | CPF_OutParm )

bool UISFXOnlineComponentPlatform::GetOfflineXuid ( int nUserIndex, struct FUniqueNetId* oUserXuid )
{
	static UFunction* pFnGetOfflineXuid = NULL;

	if ( ! pFnGetOfflineXuid )
		pFnGetOfflineXuid = (UFunction*) UObject::GObjObjects()->Data[ 38363 ];

	UISFXOnlineComponentPlatform_execGetOfflineXuid_Parms GetOfflineXuid_Parms;
	GetOfflineXuid_Parms.nUserIndex = nUserIndex;

	pFnGetOfflineXuid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOfflineXuid, &GetOfflineXuid_Parms, NULL );

	pFnGetOfflineXuid->FunctionFlags |= 0x400;

	if ( oUserXuid )
		memcpy ( oUserXuid, &GetOfflineXuid_Parms.oUserXuid, 0x8 );

	return GetOfflineXuid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.AddRecentPlayer
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )
// struct FString                 sDescription                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool UISFXOnlineComponentPlatform::AddRecentPlayer ( struct FUniqueNetId oPlayerId, struct FString sDescription )
{
	static UFunction* pFnAddRecentPlayer = NULL;

	if ( ! pFnAddRecentPlayer )
		pFnAddRecentPlayer = (UFunction*) UObject::GObjObjects()->Data[ 38359 ];

	UISFXOnlineComponentPlatform_execAddRecentPlayer_Parms AddRecentPlayer_Parms;
	memcpy ( &AddRecentPlayer_Parms.oPlayerId, &oPlayerId, 0x8 );
	memcpy ( &AddRecentPlayer_Parms.sDescription, &sDescription, 0x10 );

	pFnAddRecentPlayer->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnAddRecentPlayer, &AddRecentPlayer_Parms, NULL );

	pFnAddRecentPlayer->FunctionFlags |= 0x400;

	return AddRecentPlayer_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.ShowKeyboardUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )
// struct FString                 sTitleText                     ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sDescriptionText               ( CPF_Parm | CPF_NeedCtorLink )
// unsigned char                  nKeyboardType                  ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldValidate                ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bRouteThroughConsole           ( CPF_OptionalParm | CPF_Parm )
// struct FString                 sDefaultText                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
// int                            nMaxResultLength               ( CPF_OptionalParm | CPF_Parm )

bool UISFXOnlineComponentPlatform::ShowKeyboardUI ( unsigned char byLocalUserNum, struct FString sTitleText, struct FString sDescriptionText, unsigned char nKeyboardType, unsigned long bShouldValidate, unsigned long bRouteThroughConsole, struct FString sDefaultText, int nMaxResultLength )
{
	static UFunction* pFnShowKeyboardUI = NULL;

	if ( ! pFnShowKeyboardUI )
		pFnShowKeyboardUI = (UFunction*) UObject::GObjObjects()->Data[ 38349 ];

	UISFXOnlineComponentPlatform_execShowKeyboardUI_Parms ShowKeyboardUI_Parms;
	ShowKeyboardUI_Parms.byLocalUserNum = byLocalUserNum;
	memcpy ( &ShowKeyboardUI_Parms.sTitleText, &sTitleText, 0x10 );
	memcpy ( &ShowKeyboardUI_Parms.sDescriptionText, &sDescriptionText, 0x10 );
	ShowKeyboardUI_Parms.nKeyboardType = nKeyboardType;
	ShowKeyboardUI_Parms.bShouldValidate = bShouldValidate;
	ShowKeyboardUI_Parms.bRouteThroughConsole = bRouteThroughConsole;
	memcpy ( &ShowKeyboardUI_Parms.sDefaultText, &sDefaultText, 0x10 );
	ShowKeyboardUI_Parms.nMaxResultLength = nMaxResultLength;

	pFnShowKeyboardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowKeyboardUI, &ShowKeyboardUI_Parms, NULL );

	pFnShowKeyboardUI->FunctionFlags |= 0x400;

	return ShowKeyboardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.ShowAchievementsUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

bool UISFXOnlineComponentPlatform::ShowAchievementsUI ( unsigned char byLocalUserNum )
{
	static UFunction* pFnShowAchievementsUI = NULL;

	if ( ! pFnShowAchievementsUI )
		pFnShowAchievementsUI = (UFunction*) UObject::GObjObjects()->Data[ 38346 ];

	UISFXOnlineComponentPlatform_execShowAchievementsUI_Parms ShowAchievementsUI_Parms;
	ShowAchievementsUI_Parms.byLocalUserNum = byLocalUserNum;

	pFnShowAchievementsUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowAchievementsUI, &ShowAchievementsUI_Parms, NULL );

	pFnShowAchievementsUI->FunctionFlags |= 0x400;

	return ShowAchievementsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.ShowFeedbackUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )

bool UISFXOnlineComponentPlatform::ShowFeedbackUI ( unsigned char byLocalUserNum, struct FUniqueNetId oPlayerId )
{
	static UFunction* pFnShowFeedbackUI = NULL;

	if ( ! pFnShowFeedbackUI )
		pFnShowFeedbackUI = (UFunction*) UObject::GObjObjects()->Data[ 38342 ];

	UISFXOnlineComponentPlatform_execShowFeedbackUI_Parms ShowFeedbackUI_Parms;
	ShowFeedbackUI_Parms.byLocalUserNum = byLocalUserNum;
	memcpy ( &ShowFeedbackUI_Parms.oPlayerId, &oPlayerId, 0x8 );

	pFnShowFeedbackUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFeedbackUI, &ShowFeedbackUI_Parms, NULL );

	pFnShowFeedbackUI->FunctionFlags |= 0x400;

	return ShowFeedbackUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.ShowGamerCardUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )

bool UISFXOnlineComponentPlatform::ShowGamerCardUI ( unsigned char byLocalUserNum, struct FUniqueNetId oPlayerId )
{
	static UFunction* pFnShowGamerCardUI = NULL;

	if ( ! pFnShowGamerCardUI )
		pFnShowGamerCardUI = (UFunction*) UObject::GObjObjects()->Data[ 38338 ];

	UISFXOnlineComponentPlatform_execShowGamerCardUI_Parms ShowGamerCardUI_Parms;
	ShowGamerCardUI_Parms.byLocalUserNum = byLocalUserNum;
	memcpy ( &ShowGamerCardUI_Parms.oPlayerId, &oPlayerId, 0x8 );

	pFnShowGamerCardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowGamerCardUI, &ShowGamerCardUI_Parms, NULL );

	pFnShowGamerCardUI->FunctionFlags |= 0x400;

	return ShowGamerCardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.ShowFriendsInviteUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )

bool UISFXOnlineComponentPlatform::ShowFriendsInviteUI ( unsigned char byLocalUserNum, struct FUniqueNetId oPlayerId )
{
	static UFunction* pFnShowFriendsInviteUI = NULL;

	if ( ! pFnShowFriendsInviteUI )
		pFnShowFriendsInviteUI = (UFunction*) UObject::GObjObjects()->Data[ 38334 ];

	UISFXOnlineComponentPlatform_execShowFriendsInviteUI_Parms ShowFriendsInviteUI_Parms;
	ShowFriendsInviteUI_Parms.byLocalUserNum = byLocalUserNum;
	memcpy ( &ShowFriendsInviteUI_Parms.oPlayerId, &oPlayerId, 0x8 );

	pFnShowFriendsInviteUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFriendsInviteUI, &ShowFriendsInviteUI_Parms, NULL );

	pFnShowFriendsInviteUI->FunctionFlags |= 0x400;

	return ShowFriendsInviteUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.ShowFriendsUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

bool UISFXOnlineComponentPlatform::ShowFriendsUI ( unsigned char byLocalUserNum )
{
	static UFunction* pFnShowFriendsUI = NULL;

	if ( ! pFnShowFriendsUI )
		pFnShowFriendsUI = (UFunction*) UObject::GObjObjects()->Data[ 38331 ];

	UISFXOnlineComponentPlatform_execShowFriendsUI_Parms ShowFriendsUI_Parms;
	ShowFriendsUI_Parms.byLocalUserNum = byLocalUserNum;

	pFnShowFriendsUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFriendsUI, &ShowFriendsUI_Parms, NULL );

	pFnShowFriendsUI->FunctionFlags |= 0x400;

	return ShowFriendsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.CanShowPresenceInformation
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

unsigned char UISFXOnlineComponentPlatform::CanShowPresenceInformation ( unsigned char byLocalUserNum )
{
	static UFunction* pFnCanShowPresenceInformation = NULL;

	if ( ! pFnCanShowPresenceInformation )
		pFnCanShowPresenceInformation = (UFunction*) UObject::GObjObjects()->Data[ 38328 ];

	UISFXOnlineComponentPlatform_execCanShowPresenceInformation_Parms CanShowPresenceInformation_Parms;
	CanShowPresenceInformation_Parms.byLocalUserNum = byLocalUserNum;

	pFnCanShowPresenceInformation->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanShowPresenceInformation, &CanShowPresenceInformation_Parms, NULL );

	pFnCanShowPresenceInformation->FunctionFlags |= 0x400;

	return CanShowPresenceInformation_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.CanViewPlayerProfiles
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

unsigned char UISFXOnlineComponentPlatform::CanViewPlayerProfiles ( unsigned char byLocalUserNum )
{
	static UFunction* pFnCanViewPlayerProfiles = NULL;

	if ( ! pFnCanViewPlayerProfiles )
		pFnCanViewPlayerProfiles = (UFunction*) UObject::GObjObjects()->Data[ 38325 ];

	UISFXOnlineComponentPlatform_execCanViewPlayerProfiles_Parms CanViewPlayerProfiles_Parms;
	CanViewPlayerProfiles_Parms.byLocalUserNum = byLocalUserNum;

	pFnCanViewPlayerProfiles->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanViewPlayerProfiles, &CanViewPlayerProfiles_Parms, NULL );

	pFnCanViewPlayerProfiles->FunctionFlags |= 0x400;

	return CanViewPlayerProfiles_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.CanPurchaseContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

unsigned char UISFXOnlineComponentPlatform::CanPurchaseContent ( unsigned char byLocalUserNum )
{
	static UFunction* pFnCanPurchaseContent = NULL;

	if ( ! pFnCanPurchaseContent )
		pFnCanPurchaseContent = (UFunction*) UObject::GObjObjects()->Data[ 38322 ];

	UISFXOnlineComponentPlatform_execCanPurchaseContent_Parms CanPurchaseContent_Parms;
	CanPurchaseContent_Parms.byLocalUserNum = byLocalUserNum;

	pFnCanPurchaseContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPurchaseContent, &CanPurchaseContent_Parms, NULL );

	pFnCanPurchaseContent->FunctionFlags |= 0x400;

	return CanPurchaseContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.CanDownloadUserContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

unsigned char UISFXOnlineComponentPlatform::CanDownloadUserContent ( unsigned char byLocalUserNum )
{
	static UFunction* pFnCanDownloadUserContent = NULL;

	if ( ! pFnCanDownloadUserContent )
		pFnCanDownloadUserContent = (UFunction*) UObject::GObjObjects()->Data[ 38319 ];

	UISFXOnlineComponentPlatform_execCanDownloadUserContent_Parms CanDownloadUserContent_Parms;
	CanDownloadUserContent_Parms.byLocalUserNum = byLocalUserNum;

	pFnCanDownloadUserContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanDownloadUserContent, &CanDownloadUserContent_Parms, NULL );

	pFnCanDownloadUserContent->FunctionFlags |= 0x400;

	return CanDownloadUserContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.CanCommunicate
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

unsigned char UISFXOnlineComponentPlatform::CanCommunicate ( unsigned char byLocalUserNum )
{
	static UFunction* pFnCanCommunicate = NULL;

	if ( ! pFnCanCommunicate )
		pFnCanCommunicate = (UFunction*) UObject::GObjObjects()->Data[ 38316 ];

	UISFXOnlineComponentPlatform_execCanCommunicate_Parms CanCommunicate_Parms;
	CanCommunicate_Parms.byLocalUserNum = byLocalUserNum;

	pFnCanCommunicate->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanCommunicate, &CanCommunicate_Parms, NULL );

	pFnCanCommunicate->FunctionFlags |= 0x400;

	return CanCommunicate_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.CanPlayOnline
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

unsigned char UISFXOnlineComponentPlatform::CanPlayOnline ( unsigned char byLocalUserNum )
{
	static UFunction* pFnCanPlayOnline = NULL;

	if ( ! pFnCanPlayOnline )
		pFnCanPlayOnline = (UFunction*) UObject::GObjObjects()->Data[ 38313 ];

	UISFXOnlineComponentPlatform_execCanPlayOnline_Parms CanPlayOnline_Parms;
	CanPlayOnline_Parms.byLocalUserNum = byLocalUserNum;

	pFnCanPlayOnline->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPlayOnline, &CanPlayOnline_Parms, NULL );

	pFnCanPlayOnline->FunctionFlags |= 0x400;

	return CanPlayOnline_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.SetRichPresence
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  byLocalUserNum                 ( CPF_Parm )
// int                            nPresenceMode                  ( CPF_Parm )
// struct TArray<struct FLocalizedStringSetting> aLocalizedStringSettings       ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
// struct TArray<struct FSettingsProperty> aProperties                    ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void UISFXOnlineComponentPlatform::SetRichPresence ( unsigned char byLocalUserNum, int nPresenceMode, struct TArray<struct FLocalizedStringSetting>* aLocalizedStringSettings, struct TArray<struct FSettingsProperty>* aProperties )
{
	static UFunction* pFnSetRichPresence = NULL;

	if ( ! pFnSetRichPresence )
		pFnSetRichPresence = (UFunction*) UObject::GObjObjects()->Data[ 38306 ];

	UISFXOnlineComponentPlatform_execSetRichPresence_Parms SetRichPresence_Parms;
	SetRichPresence_Parms.byLocalUserNum = byLocalUserNum;
	SetRichPresence_Parms.nPresenceMode = nPresenceMode;

	pFnSetRichPresence->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetRichPresence, &SetRichPresence_Parms, NULL );

	pFnSetRichPresence->FunctionFlags |= 0x400;

	if ( aLocalizedStringSettings )
		memcpy ( aLocalizedStringSettings, &SetRichPresence_Parms.aLocalizedStringSettings, 0x10 );

	if ( aProperties )
		memcpy ( aProperties, &SetRichPresence_Parms.aProperties, 0x10 );
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.ShowLoginUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned long                  bShowOnlineOnly                ( CPF_OptionalParm | CPF_Parm )

bool UISFXOnlineComponentPlatform::ShowLoginUI ( unsigned long bShowOnlineOnly )
{
	static UFunction* pFnShowLoginUI = NULL;

	if ( ! pFnShowLoginUI )
		pFnShowLoginUI = (UFunction*) UObject::GObjObjects()->Data[ 38303 ];

	UISFXOnlineComponentPlatform_execShowLoginUI_Parms ShowLoginUI_Parms;
	ShowLoginUI_Parms.bShowOnlineOnly = bShowOnlineOnly;

	pFnShowLoginUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowLoginUI, &ShowLoginUI_Parms, NULL );

	pFnShowLoginUI->FunctionFlags |= 0x400;

	return ShowLoginUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentPlatform.GetLoginStatus
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

unsigned char UISFXOnlineComponentPlatform::GetLoginStatus ( unsigned char byLocalUserNum )
{
	static UFunction* pFnGetLoginStatus = NULL;

	if ( ! pFnGetLoginStatus )
		pFnGetLoginStatus = (UFunction*) UObject::GObjObjects()->Data[ 38300 ];

	UISFXOnlineComponentPlatform_execGetLoginStatus_Parms GetLoginStatus_Parms;
	GetLoginStatus_Parms.byLocalUserNum = byLocalUserNum;

	pFnGetLoginStatus->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetLoginStatus, &GetLoginStatus_Parms, NULL );

	pFnGetLoginStatus->FunctionFlags |= 0x400;

	return GetLoginStatus_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentTelemetry.Flush
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  Channel                        ( CPF_Parm )

void UISFXOnlineComponentTelemetry::Flush ( unsigned char Channel )
{
	static UFunction* pFnFlush = NULL;

	if ( ! pFnFlush )
		pFnFlush = (UFunction*) UObject::GObjObjects()->Data[ 38400 ];

	UISFXOnlineComponentTelemetry_execFlush_Parms Flush_Parms;
	Flush_Parms.Channel = Channel;

	pFnFlush->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnFlush, &Flush_Parms, NULL );

	pFnFlush->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentTelemetry.RegisterConnectionDelegates
// [0x00020000] 
// Parameters infos:

void UISFXOnlineComponentTelemetry::RegisterConnectionDelegates ( )
{
	static UFunction* pFnRegisterConnectionDelegates = NULL;

	if ( ! pFnRegisterConnectionDelegates )
		pFnRegisterConnectionDelegates = (UFunction*) UObject::GObjObjects()->Data[ 38396 ];

	UISFXOnlineComponentTelemetry_execRegisterConnectionDelegates_Parms RegisterConnectionDelegates_Parms;

	this->ProcessEvent ( pFnRegisterConnectionDelegates, &RegisterConnectionDelegates_Parms, NULL );
};

// Function SFXOnlineFoundation.ISFXOnlineComponentTelemetry.OnDisconnect
// [0x00120000] 
// Parameters infos:
// int                            Error                          ( CPF_Parm )
// struct FString                 SessionId                      ( CPF_Const | CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentTelemetry::OnDisconnect ( int Error, struct FString SessionId )
{
	static UFunction* pFnOnDisconnect = NULL;

	if ( ! pFnOnDisconnect )
		pFnOnDisconnect = (UFunction*) UObject::GObjObjects()->Data[ 38393 ];

	UISFXOnlineComponentTelemetry_execOnDisconnect_Parms OnDisconnect_Parms;
	OnDisconnect_Parms.Error = Error;
	memcpy ( &OnDisconnect_Parms.SessionId, &SessionId, 0x10 );

	this->ProcessEvent ( pFnOnDisconnect, &OnDisconnect_Parms, NULL );
};

// Function SFXOnlineFoundation.ISFXOnlineComponentTelemetry.OnAuthenticate
// [0x00120000] 
// Parameters infos:

void UISFXOnlineComponentTelemetry::OnAuthenticate ( )
{
	static UFunction* pFnOnAuthenticate = NULL;

	if ( ! pFnOnAuthenticate )
		pFnOnAuthenticate = (UFunction*) UObject::GObjObjects()->Data[ 38392 ];

	UISFXOnlineComponentTelemetry_execOnAuthenticate_Parms OnAuthenticate_Parms;

	this->ProcessEvent ( pFnOnAuthenticate, &OnAuthenticate_Parms, NULL );
};

// Function SFXOnlineFoundation.ISFXOnlineComponentTelemetry.CanCollect
// [0x00120000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UISFXOnlineComponentTelemetry::CanCollect ( )
{
	static UFunction* pFnCanCollect = NULL;

	if ( ! pFnCanCollect )
		pFnCanCollect = (UFunction*) UObject::GObjObjects()->Data[ 38390 ];

	UISFXOnlineComponentTelemetry_execCanCollect_Parms CanCollect_Parms;

	this->ProcessEvent ( pFnCanCollect, &CanCollect_Parms, NULL );

	return CanCollect_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowStore
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// struct TArray<struct FSFXOfferDescriptor> aOffers                        ( CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentUserInterface::eventShowStore ( struct TArray<struct FSFXOfferDescriptor> aOffers )
{
	static UFunction* pFnShowStore = NULL;

	if ( ! pFnShowStore )
		pFnShowStore = (UFunction*) UObject::GObjObjects()->Data[ 38470 ];

	UISFXOnlineComponentUserInterface_eventShowStore_Parms ShowStore_Parms;
	memcpy ( &ShowStore_Parms.aOffers, &aOffers, 0x10 );

	this->ProcessEvent ( pFnShowStore, &ShowStore_Parms, NULL );
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.HasCerberusDLC
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// unsigned long                  bVal                           ( CPF_Parm )

void UISFXOnlineComponentUserInterface::eventHasCerberusDLC ( unsigned long bVal )
{
	static UFunction* pFnHasCerberusDLC = NULL;

	if ( ! pFnHasCerberusDLC )
		pFnHasCerberusDLC = (UFunction*) UObject::GObjObjects()->Data[ 38468 ];

	UISFXOnlineComponentUserInterface_eventHasCerberusDLC_Parms HasCerberusDLC_Parms;
	HasCerberusDLC_Parms.bVal = bVal;

	this->ProcessEvent ( pFnHasCerberusDLC, &HasCerberusDLC_Parms, NULL );
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.OnDisplayNotification
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// unsigned char                  Type                           ( CPF_Parm )
// struct FString                 MessageData                    ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Title                          ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Image                          ( CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentUserInterface::eventOnDisplayNotification ( unsigned char Type, struct FString MessageData, struct FString Title, struct FString Image )
{
	static UFunction* pFnOnDisplayNotification = NULL;

	if ( ! pFnOnDisplayNotification )
		pFnOnDisplayNotification = (UFunction*) UObject::GObjObjects()->Data[ 38463 ];

	UISFXOnlineComponentUserInterface_eventOnDisplayNotification_Parms OnDisplayNotification_Parms;
	OnDisplayNotification_Parms.Type = Type;
	memcpy ( &OnDisplayNotification_Parms.MessageData, &MessageData, 0x10 );
	memcpy ( &OnDisplayNotification_Parms.Title, &Title, 0x10 );
	memcpy ( &OnDisplayNotification_Parms.Image, &Image, 0x10 );

	this->ProcessEvent ( pFnOnDisplayNotification, &OnDisplayNotification_Parms, NULL );
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ClearNotifications
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void UISFXOnlineComponentUserInterface::eventClearNotifications ( )
{
	static UFunction* pFnClearNotifications = NULL;

	if ( ! pFnClearNotifications )
		pFnClearNotifications = (UFunction*) UObject::GObjObjects()->Data[ 38462 ];

	UISFXOnlineComponentUserInterface_eventClearNotifications_Parms ClearNotifications_Parms;

	this->ProcessEvent ( pFnClearNotifications, &ClearNotifications_Parms, NULL );
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.CloseEANetworking
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void UISFXOnlineComponentUserInterface::eventCloseEANetworking ( )
{
	static UFunction* pFnCloseEANetworking = NULL;

	if ( ! pFnCloseEANetworking )
		pFnCloseEANetworking = (UFunction*) UObject::GObjObjects()->Data[ 38461 ];

	UISFXOnlineComponentUserInterface_eventCloseEANetworking_Parms CloseEANetworking_Parms;

	this->ProcessEvent ( pFnCloseEANetworking, &CloseEANetworking_Parms, NULL );
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.SetState
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// unsigned char                  eState                         ( CPF_Parm )

void UISFXOnlineComponentUserInterface::eventSetState ( unsigned char eState )
{
	static UFunction* pFnSetState = NULL;

	if ( ! pFnSetState )
		pFnSetState = (UFunction*) UObject::GObjObjects()->Data[ 38459 ];

	UISFXOnlineComponentUserInterface_eventSetState_Parms SetState_Parms;
	SetState_Parms.eState = eState;

	this->ProcessEvent ( pFnSetState, &SetState_Parms, NULL );
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowEmailPasswordMismatch
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 Email                          ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Password                       ( CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentUserInterface::ShowEmailPasswordMismatch ( struct FString Email, struct FString Password )
{
	static UFunction* pFnShowEmailPasswordMismatch = NULL;

	if ( ! pFnShowEmailPasswordMismatch )
		pFnShowEmailPasswordMismatch = (UFunction*) UObject::GObjObjects()->Data[ 38456 ];

	UISFXOnlineComponentUserInterface_execShowEmailPasswordMismatch_Parms ShowEmailPasswordMismatch_Parms;
	memcpy ( &ShowEmailPasswordMismatch_Parms.Email, &Email, 0x10 );
	memcpy ( &ShowEmailPasswordMismatch_Parms.Password, &Password, 0x10 );

	pFnShowEmailPasswordMismatch->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowEmailPasswordMismatch, &ShowEmailPasswordMismatch_Parms, NULL );

	pFnShowEmailPasswordMismatch->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowMessageBoxWait
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            srMessage                      ( CPF_Parm )
// int                            srButton1Text                  ( CPF_Parm )
// int                            srButton2Text                  ( CPF_Parm )

void UISFXOnlineComponentUserInterface::ShowMessageBoxWait ( int srMessage, int srButton1Text, int srButton2Text )
{
	static UFunction* pFnShowMessageBoxWait = NULL;

	if ( ! pFnShowMessageBoxWait )
		pFnShowMessageBoxWait = (UFunction*) UObject::GObjObjects()->Data[ 38452 ];

	UISFXOnlineComponentUserInterface_execShowMessageBoxWait_Parms ShowMessageBoxWait_Parms;
	ShowMessageBoxWait_Parms.srMessage = srMessage;
	ShowMessageBoxWait_Parms.srButton1Text = srButton1Text;
	ShowMessageBoxWait_Parms.srButton2Text = srButton2Text;

	pFnShowMessageBoxWait->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowMessageBoxWait, &ShowMessageBoxWait_Parms, NULL );

	pFnShowMessageBoxWait->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowMessageBox
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// struct FString                 sTitle                         ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sMessage                       ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sButton1Text                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sButton2Text                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sButton3Text                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentUserInterface::ShowMessageBox ( struct FString sTitle, struct FString sMessage, struct FString sButton1Text, struct FString sButton2Text, struct FString sButton3Text )
{
	static UFunction* pFnShowMessageBox = NULL;

	if ( ! pFnShowMessageBox )
		pFnShowMessageBox = (UFunction*) UObject::GObjObjects()->Data[ 38446 ];

	UISFXOnlineComponentUserInterface_execShowMessageBox_Parms ShowMessageBox_Parms;
	memcpy ( &ShowMessageBox_Parms.sTitle, &sTitle, 0x10 );
	memcpy ( &ShowMessageBox_Parms.sMessage, &sMessage, 0x10 );
	memcpy ( &ShowMessageBox_Parms.sButton1Text, &sButton1Text, 0x10 );
	memcpy ( &ShowMessageBox_Parms.sButton2Text, &sButton2Text, 0x10 );
	memcpy ( &ShowMessageBox_Parms.sButton3Text, &sButton3Text, 0x10 );

	pFnShowMessageBox->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowMessageBox, &ShowMessageBox_Parms, NULL );

	pFnShowMessageBox->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowCreateNucleusAccountEx
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 sEmail                         ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sPassword                      ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bEAProducts                    ( CPF_Parm )
// unsigned long                  bThirdParty                    ( CPF_Parm )
// unsigned long                  bBioWareProducts               ( CPF_Parm )
// struct FString                 i_sCountryCode                 ( CPF_Parm | CPF_NeedCtorLink )
// int                            BirthDay                       ( CPF_Parm )
// int                            BirthMonth                     ( CPF_Parm )
// int                            BirthYear                      ( CPF_Parm )
// struct FString                 i_sLanguageCode                ( CPF_Parm | CPF_NeedCtorLink )
// struct TArray<struct FString>  m_CountryCodeList              ( CPF_Parm | CPF_NeedCtorLink )
// struct TArray<struct FString>  m_CountryDisplayList           ( CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentUserInterface::ShowCreateNucleusAccountEx ( struct FString sEmail, struct FString sPassword, unsigned long bEAProducts, unsigned long bThirdParty, unsigned long bBioWareProducts, struct FString i_sCountryCode, int BirthDay, int BirthMonth, int BirthYear, struct FString i_sLanguageCode, struct TArray<struct FString> m_CountryCodeList, struct TArray<struct FString> m_CountryDisplayList )
{
	static UFunction* pFnShowCreateNucleusAccountEx = NULL;

	if ( ! pFnShowCreateNucleusAccountEx )
		pFnShowCreateNucleusAccountEx = (UFunction*) UObject::GObjObjects()->Data[ 38431 ];

	UISFXOnlineComponentUserInterface_execShowCreateNucleusAccountEx_Parms ShowCreateNucleusAccountEx_Parms;
	memcpy ( &ShowCreateNucleusAccountEx_Parms.sEmail, &sEmail, 0x10 );
	memcpy ( &ShowCreateNucleusAccountEx_Parms.sPassword, &sPassword, 0x10 );
	ShowCreateNucleusAccountEx_Parms.bEAProducts = bEAProducts;
	ShowCreateNucleusAccountEx_Parms.bThirdParty = bThirdParty;
	ShowCreateNucleusAccountEx_Parms.bBioWareProducts = bBioWareProducts;
	memcpy ( &ShowCreateNucleusAccountEx_Parms.i_sCountryCode, &i_sCountryCode, 0x10 );
	ShowCreateNucleusAccountEx_Parms.BirthDay = BirthDay;
	ShowCreateNucleusAccountEx_Parms.BirthMonth = BirthMonth;
	ShowCreateNucleusAccountEx_Parms.BirthYear = BirthYear;
	memcpy ( &ShowCreateNucleusAccountEx_Parms.i_sLanguageCode, &i_sLanguageCode, 0x10 );
	memcpy ( &ShowCreateNucleusAccountEx_Parms.m_CountryCodeList, &m_CountryCodeList, 0x10 );
	memcpy ( &ShowCreateNucleusAccountEx_Parms.m_CountryDisplayList, &m_CountryDisplayList, 0x10 );

	pFnShowCreateNucleusAccountEx->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowCreateNucleusAccountEx, &ShowCreateNucleusAccountEx_Parms, NULL );

	pFnShowCreateNucleusAccountEx->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowCerberusWelcomeMessage
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentUserInterface::ShowCerberusWelcomeMessage ( )
{
	static UFunction* pFnShowCerberusWelcomeMessage = NULL;

	if ( ! pFnShowCerberusWelcomeMessage )
		pFnShowCerberusWelcomeMessage = (UFunction*) UObject::GObjObjects()->Data[ 38430 ];

	UISFXOnlineComponentUserInterface_execShowCerberusWelcomeMessage_Parms ShowCerberusWelcomeMessage_Parms;

	pFnShowCerberusWelcomeMessage->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowCerberusWelcomeMessage, &ShowCerberusWelcomeMessage_Parms, NULL );

	pFnShowCerberusWelcomeMessage->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowRedeemCode
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentUserInterface::ShowRedeemCode ( )
{
	static UFunction* pFnShowRedeemCode = NULL;

	if ( ! pFnShowRedeemCode )
		pFnShowRedeemCode = (UFunction*) UObject::GObjObjects()->Data[ 38429 ];

	UISFXOnlineComponentUserInterface_execShowRedeemCode_Parms ShowRedeemCode_Parms;

	pFnShowRedeemCode->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowRedeemCode, &ShowRedeemCode_Parms, NULL );

	pFnShowRedeemCode->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowCerberusIntro
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentUserInterface::ShowCerberusIntro ( )
{
	static UFunction* pFnShowCerberusIntro = NULL;

	if ( ! pFnShowCerberusIntro )
		pFnShowCerberusIntro = (UFunction*) UObject::GObjObjects()->Data[ 38428 ];

	UISFXOnlineComponentUserInterface_execShowCerberusIntro_Parms ShowCerberusIntro_Parms;

	pFnShowCerberusIntro->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowCerberusIntro, &ShowCerberusIntro_Parms, NULL );

	pFnShowCerberusIntro->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowNucleusWelcomeMessage
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentUserInterface::ShowNucleusWelcomeMessage ( )
{
	static UFunction* pFnShowNucleusWelcomeMessage = NULL;

	if ( ! pFnShowNucleusWelcomeMessage )
		pFnShowNucleusWelcomeMessage = (UFunction*) UObject::GObjObjects()->Data[ 38427 ];

	UISFXOnlineComponentUserInterface_execShowNucleusWelcomeMessage_Parms ShowNucleusWelcomeMessage_Parms;

	pFnShowNucleusWelcomeMessage->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowNucleusWelcomeMessage, &ShowNucleusWelcomeMessage_Parms, NULL );

	pFnShowNucleusWelcomeMessage->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowCreateNucleusAccount
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 sEmail                         ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sPassword                      ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bEAProducts                    ( CPF_Parm )
// unsigned long                  bThirdParty                    ( CPF_Parm )
// unsigned long                  bRegisterProduct               ( CPF_Parm )
// unsigned long                  bBioWareProducts               ( CPF_Parm )
// unsigned long                  bUnderage                      ( CPF_Parm )

void UISFXOnlineComponentUserInterface::ShowCreateNucleusAccount ( struct FString sEmail, struct FString sPassword, unsigned long bEAProducts, unsigned long bThirdParty, unsigned long bRegisterProduct, unsigned long bBioWareProducts, unsigned long bUnderage )
{
	static UFunction* pFnShowCreateNucleusAccount = NULL;

	if ( ! pFnShowCreateNucleusAccount )
		pFnShowCreateNucleusAccount = (UFunction*) UObject::GObjObjects()->Data[ 38419 ];

	UISFXOnlineComponentUserInterface_execShowCreateNucleusAccount_Parms ShowCreateNucleusAccount_Parms;
	memcpy ( &ShowCreateNucleusAccount_Parms.sEmail, &sEmail, 0x10 );
	memcpy ( &ShowCreateNucleusAccount_Parms.sPassword, &sPassword, 0x10 );
	ShowCreateNucleusAccount_Parms.bEAProducts = bEAProducts;
	ShowCreateNucleusAccount_Parms.bThirdParty = bThirdParty;
	ShowCreateNucleusAccount_Parms.bRegisterProduct = bRegisterProduct;
	ShowCreateNucleusAccount_Parms.bBioWareProducts = bBioWareProducts;
	ShowCreateNucleusAccount_Parms.bUnderage = bUnderage;

	pFnShowCreateNucleusAccount->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowCreateNucleusAccount, &ShowCreateNucleusAccount_Parms, NULL );

	pFnShowCreateNucleusAccount->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowParentEmail
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentUserInterface::ShowParentEmail ( )
{
	static UFunction* pFnShowParentEmail = NULL;

	if ( ! pFnShowParentEmail )
		pFnShowParentEmail = (UFunction*) UObject::GObjObjects()->Data[ 38418 ];

	UISFXOnlineComponentUserInterface_execShowParentEmail_Parms ShowParentEmail_Parms;

	pFnShowParentEmail->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowParentEmail, &ShowParentEmail_Parms, NULL );

	pFnShowParentEmail->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowAccountDemographics
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct TArray<struct FString>  m_CountryCodeList              ( CPF_Parm | CPF_NeedCtorLink )
// struct TArray<struct FString>  m_CountryDisplayList           ( CPF_Parm | CPF_NeedCtorLink )

void UISFXOnlineComponentUserInterface::ShowAccountDemographics ( struct TArray<struct FString> m_CountryCodeList, struct TArray<struct FString> m_CountryDisplayList )
{
	static UFunction* pFnShowAccountDemographics = NULL;

	if ( ! pFnShowAccountDemographics )
		pFnShowAccountDemographics = (UFunction*) UObject::GObjObjects()->Data[ 38413 ];

	UISFXOnlineComponentUserInterface_execShowAccountDemographics_Parms ShowAccountDemographics_Parms;
	memcpy ( &ShowAccountDemographics_Parms.m_CountryCodeList, &m_CountryCodeList, 0x10 );
	memcpy ( &ShowAccountDemographics_Parms.m_CountryDisplayList, &m_CountryDisplayList, 0x10 );

	pFnShowAccountDemographics->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowAccountDemographics, &ShowAccountDemographics_Parms, NULL );

	pFnShowAccountDemographics->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowTermsOfService
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// struct FString                 i_sTermsOfService              ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bTOSChanged                    ( CPF_OptionalParm | CPF_Parm )

void UISFXOnlineComponentUserInterface::ShowTermsOfService ( struct FString i_sTermsOfService, unsigned long bTOSChanged )
{
	static UFunction* pFnShowTermsOfService = NULL;

	if ( ! pFnShowTermsOfService )
		pFnShowTermsOfService = (UFunction*) UObject::GObjObjects()->Data[ 38410 ];

	UISFXOnlineComponentUserInterface_execShowTermsOfService_Parms ShowTermsOfService_Parms;
	memcpy ( &ShowTermsOfService_Parms.i_sTermsOfService, &i_sTermsOfService, 0x10 );
	ShowTermsOfService_Parms.bTOSChanged = bTOSChanged;

	pFnShowTermsOfService->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowTermsOfService, &ShowTermsOfService_Parms, NULL );

	pFnShowTermsOfService->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowNucleusLogin
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 Email                          ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Password                       ( CPF_Parm | CPF_NeedCtorLink )
// int                            eScreenState                   ( CPF_Parm )

void UISFXOnlineComponentUserInterface::ShowNucleusLogin ( struct FString Email, struct FString Password, int eScreenState )
{
	static UFunction* pFnShowNucleusLogin = NULL;

	if ( ! pFnShowNucleusLogin )
		pFnShowNucleusLogin = (UFunction*) UObject::GObjObjects()->Data[ 38406 ];

	UISFXOnlineComponentUserInterface_execShowNucleusLogin_Parms ShowNucleusLogin_Parms;
	memcpy ( &ShowNucleusLogin_Parms.Email, &Email, 0x10 );
	memcpy ( &ShowNucleusLogin_Parms.Password, &Password, 0x10 );
	ShowNucleusLogin_Parms.eScreenState = eScreenState;

	pFnShowNucleusLogin->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowNucleusLogin, &ShowNucleusLogin_Parms, NULL );

	pFnShowNucleusLogin->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.ISFXOnlineComponentUserInterface.ShowIntroPage
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UISFXOnlineComponentUserInterface::ShowIntroPage ( )
{
	static UFunction* pFnShowIntroPage = NULL;

	if ( ! pFnShowIntroPage )
		pFnShowIntroPage = (UFunction*) UObject::GObjObjects()->Data[ 38405 ];

	UISFXOnlineComponentUserInterface_execShowIntroPage_Parms ShowIntroPage_Parms;

	pFnShowIntroPage->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowIntroPage, &ShowIntroPage_Parms, NULL );

	pFnShowIntroPage->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.IsXbox360
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponent::eventIsXbox360 ( )
{
	static UFunction* pFnIsXbox360 = NULL;

	if ( ! pFnIsXbox360 )
		pFnIsXbox360 = (UFunction*) UObject::GObjObjects()->Data[ 38597 ];

	USFXOnlineComponent_eventIsXbox360_Parms IsXbox360_Parms;

	this->ProcessEvent ( pFnIsXbox360, &IsXbox360_Parms, NULL );

	return IsXbox360_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.IsPS3
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponent::eventIsPS3 ( )
{
	static UFunction* pFnIsPS3 = NULL;

	if ( ! pFnIsPS3 )
		pFnIsPS3 = (UFunction*) UObject::GObjObjects()->Data[ 38595 ];

	USFXOnlineComponent_eventIsPS3_Parms IsPS3_Parms;

	this->ProcessEvent ( pFnIsPS3, &IsPS3_Parms, NULL );

	return IsPS3_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.IsConsole
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponent::eventIsConsole ( )
{
	static UFunction* pFnIsConsole = NULL;

	if ( ! pFnIsConsole )
		pFnIsConsole = (UFunction*) UObject::GObjObjects()->Data[ 38593 ];

	USFXOnlineComponent_eventIsConsole_Parms IsConsole_Parms;

	this->ProcessEvent ( pFnIsConsole, &IsConsole_Parms, NULL );

	return IsConsole_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.IsEventPending
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eEventType                     ( CPF_Parm )
// int                            nEventId                       ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponent::IsEventPending ( unsigned char eEventType, int nEventId )
{
	static UFunction* pFnIsEventPending = NULL;

	if ( ! pFnIsEventPending )
		pFnIsEventPending = (UFunction*) UObject::GObjObjects()->Data[ 38589 ];

	USFXOnlineComponent_execIsEventPending_Parms IsEventPending_Parms;
	IsEventPending_Parms.eEventType = eEventType;
	IsEventPending_Parms.nEventId = nEventId;

	pFnIsEventPending->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsEventPending, &IsEventPending_Parms, NULL );

	pFnIsEventPending->FunctionFlags |= 0x400;

	return IsEventPending_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.GetEvent
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eEventType                     ( CPF_Parm )
// int                            nEventId                       ( CPF_OptionalParm | CPF_Parm )

class USFXOnlineEvent* USFXOnlineComponent::GetEvent ( unsigned char eEventType, int nEventId )
{
	static UFunction* pFnGetEvent = NULL;

	if ( ! pFnGetEvent )
		pFnGetEvent = (UFunction*) UObject::GObjObjects()->Data[ 38585 ];

	USFXOnlineComponent_execGetEvent_Parms GetEvent_Parms;
	GetEvent_Parms.eEventType = eEventType;
	GetEvent_Parms.nEventId = nEventId;

	pFnGetEvent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetEvent, &GetEvent_Parms, NULL );

	pFnGetEvent->FunctionFlags |= 0x400;

	return GetEvent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.WaitingForWorkSetObject
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct TArray<class USFXOnlineEvent*> aOnlineEventSet                ( CPF_Parm | CPF_NeedCtorLink )
// struct FScriptDelegate         fnWorkComplete                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponent::WaitingForWorkSetObject ( struct TArray<class USFXOnlineEvent*> aOnlineEventSet, struct FScriptDelegate fnWorkComplete )
{
	static UFunction* pFnWaitingForWorkSetObject = NULL;

	if ( ! pFnWaitingForWorkSetObject )
		pFnWaitingForWorkSetObject = (UFunction*) UObject::GObjObjects()->Data[ 38581 ];

	USFXOnlineComponent_execWaitingForWorkSetObject_Parms WaitingForWorkSetObject_Parms;
	memcpy ( &WaitingForWorkSetObject_Parms.aOnlineEventSet, &aOnlineEventSet, 0x10 );
	memcpy ( &WaitingForWorkSetObject_Parms.fnWorkComplete, &fnWorkComplete, 0x10 );

	pFnWaitingForWorkSetObject->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWaitingForWorkSetObject, &WaitingForWorkSetObject_Parms, NULL );

	pFnWaitingForWorkSetObject->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.WaitingForWorkSetType
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct TArray<unsigned char>   aWorkUnits                     ( CPF_Parm | CPF_NeedCtorLink )
// struct FScriptDelegate         fnWorkComplete                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponent::WaitingForWorkSetType ( struct TArray<unsigned char> aWorkUnits, struct FScriptDelegate fnWorkComplete )
{
	static UFunction* pFnWaitingForWorkSetType = NULL;

	if ( ! pFnWaitingForWorkSetType )
		pFnWaitingForWorkSetType = (UFunction*) UObject::GObjObjects()->Data[ 38577 ];

	USFXOnlineComponent_execWaitingForWorkSetType_Parms WaitingForWorkSetType_Parms;
	memcpy ( &WaitingForWorkSetType_Parms.aWorkUnits, &aWorkUnits, 0x10 );
	memcpy ( &WaitingForWorkSetType_Parms.fnWorkComplete, &fnWorkComplete, 0x10 );

	pFnWaitingForWorkSetType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWaitingForWorkSetType, &WaitingForWorkSetType_Parms, NULL );

	pFnWaitingForWorkSetType->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.WaitingForWorkObject
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )
// struct FScriptDelegate         fnWorkComplete                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponent::WaitingForWorkObject ( class USFXOnlineEvent* oEvent, struct FScriptDelegate fnWorkComplete )
{
	static UFunction* pFnWaitingForWorkObject = NULL;

	if ( ! pFnWaitingForWorkObject )
		pFnWaitingForWorkObject = (UFunction*) UObject::GObjObjects()->Data[ 38574 ];

	USFXOnlineComponent_execWaitingForWorkObject_Parms WaitingForWorkObject_Parms;
	WaitingForWorkObject_Parms.oEvent = oEvent;
	memcpy ( &WaitingForWorkObject_Parms.fnWorkComplete, &fnWorkComplete, 0x10 );

	pFnWaitingForWorkObject->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWaitingForWorkObject, &WaitingForWorkObject_Parms, NULL );

	pFnWaitingForWorkObject->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.WaitingForWorkType
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  eWork                          ( CPF_Parm )
// struct FScriptDelegate         fnWorkComplete                 ( CPF_Parm | CPF_NeedCtorLink )
// int                            nEventId                       ( CPF_OptionalParm | CPF_Parm )

void USFXOnlineComponent::WaitingForWorkType ( unsigned char eWork, struct FScriptDelegate fnWorkComplete, int nEventId )
{
	static UFunction* pFnWaitingForWorkType = NULL;

	if ( ! pFnWaitingForWorkType )
		pFnWaitingForWorkType = (UFunction*) UObject::GObjObjects()->Data[ 38570 ];

	USFXOnlineComponent_execWaitingForWorkType_Parms WaitingForWorkType_Parms;
	WaitingForWorkType_Parms.eWork = eWork;
	memcpy ( &WaitingForWorkType_Parms.fnWorkComplete, &fnWorkComplete, 0x10 );
	WaitingForWorkType_Parms.nEventId = nEventId;

	pFnWaitingForWorkType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWaitingForWorkType, &WaitingForWorkType_Parms, NULL );

	pFnWaitingForWorkType->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.NotifyWorkFinishedObject
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )
// unsigned char                  eStatusFinished                ( CPF_OptionalParm | CPF_Parm )

void USFXOnlineComponent::NotifyWorkFinishedObject ( class USFXOnlineEvent* oEvent, unsigned char eStatusFinished )
{
	static UFunction* pFnNotifyWorkFinishedObject = NULL;

	if ( ! pFnNotifyWorkFinishedObject )
		pFnNotifyWorkFinishedObject = (UFunction*) UObject::GObjObjects()->Data[ 38567 ];

	USFXOnlineComponent_execNotifyWorkFinishedObject_Parms NotifyWorkFinishedObject_Parms;
	NotifyWorkFinishedObject_Parms.oEvent = oEvent;
	NotifyWorkFinishedObject_Parms.eStatusFinished = eStatusFinished;

	pFnNotifyWorkFinishedObject->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNotifyWorkFinishedObject, &NotifyWorkFinishedObject_Parms, NULL );

	pFnNotifyWorkFinishedObject->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.NotifyWorkFinishedType
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  eWork                          ( CPF_Parm )
// unsigned char                  eStatusFinished                ( CPF_OptionalParm | CPF_Parm )
// int                            nEventId                       ( CPF_OptionalParm | CPF_Parm )

void USFXOnlineComponent::NotifyWorkFinishedType ( unsigned char eWork, unsigned char eStatusFinished, int nEventId )
{
	static UFunction* pFnNotifyWorkFinishedType = NULL;

	if ( ! pFnNotifyWorkFinishedType )
		pFnNotifyWorkFinishedType = (UFunction*) UObject::GObjObjects()->Data[ 38563 ];

	USFXOnlineComponent_execNotifyWorkFinishedType_Parms NotifyWorkFinishedType_Parms;
	NotifyWorkFinishedType_Parms.eWork = eWork;
	NotifyWorkFinishedType_Parms.eStatusFinished = eStatusFinished;
	NotifyWorkFinishedType_Parms.nEventId = nEventId;

	pFnNotifyWorkFinishedType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNotifyWorkFinishedType, &NotifyWorkFinishedType_Parms, NULL );

	pFnNotifyWorkFinishedType->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.NotifyWorkStartedObject
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )
// unsigned char                  eEventType                     ( CPF_OptionalParm | CPF_Parm )

void USFXOnlineComponent::NotifyWorkStartedObject ( class USFXOnlineEvent* oEvent, unsigned char eEventType )
{
	static UFunction* pFnNotifyWorkStartedObject = NULL;

	if ( ! pFnNotifyWorkStartedObject )
		pFnNotifyWorkStartedObject = (UFunction*) UObject::GObjObjects()->Data[ 38560 ];

	USFXOnlineComponent_execNotifyWorkStartedObject_Parms NotifyWorkStartedObject_Parms;
	NotifyWorkStartedObject_Parms.oEvent = oEvent;
	NotifyWorkStartedObject_Parms.eEventType = eEventType;

	pFnNotifyWorkStartedObject->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNotifyWorkStartedObject, &NotifyWorkStartedObject_Parms, NULL );

	pFnNotifyWorkStartedObject->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.NotifyWorkStartedType
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  eWork                          ( CPF_Parm )
// int                            nEventId                       ( CPF_OptionalParm | CPF_Parm )
// float                          fTimeOut                       ( CPF_OptionalParm | CPF_Parm )

void USFXOnlineComponent::NotifyWorkStartedType ( unsigned char eWork, int nEventId, float fTimeOut )
{
	static UFunction* pFnNotifyWorkStartedType = NULL;

	if ( ! pFnNotifyWorkStartedType )
		pFnNotifyWorkStartedType = (UFunction*) UObject::GObjObjects()->Data[ 38556 ];

	USFXOnlineComponent_execNotifyWorkStartedType_Parms NotifyWorkStartedType_Parms;
	NotifyWorkStartedType_Parms.eWork = eWork;
	NotifyWorkStartedType_Parms.nEventId = nEventId;
	NotifyWorkStartedType_Parms.fTimeOut = fTimeOut;

	pFnNotifyWorkStartedType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNotifyWorkStartedType, &NotifyWorkStartedType_Parms, NULL );

	pFnNotifyWorkStartedType->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.NotifyEventObject
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineComponent::NotifyEventObject ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnNotifyEventObject = NULL;

	if ( ! pFnNotifyEventObject )
		pFnNotifyEventObject = (UFunction*) UObject::GObjObjects()->Data[ 38554 ];

	USFXOnlineComponent_execNotifyEventObject_Parms NotifyEventObject_Parms;
	NotifyEventObject_Parms.oEvent = oEvent;

	pFnNotifyEventObject->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNotifyEventObject, &NotifyEventObject_Parms, NULL );

	pFnNotifyEventObject->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.NotifyEventType
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  eEventType                     ( CPF_Parm )
// unsigned char                  eStatus                        ( CPF_OptionalParm | CPF_Parm )
// unsigned char                  eOutcome                       ( CPF_OptionalParm | CPF_Parm )

void USFXOnlineComponent::NotifyEventType ( unsigned char eEventType, unsigned char eStatus, unsigned char eOutcome )
{
	static UFunction* pFnNotifyEventType = NULL;

	if ( ! pFnNotifyEventType )
		pFnNotifyEventType = (UFunction*) UObject::GObjObjects()->Data[ 38550 ];

	USFXOnlineComponent_execNotifyEventType_Parms NotifyEventType_Parms;
	NotifyEventType_Parms.eEventType = eEventType;
	NotifyEventType_Parms.eStatus = eStatus;
	NotifyEventType_Parms.eOutcome = eOutcome;

	pFnNotifyEventType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNotifyEventType, &NotifyEventType_Parms, NULL );

	pFnNotifyEventType->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.StopWaitingForAllWork
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class UObject*                 oCallbackTarget                ( CPF_Parm )

void USFXOnlineComponent::StopWaitingForAllWork ( class UObject* oCallbackTarget )
{
	static UFunction* pFnStopWaitingForAllWork = NULL;

	if ( ! pFnStopWaitingForAllWork )
		pFnStopWaitingForAllWork = (UFunction*) UObject::GObjObjects()->Data[ 38548 ];

	USFXOnlineComponent_execStopWaitingForAllWork_Parms StopWaitingForAllWork_Parms;
	StopWaitingForAllWork_Parms.oCallbackTarget = oCallbackTarget;

	pFnStopWaitingForAllWork->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnStopWaitingForAllWork, &StopWaitingForAllWork_Parms, NULL );

	pFnStopWaitingForAllWork->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.UnsubscribeFromAllEvents
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class UObject*                 oCallbackTarget                ( CPF_Parm )

void USFXOnlineComponent::UnsubscribeFromAllEvents ( class UObject* oCallbackTarget )
{
	static UFunction* pFnUnsubscribeFromAllEvents = NULL;

	if ( ! pFnUnsubscribeFromAllEvents )
		pFnUnsubscribeFromAllEvents = (UFunction*) UObject::GObjObjects()->Data[ 38546 ];

	USFXOnlineComponent_execUnsubscribeFromAllEvents_Parms UnsubscribeFromAllEvents_Parms;
	UnsubscribeFromAllEvents_Parms.oCallbackTarget = oCallbackTarget;

	pFnUnsubscribeFromAllEvents->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnUnsubscribeFromAllEvents, &UnsubscribeFromAllEvents_Parms, NULL );

	pFnUnsubscribeFromAllEvents->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.UnsubscribeFromEvent
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  oEventType                     ( CPF_Parm )
// struct FScriptDelegate         fnEventCallback                ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponent::UnsubscribeFromEvent ( unsigned char oEventType, struct FScriptDelegate fnEventCallback )
{
	static UFunction* pFnUnsubscribeFromEvent = NULL;

	if ( ! pFnUnsubscribeFromEvent )
		pFnUnsubscribeFromEvent = (UFunction*) UObject::GObjObjects()->Data[ 38543 ];

	USFXOnlineComponent_execUnsubscribeFromEvent_Parms UnsubscribeFromEvent_Parms;
	UnsubscribeFromEvent_Parms.oEventType = oEventType;
	memcpy ( &UnsubscribeFromEvent_Parms.fnEventCallback, &fnEventCallback, 0x10 );

	pFnUnsubscribeFromEvent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnUnsubscribeFromEvent, &UnsubscribeFromEvent_Parms, NULL );

	pFnUnsubscribeFromEvent->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.SubscribeToEvent
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  eEventType                     ( CPF_Parm )
// struct FScriptDelegate         fnEventCallback                ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponent::SubscribeToEvent ( unsigned char eEventType, struct FScriptDelegate fnEventCallback )
{
	static UFunction* pFnSubscribeToEvent = NULL;

	if ( ! pFnSubscribeToEvent )
		pFnSubscribeToEvent = (UFunction*) UObject::GObjObjects()->Data[ 38540 ];

	USFXOnlineComponent_execSubscribeToEvent_Parms SubscribeToEvent_Parms;
	SubscribeToEvent_Parms.eEventType = eEventType;
	memcpy ( &SubscribeToEvent_Parms.fnEventCallback, &fnEventCallback, 0x10 );

	pFnSubscribeToEvent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubscribeToEvent, &SubscribeToEvent_Parms, NULL );

	pFnSubscribeToEvent->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.OnEvent
// [0x00120000] 
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineComponent::OnEvent ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnOnEvent = NULL;

	if ( ! pFnOnEvent )
		pFnOnEvent = (UFunction*) UObject::GObjObjects()->Data[ 38538 ];

	USFXOnlineComponent_execOnEvent_Parms OnEvent_Parms;
	OnEvent_Parms.oEvent = oEvent;

	this->ProcessEvent ( pFnOnEvent, &OnEvent_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponent.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponent::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 38536 ];

	USFXOnlineComponent_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponent::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 38535 ];

	USFXOnlineComponent_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponent::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 38533 ];

	USFXOnlineComponent_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponent.SubscribeToEvents
// [0x00040401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void USFXOnlineComponent::SubscribeToEvents ( )
{
	static UFunction* pFnSubscribeToEvents = NULL;

	if ( ! pFnSubscribeToEvents )
		pFnSubscribeToEvents = (UFunction*) UObject::GObjObjects()->Data[ 38532 ];

	USFXOnlineComponent_execSubscribeToEvents_Parms SubscribeToEvents_Parms;

	pFnSubscribeToEvents->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubscribeToEvents, &SubscribeToEvents_Parms, NULL );

	pFnSubscribeToEvents->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentOrigin.OnTick
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentOrigin::OnTick ( )
{
	static UFunction* pFnOnTick = NULL;

	if ( ! pFnOnTick )
		pFnOnTick = (UFunction*) UObject::GObjObjects()->Data[ 38825 ];

	USFXOnlineComponentOrigin_execOnTick_Parms OnTick_Parms;

	pFnOnTick->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnTick, &OnTick_Parms, NULL );

	pFnOnTick->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentOrigin.RefreshServerAchievements_ASync
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FSFXCachedAchievements  cached                         ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

bool USFXOnlineComponentOrigin::RefreshServerAchievements_ASync ( struct FSFXCachedAchievements* cached )
{
	static UFunction* pFnRefreshServerAchievements_ASync = NULL;

	if ( ! pFnRefreshServerAchievements_ASync )
		pFnRefreshServerAchievements_ASync = (UFunction*) UObject::GObjObjects()->Data[ 38822 ];

	USFXOnlineComponentOrigin_execRefreshServerAchievements_ASync_Parms RefreshServerAchievements_ASync_Parms;

	pFnRefreshServerAchievements_ASync->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnRefreshServerAchievements_ASync, &RefreshServerAchievements_ASync_Parms, NULL );

	pFnRefreshServerAchievements_ASync->FunctionFlags |= 0x400;

	if ( cached )
		memcpy ( cached, &RefreshServerAchievements_ASync_Parms.cached, 0x24 );

	return RefreshServerAchievements_ASync_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentOrigin.SetRichPresence
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FString                 presence                       ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 gamePresence                   ( CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentOrigin::SetRichPresence ( struct FString presence, struct FString gamePresence )
{
	static UFunction* pFnSetRichPresence = NULL;

	if ( ! pFnSetRichPresence )
		pFnSetRichPresence = (UFunction*) UObject::GObjObjects()->Data[ 38797 ];

	USFXOnlineComponentOrigin_execSetRichPresence_Parms SetRichPresence_Parms;
	memcpy ( &SetRichPresence_Parms.presence, &presence, 0x10 );
	memcpy ( &SetRichPresence_Parms.gamePresence, &gamePresence, 0x10 );

	pFnSetRichPresence->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetRichPresence, &SetRichPresence_Parms, NULL );

	pFnSetRichPresence->FunctionFlags |= 0x400;

	return SetRichPresence_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentOrigin.RequestProfile
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentOrigin::RequestProfile ( )
{
	static UFunction* pFnRequestProfile = NULL;

	if ( ! pFnRequestProfile )
		pFnRequestProfile = (UFunction*) UObject::GObjObjects()->Data[ 38795 ];

	USFXOnlineComponentOrigin_execRequestProfile_Parms RequestProfile_Parms;

	pFnRequestProfile->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnRequestProfile, &RequestProfile_Parms, NULL );

	pFnRequestProfile->FunctionFlags |= 0x400;

	return RequestProfile_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentOrigin.StartService
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentOrigin::StartService ( )
{
	static UFunction* pFnStartService = NULL;

	if ( ! pFnStartService )
		pFnStartService = (UFunction*) UObject::GObjObjects()->Data[ 38793 ];

	USFXOnlineComponentOrigin_execStartService_Parms StartService_Parms;

	pFnStartService->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnStartService, &StartService_Parms, NULL );

	pFnStartService->FunctionFlags |= 0x400;

	return StartService_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentOrigin.EnsureSignedIn
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentOrigin::EnsureSignedIn ( )
{
	static UFunction* pFnEnsureSignedIn = NULL;

	if ( ! pFnEnsureSignedIn )
		pFnEnsureSignedIn = (UFunction*) UObject::GObjObjects()->Data[ 38791 ];

	USFXOnlineComponentOrigin_execEnsureSignedIn_Parms EnsureSignedIn_Parms;

	pFnEnsureSignedIn->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnEnsureSignedIn, &EnsureSignedIn_Parms, NULL );

	pFnEnsureSignedIn->FunctionFlags |= 0x400;

	return EnsureSignedIn_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentOrigin.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentOrigin::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 38789 ];

	USFXOnlineComponentOrigin_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentOrigin.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentOrigin::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 38788 ];

	USFXOnlineComponentOrigin_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentOrigin.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentOrigin::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 38786 ];

	USFXOnlineComponentOrigin_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearUnlockAchievementCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         UnlockAchievementCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearUnlockAchievementCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate UnlockAchievementCompleteDelegate )
{
	static UFunction* pFnClearUnlockAchievementCompleteDelegate = NULL;

	if ( ! pFnClearUnlockAchievementCompleteDelegate )
		pFnClearUnlockAchievementCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39761 ];

	USFXOnlineComponentUnrealPlayer_execClearUnlockAchievementCompleteDelegate_Parms ClearUnlockAchievementCompleteDelegate_Parms;
	ClearUnlockAchievementCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearUnlockAchievementCompleteDelegate_Parms.UnlockAchievementCompleteDelegate, &UnlockAchievementCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnClearUnlockAchievementCompleteDelegate, &ClearUnlockAchievementCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddUnlockAchievementCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         UnlockAchievementCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddUnlockAchievementCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate UnlockAchievementCompleteDelegate )
{
	static UFunction* pFnAddUnlockAchievementCompleteDelegate = NULL;

	if ( ! pFnAddUnlockAchievementCompleteDelegate )
		pFnAddUnlockAchievementCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39758 ];

	USFXOnlineComponentUnrealPlayer_execAddUnlockAchievementCompleteDelegate_Parms AddUnlockAchievementCompleteDelegate_Parms;
	AddUnlockAchievementCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddUnlockAchievementCompleteDelegate_Parms.UnlockAchievementCompleteDelegate, &UnlockAchievementCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnAddUnlockAchievementCompleteDelegate, &AddUnlockAchievementCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnUnlockAchievementComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnUnlockAchievementComplete ( unsigned long bWasSuccessful )
{
	static UFunction* pFnOnUnlockAchievementComplete = NULL;

	if ( ! pFnOnUnlockAchievementComplete )
		pFnOnUnlockAchievementComplete = (UFunction*) UObject::GObjObjects()->Data[ 39375 ];

	USFXOnlineComponentUnrealPlayer_execOnUnlockAchievementComplete_Parms OnUnlockAchievementComplete_Parms;
	OnUnlockAchievementComplete_Parms.bWasSuccessful = bWasSuccessful;

	this->ProcessEvent ( pFnOnUnlockAchievementComplete, &OnUnlockAchievementComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.UnlockAchievement
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::UnlockAchievement ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnUnlockAchievement = NULL;

	if ( ! pFnUnlockAchievement )
		pFnUnlockAchievement = (UFunction*) UObject::GObjObjects()->Data[ 39753 ];

	USFXOnlineComponentUnrealPlayer_execUnlockAchievement_Parms UnlockAchievement_Parms;
	UnlockAchievement_Parms.LocalUserNum = LocalUserNum;
	UnlockAchievement_Parms.AchievementId = AchievementId;

	pFnUnlockAchievement->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnUnlockAchievement, &UnlockAchievement_Parms, NULL );

	pFnUnlockAchievement->FunctionFlags |= 0x400;

	return UnlockAchievement_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.GetAchievements
// [0x00424400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            TitleId                        ( CPF_OptionalParm | CPF_Parm )
// int                            SetIndex                       ( CPF_OptionalParm | CPF_Parm )
// struct TArray<struct FAchievementDetails> Achievements                   ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

unsigned char USFXOnlineComponentUnrealPlayer::GetAchievements ( unsigned char LocalUserNum, int TitleId, int SetIndex, struct TArray<struct FAchievementDetails>* Achievements )
{
	static UFunction* pFnGetAchievements = NULL;

	if ( ! pFnGetAchievements )
		pFnGetAchievements = (UFunction*) UObject::GObjObjects()->Data[ 39746 ];

	USFXOnlineComponentUnrealPlayer_execGetAchievements_Parms GetAchievements_Parms;
	GetAchievements_Parms.LocalUserNum = LocalUserNum;
	GetAchievements_Parms.TitleId = TitleId;
	GetAchievements_Parms.SetIndex = SetIndex;

	pFnGetAchievements->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAchievements, &GetAchievements_Parms, NULL );

	pFnGetAchievements->FunctionFlags |= 0x400;

	if ( Achievements )
		memcpy ( Achievements, &GetAchievements_Parms.Achievements, 0x10 );

	return GetAchievements_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearReadAchievementsCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadAchievementsCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearReadAchievementsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadAchievementsCompleteDelegate )
{
	static UFunction* pFnClearReadAchievementsCompleteDelegate = NULL;

	if ( ! pFnClearReadAchievementsCompleteDelegate )
		pFnClearReadAchievementsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39742 ];

	USFXOnlineComponentUnrealPlayer_execClearReadAchievementsCompleteDelegate_Parms ClearReadAchievementsCompleteDelegate_Parms;
	ClearReadAchievementsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearReadAchievementsCompleteDelegate_Parms.ReadAchievementsCompleteDelegate, &ReadAchievementsCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnClearReadAchievementsCompleteDelegate, &ClearReadAchievementsCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddReadAchievementsCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadAchievementsCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddReadAchievementsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadAchievementsCompleteDelegate )
{
	static UFunction* pFnAddReadAchievementsCompleteDelegate = NULL;

	if ( ! pFnAddReadAchievementsCompleteDelegate )
		pFnAddReadAchievementsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39738 ];

	USFXOnlineComponentUnrealPlayer_execAddReadAchievementsCompleteDelegate_Parms AddReadAchievementsCompleteDelegate_Parms;
	AddReadAchievementsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddReadAchievementsCompleteDelegate_Parms.ReadAchievementsCompleteDelegate, &ReadAchievementsCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnAddReadAchievementsCompleteDelegate, &AddReadAchievementsCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnReadAchievementsComplete
// [0x00120000] 
// Parameters infos:
// int                            TitleId                        ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnReadAchievementsComplete ( int TitleId )
{
	static UFunction* pFnOnReadAchievementsComplete = NULL;

	if ( ! pFnOnReadAchievementsComplete )
		pFnOnReadAchievementsComplete = (UFunction*) UObject::GObjObjects()->Data[ 39378 ];

	USFXOnlineComponentUnrealPlayer_execOnReadAchievementsComplete_Parms OnReadAchievementsComplete_Parms;
	OnReadAchievementsComplete_Parms.TitleId = TitleId;

	this->ProcessEvent ( pFnOnReadAchievementsComplete, &OnReadAchievementsComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ReadAchievements
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            TitleId                        ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldReadText                ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldReadImages              ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::ReadAchievements ( unsigned char LocalUserNum, int TitleId, unsigned long bShouldReadText, unsigned long bShouldReadImages )
{
	static UFunction* pFnReadAchievements = NULL;

	if ( ! pFnReadAchievements )
		pFnReadAchievements = (UFunction*) UObject::GObjObjects()->Data[ 39731 ];

	USFXOnlineComponentUnrealPlayer_execReadAchievements_Parms ReadAchievements_Parms;
	ReadAchievements_Parms.LocalUserNum = LocalUserNum;
	ReadAchievements_Parms.TitleId = TitleId;
	ReadAchievements_Parms.bShouldReadText = bShouldReadText;
	ReadAchievements_Parms.bShouldReadImages = bShouldReadImages;

	pFnReadAchievements->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnReadAchievements, &ReadAchievements_Parms, NULL );

	pFnReadAchievements->FunctionFlags |= 0x400;

	return ReadAchievements_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.DeleteMessage
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            MessageIndex                   ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::DeleteMessage ( unsigned char LocalUserNum, int MessageIndex )
{
	static UFunction* pFnDeleteMessage = NULL;

	if ( ! pFnDeleteMessage )
		pFnDeleteMessage = (UFunction*) UObject::GObjObjects()->Data[ 39727 ];

	USFXOnlineComponentUnrealPlayer_execDeleteMessage_Parms DeleteMessage_Parms;
	DeleteMessage_Parms.LocalUserNum = LocalUserNum;
	DeleteMessage_Parms.MessageIndex = MessageIndex;

	this->ProcessEvent ( pFnDeleteMessage, &DeleteMessage_Parms, NULL );

	return DeleteMessage_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearFriendMessageReceivedDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         MessageDelegate                ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearFriendMessageReceivedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate MessageDelegate )
{
	static UFunction* pFnClearFriendMessageReceivedDelegate = NULL;

	if ( ! pFnClearFriendMessageReceivedDelegate )
		pFnClearFriendMessageReceivedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39724 ];

	USFXOnlineComponentUnrealPlayer_execClearFriendMessageReceivedDelegate_Parms ClearFriendMessageReceivedDelegate_Parms;
	ClearFriendMessageReceivedDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearFriendMessageReceivedDelegate_Parms.MessageDelegate, &MessageDelegate, 0x10 );

	this->ProcessEvent ( pFnClearFriendMessageReceivedDelegate, &ClearFriendMessageReceivedDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddFriendMessageReceivedDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         MessageDelegate                ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddFriendMessageReceivedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate MessageDelegate )
{
	static UFunction* pFnAddFriendMessageReceivedDelegate = NULL;

	if ( ! pFnAddFriendMessageReceivedDelegate )
		pFnAddFriendMessageReceivedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39721 ];

	USFXOnlineComponentUnrealPlayer_execAddFriendMessageReceivedDelegate_Parms AddFriendMessageReceivedDelegate_Parms;
	AddFriendMessageReceivedDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddFriendMessageReceivedDelegate_Parms.MessageDelegate, &MessageDelegate, 0x10 );

	this->ProcessEvent ( pFnAddFriendMessageReceivedDelegate, &AddFriendMessageReceivedDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnFriendMessageReceived
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            SendingPlayer                  ( CPF_Parm )
// struct FString                 SendingNick                    ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Message                        ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::OnFriendMessageReceived ( unsigned char LocalUserNum, struct FUniqueNetId SendingPlayer, struct FString SendingNick, struct FString Message )
{
	static UFunction* pFnOnFriendMessageReceived = NULL;

	if ( ! pFnOnFriendMessageReceived )
		pFnOnFriendMessageReceived = (UFunction*) UObject::GObjObjects()->Data[ 39716 ];

	USFXOnlineComponentUnrealPlayer_execOnFriendMessageReceived_Parms OnFriendMessageReceived_Parms;
	OnFriendMessageReceived_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &OnFriendMessageReceived_Parms.SendingPlayer, &SendingPlayer, 0x8 );
	memcpy ( &OnFriendMessageReceived_Parms.SendingNick, &SendingNick, 0x10 );
	memcpy ( &OnFriendMessageReceived_Parms.Message, &Message, 0x10 );

	this->ProcessEvent ( pFnOnFriendMessageReceived, &OnFriendMessageReceived_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.GetFriendMessages
// [0x00420000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct TArray<struct FOnlineFriendMessage> FriendMessages                 ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::GetFriendMessages ( unsigned char LocalUserNum, struct TArray<struct FOnlineFriendMessage>* FriendMessages )
{
	static UFunction* pFnGetFriendMessages = NULL;

	if ( ! pFnGetFriendMessages )
		pFnGetFriendMessages = (UFunction*) UObject::GObjObjects()->Data[ 39712 ];

	USFXOnlineComponentUnrealPlayer_execGetFriendMessages_Parms GetFriendMessages_Parms;
	GetFriendMessages_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnGetFriendMessages, &GetFriendMessages_Parms, NULL );

	if ( FriendMessages )
		memcpy ( FriendMessages, &GetFriendMessages_Parms.FriendMessages, 0x10 );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearJoinFriendGameCompleteDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         JoinFriendGameCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearJoinFriendGameCompleteDelegate ( struct FScriptDelegate JoinFriendGameCompleteDelegate )
{
	static UFunction* pFnClearJoinFriendGameCompleteDelegate = NULL;

	if ( ! pFnClearJoinFriendGameCompleteDelegate )
		pFnClearJoinFriendGameCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39710 ];

	USFXOnlineComponentUnrealPlayer_execClearJoinFriendGameCompleteDelegate_Parms ClearJoinFriendGameCompleteDelegate_Parms;
	memcpy ( &ClearJoinFriendGameCompleteDelegate_Parms.JoinFriendGameCompleteDelegate, &JoinFriendGameCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnClearJoinFriendGameCompleteDelegate, &ClearJoinFriendGameCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddJoinFriendGameCompleteDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         JoinFriendGameCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddJoinFriendGameCompleteDelegate ( struct FScriptDelegate JoinFriendGameCompleteDelegate )
{
	static UFunction* pFnAddJoinFriendGameCompleteDelegate = NULL;

	if ( ! pFnAddJoinFriendGameCompleteDelegate )
		pFnAddJoinFriendGameCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39708 ];

	USFXOnlineComponentUnrealPlayer_execAddJoinFriendGameCompleteDelegate_Parms AddJoinFriendGameCompleteDelegate_Parms;
	memcpy ( &AddJoinFriendGameCompleteDelegate_Parms.JoinFriendGameCompleteDelegate, &JoinFriendGameCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnAddJoinFriendGameCompleteDelegate, &AddJoinFriendGameCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnJoinFriendGameComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnJoinFriendGameComplete ( unsigned long bWasSuccessful )
{
	static UFunction* pFnOnJoinFriendGameComplete = NULL;

	if ( ! pFnOnJoinFriendGameComplete )
		pFnOnJoinFriendGameComplete = (UFunction*) UObject::GObjObjects()->Data[ 39706 ];

	USFXOnlineComponentUnrealPlayer_execOnJoinFriendGameComplete_Parms OnJoinFriendGameComplete_Parms;
	OnJoinFriendGameComplete_Parms.bWasSuccessful = bWasSuccessful;

	this->ProcessEvent ( pFnOnJoinFriendGameComplete, &OnJoinFriendGameComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.JoinFriendGame
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            Friend                         ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::JoinFriendGame ( unsigned char LocalUserNum, struct FUniqueNetId Friend )
{
	static UFunction* pFnJoinFriendGame = NULL;

	if ( ! pFnJoinFriendGame )
		pFnJoinFriendGame = (UFunction*) UObject::GObjObjects()->Data[ 39702 ];

	USFXOnlineComponentUnrealPlayer_execJoinFriendGame_Parms JoinFriendGame_Parms;
	JoinFriendGame_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &JoinFriendGame_Parms.Friend, &Friend, 0x8 );

	this->ProcessEvent ( pFnJoinFriendGame, &JoinFriendGame_Parms, NULL );

	return JoinFriendGame_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearReceivedGameInviteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReceivedGameInviteDelegate     ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearReceivedGameInviteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReceivedGameInviteDelegate )
{
	static UFunction* pFnClearReceivedGameInviteDelegate = NULL;

	if ( ! pFnClearReceivedGameInviteDelegate )
		pFnClearReceivedGameInviteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39699 ];

	USFXOnlineComponentUnrealPlayer_execClearReceivedGameInviteDelegate_Parms ClearReceivedGameInviteDelegate_Parms;
	ClearReceivedGameInviteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearReceivedGameInviteDelegate_Parms.ReceivedGameInviteDelegate, &ReceivedGameInviteDelegate, 0x10 );

	this->ProcessEvent ( pFnClearReceivedGameInviteDelegate, &ClearReceivedGameInviteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddReceivedGameInviteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReceivedGameInviteDelegate     ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddReceivedGameInviteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReceivedGameInviteDelegate )
{
	static UFunction* pFnAddReceivedGameInviteDelegate = NULL;

	if ( ! pFnAddReceivedGameInviteDelegate )
		pFnAddReceivedGameInviteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39696 ];

	USFXOnlineComponentUnrealPlayer_execAddReceivedGameInviteDelegate_Parms AddReceivedGameInviteDelegate_Parms;
	AddReceivedGameInviteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddReceivedGameInviteDelegate_Parms.ReceivedGameInviteDelegate, &ReceivedGameInviteDelegate, 0x10 );

	this->ProcessEvent ( pFnAddReceivedGameInviteDelegate, &AddReceivedGameInviteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnReceivedGameInvite
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 InviterName                    ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::OnReceivedGameInvite ( unsigned char LocalUserNum, struct FString InviterName )
{
	static UFunction* pFnOnReceivedGameInvite = NULL;

	if ( ! pFnOnReceivedGameInvite )
		pFnOnReceivedGameInvite = (UFunction*) UObject::GObjObjects()->Data[ 39693 ];

	USFXOnlineComponentUnrealPlayer_execOnReceivedGameInvite_Parms OnReceivedGameInvite_Parms;
	OnReceivedGameInvite_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &OnReceivedGameInvite_Parms.InviterName, &InviterName, 0x10 );

	this->ProcessEvent ( pFnOnReceivedGameInvite, &OnReceivedGameInvite_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.SendGameInviteToFriends
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct TArray<struct FUniqueNetId> Friends                        ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Text                           ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentUnrealPlayer::SendGameInviteToFriends ( unsigned char LocalUserNum, struct TArray<struct FUniqueNetId> Friends, struct FString Text )
{
	static UFunction* pFnSendGameInviteToFriends = NULL;

	if ( ! pFnSendGameInviteToFriends )
		pFnSendGameInviteToFriends = (UFunction*) UObject::GObjObjects()->Data[ 39687 ];

	USFXOnlineComponentUnrealPlayer_execSendGameInviteToFriends_Parms SendGameInviteToFriends_Parms;
	SendGameInviteToFriends_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &SendGameInviteToFriends_Parms.Friends, &Friends, 0x10 );
	memcpy ( &SendGameInviteToFriends_Parms.Text, &Text, 0x10 );

	this->ProcessEvent ( pFnSendGameInviteToFriends, &SendGameInviteToFriends_Parms, NULL );

	return SendGameInviteToFriends_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.SendGameInviteToFriend
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            Friend                         ( CPF_Parm )
// struct FString                 Text                           ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentUnrealPlayer::SendGameInviteToFriend ( unsigned char LocalUserNum, struct FUniqueNetId Friend, struct FString Text )
{
	static UFunction* pFnSendGameInviteToFriend = NULL;

	if ( ! pFnSendGameInviteToFriend )
		pFnSendGameInviteToFriend = (UFunction*) UObject::GObjObjects()->Data[ 39682 ];

	USFXOnlineComponentUnrealPlayer_execSendGameInviteToFriend_Parms SendGameInviteToFriend_Parms;
	SendGameInviteToFriend_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &SendGameInviteToFriend_Parms.Friend, &Friend, 0x8 );
	memcpy ( &SendGameInviteToFriend_Parms.Text, &Text, 0x10 );

	this->ProcessEvent ( pFnSendGameInviteToFriend, &SendGameInviteToFriend_Parms, NULL );

	return SendGameInviteToFriend_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.SendMessageToFriend
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            Friend                         ( CPF_Parm )
// struct FString                 Message                        ( CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentUnrealPlayer::SendMessageToFriend ( unsigned char LocalUserNum, struct FUniqueNetId Friend, struct FString Message )
{
	static UFunction* pFnSendMessageToFriend = NULL;

	if ( ! pFnSendMessageToFriend )
		pFnSendMessageToFriend = (UFunction*) UObject::GObjObjects()->Data[ 39677 ];

	USFXOnlineComponentUnrealPlayer_execSendMessageToFriend_Parms SendMessageToFriend_Parms;
	SendMessageToFriend_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &SendMessageToFriend_Parms.Friend, &Friend, 0x8 );
	memcpy ( &SendMessageToFriend_Parms.Message, &Message, 0x10 );

	this->ProcessEvent ( pFnSendMessageToFriend, &SendMessageToFriend_Parms, NULL );

	return SendMessageToFriend_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearFriendInviteReceivedDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         InviteDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearFriendInviteReceivedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate InviteDelegate )
{
	static UFunction* pFnClearFriendInviteReceivedDelegate = NULL;

	if ( ! pFnClearFriendInviteReceivedDelegate )
		pFnClearFriendInviteReceivedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39674 ];

	USFXOnlineComponentUnrealPlayer_execClearFriendInviteReceivedDelegate_Parms ClearFriendInviteReceivedDelegate_Parms;
	ClearFriendInviteReceivedDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearFriendInviteReceivedDelegate_Parms.InviteDelegate, &InviteDelegate, 0x10 );

	this->ProcessEvent ( pFnClearFriendInviteReceivedDelegate, &ClearFriendInviteReceivedDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddFriendInviteReceivedDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         InviteDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddFriendInviteReceivedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate InviteDelegate )
{
	static UFunction* pFnAddFriendInviteReceivedDelegate = NULL;

	if ( ! pFnAddFriendInviteReceivedDelegate )
		pFnAddFriendInviteReceivedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39671 ];

	USFXOnlineComponentUnrealPlayer_execAddFriendInviteReceivedDelegate_Parms AddFriendInviteReceivedDelegate_Parms;
	AddFriendInviteReceivedDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddFriendInviteReceivedDelegate_Parms.InviteDelegate, &InviteDelegate, 0x10 );

	this->ProcessEvent ( pFnAddFriendInviteReceivedDelegate, &AddFriendInviteReceivedDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnFriendInviteReceived
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            RequestingPlayer               ( CPF_Parm )
// struct FString                 RequestingNick                 ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Message                        ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::OnFriendInviteReceived ( unsigned char LocalUserNum, struct FUniqueNetId RequestingPlayer, struct FString RequestingNick, struct FString Message )
{
	static UFunction* pFnOnFriendInviteReceived = NULL;

	if ( ! pFnOnFriendInviteReceived )
		pFnOnFriendInviteReceived = (UFunction*) UObject::GObjObjects()->Data[ 39666 ];

	USFXOnlineComponentUnrealPlayer_execOnFriendInviteReceived_Parms OnFriendInviteReceived_Parms;
	OnFriendInviteReceived_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &OnFriendInviteReceived_Parms.RequestingPlayer, &RequestingPlayer, 0x8 );
	memcpy ( &OnFriendInviteReceived_Parms.RequestingNick, &RequestingNick, 0x10 );
	memcpy ( &OnFriendInviteReceived_Parms.Message, &Message, 0x10 );

	this->ProcessEvent ( pFnOnFriendInviteReceived, &OnFriendInviteReceived_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.RemoveFriend
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            FormerFriend                   ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::RemoveFriend ( unsigned char LocalUserNum, struct FUniqueNetId FormerFriend )
{
	static UFunction* pFnRemoveFriend = NULL;

	if ( ! pFnRemoveFriend )
		pFnRemoveFriend = (UFunction*) UObject::GObjObjects()->Data[ 39662 ];

	USFXOnlineComponentUnrealPlayer_execRemoveFriend_Parms RemoveFriend_Parms;
	RemoveFriend_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &RemoveFriend_Parms.FormerFriend, &FormerFriend, 0x8 );

	this->ProcessEvent ( pFnRemoveFriend, &RemoveFriend_Parms, NULL );

	return RemoveFriend_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.DenyFriendInvite
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            RequestingPlayer               ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::DenyFriendInvite ( unsigned char LocalUserNum, struct FUniqueNetId RequestingPlayer )
{
	static UFunction* pFnDenyFriendInvite = NULL;

	if ( ! pFnDenyFriendInvite )
		pFnDenyFriendInvite = (UFunction*) UObject::GObjObjects()->Data[ 39658 ];

	USFXOnlineComponentUnrealPlayer_execDenyFriendInvite_Parms DenyFriendInvite_Parms;
	DenyFriendInvite_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &DenyFriendInvite_Parms.RequestingPlayer, &RequestingPlayer, 0x8 );

	this->ProcessEvent ( pFnDenyFriendInvite, &DenyFriendInvite_Parms, NULL );

	return DenyFriendInvite_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AcceptFriendInvite
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            RequestingPlayer               ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::AcceptFriendInvite ( unsigned char LocalUserNum, struct FUniqueNetId RequestingPlayer )
{
	static UFunction* pFnAcceptFriendInvite = NULL;

	if ( ! pFnAcceptFriendInvite )
		pFnAcceptFriendInvite = (UFunction*) UObject::GObjObjects()->Data[ 39654 ];

	USFXOnlineComponentUnrealPlayer_execAcceptFriendInvite_Parms AcceptFriendInvite_Parms;
	AcceptFriendInvite_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AcceptFriendInvite_Parms.RequestingPlayer, &RequestingPlayer, 0x8 );

	this->ProcessEvent ( pFnAcceptFriendInvite, &AcceptFriendInvite_Parms, NULL );

	return AcceptFriendInvite_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearAddFriendByNameCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         FriendDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearAddFriendByNameCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate FriendDelegate )
{
	static UFunction* pFnClearAddFriendByNameCompleteDelegate = NULL;

	if ( ! pFnClearAddFriendByNameCompleteDelegate )
		pFnClearAddFriendByNameCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39651 ];

	USFXOnlineComponentUnrealPlayer_execClearAddFriendByNameCompleteDelegate_Parms ClearAddFriendByNameCompleteDelegate_Parms;
	ClearAddFriendByNameCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearAddFriendByNameCompleteDelegate_Parms.FriendDelegate, &FriendDelegate, 0x10 );

	this->ProcessEvent ( pFnClearAddFriendByNameCompleteDelegate, &ClearAddFriendByNameCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddAddFriendByNameCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         FriendDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddAddFriendByNameCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate FriendDelegate )
{
	static UFunction* pFnAddAddFriendByNameCompleteDelegate = NULL;

	if ( ! pFnAddAddFriendByNameCompleteDelegate )
		pFnAddAddFriendByNameCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39648 ];

	USFXOnlineComponentUnrealPlayer_execAddAddFriendByNameCompleteDelegate_Parms AddAddFriendByNameCompleteDelegate_Parms;
	AddAddFriendByNameCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddAddFriendByNameCompleteDelegate_Parms.FriendDelegate, &FriendDelegate, 0x10 );

	this->ProcessEvent ( pFnAddAddFriendByNameCompleteDelegate, &AddAddFriendByNameCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnAddFriendByNameComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnAddFriendByNameComplete ( unsigned long bWasSuccessful )
{
	static UFunction* pFnOnAddFriendByNameComplete = NULL;

	if ( ! pFnOnAddFriendByNameComplete )
		pFnOnAddFriendByNameComplete = (UFunction*) UObject::GObjObjects()->Data[ 39646 ];

	USFXOnlineComponentUnrealPlayer_execOnAddFriendByNameComplete_Parms OnAddFriendByNameComplete_Parms;
	OnAddFriendByNameComplete_Parms.bWasSuccessful = bWasSuccessful;

	this->ProcessEvent ( pFnOnAddFriendByNameComplete, &OnAddFriendByNameComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddFriendByName
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 FriendName                     ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Message                        ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentUnrealPlayer::AddFriendByName ( unsigned char LocalUserNum, struct FString FriendName, struct FString Message )
{
	static UFunction* pFnAddFriendByName = NULL;

	if ( ! pFnAddFriendByName )
		pFnAddFriendByName = (UFunction*) UObject::GObjObjects()->Data[ 39641 ];

	USFXOnlineComponentUnrealPlayer_execAddFriendByName_Parms AddFriendByName_Parms;
	AddFriendByName_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddFriendByName_Parms.FriendName, &FriendName, 0x10 );
	memcpy ( &AddFriendByName_Parms.Message, &Message, 0x10 );

	this->ProcessEvent ( pFnAddFriendByName, &AddFriendByName_Parms, NULL );

	return AddFriendByName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddFriend
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            NewFriend                      ( CPF_Parm )
// struct FString                 Message                        ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentUnrealPlayer::AddFriend ( unsigned char LocalUserNum, struct FUniqueNetId NewFriend, struct FString Message )
{
	static UFunction* pFnAddFriend = NULL;

	if ( ! pFnAddFriend )
		pFnAddFriend = (UFunction*) UObject::GObjObjects()->Data[ 39636 ];

	USFXOnlineComponentUnrealPlayer_execAddFriend_Parms AddFriend_Parms;
	AddFriend_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddFriend_Parms.NewFriend, &NewFriend, 0x8 );
	memcpy ( &AddFriend_Parms.Message, &Message, 0x10 );

	this->ProcessEvent ( pFnAddFriend, &AddFriend_Parms, NULL );

	return AddFriend_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.GetKeyboardInputResults
// [0x00420000] 
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// unsigned char                  bWasCanceled                   ( CPF_Parm | CPF_OutParm )

struct FString USFXOnlineComponentUnrealPlayer::GetKeyboardInputResults ( unsigned char* bWasCanceled )
{
	static UFunction* pFnGetKeyboardInputResults = NULL;

	if ( ! pFnGetKeyboardInputResults )
		pFnGetKeyboardInputResults = (UFunction*) UObject::GObjObjects()->Data[ 39633 ];

	USFXOnlineComponentUnrealPlayer_execGetKeyboardInputResults_Parms GetKeyboardInputResults_Parms;

	this->ProcessEvent ( pFnGetKeyboardInputResults, &GetKeyboardInputResults_Parms, NULL );

	if ( bWasCanceled )
		*bWasCanceled = GetKeyboardInputResults_Parms.bWasCanceled;

	return GetKeyboardInputResults_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearKeyboardInputDoneDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         InputDelegate                  ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearKeyboardInputDoneDelegate ( struct FScriptDelegate InputDelegate )
{
	static UFunction* pFnClearKeyboardInputDoneDelegate = NULL;

	if ( ! pFnClearKeyboardInputDoneDelegate )
		pFnClearKeyboardInputDoneDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39631 ];

	USFXOnlineComponentUnrealPlayer_execClearKeyboardInputDoneDelegate_Parms ClearKeyboardInputDoneDelegate_Parms;
	memcpy ( &ClearKeyboardInputDoneDelegate_Parms.InputDelegate, &InputDelegate, 0x10 );

	this->ProcessEvent ( pFnClearKeyboardInputDoneDelegate, &ClearKeyboardInputDoneDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddKeyboardInputDoneDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         InputDelegate                  ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddKeyboardInputDoneDelegate ( struct FScriptDelegate InputDelegate )
{
	static UFunction* pFnAddKeyboardInputDoneDelegate = NULL;

	if ( ! pFnAddKeyboardInputDoneDelegate )
		pFnAddKeyboardInputDoneDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39629 ];

	USFXOnlineComponentUnrealPlayer_execAddKeyboardInputDoneDelegate_Parms AddKeyboardInputDoneDelegate_Parms;
	memcpy ( &AddKeyboardInputDoneDelegate_Parms.InputDelegate, &InputDelegate, 0x10 );

	this->ProcessEvent ( pFnAddKeyboardInputDoneDelegate, &AddKeyboardInputDoneDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnKeyboardInputComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnKeyboardInputComplete ( unsigned long bWasSuccessful )
{
	static UFunction* pFnOnKeyboardInputComplete = NULL;

	if ( ! pFnOnKeyboardInputComplete )
		pFnOnKeyboardInputComplete = (UFunction*) UObject::GObjObjects()->Data[ 39627 ];

	USFXOnlineComponentUnrealPlayer_execOnKeyboardInputComplete_Parms OnKeyboardInputComplete_Parms;
	OnKeyboardInputComplete_Parms.bWasSuccessful = bWasSuccessful;

	this->ProcessEvent ( pFnOnKeyboardInputComplete, &OnKeyboardInputComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ShowKeyboardUI
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 TitleText                      ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 DescriptionText                ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bIsPassword                    ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldValidate                ( CPF_OptionalParm | CPF_Parm )
// struct FString                 DefaultText                    ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
// int                            MaxResultLength                ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::ShowKeyboardUI ( unsigned char LocalUserNum, struct FString TitleText, struct FString DescriptionText, unsigned long bIsPassword, unsigned long bShouldValidate, struct FString DefaultText, int MaxResultLength )
{
	static UFunction* pFnShowKeyboardUI = NULL;

	if ( ! pFnShowKeyboardUI )
		pFnShowKeyboardUI = (UFunction*) UObject::GObjObjects()->Data[ 39618 ];

	USFXOnlineComponentUnrealPlayer_execShowKeyboardUI_Parms ShowKeyboardUI_Parms;
	ShowKeyboardUI_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ShowKeyboardUI_Parms.TitleText, &TitleText, 0x10 );
	memcpy ( &ShowKeyboardUI_Parms.DescriptionText, &DescriptionText, 0x10 );
	ShowKeyboardUI_Parms.bIsPassword = bIsPassword;
	ShowKeyboardUI_Parms.bShouldValidate = bShouldValidate;
	memcpy ( &ShowKeyboardUI_Parms.DefaultText, &DefaultText, 0x10 );
	ShowKeyboardUI_Parms.MaxResultLength = MaxResultLength;

	this->ProcessEvent ( pFnShowKeyboardUI, &ShowKeyboardUI_Parms, NULL );

	return ShowKeyboardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.SetOnlineStatus
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            StatusId                       ( CPF_Parm )
// struct TArray<struct FLocalizedStringSetting> LocalizedStringSettings        ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
// struct TArray<struct FSettingsProperty> Properties                     ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::SetOnlineStatus ( unsigned char LocalUserNum, int StatusId, struct TArray<struct FLocalizedStringSetting>* LocalizedStringSettings, struct TArray<struct FSettingsProperty>* Properties )
{
	static UFunction* pFnSetOnlineStatus = NULL;

	if ( ! pFnSetOnlineStatus )
		pFnSetOnlineStatus = (UFunction*) UObject::GObjObjects()->Data[ 39611 ];

	USFXOnlineComponentUnrealPlayer_execSetOnlineStatus_Parms SetOnlineStatus_Parms;
	SetOnlineStatus_Parms.LocalUserNum = LocalUserNum;
	SetOnlineStatus_Parms.StatusId = StatusId;

	pFnSetOnlineStatus->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetOnlineStatus, &SetOnlineStatus_Parms, NULL );

	pFnSetOnlineStatus->FunctionFlags |= 0x400;

	if ( LocalizedStringSettings )
		memcpy ( LocalizedStringSettings, &SetOnlineStatus_Parms.LocalizedStringSettings, 0x10 );

	if ( Properties )
		memcpy ( Properties, &SetOnlineStatus_Parms.Properties, 0x10 );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.GetFriendsList
// [0x00424000] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            Count                          ( CPF_OptionalParm | CPF_Parm )
// int                            StartingAt                     ( CPF_OptionalParm | CPF_Parm )
// struct TArray<struct FOnlineFriend> Friends                        ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

unsigned char USFXOnlineComponentUnrealPlayer::GetFriendsList ( unsigned char LocalUserNum, int Count, int StartingAt, struct TArray<struct FOnlineFriend>* Friends )
{
	static UFunction* pFnGetFriendsList = NULL;

	if ( ! pFnGetFriendsList )
		pFnGetFriendsList = (UFunction*) UObject::GObjObjects()->Data[ 39604 ];

	USFXOnlineComponentUnrealPlayer_execGetFriendsList_Parms GetFriendsList_Parms;
	GetFriendsList_Parms.LocalUserNum = LocalUserNum;
	GetFriendsList_Parms.Count = Count;
	GetFriendsList_Parms.StartingAt = StartingAt;

	this->ProcessEvent ( pFnGetFriendsList, &GetFriendsList_Parms, NULL );

	if ( Friends )
		memcpy ( Friends, &GetFriendsList_Parms.Friends, 0x10 );

	return GetFriendsList_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearReadFriendsCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadFriendsCompleteDelegate    ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearReadFriendsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadFriendsCompleteDelegate )
{
	static UFunction* pFnClearReadFriendsCompleteDelegate = NULL;

	if ( ! pFnClearReadFriendsCompleteDelegate )
		pFnClearReadFriendsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39601 ];

	USFXOnlineComponentUnrealPlayer_execClearReadFriendsCompleteDelegate_Parms ClearReadFriendsCompleteDelegate_Parms;
	ClearReadFriendsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearReadFriendsCompleteDelegate_Parms.ReadFriendsCompleteDelegate, &ReadFriendsCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnClearReadFriendsCompleteDelegate, &ClearReadFriendsCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddReadFriendsCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadFriendsCompleteDelegate    ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddReadFriendsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadFriendsCompleteDelegate )
{
	static UFunction* pFnAddReadFriendsCompleteDelegate = NULL;

	if ( ! pFnAddReadFriendsCompleteDelegate )
		pFnAddReadFriendsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39598 ];

	USFXOnlineComponentUnrealPlayer_execAddReadFriendsCompleteDelegate_Parms AddReadFriendsCompleteDelegate_Parms;
	AddReadFriendsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddReadFriendsCompleteDelegate_Parms.ReadFriendsCompleteDelegate, &ReadFriendsCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnAddReadFriendsCompleteDelegate, &AddReadFriendsCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnReadFriendsComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnReadFriendsComplete ( unsigned long bWasSuccessful )
{
	static UFunction* pFnOnReadFriendsComplete = NULL;

	if ( ! pFnOnReadFriendsComplete )
		pFnOnReadFriendsComplete = (UFunction*) UObject::GObjObjects()->Data[ 39596 ];

	USFXOnlineComponentUnrealPlayer_execOnReadFriendsComplete_Parms OnReadFriendsComplete_Parms;
	OnReadFriendsComplete_Parms.bWasSuccessful = bWasSuccessful;

	this->ProcessEvent ( pFnOnReadFriendsComplete, &OnReadFriendsComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ReadFriendsList
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            Count                          ( CPF_OptionalParm | CPF_Parm )
// int                            StartingAt                     ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::ReadFriendsList ( unsigned char LocalUserNum, int Count, int StartingAt )
{
	static UFunction* pFnReadFriendsList = NULL;

	if ( ! pFnReadFriendsList )
		pFnReadFriendsList = (UFunction*) UObject::GObjObjects()->Data[ 39591 ];

	USFXOnlineComponentUnrealPlayer_execReadFriendsList_Parms ReadFriendsList_Parms;
	ReadFriendsList_Parms.LocalUserNum = LocalUserNum;
	ReadFriendsList_Parms.Count = Count;
	ReadFriendsList_Parms.StartingAt = StartingAt;

	this->ProcessEvent ( pFnReadFriendsList, &ReadFriendsList_Parms, NULL );

	return ReadFriendsList_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearWritePlayerStorageCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         WritePlayerStorageCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearWritePlayerStorageCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate WritePlayerStorageCompleteDelegate )
{
	static UFunction* pFnClearWritePlayerStorageCompleteDelegate = NULL;

	if ( ! pFnClearWritePlayerStorageCompleteDelegate )
		pFnClearWritePlayerStorageCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39587 ];

	USFXOnlineComponentUnrealPlayer_execClearWritePlayerStorageCompleteDelegate_Parms ClearWritePlayerStorageCompleteDelegate_Parms;
	ClearWritePlayerStorageCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearWritePlayerStorageCompleteDelegate_Parms.WritePlayerStorageCompleteDelegate, &WritePlayerStorageCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnClearWritePlayerStorageCompleteDelegate, &ClearWritePlayerStorageCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddWritePlayerStorageCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         WritePlayerStorageCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddWritePlayerStorageCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate WritePlayerStorageCompleteDelegate )
{
	static UFunction* pFnAddWritePlayerStorageCompleteDelegate = NULL;

	if ( ! pFnAddWritePlayerStorageCompleteDelegate )
		pFnAddWritePlayerStorageCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39584 ];

	USFXOnlineComponentUnrealPlayer_execAddWritePlayerStorageCompleteDelegate_Parms AddWritePlayerStorageCompleteDelegate_Parms;
	AddWritePlayerStorageCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddWritePlayerStorageCompleteDelegate_Parms.WritePlayerStorageCompleteDelegate, &WritePlayerStorageCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnAddWritePlayerStorageCompleteDelegate, &AddWritePlayerStorageCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnWritePlayerStorageComplete
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnWritePlayerStorageComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful )
{
	static UFunction* pFnOnWritePlayerStorageComplete = NULL;

	if ( ! pFnOnWritePlayerStorageComplete )
		pFnOnWritePlayerStorageComplete = (UFunction*) UObject::GObjObjects()->Data[ 39356 ];

	USFXOnlineComponentUnrealPlayer_execOnWritePlayerStorageComplete_Parms OnWritePlayerStorageComplete_Parms;
	OnWritePlayerStorageComplete_Parms.LocalUserNum = LocalUserNum;
	OnWritePlayerStorageComplete_Parms.bWasSuccessful = bWasSuccessful;

	this->ProcessEvent ( pFnOnWritePlayerStorageComplete, &OnWritePlayerStorageComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.WritePlayerStorage
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// class UOnlinePlayerStorage*    PlayerStorage                  ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::WritePlayerStorage ( unsigned char LocalUserNum, class UOnlinePlayerStorage* PlayerStorage )
{
	static UFunction* pFnWritePlayerStorage = NULL;

	if ( ! pFnWritePlayerStorage )
		pFnWritePlayerStorage = (UFunction*) UObject::GObjObjects()->Data[ 39578 ];

	USFXOnlineComponentUnrealPlayer_execWritePlayerStorage_Parms WritePlayerStorage_Parms;
	WritePlayerStorage_Parms.LocalUserNum = LocalUserNum;
	WritePlayerStorage_Parms.PlayerStorage = PlayerStorage;

	pFnWritePlayerStorage->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWritePlayerStorage, &WritePlayerStorage_Parms, NULL );

	pFnWritePlayerStorage->FunctionFlags |= 0x400;

	return WritePlayerStorage_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.GetPlayerStorage
// [0x00020002] 
// Parameters infos:
// class UOnlinePlayerStorage*    ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

class UOnlinePlayerStorage* USFXOnlineComponentUnrealPlayer::GetPlayerStorage ( unsigned char LocalUserNum )
{
	static UFunction* pFnGetPlayerStorage = NULL;

	if ( ! pFnGetPlayerStorage )
		pFnGetPlayerStorage = (UFunction*) UObject::GObjObjects()->Data[ 39574 ];

	USFXOnlineComponentUnrealPlayer_execGetPlayerStorage_Parms GetPlayerStorage_Parms;
	GetPlayerStorage_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnGetPlayerStorage, &GetPlayerStorage_Parms, NULL );

	return GetPlayerStorage_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearReadPlayerStorageForNetIdCompleteDelegate
// [0x00020002] 
// Parameters infos:
// struct FUniqueNetId            NetId                          ( CPF_Parm )
// struct FScriptDelegate         ReadPlayerStorageForNetIdCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearReadPlayerStorageForNetIdCompleteDelegate ( struct FUniqueNetId NetId, struct FScriptDelegate ReadPlayerStorageForNetIdCompleteDelegate )
{
	static UFunction* pFnClearReadPlayerStorageForNetIdCompleteDelegate = NULL;

	if ( ! pFnClearReadPlayerStorageForNetIdCompleteDelegate )
		pFnClearReadPlayerStorageForNetIdCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39570 ];

	USFXOnlineComponentUnrealPlayer_execClearReadPlayerStorageForNetIdCompleteDelegate_Parms ClearReadPlayerStorageForNetIdCompleteDelegate_Parms;
	memcpy ( &ClearReadPlayerStorageForNetIdCompleteDelegate_Parms.NetId, &NetId, 0x8 );
	memcpy ( &ClearReadPlayerStorageForNetIdCompleteDelegate_Parms.ReadPlayerStorageForNetIdCompleteDelegate, &ReadPlayerStorageForNetIdCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnClearReadPlayerStorageForNetIdCompleteDelegate, &ClearReadPlayerStorageForNetIdCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddReadPlayerStorageForNetIdCompleteDelegate
// [0x00020002] 
// Parameters infos:
// struct FUniqueNetId            NetId                          ( CPF_Parm )
// struct FScriptDelegate         ReadPlayerStorageForNetIdCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddReadPlayerStorageForNetIdCompleteDelegate ( struct FUniqueNetId NetId, struct FScriptDelegate ReadPlayerStorageForNetIdCompleteDelegate )
{
	static UFunction* pFnAddReadPlayerStorageForNetIdCompleteDelegate = NULL;

	if ( ! pFnAddReadPlayerStorageForNetIdCompleteDelegate )
		pFnAddReadPlayerStorageForNetIdCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39567 ];

	USFXOnlineComponentUnrealPlayer_execAddReadPlayerStorageForNetIdCompleteDelegate_Parms AddReadPlayerStorageForNetIdCompleteDelegate_Parms;
	memcpy ( &AddReadPlayerStorageForNetIdCompleteDelegate_Parms.NetId, &NetId, 0x8 );
	memcpy ( &AddReadPlayerStorageForNetIdCompleteDelegate_Parms.ReadPlayerStorageForNetIdCompleteDelegate, &ReadPlayerStorageForNetIdCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnAddReadPlayerStorageForNetIdCompleteDelegate, &AddReadPlayerStorageForNetIdCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnReadPlayerStorageForNetIdComplete
// [0x00120000] 
// Parameters infos:
// struct FUniqueNetId            NetId                          ( CPF_Parm )
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnReadPlayerStorageForNetIdComplete ( struct FUniqueNetId NetId, unsigned long bWasSuccessful )
{
	static UFunction* pFnOnReadPlayerStorageForNetIdComplete = NULL;

	if ( ! pFnOnReadPlayerStorageForNetIdComplete )
		pFnOnReadPlayerStorageForNetIdComplete = (UFunction*) UObject::GObjObjects()->Data[ 39359 ];

	USFXOnlineComponentUnrealPlayer_execOnReadPlayerStorageForNetIdComplete_Parms OnReadPlayerStorageForNetIdComplete_Parms;
	memcpy ( &OnReadPlayerStorageForNetIdComplete_Parms.NetId, &NetId, 0x8 );
	OnReadPlayerStorageForNetIdComplete_Parms.bWasSuccessful = bWasSuccessful;

	this->ProcessEvent ( pFnOnReadPlayerStorageForNetIdComplete, &OnReadPlayerStorageForNetIdComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ReadPlayerStorageForNetId
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FUniqueNetId            NetId                          ( CPF_Parm )
// class UOnlinePlayerStorage*    PlayerStorage                  ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::ReadPlayerStorageForNetId ( struct FUniqueNetId NetId, class UOnlinePlayerStorage* PlayerStorage )
{
	static UFunction* pFnReadPlayerStorageForNetId = NULL;

	if ( ! pFnReadPlayerStorageForNetId )
		pFnReadPlayerStorageForNetId = (UFunction*) UObject::GObjObjects()->Data[ 39561 ];

	USFXOnlineComponentUnrealPlayer_execReadPlayerStorageForNetId_Parms ReadPlayerStorageForNetId_Parms;
	memcpy ( &ReadPlayerStorageForNetId_Parms.NetId, &NetId, 0x8 );
	ReadPlayerStorageForNetId_Parms.PlayerStorage = PlayerStorage;

	pFnReadPlayerStorageForNetId->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnReadPlayerStorageForNetId, &ReadPlayerStorageForNetId_Parms, NULL );

	pFnReadPlayerStorageForNetId->FunctionFlags |= 0x400;

	return ReadPlayerStorageForNetId_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearReadPlayerStorageCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadPlayerStorageCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearReadPlayerStorageCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadPlayerStorageCompleteDelegate )
{
	static UFunction* pFnClearReadPlayerStorageCompleteDelegate = NULL;

	if ( ! pFnClearReadPlayerStorageCompleteDelegate )
		pFnClearReadPlayerStorageCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39557 ];

	USFXOnlineComponentUnrealPlayer_execClearReadPlayerStorageCompleteDelegate_Parms ClearReadPlayerStorageCompleteDelegate_Parms;
	ClearReadPlayerStorageCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearReadPlayerStorageCompleteDelegate_Parms.ReadPlayerStorageCompleteDelegate, &ReadPlayerStorageCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnClearReadPlayerStorageCompleteDelegate, &ClearReadPlayerStorageCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddReadPlayerStorageCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadPlayerStorageCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddReadPlayerStorageCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadPlayerStorageCompleteDelegate )
{
	static UFunction* pFnAddReadPlayerStorageCompleteDelegate = NULL;

	if ( ! pFnAddReadPlayerStorageCompleteDelegate )
		pFnAddReadPlayerStorageCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39554 ];

	USFXOnlineComponentUnrealPlayer_execAddReadPlayerStorageCompleteDelegate_Parms AddReadPlayerStorageCompleteDelegate_Parms;
	AddReadPlayerStorageCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddReadPlayerStorageCompleteDelegate_Parms.ReadPlayerStorageCompleteDelegate, &ReadPlayerStorageCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnAddReadPlayerStorageCompleteDelegate, &AddReadPlayerStorageCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnReadPlayerStorageComplete
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnReadPlayerStorageComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful )
{
	static UFunction* pFnOnReadPlayerStorageComplete = NULL;

	if ( ! pFnOnReadPlayerStorageComplete )
		pFnOnReadPlayerStorageComplete = (UFunction*) UObject::GObjObjects()->Data[ 39353 ];

	USFXOnlineComponentUnrealPlayer_execOnReadPlayerStorageComplete_Parms OnReadPlayerStorageComplete_Parms;
	OnReadPlayerStorageComplete_Parms.LocalUserNum = LocalUserNum;
	OnReadPlayerStorageComplete_Parms.bWasSuccessful = bWasSuccessful;

	this->ProcessEvent ( pFnOnReadPlayerStorageComplete, &OnReadPlayerStorageComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ReadPlayerStorage
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// class UOnlinePlayerStorage*    PlayerStorage                  ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::ReadPlayerStorage ( unsigned char LocalUserNum, class UOnlinePlayerStorage* PlayerStorage )
{
	static UFunction* pFnReadPlayerStorage = NULL;

	if ( ! pFnReadPlayerStorage )
		pFnReadPlayerStorage = (UFunction*) UObject::GObjObjects()->Data[ 39548 ];

	USFXOnlineComponentUnrealPlayer_execReadPlayerStorage_Parms ReadPlayerStorage_Parms;
	ReadPlayerStorage_Parms.LocalUserNum = LocalUserNum;
	ReadPlayerStorage_Parms.PlayerStorage = PlayerStorage;

	pFnReadPlayerStorage->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnReadPlayerStorage, &ReadPlayerStorage_Parms, NULL );

	pFnReadPlayerStorage->FunctionFlags |= 0x400;

	return ReadPlayerStorage_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearWriteProfileSettingsCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         WriteProfileSettingsCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearWriteProfileSettingsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate WriteProfileSettingsCompleteDelegate )
{
	static UFunction* pFnClearWriteProfileSettingsCompleteDelegate = NULL;

	if ( ! pFnClearWriteProfileSettingsCompleteDelegate )
		pFnClearWriteProfileSettingsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39544 ];

	USFXOnlineComponentUnrealPlayer_execClearWriteProfileSettingsCompleteDelegate_Parms ClearWriteProfileSettingsCompleteDelegate_Parms;
	ClearWriteProfileSettingsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearWriteProfileSettingsCompleteDelegate_Parms.WriteProfileSettingsCompleteDelegate, &WriteProfileSettingsCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnClearWriteProfileSettingsCompleteDelegate, &ClearWriteProfileSettingsCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddWriteProfileSettingsCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         WriteProfileSettingsCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddWriteProfileSettingsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate WriteProfileSettingsCompleteDelegate )
{
	static UFunction* pFnAddWriteProfileSettingsCompleteDelegate = NULL;

	if ( ! pFnAddWriteProfileSettingsCompleteDelegate )
		pFnAddWriteProfileSettingsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39541 ];

	USFXOnlineComponentUnrealPlayer_execAddWriteProfileSettingsCompleteDelegate_Parms AddWriteProfileSettingsCompleteDelegate_Parms;
	AddWriteProfileSettingsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddWriteProfileSettingsCompleteDelegate_Parms.WriteProfileSettingsCompleteDelegate, &WriteProfileSettingsCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnAddWriteProfileSettingsCompleteDelegate, &AddWriteProfileSettingsCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnWriteProfileSettingsComplete
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnWriteProfileSettingsComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful )
{
	static UFunction* pFnOnWriteProfileSettingsComplete = NULL;

	if ( ! pFnOnWriteProfileSettingsComplete )
		pFnOnWriteProfileSettingsComplete = (UFunction*) UObject::GObjObjects()->Data[ 38807 ];

	USFXOnlineComponentUnrealPlayer_execOnWriteProfileSettingsComplete_Parms OnWriteProfileSettingsComplete_Parms;
	OnWriteProfileSettingsComplete_Parms.LocalUserNum = LocalUserNum;
	OnWriteProfileSettingsComplete_Parms.bWasSuccessful = bWasSuccessful;

	this->ProcessEvent ( pFnOnWriteProfileSettingsComplete, &OnWriteProfileSettingsComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.WriteProfileSettings
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// class UOnlineProfileSettings*  ProfileSettings                ( CPF_Parm )
// unsigned long                  bIsTrilogyProfile              ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::WriteProfileSettings ( unsigned char LocalUserNum, class UOnlineProfileSettings* ProfileSettings, unsigned long bIsTrilogyProfile )
{
	static UFunction* pFnWriteProfileSettings = NULL;

	if ( ! pFnWriteProfileSettings )
		pFnWriteProfileSettings = (UFunction*) UObject::GObjObjects()->Data[ 39534 ];

	USFXOnlineComponentUnrealPlayer_execWriteProfileSettings_Parms WriteProfileSettings_Parms;
	WriteProfileSettings_Parms.LocalUserNum = LocalUserNum;
	WriteProfileSettings_Parms.ProfileSettings = ProfileSettings;
	WriteProfileSettings_Parms.bIsTrilogyProfile = bIsTrilogyProfile;

	pFnWriteProfileSettings->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWriteProfileSettings, &WriteProfileSettings_Parms, NULL );

	pFnWriteProfileSettings->FunctionFlags |= 0x400;

	return WriteProfileSettings_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.GetProfileSettings
// [0x00020002] 
// Parameters infos:
// class UOnlineProfileSettings*  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

class UOnlineProfileSettings* USFXOnlineComponentUnrealPlayer::GetProfileSettings ( unsigned char LocalUserNum )
{
	static UFunction* pFnGetProfileSettings = NULL;

	if ( ! pFnGetProfileSettings )
		pFnGetProfileSettings = (UFunction*) UObject::GObjObjects()->Data[ 39531 ];

	USFXOnlineComponentUnrealPlayer_execGetProfileSettings_Parms GetProfileSettings_Parms;
	GetProfileSettings_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnGetProfileSettings, &GetProfileSettings_Parms, NULL );

	return GetProfileSettings_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearReadProfileSettingsCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadProfileSettingsCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearReadProfileSettingsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadProfileSettingsCompleteDelegate )
{
	static UFunction* pFnClearReadProfileSettingsCompleteDelegate = NULL;

	if ( ! pFnClearReadProfileSettingsCompleteDelegate )
		pFnClearReadProfileSettingsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39527 ];

	USFXOnlineComponentUnrealPlayer_execClearReadProfileSettingsCompleteDelegate_Parms ClearReadProfileSettingsCompleteDelegate_Parms;
	ClearReadProfileSettingsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearReadProfileSettingsCompleteDelegate_Parms.ReadProfileSettingsCompleteDelegate, &ReadProfileSettingsCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnClearReadProfileSettingsCompleteDelegate, &ClearReadProfileSettingsCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddReadProfileSettingsCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadProfileSettingsCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddReadProfileSettingsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadProfileSettingsCompleteDelegate )
{
	static UFunction* pFnAddReadProfileSettingsCompleteDelegate = NULL;

	if ( ! pFnAddReadProfileSettingsCompleteDelegate )
		pFnAddReadProfileSettingsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39523 ];

	USFXOnlineComponentUnrealPlayer_execAddReadProfileSettingsCompleteDelegate_Parms AddReadProfileSettingsCompleteDelegate_Parms;
	AddReadProfileSettingsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddReadProfileSettingsCompleteDelegate_Parms.ReadProfileSettingsCompleteDelegate, &ReadProfileSettingsCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnAddReadProfileSettingsCompleteDelegate, &AddReadProfileSettingsCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnReadProfileSettingsComplete
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnReadProfileSettingsComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful )
{
	static UFunction* pFnOnReadProfileSettingsComplete = NULL;

	if ( ! pFnOnReadProfileSettingsComplete )
		pFnOnReadProfileSettingsComplete = (UFunction*) UObject::GObjObjects()->Data[ 38804 ];

	USFXOnlineComponentUnrealPlayer_execOnReadProfileSettingsComplete_Parms OnReadProfileSettingsComplete_Parms;
	OnReadProfileSettingsComplete_Parms.LocalUserNum = LocalUserNum;
	OnReadProfileSettingsComplete_Parms.bWasSuccessful = bWasSuccessful;

	this->ProcessEvent ( pFnOnReadProfileSettingsComplete, &OnReadProfileSettingsComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ReadProfileSettings
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// class UOnlineProfileSettings*  ProfileSettings                ( CPF_Parm )
// unsigned long                  bIsTrilogyProfile              ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::ReadProfileSettings ( unsigned char LocalUserNum, class UOnlineProfileSettings* ProfileSettings, unsigned long bIsTrilogyProfile )
{
	static UFunction* pFnReadProfileSettings = NULL;

	if ( ! pFnReadProfileSettings )
		pFnReadProfileSettings = (UFunction*) UObject::GObjObjects()->Data[ 39516 ];

	USFXOnlineComponentUnrealPlayer_execReadProfileSettings_Parms ReadProfileSettings_Parms;
	ReadProfileSettings_Parms.LocalUserNum = LocalUserNum;
	ReadProfileSettings_Parms.ProfileSettings = ProfileSettings;
	ReadProfileSettings_Parms.bIsTrilogyProfile = bIsTrilogyProfile;

	pFnReadProfileSettings->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnReadProfileSettings, &ReadProfileSettings_Parms, NULL );

	pFnReadProfileSettings->FunctionFlags |= 0x400;

	return ReadProfileSettings_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearFriendsChangeDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         FriendsDelegate                ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearFriendsChangeDelegate ( unsigned char LocalUserNum, struct FScriptDelegate FriendsDelegate )
{
	static UFunction* pFnClearFriendsChangeDelegate = NULL;

	if ( ! pFnClearFriendsChangeDelegate )
		pFnClearFriendsChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39513 ];

	USFXOnlineComponentUnrealPlayer_execClearFriendsChangeDelegate_Parms ClearFriendsChangeDelegate_Parms;
	ClearFriendsChangeDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearFriendsChangeDelegate_Parms.FriendsDelegate, &FriendsDelegate, 0x10 );

	this->ProcessEvent ( pFnClearFriendsChangeDelegate, &ClearFriendsChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddFriendsChangeDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         FriendsDelegate                ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddFriendsChangeDelegate ( unsigned char LocalUserNum, struct FScriptDelegate FriendsDelegate )
{
	static UFunction* pFnAddFriendsChangeDelegate = NULL;

	if ( ! pFnAddFriendsChangeDelegate )
		pFnAddFriendsChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39510 ];

	USFXOnlineComponentUnrealPlayer_execAddFriendsChangeDelegate_Parms AddFriendsChangeDelegate_Parms;
	AddFriendsChangeDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddFriendsChangeDelegate_Parms.FriendsDelegate, &FriendsDelegate, 0x10 );

	this->ProcessEvent ( pFnAddFriendsChangeDelegate, &AddFriendsChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearMutingChangeDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         MutingDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearMutingChangeDelegate ( struct FScriptDelegate MutingDelegate )
{
	static UFunction* pFnClearMutingChangeDelegate = NULL;

	if ( ! pFnClearMutingChangeDelegate )
		pFnClearMutingChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39508 ];

	USFXOnlineComponentUnrealPlayer_execClearMutingChangeDelegate_Parms ClearMutingChangeDelegate_Parms;
	memcpy ( &ClearMutingChangeDelegate_Parms.MutingDelegate, &MutingDelegate, 0x10 );

	this->ProcessEvent ( pFnClearMutingChangeDelegate, &ClearMutingChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddMutingChangeDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         MutingDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddMutingChangeDelegate ( struct FScriptDelegate MutingDelegate )
{
	static UFunction* pFnAddMutingChangeDelegate = NULL;

	if ( ! pFnAddMutingChangeDelegate )
		pFnAddMutingChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39506 ];

	USFXOnlineComponentUnrealPlayer_execAddMutingChangeDelegate_Parms AddMutingChangeDelegate_Parms;
	memcpy ( &AddMutingChangeDelegate_Parms.MutingDelegate, &MutingDelegate, 0x10 );

	this->ProcessEvent ( pFnAddMutingChangeDelegate, &AddMutingChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearLoginCancelledDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         CancelledDelegate              ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearLoginCancelledDelegate ( struct FScriptDelegate CancelledDelegate )
{
	static UFunction* pFnClearLoginCancelledDelegate = NULL;

	if ( ! pFnClearLoginCancelledDelegate )
		pFnClearLoginCancelledDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39503 ];

	USFXOnlineComponentUnrealPlayer_execClearLoginCancelledDelegate_Parms ClearLoginCancelledDelegate_Parms;
	memcpy ( &ClearLoginCancelledDelegate_Parms.CancelledDelegate, &CancelledDelegate, 0x10 );

	this->ProcessEvent ( pFnClearLoginCancelledDelegate, &ClearLoginCancelledDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddLoginCancelledDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         CancelledDelegate              ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddLoginCancelledDelegate ( struct FScriptDelegate CancelledDelegate )
{
	static UFunction* pFnAddLoginCancelledDelegate = NULL;

	if ( ! pFnAddLoginCancelledDelegate )
		pFnAddLoginCancelledDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39501 ];

	USFXOnlineComponentUnrealPlayer_execAddLoginCancelledDelegate_Parms AddLoginCancelledDelegate_Parms;
	memcpy ( &AddLoginCancelledDelegate_Parms.CancelledDelegate, &CancelledDelegate, 0x10 );

	this->ProcessEvent ( pFnAddLoginCancelledDelegate, &AddLoginCancelledDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearLoginStatusChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         LoginStatusDelegate            ( CPF_Parm | CPF_NeedCtorLink )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::ClearLoginStatusChangeDelegate ( struct FScriptDelegate LoginStatusDelegate, unsigned char LocalUserNum )
{
	static UFunction* pFnClearLoginStatusChangeDelegate = NULL;

	if ( ! pFnClearLoginStatusChangeDelegate )
		pFnClearLoginStatusChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39497 ];

	USFXOnlineComponentUnrealPlayer_execClearLoginStatusChangeDelegate_Parms ClearLoginStatusChangeDelegate_Parms;
	memcpy ( &ClearLoginStatusChangeDelegate_Parms.LoginStatusDelegate, &LoginStatusDelegate, 0x10 );
	ClearLoginStatusChangeDelegate_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnClearLoginStatusChangeDelegate, &ClearLoginStatusChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddLoginStatusChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         LoginStatusDelegate            ( CPF_Parm | CPF_NeedCtorLink )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::AddLoginStatusChangeDelegate ( struct FScriptDelegate LoginStatusDelegate, unsigned char LocalUserNum )
{
	static UFunction* pFnAddLoginStatusChangeDelegate = NULL;

	if ( ! pFnAddLoginStatusChangeDelegate )
		pFnAddLoginStatusChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39493 ];

	USFXOnlineComponentUnrealPlayer_execAddLoginStatusChangeDelegate_Parms AddLoginStatusChangeDelegate_Parms;
	memcpy ( &AddLoginStatusChangeDelegate_Parms.LoginStatusDelegate, &LoginStatusDelegate, 0x10 );
	AddLoginStatusChangeDelegate_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnAddLoginStatusChangeDelegate, &AddLoginStatusChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnLoginStatusChange
// [0x00120000] 
// Parameters infos:
// unsigned char                  NewStatus                      ( CPF_Parm )
// struct FUniqueNetId            NewId                          ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnLoginStatusChange ( unsigned char NewStatus, struct FUniqueNetId NewId )
{
	static UFunction* pFnOnLoginStatusChange = NULL;

	if ( ! pFnOnLoginStatusChange )
		pFnOnLoginStatusChange = (UFunction*) UObject::GObjObjects()->Data[ 39382 ];

	USFXOnlineComponentUnrealPlayer_execOnLoginStatusChange_Parms OnLoginStatusChange_Parms;
	OnLoginStatusChange_Parms.NewStatus = NewStatus;
	memcpy ( &OnLoginStatusChange_Parms.NewId, &NewId, 0x8 );

	this->ProcessEvent ( pFnOnLoginStatusChange, &OnLoginStatusChange_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearLoginChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         LoginDelegate                  ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearLoginChangeDelegate ( struct FScriptDelegate LoginDelegate )
{
	static UFunction* pFnClearLoginChangeDelegate = NULL;

	if ( ! pFnClearLoginChangeDelegate )
		pFnClearLoginChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39488 ];

	USFXOnlineComponentUnrealPlayer_execClearLoginChangeDelegate_Parms ClearLoginChangeDelegate_Parms;
	memcpy ( &ClearLoginChangeDelegate_Parms.LoginDelegate, &LoginDelegate, 0x10 );

	this->ProcessEvent ( pFnClearLoginChangeDelegate, &ClearLoginChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddLoginChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         LoginDelegate                  ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddLoginChangeDelegate ( struct FScriptDelegate LoginDelegate )
{
	static UFunction* pFnAddLoginChangeDelegate = NULL;

	if ( ! pFnAddLoginChangeDelegate )
		pFnAddLoginChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39486 ];

	USFXOnlineComponentUnrealPlayer_execAddLoginChangeDelegate_Parms AddLoginChangeDelegate_Parms;
	memcpy ( &AddLoginChangeDelegate_Parms.LoginDelegate, &LoginDelegate, 0x10 );

	this->ProcessEvent ( pFnAddLoginChangeDelegate, &AddLoginChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ShowFriendsUI
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::ShowFriendsUI ( unsigned char LocalUserNum )
{
	static UFunction* pFnShowFriendsUI = NULL;

	if ( ! pFnShowFriendsUI )
		pFnShowFriendsUI = (UFunction*) UObject::GObjObjects()->Data[ 39483 ];

	USFXOnlineComponentUnrealPlayer_execShowFriendsUI_Parms ShowFriendsUI_Parms;
	ShowFriendsUI_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnShowFriendsUI, &ShowFriendsUI_Parms, NULL );

	return ShowFriendsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.IsMuted
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::IsMuted ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID )
{
	static UFunction* pFnIsMuted = NULL;

	if ( ! pFnIsMuted )
		pFnIsMuted = (UFunction*) UObject::GObjObjects()->Data[ 39479 ];

	USFXOnlineComponentUnrealPlayer_execIsMuted_Parms IsMuted_Parms;
	IsMuted_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &IsMuted_Parms.PlayerID, &PlayerID, 0x8 );

	this->ProcessEvent ( pFnIsMuted, &IsMuted_Parms, NULL );

	return IsMuted_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AreAnyFriends
// [0x00420000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct TArray<struct FFriendsQuery> Query                          ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

bool USFXOnlineComponentUnrealPlayer::AreAnyFriends ( unsigned char LocalUserNum, struct TArray<struct FFriendsQuery>* Query )
{
	static UFunction* pFnAreAnyFriends = NULL;

	if ( ! pFnAreAnyFriends )
		pFnAreAnyFriends = (UFunction*) UObject::GObjObjects()->Data[ 39474 ];

	USFXOnlineComponentUnrealPlayer_execAreAnyFriends_Parms AreAnyFriends_Parms;
	AreAnyFriends_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnAreAnyFriends, &AreAnyFriends_Parms, NULL );

	if ( Query )
		memcpy ( Query, &AreAnyFriends_Parms.Query, 0x10 );

	return AreAnyFriends_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.IsFriend
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::IsFriend ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID )
{
	static UFunction* pFnIsFriend = NULL;

	if ( ! pFnIsFriend )
		pFnIsFriend = (UFunction*) UObject::GObjObjects()->Data[ 39470 ];

	USFXOnlineComponentUnrealPlayer_execIsFriend_Parms IsFriend_Parms;
	IsFriend_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &IsFriend_Parms.PlayerID, &PlayerID, 0x8 );

	this->ProcessEvent ( pFnIsFriend, &IsFriend_Parms, NULL );

	return IsFriend_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.CanShowPresenceInformation
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char USFXOnlineComponentUnrealPlayer::CanShowPresenceInformation ( unsigned char LocalUserNum )
{
	static UFunction* pFnCanShowPresenceInformation = NULL;

	if ( ! pFnCanShowPresenceInformation )
		pFnCanShowPresenceInformation = (UFunction*) UObject::GObjObjects()->Data[ 39467 ];

	USFXOnlineComponentUnrealPlayer_execCanShowPresenceInformation_Parms CanShowPresenceInformation_Parms;
	CanShowPresenceInformation_Parms.LocalUserNum = LocalUserNum;

	pFnCanShowPresenceInformation->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanShowPresenceInformation, &CanShowPresenceInformation_Parms, NULL );

	pFnCanShowPresenceInformation->FunctionFlags |= 0x400;

	return CanShowPresenceInformation_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.CanViewPlayerProfiles
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char USFXOnlineComponentUnrealPlayer::CanViewPlayerProfiles ( unsigned char LocalUserNum )
{
	static UFunction* pFnCanViewPlayerProfiles = NULL;

	if ( ! pFnCanViewPlayerProfiles )
		pFnCanViewPlayerProfiles = (UFunction*) UObject::GObjObjects()->Data[ 39464 ];

	USFXOnlineComponentUnrealPlayer_execCanViewPlayerProfiles_Parms CanViewPlayerProfiles_Parms;
	CanViewPlayerProfiles_Parms.LocalUserNum = LocalUserNum;

	pFnCanViewPlayerProfiles->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanViewPlayerProfiles, &CanViewPlayerProfiles_Parms, NULL );

	pFnCanViewPlayerProfiles->FunctionFlags |= 0x400;

	return CanViewPlayerProfiles_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.CanPurchaseContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char USFXOnlineComponentUnrealPlayer::CanPurchaseContent ( unsigned char LocalUserNum )
{
	static UFunction* pFnCanPurchaseContent = NULL;

	if ( ! pFnCanPurchaseContent )
		pFnCanPurchaseContent = (UFunction*) UObject::GObjObjects()->Data[ 39461 ];

	USFXOnlineComponentUnrealPlayer_execCanPurchaseContent_Parms CanPurchaseContent_Parms;
	CanPurchaseContent_Parms.LocalUserNum = LocalUserNum;

	pFnCanPurchaseContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPurchaseContent, &CanPurchaseContent_Parms, NULL );

	pFnCanPurchaseContent->FunctionFlags |= 0x400;

	return CanPurchaseContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.CanDownloadUserContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char USFXOnlineComponentUnrealPlayer::CanDownloadUserContent ( unsigned char LocalUserNum )
{
	static UFunction* pFnCanDownloadUserContent = NULL;

	if ( ! pFnCanDownloadUserContent )
		pFnCanDownloadUserContent = (UFunction*) UObject::GObjObjects()->Data[ 39458 ];

	USFXOnlineComponentUnrealPlayer_execCanDownloadUserContent_Parms CanDownloadUserContent_Parms;
	CanDownloadUserContent_Parms.LocalUserNum = LocalUserNum;

	pFnCanDownloadUserContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanDownloadUserContent, &CanDownloadUserContent_Parms, NULL );

	pFnCanDownloadUserContent->FunctionFlags |= 0x400;

	return CanDownloadUserContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.CanCommunicate
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char USFXOnlineComponentUnrealPlayer::CanCommunicate ( unsigned char LocalUserNum )
{
	static UFunction* pFnCanCommunicate = NULL;

	if ( ! pFnCanCommunicate )
		pFnCanCommunicate = (UFunction*) UObject::GObjObjects()->Data[ 39455 ];

	USFXOnlineComponentUnrealPlayer_execCanCommunicate_Parms CanCommunicate_Parms;
	CanCommunicate_Parms.LocalUserNum = LocalUserNum;

	pFnCanCommunicate->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanCommunicate, &CanCommunicate_Parms, NULL );

	pFnCanCommunicate->FunctionFlags |= 0x400;

	return CanCommunicate_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.CanPlayOnline
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char USFXOnlineComponentUnrealPlayer::CanPlayOnline ( unsigned char LocalUserNum )
{
	static UFunction* pFnCanPlayOnline = NULL;

	if ( ! pFnCanPlayOnline )
		pFnCanPlayOnline = (UFunction*) UObject::GObjObjects()->Data[ 39452 ];

	USFXOnlineComponentUnrealPlayer_execCanPlayOnline_Parms CanPlayOnline_Parms;
	CanPlayOnline_Parms.LocalUserNum = LocalUserNum;

	pFnCanPlayOnline->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPlayOnline, &CanPlayOnline_Parms, NULL );

	pFnCanPlayOnline->FunctionFlags |= 0x400;

	return CanPlayOnline_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.IsLocalLogin
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::IsLocalLogin ( unsigned char LocalUserNum )
{
	static UFunction* pFnIsLocalLogin = NULL;

	if ( ! pFnIsLocalLogin )
		pFnIsLocalLogin = (UFunction*) UObject::GObjObjects()->Data[ 39449 ];

	USFXOnlineComponentUnrealPlayer_execIsLocalLogin_Parms IsLocalLogin_Parms;
	IsLocalLogin_Parms.LocalUserNum = LocalUserNum;

	pFnIsLocalLogin->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsLocalLogin, &IsLocalLogin_Parms, NULL );

	pFnIsLocalLogin->FunctionFlags |= 0x400;

	return IsLocalLogin_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.IsGuestLogin
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::IsGuestLogin ( unsigned char LocalUserNum )
{
	static UFunction* pFnIsGuestLogin = NULL;

	if ( ! pFnIsGuestLogin )
		pFnIsGuestLogin = (UFunction*) UObject::GObjObjects()->Data[ 39446 ];

	USFXOnlineComponentUnrealPlayer_execIsGuestLogin_Parms IsGuestLogin_Parms;
	IsGuestLogin_Parms.LocalUserNum = LocalUserNum;

	pFnIsGuestLogin->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsGuestLogin, &IsGuestLogin_Parms, NULL );

	pFnIsGuestLogin->FunctionFlags |= 0x400;

	return IsGuestLogin_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.GetPlayerNickname
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

struct FString USFXOnlineComponentUnrealPlayer::GetPlayerNickname ( unsigned char LocalUserNum )
{
	static UFunction* pFnGetPlayerNickname = NULL;

	if ( ! pFnGetPlayerNickname )
		pFnGetPlayerNickname = (UFunction*) UObject::GObjObjects()->Data[ 39443 ];

	USFXOnlineComponentUnrealPlayer_execGetPlayerNickname_Parms GetPlayerNickname_Parms;
	GetPlayerNickname_Parms.LocalUserNum = LocalUserNum;

	pFnGetPlayerNickname->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetPlayerNickname, &GetPlayerNickname_Parms, NULL );

	pFnGetPlayerNickname->FunctionFlags |= 0x400;

	return GetPlayerNickname_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.GetUniquePlayerId
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm | CPF_OutParm )

bool USFXOnlineComponentUnrealPlayer::GetUniquePlayerId ( unsigned char LocalUserNum, struct FUniqueNetId* PlayerID )
{
	static UFunction* pFnGetUniquePlayerId = NULL;

	if ( ! pFnGetUniquePlayerId )
		pFnGetUniquePlayerId = (UFunction*) UObject::GObjObjects()->Data[ 39439 ];

	USFXOnlineComponentUnrealPlayer_execGetUniquePlayerId_Parms GetUniquePlayerId_Parms;
	GetUniquePlayerId_Parms.LocalUserNum = LocalUserNum;

	pFnGetUniquePlayerId->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetUniquePlayerId, &GetUniquePlayerId_Parms, NULL );

	pFnGetUniquePlayerId->FunctionFlags |= 0x400;

	if ( PlayerID )
		memcpy ( PlayerID, &GetUniquePlayerId_Parms.PlayerID, 0x8 );

	return GetUniquePlayerId_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.GetLoginStatus
// [0x00020002] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char USFXOnlineComponentUnrealPlayer::GetLoginStatus ( unsigned char LocalUserNum )
{
	static UFunction* pFnGetLoginStatus = NULL;

	if ( ! pFnGetLoginStatus )
		pFnGetLoginStatus = (UFunction*) UObject::GObjObjects()->Data[ 39430 ];

	USFXOnlineComponentUnrealPlayer_execGetLoginStatus_Parms GetLoginStatus_Parms;
	GetLoginStatus_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnGetLoginStatus, &GetLoginStatus_Parms, NULL );

	return GetLoginStatus_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearLogoutCompletedDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         LogoutDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearLogoutCompletedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate LogoutDelegate )
{
	static UFunction* pFnClearLogoutCompletedDelegate = NULL;

	if ( ! pFnClearLogoutCompletedDelegate )
		pFnClearLogoutCompletedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39426 ];

	USFXOnlineComponentUnrealPlayer_execClearLogoutCompletedDelegate_Parms ClearLogoutCompletedDelegate_Parms;
	ClearLogoutCompletedDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearLogoutCompletedDelegate_Parms.LogoutDelegate, &LogoutDelegate, 0x10 );

	this->ProcessEvent ( pFnClearLogoutCompletedDelegate, &ClearLogoutCompletedDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddLogoutCompletedDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         LogoutDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddLogoutCompletedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate LogoutDelegate )
{
	static UFunction* pFnAddLogoutCompletedDelegate = NULL;

	if ( ! pFnAddLogoutCompletedDelegate )
		pFnAddLogoutCompletedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39423 ];

	USFXOnlineComponentUnrealPlayer_execAddLogoutCompletedDelegate_Parms AddLogoutCompletedDelegate_Parms;
	AddLogoutCompletedDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddLogoutCompletedDelegate_Parms.LogoutDelegate, &LogoutDelegate, 0x10 );

	this->ProcessEvent ( pFnAddLogoutCompletedDelegate, &AddLogoutCompletedDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnLogoutCompleted
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnLogoutCompleted ( unsigned long bWasSuccessful )
{
	static UFunction* pFnOnLogoutCompleted = NULL;

	if ( ! pFnOnLogoutCompleted )
		pFnOnLogoutCompleted = (UFunction*) UObject::GObjObjects()->Data[ 39368 ];

	USFXOnlineComponentUnrealPlayer_execOnLogoutCompleted_Parms OnLogoutCompleted_Parms;
	OnLogoutCompleted_Parms.bWasSuccessful = bWasSuccessful;

	this->ProcessEvent ( pFnOnLogoutCompleted, &OnLogoutCompleted_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.Logout
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::Logout ( unsigned char LocalUserNum )
{
	static UFunction* pFnLogout = NULL;

	if ( ! pFnLogout )
		pFnLogout = (UFunction*) UObject::GObjObjects()->Data[ 39419 ];

	USFXOnlineComponentUnrealPlayer_execLogout_Parms Logout_Parms;
	Logout_Parms.LocalUserNum = LocalUserNum;

	pFnLogout->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnLogout, &Logout_Parms, NULL );

	pFnLogout->FunctionFlags |= 0x400;

	return Logout_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ClearLoginFailedDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         LoginDelegate                  ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::ClearLoginFailedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate LoginDelegate )
{
	static UFunction* pFnClearLoginFailedDelegate = NULL;

	if ( ! pFnClearLoginFailedDelegate )
		pFnClearLoginFailedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39415 ];

	USFXOnlineComponentUnrealPlayer_execClearLoginFailedDelegate_Parms ClearLoginFailedDelegate_Parms;
	ClearLoginFailedDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearLoginFailedDelegate_Parms.LoginDelegate, &LoginDelegate, 0x10 );

	this->ProcessEvent ( pFnClearLoginFailedDelegate, &ClearLoginFailedDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AddLoginFailedDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         LoginDelegate                  ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayer::AddLoginFailedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate LoginDelegate )
{
	static UFunction* pFnAddLoginFailedDelegate = NULL;

	if ( ! pFnAddLoginFailedDelegate )
		pFnAddLoginFailedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39412 ];

	USFXOnlineComponentUnrealPlayer_execAddLoginFailedDelegate_Parms AddLoginFailedDelegate_Parms;
	AddLoginFailedDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddLoginFailedDelegate_Parms.LoginDelegate, &LoginDelegate, 0x10 );

	this->ProcessEvent ( pFnAddLoginFailedDelegate, &AddLoginFailedDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnLoginFailed
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// unsigned char                  ErrorCode                      ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnLoginFailed ( unsigned char LocalUserNum, unsigned char ErrorCode )
{
	static UFunction* pFnOnLoginFailed = NULL;

	if ( ! pFnOnLoginFailed )
		pFnOnLoginFailed = (UFunction*) UObject::GObjObjects()->Data[ 39365 ];

	USFXOnlineComponentUnrealPlayer_execOnLoginFailed_Parms OnLoginFailed_Parms;
	OnLoginFailed_Parms.LocalUserNum = LocalUserNum;
	OnLoginFailed_Parms.ErrorCode = ErrorCode;

	this->ProcessEvent ( pFnOnLoginFailed, &OnLoginFailed_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.AutoLogin
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentUnrealPlayer::AutoLogin ( )
{
	static UFunction* pFnAutoLogin = NULL;

	if ( ! pFnAutoLogin )
		pFnAutoLogin = (UFunction*) UObject::GObjObjects()->Data[ 39408 ];

	USFXOnlineComponentUnrealPlayer_execAutoLogin_Parms AutoLogin_Parms;

	pFnAutoLogin->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnAutoLogin, &AutoLogin_Parms, NULL );

	pFnAutoLogin->FunctionFlags |= 0x400;

	return AutoLogin_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.Login
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 LoginName                      ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Password                       ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bWantsLocalOnly                ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::Login ( unsigned char LocalUserNum, struct FString LoginName, struct FString Password, unsigned long bWantsLocalOnly )
{
	static UFunction* pFnLogin = NULL;

	if ( ! pFnLogin )
		pFnLogin = (UFunction*) UObject::GObjObjects()->Data[ 39402 ];

	USFXOnlineComponentUnrealPlayer_execLogin_Parms Login_Parms;
	Login_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &Login_Parms.LoginName, &LoginName, 0x10 );
	memcpy ( &Login_Parms.Password, &Password, 0x10 );
	Login_Parms.bWantsLocalOnly = bWantsLocalOnly;

	pFnLogin->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnLogin, &Login_Parms, NULL );

	pFnLogin->FunctionFlags |= 0x400;

	return Login_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.ShowLoginUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned long                  bShowOnlineOnly                ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::ShowLoginUI ( unsigned long bShowOnlineOnly )
{
	static UFunction* pFnShowLoginUI = NULL;

	if ( ! pFnShowLoginUI )
		pFnShowLoginUI = (UFunction*) UObject::GObjObjects()->Data[ 39399 ];

	USFXOnlineComponentUnrealPlayer_execShowLoginUI_Parms ShowLoginUI_Parms;
	ShowLoginUI_Parms.bShowOnlineOnly = bShowOnlineOnly;

	pFnShowLoginUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowLoginUI, &ShowLoginUI_Parms, NULL );

	pFnShowLoginUI->FunctionFlags |= 0x400;

	return ShowLoginUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnFriendsChange
// [0x00120000] 
// Parameters infos:

void USFXOnlineComponentUnrealPlayer::OnFriendsChange ( )
{
	static UFunction* pFnOnFriendsChange = NULL;

	if ( ! pFnOnFriendsChange )
		pFnOnFriendsChange = (UFunction*) UObject::GObjObjects()->Data[ 39398 ];

	USFXOnlineComponentUnrealPlayer_execOnFriendsChange_Parms OnFriendsChange_Parms;

	this->ProcessEvent ( pFnOnFriendsChange, &OnFriendsChange_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnMutingChange
// [0x00120000] 
// Parameters infos:

void USFXOnlineComponentUnrealPlayer::OnMutingChange ( )
{
	static UFunction* pFnOnMutingChange = NULL;

	if ( ! pFnOnMutingChange )
		pFnOnMutingChange = (UFunction*) UObject::GObjObjects()->Data[ 39397 ];

	USFXOnlineComponentUnrealPlayer_execOnMutingChange_Parms OnMutingChange_Parms;

	this->ProcessEvent ( pFnOnMutingChange, &OnMutingChange_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnLoginCancelled
// [0x00120000] 
// Parameters infos:

void USFXOnlineComponentUnrealPlayer::OnLoginCancelled ( )
{
	static UFunction* pFnOnLoginCancelled = NULL;

	if ( ! pFnOnLoginCancelled )
		pFnOnLoginCancelled = (UFunction*) UObject::GObjObjects()->Data[ 39362 ];

	USFXOnlineComponentUnrealPlayer_execOnLoginCancelled_Parms OnLoginCancelled_Parms;

	this->ProcessEvent ( pFnOnLoginCancelled, &OnLoginCancelled_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnLoginChange
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnLoginChange ( unsigned char LocalUserNum )
{
	static UFunction* pFnOnLoginChange = NULL;

	if ( ! pFnOnLoginChange )
		pFnOnLoginChange = (UFunction*) UObject::GObjObjects()->Data[ 39371 ];

	USFXOnlineComponentUnrealPlayer_execOnLoginChange_Parms OnLoginChange_Parms;
	OnLoginChange_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnOnLoginChange, &OnLoginChange_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnProfileDataChanged
// [0x00120000] 
// Parameters infos:

void USFXOnlineComponentUnrealPlayer::OnProfileDataChanged ( )
{
	static UFunction* pFnOnProfileDataChanged = NULL;

	if ( ! pFnOnProfileDataChanged )
		pFnOnProfileDataChanged = (UFunction*) UObject::GObjObjects()->Data[ 38810 ];

	USFXOnlineComponentUnrealPlayer_execOnProfileDataChanged_Parms OnProfileDataChanged_Parms;

	this->ProcessEvent ( pFnOnProfileDataChanged, &OnProfileDataChanged_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.CreateProfileName
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// unsigned long                  bIsTrilogyProfile              ( CPF_OptionalParm | CPF_Parm )

struct FString USFXOnlineComponentUnrealPlayer::CreateProfileName ( unsigned long bIsTrilogyProfile )
{
	static UFunction* pFnCreateProfileName = NULL;

	if ( ! pFnCreateProfileName )
		pFnCreateProfileName = (UFunction*) UObject::GObjObjects()->Data[ 39393 ];

	USFXOnlineComponentUnrealPlayer_execCreateProfileName_Parms CreateProfileName_Parms;
	CreateProfileName_Parms.bIsTrilogyProfile = bIsTrilogyProfile;

	pFnCreateProfileName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCreateProfileName, &CreateProfileName_Parms, NULL );

	pFnCreateProfileName->FunctionFlags |= 0x400;

	return CreateProfileName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.DoesProfileExist
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned long                  bIsTrilogyProfile              ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentUnrealPlayer::DoesProfileExist ( unsigned long bIsTrilogyProfile )
{
	static UFunction* pFnDoesProfileExist = NULL;

	if ( ! pFnDoesProfileExist )
		pFnDoesProfileExist = (UFunction*) UObject::GObjObjects()->Data[ 39390 ];

	USFXOnlineComponentUnrealPlayer_execDoesProfileExist_Parms DoesProfileExist_Parms;
	DoesProfileExist_Parms.bIsTrilogyProfile = bIsTrilogyProfile;

	pFnDoesProfileExist->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnDoesProfileExist, &DoesProfileExist_Parms, NULL );

	pFnDoesProfileExist->FunctionFlags |= 0x400;

	return DoesProfileExist_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnTick
// [0x00040401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnTick ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnOnTick = NULL;

	if ( ! pFnOnTick )
		pFnOnTick = (UFunction*) UObject::GObjObjects()->Data[ 39388 ];

	USFXOnlineComponentUnrealPlayer_execOnTick_Parms OnTick_Parms;
	OnTick_Parms.oEvent = oEvent;

	pFnOnTick->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnTick, &OnTick_Parms, NULL );

	pFnOnTick->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentUnrealPlayer::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 39386 ];

	USFXOnlineComponentUnrealPlayer_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentUnrealPlayer::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 39385 ];

	USFXOnlineComponentUnrealPlayer_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayer.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentUnrealPlayer::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 39383 ];

	USFXOnlineComponentUnrealPlayer_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ShowCustomPlayersUI
// [0x00420000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 Title                          ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Description                    ( CPF_Parm | CPF_NeedCtorLink )
// struct TArray<struct FUniqueNetId> Players                        ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

bool USFXOnlineComponentUnrealPlayerEx::ShowCustomPlayersUI ( unsigned char LocalUserNum, struct FString Title, struct FString Description, struct TArray<struct FUniqueNetId>* Players )
{
	static UFunction* pFnShowCustomPlayersUI = NULL;

	if ( ! pFnShowCustomPlayersUI )
		pFnShowCustomPlayersUI = (UFunction*) UObject::GObjObjects()->Data[ 39872 ];

	USFXOnlineComponentUnrealPlayerEx_execShowCustomPlayersUI_Parms ShowCustomPlayersUI_Parms;
	ShowCustomPlayersUI_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ShowCustomPlayersUI_Parms.Title, &Title, 0x10 );
	memcpy ( &ShowCustomPlayersUI_Parms.Description, &Description, 0x10 );

	this->ProcessEvent ( pFnShowCustomPlayersUI, &ShowCustomPlayersUI_Parms, NULL );

	if ( Players )
		memcpy ( Players, &ShowCustomPlayersUI_Parms.Players, 0x10 );

	return ShowCustomPlayersUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ShowPlayersUI
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayerEx::ShowPlayersUI ( unsigned char LocalUserNum )
{
	static UFunction* pFnShowPlayersUI = NULL;

	if ( ! pFnShowPlayersUI )
		pFnShowPlayersUI = (UFunction*) UObject::GObjObjects()->Data[ 39869 ];

	USFXOnlineComponentUnrealPlayerEx_execShowPlayersUI_Parms ShowPlayersUI_Parms;
	ShowPlayersUI_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnShowPlayersUI, &ShowPlayersUI_Parms, NULL );

	return ShowPlayersUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ShowFriendsInviteUI
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayerEx::ShowFriendsInviteUI ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID )
{
	static UFunction* pFnShowFriendsInviteUI = NULL;

	if ( ! pFnShowFriendsInviteUI )
		pFnShowFriendsInviteUI = (UFunction*) UObject::GObjObjects()->Data[ 39865 ];

	USFXOnlineComponentUnrealPlayerEx_execShowFriendsInviteUI_Parms ShowFriendsInviteUI_Parms;
	ShowFriendsInviteUI_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ShowFriendsInviteUI_Parms.PlayerID, &PlayerID, 0x8 );

	this->ProcessEvent ( pFnShowFriendsInviteUI, &ShowFriendsInviteUI_Parms, NULL );

	return ShowFriendsInviteUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ClearProfileDataChangedDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ProfileDataChangedDelegate     ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayerEx::ClearProfileDataChangedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ProfileDataChangedDelegate )
{
	static UFunction* pFnClearProfileDataChangedDelegate = NULL;

	if ( ! pFnClearProfileDataChangedDelegate )
		pFnClearProfileDataChangedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39862 ];

	USFXOnlineComponentUnrealPlayerEx_execClearProfileDataChangedDelegate_Parms ClearProfileDataChangedDelegate_Parms;
	ClearProfileDataChangedDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearProfileDataChangedDelegate_Parms.ProfileDataChangedDelegate, &ProfileDataChangedDelegate, 0x10 );

	this->ProcessEvent ( pFnClearProfileDataChangedDelegate, &ClearProfileDataChangedDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.AddProfileDataChangedDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ProfileDataChangedDelegate     ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayerEx::AddProfileDataChangedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ProfileDataChangedDelegate )
{
	static UFunction* pFnAddProfileDataChangedDelegate = NULL;

	if ( ! pFnAddProfileDataChangedDelegate )
		pFnAddProfileDataChangedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39859 ];

	USFXOnlineComponentUnrealPlayerEx_execAddProfileDataChangedDelegate_Parms AddProfileDataChangedDelegate_Parms;
	AddProfileDataChangedDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddProfileDataChangedDelegate_Parms.ProfileDataChangedDelegate, &ProfileDataChangedDelegate, 0x10 );

	this->ProcessEvent ( pFnAddProfileDataChangedDelegate, &AddProfileDataChangedDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.OnProfileDataChanged
// [0x00120000] 
// Parameters infos:

void USFXOnlineComponentUnrealPlayerEx::OnProfileDataChanged ( )
{
	static UFunction* pFnOnProfileDataChanged = NULL;

	if ( ! pFnOnProfileDataChanged )
		pFnOnProfileDataChanged = (UFunction*) UObject::GObjObjects()->Data[ 39858 ];

	USFXOnlineComponentUnrealPlayerEx_execOnProfileDataChanged_Parms OnProfileDataChanged_Parms;

	this->ProcessEvent ( pFnOnProfileDataChanged, &OnProfileDataChanged_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.UnlockGamerPicture
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            PictureId                      ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayerEx::UnlockGamerPicture ( unsigned char LocalUserNum, int PictureId )
{
	static UFunction* pFnUnlockGamerPicture = NULL;

	if ( ! pFnUnlockGamerPicture )
		pFnUnlockGamerPicture = (UFunction*) UObject::GObjObjects()->Data[ 39854 ];

	USFXOnlineComponentUnrealPlayerEx_execUnlockGamerPicture_Parms UnlockGamerPicture_Parms;
	UnlockGamerPicture_Parms.LocalUserNum = LocalUserNum;
	UnlockGamerPicture_Parms.PictureId = PictureId;

	this->ProcessEvent ( pFnUnlockGamerPicture, &UnlockGamerPicture_Parms, NULL );

	return UnlockGamerPicture_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.IsDeviceValid
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            DeviceID                       ( CPF_Parm )
// int                            SizeNeeded                     ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentUnrealPlayerEx::IsDeviceValid ( int DeviceID, int SizeNeeded )
{
	static UFunction* pFnIsDeviceValid = NULL;

	if ( ! pFnIsDeviceValid )
		pFnIsDeviceValid = (UFunction*) UObject::GObjObjects()->Data[ 39850 ];

	USFXOnlineComponentUnrealPlayerEx_execIsDeviceValid_Parms IsDeviceValid_Parms;
	IsDeviceValid_Parms.DeviceID = DeviceID;
	IsDeviceValid_Parms.SizeNeeded = SizeNeeded;

	pFnIsDeviceValid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsDeviceValid, &IsDeviceValid_Parms, NULL );

	pFnIsDeviceValid->FunctionFlags |= 0x400;

	return IsDeviceValid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.GetDeviceSelectionResults
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 DeviceName                     ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

int USFXOnlineComponentUnrealPlayerEx::GetDeviceSelectionResults ( unsigned char LocalUserNum, struct FString* DeviceName )
{
	static UFunction* pFnGetDeviceSelectionResults = NULL;

	if ( ! pFnGetDeviceSelectionResults )
		pFnGetDeviceSelectionResults = (UFunction*) UObject::GObjObjects()->Data[ 39846 ];

	USFXOnlineComponentUnrealPlayerEx_execGetDeviceSelectionResults_Parms GetDeviceSelectionResults_Parms;
	GetDeviceSelectionResults_Parms.LocalUserNum = LocalUserNum;

	pFnGetDeviceSelectionResults->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetDeviceSelectionResults, &GetDeviceSelectionResults_Parms, NULL );

	pFnGetDeviceSelectionResults->FunctionFlags |= 0x400;

	if ( DeviceName )
		memcpy ( DeviceName, &GetDeviceSelectionResults_Parms.DeviceName, 0x10 );

	return GetDeviceSelectionResults_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ClearDeviceSelectionDoneDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         DeviceDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayerEx::ClearDeviceSelectionDoneDelegate ( unsigned char LocalUserNum, struct FScriptDelegate DeviceDelegate )
{
	static UFunction* pFnClearDeviceSelectionDoneDelegate = NULL;

	if ( ! pFnClearDeviceSelectionDoneDelegate )
		pFnClearDeviceSelectionDoneDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39842 ];

	USFXOnlineComponentUnrealPlayerEx_execClearDeviceSelectionDoneDelegate_Parms ClearDeviceSelectionDoneDelegate_Parms;
	ClearDeviceSelectionDoneDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ClearDeviceSelectionDoneDelegate_Parms.DeviceDelegate, &DeviceDelegate, 0x10 );

	this->ProcessEvent ( pFnClearDeviceSelectionDoneDelegate, &ClearDeviceSelectionDoneDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.AddDeviceSelectionDoneDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         DeviceDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealPlayerEx::AddDeviceSelectionDoneDelegate ( unsigned char LocalUserNum, struct FScriptDelegate DeviceDelegate )
{
	static UFunction* pFnAddDeviceSelectionDoneDelegate = NULL;

	if ( ! pFnAddDeviceSelectionDoneDelegate )
		pFnAddDeviceSelectionDoneDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39837 ];

	USFXOnlineComponentUnrealPlayerEx_execAddDeviceSelectionDoneDelegate_Parms AddDeviceSelectionDoneDelegate_Parms;
	AddDeviceSelectionDoneDelegate_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &AddDeviceSelectionDoneDelegate_Parms.DeviceDelegate, &DeviceDelegate, 0x10 );

	this->ProcessEvent ( pFnAddDeviceSelectionDoneDelegate, &AddDeviceSelectionDoneDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.OnDeviceSelectionComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void USFXOnlineComponentUnrealPlayerEx::OnDeviceSelectionComplete ( unsigned long bWasSuccessful )
{
	static UFunction* pFnOnDeviceSelectionComplete = NULL;

	if ( ! pFnOnDeviceSelectionComplete )
		pFnOnDeviceSelectionComplete = (UFunction*) UObject::GObjObjects()->Data[ 39794 ];

	USFXOnlineComponentUnrealPlayerEx_execOnDeviceSelectionComplete_Parms OnDeviceSelectionComplete_Parms;
	OnDeviceSelectionComplete_Parms.bWasSuccessful = bWasSuccessful;

	this->ProcessEvent ( pFnOnDeviceSelectionComplete, &OnDeviceSelectionComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ShowDeviceSelectionUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            SizeNeeded                     ( CPF_Parm )
// unsigned long                  bForceShowUI                   ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bManageStorage                 ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentUnrealPlayerEx::ShowDeviceSelectionUI ( unsigned char LocalUserNum, int SizeNeeded, unsigned long bForceShowUI, unsigned long bManageStorage )
{
	static UFunction* pFnShowDeviceSelectionUI = NULL;

	if ( ! pFnShowDeviceSelectionUI )
		pFnShowDeviceSelectionUI = (UFunction*) UObject::GObjObjects()->Data[ 39830 ];

	USFXOnlineComponentUnrealPlayerEx_execShowDeviceSelectionUI_Parms ShowDeviceSelectionUI_Parms;
	ShowDeviceSelectionUI_Parms.LocalUserNum = LocalUserNum;
	ShowDeviceSelectionUI_Parms.SizeNeeded = SizeNeeded;
	ShowDeviceSelectionUI_Parms.bForceShowUI = bForceShowUI;
	ShowDeviceSelectionUI_Parms.bManageStorage = bManageStorage;

	pFnShowDeviceSelectionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowDeviceSelectionUI, &ShowDeviceSelectionUI_Parms, NULL );

	pFnShowDeviceSelectionUI->FunctionFlags |= 0x400;

	return ShowDeviceSelectionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ShowMembershipMarketplaceUI
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayerEx::ShowMembershipMarketplaceUI ( unsigned char LocalUserNum )
{
	static UFunction* pFnShowMembershipMarketplaceUI = NULL;

	if ( ! pFnShowMembershipMarketplaceUI )
		pFnShowMembershipMarketplaceUI = (UFunction*) UObject::GObjObjects()->Data[ 39827 ];

	USFXOnlineComponentUnrealPlayerEx_execShowMembershipMarketplaceUI_Parms ShowMembershipMarketplaceUI_Parms;
	ShowMembershipMarketplaceUI_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnShowMembershipMarketplaceUI, &ShowMembershipMarketplaceUI_Parms, NULL );

	return ShowMembershipMarketplaceUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ShowContentMarketplaceUI
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            CategoryMask                   ( CPF_OptionalParm | CPF_Parm )
// int                            OfferId                        ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentUnrealPlayerEx::ShowContentMarketplaceUI ( unsigned char LocalUserNum, int CategoryMask, int OfferId )
{
	static UFunction* pFnShowContentMarketplaceUI = NULL;

	if ( ! pFnShowContentMarketplaceUI )
		pFnShowContentMarketplaceUI = (UFunction*) UObject::GObjObjects()->Data[ 39822 ];

	USFXOnlineComponentUnrealPlayerEx_execShowContentMarketplaceUI_Parms ShowContentMarketplaceUI_Parms;
	ShowContentMarketplaceUI_Parms.LocalUserNum = LocalUserNum;
	ShowContentMarketplaceUI_Parms.CategoryMask = CategoryMask;
	ShowContentMarketplaceUI_Parms.OfferId = OfferId;

	this->ProcessEvent ( pFnShowContentMarketplaceUI, &ShowContentMarketplaceUI_Parms, NULL );

	return ShowContentMarketplaceUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ShowInviteUI
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 InviteText                     ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentUnrealPlayerEx::ShowInviteUI ( unsigned char LocalUserNum, struct FString InviteText )
{
	static UFunction* pFnShowInviteUI = NULL;

	if ( ! pFnShowInviteUI )
		pFnShowInviteUI = (UFunction*) UObject::GObjObjects()->Data[ 39818 ];

	USFXOnlineComponentUnrealPlayerEx_execShowInviteUI_Parms ShowInviteUI_Parms;
	ShowInviteUI_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ShowInviteUI_Parms.InviteText, &InviteText, 0x10 );

	this->ProcessEvent ( pFnShowInviteUI, &ShowInviteUI_Parms, NULL );

	return ShowInviteUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ShowAchievementsUI
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayerEx::ShowAchievementsUI ( unsigned char LocalUserNum )
{
	static UFunction* pFnShowAchievementsUI = NULL;

	if ( ! pFnShowAchievementsUI )
		pFnShowAchievementsUI = (UFunction*) UObject::GObjObjects()->Data[ 39815 ];

	USFXOnlineComponentUnrealPlayerEx_execShowAchievementsUI_Parms ShowAchievementsUI_Parms;
	ShowAchievementsUI_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnShowAchievementsUI, &ShowAchievementsUI_Parms, NULL );

	return ShowAchievementsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ShowMessagesUI
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayerEx::ShowMessagesUI ( unsigned char LocalUserNum )
{
	static UFunction* pFnShowMessagesUI = NULL;

	if ( ! pFnShowMessagesUI )
		pFnShowMessagesUI = (UFunction*) UObject::GObjObjects()->Data[ 39812 ];

	USFXOnlineComponentUnrealPlayerEx_execShowMessagesUI_Parms ShowMessagesUI_Parms;
	ShowMessagesUI_Parms.LocalUserNum = LocalUserNum;

	this->ProcessEvent ( pFnShowMessagesUI, &ShowMessagesUI_Parms, NULL );

	return ShowMessagesUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ShowGamerCardUI
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayerEx::ShowGamerCardUI ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID )
{
	static UFunction* pFnShowGamerCardUI = NULL;

	if ( ! pFnShowGamerCardUI )
		pFnShowGamerCardUI = (UFunction*) UObject::GObjObjects()->Data[ 39808 ];

	USFXOnlineComponentUnrealPlayerEx_execShowGamerCardUI_Parms ShowGamerCardUI_Parms;
	ShowGamerCardUI_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ShowGamerCardUI_Parms.PlayerID, &PlayerID, 0x8 );

	this->ProcessEvent ( pFnShowGamerCardUI, &ShowGamerCardUI_Parms, NULL );

	return ShowGamerCardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.ShowFeedbackUI
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )

bool USFXOnlineComponentUnrealPlayerEx::ShowFeedbackUI ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID )
{
	static UFunction* pFnShowFeedbackUI = NULL;

	if ( ! pFnShowFeedbackUI )
		pFnShowFeedbackUI = (UFunction*) UObject::GObjObjects()->Data[ 39804 ];

	USFXOnlineComponentUnrealPlayerEx_execShowFeedbackUI_Parms ShowFeedbackUI_Parms;
	ShowFeedbackUI_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ShowFeedbackUI_Parms.PlayerID, &PlayerID, 0x8 );

	this->ProcessEvent ( pFnShowFeedbackUI, &ShowFeedbackUI_Parms, NULL );

	return ShowFeedbackUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.OnTick
// [0x00040401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineComponentUnrealPlayerEx::OnTick ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnOnTick = NULL;

	if ( ! pFnOnTick )
		pFnOnTick = (UFunction*) UObject::GObjObjects()->Data[ 39802 ];

	USFXOnlineComponentUnrealPlayerEx_execOnTick_Parms OnTick_Parms;
	OnTick_Parms.oEvent = oEvent;

	pFnOnTick->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnTick, &OnTick_Parms, NULL );

	pFnOnTick->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentUnrealPlayerEx::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 39800 ];

	USFXOnlineComponentUnrealPlayerEx_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentUnrealPlayerEx::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 39799 ];

	USFXOnlineComponentUnrealPlayerEx_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealPlayerEx.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentUnrealPlayerEx::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 39797 ];

	USFXOnlineComponentUnrealPlayerEx_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.GetTitleFileState
// [0x00020002] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FString                 Filename                       ( CPF_Parm | CPF_NeedCtorLink )

unsigned char USFXOnlineComponentUnrealSystem::GetTitleFileState ( struct FString Filename )
{
	static UFunction* pFnGetTitleFileState = NULL;

	if ( ! pFnGetTitleFileState )
		pFnGetTitleFileState = (UFunction*) UObject::GObjObjects()->Data[ 39970 ];

	USFXOnlineComponentUnrealSystem_execGetTitleFileState_Parms GetTitleFileState_Parms;
	memcpy ( &GetTitleFileState_Parms.Filename, &Filename, 0x10 );

	this->ProcessEvent ( pFnGetTitleFileState, &GetTitleFileState_Parms, NULL );

	return GetTitleFileState_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.GetTitleFileContents
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FString                 Filename                       ( CPF_Parm | CPF_NeedCtorLink )
// struct TArray<unsigned char>   FileContents                   ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

bool USFXOnlineComponentUnrealSystem::GetTitleFileContents ( struct FString Filename, struct TArray<unsigned char>* FileContents )
{
	static UFunction* pFnGetTitleFileContents = NULL;

	if ( ! pFnGetTitleFileContents )
		pFnGetTitleFileContents = (UFunction*) UObject::GObjObjects()->Data[ 39965 ];

	USFXOnlineComponentUnrealSystem_execGetTitleFileContents_Parms GetTitleFileContents_Parms;
	memcpy ( &GetTitleFileContents_Parms.Filename, &Filename, 0x10 );

	pFnGetTitleFileContents->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetTitleFileContents, &GetTitleFileContents_Parms, NULL );

	pFnGetTitleFileContents->FunctionFlags |= 0x400;

	if ( FileContents )
		memcpy ( FileContents, &GetTitleFileContents_Parms.FileContents, 0x10 );

	return GetTitleFileContents_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.ClearReadTitleFileCompleteDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         ReadTitleFileCompleteDelegate  ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::ClearReadTitleFileCompleteDelegate ( struct FScriptDelegate ReadTitleFileCompleteDelegate )
{
	static UFunction* pFnClearReadTitleFileCompleteDelegate = NULL;

	if ( ! pFnClearReadTitleFileCompleteDelegate )
		pFnClearReadTitleFileCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39962 ];

	USFXOnlineComponentUnrealSystem_execClearReadTitleFileCompleteDelegate_Parms ClearReadTitleFileCompleteDelegate_Parms;
	memcpy ( &ClearReadTitleFileCompleteDelegate_Parms.ReadTitleFileCompleteDelegate, &ReadTitleFileCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnClearReadTitleFileCompleteDelegate, &ClearReadTitleFileCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.AddReadTitleFileCompleteDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         ReadTitleFileCompleteDelegate  ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::AddReadTitleFileCompleteDelegate ( struct FScriptDelegate ReadTitleFileCompleteDelegate )
{
	static UFunction* pFnAddReadTitleFileCompleteDelegate = NULL;

	if ( ! pFnAddReadTitleFileCompleteDelegate )
		pFnAddReadTitleFileCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39960 ];

	USFXOnlineComponentUnrealSystem_execAddReadTitleFileCompleteDelegate_Parms AddReadTitleFileCompleteDelegate_Parms;
	memcpy ( &AddReadTitleFileCompleteDelegate_Parms.ReadTitleFileCompleteDelegate, &ReadTitleFileCompleteDelegate, 0x10 );

	this->ProcessEvent ( pFnAddReadTitleFileCompleteDelegate, &AddReadTitleFileCompleteDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.ReadTitleFile
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FString                 FileToRead                     ( CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentUnrealSystem::ReadTitleFile ( struct FString FileToRead )
{
	static UFunction* pFnReadTitleFile = NULL;

	if ( ! pFnReadTitleFile )
		pFnReadTitleFile = (UFunction*) UObject::GObjObjects()->Data[ 39957 ];

	USFXOnlineComponentUnrealSystem_execReadTitleFile_Parms ReadTitleFile_Parms;
	memcpy ( &ReadTitleFile_Parms.FileToRead, &FileToRead, 0x10 );

	pFnReadTitleFile->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnReadTitleFile, &ReadTitleFile_Parms, NULL );

	pFnReadTitleFile->FunctionFlags |= 0x400;

	return ReadTitleFile_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.OnReadTitleFileComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )
// struct FString                 Filename                       ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::OnReadTitleFileComplete ( unsigned long bWasSuccessful, struct FString Filename )
{
	static UFunction* pFnOnReadTitleFileComplete = NULL;

	if ( ! pFnOnReadTitleFileComplete )
		pFnOnReadTitleFileComplete = (UFunction*) UObject::GObjObjects()->Data[ 39892 ];

	USFXOnlineComponentUnrealSystem_execOnReadTitleFileComplete_Parms OnReadTitleFileComplete_Parms;
	OnReadTitleFileComplete_Parms.bWasSuccessful = bWasSuccessful;
	memcpy ( &OnReadTitleFileComplete_Parms.Filename, &Filename, 0x10 );

	this->ProcessEvent ( pFnOnReadTitleFileComplete, &OnReadTitleFileComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.ClearStorageDeviceChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         StorageDeviceChangeDelegate    ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::ClearStorageDeviceChangeDelegate ( struct FScriptDelegate StorageDeviceChangeDelegate )
{
	static UFunction* pFnClearStorageDeviceChangeDelegate = NULL;

	if ( ! pFnClearStorageDeviceChangeDelegate )
		pFnClearStorageDeviceChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39952 ];

	USFXOnlineComponentUnrealSystem_execClearStorageDeviceChangeDelegate_Parms ClearStorageDeviceChangeDelegate_Parms;
	memcpy ( &ClearStorageDeviceChangeDelegate_Parms.StorageDeviceChangeDelegate, &StorageDeviceChangeDelegate, 0x10 );

	this->ProcessEvent ( pFnClearStorageDeviceChangeDelegate, &ClearStorageDeviceChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.AddStorageDeviceChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         StorageDeviceChangeDelegate    ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::AddStorageDeviceChangeDelegate ( struct FScriptDelegate StorageDeviceChangeDelegate )
{
	static UFunction* pFnAddStorageDeviceChangeDelegate = NULL;

	if ( ! pFnAddStorageDeviceChangeDelegate )
		pFnAddStorageDeviceChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39950 ];

	USFXOnlineComponentUnrealSystem_execAddStorageDeviceChangeDelegate_Parms AddStorageDeviceChangeDelegate_Parms;
	memcpy ( &AddStorageDeviceChangeDelegate_Parms.StorageDeviceChangeDelegate, &StorageDeviceChangeDelegate, 0x10 );

	this->ProcessEvent ( pFnAddStorageDeviceChangeDelegate, &AddStorageDeviceChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.OnStorageDeviceChange
// [0x00120000] 
// Parameters infos:

void USFXOnlineComponentUnrealSystem::OnStorageDeviceChange ( )
{
	static UFunction* pFnOnStorageDeviceChange = NULL;

	if ( ! pFnOnStorageDeviceChange )
		pFnOnStorageDeviceChange = (UFunction*) UObject::GObjObjects()->Data[ 39895 ];

	USFXOnlineComponentUnrealSystem_execOnStorageDeviceChange_Parms OnStorageDeviceChange_Parms;

	this->ProcessEvent ( pFnOnStorageDeviceChange, &OnStorageDeviceChange_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.GetNATType
// [0x00020002] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char USFXOnlineComponentUnrealSystem::GetNATType ( )
{
	static UFunction* pFnGetNATType = NULL;

	if ( ! pFnGetNATType )
		pFnGetNATType = (UFunction*) UObject::GObjObjects()->Data[ 39948 ];

	USFXOnlineComponentUnrealSystem_execGetNATType_Parms GetNATType_Parms;

	this->ProcessEvent ( pFnGetNATType, &GetNATType_Parms, NULL );

	return GetNATType_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.ClearConnectionStatusChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         ConnectionStatusDelegate       ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::ClearConnectionStatusChangeDelegate ( struct FScriptDelegate ConnectionStatusDelegate )
{
	static UFunction* pFnClearConnectionStatusChangeDelegate = NULL;

	if ( ! pFnClearConnectionStatusChangeDelegate )
		pFnClearConnectionStatusChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39945 ];

	USFXOnlineComponentUnrealSystem_execClearConnectionStatusChangeDelegate_Parms ClearConnectionStatusChangeDelegate_Parms;
	memcpy ( &ClearConnectionStatusChangeDelegate_Parms.ConnectionStatusDelegate, &ConnectionStatusDelegate, 0x10 );

	this->ProcessEvent ( pFnClearConnectionStatusChangeDelegate, &ClearConnectionStatusChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.AddConnectionStatusChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         ConnectionStatusDelegate       ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::AddConnectionStatusChangeDelegate ( struct FScriptDelegate ConnectionStatusDelegate )
{
	static UFunction* pFnAddConnectionStatusChangeDelegate = NULL;

	if ( ! pFnAddConnectionStatusChangeDelegate )
		pFnAddConnectionStatusChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39942 ];

	USFXOnlineComponentUnrealSystem_execAddConnectionStatusChangeDelegate_Parms AddConnectionStatusChangeDelegate_Parms;
	memcpy ( &AddConnectionStatusChangeDelegate_Parms.ConnectionStatusDelegate, &ConnectionStatusDelegate, 0x10 );

	this->ProcessEvent ( pFnAddConnectionStatusChangeDelegate, &AddConnectionStatusChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.OnConnectionStatusChange
// [0x00120000] 
// Parameters infos:
// unsigned char                  ConnectionStatus               ( CPF_Parm )

void USFXOnlineComponentUnrealSystem::OnConnectionStatusChange ( unsigned char ConnectionStatus )
{
	static UFunction* pFnOnConnectionStatusChange = NULL;

	if ( ! pFnOnConnectionStatusChange )
		pFnOnConnectionStatusChange = (UFunction*) UObject::GObjObjects()->Data[ 39898 ];

	USFXOnlineComponentUnrealSystem_execOnConnectionStatusChange_Parms OnConnectionStatusChange_Parms;
	OnConnectionStatusChange_Parms.ConnectionStatus = ConnectionStatus;

	this->ProcessEvent ( pFnOnConnectionStatusChange, &OnConnectionStatusChange_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.IsControllerConnected
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            ControllerId                   ( CPF_Parm )

bool USFXOnlineComponentUnrealSystem::IsControllerConnected ( int ControllerId )
{
	static UFunction* pFnIsControllerConnected = NULL;

	if ( ! pFnIsControllerConnected )
		pFnIsControllerConnected = (UFunction*) UObject::GObjObjects()->Data[ 39938 ];

	USFXOnlineComponentUnrealSystem_execIsControllerConnected_Parms IsControllerConnected_Parms;
	IsControllerConnected_Parms.ControllerId = ControllerId;

	pFnIsControllerConnected->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsControllerConnected, &IsControllerConnected_Parms, NULL );

	pFnIsControllerConnected->FunctionFlags |= 0x400;

	return IsControllerConnected_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.ClearControllerChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         ControllerChangeDelegate       ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::ClearControllerChangeDelegate ( struct FScriptDelegate ControllerChangeDelegate )
{
	static UFunction* pFnClearControllerChangeDelegate = NULL;

	if ( ! pFnClearControllerChangeDelegate )
		pFnClearControllerChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39935 ];

	USFXOnlineComponentUnrealSystem_execClearControllerChangeDelegate_Parms ClearControllerChangeDelegate_Parms;
	memcpy ( &ClearControllerChangeDelegate_Parms.ControllerChangeDelegate, &ControllerChangeDelegate, 0x10 );

	this->ProcessEvent ( pFnClearControllerChangeDelegate, &ClearControllerChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.AddControllerChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         ControllerChangeDelegate       ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::AddControllerChangeDelegate ( struct FScriptDelegate ControllerChangeDelegate )
{
	static UFunction* pFnAddControllerChangeDelegate = NULL;

	if ( ! pFnAddControllerChangeDelegate )
		pFnAddControllerChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39932 ];

	USFXOnlineComponentUnrealSystem_execAddControllerChangeDelegate_Parms AddControllerChangeDelegate_Parms;
	memcpy ( &AddControllerChangeDelegate_Parms.ControllerChangeDelegate, &ControllerChangeDelegate, 0x10 );

	this->ProcessEvent ( pFnAddControllerChangeDelegate, &AddControllerChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.OnControllerChange
// [0x00120000] 
// Parameters infos:
// int                            ControllerId                   ( CPF_Parm )
// unsigned long                  bIsConnected                   ( CPF_Parm )

void USFXOnlineComponentUnrealSystem::OnControllerChange ( int ControllerId, unsigned long bIsConnected )
{
	static UFunction* pFnOnControllerChange = NULL;

	if ( ! pFnOnControllerChange )
		pFnOnControllerChange = (UFunction*) UObject::GObjObjects()->Data[ 39887 ];

	USFXOnlineComponentUnrealSystem_execOnControllerChange_Parms OnControllerChange_Parms;
	OnControllerChange_Parms.ControllerId = ControllerId;
	OnControllerChange_Parms.bIsConnected = bIsConnected;

	this->ProcessEvent ( pFnOnControllerChange, &OnControllerChange_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.SetNetworkNotificationPosition
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  NewPos                         ( CPF_Parm )

void USFXOnlineComponentUnrealSystem::SetNetworkNotificationPosition ( unsigned char NewPos )
{
	static UFunction* pFnSetNetworkNotificationPosition = NULL;

	if ( ! pFnSetNetworkNotificationPosition )
		pFnSetNetworkNotificationPosition = (UFunction*) UObject::GObjObjects()->Data[ 39928 ];

	USFXOnlineComponentUnrealSystem_execSetNetworkNotificationPosition_Parms SetNetworkNotificationPosition_Parms;
	SetNetworkNotificationPosition_Parms.NewPos = NewPos;

	pFnSetNetworkNotificationPosition->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetNetworkNotificationPosition, &SetNetworkNotificationPosition_Parms, NULL );

	pFnSetNetworkNotificationPosition->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.GetNetworkNotificationPosition
// [0x00020002] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char USFXOnlineComponentUnrealSystem::GetNetworkNotificationPosition ( )
{
	static UFunction* pFnGetNetworkNotificationPosition = NULL;

	if ( ! pFnGetNetworkNotificationPosition )
		pFnGetNetworkNotificationPosition = (UFunction*) UObject::GObjObjects()->Data[ 39925 ];

	USFXOnlineComponentUnrealSystem_execGetNetworkNotificationPosition_Parms GetNetworkNotificationPosition_Parms;

	this->ProcessEvent ( pFnGetNetworkNotificationPosition, &GetNetworkNotificationPosition_Parms, NULL );

	return GetNetworkNotificationPosition_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.ProcessExternalUINotification
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned long                  bOpening                       ( CPF_Parm )

void USFXOnlineComponentUnrealSystem::ProcessExternalUINotification ( unsigned long bOpening )
{
	static UFunction* pFnProcessExternalUINotification = NULL;

	if ( ! pFnProcessExternalUINotification )
		pFnProcessExternalUINotification = (UFunction*) UObject::GObjObjects()->Data[ 39923 ];

	USFXOnlineComponentUnrealSystem_execProcessExternalUINotification_Parms ProcessExternalUINotification_Parms;
	ProcessExternalUINotification_Parms.bOpening = bOpening;

	pFnProcessExternalUINotification->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnProcessExternalUINotification, &ProcessExternalUINotification_Parms, NULL );

	pFnProcessExternalUINotification->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.ClearExternalUIChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         ExternalUIDelegate             ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::ClearExternalUIChangeDelegate ( struct FScriptDelegate ExternalUIDelegate )
{
	static UFunction* pFnClearExternalUIChangeDelegate = NULL;

	if ( ! pFnClearExternalUIChangeDelegate )
		pFnClearExternalUIChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39920 ];

	USFXOnlineComponentUnrealSystem_execClearExternalUIChangeDelegate_Parms ClearExternalUIChangeDelegate_Parms;
	memcpy ( &ClearExternalUIChangeDelegate_Parms.ExternalUIDelegate, &ExternalUIDelegate, 0x10 );

	this->ProcessEvent ( pFnClearExternalUIChangeDelegate, &ClearExternalUIChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.AddExternalUIChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         ExternalUIDelegate             ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::AddExternalUIChangeDelegate ( struct FScriptDelegate ExternalUIDelegate )
{
	static UFunction* pFnAddExternalUIChangeDelegate = NULL;

	if ( ! pFnAddExternalUIChangeDelegate )
		pFnAddExternalUIChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39917 ];

	USFXOnlineComponentUnrealSystem_execAddExternalUIChangeDelegate_Parms AddExternalUIChangeDelegate_Parms;
	memcpy ( &AddExternalUIChangeDelegate_Parms.ExternalUIDelegate, &ExternalUIDelegate, 0x10 );

	this->ProcessEvent ( pFnAddExternalUIChangeDelegate, &AddExternalUIChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.OnExternalUIChange
// [0x00120000] 
// Parameters infos:
// unsigned long                  bIsOpening                     ( CPF_Parm )

void USFXOnlineComponentUnrealSystem::OnExternalUIChange ( unsigned long bIsOpening )
{
	static UFunction* pFnOnExternalUIChange = NULL;

	if ( ! pFnOnExternalUIChange )
		pFnOnExternalUIChange = (UFunction*) UObject::GObjObjects()->Data[ 39884 ];

	USFXOnlineComponentUnrealSystem_execOnExternalUIChange_Parms OnExternalUIChange_Parms;
	OnExternalUIChange_Parms.bIsOpening = bIsOpening;

	this->ProcessEvent ( pFnOnExternalUIChange, &OnExternalUIChange_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.ClearLinkStatusChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         LinkStatusDelegate             ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::ClearLinkStatusChangeDelegate ( struct FScriptDelegate LinkStatusDelegate )
{
	static UFunction* pFnClearLinkStatusChangeDelegate = NULL;

	if ( ! pFnClearLinkStatusChangeDelegate )
		pFnClearLinkStatusChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39913 ];

	USFXOnlineComponentUnrealSystem_execClearLinkStatusChangeDelegate_Parms ClearLinkStatusChangeDelegate_Parms;
	memcpy ( &ClearLinkStatusChangeDelegate_Parms.LinkStatusDelegate, &LinkStatusDelegate, 0x10 );

	this->ProcessEvent ( pFnClearLinkStatusChangeDelegate, &ClearLinkStatusChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.AddLinkStatusChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         LinkStatusDelegate             ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentUnrealSystem::AddLinkStatusChangeDelegate ( struct FScriptDelegate LinkStatusDelegate )
{
	static UFunction* pFnAddLinkStatusChangeDelegate = NULL;

	if ( ! pFnAddLinkStatusChangeDelegate )
		pFnAddLinkStatusChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 39910 ];

	USFXOnlineComponentUnrealSystem_execAddLinkStatusChangeDelegate_Parms AddLinkStatusChangeDelegate_Parms;
	memcpy ( &AddLinkStatusChangeDelegate_Parms.LinkStatusDelegate, &LinkStatusDelegate, 0x10 );

	this->ProcessEvent ( pFnAddLinkStatusChangeDelegate, &AddLinkStatusChangeDelegate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.OnLinkStatusChange
// [0x00120000] 
// Parameters infos:
// unsigned long                  bIsConnected                   ( CPF_Parm )

void USFXOnlineComponentUnrealSystem::OnLinkStatusChange ( unsigned long bIsConnected )
{
	static UFunction* pFnOnLinkStatusChange = NULL;

	if ( ! pFnOnLinkStatusChange )
		pFnOnLinkStatusChange = (UFunction*) UObject::GObjObjects()->Data[ 39908 ];

	USFXOnlineComponentUnrealSystem_execOnLinkStatusChange_Parms OnLinkStatusChange_Parms;
	OnLinkStatusChange_Parms.bIsConnected = bIsConnected;

	this->ProcessEvent ( pFnOnLinkStatusChange, &OnLinkStatusChange_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.HasLinkConnection
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentUnrealSystem::HasLinkConnection ( )
{
	static UFunction* pFnHasLinkConnection = NULL;

	if ( ! pFnHasLinkConnection )
		pFnHasLinkConnection = (UFunction*) UObject::GObjObjects()->Data[ 39906 ];

	USFXOnlineComponentUnrealSystem_execHasLinkConnection_Parms HasLinkConnection_Parms;

	pFnHasLinkConnection->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnHasLinkConnection, &HasLinkConnection_Parms, NULL );

	pFnHasLinkConnection->FunctionFlags |= 0x400;

	return HasLinkConnection_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentUnrealSystem::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 39904 ];

	USFXOnlineComponentUnrealSystem_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentUnrealSystem::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 39903 ];

	USFXOnlineComponentUnrealSystem_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentUnrealSystem.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentUnrealSystem::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 39901 ];

	USFXOnlineComponentUnrealSystem_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.GetAPIName
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentCoordinator::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 38780 ];

	USFXOnlineComponentCoordinator_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.OnRelease
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void USFXOnlineComponentCoordinator::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 38779 ];

	USFXOnlineComponentCoordinator_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.OnInitialize
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentCoordinator::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 38777 ];

	USFXOnlineComponentCoordinator_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.StopWaitingForAllWork
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class UObject*                 oCallbackTarget                ( CPF_Parm )

void USFXOnlineComponentCoordinator::StopWaitingForAllWork ( class UObject* oCallbackTarget )
{
	static UFunction* pFnStopWaitingForAllWork = NULL;

	if ( ! pFnStopWaitingForAllWork )
		pFnStopWaitingForAllWork = (UFunction*) UObject::GObjObjects()->Data[ 38775 ];

	USFXOnlineComponentCoordinator_execStopWaitingForAllWork_Parms StopWaitingForAllWork_Parms;
	StopWaitingForAllWork_Parms.oCallbackTarget = oCallbackTarget;

	pFnStopWaitingForAllWork->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnStopWaitingForAllWork, &StopWaitingForAllWork_Parms, NULL );

	pFnStopWaitingForAllWork->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.WaitingForWorkSetObject
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct TArray<class USFXOnlineEvent*> aEventObjects                  ( CPF_Parm | CPF_NeedCtorLink )
// struct FScriptDelegate         fnWorkComplete                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentCoordinator::WaitingForWorkSetObject ( struct TArray<class USFXOnlineEvent*> aEventObjects, struct FScriptDelegate fnWorkComplete )
{
	static UFunction* pFnWaitingForWorkSetObject = NULL;

	if ( ! pFnWaitingForWorkSetObject )
		pFnWaitingForWorkSetObject = (UFunction*) UObject::GObjObjects()->Data[ 38771 ];

	USFXOnlineComponentCoordinator_execWaitingForWorkSetObject_Parms WaitingForWorkSetObject_Parms;
	memcpy ( &WaitingForWorkSetObject_Parms.aEventObjects, &aEventObjects, 0x10 );
	memcpy ( &WaitingForWorkSetObject_Parms.fnWorkComplete, &fnWorkComplete, 0x10 );

	pFnWaitingForWorkSetObject->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWaitingForWorkSetObject, &WaitingForWorkSetObject_Parms, NULL );

	pFnWaitingForWorkSetObject->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.WaitingForWorkSetType
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// struct TArray<unsigned char>   aEventTypes                    ( CPF_Parm | CPF_NeedCtorLink )
// struct FScriptDelegate         fnWorkComplete                 ( CPF_Parm | CPF_NeedCtorLink )
// struct TArray<int>             aWorkEventIds                  ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentCoordinator::WaitingForWorkSetType ( struct TArray<unsigned char> aEventTypes, struct FScriptDelegate fnWorkComplete, struct TArray<int> aWorkEventIds )
{
	static UFunction* pFnWaitingForWorkSetType = NULL;

	if ( ! pFnWaitingForWorkSetType )
		pFnWaitingForWorkSetType = (UFunction*) UObject::GObjObjects()->Data[ 38765 ];

	USFXOnlineComponentCoordinator_execWaitingForWorkSetType_Parms WaitingForWorkSetType_Parms;
	memcpy ( &WaitingForWorkSetType_Parms.aEventTypes, &aEventTypes, 0x10 );
	memcpy ( &WaitingForWorkSetType_Parms.fnWorkComplete, &fnWorkComplete, 0x10 );
	memcpy ( &WaitingForWorkSetType_Parms.aWorkEventIds, &aWorkEventIds, 0x10 );

	pFnWaitingForWorkSetType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWaitingForWorkSetType, &WaitingForWorkSetType_Parms, NULL );

	pFnWaitingForWorkSetType->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.WaitingForWorkObject
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )
// struct FScriptDelegate         fnWorkComplete                 ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentCoordinator::WaitingForWorkObject ( class USFXOnlineEvent* oEvent, struct FScriptDelegate fnWorkComplete )
{
	static UFunction* pFnWaitingForWorkObject = NULL;

	if ( ! pFnWaitingForWorkObject )
		pFnWaitingForWorkObject = (UFunction*) UObject::GObjObjects()->Data[ 38762 ];

	USFXOnlineComponentCoordinator_execWaitingForWorkObject_Parms WaitingForWorkObject_Parms;
	WaitingForWorkObject_Parms.oEvent = oEvent;
	memcpy ( &WaitingForWorkObject_Parms.fnWorkComplete, &fnWorkComplete, 0x10 );

	pFnWaitingForWorkObject->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWaitingForWorkObject, &WaitingForWorkObject_Parms, NULL );

	pFnWaitingForWorkObject->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.WaitingForWorkType
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  eEventType                     ( CPF_Parm )
// struct FScriptDelegate         fnWorkComplete                 ( CPF_Parm | CPF_NeedCtorLink )
// int                            nEventId                       ( CPF_OptionalParm | CPF_Parm )

void USFXOnlineComponentCoordinator::WaitingForWorkType ( unsigned char eEventType, struct FScriptDelegate fnWorkComplete, int nEventId )
{
	static UFunction* pFnWaitingForWorkType = NULL;

	if ( ! pFnWaitingForWorkType )
		pFnWaitingForWorkType = (UFunction*) UObject::GObjObjects()->Data[ 38758 ];

	USFXOnlineComponentCoordinator_execWaitingForWorkType_Parms WaitingForWorkType_Parms;
	WaitingForWorkType_Parms.eEventType = eEventType;
	memcpy ( &WaitingForWorkType_Parms.fnWorkComplete, &fnWorkComplete, 0x10 );
	WaitingForWorkType_Parms.nEventId = nEventId;

	pFnWaitingForWorkType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWaitingForWorkType, &WaitingForWorkType_Parms, NULL );

	pFnWaitingForWorkType->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.IsEventPending
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eEventType                     ( CPF_Parm )
// int                            nEventId                       ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentCoordinator::IsEventPending ( unsigned char eEventType, int nEventId )
{
	static UFunction* pFnIsEventPending = NULL;

	if ( ! pFnIsEventPending )
		pFnIsEventPending = (UFunction*) UObject::GObjObjects()->Data[ 38754 ];

	USFXOnlineComponentCoordinator_execIsEventPending_Parms IsEventPending_Parms;
	IsEventPending_Parms.eEventType = eEventType;
	IsEventPending_Parms.nEventId = nEventId;

	pFnIsEventPending->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsEventPending, &IsEventPending_Parms, NULL );

	pFnIsEventPending->FunctionFlags |= 0x400;

	return IsEventPending_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.GetEvent
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eEventType                     ( CPF_Parm )
// int                            nEventId                       ( CPF_OptionalParm | CPF_Parm )

class USFXOnlineEvent* USFXOnlineComponentCoordinator::GetEvent ( unsigned char eEventType, int nEventId )
{
	static UFunction* pFnGetEvent = NULL;

	if ( ! pFnGetEvent )
		pFnGetEvent = (UFunction*) UObject::GObjObjects()->Data[ 38750 ];

	USFXOnlineComponentCoordinator_execGetEvent_Parms GetEvent_Parms;
	GetEvent_Parms.eEventType = eEventType;
	GetEvent_Parms.nEventId = nEventId;

	pFnGetEvent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetEvent, &GetEvent_Parms, NULL );

	pFnGetEvent->FunctionFlags |= 0x400;

	return GetEvent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.UnsubscribeFromAllEvents
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class UObject*                 oCallbackTarget                ( CPF_Parm )

void USFXOnlineComponentCoordinator::UnsubscribeFromAllEvents ( class UObject* oCallbackTarget )
{
	static UFunction* pFnUnsubscribeFromAllEvents = NULL;

	if ( ! pFnUnsubscribeFromAllEvents )
		pFnUnsubscribeFromAllEvents = (UFunction*) UObject::GObjObjects()->Data[ 38748 ];

	USFXOnlineComponentCoordinator_execUnsubscribeFromAllEvents_Parms UnsubscribeFromAllEvents_Parms;
	UnsubscribeFromAllEvents_Parms.oCallbackTarget = oCallbackTarget;

	pFnUnsubscribeFromAllEvents->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnUnsubscribeFromAllEvents, &UnsubscribeFromAllEvents_Parms, NULL );

	pFnUnsubscribeFromAllEvents->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.UnsubscribeFromEvent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  eEventType                     ( CPF_Parm )
// struct FScriptDelegate         fnEventCallback                ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentCoordinator::UnsubscribeFromEvent ( unsigned char eEventType, struct FScriptDelegate fnEventCallback )
{
	static UFunction* pFnUnsubscribeFromEvent = NULL;

	if ( ! pFnUnsubscribeFromEvent )
		pFnUnsubscribeFromEvent = (UFunction*) UObject::GObjObjects()->Data[ 38745 ];

	USFXOnlineComponentCoordinator_execUnsubscribeFromEvent_Parms UnsubscribeFromEvent_Parms;
	UnsubscribeFromEvent_Parms.eEventType = eEventType;
	memcpy ( &UnsubscribeFromEvent_Parms.fnEventCallback, &fnEventCallback, 0x10 );

	pFnUnsubscribeFromEvent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnUnsubscribeFromEvent, &UnsubscribeFromEvent_Parms, NULL );

	pFnUnsubscribeFromEvent->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.SubscribeToEvent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  eEventType                     ( CPF_Parm )
// struct FScriptDelegate         fnEventCallback                ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentCoordinator::SubscribeToEvent ( unsigned char eEventType, struct FScriptDelegate fnEventCallback )
{
	static UFunction* pFnSubscribeToEvent = NULL;

	if ( ! pFnSubscribeToEvent )
		pFnSubscribeToEvent = (UFunction*) UObject::GObjObjects()->Data[ 38742 ];

	USFXOnlineComponentCoordinator_execSubscribeToEvent_Parms SubscribeToEvent_Parms;
	SubscribeToEvent_Parms.eEventType = eEventType;
	memcpy ( &SubscribeToEvent_Parms.fnEventCallback, &fnEventCallback, 0x10 );

	pFnSubscribeToEvent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSubscribeToEvent, &SubscribeToEvent_Parms, NULL );

	pFnSubscribeToEvent->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.NotifyWorkFinishedObject
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )
// unsigned char                  eStatusFinished                ( CPF_Parm )

void USFXOnlineComponentCoordinator::NotifyWorkFinishedObject ( class USFXOnlineEvent* oEvent, unsigned char eStatusFinished )
{
	static UFunction* pFnNotifyWorkFinishedObject = NULL;

	if ( ! pFnNotifyWorkFinishedObject )
		pFnNotifyWorkFinishedObject = (UFunction*) UObject::GObjObjects()->Data[ 38739 ];

	USFXOnlineComponentCoordinator_execNotifyWorkFinishedObject_Parms NotifyWorkFinishedObject_Parms;
	NotifyWorkFinishedObject_Parms.oEvent = oEvent;
	NotifyWorkFinishedObject_Parms.eStatusFinished = eStatusFinished;

	pFnNotifyWorkFinishedObject->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNotifyWorkFinishedObject, &NotifyWorkFinishedObject_Parms, NULL );

	pFnNotifyWorkFinishedObject->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.NotifyWorkFinishedType
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  eEventType                     ( CPF_Parm )
// unsigned char                  eStatusFinished                ( CPF_Parm )
// int                            nEventId                       ( CPF_Parm )

void USFXOnlineComponentCoordinator::NotifyWorkFinishedType ( unsigned char eEventType, unsigned char eStatusFinished, int nEventId )
{
	static UFunction* pFnNotifyWorkFinishedType = NULL;

	if ( ! pFnNotifyWorkFinishedType )
		pFnNotifyWorkFinishedType = (UFunction*) UObject::GObjObjects()->Data[ 38735 ];

	USFXOnlineComponentCoordinator_execNotifyWorkFinishedType_Parms NotifyWorkFinishedType_Parms;
	NotifyWorkFinishedType_Parms.eEventType = eEventType;
	NotifyWorkFinishedType_Parms.eStatusFinished = eStatusFinished;
	NotifyWorkFinishedType_Parms.nEventId = nEventId;

	pFnNotifyWorkFinishedType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNotifyWorkFinishedType, &NotifyWorkFinishedType_Parms, NULL );

	pFnNotifyWorkFinishedType->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.NotifyWorkStartedObject
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )
// unsigned char                  eEventType                     ( CPF_Parm )

void USFXOnlineComponentCoordinator::NotifyWorkStartedObject ( class USFXOnlineEvent* oEvent, unsigned char eEventType )
{
	static UFunction* pFnNotifyWorkStartedObject = NULL;

	if ( ! pFnNotifyWorkStartedObject )
		pFnNotifyWorkStartedObject = (UFunction*) UObject::GObjObjects()->Data[ 38732 ];

	USFXOnlineComponentCoordinator_execNotifyWorkStartedObject_Parms NotifyWorkStartedObject_Parms;
	NotifyWorkStartedObject_Parms.oEvent = oEvent;
	NotifyWorkStartedObject_Parms.eEventType = eEventType;

	pFnNotifyWorkStartedObject->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNotifyWorkStartedObject, &NotifyWorkStartedObject_Parms, NULL );

	pFnNotifyWorkStartedObject->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.NotifyWorkStartedType
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  eEventType                     ( CPF_Parm )
// int                            nEventId                       ( CPF_OptionalParm | CPF_Parm )
// float                          fTimeOut                       ( CPF_OptionalParm | CPF_Parm )

void USFXOnlineComponentCoordinator::NotifyWorkStartedType ( unsigned char eEventType, int nEventId, float fTimeOut )
{
	static UFunction* pFnNotifyWorkStartedType = NULL;

	if ( ! pFnNotifyWorkStartedType )
		pFnNotifyWorkStartedType = (UFunction*) UObject::GObjObjects()->Data[ 38728 ];

	USFXOnlineComponentCoordinator_execNotifyWorkStartedType_Parms NotifyWorkStartedType_Parms;
	NotifyWorkStartedType_Parms.eEventType = eEventType;
	NotifyWorkStartedType_Parms.nEventId = nEventId;
	NotifyWorkStartedType_Parms.fTimeOut = fTimeOut;

	pFnNotifyWorkStartedType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNotifyWorkStartedType, &NotifyWorkStartedType_Parms, NULL );

	pFnNotifyWorkStartedType->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.NotifyEventObject
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineComponentCoordinator::NotifyEventObject ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnNotifyEventObject = NULL;

	if ( ! pFnNotifyEventObject )
		pFnNotifyEventObject = (UFunction*) UObject::GObjObjects()->Data[ 38726 ];

	USFXOnlineComponentCoordinator_execNotifyEventObject_Parms NotifyEventObject_Parms;
	NotifyEventObject_Parms.oEvent = oEvent;

	pFnNotifyEventObject->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNotifyEventObject, &NotifyEventObject_Parms, NULL );

	pFnNotifyEventObject->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.NotifyEventType
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  eEventType                     ( CPF_Parm )
// unsigned char                  eStatus                        ( CPF_OptionalParm | CPF_Parm )
// unsigned char                  eOutcome                       ( CPF_OptionalParm | CPF_Parm )

void USFXOnlineComponentCoordinator::NotifyEventType ( unsigned char eEventType, unsigned char eStatus, unsigned char eOutcome )
{
	static UFunction* pFnNotifyEventType = NULL;

	if ( ! pFnNotifyEventType )
		pFnNotifyEventType = (UFunction*) UObject::GObjObjects()->Data[ 38722 ];

	USFXOnlineComponentCoordinator_execNotifyEventType_Parms NotifyEventType_Parms;
	NotifyEventType_Parms.eEventType = eEventType;
	NotifyEventType_Parms.eStatus = eStatus;
	NotifyEventType_Parms.eOutcome = eOutcome;

	pFnNotifyEventType->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNotifyEventType, &NotifyEventType_Parms, NULL );

	pFnNotifyEventType->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.OnTick
// [0x00040401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineComponentCoordinator::OnTick ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnOnTick = NULL;

	if ( ! pFnOnTick )
		pFnOnTick = (UFunction*) UObject::GObjObjects()->Data[ 38720 ];

	USFXOnlineComponentCoordinator_execOnTick_Parms OnTick_Parms;
	OnTick_Parms.oEvent = oEvent;

	pFnOnTick->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnTick, &OnTick_Parms, NULL );

	pFnOnTick->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentCoordinator.OnEvent
// [0x00120000] 
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineComponentCoordinator::OnEvent ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnOnEvent = NULL;

	if ( ! pFnOnEvent )
		pFnOnEvent = (UFunction*) UObject::GObjObjects()->Data[ 38716 ];

	USFXOnlineComponentCoordinator_execOnEvent_Parms OnEvent_Parms;
	OnEvent_Parms.oEvent = oEvent;

	this->ProcessEvent ( pFnOnEvent, &OnEvent_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.Exit
// [0x00020C00] ( FUNC_Event | FUNC_Native )
// Parameters infos:

void USFXOnlineSubsystem::eventExit ( )
{
	static UFunction* pFnExit = NULL;

	if ( ! pFnExit )
		pFnExit = (UFunction*) UObject::GObjObjects()->Data[ 40147 ];

	USFXOnlineSubsystem_eventExit_Parms Exit_Parms;

	pFnExit->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnExit, &Exit_Parms, NULL );

	pFnExit->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.ShowConsoleRoutedKeyboardUI
// [0x00024102] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FString                 sTitleText                     ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sDescriptionText               ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bIsPassword                    ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldValidate                ( CPF_OptionalParm | CPF_Parm )
// struct FString                 sDefaultText                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
// int                            nMaxResultLength               ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineSubsystem::ShowConsoleRoutedKeyboardUI ( unsigned char eLocalUserNum, struct FString sTitleText, struct FString sDescriptionText, unsigned long bIsPassword, unsigned long bShouldValidate, struct FString sDefaultText, int nMaxResultLength )
{
	static UFunction* pFnShowConsoleRoutedKeyboardUI = NULL;

	if ( ! pFnShowConsoleRoutedKeyboardUI )
		pFnShowConsoleRoutedKeyboardUI = (UFunction*) UObject::GObjObjects()->Data[ 40138 ];

	USFXOnlineSubsystem_execShowConsoleRoutedKeyboardUI_Parms ShowConsoleRoutedKeyboardUI_Parms;
	ShowConsoleRoutedKeyboardUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowConsoleRoutedKeyboardUI_Parms.sTitleText, &sTitleText, 0x10 );
	memcpy ( &ShowConsoleRoutedKeyboardUI_Parms.sDescriptionText, &sDescriptionText, 0x10 );
	ShowConsoleRoutedKeyboardUI_Parms.bIsPassword = bIsPassword;
	ShowConsoleRoutedKeyboardUI_Parms.bShouldValidate = bShouldValidate;
	memcpy ( &ShowConsoleRoutedKeyboardUI_Parms.sDefaultText, &sDefaultText, 0x10 );
	ShowConsoleRoutedKeyboardUI_Parms.nMaxResultLength = nMaxResultLength;

	this->ProcessEvent ( pFnShowConsoleRoutedKeyboardUI, &ShowConsoleRoutedKeyboardUI_Parms, NULL );

	return ShowConsoleRoutedKeyboardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.ShowKeyboardUI
// [0x00024002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FString                 sTitleText                     ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sDescriptionText               ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bIsPassword                    ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldValidate                ( CPF_OptionalParm | CPF_Parm )
// struct FString                 sDefaultText                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
// int                            nMaxResultLength               ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineSubsystem::ShowKeyboardUI ( unsigned char eLocalUserNum, struct FString sTitleText, struct FString sDescriptionText, unsigned long bIsPassword, unsigned long bShouldValidate, struct FString sDefaultText, int nMaxResultLength )
{
	static UFunction* pFnShowKeyboardUI = NULL;

	if ( ! pFnShowKeyboardUI )
		pFnShowKeyboardUI = (UFunction*) UObject::GObjObjects()->Data[ 40129 ];

	USFXOnlineSubsystem_execShowKeyboardUI_Parms ShowKeyboardUI_Parms;
	ShowKeyboardUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowKeyboardUI_Parms.sTitleText, &sTitleText, 0x10 );
	memcpy ( &ShowKeyboardUI_Parms.sDescriptionText, &sDescriptionText, 0x10 );
	ShowKeyboardUI_Parms.bIsPassword = bIsPassword;
	ShowKeyboardUI_Parms.bShouldValidate = bShouldValidate;
	memcpy ( &ShowKeyboardUI_Parms.sDefaultText, &sDefaultText, 0x10 );
	ShowKeyboardUI_Parms.nMaxResultLength = nMaxResultLength;

	this->ProcessEvent ( pFnShowKeyboardUI, &ShowKeyboardUI_Parms, NULL );

	return ShowKeyboardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.FormatTime
// [0x00044401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// float                          fInSeconds                     ( CPF_Parm )
// unsigned long                  bShowHours                     ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShowMins                      ( CPF_OptionalParm | CPF_Parm )

struct FString USFXOnlineSubsystem::FormatTime ( float fInSeconds, unsigned long bShowHours, unsigned long bShowMins )
{
	static UFunction* pFnFormatTime = NULL;

	if ( ! pFnFormatTime )
		pFnFormatTime = (UFunction*) UObject::GObjObjects()->Data[ 40124 ];

	USFXOnlineSubsystem_execFormatTime_Parms FormatTime_Parms;
	FormatTime_Parms.fInSeconds = fInSeconds;
	FormatTime_Parms.bShowHours = bShowHours;
	FormatTime_Parms.bShowMins = bShowMins;

	pFnFormatTime->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnFormatTime, &FormatTime_Parms, NULL );

	pFnFormatTime->FunctionFlags |= 0x400;

	return FormatTime_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.CheckEntitlement
// [0x00020002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FString                 sGroup                         ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sTag                           ( CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineSubsystem::CheckEntitlement ( struct FString sGroup, struct FString sTag )
{
	static UFunction* pFnCheckEntitlement = NULL;

	if ( ! pFnCheckEntitlement )
		pFnCheckEntitlement = (UFunction*) UObject::GObjObjects()->Data[ 40120 ];

	USFXOnlineSubsystem_execCheckEntitlement_Parms CheckEntitlement_Parms;
	memcpy ( &CheckEntitlement_Parms.sGroup, &sGroup, 0x10 );
	memcpy ( &CheckEntitlement_Parms.sTag, &sTag, 0x10 );

	this->ProcessEvent ( pFnCheckEntitlement, &CheckEntitlement_Parms, NULL );

	return CheckEntitlement_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.IsCerberusMember
// [0x00020002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineSubsystem::IsCerberusMember ( )
{
	static UFunction* pFnIsCerberusMember = NULL;

	if ( ! pFnIsCerberusMember )
		pFnIsCerberusMember = (UFunction*) UObject::GObjObjects()->Data[ 40118 ];

	USFXOnlineSubsystem_execIsCerberusMember_Parms IsCerberusMember_Parms;

	this->ProcessEvent ( pFnIsCerberusMember, &IsCerberusMember_Parms, NULL );

	return IsCerberusMember_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetUniqueIdFromConnection
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FUniqueNetId            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class APlayerReplicationInfo*  oPRI                           ( CPF_Parm )

struct FUniqueNetId USFXOnlineSubsystem::GetUniqueIdFromConnection ( class APlayerReplicationInfo* oPRI )
{
	static UFunction* pFnGetUniqueIdFromConnection = NULL;

	if ( ! pFnGetUniqueIdFromConnection )
		pFnGetUniqueIdFromConnection = (UFunction*) UObject::GObjObjects()->Data[ 40115 ];

	USFXOnlineSubsystem_execGetUniqueIdFromConnection_Parms GetUniqueIdFromConnection_Parms;
	GetUniqueIdFromConnection_Parms.oPRI = oPRI;

	pFnGetUniqueIdFromConnection->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetUniqueIdFromConnection, &GetUniqueIdFromConnection_Parms, NULL );

	pFnGetUniqueIdFromConnection->FunctionFlags |= 0x400;

	return GetUniqueIdFromConnection_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.MD5HashString
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// struct FString                 InStr                          ( CPF_Parm | CPF_NeedCtorLink )

struct FString USFXOnlineSubsystem::MD5HashString ( struct FString InStr )
{
	static UFunction* pFnMD5HashString = NULL;

	if ( ! pFnMD5HashString )
		pFnMD5HashString = (UFunction*) UObject::GObjObjects()->Data[ 40112 ];

	USFXOnlineSubsystem_execMD5HashString_Parms MD5HashString_Parms;
	memcpy ( &MD5HashString_Parms.InStr, &InStr, 0x10 );

	pFnMD5HashString->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnMD5HashString, &MD5HashString_Parms, NULL );

	pFnMD5HashString->FunctionFlags |= 0x400;

	return MD5HashString_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetProjectID
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct FString USFXOnlineSubsystem::GetProjectID ( )
{
	static UFunction* pFnGetProjectID = NULL;

	if ( ! pFnGetProjectID )
		pFnGetProjectID = (UFunction*) UObject::GObjObjects()->Data[ 40110 ];

	USFXOnlineSubsystem_execGetProjectID_Parms GetProjectID_Parms;

	pFnGetProjectID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetProjectID, &GetProjectID_Parms, NULL );

	pFnGetProjectID->FunctionFlags |= 0x400;

	return GetProjectID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetCDKey
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct FString USFXOnlineSubsystem::GetCDKey ( )
{
	static UFunction* pFnGetCDKey = NULL;

	if ( ! pFnGetCDKey )
		pFnGetCDKey = (UFunction*) UObject::GObjObjects()->Data[ 40108 ];

	USFXOnlineSubsystem_execGetCDKey_Parms GetCDKey_Parms;

	pFnGetCDKey->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetCDKey, &GetCDKey_Parms, NULL );

	pFnGetCDKey->FunctionFlags |= 0x400;

	return GetCDKey_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetLanguage
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct FString USFXOnlineSubsystem::GetLanguage ( )
{
	static UFunction* pFnGetLanguage = NULL;

	if ( ! pFnGetLanguage )
		pFnGetLanguage = (UFunction*) UObject::GObjObjects()->Data[ 40106 ];

	USFXOnlineSubsystem_execGetLanguage_Parms GetLanguage_Parms;

	pFnGetLanguage->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetLanguage, &GetLanguage_Parms, NULL );

	pFnGetLanguage->FunctionFlags |= 0x400;

	return GetLanguage_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetPlatform
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineSubsystem::GetPlatform ( )
{
	static UFunction* pFnGetPlatform = NULL;

	if ( ! pFnGetPlatform )
		pFnGetPlatform = (UFunction*) UObject::GObjObjects()->Data[ 40104 ];

	USFXOnlineSubsystem_execGetPlatform_Parms GetPlatform_Parms;

	pFnGetPlatform->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetPlatform, &GetPlatform_Parms, NULL );

	pFnGetPlatform->FunctionFlags |= 0x400;

	return GetPlatform_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.ShutDown
// [0x00020C00] ( FUNC_Event | FUNC_Native )
// Parameters infos:

void USFXOnlineSubsystem::eventShutDown ( )
{
	static UFunction* pFnShutDown = NULL;

	if ( ! pFnShutDown )
		pFnShutDown = (UFunction*) UObject::GObjObjects()->Data[ 40103 ];

	USFXOnlineSubsystem_eventShutDown_Parms ShutDown_Parms;

	pFnShutDown->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShutDown, &ShutDown_Parms, NULL );

	pFnShutDown->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.NativeInit
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineSubsystem::NativeInit ( )
{
	static UFunction* pFnNativeInit = NULL;

	if ( ! pFnNativeInit )
		pFnNativeInit = (UFunction*) UObject::GObjObjects()->Data[ 40101 ];

	USFXOnlineSubsystem_execNativeInit_Parms NativeInit_Parms;

	pFnNativeInit->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnNativeInit, &NativeInit_Parms, NULL );

	pFnNativeInit->FunctionFlags |= 0x400;

	return NativeInit_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetGameListenPort
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineSubsystem::GetGameListenPort ( )
{
	static UFunction* pFnGetGameListenPort = NULL;

	if ( ! pFnGetGameListenPort )
		pFnGetGameListenPort = (UFunction*) UObject::GObjObjects()->Data[ 40099 ];

	USFXOnlineSubsystem_execGetGameListenPort_Parms GetGameListenPort_Parms;

	pFnGetGameListenPort->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetGameListenPort, &GetGameListenPort_Parms, NULL );

	pFnGetGameListenPort->FunctionFlags |= 0x400;

	return GetGameListenPort_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetReserveTimeout
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineSubsystem::GetReserveTimeout ( )
{
	static UFunction* pFnGetReserveTimeout = NULL;

	if ( ! pFnGetReserveTimeout )
		pFnGetReserveTimeout = (UFunction*) UObject::GObjObjects()->Data[ 40097 ];

	USFXOnlineSubsystem_execGetReserveTimeout_Parms GetReserveTimeout_Parms;

	pFnGetReserveTimeout->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetReserveTimeout, &GetReserveTimeout_Parms, NULL );

	pFnGetReserveTimeout->FunctionFlags |= 0x400;

	return GetReserveTimeout_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetMaxObserverCount
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineSubsystem::GetMaxObserverCount ( )
{
	static UFunction* pFnGetMaxObserverCount = NULL;

	if ( ! pFnGetMaxObserverCount )
		pFnGetMaxObserverCount = (UFunction*) UObject::GObjObjects()->Data[ 40095 ];

	USFXOnlineSubsystem_execGetMaxObserverCount_Parms GetMaxObserverCount_Parms;

	pFnGetMaxObserverCount->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetMaxObserverCount, &GetMaxObserverCount_Parms, NULL );

	pFnGetMaxObserverCount->FunctionFlags |= 0x400;

	return GetMaxObserverCount_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetMaxPlayerCount
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineSubsystem::GetMaxPlayerCount ( )
{
	static UFunction* pFnGetMaxPlayerCount = NULL;

	if ( ! pFnGetMaxPlayerCount )
		pFnGetMaxPlayerCount = (UFunction*) UObject::GObjObjects()->Data[ 40093 ];

	USFXOnlineSubsystem_execGetMaxPlayerCount_Parms GetMaxPlayerCount_Parms;

	pFnGetMaxPlayerCount->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetMaxPlayerCount, &GetMaxPlayerCount_Parms, NULL );

	pFnGetMaxPlayerCount->FunctionFlags |= 0x400;

	return GetMaxPlayerCount_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.SetMaxPlayerCount
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            nMaxPlayers                    ( CPF_Parm )

void USFXOnlineSubsystem::SetMaxPlayerCount ( int nMaxPlayers )
{
	static UFunction* pFnSetMaxPlayerCount = NULL;

	if ( ! pFnSetMaxPlayerCount )
		pFnSetMaxPlayerCount = (UFunction*) UObject::GObjObjects()->Data[ 40091 ];

	USFXOnlineSubsystem_execSetMaxPlayerCount_Parms SetMaxPlayerCount_Parms;
	SetMaxPlayerCount_Parms.nMaxPlayers = nMaxPlayers;

	pFnSetMaxPlayerCount->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetMaxPlayerCount, &SetMaxPlayerCount_Parms, NULL );

	pFnSetMaxPlayerCount->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetGameProtocolVersion
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct FString USFXOnlineSubsystem::GetGameProtocolVersion ( )
{
	static UFunction* pFnGetGameProtocolVersion = NULL;

	if ( ! pFnGetGameProtocolVersion )
		pFnGetGameProtocolVersion = (UFunction*) UObject::GObjObjects()->Data[ 40089 ];

	USFXOnlineSubsystem_execGetGameProtocolVersion_Parms GetGameProtocolVersion_Parms;

	pFnGetGameProtocolVersion->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetGameProtocolVersion, &GetGameProtocolVersion_Parms, NULL );

	pFnGetGameProtocolVersion->FunctionFlags |= 0x400;

	return GetGameProtocolVersion_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetComponentOrigin
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineComponentOrigin* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class USFXOnlineComponentOrigin* USFXOnlineSubsystem::GetComponentOrigin ( )
{
	static UFunction* pFnGetComponentOrigin = NULL;

	if ( ! pFnGetComponentOrigin )
		pFnGetComponentOrigin = (UFunction*) UObject::GObjObjects()->Data[ 40087 ];

	USFXOnlineSubsystem_execGetComponentOrigin_Parms GetComponentOrigin_Parms;

	pFnGetComponentOrigin->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetComponentOrigin, &GetComponentOrigin_Parms, NULL );

	pFnGetComponentOrigin->FunctionFlags |= 0x400;

	return GetComponentOrigin_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetComponentUnrealPlayerEx
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineComponentUnrealPlayerEx* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class USFXOnlineComponentUnrealPlayerEx* USFXOnlineSubsystem::GetComponentUnrealPlayerEx ( )
{
	static UFunction* pFnGetComponentUnrealPlayerEx = NULL;

	if ( ! pFnGetComponentUnrealPlayerEx )
		pFnGetComponentUnrealPlayerEx = (UFunction*) UObject::GObjObjects()->Data[ 40059 ];

	USFXOnlineSubsystem_execGetComponentUnrealPlayerEx_Parms GetComponentUnrealPlayerEx_Parms;

	pFnGetComponentUnrealPlayerEx->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetComponentUnrealPlayerEx, &GetComponentUnrealPlayerEx_Parms, NULL );

	pFnGetComponentUnrealPlayerEx->FunctionFlags |= 0x400;

	return GetComponentUnrealPlayerEx_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetComponentUnrealPlayer
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineComponentUnrealPlayer* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class USFXOnlineComponentUnrealPlayer* USFXOnlineSubsystem::GetComponentUnrealPlayer ( )
{
	static UFunction* pFnGetComponentUnrealPlayer = NULL;

	if ( ! pFnGetComponentUnrealPlayer )
		pFnGetComponentUnrealPlayer = (UFunction*) UObject::GObjObjects()->Data[ 40058 ];

	USFXOnlineSubsystem_execGetComponentUnrealPlayer_Parms GetComponentUnrealPlayer_Parms;

	pFnGetComponentUnrealPlayer->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetComponentUnrealPlayer, &GetComponentUnrealPlayer_Parms, NULL );

	pFnGetComponentUnrealPlayer->FunctionFlags |= 0x400;

	return GetComponentUnrealPlayer_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetComponentUnrealSystem
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineComponentUnrealSystem* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class USFXOnlineComponentUnrealSystem* USFXOnlineSubsystem::GetComponentUnrealSystem ( )
{
	static UFunction* pFnGetComponentUnrealSystem = NULL;

	if ( ! pFnGetComponentUnrealSystem )
		pFnGetComponentUnrealSystem = (UFunction*) UObject::GObjObjects()->Data[ 40060 ];

	USFXOnlineSubsystem_execGetComponentUnrealSystem_Parms GetComponentUnrealSystem_Parms;

	pFnGetComponentUnrealSystem->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetComponentUnrealSystem, &GetComponentUnrealSystem_Parms, NULL );

	pFnGetComponentUnrealSystem->FunctionFlags |= 0x400;

	return GetComponentUnrealSystem_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetCoordinator
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineComponentCoordinator* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class USFXOnlineComponentCoordinator* USFXOnlineSubsystem::GetCoordinator ( )
{
	static UFunction* pFnGetCoordinator = NULL;

	if ( ! pFnGetCoordinator )
		pFnGetCoordinator = (UFunction*) UObject::GObjObjects()->Data[ 40082 ];

	USFXOnlineSubsystem_execGetCoordinator_Parms GetCoordinator_Parms;

	pFnGetCoordinator->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetCoordinator, &GetCoordinator_Parms, NULL );

	pFnGetCoordinator->FunctionFlags |= 0x400;

	return GetCoordinator_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetComponentTelemetry
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class UISFXOnlineComponentTelemetry* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class UISFXOnlineComponentTelemetry* USFXOnlineSubsystem::GetComponentTelemetry ( )
{
	static UFunction* pFnGetComponentTelemetry = NULL;

	if ( ! pFnGetComponentTelemetry )
		pFnGetComponentTelemetry = (UFunction*) UObject::GObjObjects()->Data[ 40080 ];

	USFXOnlineSubsystem_execGetComponentTelemetry_Parms GetComponentTelemetry_Parms;

	pFnGetComponentTelemetry->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetComponentTelemetry, &GetComponentTelemetry_Parms, NULL );

	pFnGetComponentTelemetry->FunctionFlags |= 0x400;

	return GetComponentTelemetry_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetComponentNotification
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class UISFXOnlineComponentNotification* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class UISFXOnlineComponentNotification* USFXOnlineSubsystem::GetComponentNotification ( )
{
	static UFunction* pFnGetComponentNotification = NULL;

	if ( ! pFnGetComponentNotification )
		pFnGetComponentNotification = (UFunction*) UObject::GObjObjects()->Data[ 40078 ];

	USFXOnlineSubsystem_execGetComponentNotification_Parms GetComponentNotification_Parms;

	pFnGetComponentNotification->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetComponentNotification, &GetComponentNotification_Parms, NULL );

	pFnGetComponentNotification->FunctionFlags |= 0x400;

	return GetComponentNotification_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetComponentUserInterface
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class UISFXOnlineComponentUserInterface* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class UISFXOnlineComponentUserInterface* USFXOnlineSubsystem::GetComponentUserInterface ( )
{
	static UFunction* pFnGetComponentUserInterface = NULL;

	if ( ! pFnGetComponentUserInterface )
		pFnGetComponentUserInterface = (UFunction*) UObject::GObjObjects()->Data[ 40076 ];

	USFXOnlineSubsystem_execGetComponentUserInterface_Parms GetComponentUserInterface_Parms;

	pFnGetComponentUserInterface->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetComponentUserInterface, &GetComponentUserInterface_Parms, NULL );

	pFnGetComponentUserInterface->FunctionFlags |= 0x400;

	return GetComponentUserInterface_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetComponentLogin
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class UISFXOnlineComponentLogin* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class UISFXOnlineComponentLogin* USFXOnlineSubsystem::GetComponentLogin ( )
{
	static UFunction* pFnGetComponentLogin = NULL;

	if ( ! pFnGetComponentLogin )
		pFnGetComponentLogin = (UFunction*) UObject::GObjObjects()->Data[ 40074 ];

	USFXOnlineSubsystem_execGetComponentLogin_Parms GetComponentLogin_Parms;

	pFnGetComponentLogin->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetComponentLogin, &GetComponentLogin_Parms, NULL );

	pFnGetComponentLogin->FunctionFlags |= 0x400;

	return GetComponentLogin_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetComponentAPI
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class UISFXOnlineComponentAPI* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class UISFXOnlineComponentAPI* USFXOnlineSubsystem::GetComponentAPI ( )
{
	static UFunction* pFnGetComponentAPI = NULL;

	if ( ! pFnGetComponentAPI )
		pFnGetComponentAPI = (UFunction*) UObject::GObjObjects()->Data[ 40072 ];

	USFXOnlineSubsystem_execGetComponentAPI_Parms GetComponentAPI_Parms;

	pFnGetComponentAPI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetComponentAPI, &GetComponentAPI_Parms, NULL );

	pFnGetComponentAPI->FunctionFlags |= 0x400;

	return GetComponentAPI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetComponentAchievement
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class UISFXOnlineComponentAchievement* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class UISFXOnlineComponentAchievement* USFXOnlineSubsystem::GetComponentAchievement ( )
{
	static UFunction* pFnGetComponentAchievement = NULL;

	if ( ! pFnGetComponentAchievement )
		pFnGetComponentAchievement = (UFunction*) UObject::GObjObjects()->Data[ 40070 ];

	USFXOnlineSubsystem_execGetComponentAchievement_Parms GetComponentAchievement_Parms;

	pFnGetComponentAchievement->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetComponentAchievement, &GetComponentAchievement_Parms, NULL );

	pFnGetComponentAchievement->FunctionFlags |= 0x400;

	return GetComponentAchievement_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetComponentPlatform
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class UISFXOnlineComponentPlatform* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class UISFXOnlineComponentPlatform* USFXOnlineSubsystem::GetComponentPlatform ( )
{
	static UFunction* pFnGetComponentPlatform = NULL;

	if ( ! pFnGetComponentPlatform )
		pFnGetComponentPlatform = (UFunction*) UObject::GObjObjects()->Data[ 39437 ];

	USFXOnlineSubsystem_execGetComponentPlatform_Parms GetComponentPlatform_Parms;

	pFnGetComponentPlatform->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetComponentPlatform, &GetComponentPlatform_Parms, NULL );

	pFnGetComponentPlatform->FunctionFlags |= 0x400;

	return GetComponentPlatform_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetOnlineSubsystem
// [0x00022400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class USFXOnlineSubsystem* USFXOnlineSubsystem::GetOnlineSubsystem ( )
{
	static UFunction* pFnGetOnlineSubsystem = NULL;

	if ( ! pFnGetOnlineSubsystem )
		pFnGetOnlineSubsystem = (UFunction*) UObject::GObjObjects()->Data[ 39435 ];

	USFXOnlineSubsystem_execGetOnlineSubsystem_Parms GetOnlineSubsystem_Parms;

	pFnGetOnlineSubsystem->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOnlineSubsystem, &GetOnlineSubsystem_Parms, NULL );

	pFnGetOnlineSubsystem->FunctionFlags |= 0x400;

	return GetOnlineSubsystem_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.StripBadPWCharacters
// [0x00080002] 
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// struct FString                 sPassword                      ( CPF_Parm | CPF_NeedCtorLink )

struct FString USFXOnlineSubsystem::StripBadPWCharacters ( struct FString sPassword )
{
	static UFunction* pFnStripBadPWCharacters = NULL;

	if ( ! pFnStripBadPWCharacters )
		pFnStripBadPWCharacters = (UFunction*) UObject::GObjObjects()->Data[ 40064 ];

	USFXOnlineSubsystem_execStripBadPWCharacters_Parms StripBadPWCharacters_Parms;
	memcpy ( &StripBadPWCharacters_Parms.sPassword, &sPassword, 0x10 );

	this->ProcessEvent ( pFnStripBadPWCharacters, &StripBadPWCharacters_Parms, NULL );

	return StripBadPWCharacters_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetURL
// [0x00020902] ( FUNC_Event )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct FString USFXOnlineSubsystem::eventGetURL ( )
{
	static UFunction* pFnGetURL = NULL;

	if ( ! pFnGetURL )
		pFnGetURL = (UFunction*) UObject::GObjObjects()->Data[ 40061 ];

	USFXOnlineSubsystem_eventGetURL_Parms GetURL_Parms;

	this->ProcessEvent ( pFnGetURL, &GetURL_Parms, NULL );

	return GetURL_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.SetUnrealInterfaces
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void USFXOnlineSubsystem::SetUnrealInterfaces ( )
{
	static UFunction* pFnSetUnrealInterfaces = NULL;

	if ( ! pFnSetUnrealInterfaces )
		pFnSetUnrealInterfaces = (UFunction*) UObject::GObjObjects()->Data[ 40054 ];

	USFXOnlineSubsystem_execSetUnrealInterfaces_Parms SetUnrealInterfaces_Parms;

	this->ProcessEvent ( pFnSetUnrealInterfaces, &SetUnrealInterfaces_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.CreateComponents
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void USFXOnlineSubsystem::CreateComponents ( )
{
	static UFunction* pFnCreateComponents = NULL;

	if ( ! pFnCreateComponents )
		pFnCreateComponents = (UFunction*) UObject::GObjObjects()->Data[ 40053 ];

	USFXOnlineSubsystem_execCreateComponents_Parms CreateComponents_Parms;

	this->ProcessEvent ( pFnCreateComponents, &CreateComponents_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.InitGameProtocolVersion
// [0x00040001] ( FUNC_Final )
// Parameters infos:

void USFXOnlineSubsystem::InitGameProtocolVersion ( )
{
	static UFunction* pFnInitGameProtocolVersion = NULL;

	if ( ! pFnInitGameProtocolVersion )
		pFnInitGameProtocolVersion = (UFunction*) UObject::GObjObjects()->Data[ 40052 ];

	USFXOnlineSubsystem_execInitGameProtocolVersion_Parms InitGameProtocolVersion_Parms;

	this->ProcessEvent ( pFnInitGameProtocolVersion, &InitGameProtocolVersion_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.Init
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineSubsystem::eventInit ( )
{
	static UFunction* pFnInit = NULL;

	if ( ! pFnInit )
		pFnInit = (UFunction*) UObject::GObjObjects()->Data[ 40049 ];

	USFXOnlineSubsystem_eventInit_Parms Init_Parms;

	this->ProcessEvent ( pFnInit, &Init_Parms, NULL );

	return Init_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineSubsystem.GetAchievementList
// [0x00020002] 
// Parameters infos:
// struct TArray<struct FSFXOnlineAchievement> ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct TArray<struct FSFXOnlineAchievement> USFXOnlineSubsystem::GetAchievementList ( )
{
	static UFunction* pFnGetAchievementList = NULL;

	if ( ! pFnGetAchievementList )
		pFnGetAchievementList = (UFunction*) UObject::GObjObjects()->Data[ 40046 ];

	USFXOnlineSubsystem_execGetAchievementList_Parms GetAchievementList_Parms;

	this->ProcessEvent ( pFnGetAchievementList, &GetAchievementList_Parms, NULL );

	return GetAchievementList_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPC.GetTitleAchievementID
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            Index                          ( CPF_Parm )
// int                            SetIndex                       ( CPF_Parm | CPF_OutParm )

int USFXOnlineComponentAchievementPC::GetTitleAchievementID ( int Index, int* SetIndex )
{
	static UFunction* pFnGetTitleAchievementID = NULL;

	if ( ! pFnGetTitleAchievementID )
		pFnGetTitleAchievementID = (UFunction*) UObject::GObjObjects()->Data[ 38664 ];

	USFXOnlineComponentAchievementPC_execGetTitleAchievementID_Parms GetTitleAchievementID_Parms;
	GetTitleAchievementID_Parms.Index = Index;

	pFnGetTitleAchievementID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetTitleAchievementID, &GetTitleAchievementID_Parms, NULL );

	pFnGetTitleAchievementID->FunctionFlags |= 0x400;

	if ( SetIndex )
		*SetIndex = GetTitleAchievementID_Parms.SetIndex;

	return GetTitleAchievementID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPC.GetPlatformAchievementID
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            Index                          ( CPF_Parm )
// int                            SetIndex                       ( CPF_Parm | CPF_OutParm )

int USFXOnlineComponentAchievementPC::GetPlatformAchievementID ( int Index, int* SetIndex )
{
	static UFunction* pFnGetPlatformAchievementID = NULL;

	if ( ! pFnGetPlatformAchievementID )
		pFnGetPlatformAchievementID = (UFunction*) UObject::GObjObjects()->Data[ 38660 ];

	USFXOnlineComponentAchievementPC_execGetPlatformAchievementID_Parms GetPlatformAchievementID_Parms;
	GetPlatformAchievementID_Parms.Index = Index;

	pFnGetPlatformAchievementID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetPlatformAchievementID, &GetPlatformAchievementID_Parms, NULL );

	pFnGetPlatformAchievementID->FunctionFlags |= 0x400;

	if ( SetIndex )
		*SetIndex = GetPlatformAchievementID_Parms.SetIndex;

	return GetPlatformAchievementID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPC.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentAchievementPC::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 38658 ];

	USFXOnlineComponentAchievementPC_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPC.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentAchievementPC::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 38657 ];

	USFXOnlineComponentAchievementPC_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPC.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentAchievementPC::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 38655 ];

	USFXOnlineComponentAchievementPC_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPC.IsGranted
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

bool USFXOnlineComponentAchievementPC::IsGranted ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnIsGranted = NULL;

	if ( ! pFnIsGranted )
		pFnIsGranted = (UFunction*) UObject::GObjObjects()->Data[ 38651 ];

	USFXOnlineComponentAchievementPC_execIsGranted_Parms IsGranted_Parms;
	IsGranted_Parms.LocalUserNum = LocalUserNum;
	IsGranted_Parms.AchievementId = AchievementId;

	pFnIsGranted->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsGranted, &IsGranted_Parms, NULL );

	pFnIsGranted->FunctionFlags |= 0x400;

	return IsGranted_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPC.Grant
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

void USFXOnlineComponentAchievementPC::Grant ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnGrant = NULL;

	if ( ! pFnGrant )
		pFnGrant = (UFunction*) UObject::GObjObjects()->Data[ 38648 ];

	USFXOnlineComponentAchievementPC_execGrant_Parms Grant_Parms;
	Grant_Parms.LocalUserNum = LocalUserNum;
	Grant_Parms.AchievementId = AchievementId;

	pFnGrant->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGrant, &Grant_Parms, NULL );

	pFnGrant->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.GetRebootUserData
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineComponentPlatformPC::GetRebootUserData ( )
{
	static UFunction* pFnGetRebootUserData = NULL;

	if ( ! pFnGetRebootUserData )
		pFnGetRebootUserData = (UFunction*) UObject::GObjObjects()->Data[ 39095 ];

	USFXOnlineComponentPlatformPC_execGetRebootUserData_Parms GetRebootUserData_Parms;

	pFnGetRebootUserData->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetRebootUserData, &GetRebootUserData_Parms, NULL );

	pFnGetRebootUserData->FunctionFlags |= 0x400;

	return GetRebootUserData_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.WasRebootedFromOSCodeRedemptionUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentPlatformPC::WasRebootedFromOSCodeRedemptionUI ( )
{
	static UFunction* pFnWasRebootedFromOSCodeRedemptionUI = NULL;

	if ( ! pFnWasRebootedFromOSCodeRedemptionUI )
		pFnWasRebootedFromOSCodeRedemptionUI = (UFunction*) UObject::GObjObjects()->Data[ 39093 ];

	USFXOnlineComponentPlatformPC_execWasRebootedFromOSCodeRedemptionUI_Parms WasRebootedFromOSCodeRedemptionUI_Parms;

	pFnWasRebootedFromOSCodeRedemptionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWasRebootedFromOSCodeRedemptionUI, &WasRebootedFromOSCodeRedemptionUI_Parms, NULL );

	pFnWasRebootedFromOSCodeRedemptionUI->FunctionFlags |= 0x400;

	return WasRebootedFromOSCodeRedemptionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.ShowCodeRedemptionUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            UserData                       ( CPF_Parm )

bool USFXOnlineComponentPlatformPC::ShowCodeRedemptionUI ( int UserData )
{
	static UFunction* pFnShowCodeRedemptionUI = NULL;

	if ( ! pFnShowCodeRedemptionUI )
		pFnShowCodeRedemptionUI = (UFunction*) UObject::GObjObjects()->Data[ 39090 ];

	USFXOnlineComponentPlatformPC_execShowCodeRedemptionUI_Parms ShowCodeRedemptionUI_Parms;
	ShowCodeRedemptionUI_Parms.UserData = UserData;

	pFnShowCodeRedemptionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowCodeRedemptionUI, &ShowCodeRedemptionUI_Parms, NULL );

	pFnShowCodeRedemptionUI->FunctionFlags |= 0x400;

	return ShowCodeRedemptionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.ShowStoreUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentPlatformPC::ShowStoreUI ( )
{
	static UFunction* pFnShowStoreUI = NULL;

	if ( ! pFnShowStoreUI )
		pFnShowStoreUI = (UFunction*) UObject::GObjObjects()->Data[ 39088 ];

	USFXOnlineComponentPlatformPC_execShowStoreUI_Parms ShowStoreUI_Parms;

	pFnShowStoreUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowStoreUI, &ShowStoreUI_Parms, NULL );

	pFnShowStoreUI->FunctionFlags |= 0x400;

	return ShowStoreUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.GetOnlineXuid
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm | CPF_OutParm )

bool USFXOnlineComponentPlatformPC::GetOnlineXuid ( int nUserIndex, struct FUniqueNetId* oPlayerXuid )
{
	static UFunction* pFnGetOnlineXuid = NULL;

	if ( ! pFnGetOnlineXuid )
		pFnGetOnlineXuid = (UFunction*) UObject::GObjObjects()->Data[ 39084 ];

	USFXOnlineComponentPlatformPC_execGetOnlineXuid_Parms GetOnlineXuid_Parms;
	GetOnlineXuid_Parms.nUserIndex = nUserIndex;

	pFnGetOnlineXuid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOnlineXuid, &GetOnlineXuid_Parms, NULL );

	pFnGetOnlineXuid->FunctionFlags |= 0x400;

	if ( oPlayerXuid )
		memcpy ( oPlayerXuid, &GetOnlineXuid_Parms.oPlayerXuid, 0x8 );

	return GetOnlineXuid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.GetOfflineXuid
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm | CPF_OutParm )

bool USFXOnlineComponentPlatformPC::GetOfflineXuid ( int nUserIndex, struct FUniqueNetId* oPlayerXuid )
{
	static UFunction* pFnGetOfflineXuid = NULL;

	if ( ! pFnGetOfflineXuid )
		pFnGetOfflineXuid = (UFunction*) UObject::GObjObjects()->Data[ 39080 ];

	USFXOnlineComponentPlatformPC_execGetOfflineXuid_Parms GetOfflineXuid_Parms;
	GetOfflineXuid_Parms.nUserIndex = nUserIndex;

	pFnGetOfflineXuid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOfflineXuid, &GetOfflineXuid_Parms, NULL );

	pFnGetOfflineXuid->FunctionFlags |= 0x400;

	if ( oPlayerXuid )
		memcpy ( oPlayerXuid, &GetOfflineXuid_Parms.oPlayerXuid, 0x8 );

	return GetOfflineXuid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.ShowKeyboardUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 sTitleText                     ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sDescriptionText               ( CPF_Parm | CPF_NeedCtorLink )
// unsigned char                  nKeyboardType                  ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldValidate                ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bRouteThroughConsole           ( CPF_OptionalParm | CPF_Parm )
// struct FString                 sDefaultText                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
// int                            nMaxResultLength               ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentPlatformPC::ShowKeyboardUI ( unsigned char LocalUserNum, struct FString sTitleText, struct FString sDescriptionText, unsigned char nKeyboardType, unsigned long bShouldValidate, unsigned long bRouteThroughConsole, struct FString sDefaultText, int nMaxResultLength )
{
	static UFunction* pFnShowKeyboardUI = NULL;

	if ( ! pFnShowKeyboardUI )
		pFnShowKeyboardUI = (UFunction*) UObject::GObjObjects()->Data[ 39070 ];

	USFXOnlineComponentPlatformPC_execShowKeyboardUI_Parms ShowKeyboardUI_Parms;
	ShowKeyboardUI_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ShowKeyboardUI_Parms.sTitleText, &sTitleText, 0x10 );
	memcpy ( &ShowKeyboardUI_Parms.sDescriptionText, &sDescriptionText, 0x10 );
	ShowKeyboardUI_Parms.nKeyboardType = nKeyboardType;
	ShowKeyboardUI_Parms.bShouldValidate = bShouldValidate;
	ShowKeyboardUI_Parms.bRouteThroughConsole = bRouteThroughConsole;
	memcpy ( &ShowKeyboardUI_Parms.sDefaultText, &sDefaultText, 0x10 );
	ShowKeyboardUI_Parms.nMaxResultLength = nMaxResultLength;

	pFnShowKeyboardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowKeyboardUI, &ShowKeyboardUI_Parms, NULL );

	pFnShowKeyboardUI->FunctionFlags |= 0x400;

	return ShowKeyboardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.ShowFriendsInviteUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm )

bool USFXOnlineComponentPlatformPC::ShowFriendsInviteUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerXuid )
{
	static UFunction* pFnShowFriendsInviteUI = NULL;

	if ( ! pFnShowFriendsInviteUI )
		pFnShowFriendsInviteUI = (UFunction*) UObject::GObjObjects()->Data[ 39066 ];

	USFXOnlineComponentPlatformPC_execShowFriendsInviteUI_Parms ShowFriendsInviteUI_Parms;
	ShowFriendsInviteUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowFriendsInviteUI_Parms.oPlayerXuid, &oPlayerXuid, 0x8 );

	pFnShowFriendsInviteUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFriendsInviteUI, &ShowFriendsInviteUI_Parms, NULL );

	pFnShowFriendsInviteUI->FunctionFlags |= 0x400;

	return ShowFriendsInviteUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.ShowFriendsUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

bool USFXOnlineComponentPlatformPC::ShowFriendsUI ( unsigned char eLocalUserNum )
{
	static UFunction* pFnShowFriendsUI = NULL;

	if ( ! pFnShowFriendsUI )
		pFnShowFriendsUI = (UFunction*) UObject::GObjObjects()->Data[ 39063 ];

	USFXOnlineComponentPlatformPC_execShowFriendsUI_Parms ShowFriendsUI_Parms;
	ShowFriendsUI_Parms.eLocalUserNum = eLocalUserNum;

	pFnShowFriendsUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFriendsUI, &ShowFriendsUI_Parms, NULL );

	pFnShowFriendsUI->FunctionFlags |= 0x400;

	return ShowFriendsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.ShowAchievementsUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

bool USFXOnlineComponentPlatformPC::ShowAchievementsUI ( unsigned char byLocalUserNum )
{
	static UFunction* pFnShowAchievementsUI = NULL;

	if ( ! pFnShowAchievementsUI )
		pFnShowAchievementsUI = (UFunction*) UObject::GObjObjects()->Data[ 39060 ];

	USFXOnlineComponentPlatformPC_execShowAchievementsUI_Parms ShowAchievementsUI_Parms;
	ShowAchievementsUI_Parms.byLocalUserNum = byLocalUserNum;

	pFnShowAchievementsUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowAchievementsUI, &ShowAchievementsUI_Parms, NULL );

	pFnShowAchievementsUI->FunctionFlags |= 0x400;

	return ShowAchievementsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.ShowFeedbackUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )

bool USFXOnlineComponentPlatformPC::ShowFeedbackUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerId )
{
	static UFunction* pFnShowFeedbackUI = NULL;

	if ( ! pFnShowFeedbackUI )
		pFnShowFeedbackUI = (UFunction*) UObject::GObjObjects()->Data[ 39056 ];

	USFXOnlineComponentPlatformPC_execShowFeedbackUI_Parms ShowFeedbackUI_Parms;
	ShowFeedbackUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowFeedbackUI_Parms.oPlayerId, &oPlayerId, 0x8 );

	pFnShowFeedbackUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFeedbackUI, &ShowFeedbackUI_Parms, NULL );

	pFnShowFeedbackUI->FunctionFlags |= 0x400;

	return ShowFeedbackUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.ShowGamerCardUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )

bool USFXOnlineComponentPlatformPC::ShowGamerCardUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerId )
{
	static UFunction* pFnShowGamerCardUI = NULL;

	if ( ! pFnShowGamerCardUI )
		pFnShowGamerCardUI = (UFunction*) UObject::GObjObjects()->Data[ 39052 ];

	USFXOnlineComponentPlatformPC_execShowGamerCardUI_Parms ShowGamerCardUI_Parms;
	ShowGamerCardUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowGamerCardUI_Parms.oPlayerId, &oPlayerId, 0x8 );

	pFnShowGamerCardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowGamerCardUI, &ShowGamerCardUI_Parms, NULL );

	pFnShowGamerCardUI->FunctionFlags |= 0x400;

	return ShowGamerCardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.CanShowPresenceInformation
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPC::CanShowPresenceInformation ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanShowPresenceInformation = NULL;

	if ( ! pFnCanShowPresenceInformation )
		pFnCanShowPresenceInformation = (UFunction*) UObject::GObjObjects()->Data[ 39049 ];

	USFXOnlineComponentPlatformPC_execCanShowPresenceInformation_Parms CanShowPresenceInformation_Parms;
	CanShowPresenceInformation_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanShowPresenceInformation->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanShowPresenceInformation, &CanShowPresenceInformation_Parms, NULL );

	pFnCanShowPresenceInformation->FunctionFlags |= 0x400;

	return CanShowPresenceInformation_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.CanViewPlayerProfiles
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPC::CanViewPlayerProfiles ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanViewPlayerProfiles = NULL;

	if ( ! pFnCanViewPlayerProfiles )
		pFnCanViewPlayerProfiles = (UFunction*) UObject::GObjObjects()->Data[ 39046 ];

	USFXOnlineComponentPlatformPC_execCanViewPlayerProfiles_Parms CanViewPlayerProfiles_Parms;
	CanViewPlayerProfiles_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanViewPlayerProfiles->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanViewPlayerProfiles, &CanViewPlayerProfiles_Parms, NULL );

	pFnCanViewPlayerProfiles->FunctionFlags |= 0x400;

	return CanViewPlayerProfiles_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.CanPurchaseContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPC::CanPurchaseContent ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanPurchaseContent = NULL;

	if ( ! pFnCanPurchaseContent )
		pFnCanPurchaseContent = (UFunction*) UObject::GObjObjects()->Data[ 39043 ];

	USFXOnlineComponentPlatformPC_execCanPurchaseContent_Parms CanPurchaseContent_Parms;
	CanPurchaseContent_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanPurchaseContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPurchaseContent, &CanPurchaseContent_Parms, NULL );

	pFnCanPurchaseContent->FunctionFlags |= 0x400;

	return CanPurchaseContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.CanDownloadUserContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPC::CanDownloadUserContent ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanDownloadUserContent = NULL;

	if ( ! pFnCanDownloadUserContent )
		pFnCanDownloadUserContent = (UFunction*) UObject::GObjObjects()->Data[ 39040 ];

	USFXOnlineComponentPlatformPC_execCanDownloadUserContent_Parms CanDownloadUserContent_Parms;
	CanDownloadUserContent_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanDownloadUserContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanDownloadUserContent, &CanDownloadUserContent_Parms, NULL );

	pFnCanDownloadUserContent->FunctionFlags |= 0x400;

	return CanDownloadUserContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.CanCommunicate
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPC::CanCommunicate ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanCommunicate = NULL;

	if ( ! pFnCanCommunicate )
		pFnCanCommunicate = (UFunction*) UObject::GObjObjects()->Data[ 39037 ];

	USFXOnlineComponentPlatformPC_execCanCommunicate_Parms CanCommunicate_Parms;
	CanCommunicate_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanCommunicate->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanCommunicate, &CanCommunicate_Parms, NULL );

	pFnCanCommunicate->FunctionFlags |= 0x400;

	return CanCommunicate_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.CanPlayOnline
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPC::CanPlayOnline ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanPlayOnline = NULL;

	if ( ! pFnCanPlayOnline )
		pFnCanPlayOnline = (UFunction*) UObject::GObjObjects()->Data[ 39034 ];

	USFXOnlineComponentPlatformPC_execCanPlayOnline_Parms CanPlayOnline_Parms;
	CanPlayOnline_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanPlayOnline->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPlayOnline, &CanPlayOnline_Parms, NULL );

	pFnCanPlayOnline->FunctionFlags |= 0x400;

	return CanPlayOnline_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.SetRichPresence
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// int                            nPresenceMode                  ( CPF_Parm )
// struct TArray<struct FLocalizedStringSetting> aLocalizedStringSettings       ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
// struct TArray<struct FSettingsProperty> aProperties                    ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void USFXOnlineComponentPlatformPC::SetRichPresence ( unsigned char eLocalUserNum, int nPresenceMode, struct TArray<struct FLocalizedStringSetting>* aLocalizedStringSettings, struct TArray<struct FSettingsProperty>* aProperties )
{
	static UFunction* pFnSetRichPresence = NULL;

	if ( ! pFnSetRichPresence )
		pFnSetRichPresence = (UFunction*) UObject::GObjObjects()->Data[ 39027 ];

	USFXOnlineComponentPlatformPC_execSetRichPresence_Parms SetRichPresence_Parms;
	SetRichPresence_Parms.eLocalUserNum = eLocalUserNum;
	SetRichPresence_Parms.nPresenceMode = nPresenceMode;

	pFnSetRichPresence->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetRichPresence, &SetRichPresence_Parms, NULL );

	pFnSetRichPresence->FunctionFlags |= 0x400;

	if ( aLocalizedStringSettings )
		memcpy ( aLocalizedStringSettings, &SetRichPresence_Parms.aLocalizedStringSettings, 0x10 );

	if ( aProperties )
		memcpy ( aProperties, &SetRichPresence_Parms.aProperties, 0x10 );
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.ShowLoginUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned long                  bShowOnlineOnly                ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentPlatformPC::ShowLoginUI ( unsigned long bShowOnlineOnly )
{
	static UFunction* pFnShowLoginUI = NULL;

	if ( ! pFnShowLoginUI )
		pFnShowLoginUI = (UFunction*) UObject::GObjObjects()->Data[ 39024 ];

	USFXOnlineComponentPlatformPC_execShowLoginUI_Parms ShowLoginUI_Parms;
	ShowLoginUI_Parms.bShowOnlineOnly = bShowOnlineOnly;

	pFnShowLoginUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowLoginUI, &ShowLoginUI_Parms, NULL );

	pFnShowLoginUI->FunctionFlags |= 0x400;

	return ShowLoginUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.GetLoginStatus
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPC::GetLoginStatus ( unsigned char eLocalUserNum )
{
	static UFunction* pFnGetLoginStatus = NULL;

	if ( ! pFnGetLoginStatus )
		pFnGetLoginStatus = (UFunction*) UObject::GObjObjects()->Data[ 39021 ];

	USFXOnlineComponentPlatformPC_execGetLoginStatus_Parms GetLoginStatus_Parms;
	GetLoginStatus_Parms.eLocalUserNum = eLocalUserNum;

	pFnGetLoginStatus->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetLoginStatus, &GetLoginStatus_Parms, NULL );

	pFnGetLoginStatus->FunctionFlags |= 0x400;

	return GetLoginStatus_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.AddRecentPlayer
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )
// struct FString                 sDescription                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentPlatformPC::AddRecentPlayer ( struct FUniqueNetId oPlayerId, struct FString sDescription )
{
	static UFunction* pFnAddRecentPlayer = NULL;

	if ( ! pFnAddRecentPlayer )
		pFnAddRecentPlayer = (UFunction*) UObject::GObjObjects()->Data[ 39017 ];

	USFXOnlineComponentPlatformPC_execAddRecentPlayer_Parms AddRecentPlayer_Parms;
	memcpy ( &AddRecentPlayer_Parms.oPlayerId, &oPlayerId, 0x8 );
	memcpy ( &AddRecentPlayer_Parms.sDescription, &sDescription, 0x10 );

	pFnAddRecentPlayer->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnAddRecentPlayer, &AddRecentPlayer_Parms, NULL );

	pFnAddRecentPlayer->FunctionFlags |= 0x400;

	return AddRecentPlayer_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentPlatformPC::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 39015 ];

	USFXOnlineComponentPlatformPC_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentPlatformPC::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 39014 ];

	USFXOnlineComponentPlatformPC_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPC.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentPlatformPC::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 39012 ];

	USFXOnlineComponentPlatformPC_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementXenon.GetTitleAchievementID
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            Index                          ( CPF_Parm )
// int                            SetIndex                       ( CPF_Parm | CPF_OutParm )

int USFXOnlineComponentAchievementXenon::GetTitleAchievementID ( int Index, int* SetIndex )
{
	static UFunction* pFnGetTitleAchievementID = NULL;

	if ( ! pFnGetTitleAchievementID )
		pFnGetTitleAchievementID = (UFunction*) UObject::GObjObjects()->Data[ 38708 ];

	USFXOnlineComponentAchievementXenon_execGetTitleAchievementID_Parms GetTitleAchievementID_Parms;
	GetTitleAchievementID_Parms.Index = Index;

	pFnGetTitleAchievementID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetTitleAchievementID, &GetTitleAchievementID_Parms, NULL );

	pFnGetTitleAchievementID->FunctionFlags |= 0x400;

	if ( SetIndex )
		*SetIndex = GetTitleAchievementID_Parms.SetIndex;

	return GetTitleAchievementID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementXenon.GetPlatformAchievementID
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            Index                          ( CPF_Parm )
// int                            SetIndex                       ( CPF_Parm | CPF_OutParm )

int USFXOnlineComponentAchievementXenon::GetPlatformAchievementID ( int Index, int* SetIndex )
{
	static UFunction* pFnGetPlatformAchievementID = NULL;

	if ( ! pFnGetPlatformAchievementID )
		pFnGetPlatformAchievementID = (UFunction*) UObject::GObjObjects()->Data[ 38704 ];

	USFXOnlineComponentAchievementXenon_execGetPlatformAchievementID_Parms GetPlatformAchievementID_Parms;
	GetPlatformAchievementID_Parms.Index = Index;

	pFnGetPlatformAchievementID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetPlatformAchievementID, &GetPlatformAchievementID_Parms, NULL );

	pFnGetPlatformAchievementID->FunctionFlags |= 0x400;

	if ( SetIndex )
		*SetIndex = GetPlatformAchievementID_Parms.SetIndex;

	return GetPlatformAchievementID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementXenon.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentAchievementXenon::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 38702 ];

	USFXOnlineComponentAchievementXenon_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementXenon.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentAchievementXenon::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 38701 ];

	USFXOnlineComponentAchievementXenon_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementXenon.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentAchievementXenon::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 38699 ];

	USFXOnlineComponentAchievementXenon_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementXenon.IsGranted
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

bool USFXOnlineComponentAchievementXenon::IsGranted ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnIsGranted = NULL;

	if ( ! pFnIsGranted )
		pFnIsGranted = (UFunction*) UObject::GObjObjects()->Data[ 38695 ];

	USFXOnlineComponentAchievementXenon_execIsGranted_Parms IsGranted_Parms;
	IsGranted_Parms.LocalUserNum = LocalUserNum;
	IsGranted_Parms.AchievementId = AchievementId;

	pFnIsGranted->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsGranted, &IsGranted_Parms, NULL );

	pFnIsGranted->FunctionFlags |= 0x400;

	return IsGranted_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementXenon.Grant
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

void USFXOnlineComponentAchievementXenon::Grant ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnGrant = NULL;

	if ( ! pFnGrant )
		pFnGrant = (UFunction*) UObject::GObjObjects()->Data[ 38692 ];

	USFXOnlineComponentAchievementXenon_execGrant_Parms Grant_Parms;
	Grant_Parms.LocalUserNum = LocalUserNum;
	Grant_Parms.AchievementId = AchievementId;

	pFnGrant->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGrant, &Grant_Parms, NULL );

	pFnGrant->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.GetRebootUserData
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineComponentPlatformXenon::GetRebootUserData ( )
{
	static UFunction* pFnGetRebootUserData = NULL;

	if ( ! pFnGetRebootUserData )
		pFnGetRebootUserData = (UFunction*) UObject::GObjObjects()->Data[ 39302 ];

	USFXOnlineComponentPlatformXenon_execGetRebootUserData_Parms GetRebootUserData_Parms;

	pFnGetRebootUserData->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetRebootUserData, &GetRebootUserData_Parms, NULL );

	pFnGetRebootUserData->FunctionFlags |= 0x400;

	return GetRebootUserData_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.WasRebootedFromOSCodeRedemptionUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentPlatformXenon::WasRebootedFromOSCodeRedemptionUI ( )
{
	static UFunction* pFnWasRebootedFromOSCodeRedemptionUI = NULL;

	if ( ! pFnWasRebootedFromOSCodeRedemptionUI )
		pFnWasRebootedFromOSCodeRedemptionUI = (UFunction*) UObject::GObjObjects()->Data[ 39300 ];

	USFXOnlineComponentPlatformXenon_execWasRebootedFromOSCodeRedemptionUI_Parms WasRebootedFromOSCodeRedemptionUI_Parms;

	pFnWasRebootedFromOSCodeRedemptionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWasRebootedFromOSCodeRedemptionUI, &WasRebootedFromOSCodeRedemptionUI_Parms, NULL );

	pFnWasRebootedFromOSCodeRedemptionUI->FunctionFlags |= 0x400;

	return WasRebootedFromOSCodeRedemptionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.ShowCodeRedemptionUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            UserData                       ( CPF_Parm )

bool USFXOnlineComponentPlatformXenon::ShowCodeRedemptionUI ( int UserData )
{
	static UFunction* pFnShowCodeRedemptionUI = NULL;

	if ( ! pFnShowCodeRedemptionUI )
		pFnShowCodeRedemptionUI = (UFunction*) UObject::GObjObjects()->Data[ 39297 ];

	USFXOnlineComponentPlatformXenon_execShowCodeRedemptionUI_Parms ShowCodeRedemptionUI_Parms;
	ShowCodeRedemptionUI_Parms.UserData = UserData;

	pFnShowCodeRedemptionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowCodeRedemptionUI, &ShowCodeRedemptionUI_Parms, NULL );

	pFnShowCodeRedemptionUI->FunctionFlags |= 0x400;

	return ShowCodeRedemptionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.ShowStoreUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentPlatformXenon::ShowStoreUI ( )
{
	static UFunction* pFnShowStoreUI = NULL;

	if ( ! pFnShowStoreUI )
		pFnShowStoreUI = (UFunction*) UObject::GObjObjects()->Data[ 39295 ];

	USFXOnlineComponentPlatformXenon_execShowStoreUI_Parms ShowStoreUI_Parms;

	pFnShowStoreUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowStoreUI, &ShowStoreUI_Parms, NULL );

	pFnShowStoreUI->FunctionFlags |= 0x400;

	return ShowStoreUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.GetOnlineXuid
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm | CPF_OutParm )

bool USFXOnlineComponentPlatformXenon::GetOnlineXuid ( int nUserIndex, struct FUniqueNetId* oPlayerXuid )
{
	static UFunction* pFnGetOnlineXuid = NULL;

	if ( ! pFnGetOnlineXuid )
		pFnGetOnlineXuid = (UFunction*) UObject::GObjObjects()->Data[ 39291 ];

	USFXOnlineComponentPlatformXenon_execGetOnlineXuid_Parms GetOnlineXuid_Parms;
	GetOnlineXuid_Parms.nUserIndex = nUserIndex;

	pFnGetOnlineXuid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOnlineXuid, &GetOnlineXuid_Parms, NULL );

	pFnGetOnlineXuid->FunctionFlags |= 0x400;

	if ( oPlayerXuid )
		memcpy ( oPlayerXuid, &GetOnlineXuid_Parms.oPlayerXuid, 0x8 );

	return GetOnlineXuid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.GetOfflineXuid
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm | CPF_OutParm )

bool USFXOnlineComponentPlatformXenon::GetOfflineXuid ( int nUserIndex, struct FUniqueNetId* oPlayerXuid )
{
	static UFunction* pFnGetOfflineXuid = NULL;

	if ( ! pFnGetOfflineXuid )
		pFnGetOfflineXuid = (UFunction*) UObject::GObjObjects()->Data[ 39287 ];

	USFXOnlineComponentPlatformXenon_execGetOfflineXuid_Parms GetOfflineXuid_Parms;
	GetOfflineXuid_Parms.nUserIndex = nUserIndex;

	pFnGetOfflineXuid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOfflineXuid, &GetOfflineXuid_Parms, NULL );

	pFnGetOfflineXuid->FunctionFlags |= 0x400;

	if ( oPlayerXuid )
		memcpy ( oPlayerXuid, &GetOfflineXuid_Parms.oPlayerXuid, 0x8 );

	return GetOfflineXuid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.ShowKeyboardUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 sTitleText                     ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sDescriptionText               ( CPF_Parm | CPF_NeedCtorLink )
// unsigned char                  nKeyboardType                  ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldValidate                ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bRouteThroughConsole           ( CPF_OptionalParm | CPF_Parm )
// struct FString                 sDefaultText                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
// int                            nMaxResultLength               ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentPlatformXenon::ShowKeyboardUI ( unsigned char LocalUserNum, struct FString sTitleText, struct FString sDescriptionText, unsigned char nKeyboardType, unsigned long bShouldValidate, unsigned long bRouteThroughConsole, struct FString sDefaultText, int nMaxResultLength )
{
	static UFunction* pFnShowKeyboardUI = NULL;

	if ( ! pFnShowKeyboardUI )
		pFnShowKeyboardUI = (UFunction*) UObject::GObjObjects()->Data[ 39277 ];

	USFXOnlineComponentPlatformXenon_execShowKeyboardUI_Parms ShowKeyboardUI_Parms;
	ShowKeyboardUI_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ShowKeyboardUI_Parms.sTitleText, &sTitleText, 0x10 );
	memcpy ( &ShowKeyboardUI_Parms.sDescriptionText, &sDescriptionText, 0x10 );
	ShowKeyboardUI_Parms.nKeyboardType = nKeyboardType;
	ShowKeyboardUI_Parms.bShouldValidate = bShouldValidate;
	ShowKeyboardUI_Parms.bRouteThroughConsole = bRouteThroughConsole;
	memcpy ( &ShowKeyboardUI_Parms.sDefaultText, &sDefaultText, 0x10 );
	ShowKeyboardUI_Parms.nMaxResultLength = nMaxResultLength;

	pFnShowKeyboardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowKeyboardUI, &ShowKeyboardUI_Parms, NULL );

	pFnShowKeyboardUI->FunctionFlags |= 0x400;

	return ShowKeyboardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.ShowFriendsInviteUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm )

bool USFXOnlineComponentPlatformXenon::ShowFriendsInviteUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerXuid )
{
	static UFunction* pFnShowFriendsInviteUI = NULL;

	if ( ! pFnShowFriendsInviteUI )
		pFnShowFriendsInviteUI = (UFunction*) UObject::GObjObjects()->Data[ 39273 ];

	USFXOnlineComponentPlatformXenon_execShowFriendsInviteUI_Parms ShowFriendsInviteUI_Parms;
	ShowFriendsInviteUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowFriendsInviteUI_Parms.oPlayerXuid, &oPlayerXuid, 0x8 );

	pFnShowFriendsInviteUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFriendsInviteUI, &ShowFriendsInviteUI_Parms, NULL );

	pFnShowFriendsInviteUI->FunctionFlags |= 0x400;

	return ShowFriendsInviteUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.ShowFriendsUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

bool USFXOnlineComponentPlatformXenon::ShowFriendsUI ( unsigned char eLocalUserNum )
{
	static UFunction* pFnShowFriendsUI = NULL;

	if ( ! pFnShowFriendsUI )
		pFnShowFriendsUI = (UFunction*) UObject::GObjObjects()->Data[ 39270 ];

	USFXOnlineComponentPlatformXenon_execShowFriendsUI_Parms ShowFriendsUI_Parms;
	ShowFriendsUI_Parms.eLocalUserNum = eLocalUserNum;

	pFnShowFriendsUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFriendsUI, &ShowFriendsUI_Parms, NULL );

	pFnShowFriendsUI->FunctionFlags |= 0x400;

	return ShowFriendsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.ShowAchievementsUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

bool USFXOnlineComponentPlatformXenon::ShowAchievementsUI ( unsigned char byLocalUserNum )
{
	static UFunction* pFnShowAchievementsUI = NULL;

	if ( ! pFnShowAchievementsUI )
		pFnShowAchievementsUI = (UFunction*) UObject::GObjObjects()->Data[ 39267 ];

	USFXOnlineComponentPlatformXenon_execShowAchievementsUI_Parms ShowAchievementsUI_Parms;
	ShowAchievementsUI_Parms.byLocalUserNum = byLocalUserNum;

	pFnShowAchievementsUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowAchievementsUI, &ShowAchievementsUI_Parms, NULL );

	pFnShowAchievementsUI->FunctionFlags |= 0x400;

	return ShowAchievementsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.ShowFeedbackUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm )

bool USFXOnlineComponentPlatformXenon::ShowFeedbackUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerXuid )
{
	static UFunction* pFnShowFeedbackUI = NULL;

	if ( ! pFnShowFeedbackUI )
		pFnShowFeedbackUI = (UFunction*) UObject::GObjObjects()->Data[ 39263 ];

	USFXOnlineComponentPlatformXenon_execShowFeedbackUI_Parms ShowFeedbackUI_Parms;
	ShowFeedbackUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowFeedbackUI_Parms.oPlayerXuid, &oPlayerXuid, 0x8 );

	pFnShowFeedbackUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFeedbackUI, &ShowFeedbackUI_Parms, NULL );

	pFnShowFeedbackUI->FunctionFlags |= 0x400;

	return ShowFeedbackUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.ShowGamerCardUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm )

bool USFXOnlineComponentPlatformXenon::ShowGamerCardUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerXuid )
{
	static UFunction* pFnShowGamerCardUI = NULL;

	if ( ! pFnShowGamerCardUI )
		pFnShowGamerCardUI = (UFunction*) UObject::GObjObjects()->Data[ 39259 ];

	USFXOnlineComponentPlatformXenon_execShowGamerCardUI_Parms ShowGamerCardUI_Parms;
	ShowGamerCardUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowGamerCardUI_Parms.oPlayerXuid, &oPlayerXuid, 0x8 );

	pFnShowGamerCardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowGamerCardUI, &ShowGamerCardUI_Parms, NULL );

	pFnShowGamerCardUI->FunctionFlags |= 0x400;

	return ShowGamerCardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.CanShowPresenceInformation
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformXenon::CanShowPresenceInformation ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanShowPresenceInformation = NULL;

	if ( ! pFnCanShowPresenceInformation )
		pFnCanShowPresenceInformation = (UFunction*) UObject::GObjObjects()->Data[ 39256 ];

	USFXOnlineComponentPlatformXenon_execCanShowPresenceInformation_Parms CanShowPresenceInformation_Parms;
	CanShowPresenceInformation_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanShowPresenceInformation->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanShowPresenceInformation, &CanShowPresenceInformation_Parms, NULL );

	pFnCanShowPresenceInformation->FunctionFlags |= 0x400;

	return CanShowPresenceInformation_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.CanViewPlayerProfiles
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformXenon::CanViewPlayerProfiles ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanViewPlayerProfiles = NULL;

	if ( ! pFnCanViewPlayerProfiles )
		pFnCanViewPlayerProfiles = (UFunction*) UObject::GObjObjects()->Data[ 39253 ];

	USFXOnlineComponentPlatformXenon_execCanViewPlayerProfiles_Parms CanViewPlayerProfiles_Parms;
	CanViewPlayerProfiles_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanViewPlayerProfiles->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanViewPlayerProfiles, &CanViewPlayerProfiles_Parms, NULL );

	pFnCanViewPlayerProfiles->FunctionFlags |= 0x400;

	return CanViewPlayerProfiles_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.CanPurchaseContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformXenon::CanPurchaseContent ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanPurchaseContent = NULL;

	if ( ! pFnCanPurchaseContent )
		pFnCanPurchaseContent = (UFunction*) UObject::GObjObjects()->Data[ 39250 ];

	USFXOnlineComponentPlatformXenon_execCanPurchaseContent_Parms CanPurchaseContent_Parms;
	CanPurchaseContent_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanPurchaseContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPurchaseContent, &CanPurchaseContent_Parms, NULL );

	pFnCanPurchaseContent->FunctionFlags |= 0x400;

	return CanPurchaseContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.CanDownloadUserContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformXenon::CanDownloadUserContent ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanDownloadUserContent = NULL;

	if ( ! pFnCanDownloadUserContent )
		pFnCanDownloadUserContent = (UFunction*) UObject::GObjObjects()->Data[ 39247 ];

	USFXOnlineComponentPlatformXenon_execCanDownloadUserContent_Parms CanDownloadUserContent_Parms;
	CanDownloadUserContent_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanDownloadUserContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanDownloadUserContent, &CanDownloadUserContent_Parms, NULL );

	pFnCanDownloadUserContent->FunctionFlags |= 0x400;

	return CanDownloadUserContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.CanCommunicate
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformXenon::CanCommunicate ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanCommunicate = NULL;

	if ( ! pFnCanCommunicate )
		pFnCanCommunicate = (UFunction*) UObject::GObjObjects()->Data[ 39244 ];

	USFXOnlineComponentPlatformXenon_execCanCommunicate_Parms CanCommunicate_Parms;
	CanCommunicate_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanCommunicate->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanCommunicate, &CanCommunicate_Parms, NULL );

	pFnCanCommunicate->FunctionFlags |= 0x400;

	return CanCommunicate_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.CanPlayOnline
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformXenon::CanPlayOnline ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanPlayOnline = NULL;

	if ( ! pFnCanPlayOnline )
		pFnCanPlayOnline = (UFunction*) UObject::GObjObjects()->Data[ 39241 ];

	USFXOnlineComponentPlatformXenon_execCanPlayOnline_Parms CanPlayOnline_Parms;
	CanPlayOnline_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanPlayOnline->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPlayOnline, &CanPlayOnline_Parms, NULL );

	pFnCanPlayOnline->FunctionFlags |= 0x400;

	return CanPlayOnline_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.SetRichPresence
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// int                            nPresenceMode                  ( CPF_Parm )
// struct TArray<struct FLocalizedStringSetting> aLocalizedStringSettings       ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
// struct TArray<struct FSettingsProperty> aProperties                    ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void USFXOnlineComponentPlatformXenon::SetRichPresence ( unsigned char eLocalUserNum, int nPresenceMode, struct TArray<struct FLocalizedStringSetting>* aLocalizedStringSettings, struct TArray<struct FSettingsProperty>* aProperties )
{
	static UFunction* pFnSetRichPresence = NULL;

	if ( ! pFnSetRichPresence )
		pFnSetRichPresence = (UFunction*) UObject::GObjObjects()->Data[ 39234 ];

	USFXOnlineComponentPlatformXenon_execSetRichPresence_Parms SetRichPresence_Parms;
	SetRichPresence_Parms.eLocalUserNum = eLocalUserNum;
	SetRichPresence_Parms.nPresenceMode = nPresenceMode;

	pFnSetRichPresence->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetRichPresence, &SetRichPresence_Parms, NULL );

	pFnSetRichPresence->FunctionFlags |= 0x400;

	if ( aLocalizedStringSettings )
		memcpy ( aLocalizedStringSettings, &SetRichPresence_Parms.aLocalizedStringSettings, 0x10 );

	if ( aProperties )
		memcpy ( aProperties, &SetRichPresence_Parms.aProperties, 0x10 );
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.ShowLoginUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned long                  bShowOnlineOnly                ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentPlatformXenon::ShowLoginUI ( unsigned long bShowOnlineOnly )
{
	static UFunction* pFnShowLoginUI = NULL;

	if ( ! pFnShowLoginUI )
		pFnShowLoginUI = (UFunction*) UObject::GObjObjects()->Data[ 39231 ];

	USFXOnlineComponentPlatformXenon_execShowLoginUI_Parms ShowLoginUI_Parms;
	ShowLoginUI_Parms.bShowOnlineOnly = bShowOnlineOnly;

	pFnShowLoginUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowLoginUI, &ShowLoginUI_Parms, NULL );

	pFnShowLoginUI->FunctionFlags |= 0x400;

	return ShowLoginUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.GetLoginStatus
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformXenon::GetLoginStatus ( unsigned char eLocalUserNum )
{
	static UFunction* pFnGetLoginStatus = NULL;

	if ( ! pFnGetLoginStatus )
		pFnGetLoginStatus = (UFunction*) UObject::GObjObjects()->Data[ 39228 ];

	USFXOnlineComponentPlatformXenon_execGetLoginStatus_Parms GetLoginStatus_Parms;
	GetLoginStatus_Parms.eLocalUserNum = eLocalUserNum;

	pFnGetLoginStatus->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetLoginStatus, &GetLoginStatus_Parms, NULL );

	pFnGetLoginStatus->FunctionFlags |= 0x400;

	return GetLoginStatus_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.TickAsyncTasks
// [0x00040401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void USFXOnlineComponentPlatformXenon::TickAsyncTasks ( )
{
	static UFunction* pFnTickAsyncTasks = NULL;

	if ( ! pFnTickAsyncTasks )
		pFnTickAsyncTasks = (UFunction*) UObject::GObjObjects()->Data[ 39227 ];

	USFXOnlineComponentPlatformXenon_execTickAsyncTasks_Parms TickAsyncTasks_Parms;

	pFnTickAsyncTasks->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnTickAsyncTasks, &TickAsyncTasks_Parms, NULL );

	pFnTickAsyncTasks->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.OnTick
// [0x00040401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineComponentPlatformXenon::OnTick ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnOnTick = NULL;

	if ( ! pFnOnTick )
		pFnOnTick = (UFunction*) UObject::GObjObjects()->Data[ 39225 ];

	USFXOnlineComponentPlatformXenon_execOnTick_Parms OnTick_Parms;
	OnTick_Parms.oEvent = oEvent;

	pFnOnTick->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnTick, &OnTick_Parms, NULL );

	pFnOnTick->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.AddRecentPlayer
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )
// struct FString                 sDescription                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentPlatformXenon::AddRecentPlayer ( struct FUniqueNetId oPlayerId, struct FString sDescription )
{
	static UFunction* pFnAddRecentPlayer = NULL;

	if ( ! pFnAddRecentPlayer )
		pFnAddRecentPlayer = (UFunction*) UObject::GObjObjects()->Data[ 39221 ];

	USFXOnlineComponentPlatformXenon_execAddRecentPlayer_Parms AddRecentPlayer_Parms;
	memcpy ( &AddRecentPlayer_Parms.oPlayerId, &oPlayerId, 0x8 );
	memcpy ( &AddRecentPlayer_Parms.sDescription, &sDescription, 0x10 );

	pFnAddRecentPlayer->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnAddRecentPlayer, &AddRecentPlayer_Parms, NULL );

	pFnAddRecentPlayer->FunctionFlags |= 0x400;

	return AddRecentPlayer_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentPlatformXenon::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 39219 ];

	USFXOnlineComponentPlatformXenon_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentPlatformXenon::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 39218 ];

	USFXOnlineComponentPlatformXenon_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformXenon.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentPlatformXenon::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 39216 ];

	USFXOnlineComponentPlatformXenon_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPS3.GetTitleAchievementID
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            Index                          ( CPF_Parm )
// int                            SetIndex                       ( CPF_Parm | CPF_OutParm )

int USFXOnlineComponentAchievementPS3::GetTitleAchievementID ( int Index, int* SetIndex )
{
	static UFunction* pFnGetTitleAchievementID = NULL;

	if ( ! pFnGetTitleAchievementID )
		pFnGetTitleAchievementID = (UFunction*) UObject::GObjObjects()->Data[ 38687 ];

	USFXOnlineComponentAchievementPS3_execGetTitleAchievementID_Parms GetTitleAchievementID_Parms;
	GetTitleAchievementID_Parms.Index = Index;

	pFnGetTitleAchievementID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetTitleAchievementID, &GetTitleAchievementID_Parms, NULL );

	pFnGetTitleAchievementID->FunctionFlags |= 0x400;

	if ( SetIndex )
		*SetIndex = GetTitleAchievementID_Parms.SetIndex;

	return GetTitleAchievementID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPS3.GetPlatformAchievementID
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            Index                          ( CPF_Parm )
// int                            SetIndex                       ( CPF_Parm | CPF_OutParm )

int USFXOnlineComponentAchievementPS3::GetPlatformAchievementID ( int Index, int* SetIndex )
{
	static UFunction* pFnGetPlatformAchievementID = NULL;

	if ( ! pFnGetPlatformAchievementID )
		pFnGetPlatformAchievementID = (UFunction*) UObject::GObjObjects()->Data[ 38683 ];

	USFXOnlineComponentAchievementPS3_execGetPlatformAchievementID_Parms GetPlatformAchievementID_Parms;
	GetPlatformAchievementID_Parms.Index = Index;

	pFnGetPlatformAchievementID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetPlatformAchievementID, &GetPlatformAchievementID_Parms, NULL );

	pFnGetPlatformAchievementID->FunctionFlags |= 0x400;

	if ( SetIndex )
		*SetIndex = GetPlatformAchievementID_Parms.SetIndex;

	return GetPlatformAchievementID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPS3.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentAchievementPS3::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 38681 ];

	USFXOnlineComponentAchievementPS3_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPS3.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentAchievementPS3::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 38680 ];

	USFXOnlineComponentAchievementPS3_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPS3.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentAchievementPS3::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 38678 ];

	USFXOnlineComponentAchievementPS3_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPS3.IsGranted
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

bool USFXOnlineComponentAchievementPS3::IsGranted ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnIsGranted = NULL;

	if ( ! pFnIsGranted )
		pFnIsGranted = (UFunction*) UObject::GObjObjects()->Data[ 38674 ];

	USFXOnlineComponentAchievementPS3_execIsGranted_Parms IsGranted_Parms;
	IsGranted_Parms.LocalUserNum = LocalUserNum;
	IsGranted_Parms.AchievementId = AchievementId;

	pFnIsGranted->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsGranted, &IsGranted_Parms, NULL );

	pFnIsGranted->FunctionFlags |= 0x400;

	return IsGranted_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementPS3.Grant
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

void USFXOnlineComponentAchievementPS3::Grant ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnGrant = NULL;

	if ( ! pFnGrant )
		pFnGrant = (UFunction*) UObject::GObjObjects()->Data[ 38671 ];

	USFXOnlineComponentAchievementPS3_execGrant_Parms Grant_Parms;
	Grant_Parms.LocalUserNum = LocalUserNum;
	Grant_Parms.AchievementId = AchievementId;

	pFnGrant->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGrant, &Grant_Parms, NULL );

	pFnGrant->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.ShowLoginUIEx
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FScriptDelegate         funcSignInComplete             ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentPlatformPS3::ShowLoginUIEx ( struct FScriptDelegate funcSignInComplete )
{
	static UFunction* pFnShowLoginUIEx = NULL;

	if ( ! pFnShowLoginUIEx )
		pFnShowLoginUIEx = (UFunction*) UObject::GObjObjects()->Data[ 39199 ];

	USFXOnlineComponentPlatformPS3_execShowLoginUIEx_Parms ShowLoginUIEx_Parms;
	memcpy ( &ShowLoginUIEx_Parms.funcSignInComplete, &funcSignInComplete, 0x10 );

	pFnShowLoginUIEx->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowLoginUIEx, &ShowLoginUIEx_Parms, NULL );

	pFnShowLoginUIEx->FunctionFlags |= 0x400;

	return ShowLoginUIEx_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.OnSignInComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bSignedIn                      ( CPF_Parm )

void USFXOnlineComponentPlatformPS3::OnSignInComplete ( unsigned long bSignedIn )
{
	static UFunction* pFnOnSignInComplete = NULL;

	if ( ! pFnOnSignInComplete )
		pFnOnSignInComplete = (UFunction*) UObject::GObjObjects()->Data[ 39197 ];

	USFXOnlineComponentPlatformPS3_execOnSignInComplete_Parms OnSignInComplete_Parms;
	OnSignInComplete_Parms.bSignedIn = bSignedIn;

	this->ProcessEvent ( pFnOnSignInComplete, &OnSignInComplete_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.GetRebootUserData
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineComponentPlatformPS3::GetRebootUserData ( )
{
	static UFunction* pFnGetRebootUserData = NULL;

	if ( ! pFnGetRebootUserData )
		pFnGetRebootUserData = (UFunction*) UObject::GObjObjects()->Data[ 39195 ];

	USFXOnlineComponentPlatformPS3_execGetRebootUserData_Parms GetRebootUserData_Parms;

	pFnGetRebootUserData->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetRebootUserData, &GetRebootUserData_Parms, NULL );

	pFnGetRebootUserData->FunctionFlags |= 0x400;

	return GetRebootUserData_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.WasRebootedFromOSCodeRedemptionUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentPlatformPS3::WasRebootedFromOSCodeRedemptionUI ( )
{
	static UFunction* pFnWasRebootedFromOSCodeRedemptionUI = NULL;

	if ( ! pFnWasRebootedFromOSCodeRedemptionUI )
		pFnWasRebootedFromOSCodeRedemptionUI = (UFunction*) UObject::GObjObjects()->Data[ 39193 ];

	USFXOnlineComponentPlatformPS3_execWasRebootedFromOSCodeRedemptionUI_Parms WasRebootedFromOSCodeRedemptionUI_Parms;

	pFnWasRebootedFromOSCodeRedemptionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWasRebootedFromOSCodeRedemptionUI, &WasRebootedFromOSCodeRedemptionUI_Parms, NULL );

	pFnWasRebootedFromOSCodeRedemptionUI->FunctionFlags |= 0x400;

	return WasRebootedFromOSCodeRedemptionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.ShowCodeRedemptionUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            UserData                       ( CPF_Parm )

bool USFXOnlineComponentPlatformPS3::ShowCodeRedemptionUI ( int UserData )
{
	static UFunction* pFnShowCodeRedemptionUI = NULL;

	if ( ! pFnShowCodeRedemptionUI )
		pFnShowCodeRedemptionUI = (UFunction*) UObject::GObjObjects()->Data[ 39190 ];

	USFXOnlineComponentPlatformPS3_execShowCodeRedemptionUI_Parms ShowCodeRedemptionUI_Parms;
	ShowCodeRedemptionUI_Parms.UserData = UserData;

	pFnShowCodeRedemptionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowCodeRedemptionUI, &ShowCodeRedemptionUI_Parms, NULL );

	pFnShowCodeRedemptionUI->FunctionFlags |= 0x400;

	return ShowCodeRedemptionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.ShowStoreUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentPlatformPS3::ShowStoreUI ( )
{
	static UFunction* pFnShowStoreUI = NULL;

	if ( ! pFnShowStoreUI )
		pFnShowStoreUI = (UFunction*) UObject::GObjObjects()->Data[ 39188 ];

	USFXOnlineComponentPlatformPS3_execShowStoreUI_Parms ShowStoreUI_Parms;

	pFnShowStoreUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowStoreUI, &ShowStoreUI_Parms, NULL );

	pFnShowStoreUI->FunctionFlags |= 0x400;

	return ShowStoreUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.GetOnlineXuid
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm | CPF_OutParm )

bool USFXOnlineComponentPlatformPS3::GetOnlineXuid ( int nUserIndex, struct FUniqueNetId* oPlayerXuid )
{
	static UFunction* pFnGetOnlineXuid = NULL;

	if ( ! pFnGetOnlineXuid )
		pFnGetOnlineXuid = (UFunction*) UObject::GObjObjects()->Data[ 39184 ];

	USFXOnlineComponentPlatformPS3_execGetOnlineXuid_Parms GetOnlineXuid_Parms;
	GetOnlineXuid_Parms.nUserIndex = nUserIndex;

	pFnGetOnlineXuid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOnlineXuid, &GetOnlineXuid_Parms, NULL );

	pFnGetOnlineXuid->FunctionFlags |= 0x400;

	if ( oPlayerXuid )
		memcpy ( oPlayerXuid, &GetOnlineXuid_Parms.oPlayerXuid, 0x8 );

	return GetOnlineXuid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.GetOfflineXuid
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm | CPF_OutParm )

bool USFXOnlineComponentPlatformPS3::GetOfflineXuid ( int nUserIndex, struct FUniqueNetId* oPlayerXuid )
{
	static UFunction* pFnGetOfflineXuid = NULL;

	if ( ! pFnGetOfflineXuid )
		pFnGetOfflineXuid = (UFunction*) UObject::GObjObjects()->Data[ 39180 ];

	USFXOnlineComponentPlatformPS3_execGetOfflineXuid_Parms GetOfflineXuid_Parms;
	GetOfflineXuid_Parms.nUserIndex = nUserIndex;

	pFnGetOfflineXuid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOfflineXuid, &GetOfflineXuid_Parms, NULL );

	pFnGetOfflineXuid->FunctionFlags |= 0x400;

	if ( oPlayerXuid )
		memcpy ( oPlayerXuid, &GetOfflineXuid_Parms.oPlayerXuid, 0x8 );

	return GetOfflineXuid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.ShowKeyboardUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 sTitleText                     ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sDescriptionText               ( CPF_Parm | CPF_NeedCtorLink )
// unsigned char                  nKeyboardType                  ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldValidate                ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bRouteThroughConsole           ( CPF_OptionalParm | CPF_Parm )
// struct FString                 sDefaultText                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
// int                            nMaxResultLength               ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentPlatformPS3::ShowKeyboardUI ( unsigned char LocalUserNum, struct FString sTitleText, struct FString sDescriptionText, unsigned char nKeyboardType, unsigned long bShouldValidate, unsigned long bRouteThroughConsole, struct FString sDefaultText, int nMaxResultLength )
{
	static UFunction* pFnShowKeyboardUI = NULL;

	if ( ! pFnShowKeyboardUI )
		pFnShowKeyboardUI = (UFunction*) UObject::GObjObjects()->Data[ 39170 ];

	USFXOnlineComponentPlatformPS3_execShowKeyboardUI_Parms ShowKeyboardUI_Parms;
	ShowKeyboardUI_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ShowKeyboardUI_Parms.sTitleText, &sTitleText, 0x10 );
	memcpy ( &ShowKeyboardUI_Parms.sDescriptionText, &sDescriptionText, 0x10 );
	ShowKeyboardUI_Parms.nKeyboardType = nKeyboardType;
	ShowKeyboardUI_Parms.bShouldValidate = bShouldValidate;
	ShowKeyboardUI_Parms.bRouteThroughConsole = bRouteThroughConsole;
	memcpy ( &ShowKeyboardUI_Parms.sDefaultText, &sDefaultText, 0x10 );
	ShowKeyboardUI_Parms.nMaxResultLength = nMaxResultLength;

	pFnShowKeyboardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowKeyboardUI, &ShowKeyboardUI_Parms, NULL );

	pFnShowKeyboardUI->FunctionFlags |= 0x400;

	return ShowKeyboardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.ShowFriendsInviteUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm )

bool USFXOnlineComponentPlatformPS3::ShowFriendsInviteUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerXuid )
{
	static UFunction* pFnShowFriendsInviteUI = NULL;

	if ( ! pFnShowFriendsInviteUI )
		pFnShowFriendsInviteUI = (UFunction*) UObject::GObjObjects()->Data[ 39166 ];

	USFXOnlineComponentPlatformPS3_execShowFriendsInviteUI_Parms ShowFriendsInviteUI_Parms;
	ShowFriendsInviteUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowFriendsInviteUI_Parms.oPlayerXuid, &oPlayerXuid, 0x8 );

	pFnShowFriendsInviteUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFriendsInviteUI, &ShowFriendsInviteUI_Parms, NULL );

	pFnShowFriendsInviteUI->FunctionFlags |= 0x400;

	return ShowFriendsInviteUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.ShowFriendsUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

bool USFXOnlineComponentPlatformPS3::ShowFriendsUI ( unsigned char eLocalUserNum )
{
	static UFunction* pFnShowFriendsUI = NULL;

	if ( ! pFnShowFriendsUI )
		pFnShowFriendsUI = (UFunction*) UObject::GObjObjects()->Data[ 39163 ];

	USFXOnlineComponentPlatformPS3_execShowFriendsUI_Parms ShowFriendsUI_Parms;
	ShowFriendsUI_Parms.eLocalUserNum = eLocalUserNum;

	pFnShowFriendsUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFriendsUI, &ShowFriendsUI_Parms, NULL );

	pFnShowFriendsUI->FunctionFlags |= 0x400;

	return ShowFriendsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.ShowAchievementsUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

bool USFXOnlineComponentPlatformPS3::ShowAchievementsUI ( unsigned char byLocalUserNum )
{
	static UFunction* pFnShowAchievementsUI = NULL;

	if ( ! pFnShowAchievementsUI )
		pFnShowAchievementsUI = (UFunction*) UObject::GObjObjects()->Data[ 39160 ];

	USFXOnlineComponentPlatformPS3_execShowAchievementsUI_Parms ShowAchievementsUI_Parms;
	ShowAchievementsUI_Parms.byLocalUserNum = byLocalUserNum;

	pFnShowAchievementsUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowAchievementsUI, &ShowAchievementsUI_Parms, NULL );

	pFnShowAchievementsUI->FunctionFlags |= 0x400;

	return ShowAchievementsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.ShowFeedbackUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )

bool USFXOnlineComponentPlatformPS3::ShowFeedbackUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerId )
{
	static UFunction* pFnShowFeedbackUI = NULL;

	if ( ! pFnShowFeedbackUI )
		pFnShowFeedbackUI = (UFunction*) UObject::GObjObjects()->Data[ 39156 ];

	USFXOnlineComponentPlatformPS3_execShowFeedbackUI_Parms ShowFeedbackUI_Parms;
	ShowFeedbackUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowFeedbackUI_Parms.oPlayerId, &oPlayerId, 0x8 );

	pFnShowFeedbackUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFeedbackUI, &ShowFeedbackUI_Parms, NULL );

	pFnShowFeedbackUI->FunctionFlags |= 0x400;

	return ShowFeedbackUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.ShowGamerCardUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )

bool USFXOnlineComponentPlatformPS3::ShowGamerCardUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerId )
{
	static UFunction* pFnShowGamerCardUI = NULL;

	if ( ! pFnShowGamerCardUI )
		pFnShowGamerCardUI = (UFunction*) UObject::GObjObjects()->Data[ 39152 ];

	USFXOnlineComponentPlatformPS3_execShowGamerCardUI_Parms ShowGamerCardUI_Parms;
	ShowGamerCardUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowGamerCardUI_Parms.oPlayerId, &oPlayerId, 0x8 );

	pFnShowGamerCardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowGamerCardUI, &ShowGamerCardUI_Parms, NULL );

	pFnShowGamerCardUI->FunctionFlags |= 0x400;

	return ShowGamerCardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.CanShowPresenceInformation
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPS3::CanShowPresenceInformation ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanShowPresenceInformation = NULL;

	if ( ! pFnCanShowPresenceInformation )
		pFnCanShowPresenceInformation = (UFunction*) UObject::GObjObjects()->Data[ 39149 ];

	USFXOnlineComponentPlatformPS3_execCanShowPresenceInformation_Parms CanShowPresenceInformation_Parms;
	CanShowPresenceInformation_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanShowPresenceInformation->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanShowPresenceInformation, &CanShowPresenceInformation_Parms, NULL );

	pFnCanShowPresenceInformation->FunctionFlags |= 0x400;

	return CanShowPresenceInformation_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.CanViewPlayerProfiles
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPS3::CanViewPlayerProfiles ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanViewPlayerProfiles = NULL;

	if ( ! pFnCanViewPlayerProfiles )
		pFnCanViewPlayerProfiles = (UFunction*) UObject::GObjObjects()->Data[ 39146 ];

	USFXOnlineComponentPlatformPS3_execCanViewPlayerProfiles_Parms CanViewPlayerProfiles_Parms;
	CanViewPlayerProfiles_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanViewPlayerProfiles->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanViewPlayerProfiles, &CanViewPlayerProfiles_Parms, NULL );

	pFnCanViewPlayerProfiles->FunctionFlags |= 0x400;

	return CanViewPlayerProfiles_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.CanPurchaseContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPS3::CanPurchaseContent ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanPurchaseContent = NULL;

	if ( ! pFnCanPurchaseContent )
		pFnCanPurchaseContent = (UFunction*) UObject::GObjObjects()->Data[ 39143 ];

	USFXOnlineComponentPlatformPS3_execCanPurchaseContent_Parms CanPurchaseContent_Parms;
	CanPurchaseContent_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanPurchaseContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPurchaseContent, &CanPurchaseContent_Parms, NULL );

	pFnCanPurchaseContent->FunctionFlags |= 0x400;

	return CanPurchaseContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.CanDownloadUserContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPS3::CanDownloadUserContent ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanDownloadUserContent = NULL;

	if ( ! pFnCanDownloadUserContent )
		pFnCanDownloadUserContent = (UFunction*) UObject::GObjObjects()->Data[ 39140 ];

	USFXOnlineComponentPlatformPS3_execCanDownloadUserContent_Parms CanDownloadUserContent_Parms;
	CanDownloadUserContent_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanDownloadUserContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanDownloadUserContent, &CanDownloadUserContent_Parms, NULL );

	pFnCanDownloadUserContent->FunctionFlags |= 0x400;

	return CanDownloadUserContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.CanCommunicate
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPS3::CanCommunicate ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanCommunicate = NULL;

	if ( ! pFnCanCommunicate )
		pFnCanCommunicate = (UFunction*) UObject::GObjObjects()->Data[ 39137 ];

	USFXOnlineComponentPlatformPS3_execCanCommunicate_Parms CanCommunicate_Parms;
	CanCommunicate_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanCommunicate->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanCommunicate, &CanCommunicate_Parms, NULL );

	pFnCanCommunicate->FunctionFlags |= 0x400;

	return CanCommunicate_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.CanPlayOnline
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPS3::CanPlayOnline ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanPlayOnline = NULL;

	if ( ! pFnCanPlayOnline )
		pFnCanPlayOnline = (UFunction*) UObject::GObjObjects()->Data[ 39134 ];

	USFXOnlineComponentPlatformPS3_execCanPlayOnline_Parms CanPlayOnline_Parms;
	CanPlayOnline_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanPlayOnline->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPlayOnline, &CanPlayOnline_Parms, NULL );

	pFnCanPlayOnline->FunctionFlags |= 0x400;

	return CanPlayOnline_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.SetRichPresence
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// int                            nPresenceMode                  ( CPF_Parm )
// struct TArray<struct FLocalizedStringSetting> aLocalizedStringSettings       ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
// struct TArray<struct FSettingsProperty> aProperties                    ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void USFXOnlineComponentPlatformPS3::SetRichPresence ( unsigned char eLocalUserNum, int nPresenceMode, struct TArray<struct FLocalizedStringSetting>* aLocalizedStringSettings, struct TArray<struct FSettingsProperty>* aProperties )
{
	static UFunction* pFnSetRichPresence = NULL;

	if ( ! pFnSetRichPresence )
		pFnSetRichPresence = (UFunction*) UObject::GObjObjects()->Data[ 39127 ];

	USFXOnlineComponentPlatformPS3_execSetRichPresence_Parms SetRichPresence_Parms;
	SetRichPresence_Parms.eLocalUserNum = eLocalUserNum;
	SetRichPresence_Parms.nPresenceMode = nPresenceMode;

	pFnSetRichPresence->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetRichPresence, &SetRichPresence_Parms, NULL );

	pFnSetRichPresence->FunctionFlags |= 0x400;

	if ( aLocalizedStringSettings )
		memcpy ( aLocalizedStringSettings, &SetRichPresence_Parms.aLocalizedStringSettings, 0x10 );

	if ( aProperties )
		memcpy ( aProperties, &SetRichPresence_Parms.aProperties, 0x10 );
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.ShowLoginUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned long                  bShowOnlineOnly                ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentPlatformPS3::ShowLoginUI ( unsigned long bShowOnlineOnly )
{
	static UFunction* pFnShowLoginUI = NULL;

	if ( ! pFnShowLoginUI )
		pFnShowLoginUI = (UFunction*) UObject::GObjObjects()->Data[ 39124 ];

	USFXOnlineComponentPlatformPS3_execShowLoginUI_Parms ShowLoginUI_Parms;
	ShowLoginUI_Parms.bShowOnlineOnly = bShowOnlineOnly;

	pFnShowLoginUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowLoginUI, &ShowLoginUI_Parms, NULL );

	pFnShowLoginUI->FunctionFlags |= 0x400;

	return ShowLoginUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.GetLoginStatus
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformPS3::GetLoginStatus ( unsigned char eLocalUserNum )
{
	static UFunction* pFnGetLoginStatus = NULL;

	if ( ! pFnGetLoginStatus )
		pFnGetLoginStatus = (UFunction*) UObject::GObjObjects()->Data[ 39121 ];

	USFXOnlineComponentPlatformPS3_execGetLoginStatus_Parms GetLoginStatus_Parms;
	GetLoginStatus_Parms.eLocalUserNum = eLocalUserNum;

	pFnGetLoginStatus->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetLoginStatus, &GetLoginStatus_Parms, NULL );

	pFnGetLoginStatus->FunctionFlags |= 0x400;

	return GetLoginStatus_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.AddRecentPlayer
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )
// struct FString                 sDescription                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentPlatformPS3::AddRecentPlayer ( struct FUniqueNetId oPlayerId, struct FString sDescription )
{
	static UFunction* pFnAddRecentPlayer = NULL;

	if ( ! pFnAddRecentPlayer )
		pFnAddRecentPlayer = (UFunction*) UObject::GObjObjects()->Data[ 39117 ];

	USFXOnlineComponentPlatformPS3_execAddRecentPlayer_Parms AddRecentPlayer_Parms;
	memcpy ( &AddRecentPlayer_Parms.oPlayerId, &oPlayerId, 0x8 );
	memcpy ( &AddRecentPlayer_Parms.sDescription, &sDescription, 0x10 );

	pFnAddRecentPlayer->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnAddRecentPlayer, &AddRecentPlayer_Parms, NULL );

	pFnAddRecentPlayer->FunctionFlags |= 0x400;

	return AddRecentPlayer_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.OnKeyboardUI
// [0x00040401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineComponentPlatformPS3::OnKeyboardUI ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnOnKeyboardUI = NULL;

	if ( ! pFnOnKeyboardUI )
		pFnOnKeyboardUI = (UFunction*) UObject::GObjObjects()->Data[ 39115 ];

	USFXOnlineComponentPlatformPS3_execOnKeyboardUI_Parms OnKeyboardUI_Parms;
	OnKeyboardUI_Parms.oEvent = oEvent;

	pFnOnKeyboardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnKeyboardUI, &OnKeyboardUI_Parms, NULL );

	pFnOnKeyboardUI->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.OnTick
// [0x00040401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineComponentPlatformPS3::OnTick ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnOnTick = NULL;

	if ( ! pFnOnTick )
		pFnOnTick = (UFunction*) UObject::GObjObjects()->Data[ 39113 ];

	USFXOnlineComponentPlatformPS3_execOnTick_Parms OnTick_Parms;
	OnTick_Parms.oEvent = oEvent;

	pFnOnTick->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnTick, &OnTick_Parms, NULL );

	pFnOnTick->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentPlatformPS3::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 39111 ];

	USFXOnlineComponentPlatformPS3_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentPlatformPS3::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 39110 ];

	USFXOnlineComponentPlatformPS3_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformPS3.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentPlatformPS3::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 39108 ];

	USFXOnlineComponentPlatformPS3_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementDingo.GetTitleAchievementID
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            Index                          ( CPF_Parm )
// int                            SetIndex                       ( CPF_Parm | CPF_OutParm )

int USFXOnlineComponentAchievementDingo::GetTitleAchievementID ( int Index, int* SetIndex )
{
	static UFunction* pFnGetTitleAchievementID = NULL;

	if ( ! pFnGetTitleAchievementID )
		pFnGetTitleAchievementID = (UFunction*) UObject::GObjObjects()->Data[ 38619 ];

	USFXOnlineComponentAchievementDingo_execGetTitleAchievementID_Parms GetTitleAchievementID_Parms;
	GetTitleAchievementID_Parms.Index = Index;

	pFnGetTitleAchievementID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetTitleAchievementID, &GetTitleAchievementID_Parms, NULL );

	pFnGetTitleAchievementID->FunctionFlags |= 0x400;

	if ( SetIndex )
		*SetIndex = GetTitleAchievementID_Parms.SetIndex;

	return GetTitleAchievementID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementDingo.GetPlatformAchievementID
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            Index                          ( CPF_Parm )
// int                            SetIndex                       ( CPF_Parm | CPF_OutParm )

int USFXOnlineComponentAchievementDingo::GetPlatformAchievementID ( int Index, int* SetIndex )
{
	static UFunction* pFnGetPlatformAchievementID = NULL;

	if ( ! pFnGetPlatformAchievementID )
		pFnGetPlatformAchievementID = (UFunction*) UObject::GObjObjects()->Data[ 38615 ];

	USFXOnlineComponentAchievementDingo_execGetPlatformAchievementID_Parms GetPlatformAchievementID_Parms;
	GetPlatformAchievementID_Parms.Index = Index;

	pFnGetPlatformAchievementID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetPlatformAchievementID, &GetPlatformAchievementID_Parms, NULL );

	pFnGetPlatformAchievementID->FunctionFlags |= 0x400;

	if ( SetIndex )
		*SetIndex = GetPlatformAchievementID_Parms.SetIndex;

	return GetPlatformAchievementID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementDingo.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentAchievementDingo::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 38613 ];

	USFXOnlineComponentAchievementDingo_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementDingo.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentAchievementDingo::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 38612 ];

	USFXOnlineComponentAchievementDingo_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementDingo.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentAchievementDingo::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 38610 ];

	USFXOnlineComponentAchievementDingo_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementDingo.IsGranted
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

bool USFXOnlineComponentAchievementDingo::IsGranted ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnIsGranted = NULL;

	if ( ! pFnIsGranted )
		pFnIsGranted = (UFunction*) UObject::GObjObjects()->Data[ 38606 ];

	USFXOnlineComponentAchievementDingo_execIsGranted_Parms IsGranted_Parms;
	IsGranted_Parms.LocalUserNum = LocalUserNum;
	IsGranted_Parms.AchievementId = AchievementId;

	pFnIsGranted->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsGranted, &IsGranted_Parms, NULL );

	pFnIsGranted->FunctionFlags |= 0x400;

	return IsGranted_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementDingo.Grant
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

void USFXOnlineComponentAchievementDingo::Grant ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnGrant = NULL;

	if ( ! pFnGrant )
		pFnGrant = (UFunction*) UObject::GObjObjects()->Data[ 38603 ];

	USFXOnlineComponentAchievementDingo_execGrant_Parms Grant_Parms;
	Grant_Parms.LocalUserNum = LocalUserNum;
	Grant_Parms.AchievementId = AchievementId;

	pFnGrant->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGrant, &Grant_Parms, NULL );

	pFnGrant->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.OnTick
// [0x00040401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineComponentPlatformDingo::OnTick ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnOnTick = NULL;

	if ( ! pFnOnTick )
		pFnOnTick = (UFunction*) UObject::GObjObjects()->Data[ 38920 ];

	USFXOnlineComponentPlatformDingo_execOnTick_Parms OnTick_Parms;
	OnTick_Parms.oEvent = oEvent;

	pFnOnTick->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnTick, &OnTick_Parms, NULL );

	pFnOnTick->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.OnKeyboardUIClosed
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned long                  Success                        ( CPF_Parm )
// struct FString                 InputBuffer                    ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentPlatformDingo::OnKeyboardUIClosed ( unsigned long Success, struct FString InputBuffer )
{
	static UFunction* pFnOnKeyboardUIClosed = NULL;

	if ( ! pFnOnKeyboardUIClosed )
		pFnOnKeyboardUIClosed = (UFunction*) UObject::GObjObjects()->Data[ 38917 ];

	USFXOnlineComponentPlatformDingo_execOnKeyboardUIClosed_Parms OnKeyboardUIClosed_Parms;
	OnKeyboardUIClosed_Parms.Success = Success;
	memcpy ( &OnKeyboardUIClosed_Parms.InputBuffer, &InputBuffer, 0x10 );

	pFnOnKeyboardUIClosed->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnKeyboardUIClosed, &OnKeyboardUIClosed_Parms, NULL );

	pFnOnKeyboardUIClosed->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.GetRebootUserData
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineComponentPlatformDingo::GetRebootUserData ( )
{
	static UFunction* pFnGetRebootUserData = NULL;

	if ( ! pFnGetRebootUserData )
		pFnGetRebootUserData = (UFunction*) UObject::GObjObjects()->Data[ 38915 ];

	USFXOnlineComponentPlatformDingo_execGetRebootUserData_Parms GetRebootUserData_Parms;

	pFnGetRebootUserData->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetRebootUserData, &GetRebootUserData_Parms, NULL );

	pFnGetRebootUserData->FunctionFlags |= 0x400;

	return GetRebootUserData_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.WasRebootedFromOSCodeRedemptionUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentPlatformDingo::WasRebootedFromOSCodeRedemptionUI ( )
{
	static UFunction* pFnWasRebootedFromOSCodeRedemptionUI = NULL;

	if ( ! pFnWasRebootedFromOSCodeRedemptionUI )
		pFnWasRebootedFromOSCodeRedemptionUI = (UFunction*) UObject::GObjObjects()->Data[ 38913 ];

	USFXOnlineComponentPlatformDingo_execWasRebootedFromOSCodeRedemptionUI_Parms WasRebootedFromOSCodeRedemptionUI_Parms;

	pFnWasRebootedFromOSCodeRedemptionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWasRebootedFromOSCodeRedemptionUI, &WasRebootedFromOSCodeRedemptionUI_Parms, NULL );

	pFnWasRebootedFromOSCodeRedemptionUI->FunctionFlags |= 0x400;

	return WasRebootedFromOSCodeRedemptionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.ShowCodeRedemptionUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            UserData                       ( CPF_Parm )

bool USFXOnlineComponentPlatformDingo::ShowCodeRedemptionUI ( int UserData )
{
	static UFunction* pFnShowCodeRedemptionUI = NULL;

	if ( ! pFnShowCodeRedemptionUI )
		pFnShowCodeRedemptionUI = (UFunction*) UObject::GObjObjects()->Data[ 38910 ];

	USFXOnlineComponentPlatformDingo_execShowCodeRedemptionUI_Parms ShowCodeRedemptionUI_Parms;
	ShowCodeRedemptionUI_Parms.UserData = UserData;

	pFnShowCodeRedemptionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowCodeRedemptionUI, &ShowCodeRedemptionUI_Parms, NULL );

	pFnShowCodeRedemptionUI->FunctionFlags |= 0x400;

	return ShowCodeRedemptionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.ShowStoreUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentPlatformDingo::ShowStoreUI ( )
{
	static UFunction* pFnShowStoreUI = NULL;

	if ( ! pFnShowStoreUI )
		pFnShowStoreUI = (UFunction*) UObject::GObjObjects()->Data[ 38908 ];

	USFXOnlineComponentPlatformDingo_execShowStoreUI_Parms ShowStoreUI_Parms;

	pFnShowStoreUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowStoreUI, &ShowStoreUI_Parms, NULL );

	pFnShowStoreUI->FunctionFlags |= 0x400;

	return ShowStoreUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.GetOnlineXuid
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm | CPF_OutParm )

bool USFXOnlineComponentPlatformDingo::GetOnlineXuid ( int nUserIndex, struct FUniqueNetId* oPlayerXuid )
{
	static UFunction* pFnGetOnlineXuid = NULL;

	if ( ! pFnGetOnlineXuid )
		pFnGetOnlineXuid = (UFunction*) UObject::GObjObjects()->Data[ 38904 ];

	USFXOnlineComponentPlatformDingo_execGetOnlineXuid_Parms GetOnlineXuid_Parms;
	GetOnlineXuid_Parms.nUserIndex = nUserIndex;

	pFnGetOnlineXuid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOnlineXuid, &GetOnlineXuid_Parms, NULL );

	pFnGetOnlineXuid->FunctionFlags |= 0x400;

	if ( oPlayerXuid )
		memcpy ( oPlayerXuid, &GetOnlineXuid_Parms.oPlayerXuid, 0x8 );

	return GetOnlineXuid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.GetOfflineXuid
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm | CPF_OutParm )

bool USFXOnlineComponentPlatformDingo::GetOfflineXuid ( int nUserIndex, struct FUniqueNetId* oPlayerXuid )
{
	static UFunction* pFnGetOfflineXuid = NULL;

	if ( ! pFnGetOfflineXuid )
		pFnGetOfflineXuid = (UFunction*) UObject::GObjObjects()->Data[ 38900 ];

	USFXOnlineComponentPlatformDingo_execGetOfflineXuid_Parms GetOfflineXuid_Parms;
	GetOfflineXuid_Parms.nUserIndex = nUserIndex;

	pFnGetOfflineXuid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOfflineXuid, &GetOfflineXuid_Parms, NULL );

	pFnGetOfflineXuid->FunctionFlags |= 0x400;

	if ( oPlayerXuid )
		memcpy ( oPlayerXuid, &GetOfflineXuid_Parms.oPlayerXuid, 0x8 );

	return GetOfflineXuid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.ShowKeyboardUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 sTitleText                     ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sDescriptionText               ( CPF_Parm | CPF_NeedCtorLink )
// unsigned char                  nKeyboardType                  ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldValidate                ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bRouteThroughConsole           ( CPF_OptionalParm | CPF_Parm )
// struct FString                 sDefaultText                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
// int                            nMaxResultLength               ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentPlatformDingo::ShowKeyboardUI ( unsigned char LocalUserNum, struct FString sTitleText, struct FString sDescriptionText, unsigned char nKeyboardType, unsigned long bShouldValidate, unsigned long bRouteThroughConsole, struct FString sDefaultText, int nMaxResultLength )
{
	static UFunction* pFnShowKeyboardUI = NULL;

	if ( ! pFnShowKeyboardUI )
		pFnShowKeyboardUI = (UFunction*) UObject::GObjObjects()->Data[ 38890 ];

	USFXOnlineComponentPlatformDingo_execShowKeyboardUI_Parms ShowKeyboardUI_Parms;
	ShowKeyboardUI_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ShowKeyboardUI_Parms.sTitleText, &sTitleText, 0x10 );
	memcpy ( &ShowKeyboardUI_Parms.sDescriptionText, &sDescriptionText, 0x10 );
	ShowKeyboardUI_Parms.nKeyboardType = nKeyboardType;
	ShowKeyboardUI_Parms.bShouldValidate = bShouldValidate;
	ShowKeyboardUI_Parms.bRouteThroughConsole = bRouteThroughConsole;
	memcpy ( &ShowKeyboardUI_Parms.sDefaultText, &sDefaultText, 0x10 );
	ShowKeyboardUI_Parms.nMaxResultLength = nMaxResultLength;

	pFnShowKeyboardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowKeyboardUI, &ShowKeyboardUI_Parms, NULL );

	pFnShowKeyboardUI->FunctionFlags |= 0x400;

	return ShowKeyboardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.ShowFriendsInviteUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm )

bool USFXOnlineComponentPlatformDingo::ShowFriendsInviteUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerXuid )
{
	static UFunction* pFnShowFriendsInviteUI = NULL;

	if ( ! pFnShowFriendsInviteUI )
		pFnShowFriendsInviteUI = (UFunction*) UObject::GObjObjects()->Data[ 38886 ];

	USFXOnlineComponentPlatformDingo_execShowFriendsInviteUI_Parms ShowFriendsInviteUI_Parms;
	ShowFriendsInviteUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowFriendsInviteUI_Parms.oPlayerXuid, &oPlayerXuid, 0x8 );

	pFnShowFriendsInviteUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFriendsInviteUI, &ShowFriendsInviteUI_Parms, NULL );

	pFnShowFriendsInviteUI->FunctionFlags |= 0x400;

	return ShowFriendsInviteUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.ShowFriendsUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

bool USFXOnlineComponentPlatformDingo::ShowFriendsUI ( unsigned char eLocalUserNum )
{
	static UFunction* pFnShowFriendsUI = NULL;

	if ( ! pFnShowFriendsUI )
		pFnShowFriendsUI = (UFunction*) UObject::GObjObjects()->Data[ 38883 ];

	USFXOnlineComponentPlatformDingo_execShowFriendsUI_Parms ShowFriendsUI_Parms;
	ShowFriendsUI_Parms.eLocalUserNum = eLocalUserNum;

	pFnShowFriendsUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFriendsUI, &ShowFriendsUI_Parms, NULL );

	pFnShowFriendsUI->FunctionFlags |= 0x400;

	return ShowFriendsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.ShowAchievementsUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

bool USFXOnlineComponentPlatformDingo::ShowAchievementsUI ( unsigned char byLocalUserNum )
{
	static UFunction* pFnShowAchievementsUI = NULL;

	if ( ! pFnShowAchievementsUI )
		pFnShowAchievementsUI = (UFunction*) UObject::GObjObjects()->Data[ 38880 ];

	USFXOnlineComponentPlatformDingo_execShowAchievementsUI_Parms ShowAchievementsUI_Parms;
	ShowAchievementsUI_Parms.byLocalUserNum = byLocalUserNum;

	pFnShowAchievementsUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowAchievementsUI, &ShowAchievementsUI_Parms, NULL );

	pFnShowAchievementsUI->FunctionFlags |= 0x400;

	return ShowAchievementsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.ShowFeedbackUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )

bool USFXOnlineComponentPlatformDingo::ShowFeedbackUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerId )
{
	static UFunction* pFnShowFeedbackUI = NULL;

	if ( ! pFnShowFeedbackUI )
		pFnShowFeedbackUI = (UFunction*) UObject::GObjObjects()->Data[ 38876 ];

	USFXOnlineComponentPlatformDingo_execShowFeedbackUI_Parms ShowFeedbackUI_Parms;
	ShowFeedbackUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowFeedbackUI_Parms.oPlayerId, &oPlayerId, 0x8 );

	pFnShowFeedbackUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFeedbackUI, &ShowFeedbackUI_Parms, NULL );

	pFnShowFeedbackUI->FunctionFlags |= 0x400;

	return ShowFeedbackUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.ShowGamerCardUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )

bool USFXOnlineComponentPlatformDingo::ShowGamerCardUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerId )
{
	static UFunction* pFnShowGamerCardUI = NULL;

	if ( ! pFnShowGamerCardUI )
		pFnShowGamerCardUI = (UFunction*) UObject::GObjObjects()->Data[ 38872 ];

	USFXOnlineComponentPlatformDingo_execShowGamerCardUI_Parms ShowGamerCardUI_Parms;
	ShowGamerCardUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowGamerCardUI_Parms.oPlayerId, &oPlayerId, 0x8 );

	pFnShowGamerCardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowGamerCardUI, &ShowGamerCardUI_Parms, NULL );

	pFnShowGamerCardUI->FunctionFlags |= 0x400;

	return ShowGamerCardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.CanShowPresenceInformation
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformDingo::CanShowPresenceInformation ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanShowPresenceInformation = NULL;

	if ( ! pFnCanShowPresenceInformation )
		pFnCanShowPresenceInformation = (UFunction*) UObject::GObjObjects()->Data[ 38869 ];

	USFXOnlineComponentPlatformDingo_execCanShowPresenceInformation_Parms CanShowPresenceInformation_Parms;
	CanShowPresenceInformation_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanShowPresenceInformation->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanShowPresenceInformation, &CanShowPresenceInformation_Parms, NULL );

	pFnCanShowPresenceInformation->FunctionFlags |= 0x400;

	return CanShowPresenceInformation_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.CanViewPlayerProfiles
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformDingo::CanViewPlayerProfiles ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanViewPlayerProfiles = NULL;

	if ( ! pFnCanViewPlayerProfiles )
		pFnCanViewPlayerProfiles = (UFunction*) UObject::GObjObjects()->Data[ 38866 ];

	USFXOnlineComponentPlatformDingo_execCanViewPlayerProfiles_Parms CanViewPlayerProfiles_Parms;
	CanViewPlayerProfiles_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanViewPlayerProfiles->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanViewPlayerProfiles, &CanViewPlayerProfiles_Parms, NULL );

	pFnCanViewPlayerProfiles->FunctionFlags |= 0x400;

	return CanViewPlayerProfiles_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.CanPurchaseContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformDingo::CanPurchaseContent ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanPurchaseContent = NULL;

	if ( ! pFnCanPurchaseContent )
		pFnCanPurchaseContent = (UFunction*) UObject::GObjObjects()->Data[ 38863 ];

	USFXOnlineComponentPlatformDingo_execCanPurchaseContent_Parms CanPurchaseContent_Parms;
	CanPurchaseContent_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanPurchaseContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPurchaseContent, &CanPurchaseContent_Parms, NULL );

	pFnCanPurchaseContent->FunctionFlags |= 0x400;

	return CanPurchaseContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.CanDownloadUserContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformDingo::CanDownloadUserContent ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanDownloadUserContent = NULL;

	if ( ! pFnCanDownloadUserContent )
		pFnCanDownloadUserContent = (UFunction*) UObject::GObjObjects()->Data[ 38860 ];

	USFXOnlineComponentPlatformDingo_execCanDownloadUserContent_Parms CanDownloadUserContent_Parms;
	CanDownloadUserContent_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanDownloadUserContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanDownloadUserContent, &CanDownloadUserContent_Parms, NULL );

	pFnCanDownloadUserContent->FunctionFlags |= 0x400;

	return CanDownloadUserContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.CanCommunicate
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformDingo::CanCommunicate ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanCommunicate = NULL;

	if ( ! pFnCanCommunicate )
		pFnCanCommunicate = (UFunction*) UObject::GObjObjects()->Data[ 38857 ];

	USFXOnlineComponentPlatformDingo_execCanCommunicate_Parms CanCommunicate_Parms;
	CanCommunicate_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanCommunicate->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanCommunicate, &CanCommunicate_Parms, NULL );

	pFnCanCommunicate->FunctionFlags |= 0x400;

	return CanCommunicate_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.CanPlayOnline
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformDingo::CanPlayOnline ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanPlayOnline = NULL;

	if ( ! pFnCanPlayOnline )
		pFnCanPlayOnline = (UFunction*) UObject::GObjObjects()->Data[ 38854 ];

	USFXOnlineComponentPlatformDingo_execCanPlayOnline_Parms CanPlayOnline_Parms;
	CanPlayOnline_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanPlayOnline->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPlayOnline, &CanPlayOnline_Parms, NULL );

	pFnCanPlayOnline->FunctionFlags |= 0x400;

	return CanPlayOnline_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.SetRichPresence
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// int                            nPresenceMode                  ( CPF_Parm )
// struct TArray<struct FLocalizedStringSetting> aLocalizedStringSettings       ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
// struct TArray<struct FSettingsProperty> aProperties                    ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void USFXOnlineComponentPlatformDingo::SetRichPresence ( unsigned char eLocalUserNum, int nPresenceMode, struct TArray<struct FLocalizedStringSetting>* aLocalizedStringSettings, struct TArray<struct FSettingsProperty>* aProperties )
{
	static UFunction* pFnSetRichPresence = NULL;

	if ( ! pFnSetRichPresence )
		pFnSetRichPresence = (UFunction*) UObject::GObjObjects()->Data[ 38847 ];

	USFXOnlineComponentPlatformDingo_execSetRichPresence_Parms SetRichPresence_Parms;
	SetRichPresence_Parms.eLocalUserNum = eLocalUserNum;
	SetRichPresence_Parms.nPresenceMode = nPresenceMode;

	pFnSetRichPresence->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetRichPresence, &SetRichPresence_Parms, NULL );

	pFnSetRichPresence->FunctionFlags |= 0x400;

	if ( aLocalizedStringSettings )
		memcpy ( aLocalizedStringSettings, &SetRichPresence_Parms.aLocalizedStringSettings, 0x10 );

	if ( aProperties )
		memcpy ( aProperties, &SetRichPresence_Parms.aProperties, 0x10 );
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.ShowLoginUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned long                  bShowOnlineOnly                ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentPlatformDingo::ShowLoginUI ( unsigned long bShowOnlineOnly )
{
	static UFunction* pFnShowLoginUI = NULL;

	if ( ! pFnShowLoginUI )
		pFnShowLoginUI = (UFunction*) UObject::GObjObjects()->Data[ 38844 ];

	USFXOnlineComponentPlatformDingo_execShowLoginUI_Parms ShowLoginUI_Parms;
	ShowLoginUI_Parms.bShowOnlineOnly = bShowOnlineOnly;

	pFnShowLoginUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowLoginUI, &ShowLoginUI_Parms, NULL );

	pFnShowLoginUI->FunctionFlags |= 0x400;

	return ShowLoginUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.GetLoginStatus
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformDingo::GetLoginStatus ( unsigned char eLocalUserNum )
{
	static UFunction* pFnGetLoginStatus = NULL;

	if ( ! pFnGetLoginStatus )
		pFnGetLoginStatus = (UFunction*) UObject::GObjObjects()->Data[ 38841 ];

	USFXOnlineComponentPlatformDingo_execGetLoginStatus_Parms GetLoginStatus_Parms;
	GetLoginStatus_Parms.eLocalUserNum = eLocalUserNum;

	pFnGetLoginStatus->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetLoginStatus, &GetLoginStatus_Parms, NULL );

	pFnGetLoginStatus->FunctionFlags |= 0x400;

	return GetLoginStatus_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.AddRecentPlayer
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )
// struct FString                 sDescription                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentPlatformDingo::AddRecentPlayer ( struct FUniqueNetId oPlayerId, struct FString sDescription )
{
	static UFunction* pFnAddRecentPlayer = NULL;

	if ( ! pFnAddRecentPlayer )
		pFnAddRecentPlayer = (UFunction*) UObject::GObjObjects()->Data[ 38837 ];

	USFXOnlineComponentPlatformDingo_execAddRecentPlayer_Parms AddRecentPlayer_Parms;
	memcpy ( &AddRecentPlayer_Parms.oPlayerId, &oPlayerId, 0x8 );
	memcpy ( &AddRecentPlayer_Parms.sDescription, &sDescription, 0x10 );

	pFnAddRecentPlayer->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnAddRecentPlayer, &AddRecentPlayer_Parms, NULL );

	pFnAddRecentPlayer->FunctionFlags |= 0x400;

	return AddRecentPlayer_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentPlatformDingo::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 38835 ];

	USFXOnlineComponentPlatformDingo_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentPlatformDingo::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 38834 ];

	USFXOnlineComponentPlatformDingo_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformDingo.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentPlatformDingo::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 38832 ];

	USFXOnlineComponentPlatformDingo_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementOrbis.GetTitleAchievementID
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            Index                          ( CPF_Parm )
// int                            SetIndex                       ( CPF_Parm | CPF_OutParm )

int USFXOnlineComponentAchievementOrbis::GetTitleAchievementID ( int Index, int* SetIndex )
{
	static UFunction* pFnGetTitleAchievementID = NULL;

	if ( ! pFnGetTitleAchievementID )
		pFnGetTitleAchievementID = (UFunction*) UObject::GObjObjects()->Data[ 38641 ];

	USFXOnlineComponentAchievementOrbis_execGetTitleAchievementID_Parms GetTitleAchievementID_Parms;
	GetTitleAchievementID_Parms.Index = Index;

	pFnGetTitleAchievementID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetTitleAchievementID, &GetTitleAchievementID_Parms, NULL );

	pFnGetTitleAchievementID->FunctionFlags |= 0x400;

	if ( SetIndex )
		*SetIndex = GetTitleAchievementID_Parms.SetIndex;

	return GetTitleAchievementID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementOrbis.GetPlatformAchievementID
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            Index                          ( CPF_Parm )
// int                            SetIndex                       ( CPF_Parm | CPF_OutParm )

int USFXOnlineComponentAchievementOrbis::GetPlatformAchievementID ( int Index, int* SetIndex )
{
	static UFunction* pFnGetPlatformAchievementID = NULL;

	if ( ! pFnGetPlatformAchievementID )
		pFnGetPlatformAchievementID = (UFunction*) UObject::GObjObjects()->Data[ 38637 ];

	USFXOnlineComponentAchievementOrbis_execGetPlatformAchievementID_Parms GetPlatformAchievementID_Parms;
	GetPlatformAchievementID_Parms.Index = Index;

	pFnGetPlatformAchievementID->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetPlatformAchievementID, &GetPlatformAchievementID_Parms, NULL );

	pFnGetPlatformAchievementID->FunctionFlags |= 0x400;

	if ( SetIndex )
		*SetIndex = GetPlatformAchievementID_Parms.SetIndex;

	return GetPlatformAchievementID_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementOrbis.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentAchievementOrbis::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 38635 ];

	USFXOnlineComponentAchievementOrbis_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementOrbis.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentAchievementOrbis::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 38634 ];

	USFXOnlineComponentAchievementOrbis_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementOrbis.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentAchievementOrbis::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 38632 ];

	USFXOnlineComponentAchievementOrbis_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementOrbis.IsGranted
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

bool USFXOnlineComponentAchievementOrbis::IsGranted ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnIsGranted = NULL;

	if ( ! pFnIsGranted )
		pFnIsGranted = (UFunction*) UObject::GObjObjects()->Data[ 38628 ];

	USFXOnlineComponentAchievementOrbis_execIsGranted_Parms IsGranted_Parms;
	IsGranted_Parms.LocalUserNum = LocalUserNum;
	IsGranted_Parms.AchievementId = AchievementId;

	pFnIsGranted->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnIsGranted, &IsGranted_Parms, NULL );

	pFnIsGranted->FunctionFlags |= 0x400;

	return IsGranted_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentAchievementOrbis.Grant
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

void USFXOnlineComponentAchievementOrbis::Grant ( unsigned char LocalUserNum, int AchievementId )
{
	static UFunction* pFnGrant = NULL;

	if ( ! pFnGrant )
		pFnGrant = (UFunction*) UObject::GObjObjects()->Data[ 38625 ];

	USFXOnlineComponentAchievementOrbis_execGrant_Parms Grant_Parms;
	Grant_Parms.LocalUserNum = LocalUserNum;
	Grant_Parms.AchievementId = AchievementId;

	pFnGrant->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGrant, &Grant_Parms, NULL );

	pFnGrant->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.OnKeyboardUIClosed
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned long                  Success                        ( CPF_Parm )
// struct FString                 InputBuffer                    ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentPlatformOrbis::OnKeyboardUIClosed ( unsigned long Success, struct FString InputBuffer )
{
	static UFunction* pFnOnKeyboardUIClosed = NULL;

	if ( ! pFnOnKeyboardUIClosed )
		pFnOnKeyboardUIClosed = (UFunction*) UObject::GObjObjects()->Data[ 39008 ];

	USFXOnlineComponentPlatformOrbis_execOnKeyboardUIClosed_Parms OnKeyboardUIClosed_Parms;
	OnKeyboardUIClosed_Parms.Success = Success;
	memcpy ( &OnKeyboardUIClosed_Parms.InputBuffer, &InputBuffer, 0x10 );

	pFnOnKeyboardUIClosed->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnKeyboardUIClosed, &OnKeyboardUIClosed_Parms, NULL );

	pFnOnKeyboardUIClosed->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.GetRebootUserData
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int USFXOnlineComponentPlatformOrbis::GetRebootUserData ( )
{
	static UFunction* pFnGetRebootUserData = NULL;

	if ( ! pFnGetRebootUserData )
		pFnGetRebootUserData = (UFunction*) UObject::GObjObjects()->Data[ 39006 ];

	USFXOnlineComponentPlatformOrbis_execGetRebootUserData_Parms GetRebootUserData_Parms;

	pFnGetRebootUserData->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetRebootUserData, &GetRebootUserData_Parms, NULL );

	pFnGetRebootUserData->FunctionFlags |= 0x400;

	return GetRebootUserData_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.WasRebootedFromOSCodeRedemptionUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentPlatformOrbis::WasRebootedFromOSCodeRedemptionUI ( )
{
	static UFunction* pFnWasRebootedFromOSCodeRedemptionUI = NULL;

	if ( ! pFnWasRebootedFromOSCodeRedemptionUI )
		pFnWasRebootedFromOSCodeRedemptionUI = (UFunction*) UObject::GObjObjects()->Data[ 39004 ];

	USFXOnlineComponentPlatformOrbis_execWasRebootedFromOSCodeRedemptionUI_Parms WasRebootedFromOSCodeRedemptionUI_Parms;

	pFnWasRebootedFromOSCodeRedemptionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnWasRebootedFromOSCodeRedemptionUI, &WasRebootedFromOSCodeRedemptionUI_Parms, NULL );

	pFnWasRebootedFromOSCodeRedemptionUI->FunctionFlags |= 0x400;

	return WasRebootedFromOSCodeRedemptionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.ShowCodeRedemptionUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            UserData                       ( CPF_Parm )

bool USFXOnlineComponentPlatformOrbis::ShowCodeRedemptionUI ( int UserData )
{
	static UFunction* pFnShowCodeRedemptionUI = NULL;

	if ( ! pFnShowCodeRedemptionUI )
		pFnShowCodeRedemptionUI = (UFunction*) UObject::GObjObjects()->Data[ 39001 ];

	USFXOnlineComponentPlatformOrbis_execShowCodeRedemptionUI_Parms ShowCodeRedemptionUI_Parms;
	ShowCodeRedemptionUI_Parms.UserData = UserData;

	pFnShowCodeRedemptionUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowCodeRedemptionUI, &ShowCodeRedemptionUI_Parms, NULL );

	pFnShowCodeRedemptionUI->FunctionFlags |= 0x400;

	return ShowCodeRedemptionUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.ShowStoreUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentPlatformOrbis::ShowStoreUI ( )
{
	static UFunction* pFnShowStoreUI = NULL;

	if ( ! pFnShowStoreUI )
		pFnShowStoreUI = (UFunction*) UObject::GObjObjects()->Data[ 38999 ];

	USFXOnlineComponentPlatformOrbis_execShowStoreUI_Parms ShowStoreUI_Parms;

	pFnShowStoreUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowStoreUI, &ShowStoreUI_Parms, NULL );

	pFnShowStoreUI->FunctionFlags |= 0x400;

	return ShowStoreUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.GetOnlineXuid
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm | CPF_OutParm )

bool USFXOnlineComponentPlatformOrbis::GetOnlineXuid ( int nUserIndex, struct FUniqueNetId* oPlayerXuid )
{
	static UFunction* pFnGetOnlineXuid = NULL;

	if ( ! pFnGetOnlineXuid )
		pFnGetOnlineXuid = (UFunction*) UObject::GObjObjects()->Data[ 38995 ];

	USFXOnlineComponentPlatformOrbis_execGetOnlineXuid_Parms GetOnlineXuid_Parms;
	GetOnlineXuid_Parms.nUserIndex = nUserIndex;

	pFnGetOnlineXuid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOnlineXuid, &GetOnlineXuid_Parms, NULL );

	pFnGetOnlineXuid->FunctionFlags |= 0x400;

	if ( oPlayerXuid )
		memcpy ( oPlayerXuid, &GetOnlineXuid_Parms.oPlayerXuid, 0x8 );

	return GetOnlineXuid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.GetOfflineXuid
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nUserIndex                     ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm | CPF_OutParm )

bool USFXOnlineComponentPlatformOrbis::GetOfflineXuid ( int nUserIndex, struct FUniqueNetId* oPlayerXuid )
{
	static UFunction* pFnGetOfflineXuid = NULL;

	if ( ! pFnGetOfflineXuid )
		pFnGetOfflineXuid = (UFunction*) UObject::GObjObjects()->Data[ 38991 ];

	USFXOnlineComponentPlatformOrbis_execGetOfflineXuid_Parms GetOfflineXuid_Parms;
	GetOfflineXuid_Parms.nUserIndex = nUserIndex;

	pFnGetOfflineXuid->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetOfflineXuid, &GetOfflineXuid_Parms, NULL );

	pFnGetOfflineXuid->FunctionFlags |= 0x400;

	if ( oPlayerXuid )
		memcpy ( oPlayerXuid, &GetOfflineXuid_Parms.oPlayerXuid, 0x8 );

	return GetOfflineXuid_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.ShowKeyboardUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 sTitleText                     ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 sDescriptionText               ( CPF_Parm | CPF_NeedCtorLink )
// unsigned char                  nKeyboardType                  ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldValidate                ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bRouteThroughConsole           ( CPF_OptionalParm | CPF_Parm )
// struct FString                 sDefaultText                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
// int                            nMaxResultLength               ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentPlatformOrbis::ShowKeyboardUI ( unsigned char LocalUserNum, struct FString sTitleText, struct FString sDescriptionText, unsigned char nKeyboardType, unsigned long bShouldValidate, unsigned long bRouteThroughConsole, struct FString sDefaultText, int nMaxResultLength )
{
	static UFunction* pFnShowKeyboardUI = NULL;

	if ( ! pFnShowKeyboardUI )
		pFnShowKeyboardUI = (UFunction*) UObject::GObjObjects()->Data[ 38981 ];

	USFXOnlineComponentPlatformOrbis_execShowKeyboardUI_Parms ShowKeyboardUI_Parms;
	ShowKeyboardUI_Parms.LocalUserNum = LocalUserNum;
	memcpy ( &ShowKeyboardUI_Parms.sTitleText, &sTitleText, 0x10 );
	memcpy ( &ShowKeyboardUI_Parms.sDescriptionText, &sDescriptionText, 0x10 );
	ShowKeyboardUI_Parms.nKeyboardType = nKeyboardType;
	ShowKeyboardUI_Parms.bShouldValidate = bShouldValidate;
	ShowKeyboardUI_Parms.bRouteThroughConsole = bRouteThroughConsole;
	memcpy ( &ShowKeyboardUI_Parms.sDefaultText, &sDefaultText, 0x10 );
	ShowKeyboardUI_Parms.nMaxResultLength = nMaxResultLength;

	pFnShowKeyboardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowKeyboardUI, &ShowKeyboardUI_Parms, NULL );

	pFnShowKeyboardUI->FunctionFlags |= 0x400;

	return ShowKeyboardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.ShowFriendsInviteUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerXuid                    ( CPF_Parm )

bool USFXOnlineComponentPlatformOrbis::ShowFriendsInviteUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerXuid )
{
	static UFunction* pFnShowFriendsInviteUI = NULL;

	if ( ! pFnShowFriendsInviteUI )
		pFnShowFriendsInviteUI = (UFunction*) UObject::GObjObjects()->Data[ 38977 ];

	USFXOnlineComponentPlatformOrbis_execShowFriendsInviteUI_Parms ShowFriendsInviteUI_Parms;
	ShowFriendsInviteUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowFriendsInviteUI_Parms.oPlayerXuid, &oPlayerXuid, 0x8 );

	pFnShowFriendsInviteUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFriendsInviteUI, &ShowFriendsInviteUI_Parms, NULL );

	pFnShowFriendsInviteUI->FunctionFlags |= 0x400;

	return ShowFriendsInviteUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.ShowFriendsUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

bool USFXOnlineComponentPlatformOrbis::ShowFriendsUI ( unsigned char eLocalUserNum )
{
	static UFunction* pFnShowFriendsUI = NULL;

	if ( ! pFnShowFriendsUI )
		pFnShowFriendsUI = (UFunction*) UObject::GObjObjects()->Data[ 38974 ];

	USFXOnlineComponentPlatformOrbis_execShowFriendsUI_Parms ShowFriendsUI_Parms;
	ShowFriendsUI_Parms.eLocalUserNum = eLocalUserNum;

	pFnShowFriendsUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFriendsUI, &ShowFriendsUI_Parms, NULL );

	pFnShowFriendsUI->FunctionFlags |= 0x400;

	return ShowFriendsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.ShowAchievementsUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  byLocalUserNum                 ( CPF_Parm )

bool USFXOnlineComponentPlatformOrbis::ShowAchievementsUI ( unsigned char byLocalUserNum )
{
	static UFunction* pFnShowAchievementsUI = NULL;

	if ( ! pFnShowAchievementsUI )
		pFnShowAchievementsUI = (UFunction*) UObject::GObjObjects()->Data[ 38971 ];

	USFXOnlineComponentPlatformOrbis_execShowAchievementsUI_Parms ShowAchievementsUI_Parms;
	ShowAchievementsUI_Parms.byLocalUserNum = byLocalUserNum;

	pFnShowAchievementsUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowAchievementsUI, &ShowAchievementsUI_Parms, NULL );

	pFnShowAchievementsUI->FunctionFlags |= 0x400;

	return ShowAchievementsUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.ShowFeedbackUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )

bool USFXOnlineComponentPlatformOrbis::ShowFeedbackUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerId )
{
	static UFunction* pFnShowFeedbackUI = NULL;

	if ( ! pFnShowFeedbackUI )
		pFnShowFeedbackUI = (UFunction*) UObject::GObjObjects()->Data[ 38967 ];

	USFXOnlineComponentPlatformOrbis_execShowFeedbackUI_Parms ShowFeedbackUI_Parms;
	ShowFeedbackUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowFeedbackUI_Parms.oPlayerId, &oPlayerId, 0x8 );

	pFnShowFeedbackUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowFeedbackUI, &ShowFeedbackUI_Parms, NULL );

	pFnShowFeedbackUI->FunctionFlags |= 0x400;

	return ShowFeedbackUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.ShowGamerCardUI
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )

bool USFXOnlineComponentPlatformOrbis::ShowGamerCardUI ( unsigned char eLocalUserNum, struct FUniqueNetId oPlayerId )
{
	static UFunction* pFnShowGamerCardUI = NULL;

	if ( ! pFnShowGamerCardUI )
		pFnShowGamerCardUI = (UFunction*) UObject::GObjObjects()->Data[ 38963 ];

	USFXOnlineComponentPlatformOrbis_execShowGamerCardUI_Parms ShowGamerCardUI_Parms;
	ShowGamerCardUI_Parms.eLocalUserNum = eLocalUserNum;
	memcpy ( &ShowGamerCardUI_Parms.oPlayerId, &oPlayerId, 0x8 );

	pFnShowGamerCardUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowGamerCardUI, &ShowGamerCardUI_Parms, NULL );

	pFnShowGamerCardUI->FunctionFlags |= 0x400;

	return ShowGamerCardUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.CanShowPresenceInformation
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformOrbis::CanShowPresenceInformation ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanShowPresenceInformation = NULL;

	if ( ! pFnCanShowPresenceInformation )
		pFnCanShowPresenceInformation = (UFunction*) UObject::GObjObjects()->Data[ 38960 ];

	USFXOnlineComponentPlatformOrbis_execCanShowPresenceInformation_Parms CanShowPresenceInformation_Parms;
	CanShowPresenceInformation_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanShowPresenceInformation->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanShowPresenceInformation, &CanShowPresenceInformation_Parms, NULL );

	pFnCanShowPresenceInformation->FunctionFlags |= 0x400;

	return CanShowPresenceInformation_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.CanViewPlayerProfiles
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformOrbis::CanViewPlayerProfiles ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanViewPlayerProfiles = NULL;

	if ( ! pFnCanViewPlayerProfiles )
		pFnCanViewPlayerProfiles = (UFunction*) UObject::GObjObjects()->Data[ 38957 ];

	USFXOnlineComponentPlatformOrbis_execCanViewPlayerProfiles_Parms CanViewPlayerProfiles_Parms;
	CanViewPlayerProfiles_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanViewPlayerProfiles->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanViewPlayerProfiles, &CanViewPlayerProfiles_Parms, NULL );

	pFnCanViewPlayerProfiles->FunctionFlags |= 0x400;

	return CanViewPlayerProfiles_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.CanPurchaseContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformOrbis::CanPurchaseContent ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanPurchaseContent = NULL;

	if ( ! pFnCanPurchaseContent )
		pFnCanPurchaseContent = (UFunction*) UObject::GObjObjects()->Data[ 38954 ];

	USFXOnlineComponentPlatformOrbis_execCanPurchaseContent_Parms CanPurchaseContent_Parms;
	CanPurchaseContent_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanPurchaseContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPurchaseContent, &CanPurchaseContent_Parms, NULL );

	pFnCanPurchaseContent->FunctionFlags |= 0x400;

	return CanPurchaseContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.CanDownloadUserContent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformOrbis::CanDownloadUserContent ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanDownloadUserContent = NULL;

	if ( ! pFnCanDownloadUserContent )
		pFnCanDownloadUserContent = (UFunction*) UObject::GObjObjects()->Data[ 38951 ];

	USFXOnlineComponentPlatformOrbis_execCanDownloadUserContent_Parms CanDownloadUserContent_Parms;
	CanDownloadUserContent_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanDownloadUserContent->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanDownloadUserContent, &CanDownloadUserContent_Parms, NULL );

	pFnCanDownloadUserContent->FunctionFlags |= 0x400;

	return CanDownloadUserContent_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.CanCommunicate
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformOrbis::CanCommunicate ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanCommunicate = NULL;

	if ( ! pFnCanCommunicate )
		pFnCanCommunicate = (UFunction*) UObject::GObjObjects()->Data[ 38948 ];

	USFXOnlineComponentPlatformOrbis_execCanCommunicate_Parms CanCommunicate_Parms;
	CanCommunicate_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanCommunicate->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanCommunicate, &CanCommunicate_Parms, NULL );

	pFnCanCommunicate->FunctionFlags |= 0x400;

	return CanCommunicate_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.CanPlayOnline
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformOrbis::CanPlayOnline ( unsigned char eLocalUserNum )
{
	static UFunction* pFnCanPlayOnline = NULL;

	if ( ! pFnCanPlayOnline )
		pFnCanPlayOnline = (UFunction*) UObject::GObjObjects()->Data[ 38945 ];

	USFXOnlineComponentPlatformOrbis_execCanPlayOnline_Parms CanPlayOnline_Parms;
	CanPlayOnline_Parms.eLocalUserNum = eLocalUserNum;

	pFnCanPlayOnline->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnCanPlayOnline, &CanPlayOnline_Parms, NULL );

	pFnCanPlayOnline->FunctionFlags |= 0x400;

	return CanPlayOnline_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.SetRichPresence
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  eLocalUserNum                  ( CPF_Parm )
// int                            nPresenceMode                  ( CPF_Parm )
// struct TArray<struct FLocalizedStringSetting> aLocalizedStringSettings       ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
// struct TArray<struct FSettingsProperty> aProperties                    ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void USFXOnlineComponentPlatformOrbis::SetRichPresence ( unsigned char eLocalUserNum, int nPresenceMode, struct TArray<struct FLocalizedStringSetting>* aLocalizedStringSettings, struct TArray<struct FSettingsProperty>* aProperties )
{
	static UFunction* pFnSetRichPresence = NULL;

	if ( ! pFnSetRichPresence )
		pFnSetRichPresence = (UFunction*) UObject::GObjObjects()->Data[ 38938 ];

	USFXOnlineComponentPlatformOrbis_execSetRichPresence_Parms SetRichPresence_Parms;
	SetRichPresence_Parms.eLocalUserNum = eLocalUserNum;
	SetRichPresence_Parms.nPresenceMode = nPresenceMode;

	pFnSetRichPresence->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnSetRichPresence, &SetRichPresence_Parms, NULL );

	pFnSetRichPresence->FunctionFlags |= 0x400;

	if ( aLocalizedStringSettings )
		memcpy ( aLocalizedStringSettings, &SetRichPresence_Parms.aLocalizedStringSettings, 0x10 );

	if ( aProperties )
		memcpy ( aProperties, &SetRichPresence_Parms.aProperties, 0x10 );
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.ShowLoginUI
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned long                  bShowOnlineOnly                ( CPF_OptionalParm | CPF_Parm )

bool USFXOnlineComponentPlatformOrbis::ShowLoginUI ( unsigned long bShowOnlineOnly )
{
	static UFunction* pFnShowLoginUI = NULL;

	if ( ! pFnShowLoginUI )
		pFnShowLoginUI = (UFunction*) UObject::GObjObjects()->Data[ 38935 ];

	USFXOnlineComponentPlatformOrbis_execShowLoginUI_Parms ShowLoginUI_Parms;
	ShowLoginUI_Parms.bShowOnlineOnly = bShowOnlineOnly;

	pFnShowLoginUI->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnShowLoginUI, &ShowLoginUI_Parms, NULL );

	pFnShowLoginUI->FunctionFlags |= 0x400;

	return ShowLoginUI_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.GetLoginStatus
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  eLocalUserNum                  ( CPF_Parm )

unsigned char USFXOnlineComponentPlatformOrbis::GetLoginStatus ( unsigned char eLocalUserNum )
{
	static UFunction* pFnGetLoginStatus = NULL;

	if ( ! pFnGetLoginStatus )
		pFnGetLoginStatus = (UFunction*) UObject::GObjObjects()->Data[ 38932 ];

	USFXOnlineComponentPlatformOrbis_execGetLoginStatus_Parms GetLoginStatus_Parms;
	GetLoginStatus_Parms.eLocalUserNum = eLocalUserNum;

	pFnGetLoginStatus->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetLoginStatus, &GetLoginStatus_Parms, NULL );

	pFnGetLoginStatus->FunctionFlags |= 0x400;

	return GetLoginStatus_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.AddRecentPlayer
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FUniqueNetId            oPlayerId                      ( CPF_Parm )
// struct FString                 sDescription                   ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool USFXOnlineComponentPlatformOrbis::AddRecentPlayer ( struct FUniqueNetId oPlayerId, struct FString sDescription )
{
	static UFunction* pFnAddRecentPlayer = NULL;

	if ( ! pFnAddRecentPlayer )
		pFnAddRecentPlayer = (UFunction*) UObject::GObjObjects()->Data[ 38928 ];

	USFXOnlineComponentPlatformOrbis_execAddRecentPlayer_Parms AddRecentPlayer_Parms;
	memcpy ( &AddRecentPlayer_Parms.oPlayerId, &oPlayerId, 0x8 );
	memcpy ( &AddRecentPlayer_Parms.sDescription, &sDescription, 0x10 );

	pFnAddRecentPlayer->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnAddRecentPlayer, &AddRecentPlayer_Parms, NULL );

	pFnAddRecentPlayer->FunctionFlags |= 0x400;

	return AddRecentPlayer_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentPlatformOrbis::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 38926 ];

	USFXOnlineComponentPlatformOrbis_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentPlatformOrbis::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 38925 ];

	USFXOnlineComponentPlatformOrbis_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentPlatformOrbis.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentPlatformOrbis::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 38923 ];

	USFXOnlineComponentPlatformOrbis_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentTelemetrySystem.OnTick
// [0x00040401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class USFXOnlineEvent*         oEvent                         ( CPF_Parm )

void USFXOnlineComponentTelemetrySystem::OnTick ( class USFXOnlineEvent* oEvent )
{
	static UFunction* pFnOnTick = NULL;

	if ( ! pFnOnTick )
		pFnOnTick = (UFunction*) UObject::GObjObjects()->Data[ 39333 ];

	USFXOnlineComponentTelemetrySystem_execOnTick_Parms OnTick_Parms;
	OnTick_Parms.oEvent = oEvent;

	pFnOnTick->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnTick, &OnTick_Parms, NULL );

	pFnOnTick->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentTelemetrySystem.Flush
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  Channel                        ( CPF_Parm )

void USFXOnlineComponentTelemetrySystem::Flush ( unsigned char Channel )
{
	static UFunction* pFnFlush = NULL;

	if ( ! pFnFlush )
		pFnFlush = (UFunction*) UObject::GObjObjects()->Data[ 39331 ];

	USFXOnlineComponentTelemetrySystem_execFlush_Parms Flush_Parms;
	Flush_Parms.Channel = Channel;

	pFnFlush->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnFlush, &Flush_Parms, NULL );

	pFnFlush->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentTelemetrySystem.GetAPIName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName USFXOnlineComponentTelemetrySystem::GetAPIName ( )
{
	static UFunction* pFnGetAPIName = NULL;

	if ( ! pFnGetAPIName )
		pFnGetAPIName = (UFunction*) UObject::GObjObjects()->Data[ 39329 ];

	USFXOnlineComponentTelemetrySystem_execGetAPIName_Parms GetAPIName_Parms;

	pFnGetAPIName->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnGetAPIName, &GetAPIName_Parms, NULL );

	pFnGetAPIName->FunctionFlags |= 0x400;

	return GetAPIName_Parms.ReturnValue;
};

// Function SFXOnlineFoundation.SFXOnlineComponentTelemetrySystem.OnRelease
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void USFXOnlineComponentTelemetrySystem::OnRelease ( )
{
	static UFunction* pFnOnRelease = NULL;

	if ( ! pFnOnRelease )
		pFnOnRelease = (UFunction*) UObject::GObjObjects()->Data[ 39328 ];

	USFXOnlineComponentTelemetrySystem_execOnRelease_Parms OnRelease_Parms;

	pFnOnRelease->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnRelease, &OnRelease_Parms, NULL );

	pFnOnRelease->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentTelemetrySystem.OnInitialize
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class USFXOnlineSubsystem*     oOnlineSubsystem               ( CPF_Parm )

void USFXOnlineComponentTelemetrySystem::OnInitialize ( class USFXOnlineSubsystem* oOnlineSubsystem )
{
	static UFunction* pFnOnInitialize = NULL;

	if ( ! pFnOnInitialize )
		pFnOnInitialize = (UFunction*) UObject::GObjObjects()->Data[ 39326 ];

	USFXOnlineComponentTelemetrySystem_execOnInitialize_Parms OnInitialize_Parms;
	OnInitialize_Parms.oOnlineSubsystem = oOnlineSubsystem;

	pFnOnInitialize->FunctionFlags |= ~0x400;

	this->ProcessEvent ( pFnOnInitialize, &OnInitialize_Parms, NULL );

	pFnOnInitialize->FunctionFlags |= 0x400;
};

// Function SFXOnlineFoundation.SFXOnlineComponentTelemetrySystem.RegisterConnectionDelegates
// [0x00020003] ( FUNC_Final )
// Parameters infos:
// struct FScriptDelegate         CollectDelegate                ( CPF_Parm | CPF_NeedCtorLink )
// struct FScriptDelegate         AuthenticateDelegate           ( CPF_Parm | CPF_NeedCtorLink )
// struct FScriptDelegate         DisconnectDelegate             ( CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentTelemetrySystem::RegisterConnectionDelegates ( struct FScriptDelegate CollectDelegate, struct FScriptDelegate AuthenticateDelegate, struct FScriptDelegate DisconnectDelegate )
{
	static UFunction* pFnRegisterConnectionDelegates = NULL;

	if ( ! pFnRegisterConnectionDelegates )
		pFnRegisterConnectionDelegates = (UFunction*) UObject::GObjObjects()->Data[ 39319 ];

	USFXOnlineComponentTelemetrySystem_execRegisterConnectionDelegates_Parms RegisterConnectionDelegates_Parms;
	memcpy ( &RegisterConnectionDelegates_Parms.CollectDelegate, &CollectDelegate, 0x10 );
	memcpy ( &RegisterConnectionDelegates_Parms.AuthenticateDelegate, &AuthenticateDelegate, 0x10 );
	memcpy ( &RegisterConnectionDelegates_Parms.DisconnectDelegate, &DisconnectDelegate, 0x10 );

	this->ProcessEvent ( pFnRegisterConnectionDelegates, &RegisterConnectionDelegates_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentTelemetrySystem.OnDisconnect
// [0x00120000] 
// Parameters infos:
// int                            Error                          ( CPF_Parm )
// struct FString                 SessionId                      ( CPF_Const | CPF_Parm | CPF_NeedCtorLink )

void USFXOnlineComponentTelemetrySystem::OnDisconnect ( int Error, struct FString SessionId )
{
	static UFunction* pFnOnDisconnect = NULL;

	if ( ! pFnOnDisconnect )
		pFnOnDisconnect = (UFunction*) UObject::GObjObjects()->Data[ 39316 ];

	USFXOnlineComponentTelemetrySystem_execOnDisconnect_Parms OnDisconnect_Parms;
	OnDisconnect_Parms.Error = Error;
	memcpy ( &OnDisconnect_Parms.SessionId, &SessionId, 0x10 );

	this->ProcessEvent ( pFnOnDisconnect, &OnDisconnect_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentTelemetrySystem.OnAuthenticate
// [0x00120000] 
// Parameters infos:

void USFXOnlineComponentTelemetrySystem::OnAuthenticate ( )
{
	static UFunction* pFnOnAuthenticate = NULL;

	if ( ! pFnOnAuthenticate )
		pFnOnAuthenticate = (UFunction*) UObject::GObjObjects()->Data[ 39315 ];

	USFXOnlineComponentTelemetrySystem_execOnAuthenticate_Parms OnAuthenticate_Parms;

	this->ProcessEvent ( pFnOnAuthenticate, &OnAuthenticate_Parms, NULL );
};

// Function SFXOnlineFoundation.SFXOnlineComponentTelemetrySystem.CanCollect
// [0x00120000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool USFXOnlineComponentTelemetrySystem::CanCollect ( )
{
	static UFunction* pFnCanCollect = NULL;

	if ( ! pFnCanCollect )
		pFnCanCollect = (UFunction*) UObject::GObjObjects()->Data[ 39313 ];

	USFXOnlineComponentTelemetrySystem_execCanCollect_Parms CanCollect_Parms;

	this->ProcessEvent ( pFnCanCollect, &CanCollect_Parms, NULL );

	return CanCollect_Parms.ReturnValue;
};


#ifdef _MSC_VER
	#pragma pack ( pop )
#endif