#pragma once

using namespace System;

public interface class IEntity
{
	void Initialize(String^ row);
	String^ GetFileName();
	String^ GetFileStr();
	int GetId();
	void SetId(int newId);
};