#pragma once

using namespace System;

#include "IEntity.h"
#include "Team.h"

public ref class Player : IEntity
{
public:
	int id;
	String^ firstName;
	String^ secondName;
	int teamId;
	Team^ team;
	int age;
	int experience;

	// Inherited via IEntity
	virtual void Initialize(System::String^ row);
	virtual System::String^ GetFileName();
	virtual System::String^ GetFileStr();
	virtual int GetId();
	virtual void SetId(int newId);
};