from Command import VALID_COMMANDS_REQ
from ErrorHandler import ErrorHandler as EH



class UserInterface(object):
    def __init__(self, line_starter) -> None: 
        self.__current_command = ""
        self.__line_starter = line_starter
        self.__valid_commands_req = VALID_COMMANDS_REQ
        self.__error_handler = EH("User Interface")

    def __repr__(self) -> str:
        return "User Interface"

    def get_command(self):
        has_valid_command = False
        raw_command = ""

        while (not has_valid_command):
            raw_command = input(self.__line_starter)
            has_valid_command = self.__validate_command(raw_command)

        if(has_valid_command):
            self.command = raw_command

        return has_valid_command

    def __validate_command(self, raw_command):
        command = raw_command.split(" ")
        if (command[0] in self.__valid_commands_req and 
            self.__valid_commands_req[command[0]] == len(command)):
            self.__current_command = command
            return True

        else:
            self.__error_handler.report(f"Error: Unknown command: {command[0]}")
            return False

    def pass_command(self):
        return self.__current_command

    def print_command(self):
        return print(self.__current_command)

    def is_quit(self):
        try:
            if (self.__current_command[0] == "quit"):
                return True
        except KeyError:
            return False

        return False


if __name__ == "__main__":
    main_pro_enable = True
    ui = UserInterface(">")

    while(main_pro_enable):
        has_valid_command = ui.get_command()

        if (has_valid_command):
            ui.print_command()
    
        main_pro_enable = not ui.is_quit()
