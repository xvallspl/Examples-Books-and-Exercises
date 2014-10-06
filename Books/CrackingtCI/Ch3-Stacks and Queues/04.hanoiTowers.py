# In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizeswhichcanslideontoanytower Thepuzzlestartswithdiskssortedinascending order of size from top to bottom (e g , each disk sits on top of an even larger one) You have the following constraints:
# (A) Only one disk can be moved at a time
# (B) A disk is slid off the top of one rod onto the next rod
# (C) A disk can only be placed on top of a larger disk
# Write a program to move the disks from the first rod to the last using Stacks


#Had to look for clues on how to implement the recursion...

class Stack:

	def __init__(self, capacity):
		self.capacity=capacity
		self.items=[]

	def pop(self):
		if(self.items!=[]):
			return self.items.pop()
		return None

	def push(self, n):
		if(len(self.items)<self.capacity):
			self.items.append(n)
		else:
			print "Stack overflow"

class HanoiGame:

	def __init__(self, N):
		self.firstTower  = Stack(N)
		self.secondTower = Stack(N)
		self.thirdTower  = Stack(N)
		for i in xrange(N):
			self.firstTower.push(N-i)

	def moveTower(self, N, source, destination, tmp):
		if(N>0):
			self.moveTower(N-1, source, tmp, destination)
			self.moveSingle(source, destination)
			self.moveTower(N-1, tmp, destination, source)

	def moveSingle(self, source, destination):
		piece=source.pop()
		destination.push(piece)
	
	def run(self):
		self.moveTower(self.firstTower.capacity, self.firstTower, self.thirdTower, self.secondTower)
	


