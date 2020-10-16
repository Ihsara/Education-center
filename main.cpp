#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

#include "FileOperation.h"


int main()
{
    std::string input_filename;
    
    std::cout << "Input file: ";
    std::cin >> input_filename;

    auto file_handler = FileOperation(input_filename);

    if (file_handler.get_status())
    {
        auto data_container = file_handler.get_data_container();
        for (auto line: data_container)
        {
            for (auto col: line)
            {
                std::cout << col << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {

    }

}
