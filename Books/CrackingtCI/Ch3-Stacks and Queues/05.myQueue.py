#Implement a MyQueue class which implements a queue using two stacks.

#No-sized stack

class Stack:

    def __init__(self):
        self.items=[]

    def pop(self):
        if(self.items!=[]):
            return self.items.pop()
        return None

    def push(self, n):
        self.items.append(n)

    def isEmpty(self):
        return self.items==[]

    def peek(self):
        if self.isEmpty:
            return None
        return self.items[-1]

class MyQueue:

    def __init__(self):
        self.stackIn = Stack()
        self.stackOut = Stack()

    def pop(self):
        self.move(self.stackIn, self.stackOut)
        return self.stackOut.pop()

    def push(self, n):
        self.move(self.stackOut, self.stackIn)
        self.stackIn.push(n)

    def move(self, src, dest):
        aux = src.pop()
        while aux!= None:
            dest.push(aux)
            aux = src.pop()
        dest.push(aux)

    def peek(self):
        self.move(self.stackIn, self.stackOut)
        return self.stackOut.peek()

class TheirQueue:

    def __init__(self):
        self.stackIn = Stack()
        self.stackOut = Stack()

    def pop(self):
        if not stackOut.isEmpty():
            return stackOut.pop()
        self.move(self.stackIn, self.stackOut)
        return self.stackOut.pop()

    def push(self, n):
        self.stackIn.push(n)

    def move(self, src, dest):
        while not src.isEmpty():
            dest.push(src.pop())

    def peek(self):
        if not stackOut.isEmpty():
            return stackOut.pop()
        self.move(self.stackIn, self.stackOut)
        return self.stackOut.pop()
