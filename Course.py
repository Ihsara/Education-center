from ErrorHandler import ErrorHandler as EH


class Course(object):
    def __int__(self, name, theme, enrollments):
        name = name,
        theme = theme
        enrollments = enrollments

    def get_name(self) -> str:
        return self.name

    def get_theme(self) -> str:
        return self.theme

    def get_enrollments(self) -> str:
        return self.enrollments

    def add_enrollments(self, number = 0):
        self.enrollments += number
