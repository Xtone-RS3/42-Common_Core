class Plant(object):
    def __init__(self, name, height, age, period=0):
        self.name = name
        self.height = height
        self.age = age

    def create(self):
        print(f"Created: {self.name} ({self.height}cm, {self.age} days)")

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
        print("=== Day ", elapsing_days, " ===", sep="")
        self.get_info()
        print("Growth this week: +", self.height - start_height, "cm", sep="")


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    rose = Plant("Rose", 25, 30).create()
    oak = Plant("Oak", 25, 30).create()
    cactus = Plant("Cactus", 25, 30).create()
    sunflower = Plant("Sunflower", 25, 30).create()
    fern = Plant("Fern", 25, 30).create()
