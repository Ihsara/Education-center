from ErrorHandler import ErrorHandler as EH


class FileOperations(object):
    def __init__(self, input_filename) -> None:
        self.error_handler = EH("file")
        self.raw_data_container = self.__get_data(input_filename)
        if (self.status):
            self.data, self.status = self.__verify_data(
                self.__clean_up_raw_data()
            )

    def __repr__(self) -> str:
        return "File Operations"

    def __get_data(self, input_filename):
        temp = []
        try:
            with open(input_filename) as f:
                temp = f.readlines()
            self.status = True
        except FileNotFoundError:
            self.status = False
            self.error_handler.report("Error: the input file cannot be opened")
            
        return temp

    def __clean_up_raw_data(self):
        temp = data_from_str = []
        
        if (self.raw_data_container is not None):
            temp = [line.replace("\n", "") for line in self.raw_data_container]

            data_from_str = [line.split(";") for line in temp]

        return data_from_str

    def __verify_data(self, data):
        status = True
        ans = data
        for row in data:
            if (len(row) != 4):
                status = False
                ans = []
                self.error_handler.report("Error: empty field")
                return ans, status
            else:
                for col in row:
                    if (col == ""): 
                        status = False
                        ans = []
                        self.error_handler.report("Error: empty field")
                        return ans, status

        return ans, status


if __name__ == "__main__":

    print("Sample data\n")
    input_filename = "data.a"
    file_handler = FileOperations(input_filename)
    print(file_handler.raw_data_container, "\n")
    print(file_handler.status , "\n")
    print(file_handler.data, "\n")

    print("Sample empty field data\n")
    input_filename = "empty_field_1.input"
    file_handler = FileOperations(input_filename)
    print(file_handler.raw_data_container, "\n")
    print(file_handler.status , "\n")
    print(file_handler.data, "\n")

    print("Sample missing field data\n")
    input_filename = "missing_field.input"
    file_handler = FileOperations(input_filename)
    print(file_handler.raw_data_container, "\n")
    print(file_handler.status , "\n")
    print(file_handler.data, "\n")     

    print("Sample missing field data\n")
    input_filename = "none_existence.input"
    file_handler = FileOperations(input_filename)
