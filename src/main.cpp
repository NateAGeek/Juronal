#include "journal.h"

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

void editJournal() {
}

void viewJournal() {
}

void syncJournal() {
}

void newJournal() {
  InitJournal();
  char interactive_mode_text[] = "This is the input mode to write yo shit, ctrl+d ends it ";
  puts(interactive_mode_text);

  std::string input = "";
  std::string line_input = "";

  fputs(">", stdout);
  while(std::getline(std::cin, line_input)) {
    input.append(line_input);
    input.append("\n");
    fputs(">", stdout);
  }
  WriteStringToJournal(input.c_str());
}

int main(int argc, char *argv[]) {
  
  if(argc > 1) {
    if(strcmp(argv[1], "edit") == 0) {
      editJournal();      
    } else if(strcmp(argv[1], "view") == 0) {
      viewJournal();
    } else if(strcmp(argv[1], "new") == 0) {
      newJournal();
    } else if(strcmp(argv[1], "sync") == 0) { 
      syncJournal();
    }
  } else {
    puts("You do not know how to use this program? Do you?");
  }

  return 0;
}

