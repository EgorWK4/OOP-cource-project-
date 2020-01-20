#pragma once

#include "Command.h"
#include "Game.h"
#include "FileDB.h"

public ref class GameEndCommand : Command
{
	Game^ game;

	void gameEnd()
	{
		game->isFinished = true;
		FileDB::Update(game);
	}
public:
	GameEndCommand(Game^ game) : game(game)
	{ }

	String^ getCommandName() override
	{
		return "gameEnd";
	}
	String^ getHelpMessage() override
	{
		return "execute when game is over";
	}

	void execute() override
	{
		gameEnd();
	}
};