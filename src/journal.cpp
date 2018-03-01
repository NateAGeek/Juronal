#include "journal.h"

static bool journal_init = false;
static FILE *journal_file = nullptr;

void InitJournal()
{
    journal_file = fopen("journal.log", "a");
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
    fclose(journal_file);
    journal_file = nullptr;
}

void WriteStringToJournal(const char *string)
{
    fprintf(journal_file, "%s\n", string);
}
