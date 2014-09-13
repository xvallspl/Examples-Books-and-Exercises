#Implement an algorithm to determine if a string has all unique characters. What if you cannot use
#additional data structures? 

#Supposed: ASCII character set. 

def isUniqueChars2(str):
	if len(str>128):
		return False
	char_set = [False] * 256
	for i in str:
		if char_set[ord(i)]:
			return False
		char_set[ord(i)]=True
	return True