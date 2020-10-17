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

bool DataHandler::process_command(std::vector<std::string> command)
{
    auto command_kw = command[0];
    bool result = false;

    if (command_kw.compare("locations") == 0)
    {
        result = locations_command(command);
    }
    else if (command_kw.compare("courses") == 0)
    {
        result = courses_command(command);
    }
    else if (command_kw.compare("available") == 0)
    {
        result = available_command(command);
    }
    else
    {

    }

    return result;
}

bool DataHandler::locations_command(std::vector<std::string> command)
{
    int res = 1;

    auto locations_list = populate_locations();

    for (auto loc : locations_list)
    {
        std::cout << loc << std::endl;
    }

    return res;
}

bool DataHandler::courses_command(std::vector<std::string> command)
{
    int res = 1;

    auto query_theme = command[2];
    auto query_location = command[1];
    auto locations_list = populate_locations();
    auto themes_list = populate_themes();

    

    if (std::find(
        locations_list.begin(),
        locations_list.end(),
        query_location) != locations_list.end())
    {

        if (std::find(
            themes_list.begin(),
            themes_list.end(),
            query_theme) != themes_list.end())
        {

            for (auto course : courses_list)
            {
                auto course_locations  = course.get_locations();
                if (course.get_theme().compare(query_theme) == 0
                    && std::find(course_locations.cbegin(),
                                    course_locations.cend(),
                                    query_location) != course_locations.cend())
                {
                    auto enrollment_amount = course.get_enrollmments().at(query_location);
                    if (enrollment_amount != 50)
                    {
                        std::cout << course.get_name() << " --- " << enrollment_amount << " enrollments" << std::endl;
                    }
                    else
                    {
                        std::cout << course.get_name() << " --- full" << std::endl;
                    }
                }
            }

        }
        else
        {
            std::cout << "Error: unknown theme" << std::endl;
        }

    }
    else
    {
        std::cout << "Error: unknown location name" << std::endl;
    }

    return res;
}

bool DataHandler::available_command(std::vector<std::string> command)
{
    int res = 1;

    return res;
}

std::vector<std::string> DataHandler::populate_locations()
{
    std::vector<std::string> temp_container;

    for (auto course: courses_list)
    {
        for (auto loc : course.get_locations())
        {
            if (std::find(
                temp_container.begin(),
                temp_container.end(),
                loc) == temp_container.end())
            {
                temp_container.push_back(loc);
            }
        }
    }

    return temp_container;
}

std::vector<std::string> DataHandler::populate_themes()
{
    std::vector<std::string> temp_container;
    for (auto course: courses_list)
    {
        if (std::find(
            temp_container.begin(),
            temp_container.end(),
            course.get_theme()) == temp_container.end())
        {
            temp_container.push_back(course.get_theme());
        }
    }

    return temp_container;
}