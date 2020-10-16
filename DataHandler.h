#include <algorithm> // TO DO: Make sure this project allow usage of this
#include <map>
#include <string> 
#include <vector>

#include "Course.h"


class DataHandler
{
public:
    DataHandler(std::vector<std::vector<std::string>> raw_data_container);
    std::vector<Course> get_courses_list();

    int print_courses_list(); // TO DO: Remove after verification
private:
    std::vector<Course> courses_list;

    void process_raw_data_container(
        std::vector<std::vector<std::string>> raw_data_container);
};