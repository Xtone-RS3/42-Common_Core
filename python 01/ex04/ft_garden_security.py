class SecurePlant(object):
    def __init__(self, name, height=0, age=0, value=0):
        self.__name = name
        self.__height = height
        self.__age = age

    def create(self):
        print(f"Created: {self.__name}")

    def get_info(self):
        print(f"Current plant: {self.__name} ({self.__height}cm, {self.__age}\
 days)")

    def set_height(self, value):
        if value < 0:
            print(f"Invalid operation attempted: height {value}cm [REJECTED]")
            print("Security: Negative height rejected")
        else:
            self.__height = value
            print("Height updated: ", value, "cm [OK]", sep="")
        return self.__height

    def set_age(self, value):
        if value < 0:
            print(f"Invalid operation attempted: age {value} days [REJECTED]")
            print("Security: Impossible age rejected")
        else:
            self.__age = value
            print("Age updated: ", value, " days [OK]", sep="")
        return self.__age

    def get_height(self):
        return self.__height

    def get_age(self):
        return self.__age


if __name__ == "__main__":
    print("=== Garden Security System ===")
    rose = SecurePlant("Rose")
    rose.create()
    rose.set_height(25)
    rose.set_age(30)
    print()
    rose.set_height(-5)
    print()
    rose.get_info()
    # oak = Plant("Oak", 25, 30).create()
    # cactus = Plant("Cactus", 25, 30).create()
    # sunflower = Plant("Sunflower", 25, 30).create()
    # fern = Plant("Fern", 25, 30).create()
