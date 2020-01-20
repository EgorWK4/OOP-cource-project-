#pragma once

#include "Command.h"
#include "StartNewGame.h"
#include "GetTeamsListCommand.h"
#include "GetSportsNamesCommand.h"
#include "ListGamesCommand.h"

using namespace System;
using namespace System::Collections::Generic;

public ref class CommandShell
{
	List<Command^>^ commands;
	void printHelpMessage();

public:
	CommandShell();
	void execute();

};