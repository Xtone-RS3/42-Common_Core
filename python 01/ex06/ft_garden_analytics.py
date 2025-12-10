class Plant(object):
    def __init__(self, owner, name="", height=0, age=0):
        self.__name = name
        self.__owner = owner
        self.__height = height
        self.__age = age

    def create(self):
        print(f"Added {self.__name} to {self.__owner}'s garden")

    def get_name(self):
        return self.__name

    def get_height(self):
        return self.__height

    def growth(self):
        self.__height = self.__height + 1
        print(f"{self.__name} grew 1cm")
        return self.__height

    def get_age(self):
        return self.__age

    def get_info(self):
        print(f"Plant: {self.get_name()} ({self.get_height()}cm, {self.get_age()} days)")


class FloweringPlant(Plant):
    def __init__(self, owner, name, color, height=0, age=0):
        super().__init__(owner, name, height, age)
        self.__color = color

    def bloom(self):
        print(f"{self.get_name()} is blooming beautifully!")

    def get_color(self):
        return self.__color

    def get_info(self):
        print(f"{self.get_name()} (Flower): {self.get_height()}cm, {self.get_age()} days, {self.get_color()} color")


class PrizeFlower(FloweringPlant):
    def __init__(self, owner, name, prize, color="", height=0, age=0):
        super().__init__(owner, name, color, height, age)
        self.__prize = prize

    def get_prize(self):
        return self.__prize

    def get_info(self):
        print(f"{self.get_name()} (Flower): {self.get_height()}cm, {self.get_age()} days, {self.get_color()} color, prize points {self.get_prize()}")


class GardenManager:
    _gardens = {}
    _network = {}

    def __init__(self, owner):
        self.owner = owner
        self.plants = {}
        self.total_growth = 0
        self.score = 0
        GardenManager._gardens[owner] = self

    @classmethod
    def create_garden_network(cls):
        cls._network = {
            owner: list(gard.plants.keys())
            for owner, gard in cls._gardens.items()
        }
        return cls._network

    def add_plant(self, plant):
        print(f"Added {plant.get_name()} to {self.owner}'s garden")
        self.plants[plant.get_name()] = plant
        if type(plant).__name__ == "PrizeFlower":
            self.score += plant.get_prize()

    def grow_plants(self):
        print(f"{self.owner} is helping all plants grow...")
        for plant in self.plants:
            self.plants[plant].growth()
            self.total_growth = self.total_growth + 1

    class GardenStats:
        def __init__(self, garden):
            self._garden = garden

        def total_height(self):
            print(f"Garden total height: {sum(plant.get_height() for plant in self._garden.plants.values())}")

        def count(self):
            print(f"Plants added: {len(self._garden.plants)}, Total growth: {self._garden.total_growth}cm")

        def type_info(self):
            t1 = 0
            t2 = 0
            t3 = 0
            for plant in self._garden.plants.keys():
                if type(self._garden.plants[plant]).__name__ == "Plant":
                    t1 = t1 + 1
                elif type(self._garden.plants[plant]).__name__ == "FloweringPlant":
                    t2 = t2 + 1
                elif type(self._garden.plants[plant]).__name__ == "PrizeFlower":
                    t3 = t3 + 1
            print(f"Plant types: {t1} regular, {t2} flowering, {t3} prize flower")

        def stats_report(self):
            print("Plants in garden: ")
            for plant in self._garden.plants.keys():
                Case = self._garden.plants[plant]
                if type(Case).__name__ == "Plant":
                    print(f"- {plant}: {Case.get_height()}cm")
                elif type(Case).__name__ == "FloweringPlant":
                    print(f"- {plant}: {Case.get_height()}cm, {Case.get_color()} flowers (blooming)")
                elif type(Case).__name__ == "PrizeFlower":
                    print(f"- {plant}: {Case.get_height()}cm, {Case.get_color()} flowers (blooming), Prize points: {Case.get_prize()}")



if __name__ == "__main__":
    print("=== Garden Management System Demo ===")
    print()
    alice_garden = GardenManager("Alice")
    bob_garden = GardenManager("Bob")
    alice_garden.create_garden_network()
    alice_garden.add_plant(Plant("Alice", "Oak Tree", 100, 1825))
    alice_garden.add_plant(Plant("Alice", "Birch Tree", 500, 10))
    alice_garden.add_plant(FloweringPlant("Alice", "Rose", "red", 25, 30))
    alice_garden.add_plant(PrizeFlower("Alice", "Sunflower", 10, "yellow", 50, 10))
    print()
    alice_garden.grow_plants()
    print()
    print("=== Alice's Garden Report ===")
    GardenManager.GardenStats(alice_garden).stats_report()
    print()
    GardenManager.GardenStats(alice_garden).count()
    GardenManager.GardenStats(alice_garden).type_info()
    print()
    print(f"Garden scores:")
    for owner in GardenManager._gardens.keys():
        print(f" - {owner}: {GardenManager._gardens[owner].score}")
    print(f"Total gardens managed: {len(GardenManager._gardens)}")
