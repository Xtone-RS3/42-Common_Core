class GardenManager(object):
    def __init__(self, plant_name="", water=0, sun=0):
        try:
            self.plant_name = plant_name
            if self.plant_name == "":
                raise ValueError
            print(f"Added {self.plant_name} successfully")
        except ValueError:
            print("Error adding plant: Plant name cannot be empty!")
        self.plant_name = plant_name
        self.water = water
        self.sun = sun


    def get_name(self):
        return self.plant_name


    def water_plants(self):
        self.water += 1


    def check_plant_health(self):
        try:
            if self.plant_name is None:
                raise ValueError("Error: Plant name cannot be empty")
            if 0<self.water<11:
                pass
            elif self.water>10:
                raise ValueError(f"Error checking {self.plant_name}: Water level {self.water} is too high (max 10)")
            elif self.water<1:
                raise ValueError(f"Error checking {self.plant_name}: Water level {self.water} is too low (min 1)")
            if 1<self.sun<13:
                pass
            elif self.sun>12:
                raise ValueError(f"Error checking {self.plant_name}: Sunlight hours {self.sun} is too high (max 12)")
            elif self.sun<2:
                raise ValueError(f"Error checking {self.plant_name}: Sunlight hours {self.sun} is too low (min 2)")
            print(f"{self.plant_name} healthy (water: {self.water}, sun: {self.sun})")
        except ValueError as e:
            print(e)


class GardenError(Exception):
    pass


if __name__ == "__main__":
    print("=== Garden Management System ===")
    print()
    print("Adding plants to garden...")
    tomato = GardenManager(plant_name="tomato", water=4, sun=8)
    lettuce = GardenManager(plant_name="lettuce", water=14, sun=4)
    error = GardenManager(plant_name="", water=2, sun=4)
    print()
    print("Watering plants...")
    print("Opening watering system")
    try:
        for plant in [tomato,lettuce]:
            if plant.get_name() == "":
                raise ValueError
            print(f"Watering {plant.get_name()} - success")
            plant.water_plants()
    except ValueError:
        print("Error: Cannot water None - invalid plant!")
    finally:
        print("Closing watering system (cleanup)")
    print()
    print("Checking plant health...")
    for plant in [tomato,lettuce]:
        plant.check_plant_health()
    print()
    print("Testing error recovery...")
    try:
        raise GardenError
    except GardenError:
        print("Caught GardenError: Not enough water in tank")
    finally:
        print("System recovered and continuing...")
    print()
    print("Garden management system test complete!")