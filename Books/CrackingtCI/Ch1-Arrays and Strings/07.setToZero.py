# Write an algorithm such that if an element in an MxN matrix is 0, its entire row and 
# column is set to 0.

#(This could be cheating)

def mySetToZeroFromPaperToWork(mat, M, N):
	rows = []
	cols = []

	for i in xrange(M):
		for j in xrange(N):
			if mat[i][j]==0:
				rows.append(i)
				cols.append(j)
	for row in xrange(M):
		if row in rows:
			mat[row]=[0]*N 
		for col in cols:
			mat[row][col]=0

if __name__ == '__main__':

	M = [[1,2,3,4,0],
		 [5,6,7,8,0],
		 [9,8,10,11,12],
		 [13,14,0,15,16]]
	print "Input: ", M
	mySetToZeroFromPaperToWork(M,4,5)
	print "myOutput:", M
	