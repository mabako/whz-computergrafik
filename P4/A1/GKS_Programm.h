#pragma once
#include "GServer.h"

class CGKS_Programm : public CServer
{
public:
	CGKS_Programm(void);
	~CGKS_Programm(void);
	void execute();
};
