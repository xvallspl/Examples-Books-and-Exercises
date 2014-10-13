#classmethod and staticmethod use case. Code from the answer here: http://stackoverflow.com/a/14605349 and http://stackoverflow.com/a/12179752.

class Date:
  def __init__(self, month, day, year):
    self.month = month
    self.day   = day
    self.year  = year

  def display(self):
    return "{0}-{1}-{2}".format(self.month, self.day, self.year)

  @staticmethod
  def millenium(month, day):
    return Date(month, day, 2000)



class DateTime(Date):
  def display(self):
      return "{0}-{1}-{2} - 00:00:00PM".format(self.month, self.day, self.year)



class DateTime2(Date):
  def display(self):
      return "{0}-{1}-{2} - 00:00:00PM".format(self.month, self.day, self.year)

  @classmethod
  def millenium(cls, month, day):
    return cls(month, day, 2000)



new_year = Date(1, 1, 2013)               # Creates a new Date object
millenium_new_year = Date.millenium(1, 1) # also creates a Date object. 

# Proof:
new_year.display()           # "1-1-2013"
millenium_new_year.display() # "1-1-2000"

isinstance(new_year, Date) # True
isinstance(millenium_new_year, Date) # True




datetime1 = DateTime(10, 10, 1990)
datetime2 = DateTime.millenium(10, 10)

isinstance(datetime1, DateTime) # True
isinstance(datetime2, DateTime) # False

datetime1.display() # returns "10-10-1990 - 00:00:00PM"
datetime2.display() # returns "10-10-2000" because it's not a DateTime object but a Date object. Check the implementation of the millenium method on the Date class



datetime3 = DateTime2(10, 10, 1990)
datetime4 = DateTime2.millenium(10, 10)

isinstance(datetime3, DateTime) # True
isinstance(datetime4, DateTime) # True


datetime3.display() # "10-10-1990 - 00:00:00PM"
datetime4.display() # "10-10-2000 - 00:00:00PM"
