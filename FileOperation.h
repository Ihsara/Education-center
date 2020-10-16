#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>


enum class FileOpsError
{
    FileCannotBeOpen,
    EmptyField
};

class FileOperation
{
public:
    FileOperation(std::string input_filename, std::string delimiter=";");

    bool get_status();
    std::vector<std::vector<std::string>> get_data_container();
private:
    bool file_ops_status = false;
    std::string input_filename;
    std::string delimiter;
    std::vector<std::string> raw_data_container;
    std::vector<std::vector<std::string>> data_container;
    //ErrorHandler error_handler(FileOpsError)
    std::vector<std::string> get_raw_data();
    std::vector<std::vector<std::string>> clean_up_raw_data();
    bool verify_data();
};