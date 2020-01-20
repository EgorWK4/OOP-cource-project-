#pragma once

using namespace System;
using namespace System::Collections::Generic;

#include "Command.h"
#include "CreateSportCommand.h"

public ref class AdminShell
{
	List<Command^>^ commands;

	void pringHeplMessage()
	{
		for each (Command ^ command in commands)
		{
			Console::WriteLine(command->getCommandName() + ":");
			Console::WriteLine(command->getHelpMessage() + "\n");
		}
	}

public:

	AdminShell()
	{
		commands = gcnew List<Command^>();
		commands->Add(gcnew CreateSportCommand());
	}

	void execute()
	{
		String^ cmd;

		while (true)
		{
		whileStart:
			Console::Write("admin>");
			cmd = Console::ReadLine();

			if (cmd == "exit")
			{
				return;
			}
			else if (cmd == "help")
			{
				pringHeplMessage();
				continue;
			}

			for each (Command ^ command in commands)
			{
				if (command->getCommandName() == cmd)
				{
					command->execute();

					goto whileStart;
				}
			}

			Console::WriteLine("unknown command");
		}
	}
};