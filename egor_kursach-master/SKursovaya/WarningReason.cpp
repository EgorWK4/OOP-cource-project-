#include "WarningReason.h"

void WarnReason::Initialize(System::String^ row)
{
	array<String^>^ parts = row->Split(';');

	if (parts->Length != 2)
	{
		throw gcnew Exception("incorrect row");
	}

	id = Convert::ToInt32(parts[0]);
	description = parts[1];
}

System::String^ WarnReason::GetFileName()
{
	return "warningReasons.txt";
}

System::String^ WarnReason::GetFileStr()
{
	return Convert::ToString(id) + ";" +
		description;
}

int WarnReason::GetId()
{
	return id;
}

void WarnReason::SetId(int newId)
{
	if (newId <= 0)
	{
		throw gcnew Exception("incorrect new id");
	}

	id = newId;
}
