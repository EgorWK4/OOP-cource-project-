#pragma once

#include "Team.h"
#include "KindOfSport.h"

public ref class GetTeamsListCommand : Command
{
	void printTeams()
	{
		auto teams = FileDB::GetDataFromFile<Team^>();

		for each (Team^ team in teams)
		{
			Console::WriteLine("{1}: {0}", team->name, team->sport->name);
		}
	}

	int getSportId()
	{
		auto sports = FileDB::GetDataFromFile<KindOfSport^>();

		Console::WriteLine("Выберите вид спорта:");
		for each (auto sport in sports)
		{
			Console::WriteLine("{0}. {1}", sport->id, sport->name);
		}

		String^ strId = Console::ReadLine();
		return Convert::ToInt32(strId);
	}

	void printSportTeams()
	{
		int sportId = getSportId();

		auto teams = FileDB::GetDataFromFile<Team^>();

		for each (Team^ team in teams)
		{
			if (team->sportId == sportId)
			{
				Console::WriteLine("{0}", team->name);
			}
		}
	}
public:
	String^ getCommandName() override
	{
		return "getTeams";
	}
	String^ getHelpMessage() override
	{
		return "print info about all teams";
	}

	void execute() override
	{
		String^ cmd;

		while (true)
		{
			Console::Write("printTeams>");
			cmd = Console::ReadLine();

			if (cmd == "exit")
			{
				break;
			}
			else if (cmd == "help")
			{
				Console::WriteLine("execute print to print all teams");
				Console::WriteLine("execute printBySport to print all teams by some sport");
			}
			else if (cmd == "print")
			{
				printTeams();
			}
			else if (cmd == "printBySport")
			{
				printSportTeams();
			}
			else
			{
				Console::WriteLine("unknown command");
			}
		}
	}
};