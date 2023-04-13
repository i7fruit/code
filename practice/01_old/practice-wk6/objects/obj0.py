#obj0.py
# Wed, 02.06.19 10:00hrs

# creates a Student class
class Student():
    def __init__(self, name, id):
        self.name = name
        self.id = id

    def changeID(self, id):
        self.id = id

    def print(self):
        print("{} - {}".format(self.name, self.id))

# creates an object jane
jane = Student("Jane", 10)

# changes name property
jane.name = "John"

# changes ID property
jane.changeID(3)

jane.print()