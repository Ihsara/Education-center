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
                    print("Found!")
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


if __name__ == "__main__":

    from FileOperations import FileOperations

    print("Sample data\n")
    input_filename = "data.a"
    
    file_handler = FileOperations(input_filename)

    if (file_handler.status):
        print(file_handler.data, "\n")
        data_handler = DataHandler(file_handler.data)

        data_handler.print_courses_list()