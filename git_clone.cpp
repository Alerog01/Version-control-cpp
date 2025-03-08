#include <iostream>
#include <filesystem>
#include <set>
#include "repository.h"
#include "input_parser.h"

int main(int argc, char *argv[]) {
 
  std::filesystem::path current_path = ".";
  Repository repo(current_path);
 
  InputParser parser{argc, argv, repo.valid_commands};
 
  if (parser.is_valid_input()){

    repo.run_command(parser.get_parsed_command());

  }else{

    parser.print_error_msg();

  }
    

  return 0;

}
