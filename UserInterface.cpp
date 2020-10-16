
#include <iostream>

#include "UserInterface.h"


UserInterface::UserInterface(std::string line_starter): line_starter(line_starter)
{
    update_valid_command_req();
}

void UserInterface::update_valid_command_req()
{
    valid_command_req.insert(std::pair<std::string, int>("quit", 1));
    valid_command_req.insert(std::pair<std::string, int>("locations", 1));
    valid_command_req.insert(std::pair<std::string, int>("courses", 3));
    valid_command_req.insert(std::pair<std::string, int>("available", 1));
    valid_command_req.insert(std::pair<std::string, int>("courses_in_theme", 2));
    valid_command_req.insert(std::pair<std::string, int>("favorite_theme", 1));
}

bool UserInterface::get_command()
{
    bool has_valid_command = false;
    std::string raw_command;

    while (!has_valid_command)
    {
        std::cout << line_starter;
        getline(std::cin, raw_command);
        if (!raw_command.empty())
        {
            has_valid_command = validate_command(raw_command);
        }
    }

    return has_valid_command;
}

std::vector<std::string> UserInterface::command_constructor(std::string raw_command)
{
    bool has_quotes = false;
    std::string query_string;
    std::vector<std::string> temp_command;
    auto quote_check_first_index = raw_command.find('\"');
    if (quote_check_first_index != std::string::npos)
    {
        auto quote_check_second_index = raw_command.find('\"');
        if (quote_check_second_index != std::string::npos)
        {
            query_string = raw_command.substr(
                quote_check_first_index + 1 ,
                quote_check_second_index - 1);
            std::cout << query_string << std::endl;
            raw_command.erase(quote_check_first_index - 1,
                            quote_check_second_index + 1);

            std::cout << raw_command << std::endl;
            has_quotes = true;
        }
    }

    auto space_deli_index = raw_command.find(" ");
    if (space_deli_index != std::string::npos)
    {
        temp_command.push_back(raw_command.substr(0, space_deli_index));
        std::cout << temp_command.front() << std::endl;
        raw_command.erase(0, space_deli_index + 1);
        raw_command.pop_back();
        temp_command.push_back(raw_command);
    }
    else
    {
        temp_command.push_back(raw_command);
    }

    if (has_quotes)
    {
        temp_command.push_back(query_string);
    }
    return temp_command;
}

bool UserInterface::validate_command(std::string raw_command)
{
    auto command_temp = command_constructor(raw_command);

    if (valid_command_req.find(command_temp.front()) != valid_command_req.end())
    {
        if (valid_command_req[command_temp.front()] == command_temp.size())
        {
            current_command = command_temp;
            return true;
        }
        else
        {
            std::cout << "Error: error in command " << command_temp.front() << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "Error: error in command " << command_temp.front() << std::endl;
        return false;
    }

    return true;
}


int UserInterface::print_command()
{
    std::cout << "Current command: ";
    for (auto c : current_command)
    {
        std::cout << c << " ";
    }

    std::cout << std::endl;
    return 0;
}

bool UserInterface::is_quit()
{
    if (current_command[0].compare("quit") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::vector<std::string> UserInterface::pass_command()
{
    return current_command;
}