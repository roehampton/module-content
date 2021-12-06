# Longest Zig-Zag subsequence in an list - adapted from https://www.geeksforgeeks.org/longest-zig-zag-subsequence/

# Function to return longest
# Zig-Zag subsequence length
def zzis(arr, n):
	
	'''Z[i][0] = Length of the longest Zig-Zag subsequence
		ending at index i and last element is greater
		than its previous element
	Z[i][1] = Length of the longest Zig-Zag subsequence
		ending at index i and last element is smaller
		than its previous element '''
	Z = [[1 for i in range(2)] for i in range(n)]


	res = 1 # Initialize result

	# Compute values in bottom up manner '''
	for i in range(1, n):
		
		# Consider all elements as previous of arr[i]
		for j in range(i):

			# If arr[i] is greater, then check with Z[j][1]
			if (arr[j] < arr[i] and Z[i][0] < Z[j][1] + 1):
				Z[i][0] = Z[j][1] + 1

			# If arr[i] is smaller, then check with Z[j][0]
			if( arr[j] > arr[i] and Z[i][1] < Z[j][0] + 1):
				Z[i][1] = Z[j][0] + 1

		# Pick maximum of both values at index i '''
		if (res < max(Z[i][0], Z[i][1])):
			res = max(Z[i][0], Z[i][1])

	return res

# Driver Code
arr = [10, 22, 9, 33, 49, 50, 31, 60]
n = len(arr)
print("Length of Longest Zig-Zag subsequence is",
									zzis(arr, n))
