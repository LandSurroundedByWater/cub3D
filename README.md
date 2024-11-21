# cub3D - RayCaster with MLX42 <br/>

![3t7w9u](https://github.com/user-attachments/assets/ec97717a-0523-4413-8750-0fd8e0405ad2)


This game was made with https://github.com/Pik-kak


This was an amazing journey to make a raycasting game like Wolfenstein 3D form 1992. We made this game from scratch
using raycasting an DDA (Digital Differential Analyzer) algorihms to count the size of wall we have to draw. 
Raycasting makes it possibele to illustrate 3D world for 2D game. Player is really in basic 2D-map which has
walls, ground and floor blocks (check the maps in test_maps folder, there is also our textures and floor and ceilig colours);
By calculating the width of several rays pointed from player to width of view we draw a vision how it would look like if 
player would be in 3D world. 

Instructions for linux ubuntu:

- Download repository
- Go to repository folder
- Execute command "make bonus"
- Execute command "./cub3D test_maps/bonus/test_file_door.cub"
- have fun :)

- There is also mandatory version without doors and with not so cute textures - command is "make" and maps are in "test_maps/mandatory/..."
- Feel free to chenge maps if you like -  1 is wall, 0 is ground, 2 is door




These were the subject rules what we had to do:

You must create a “realistic” 3D graphical
representation of the inside of a maze from a
first-person perspective. You have to create this
representation using the Ray-Casting principles.

The constraints are as follows:
- You must use the miniLibX or MLX42.
- The management of your window must remain smooth: changing to another window, minimizing, etc.
- Display different wall textures (the choice is yours) that vary depending on which
side the wall is facing (North, South, East, West).
- Your program must be able to set the floor and ceiling colors to two different ones.
- The program displays the image in a window and respects the following rules:
- The left and right arrow keys of the keyboard or mouse must allow you to look left and
right in the maze.
- The W, A, S, and D keys must allow you to move the point of view through
the maze. 
-  Pressing ESC must close the window and quit the program cleanly.
