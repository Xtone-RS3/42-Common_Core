class Plant(object):
    def __init__(self, name, height=0, age=0):
        self.__name = name
        self.__height = height
        self.__age = age

    def get_name(self):
        return self.__name

    def get_height(self):
        return self.__height

    def get_age(self):
        return self.__age

    def get_info(self):
        print(f"Plant: {self.get_name()} ({self.get_height()}cm, {self.age} days)")


class Flower(Plant):
    def __init__(self, name, color, height=0, age=0):
        super().__init__(name, height, age)
        self.__color = color

    def bloom(self):
        print(f"{self.get_name()} is blooming beautifully!")

    def get_info(self):
        print(f"{self.get_name()} (Flower): {self.get_height()}cm, {self.get_age()} days, {self.__color} color")


class Tree(Plant):
    def __init__(self, name, trunk_diameter, shade_sq, height=0, age=0):
        super().__init__(name, height, age)
        self.__trunk_diameter = trunk_diameter
        self.__shade_sq = shade_sq

    def produce_shade(self):
        print(f"{self.get_name()} provides {self.__shade_sq} square meters of shade")

    def get_info(self):
        print(f"{self.get_name()} (Tree): {self.get_height()}cm, {self.get_age()} days, {self.__trunk_diameter}cm diameter")


class Vegetable(Plant):
    def __init__(self, name, harvest_season, nutritional_value, height=0, age=0):
        super().__init__(name, height, age)
        self.__harvest_season = harvest_season
        self.__nutritional_value = nutritional_value

    def get_info(self):
        print(f"{self.get_name()} (Vegetable): {self.get_height()}cm, {self.get_age()} days, {self.__harvest_season} harvest")

    def nut_value(self):
        print(f"{self.get_name()} is rich in vitamin {self.__nutritional_value}")


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print()
    rose = Flower("Rose", "red", 25, 30)
    rose.get_info()
    rose.bloom()
    print()
    oak = Tree("Oak", 50, 78, 500, 1825)
    oak.get_info()
    oak.produce_shade()
    print()
    tomato = Vegetable("Tomato", "summer", "C", 80, 90)
    tomato.get_info()
    tomato.nut_value()
