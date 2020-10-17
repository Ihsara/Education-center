#include <algorithm> // TO DO: Make sure this project allow usage of this
#include <map>
#include <string> 
#include <vector>
#include <iostream>

#include "Course.h"


constexpr int FULL_ENROLLMENT = 50;

Course::Course(
    std::string location,
    std::string theme,
    std::string course,
    std::string enrollment):
theme(theme), name(course)
{
    update_locations(location);
    update_enrollment(location, enrollment);
}

std::string Course::get_name() const
{
    return name;
}

std::string Course::get_theme() const
{
    return theme;
}

std::vector<std::string> Course::get_locations()
{
    return locations;
}

std::map<std::string, int> Course::get_enrollmments()
{
    return enrollments;
}

int Course::update_info(std::string location, std::string theme, std::string enrollment)
{
    int res = 0;
    if (!location.empty())
    {
        res = update_locations(location);
    }

    if (!theme.empty())
    {
        theme = theme;
    }

    if (!enrollment.empty() && !location.empty())
    {
        // std::cout << "Update: " << location << " : " << enrollment << std::endl;
        res = update_enrollment(location, enrollment);
    }

    return res;
}

int Course::update_locations(std::string location)
{
    int res = 0;

    if (std::find(locations.begin(), locations.end(), location) == locations.end())
    {
        locations.push_back(location);
    }
    else
    {
        //res = -1;
    }

    return res;
}

int Course::update_enrollment(std::string location, std::string enrollment)
{
    int res = 1;

    if (enrollment.compare("full") == 0)
    {   
        enrollments[location] = FULL_ENROLLMENT;
    }
    else
    {
        enrollments[location] = std::stoi(enrollment);
    }

    return res;
}


int Course::print_locations()
{
    std::cout << "Location of " << name << std::endl;
    for (auto loc : locations)
    {
        std::cout << loc << " ";
    }
    std::cout << std::endl;

    return 0;
}

int Course::print_enrollments()
{
    std::cout << "Enrollmenets of " << name << std::endl;
    for (auto en : enrollments)
    {
        std::cout << "   " << en.first << " : " << en.second << std::endl;
    }
    return 0;
}