from Command import Command as cmd
from ErrorHandler import ErrorHandler as EH
from Course import Course, FULL_ENROLLMENT


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

        return sorted(temp)


    def print_courses_list(self):
        for course in self.courses_list:
            print(course)

    def available_command(self, command = []):
        res = True
        locations_list = self.__populate_locations()
        course_list = []

        for location in locations_list:
            for course in self.courses_list:
                if (location in course.locations and 
                    course.enrollments[location] < FULL_ENROLLMENT):
                    course_list.append(
                        (
                            location,
                            course.theme,
                            course.name
                        )
                    )

        sorted_course_list = sorted(course_list)
        for course in sorted_course_list:
            print(f"{course[0]} : {course[1]} : {course[2]}")

        return res

    def courses_command(self, command = []):
        res = True
        query_theme = command[2].replace("\"", "")
        query_location = command[1]

        course_enrollment = []

        for course in self.courses_list:
            if (course.theme == query_theme and 
                query_location in course.locations):
                enrollment_amount = course.enrollments[query_location]
                if (enrollment_amount != FULL_ENROLLMENT):
                    print(f"{course.name} --- {enrollment_amount} enrollments")
                else:
                    print(f"{course.name} --- full")

        return res

    def locations_command(self, command = []):
        res = True

        locations_list = self.__populate_locations()

        for location in locations_list:
            print(location)

        return res

    def courses_in_theme_command(self, command = []):
        res = True
        query_theme = command[1]
        courses_in_theme = []

        for course in self.courses_list:
            if (course.theme == query_theme):
                courses_in_theme.append(course.name)

        for course in sorted(courses_in_theme):
            print(course)

        return res

    def favourite_theme_command(self, command = []):
        res = True

        total_enrollments_per_theme = {}

        for course in self.courses_list:
            if (course.theme not in total_enrollments_per_theme):
                total_enrollments_per_theme[course.theme] = sum(course.enrollments.values())
            else:
                total_enrollments_per_theme[course.theme] += sum(course.enrollments.values())


        max_enrollments = max(total_enrollments_per_theme,
                key= total_enrollments_per_theme.get)
        
        max_enrollments_val = total_enrollments_per_theme[max_enrollments]

        themes_with_max_enrollments = [theme for theme, en_count in total_enrollments_per_theme.items() if en_count == max_enrollments_val]

        print(f"{max_enrollments_val} enrollments in themes")
        for theme in themes_with_max_enrollments:
            print(f"--- {theme}")

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

    print("\nCommand: locations")
    command = ["locations"]
    data_handler.process_command(command)

    print("\nCommand: courses <location> <theme>")
    print("\nEg: 1")
    command = ["courses", "Lempaala", "Exercise"]
    data_handler.process_command(command)

    print("\nEg: 2")
    command = ["courses", "Vesilahti", '"Information technology"']
    data_handler.process_command(command)

    print("\nEg: 3")
    command = ["courses", "Nokia", '"Dance"']
    data_handler.process_command(command)

    print("\nCommand: Available")
    command = ["available"]
    data_handler.process_command(command)

    print("\nCommand: courses in theme")
    command = ["courses_in_theme", "Exercise"]
    data_handler.process_command(command)

    print("\nCommand: Favourite theme")
    print("\nEg: 1")
    command = ["favourite_theme"]
    data_handler.process_command(command)

    print("\nEg: 2")
    input_filename = "two_full.input"
    
    file_handler = FileOperations(input_filename)

    if (file_handler.status):
        data_handler = DataHandler(file_handler.data)
    command = ["favourite_theme"]
    data_handler.process_command(command)