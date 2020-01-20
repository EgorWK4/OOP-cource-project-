#include "DisqualificationReason.h"

void DisqReason::Initialize(System::String^ row)
{
	array<String^>^ parts = row->Split(';');

	if (parts->Length != 2)
	{
		throw gcnew Exception("incorrect row");
	}

	id = Convert::ToInt32(parts[0]);
	description = parts[1];
}

System::String^ DisqReason::GetFileName()
{
	return "disqualificationReasons.txt";
}

System::String^ DisqReason::GetFileStr()
{
	return Convert::ToString(id) + ";" +
		description;
}

int DisqReason::GetId()
{
	return id;
}

void DisqReason::SetId(int newId)
{
	if (newId <= 0)
	{
		throw gcnew Exception("incorrect new id");
	}

	id = newId;
}
