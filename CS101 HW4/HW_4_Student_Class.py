class Student:
    def __init__(self, name, age, movie_genre):
        self.__name = name
        self.__age = age
        self.__movie_genre = movie_genre

    def set_name(self, name):
        self.__name = name

    def set_age(self, age):
        self.__age = age

    def set_movie_genre(self, movie_genre):
        self.__movie_genre = movie_genre

    def get_name(self):
        return self.__name

    def get_age(self):
        return self.__age

    def get_movie_genre(self):
        return self.__movie_genre
