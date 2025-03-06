#include <iostream>
#include <filesystem>

#include "repository.h"
  
Repository::Repository(std::filesystem::path current_path):
  repo_base_path(current_path)
{
  
  repo_path = repo_base_path / ".fake_git";

}

void Repository::init(){
  
  if (std::filesystem::is_directory(repo_path)){

    std::cout << "El repositorio ya existe\n";
    return;

  }

  std::filesystem::create_directory(repo_path);
  std::filesystem::create_directory(repo_path / "branches");
  std::filesystem::create_directory(repo_path / "branches" / "master");

}

void Repository::help(){

  return;

}

void Repository::run_command(const std::string& command){

  if (command == "init"){

    init();

  }

  if (command == "help"){

    help();

  }

}
