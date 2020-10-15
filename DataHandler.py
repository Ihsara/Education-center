from Command import Command as cmd
from ErrorHandler import ErrorHandler as EH
from Course import Course


class DataHandler(object):
    def __init__(self, raw_data_course_list):
        self.courses_list = self.process_raw_data_input(
            raw_data_course_list
        )

    def __repr__(self) -> str:
        return "DataHandler"

    def process_raw_data_input(self, raw_data_course_list):
        temp = []
        for line in raw_data_course_list:
            found = False
            for course in temp:
                if (course.name == line[2]):
                    course.update_info(
                        location=line[0],
                        theme=line[1],
                        enrollments=line[3]
                    )
                    found = True
                    break

            if (not found):
                tmp = Course(
                        location=line[0],
                        theme=line[1],
                        course=line[2],
                        enrollments=line[3]
                    )
                temp.append(tmp)

        return temp


    def print_courses_list(self):
        for course in self.courses_list:
            print(course)

    def available_command(self, command = []):
        res = True

        print("Command: Available")

        return res

    def courses_command(self, command = []):
        res = True

        print("Command: Courses")

        return res

    def locations_command(self, command = []):
        res = True

        locations_list = self.__populate_locations()

        for location in locations_list:
            print(location)

        return res

    def courses_in_theme_command(self, command = []):
        res = True

        print("Command: courses in theme")

        return res

    def favourite_theme_command(self, command = []):
        res = True

        print("Command: Favourite theme")

        return res

    def process_command(self, command = []):
        command_type = command[0]
        result = getattr(self, f"{command_type}_command")(command)

        return result

    def __populate_locations(self):
        locations_list = []
        for course in self.courses_list:
            for loc in course.locations:
                if (loc not in locations_list):
                    locations_list.append(loc)

        return sorted(locations_list)




if __name__ == "__main__":

    from FileOperations import FileOperations

    data_handler = None

    print("Sample data\n")
    input_filename = "data.a"
    
    file_handler = FileOperations(input_filename)

    if (file_handler.status):
        print(file_handler.data, "\n")
        data_handler = DataHandler(file_handler.data)

        data_handler.print_courses_list()

    from Command import VALID_COMMANDS_REQ

    commands_list = list(VALID_COMMANDS_REQ.keys())
    commands_list.remove("quit")
    for command_keyword in commands_list:
        command = [command_keyword]
        data_handler.process_command(command)