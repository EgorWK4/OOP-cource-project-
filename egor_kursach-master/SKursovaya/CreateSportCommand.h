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

		Console::WriteLine("�������� ������ ���� ������:");
		newSport->name = Console::ReadLine();

		Console::WriteLine("��������� �� ��������������:\n1) ��\n2) ���");
		newSport->areWarningAllowed = Console::ReadLine() == "1";

		Console::WriteLine("��������� �� ��������:\n1) ��\n2) ���");
		newSport->areTimeOutAllowed = Console::ReadLine() == "1";

		Console::WriteLine("���������� ������� � �������:");
		newSport->numberOfPlayersPerTeam = Convert::ToInt32(Console::ReadLine());

		Console::WriteLine("����� ����� � �������:");
		newSport->timeLength = Convert::ToInt32(Console::ReadLine());

		Console::WriteLine("���������� ������:");
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