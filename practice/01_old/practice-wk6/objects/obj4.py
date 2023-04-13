# obj4.py
# Mon, 02.18.19 13:40hrs

class Car():
    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year

    def change_year(self, year):
        self.year = year

veh0 = Car(input("Brand: "), input("Model: "), int(input("Year: ")))

# Prints car name
print(veh0.brand)
# Prints car model
print(veh0.model)
# Prints car year
print(veh0.year)

# Changes the car year
veh0.change_year(int(input("Change Value for Year: ")))
print("Year has been changed to", veh0.year)