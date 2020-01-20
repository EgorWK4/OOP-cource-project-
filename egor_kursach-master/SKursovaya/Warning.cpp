#include "Warning.h"
#include "FileDB.h"

void Warning::Initialize(System::String^ row)
{
	array<String^>^ parts = row->Split(';');

	id = Convert::ToInt32(parts[0]);
	//gameId = Convert::ToInt32(parts[1]);
	playerId = Convert::ToInt32(parts[2]);
	warningReasonId = Convert::ToInt32(parts[3]);

	//game = FileDB::GetEntityById<Game^>(gameId);
	player = FileDB::GetEntityById<Player^>(playerId);
	warningReason = FileDB::GetEntityById<WarnReason^>(warningReasonId);
}

System::String^ Warning::GetFileName()
{
	return "warnings.txt";
}

System::String^ Warning::GetFileStr()
{
	return id.ToString() + ";"
		+ "0" + ";" // this->gameId.ToString()
		+ this->playerId.ToString() + ";"
		+ this->warningReasonId.ToString();
}

int Warning::GetId()
{
	return id;
}

void Warning::SetId(int newId)
{
	this->id = id;
}