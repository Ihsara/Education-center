#include "DataHandler.h"

DataHandler::DataHandler(std::vector<std::vector<std::string>> raw_data_container)
{
    process_raw_data_container(raw_data_container);
}

void DataHandler::process_raw_data_container(
    std::vector<std::vector<std::string>> raw_data_container)
{
    
    for (auto line: raw_data_container)
    {
        bool found = false;
        for (auto& course : courses_list)
        {
            
            if (course.get_name().compare(line[2]) == 0)
            {
                // std::cout << "\nCourse to update: " << course.get_name() << " " << course.get_theme() << std::endl;
                course.update_info(
                    line[0],
                    line[1],
                    line[3]
                );
                // course.print_locations();
                // course.print_enrollments();
                found = true;
                break;
            }
        }
        if (!found)
        {
            // std::cout << "\n--> Create new course " << line[0]
            // << " " << line[1] 
            // << " " << line[3] << std::endl;
            auto tmp = Course(line[0], line[1], line[2], line[3]);
            courses_list.push_back(tmp);
        }
    }

}

int DataHandler::print_courses_list()
{
    int res = 1;
    for (auto course : courses_list)
    {
        std::cout << course.get_name() << " : " << course.get_theme() << std::endl;
        course.print_enrollments();
        course.print_locations();
        std::cout << std::endl;
    }

    return res;
}

std::vector<Course> DataHandler::get_courses_list()
{
    return courses_list;
}