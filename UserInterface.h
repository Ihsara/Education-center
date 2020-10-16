#pragma once

#include <map>
#include <vector>
#include <string>


class UserInterface
{
public:
    UserInterface(std::string line_starter=">");

    bool get_command();
    std::vector<std::string> pass_command();
    int print_command();
    bool is_quit();

private:
    std::string line_starter;
    std::vector<std::string> current_command;
    std::map<std::string, int> valid_command_req;

    std::vector<std::string> command_constructor(std::string raw_command);
    bool validate_command(std::string raw_command);
    void update_valid_command_req();
};