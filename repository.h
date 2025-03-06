#include <iostream>
#include <filesystem>
#include <set>

class Repository{
  
  private:

    std::filesystem::path repo_base_path;
    std::filesystem::path repo_path;

  public:

    std::set<std::string> valid_commands {"init", "help"};
    Repository(std::filesystem::path current_path);
    
    void run_command(const std::string& command);

    void help();
    void init();

};