#pragma once

using namespace System;
using namespace System::Collections::Generic;

#include "IEntity.h"
#include "Team.h"
#include "Disqualification.h"
#include "Warning.h"

public ref class Game : IEntity
{
public:
	int id;
	int firstTeamId;
	int secondTeamId;
	Team^ firstTeam;
	Team^ secondTeam;
	bool isFinished = false;
	int firstScore = 0;
	int secondScore = 0;
	List<Disqualification^>^ disqualifications;
	List<Warning^>^ warnings;

	bool operator <(Game^ other);
	bool operator >(Game^ other);

	Game();

	virtual void Initialize(System::String^ row);
	virtual System::String^ GetFileName();
	virtual System::String^ GetFileStr();
	virtual int GetId();
	virtual void SetId(int newId);
};