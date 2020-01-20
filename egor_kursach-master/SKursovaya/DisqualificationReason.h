#pragma once

#include "IEntity.h"

using namespace System;

public ref class DisqReason : IEntity
{
public:
	int id;
	String^ description = "";
	
	virtual void Initialize(System::String^ row);
	virtual System::String^ GetFileName();
	virtual System::String^ GetFileStr();
	virtual int GetId();
	virtual void SetId(int newId);
};