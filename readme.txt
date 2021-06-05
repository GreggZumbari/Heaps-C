# Heaps Project for C Explained
# Greggory Hickman, hickmang@oregonstate.edu
# June 2021

## pq_create()

This function should allocate memory to, and return a pq pointer.

## pq_free()

This function should free the memory of a malloc'd pq pointer.

## pq_isempty()

For this function, I check to see if the dynarray's length is 0. If so, then I know that the pq is empty.

This function should return a 1 if the pq is empty, and a 0 is not.

## pq_insert()

For the insert function, I parse the passed-in information into my "element" struct, then put that element in the last address of the dynarray.
Then, I check to see if the new element's priority is larger than it's parent element. If so, then I swap the parent and current elements.
I then repeat this process over and over again until either the element's parent has a higher priority value or the element has made it's way to the top of the heap.

This function should add a new element to the pq, and place it in it's natural place according to its priority.

## pq_max()

For this function, I know that the element with the highest priority will always be on the top of the heap. 
So, I just return the data from the 0'th element of the dynarray.

This function should return the data of the element at the top of the pq.

## pq_max_priority()

For this function, I use the exact same code as the pq_max() function, except instead of returning the node's data, I return the node's priority.

This function should return the priority of the element at the top of the pq.

## pq_max_dequeue()

For the dequeue function, I first save the root's value for later when it needs to be returned.
Then, I take the last element in the list and put it at the top of the heap.
Then, I check to see if the element has a lower priority value than either of its children, checking the left, then the right child.
If so, I swap the element with whichever child has a larger priority.
I then repeat this process until either the element has a higher priority value than both of its children, 
or it has one child with a lower priority value, or it has no children.

This function should return the root's value, then seamlessly remove the root, moving the heap's values around to accomodate.