#ifndef Journal_h
#define Journal_h

#define DEBUG 1
#if DEBUG
#define assert(x) if (!(x)) {*(int *)1 = 0;}
#else
#define assert(x) {}
#endif

#include <stdio.h>
#include <time.h>

bool journal_init = false;
FILE *journal_file = nullptr;

void InitJournal()
{
    assert(journal_file == nullptr);
    journal_file = fopen("journal.log", "a");
    assert(journal_file != nullptr);
    if (!journal_init)
    {
        fprintf(journal_file,
                "----------------------------------------"
                "----------------------------------------\n");
        time_t tm_s = time(NULL);
        tm loc_tm;
        localtime_r(&tm_s, &loc_tm);
        fprintf(journal_file, "%d.%d.%d %d:%s%d:%s%d %s\n", loc_tm.tm_mon + 1, loc_tm.tm_mday,
            loc_tm.tm_year + 1900, loc_tm.tm_hour % 12 ? loc_tm.tm_hour % 12 : 12,
            loc_tm.tm_min < 10 ? "0" : "", loc_tm.tm_min,
            loc_tm.tm_sec < 10 ? "0" : "", loc_tm.tm_sec,
            loc_tm.tm_hour < 12 ? "AM" : "PM");
    }
    journal_init = true;
}

void CloseJournal()
{
    assert(journal_file != nullptr);
    fclose(journal_file);
    journal_file = nullptr;
}

void WriteStringToJournal(const char *string)
{
    assert(journal_init);
    fprintf(journal_file, "%s\n", string);
}

#endif
