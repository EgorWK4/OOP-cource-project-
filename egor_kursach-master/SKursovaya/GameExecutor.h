#pragma once

#include "Command.h"
#include "CreateWarning.h"
#include "GoalCommand.h"
#include "CreateDisqualificationCommand.h"
#include "GameEndCommand.h"
#include "GetGameStatistic.h"

using namespace System;
using namespace System::Collections::Generic;

public ref class GameExecutor
{
	Game^ game;
	List<Command^>^ commands;

	void printHelpMsg()
	{
		for each (Command^ command in commands)
		{
			Console::WriteLine(command->getCommandName() + ":");
			Console::WriteLine(command->getHelpMessage() + "\n");
		}
	}
public:
	GameExecutor(Game^ game) : game(game)
	{
		commands = gcnew List<Command^>();
		commands->Add(gcnew CreateWarningCommand(game));
		commands->Add(gcnew GoalCommand(game));
		commands->Add(gcnew CreateDisqualificationCommand(game));
		commands->Add(gcnew GameEndCommand(game));
		commands->Add(gcnew GetGameStatistic(game));
	}

	void execute()
	{
		String^ cmd;

		while (true)
		{
			whileStart:
			Console::Write("Матч №" + Convert::ToString(game->id) + ">");
			cmd = Console::ReadLine();

			if (cmd == "exit")
			{
				GameEndCommand^ end = gcnew GameEndCommand(game);
				end->execute();
				return;
			}
			else if (cmd == "help")
			{
				printHelpMsg();
				continue;
			}

			for each (Command^ command in commands)
			{
				if (command->getCommandName() == cmd)
				{
					command->execute();

					if (command->getCommandName() == "gameEnd")
					{
						return;
					}

					goto whileStart;
				}
			}

			Console::WriteLine("unknown command");
		}
	}
};