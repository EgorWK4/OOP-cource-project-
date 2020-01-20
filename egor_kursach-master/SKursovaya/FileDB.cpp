#include <memory>
#include "FileDB.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

generic <typename T> where T : IEntity, gcnew()
List<T>^ FileDB::GetDataFromFile()
{
	T item = gcnew T();
	String^ path = FilesPath + "\\" + item->GetFileName();
	List<T>^ res = gcnew List<T>();

	{
		StreamReader^ sr = gcnew StreamReader(path);

		String^ line;
		while (!String::IsNullOrEmpty(line = sr->ReadLine()))
		{
			item = gcnew T();
			item->Initialize(line);
			res->Add(item);
		}

		delete sr;
	}

	return res;
}

generic <typename T> where T : IEntity, gcnew()
T FileDB::GetEntityById(int id)
{
	T item = gcnew T();
	String^ path = FilesPath + "\\" + item->GetFileName();
	T res = gcnew T();

	{
		StreamReader^ sr = gcnew StreamReader(path);
		String^ line;
		while ((line = sr->ReadLine()) != nullptr)
		{
			String^ strId = line->Split(';')[0];
			if (strId == Convert::ToString(id))
			{
				res->Initialize(line);
				return res;
			}
		}

		delete sr;
	}

	return res;
}

generic <typename T> where T : IEntity, gcnew()
void FileDB::Delete(T item)
{
	String^ filePath = FilesPath + "\\" + item->GetFileName();
	int id = item->GetId();
	String^ strId = Convert::ToString(id);
	String^ tempFilePath = Path::GetTempFileName();

	{
		StreamReader^ sr = gcnew StreamReader(filePath);
		StreamWriter^ sw = gcnew StreamWriter(tempFilePath);

		String^ line;

		while ((line = sr->ReadLine()) != nullptr)
		{
			String^ currId = line->Split(';')[0];
			if (!currId->Equals(strId))
			{
				sw->WriteLine(line);
			}
		}

		delete sr;
		delete sw;
	}

	File::Delete(filePath);
	File::Move(tempFilePath, filePath);
}

generic <typename T> where T : IEntity, gcnew()
void FileDB::Update(T item)
{
	String^ filePath = FilesPath + "\\" + item->GetFileName();
	String^ strId = item->GetId().ToString();
	String^ tempFilePath = Path::GetTempFileName();

	{
		StreamReader^ sr = gcnew StreamReader(filePath);
		StreamWriter^ sw = gcnew StreamWriter(tempFilePath, true);

		String^ line;

		while ((line = sr->ReadLine()) != nullptr)
		{
			String^ currId = line->Split(';')[0];

			if (currId->Equals(strId))
			{
				sw->WriteLine(item->GetFileStr());
				continue;
			}

			sw->WriteLine(line);
		}

		delete sr;
		delete sw;
	}

	File::Delete(filePath);
	File::Move(tempFilePath, filePath);
}

generic <typename T> where T : IEntity, gcnew()
void FileDB::Create(T item)
{
	String^ filePath = FilesPath + "\\" + item->GetFileName();
	int lastId = 0;

	{
		StreamReader^ sr = gcnew StreamReader(filePath);

		String^ strId = "0";
		String^ line;

		while ((line = sr->ReadLine()) != nullptr)
		{
			strId = line->Split(';')[0];
		}

		try
		{
			lastId = Convert::ToInt32(strId);
		}
		catch (System::Exception ^ ex)
		{
			lastId = 0;
		}

		delete sr;
	}

	{
		StreamWriter^ sw = gcnew StreamWriter(filePath, true);

		item->SetId(lastId + 1);

		String^ newLine = item->GetFileStr();
		sw->WriteLine(newLine);

		delete sw;
	}
}

void FileDB::SetFilesPath()
{
	{
		FolderBrowserDialog^ dialog = gcnew FolderBrowserDialog();

		auto res = dialog->ShowDialog();
		if (res == DialogResult::OK && !String::IsNullOrWhiteSpace(dialog->SelectedPath))
		{
			FilesPath = dialog->SelectedPath;
		}
	}
}