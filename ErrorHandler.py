

class ErrorHandler(object):
    def __init__(self, type_error):
        self.error_type = type_error

    def __repr__(self) -> str:
        return "Error"

    def report(self, message):
        return print(f"{message}")