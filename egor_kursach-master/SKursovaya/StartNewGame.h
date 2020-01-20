#pragma once

#include "Command.h"
#include "GameExecutor.h"
#include "KindOfSport.h"
#include "Game.h"
#include "FileDB.h"

public ref class StartNewGame : Command
{
	void printHelpMessage()
	{
		Console::WriteLine("type start to start new game");
	}

	int getTeam(String^ message, int sportid)
	{
		auto teams = FileDB::GetDataFromFile<Team^>();

		Console::WriteLine(message);
		for each (Team^ team in teams)
		{
			if (team->sportId == sportid)
			{
				Console::WriteLine("{0}: {1}", team->id, team->name);
			}
		}

		return Convert::ToInt32(Console::ReadLine());
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
public:
	void execute() override
	{
		String^ cmd;

		while (true)
		{
			Console::Write("startNewGame>");
			cmd = Console::ReadLine();

			if (cmd == "start")
			{
				int sportId = getSportId();

				int fTeamId = getTeam("Выберите первую команду:", sportId);
				int sTeamId = getTeam("Выберите вторую команду:", sportId);

				Game^ newGame = gcnew Game();
				newGame->firstTeamId = fTeamId;
				newGame->secondTeamId = sTeamId;

				FileDB::Create<Game^>(newGame);
				int gameId = newGame->id;

				Console::WriteLine("Успешно!");
				Console::WriteLine("Новый матч начат");

				GameExecutor^ executor = gcnew GameExecutor(newGame);
				executor->execute();
				break;
			}
			else if (cmd == "help")
			{
				printHelpMessage();
				continue;
			}
			else if (cmd == "exit")
			{
				break;
			}
		}
	}

	String^ getHelpMessage() override
	{
		return "starting new game";
	}

	String^ getCommandName() override
	{
		return "startNewGame";
	}
};