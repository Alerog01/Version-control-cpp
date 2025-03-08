#include "input_parser.h"

void InputParser::check_valid_argc(){

  if (this->argc < 2){

    this->error_msg = 
      "No arguments. Use \"main help\" to see the list of available arguments\n";

  }

}
 
void InputParser::check_command(){

  if (this->error_msg.empty()){

    auto search_iterator = valid_commands.find(this->command.command);

    if (search_iterator == valid_commands.end()){

      this->error_msg =
        "Your command isn't valid. Use \"help\" for more information\n";

    }      
      
  }

}

void InputParser::set_command_args(){

  int i;
  for (i = 0; i < this->argc - 2; i++ ){

    this->command.input_strings.insert(this->argv[2+i]);

  }

}
    

InputParser::InputParser (int &arg_c, char *arg_v[], std::set<std::string> valid_commands):
  argc{arg_c},
  argv{arg_v},
  valid_commands{valid_commands}
{

  check_valid_argc();

  if (this->error_msg.empty()){

    this->command.command = this->argv[1];
    check_command();
    set_command_args();

  }

  has_valid_input = this->error_msg.empty();

} 

void InputParser::print_error_msg(){
      
  if (!has_valid_input){

    std::cout << this->error_msg;

  }

}

bool InputParser::is_valid_input(){

  return this->has_valid_input;

}

Command InputParser::get_parsed_command(){

  return this->command;

}

