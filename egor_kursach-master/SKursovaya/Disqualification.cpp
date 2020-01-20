#include "Disqualification.h"

void Disqualification::Initialize(System::String^ row)
{
	array<String^>^ parts = row->Split(';');

	id = Convert::ToInt32(parts[0]);
	//gameId = Convert::ToInt32(parts[1]);
	playerId = Convert::ToInt32(parts[2]);
	disqReasonId = Convert::ToInt32(parts[3]);

	//game = FileDB::GetEntityById<Game^>(gameId);
	player = FileDB::GetEntityById<Player^>(playerId);
	disqReason = FileDB::GetEntityById<DisqReason^>(disqReasonId);
}

System::String^ Disqualification::GetFileName()
{
	return "disqualifications.txt";
}

int Disqualification::GetId()
{
	return id;
}

void Disqualification::SetId(int newId)
{
	if (newId <= 0)
	{
		throw gcnew Exception("incorrect id");
	}

	id = newId;
}

System::String^ Disqualification::GetFileStr()
{
	return Convert::ToString(id) + ";" +
		"0" + ";" + //Convert::ToString(gameId)
		Convert::ToString(playerId) + ";" +
		Convert::ToString(disqReasonId);
}
