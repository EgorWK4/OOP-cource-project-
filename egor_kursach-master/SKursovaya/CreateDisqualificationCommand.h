#pragma once

#include "Command.h"
#include "Game.h"
#include "Disqualification.h"
#include "DisqualificationReason.h"

using namespace System;

public ref class CreateDisqualificationCommand : Command
{
	Game^ game;

	int getPlayerId(bool isFirstTeam)
	{
		int teamId = isFirstTeam ? game->firstTeamId : game->secondTeamId;

		auto players = FileDB::GetDataFromFile<Player^>();

		Console::WriteLine("Выберите игрока: ");
		for each (Player^ player in players)
		{
			if (player->teamId == teamId)
			{
				Console::WriteLine("\t{0}. {1} {2}", player->id, player->firstName, player->secondName);
			}
		}

		String^ strPlayerId = Console::ReadLine();
		return Convert::ToInt32(strPlayerId);
	}

	void createDisq(int playerId, int reasonId)
	{
		Disqualification^ disq = gcnew Disqualification();
		disq->playerId = playerId;
		disq->player = FileDB::GetEntityById<Player^>(playerId);
		disq->disqReasonId = reasonId;
		disq->disqReason = FileDB::GetEntityById<DisqReason^>(reasonId);

		game->disqualifications->Add(disq);
	}

	int getDisqReason()
	{
		auto disqReasons = FileDB::GetDataFromFile<DisqReason^>();

		Console::WriteLine("Выберите причину дисквалификации: ");
		for each (DisqReason^ reason in disqReasons)
		{
			Console::WriteLine("{0}. {1}", reason->id, reason->description);
		}

		String^ strId = Console::ReadLine();

		return Convert::ToInt32(strId);
	}
public:
	CreateDisqualificationCommand(Game^ game) : game(game)
	{ }

	String^ getCommandName() override
	{
		return "disq";
	}
	String^ getHelpMessage() override
	{
		return "create new disqualification";
	}

	void execute() override
	{
		Console::WriteLine("Напишите 1 если это игрок из первой команды, и напишите 2, если это игрок из второй команды");
		int team = Console::ReadLine() == "1" ? 1 : 2;
		int playerId = getPlayerId(team == 1);
		int warnReason = getDisqReason();

		createDisq(playerId, warnReason);
		Player^ player = FileDB::GetEntityById<Player^>(playerId);
		Console::WriteLine("Игрок {0} {1} дисквалифицирован", player->firstName, player->secondName);
	}
};