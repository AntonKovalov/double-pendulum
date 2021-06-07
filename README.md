**Concept**  
This repository contains an attempt to simulate physics of double pendulum system. It is done for educational purposes only.   
PDEs used to solve this problem are taken from the MIT webpage(linked below):  

https://web.mit.edu/jorloff/www/chaosTalk/double-pendulum/double-pendulum-en.html  

More on this particular system can be researched on the aforementioned resource or elsewhere.  

**Usage and outline**  
All source files are located in the src directory.  
init.h - contains most of the configuration variables like simulation time, length of elements, mass of elements, and descritization constatns.  
Commenting or uncommenting EULER/ RUNGEE-KUTTA definitions will result in either one methods to solve the system.  
Other solution algorithms can be added easily by declaring them in methods.h and implementing in methods.c .  
Please also add definitions of corresponding methods to init.h, and wrap their calls in corresponding preprocessing guards.  

After starting the program, please enter 4 values - theta_1, theta_2, omega_1, omega_2, as this is the initial value problem.  
If succesfully run, the output file data.xlsx will appear in project root directory.  
data.xlsx - column notations (t - time, a - angle, x - x position, y - y posistion)  

**Build**  
Requires gcc for building, and gnu make utility.  
If none, run the following in the command line:  
`brew install autoconf automake libtool`  

then simply cd into the project directory, where Makefile is located and run:  
`make`  
`./double-pendulum`

