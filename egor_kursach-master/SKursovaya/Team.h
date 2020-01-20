#pragma once

using namespace System;

#include "IEntity.h"
#include "KindOfSport.h"

public ref class Team : IEntity
{
public:
	int id;
	String^ name;
	int sportId;
	KindOfSport^ sport;

	// Inherited via IEntity
	virtual void Initialize(System::String^ row);
	virtual System::String^ GetFileName();
	virtual System::String^ GetFileStr();
	virtual int GetId();
	virtual void SetId(int newId);
};