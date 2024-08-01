### time and space complexity analysis these string operation implementations

reverse_string:
- time complexity is $O(n)$ where $n$ is the length of the string because we have to iterate through each character in the string
- space complexity is $O(1)$ because the operation is performed in-place

is_palindrome:
- time complexity is $O(n)$ where $n$ is the length of the string beacuase we have to iterate through each character in the string
- space complexity is $O(1)$ because the operation is performed in-place

find_substring (naive implementation):
- time complexity is $O(m * n)$ where $m$ is the length of the main string and $n$ is the length of the substring because there is full looping through each character of both strings
- space complexity is $O(1)$ because no memory is copied 

find_substring_kmp (KMP algorithm):
- explanatation: 
    - a more efficient string matching algorithm that uses information about the substring itself to minimize the number of uneccessary comparisons made during its execution 
    - it precomputes information about the substring to determine how much to skip ahead in the string being matched against whenever a mismatch occurs
    - whenever there is a mismatch we don't need to start over from the beginning of the pattern
- time complexity is linear $O(m+n)$ where $n$ is the length of the string and $m$ is the length of the substring (pattern) which is much more efficient than the naive $O(m * n)$ approach  
- space complexity is $O(m)$ for the failure function array, where $m$ is the length of the substring
