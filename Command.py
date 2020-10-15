from enum import Enum, auto

VALID_COMMANDS_REQ = {
    "quit"             : 1,
    "locations"        : 1,
    "courses"          : 3,
    "available"        : 1,
    "courses_in_theme" : 2,
    "favorite_theme"  : 1,
}
class Command(Enum):
    QUIT = auto()
    LOCATIONS = auto()
    COURSES = auto()
    AVAILABLE = auto()
    COURSES_IN_THEME = auto()
    FAVOURITE_THEMES = auto()