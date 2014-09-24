# Given an image represented by an NxN matrix, where each pixel in the image is 4 
# bytes, write a method to rotate the image by 90 degrees. Can you do this in place?


def myRotateLeft(m, n):
	for i in xrange(n/2):
		for j in range(i, n-i-1):
			aux=m[i][j]
			m[i][j]  = m[j][-(i+1)]
			m[j][-(i+1)] = m[-(i+1)][-(j+1)]
			m[-(i+1)][-(j+1)] = m[i][-(j+1)]
			m[-(j+1)][i] = m[-(j+1)][i]
			m[-(j+1)][i] = aux

def theirRotateRight(m, n):
	for layer in xrange(n/2):
		first = layer
		last = n-1-layer
		for i in range(first, last):
			offset = i - first
			top = m[first][i]
			m[first][i] = m[last-offset][first]; 
			m[last-offset][first] = m[last][last - offset] 
			m[last][last - offset] = m[i][last]
			m[i][last] = top

if __name__ == '__main__':
	M = [[1,2,3,4],
		 [5,6,7,8],
		 [9,10,11,12],
		 [13,14,15,16]]
	print "Input: ", M
	myRotateLeft(M,4)
	print "myOutput:", M
	theirRotateRight(M,4)
	print "theirOutput: ", M