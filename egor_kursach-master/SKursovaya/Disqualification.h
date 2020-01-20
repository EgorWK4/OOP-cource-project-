#pragma once

using namespace System;

//#include "Game.h"
#include "Player.h"
#include "DisqualificationReason.h"
#include "FileDB.h"

public ref class Disqualification : IEntity
{
public:
	DisqReason^ disqReason;
	//Game^ game;
	Player^ player;

	int id;
	//int gameId;
	int playerId;
	int disqReasonId;

	// Inherited via IEntity
	virtual void Initialize(System::String^ row);
	virtual System::String^ GetFileName();
	virtual System::String^ GetFileStr();
	virtual int GetId();
	virtual void SetId(int newId);
};