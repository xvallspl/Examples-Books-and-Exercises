# Given a (decimal - e.g. 3.72) number that is passed in as a string, print the binary 
# representation. If the number can not be represented accurately in binary, print "ERROR"

#Too curious to not look it up

def theirDecimal2Binary(number):
	c=number.split(".")

	intPart=int(c[0])
	int_string=""
	dec_string=""
	while intPart>0:
		int_string = str(intPart%2)+int_string
		intPart>>=1

	if len(c)==1: return int_string
	
	decPart=float(c[1])/ 10**len(c[1])
	print decPart
	while decPart>0:
		if len(dec_string)>32: return "ERROR"
		if decPart ==1:
			dec_string+="1"
			break
		decPart*=2
		if decPart>=1:
			dec_string+="1"
			decPart-= 1
		else:
			dec_string+="0"

	return int_string+"."+dec_string



if __name__ == '__main__':
	print 	theirDecimal2Binary("2.2")
