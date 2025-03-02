#include <iostream>
#include <filesystem>

class Repository{
  
  private:

    std::filesystem::path repo_base_path;
    std::filesystem::path repo_path;

  public:
    
    Repository(std::filesystem::path current_path);
    void init();

};