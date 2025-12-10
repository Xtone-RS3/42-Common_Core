class Plant(object):
    def __init__(self, name, height, age, period=0):
        self.name = name
        self.height = height
        self.age = age

    def get_info(self):
        print(f"{self.name}: {self.height}cm, {self.age} days old")

    def grow(self):
        self.height = self.height + 1

    def age_verb(self):
        self.age = self.age + 1

    def simulate(self, period):
        print("=== Day 1 ===")
        self.get_info()
        start_height = self.height
        elapsing_days = period
        while (period != 1):
            self.grow()
            self.age_verb()
            period = period - 1
        print(f"=== Day {elapsing_days} ===")
        self.get_info()
        print(f"Growth this week: + {self.height - start_height}cm")


if __name__ == "__main__":
    # print("=== Garden Plant Registry ===")
    # rose = Plant("Rose", 25, 30)
    # rose.get_info()
    sunflower = Plant("Sunflower", 80, 45)
    sunflower.simulate(period=7)
    # sunflower.get_info()
    # cactus = Plant("Cactus", 15, 120)
    # cactus.get_info()
