class Plant(object):
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def get_info(self):
        print(f"{self.name}: {self.height}cm, {self.age} days old")


if __name__ == "__main__":
    print("=== Garden Plant Registry ===")
    rose = Plant("Rose", 25, 30)
    rose.get_info()
    sunflower = Plant("Sunflower", 80, 45)
    sunflower.get_info()
    cactus = Plant("Cactus", 15, 120)
    cactus.get_info()
