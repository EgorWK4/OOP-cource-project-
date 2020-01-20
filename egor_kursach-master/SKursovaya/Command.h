#pragma once

using namespace System;

public ref class Command
{
public:
	virtual String^ getHelpMessage() { return ""; }
	virtual void execute() {}
	virtual String^ getCommandName() { return ""; }
};