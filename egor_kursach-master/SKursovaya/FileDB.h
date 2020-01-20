#pragma once

#include "IEntity.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

public ref class FileDB
{
private: static String^ path;
public:
	static property String^ FilesPath
	{
		String^ get()
		{
			return path;
		}
		void set(String^ value)
		{
			if (!Directory::Exists(value))
			{
				throw gcnew Exception("folder not exists");
			}

			path = value;
		}
	}

	generic <typename T> where T : IEntity, gcnew()
	static List<T>^ GetDataFromFile();

	generic <typename T> where T : IEntity, gcnew()
	static T GetEntityById(int id);

	generic <typename T> where T : IEntity, gcnew()
	static void Delete(T item);

	generic <typename T> where T : IEntity, gcnew()
	static void Update(T item);

	generic <typename T> where T : IEntity, gcnew()
	static void Create(T item);

	static void SetFilesPath();
};