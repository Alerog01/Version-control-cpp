#include <iostream>
#include <set>
#include <filesystem>

#include "repository.h"

class InputParser{

  private:
 
    int argc;
    char **argv;

    const std::set<std::string> valid_args{"init", "help"};
    std::string error_msg;

    void parse_argc(){

      if (this->argc == 1){

        this->is_valid_args = false;
        this->error_msg = 
          "No arguments. Use \"main help\" to see the list of available arguments\n";

      }
  
      if (this->argc > 2){
    
        this->is_valid_args = false;
        this->error_msg =
         "Enter one argument only\n";

      }

    }

    void parse_argv(){

      auto search = valid_args.find(this->argv[1]);

      if (search != valid_args.end()){

        this->is_valid_args = true;

      }
      else{

        this->is_valid_args = false;
        this->error_msg =
          "Your argument isn't valid. Use \"help\" for more information\n";

      }
    }


  public:

    bool is_valid_args = true;
    std::string command;

    InputParser (int &arg_c, char *arg_v[]){

      argc = arg_c;
      argv = arg_v; 

    } 

    void parse_args(){
 
      parse_argc();

      if (!this->is_valid_args){

        return;

      } 
      
      parse_argv();
      
      if (this->is_valid_args){

        this->command = this->argv[1];

      }
    }

    void print_error_msg(){
      
      if (!this->error_msg.empty()){

        std::cout << this->error_msg;

      }

    }
          
};


int main(int argc, char *argv[]) {
  
  InputParser parser{argc, argv};
  parser.parse_args();
  
  if (!parser.is_valid_args){

    parser.print_error_msg();
    return 0;

  }
  

  std::filesystem::path current_path = std::filesystem::current_path();
  Repository repo(current_path);

    

  return 0;

}
