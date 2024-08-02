### time and space complexity analysis these linked list implementations

#### singly linked list:
- insert_at_head():
    - both time and space complexity is constant $O(1)$ because the head node can be found instantly and the list itself is not copied

- insert_at_tail():
    - time complexity is $O(n)$ because we have to traverse through $n$ nodes to get to the end of the list
    - space complexity is constant $O(1)$ because no memory in the existing list is copied 

- delete_node():
    - time complexity is $O(n)$ in the worst case (when the last node is to be deleted)
    - space complexity is constant $O(1)$ because no memory in the existing list is copied 

- search():
    - time complexity is $O(n)$ in the worst case (when the last node is being searched for)
    - space complexity is constant $O(1)$ because no memory in the existing list is copied 

- print_list():
    - time complexity is $O(n)$ because we have to traverse through the entire list of $n$ nodes
    - space complexity is constant $O(1)$ because no memory in the existing list is copied 

- the overall space complexity is $O(n)$ where $n$ is the number of nodes in the list

#### doubly linked list vs singly linked list:
- each node has an additional pointer to the previous node so we can now traverse the list in both directions (forward and backwards instead of just forwards)
- the list now maintains both head and tail pointers
- insert_at_tail() is now has a constant time complexity $O(1)$ instead of a linear time complexity $O(n)$ because we don't have to traverse through the list to find the last node
- delete_node() is slightly more efficient since we can easily access the previous node

#### circular linked lists vs singly linked list:
- the last node points back to the first node, creating a circle
- there is no NULL termination so we use the head node as a termination condition when traversing forwards through the list
- insertion and deletion operations need to handle the circular nature of the list
