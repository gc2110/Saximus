# The Saximus

This repository contains the scripts utilized in the creation of my senior design project, Saximus: The Saxophone Playing Robot.

The code here was used for the following:
1. To control the electromechanical components used for button pressing and tongue-simulation.
2. To put together the logic required to make playing a song feasible. 
The logic is as follows:
-Define functions and variables for notes that can be played, i.e. a G or high A on the alto saxophone. This would include things like which solenoids required pressing on buttons and for how long.
-Define when a "tongue", in this case a small servomotor, would be used to simulate the tongue actions of a person.
-Define songs according to the functions created for notes. Having defined the notes in the script, this step then required translating sheet music to the functions in the script and their designated length of playing. 
-At the start of a song, the solenoids would be reset and air tank turned on. The robot would play until the end of a song, at which point it resets its solenoids and the air tank would be turned off.

Notes:
-Since this was a unique projcet with not many examples of it done elsewhere at the time, there were various obstacles to overcome, i.e. how to get a material strong and flexible enough to simulate human lips, controlling the tongue-to-reed action effectively, etc. 
-I learned the programming/electronics for this during Christmas break. It still took me some time throughout the spring semester to finalize the code while we obtained the necesssary electromechanical and microprocessor components. 
-Finding a method and material for the lips took up quite some time. If I could make changes to what I had done, I would have spent more time on this piece in order to have more time to do testing and make improvements. 

Files: Saximus.h, Saximus.cpp

Link to Thesis:
https://digitalcommons.bard.edu/sr-theses/966/

Thesis Abstract: 

Details on the design, construction plan, and analyses of the Saximus project will be discussed throughout this thesis. The Saximus is a saxophone-playing robot designed with lip, tongue, and finger mechanisms as well as an adjustable base, oral cavity, and air supply. In the design, the tongue, lip, and finger mechanisms are controlled via an Arduino by utilizing two servomotors and 11 solenoids. All appropriate analyses for selecting components to build the robot were completed to ensure that all motors and solenoids provide the forces necessary for their purposes, and to ensure that supports built to hold them will endure the entirety of the project. Each component is also able to meet the speed requirements necessary to play the instrument correctly. 

Throughout the construction of the Saximus, certain components were redesigned or changed entirely. Due to the nature of the project, not much was known about how different designs for components, such as the lips and oral cavity, might affect the playing ability of the robot. Therefore, any changes made towards the end will be justified toward the end of the thesis. 

It should be noted that different members of the Senior Design Group focused on different parts of this project. Lauritz David and Jose Mendez focused on manufacturing the base and finger components. Jessica Taylor focused on the design of the lip mechanism, circuit manufacturing, and managing the team’s budget. Giancarlo Lezama focused on utilizing the theory behind saxophone playing in order to assist with the design of all major components of the project, programming all electronic apparatuses, circuit design and leading the team throughout the construction process.
