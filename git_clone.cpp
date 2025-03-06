#include <iostream>
#include <filesystem>
#include <set>
#include "repository.h"

class InputParser{

  private:

    std::string command;
    bool has_valid_input;

    const std::set<std::string> valid_commands;
    std::string error_msg;

    int argc;
    char **argv;

    void check_valid_argc(){

      if (this->argc < 2){

        this->error_msg = 
          "No arguments. Use \"main help\" to see the list of available arguments\n";

      }

    }
 
    void check_command(){
 
      check_valid_argc();

      if (this->error_msg.empty()){

        this->command = this->argv[1];
        auto search_iterator = valid_commands.find(this->command);

        if (search_iterator == valid_commands.end()){

          this->error_msg =
            "Your argument isn't valid. Use \"help\" for more information\n";

        }      
      
      }

    }

    
  public:

    InputParser (int &arg_c, char *arg_v[], std::set<std::string> valid_commands):
      argc{arg_c},
      argv{arg_v},
      valid_commands{valid_commands}
    {

      check_command();
      has_valid_input = this->error_msg.empty();
      
    } 

    void print_error_msg(){
      
      if (!has_valid_input){

        std::cout << this->error_msg;

      }

    }

    bool is_valid_input(){

      return this->has_valid_input;

    }

    std::string get_command(){

      return this->command;

    }
         
};


int main(int argc, char *argv[]) {
 
  std::filesystem::path current_path = std::filesystem::current_path();
  Repository repo(current_path);
 
  InputParser parser{argc, argv, repo.valid_commands};
 
  if (parser.is_valid_input()){

    repo.run_command(parser.get_command());

  }else{

    parser.print_error_msg();

  }
    

  return 0;

}
