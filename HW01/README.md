Name: Jason Moss
Date: 9-12-23
Description: This assignment takes user input to create a vector.
1. In order to use the copy contructor, a valid vector must be created. Then call the copy constructor like Vector myVec(other).
This copies the data from other to the new vector.
2. In order to get the size of the vector, use myVec.size();.
3. Do the same thing for capacity. Use myVec.capacity();.
4. In order to use psuhback, do myVec.pushback(number). Number is a placeholder for the number you are going to enter.
5. In order to use reserve, do myVec.reserve(number). Again, number is just a placholder for the number you are going to enter.
6. Use setVec to put data into your vector. Use myVec.setVec(size, capacity). The two variable will be recieved by user input.
In the program, I tested the copy constructor by using setVec to put data into the other vector. I then called the copy constructor when I declared the myVec vector. I then printed the contents of both vectors.
I tested the I tested the pushback function by calling it and then printing out the vector contents.
I tested the reserve function by calling it. I then used the .capacity function to print out the capacity. I also tested to see if would do nothing if I tried to decrease the capacity.
Throughout all these tests, I was teasting to see if my << overload worked.
