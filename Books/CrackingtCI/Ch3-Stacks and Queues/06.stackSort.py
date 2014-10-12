# Write a program to sort a stack in ascending order You should not make any assumptions
# about how the stack is implemented. 
# The following are the only functions that should be used to write this program: 
# push | pop | peek | isEmpty

from random import randint

class Stack:

	def __init__(self):
		self.items=[]

	def pop(self):
		if not self.isEmpty():
			return self.items.pop()
		return None

	def push(self, n):
		self.items.append(n)

	def isEmpty(self):
		return self.items==[]

	def peek(self):
		if(self.isEmpty()):
			return None
		return self.items[-1]


def sortStack(stack):
	sortedStack = Stack();
	aux = stack.pop()
	while aux!=None:
		if aux < sortedStack.peek():
			stack.push(sortedStack.pop())
		else:
			sortedStack.push(aux)
			aux = stack.pop()

	while not sortedStack.isEmpty():
		stack.push(sortedStack.pop())

if __name__ == '__main__':

	s1 = Stack()
	for i in xrange(10):
		s1.push(randint(0,10))
	sortStack(s1)

	while not s1.isEmpty():
		print "%d " %s1.pop(),
	print "\n"
