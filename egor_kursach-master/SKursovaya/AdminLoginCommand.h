#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

#include "Command.h"
#include "FileDB.h"
#include "MD5.h"
#include "AdminShell.h"

public ref class AdminLoginCommand : Command
{
	bool checkPassword(String^ pass)
	{
		String^ adminPassHash = File::ReadAllText(FileDB::FilesPath + "\\adminData.txt");

		return equals(adminPassHash, pass);
	}

	String^ getEnteredPassword()
	{
		Console::WriteLine("¬ведите пароль:");
		return Console::ReadLine();
	}

	void login()
	{
		String^ userPass = getEnteredPassword();
		if (checkPassword(userPass))
		{
			AdminShell^ shell = gcnew AdminShell();
			shell->execute();
		}
	}
public:

	String^ getHelpMessage() override
	{
		return "type adminLogin to login as administrator";
	}

	String^ getCommandName() override
	{
		return "adminLogin";
	}

	void execute() override
	{
		login();
	}
};