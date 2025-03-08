#include <iostream>
#include <filesystem>
#include <unordered_set>
#include <set>
#include "command.h"

class Repository{
  
  private:

    std::filesystem::path repo_base_path;
    std::filesystem::path repo_path;

    void help();
    void fill_tmp_changes_directory();
    void init();
    void add(const std::unordered_set<std::filesystem::path>);
    void remove();
    void move();

    std::filesystem::path get_equivalent_changes_dir
      (const std::filesystem::path working_path);


  public:

    std::set<std::string> valid_commands 
      {"init", "help", "add", "remove", "move"};

    Repository(const std::filesystem::path current_path);
    
    void run_command(const Command& command);

};