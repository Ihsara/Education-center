#pragma once

#include <map>
#include <string> 
#include <vector>
#include <iostream>

class Course
{
public:
    Course(
        std::string location = "",
        std::string theme = "",
        std::string course = "",
        std::string enrollment = ""
    );

    std::string get_name();
    std::string get_theme();
    std::vector<std::string> get_locations();
    std::map<std::string, int> get_enrollmments();
    int print_locations();
    int print_enrollments();
    int update_info(std::string location = "",
                        std::string theme = "",
                        std::string enrollment = "");

private:
    std::string name;
    std::string theme;
    std::vector<std::string> locations;
    std::map<std::string, int> enrollments;
    int update_locations(std::string location="");
    int update_enrollment(std::string location="", std::string enrollment="");
};