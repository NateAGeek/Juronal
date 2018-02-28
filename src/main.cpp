#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

#include "journal.h"

int main(int argc, char *argv[]) {
  InitJournal();
  bool run_interactive_mode = true;

  for(int i = 0; i < argc; i++) {
    if(strcmp("-m", argv[i]) == 0) {
      printf("%s\n", "TODO:Make inline message support ok");
    }
  }

  if(run_interactive_mode) {
    char interactive_mode_text[] = "This is the input mode to write yo shit, ctrl+d ends it ";
    puts(interactive_mode_text);

    std::string input = "";
    std::string line_input = "";

    fputs(">", stdout);
    while(std::getline(std::cin, line_input)) {
      input.append(line_input);
      input.append("\n");
      printf("Input %s\n", line_input.c_str());

      fputs(">", stdout);
    }
    WriteStringToJournal(input.c_str());
    
  }

  return 0;
}

