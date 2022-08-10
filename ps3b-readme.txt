/**********************************************************************
 *  N-Body Simulation ps3b-readme.txt template
 **********************************************************************/

Name: Ronney Sanchez
OS: Windows
Machine (e.g., Dell Latitude, MacBook Pro):
Text editor: VI text Editor
Hours to complete assignment: 5 hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In the assignment I created the sun and four other planets within the universe.
I made the planets rotate around the sun acting upon the force of the other
planets and the gravity constant. My universe rotates counter-clockwise
in a perfect circle around the sun.

/**********************************************************************
 *  If you created your own universe for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
For my own universe, I replaced the sun with a blackhole and instead of
using the 4 inner planets, I used the 4 outer planets which is from jupiter
to neptune. However, the universe state does not start linear. I printed
the final state of the universe from my regular simulation and wrote it
to another text file and used that final state as my start state for my
own universe. The planets starts circular instead of linear.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I received help from Dr. Wilkes with the automatic file read input from
the command line argument.

I also received help with my animation from Patrick Fuller (a classmate).
He helped me with my calculations of the forces of each planet and the
positioning of the universe.
/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
The problem I encountered with was that at first, my planets were not
rotating around the sun. My planets had its own rotation spot in the window
and each planet was making random circle rotation around the window.
The problem was that there was a simple mis-calculation in my class
file, but I got it fixed.

The other issue I had was that I over wrote code at first because I was using
a file input stream when I only just needed to overload the cin operator.
I was storing everything from a file pointer and using a vector to read text
from the file pointer.

I then went back and simplified it further with the overload cin operator.
/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Make sure that you have headphones to hear the music with this animation.
The sound with the speakers will sound very low but with headphones, the
sound will be a lot higher.
