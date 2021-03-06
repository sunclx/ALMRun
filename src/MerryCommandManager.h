#ifndef _MERRY_COMMAND_MANAGER_H_
#define _MERRY_COMMAND_MANAGER_H_

#include "MerryCommand.h"
#include <vector>

typedef std::vector<MerryCommand*> MerryCommandArray;

class MerryCommandManager
{
public:
	~MerryCommandManager();
	const void AddFiles(const wxArrayString& files);
	const void AddFiles(const wxArrayString& files,const wxArrayString& excludes);
	const int AddCommand(const wxString& commandName,const wxString& commandDesc,const wxString& commandLine, int funcRef, const wxString& triggerKey,int order,int flags = 0);
	const MerryCommand* GetCommand(int commandID) const;
	bool DelCommand(int commandID);
	MerryCommandArray Collect(const wxString& commandPrefix) const;
	const int SetCmdOrder(int commandID);

private:
	MerryCommandArray m_commands;
};

extern MerryCommandManager* g_commands;
#endif
