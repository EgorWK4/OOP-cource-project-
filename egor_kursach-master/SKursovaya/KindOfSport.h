#pragma once

using namespace System;
using namespace System::Collections::Generic;

#include "IEntity.h"

public ref class KindOfSport : IEntity
{
public:
	int id;
	String^ name;
	bool areWarningAllowed;
	bool arePlayersSwapAllowed;
	bool areTimeOutAllowed;
	int numberOfPlayersPerTeam;
	int timeLength;
	int timesCount;

	// Inherited via IEntity
	virtual void Initialize(System::String^ row);
	virtual System::String^ GetFileName();
	virtual System::String^ GetFileStr();
	virtual int GetId();
	virtual void SetId(int newId);
};