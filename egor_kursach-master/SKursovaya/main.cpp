#include "CommandShell.h"
#include "Team.h"
#include "Game.h"
#include "Disqualification.h"
#include "FileDB.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

[STAThreadAttribute]
int main()
{
	//FileDB::FilesPath = "E:\\egor_data_files";
	FileDB::SetFilesPath();

	CommandShell^ sh = gcnew CommandShell();
	sh->execute();

	return 0;
}