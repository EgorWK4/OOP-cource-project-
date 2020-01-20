#include "KindOfSport.h"

void KindOfSport::Initialize(System::String^ row)
{
	array<String^>^ parts = row->Split(';');

	if (parts->Length != 8)
	{
		throw gcnew Exception("incorrect row");
	}

	id = Convert::ToInt32(parts[0]);
	name = parts[1];
	areWarningAllowed = parts[2] == "1";
	arePlayersSwapAllowed = parts[3] == "1";
	areTimeOutAllowed = parts[4] == "1";
	numberOfPlayersPerTeam = Convert::ToInt32(parts[5]);
	timeLength = Convert::ToInt32(parts[6]);
	timesCount = Convert::ToInt32(parts[7]);
}

System::String^ KindOfSport::GetFileName()
{
	return "kindsOfSport.txt";
}

System::String^ KindOfSport::GetFileStr()
{
	return Convert::ToString(id) + ";" +
		name + ";" +
		(areWarningAllowed ? "1" : "0") + ";" +
		(arePlayersSwapAllowed ? "1" : "0") + ";" +
		(areTimeOutAllowed ? "1" : "0") + ";" +
		Convert::ToString(numberOfPlayersPerTeam) + ";" +
		Convert::ToString(timeLength) + ";" +
		Convert::ToString(timesCount);
}

int KindOfSport::GetId()
{
	return id;
}

void KindOfSport::SetId(int newId)
{
	if (newId <= 0)
	{
		throw gcnew Exception("incorrect new id");
	}

	id = newId;
}
