
from Command import Command as Cmd
from Course import Course
from DataHandler import DataHandler as dataHandl
from ErrorHandler import ErrorHandler as errorHandl
from FileOperations import FileOperations as fileOps
from UserInterface import UserInterface as UI




def main():
    input_filename = input("Input file: ")
    file_handler = fileOps(input_filename)
    if (file_handler.status):
        pass
    else:
        pass


if __name__ == "__main__":
    main()