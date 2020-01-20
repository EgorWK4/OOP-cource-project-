#pragma once

#include "Command.h"
#include "Game.h"
#include "Disqualification.h"
#include "DisqualificationReason.h"
#include "Warning.h"
#include "WarningReason.h"
#include "FileDB.h"

using namespace System;
using namespace System::Collections::Generic;

public ref class GetGameStatistic : Command
{
	Game^ game;

	void printsDisqPlayers()
	{
		auto disqs = FileDB::GetDataFromFile<Disqualification^>();

		Console::WriteLine("Disqualifications: ");
		for each (Disqualification^ disq in disqs)
		{
			auto reason = disq->disqReason;
			auto player = disq->player;
			auto team = player->team;

			Console::WriteLine("\tPlayer: {0}, team: {1}, reason: {2}", 
				player->firstName + " " + player->secondName,
				team->name,
				reason->description);
		}
	}

	void printWarnPlayers()
	{
		List<Warning^>^ warns = game->warnings;

		Console::WriteLine("Warnings: ");
		for each (Warning^ warn in warns)
		{
			auto reason = warn->warningReason;
			auto player = warn->player;
			auto team = player->team;

			Console::WriteLine("\tPlayer: {0}, team: {1}, reason: {2}",
				player->firstName + " " + player->secondName,
				team->name,
				reason->description);
		}
	}

	void printScore()
	{
		Console::WriteLine("First team score: " + game->firstScore);
		Console::WriteLine("Second team score: " + game->secondScore);
	}

	void printInfo()
	{
		printScore();
		printsDisqPlayers();
		printWarnPlayers();
	}
public:
	GetGameStatistic(Game^ game) : game(game)
	{ }

	String^ getCommandName() override
	{
		return "statistic";
	}
	String^ getHelpMessage() override
	{
		return "print statistic about cuurent game";
	}

	void execute() override
	{
		printInfo();
	}
};