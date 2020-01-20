#pragma once

using namespace System;

#include "IEntity.h"

public ref class WarnReason : IEntity
{
public:
	int id;
	String^ description;

	// Inherited via IEntity
	virtual void Initialize(System::String^ row);
	virtual System::String^ GetFileName();
	virtual System::String^ GetFileStr();
	virtual int GetId();
	virtual void SetId(int newId);
};