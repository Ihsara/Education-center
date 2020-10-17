#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

#include "FileOperation.h"
#include "DataHandler.h"
#include "UserInterface.h"

/**
 * @brief This program need a lot of optimization for data handler
 * Pointer need to be pass not copying data like this
 * Please point out how I can pass pointers around
 * @return int 
 */


int main()
{
    std::string input_filename;
    bool main_proc_enable = true;
    
    std::cout << "Input file: ";
    std::cin >> input_filename;

    auto file_handler = FileOperation(input_filename);

    if (file_handler.get_status())
    {
        auto data_container = file_handler.get_data_container();
        auto data_handler = DataHandler(data_container);
        // data_handler.print_courses_list();
        auto user_if = UserInterface();
        while (main_proc_enable)
        {
            bool has_valid_command = false;
            has_valid_command = user_if.get_command();

            if (has_valid_command && !user_if.is_quit())
            {
                auto command = user_if.pass_command();
                // user_if.print_command();
                main_proc_enable = data_handler.process_command(command);
            }
            else
            {
                main_proc_enable = false;
            }
        }        
    }
    else
    {
        return EXIT_FAILURE;
    }



    return EXIT_SUCCESS;

}
