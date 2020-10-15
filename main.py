from Course import Course
from DataHandler import DataHandler as dataHandl
from ErrorHandler import ErrorHandler as errorHandl
from FileOperations import FileOperations as fileOps
from UserInterface import UserInterface as UI

LINE_STARTER = ">"


def main():
    main_proc_enable = True
    data_handler = None
    input_filename = input("Input file: ")

    file_handler = fileOps(input_filename)

    if (file_handler.status):
        data_handler = dataHandl(file_handler.data)

        data_handler.print_courses_list()
    else:
        main_proc_enable = False

    user_if = UI(LINE_STARTER)

    while(main_proc_enable):
        has_valid_command = user_if.get_command()

        if (has_valid_command):
            command = user_if.pass_command()
            main_proc_enable = data_handler.process_command(command)


if __name__ == "__main__":
    main()