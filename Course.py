from ErrorHandler import ErrorHandler as EH

FULL_ENROLLMENT = 50
class Course(object):
    def __init__(self, location="", theme="", course="", enrollments=""):
        self.name = course
        self.theme = theme

        self.locations = []
        self.enrollments = {}
        self.__update_location(location)
        self.__update_enrollment(location, enrollments)


    def __repr__(self):
        return f"""{self.name} : {self.theme}
        Locations: {self.locations}
        Enrollments: {self.enrollments}
        """

    def get_theme(self):
        return self.theme

    def get_enrollments(self):
        return self.enrollments

    def add_enrollments(self, number = 0):
        self.enrollments += number

    def __update_enrollment(self, location, enrollment):
        if (enrollment == "full"):
            self.enrollments[location] = FULL_ENROLLMENT
        else:
            self.enrollments[location] = enrollment

    def __update_location(self,location):
        if (location not in self.locations):
            self.locations.append(location)

    def update_info(self, location=None, theme=None, enrollments=None):
        if location is not None:
            self.__update_location(location)
        if location is not None:
            self.theme = theme
        if enrollments is not None:
            self.__update_enrollment(location, enrollments)