//---------------------------------------------------------------------------
/*
	TVP2 ( T Visual Presenter 2 )  A script authoring tool
	Copyright (C) 2000-2005  W.Dee <dee@kikyou.info>

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// Archive eXtractor Susie plug-in support
//---------------------------------------------------------------------------
#ifndef SusieArchiveH
#define SusieArchiveH
//---------------------------------------------------------------------------
#include "StorageIntf.h"

void TVPLoadArchiveSPI(HINSTANCE inst);
void TVPUnloadArchiveSPI(HINSTANCE inst);
class tTVPArchive;
tTVPArchive * TVPOpenSusieArchive(const ttstr & name);

#endif
