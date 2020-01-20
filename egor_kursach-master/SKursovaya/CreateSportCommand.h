#pragma once

using namespace System;
using namespace System::Collections::Generic;

#include "Command.h"
#include "FileDB.h"
#include "Team.h"
#include "KindOfSport.h"
#include "FileDB.h"

public ref class CreateSportCommand : Command
{
	KindOfSport^ createSport()
	{
		KindOfSport^ newSport = gcnew KindOfSport();

		Console::WriteLine("Название нового виде спорта:");
		newSport->name = Console::ReadLine();

		Console::WriteLine("Разрешены ли предупреждения:\n1) да\n2) нет");
		newSport->areWarningAllowed = Console::ReadLine() == "1";

		Console::WriteLine("Разрешены ли таймауты:\n1) да\n2) нет");
		newSport->areTimeOutAllowed = Console::ReadLine() == "1";

		Console::WriteLine("Количество игроков в команде:");
		newSport->numberOfPlayersPerTeam = Convert::ToInt32(Console::ReadLine());

		Console::WriteLine("Длина тайма в минутах:");
		newSport->timeLength = Convert::ToInt32(Console::ReadLine());

		Console::WriteLine("Количество таймов:");
		newSport->timesCount = Convert::ToInt32(Console::ReadLine());

		return newSport;
	}

	void saveNewKindOfSport(KindOfSport^ sport)
	{
		FileDB::Create<KindOfSport^>(sport);
	}

public:
	String^ getHelpMessage() override
	{
		return "type createSport to create new kind of sport";
	}

	String^ getCommandName() override
	{
		return "createSport";
	}

	void execute() override
	{
		KindOfSport^ sport = createSport();
		saveNewKindOfSport(sport);
	}
};