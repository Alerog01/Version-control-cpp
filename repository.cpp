#include "repository.h"
  
Repository::Repository(const std::filesystem::path current_path):
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
  std::filesystem::create_directory(repo_path / "tmp_changes");

}

void Repository::fill_tmp_changes_directory(){

  using recursive_directory_iterator = 
      std::filesystem::recursive_directory_iterator;

    for (const auto& directory : recursive_directory_iterator(this->repo_base_path)){

      if (!std::filesystem::equivalent(directory, this->repo_path)){

        std::filesystem::copy(directory, this->repo_path / "tmp_changes");

      }

    }

}

void Repository::help(){

  return;

}

void Repository::add
  (const std::unordered_set<std::filesystem::path> added_directories){

  for (const auto& added_directory: added_directories){

    if (!std::filesystem::exists(added_directory)){

      std::cout << "Couldn't find "<< added_directory;

    } else{

      std::filesystem::path equivalent_repo_path = 
        get_equivalent_changes_dir(added_directory);
      
      if (std::filesystem::exists(equivalent_repo_path)){

        //TODO hay que comparar archivos

      } else{

        std::filesystem::copy(added_directory, equivalent_repo_path);

      }

    }

  }

}

std::filesystem::path Repository::get_equivalent_changes_dir
  (const std::filesystem::path working_path){
    
  std::filesystem::path relative_path = 
    std::filesystem::relative(working_path, repo_base_path);

  return repo_base_path / relative_path;

}

void Repository::run_command(const Command& command){

  //TODO: implementar un mapa o algo asi
  if (command.command == "init"){

    init();

  }

  if (command.command == "help"){

    help();

  }
  
  if (command.command == "add"){

    //TODO pasar de strings a paths, segun si son rutas completas o archivos
    //add(command.input_strings);

  }

}
