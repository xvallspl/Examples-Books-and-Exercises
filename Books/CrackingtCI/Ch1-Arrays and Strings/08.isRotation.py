# Assume you have a method isSubstring which checks if one word is a substring of 
# another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using 
# only one call to isSubstring (i.e., "waterbottle"is a rotation of "erbottlewat").


def isSubstring(s1, s2):
	return s2 in s1

def theirIsRotation(string1, string2):
	if len(string2)==len(string1) and len(string1)>0:
		s1s1 = string1+string1
		return isSubstring(s1s1, string2)
	return False 

if __name__ == '__main__':
	print "Is ojaj rotation of joja? ", theirIsRotation("ojaj","joja")
	print "Is ajjo rotation of joja? ", theirIsRotation("ajjo","joja")