#pragma once
#include <string>
#include <unordered_set>

struct Command{

  std::string command;
  std::unordered_set<std::string> input_strings;

};