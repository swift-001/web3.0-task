# web3.0-task

I imported string library to be able to use string keyword.then I took an extra parameter of t signifying the time for which car has moved.then I defined accelerate function that changes the speed in the 3 directions same is for brake function.I changed the cordinates of car by using move function.In the detect_collision function I created temporary variables to store the cordinate of cars then I updated these by calling move function for both cars.the I check if cordinates of car1 were initially less tham car 2 but after calling move function it became greater or not.if yes then they collide otherwise
not.THen in time_to_collision function i am finding minimum of the times of collision in the 3 directions.iif cars do not collide I return time of collision as -1.
