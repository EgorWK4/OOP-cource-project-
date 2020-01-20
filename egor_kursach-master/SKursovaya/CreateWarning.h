#pragma once

#include "Command.h"
#include "Player.h"
#include "Warning.h"
#include "WarningReason.h"
#include "FileDB.h"
#include "Game.h"

public ref class CreateWarningCommand : Command
{
	int getPlayerId(bool isFirstTeam)
	{
		auto players = FileDB::GetDataFromFile<Player^>();

		Console::WriteLine("¬ыберите игрока: ");
		for each (Player^ player in players)
		{
			Console::WriteLine("\t{0}. {1} {2}", player->id, player->firstName, player->secondName);
		}

		String^ strPlayerId = Console::ReadLine();
		return Convert::ToInt32(strPlayerId);
	}

	void createWarning(int playerId, int reasonId)
	{
		Warning^ newWarn = gcnew Warning();
		/*newWarn->gameId = game->id;
		newWarn->game = game;*/
		newWarn->playerId = playerId;
		newWarn->player = FileDB::GetEntityById<Player^>(playerId);
		newWarn->warningReasonId = reasonId;
		newWarn->warningReason = FileDB::GetEntityById<WarnReason^>(reasonId);

		game->warnings->Add(newWarn);
	}

	int getWarningReason()
	{
		auto warnReasons = FileDB::GetDataFromFile<WarnReason^>();

		Console::WriteLine("¬ыберите причину предупреждени€: ");
		for each (WarnReason^ reason in warnReasons)
		{
			Console::WriteLine("{0}. {1}", reason->id, reason->description);
		}

		String^ strId = Console::ReadLine();

		return Convert::ToInt32(strId);
	}
public:
	Game^ game = nullptr;

	CreateWarningCommand(Game^ game) : game(game)
	{ }

	String^ getHelpMessage() override
	{
		return "create new warning to player";
	}

	String^ getCommandName() override
	{
		return "warn";
	}

	void execute() override
	{
		Console::WriteLine("Ќапишите 1 если это игрок из первой команды, и напишите 2, если это игрок из второй команды");
		int team = Console::ReadLine() == "1" ? 1 : 2;
		int playerId = getPlayerId(team == 1);
		int warnReason = getWarningReason();
		
		createWarning(playerId, warnReason);
	}
};