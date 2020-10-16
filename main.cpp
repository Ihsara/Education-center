#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

#include "FileOperation.h"
#include "DataHandler.h"

/**
 * @brief This program need a lot of optimization for data handler
 * Pointer need to be pass not copying data like this
 * Please point out how I can pass pointers around
 * 
 * 
 * 
 * @return int 
 */


int main()
{
    std::string input_filename;
    
    std::cout << "Input file: ";
    std::cin >> input_filename;

    auto file_handler = FileOperation(input_filename);

    if (file_handler.get_status())
    {
        auto data_container = file_handler.get_data_container();
/*         for (auto line: data_container)
        {
            for (auto col: line)
            {
                std::cout << col << " ";
            }
            std::cout << std::endl;
        } */
        auto data_handler = DataHandler(data_container);
        data_handler.print_courses_list();
    }
    else
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}
