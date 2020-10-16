#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

#include "FileOperation.h"

FileOperation::FileOperation(std::string input_filename, std::string delimiter):
input_filename(input_filename), delimiter(delimiter)
{
    raw_data_container = get_raw_data();

    if (file_ops_status)
    {
        data_container = clean_up_raw_data();
        file_ops_status = verify_data();
    }
    std::cout << file_ops_status << std::endl;
}

std::vector<std::string> FileOperation::get_raw_data()
{
    std::ifstream input_file(input_filename);
    std::vector<std::string> temp_container;
    
    if (!input_file.is_open())
    {
        std::cout << "Error: the input file cannot be opened" << std::endl;
    }
    else
    {
        std::string line;
        
        while (std::getline(input_file, line))
        {
            temp_container.push_back(line);
            //std::cout << line << std::endl; //TO DO: Remove this line after veri
        }
        file_ops_status = true;
    }
    return temp_container;
}

std::vector<std::vector<std::string>> FileOperation::clean_up_raw_data()
{
    std::vector<std::vector<std::string>> temp_container;

    for (auto line: raw_data_container)
    {
        size_t pos = 0;
        std::string token;
        std::vector<std::string> temp_line_container;
        while( (pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            temp_line_container.push_back(token);
            line.erase(0, pos + delimiter.length());
            //std::cout << token << " "; // TO DO: Remove
        }
        token = line.substr(0, pos);
        temp_line_container.push_back(token);
        //std::cout << token << std::endl; // TO DO: Remove
        temp_container.push_back(temp_line_container);
    }

    return temp_container;
}

bool FileOperation::verify_data()
{
    bool status = true;

    for (auto line : data_container)
    {
        if (line.size() != 4)
        {
            status = false;
            std::cout << "Error: empty field" << std::endl;
            return status;
        }
        else
        {
            for (auto col : line)
            {
                if (col.compare("") == 0)
                {
                    status = false;
                    std::cout << "Error: empty field" << std::endl;
                    return status;
                }
            }
        }
    }

    return status;
}


bool FileOperation::get_status()
{
    return file_ops_status;
}

std::vector<std::vector<std::string>> FileOperation::get_data_container()
{
    return data_container;
}