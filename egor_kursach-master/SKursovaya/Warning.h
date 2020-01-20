#pragma once

//#include "Game.h"
#include "Player.h"
#include "WarningReason.h"
#include "IEntity.h"

public ref class Warning : IEntity
{
public:
	int id;
	//int gameId;
	//Game^ game;
	int playerId;
	Player^ player;
	int warningReasonId;
	WarnReason^ warningReason;

	// Inherited via IEntity
	virtual void Initialize(System::String^ row);
	virtual System::String^ GetFileName();
	virtual System::String^ GetFileStr();
	virtual int GetId();
	virtual void SetId(int newId);
};