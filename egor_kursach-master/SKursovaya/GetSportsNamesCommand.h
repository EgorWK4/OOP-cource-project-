#pragma once

#include "Command.h"
#include "KindOfSport.h"
#include "FileDB.h"

using namespace System;

public ref class GetSportsNames : Command
{
	void print()
	{
		auto sports = FileDB::GetDataFromFile<KindOfSport^>();

		for each (KindOfSport^ sport in sports)
		{
			Console::WriteLine("{0}. {1}", sport->id, sport->name);
		}
	}

public:
	String^ getCommandName() override
	{
		return "getSportNames";
	}
	String^ getHelpMessage() override
	{
		return "print all sport names";
	}

	void execute() override
	{
		print();
	}
};