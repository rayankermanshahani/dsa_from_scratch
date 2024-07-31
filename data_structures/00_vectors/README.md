### time and space complexity analysis this vector (dynamic array) implementation

time complexity:
- insert(): $O(1)$ when there is space in the vector, $O(n)$ in the worst case when vector capacity is reached and resizing is needed
- get(): $O(1)$ because we simply index once into the array
- resize(): $O(n)$ because we need to make a full copy of all the data into a new array
- delete(): $O(n)$ in the worst case (we remove the first element) because we shift over all the remaining $n$ elements

space complexity:
- $O(n)$ where $n$ is the number of elements in the vector
