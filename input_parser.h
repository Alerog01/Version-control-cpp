#include <set>
#include <unordered_set>
#include <string>
#include <iostream>
#include "command.h"

class InputParser{

  private:

    Command command;
    bool has_valid_input;

    const std::set<std::string> valid_commands;
    std::string error_msg;

    int argc;
    char **argv;

    void check_valid_argc();
 
    void check_command(); 
    void set_command_args();

  public:

    InputParser (int &arg_c, char *arg_v[], std::set<std::string> valid_commands);
     
    void print_error_msg();

    bool is_valid_input();

    Command get_parsed_command();      

};
