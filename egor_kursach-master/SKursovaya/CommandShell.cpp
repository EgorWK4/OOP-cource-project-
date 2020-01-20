using namespace System;
using namespace System::Collections::Generic;

#include "CommandShell.h"
#include "AdminLoginCommand.h"

CommandShell::CommandShell()
{
	commands = gcnew List<Command^>();

	commands->Add(gcnew StartNewGame());
	commands->Add(gcnew GetTeamsListCommand());
	commands->Add(gcnew GetSportsNames());
	commands->Add(gcnew ListGamesCommand());
	commands->Add(gcnew AdminLoginCommand());
}

void CommandShell::printHelpMessage()
{
	for each (Command ^ command in commands)
	{
		Console::WriteLine(command->getCommandName() + ":");
		Console::WriteLine(command->getHelpMessage() + "\n");
	}
}

void CommandShell::execute()
{
	String^ cmd;

	while (true)
	{
		whileStart:
		Console::Write("\n>");
		cmd = Console::ReadLine();

		if (cmd == "help")
		{
			printHelpMessage();
			continue;
		}

		for each (Command ^ command in commands)
		{
			if (command->getCommandName() == cmd)
			{
				try
				{
					command->execute();
				}
				catch (Exception^ ex)
				{
					Console::WriteLine("ERROR");
					Console::WriteLine(ex->Message + "\n");
				}
				goto whileStart;
			}
		}

		if (cmd == "exit")
		{
			break;
		}

		Console::WriteLine("unknown command");
	}
}