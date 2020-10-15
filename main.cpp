#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

vector<string> split(const string$ s, const char delimeter, bool ignore_empty =false){
    vector<string> result;
    string tmp = s;
    while (tmp.find(delimeter) != string::npos){
        string new_part = tmp.substr(0, tmp.find(delimeter));
        tmp=tmp.substr(tmp.find(delimeter)+1, tmp.size());
        if(not(ignore_empty and new_part.empty())){
            result.push_back(new_part);
        }
    }
    if(not(ignore_empty and tmp.empty)) {
        result.push_back(tmp);
    }
    return result;
}

int main()
{
    string input_name;
    cout << "Input file: ";
    getline(cin, input_name);
    ifstream input(input_name);

    if (!input) {
        cout << "Error: the input file cannot be opened" << endl;
        return EXIT_FAILURE;
    }
    while (true){
        string line;
        cout << "> ";
        getline(cin, line);
        vector<string> parts = split(line, ' ', true);
        string command = parts.at(0);

        if (parts.size() > 4 | parts.empty()){
            cout << "Error: empty field" << endl;
            return EXIT_FAILURE;
        }
        if(command == "locations"){

        } else if (command == "course"){

        } else if (command =="available"){

        } else if (command == ""){

        } else if (command == "favourite_theme"){

        } else if (command == "quit"){
            return EXIT_SUCCESS;
        }
    }input.close()
}
