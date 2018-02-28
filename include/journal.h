#ifndef Journal_h
#define Journal_h

#include <stdio.h>
#include <time.h>

void InitJournal();
void CloseJournal();
void WriteStringToJournal(const char *string);

#endif
