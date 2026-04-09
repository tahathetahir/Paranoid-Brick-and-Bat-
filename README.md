# Paranoid : Brick-and-Bat
Paranoid is an arcade game built in C++ inspired by the classic Breakout genre. The game features smooth ball physics, multiple brick types, power-ups, and progressively increasing difficulty. This code relies completely on hard coded logic to render graphics thus exploring the fundamental logic of graphic and rendering. </br>

## Graphics 
This project employs graphics and console libraries that are also custom made. The aim was to understand the core dynamics and fundamentals of rendering logic from scratch without the use of pre-defined libraries. In simpler words, the entire game is made with circles and rectangles of different sizes, rendered programmatically across screen. Certain techniques have been employed to create the simulate motion of ball and breaking of bricks. Graphics Libraries are implemented using C language tools. </br>

## Project Structure
paranoid/ </br>
├── main.cpp          # Core game loop, physics, rendering, collision </br>
├── mygraphics.h      # Custom graphics rendering (rectangles, ellipses, text, lines) </br>
├── myconsole.h       # Console input handling </br>

## Tech Stack 
Language: C++ </br>
Graphics: Custom mygraphics.h and myconsole.h libraries (Windows GDI-based rendering)
Platform: Windows </br>
Dependencies: Windows.h, conio.h, cmath, fstream, time.h </br>

## Gameplay
The player controls a bat (paddle) at the bottom of the screen using the A and D keys to move left and right. A ball bounces around the screen, and the objective is to destroy all bricks in the grid without letting the ball fall past the bat. The player starts with 3 lives, and loses one each time the ball hits the ground. The game ends when all lives are lost. </br>

## How to Run
Clone the repository on a Windows/Linux machine.</br>
Ensure mygraphics.h and myconsole.h are in the same directory as main.cpp.</br>
Ensure that implementations mygraphics.h and myconsole.h namely, mygraphics.cpp and myconsole.cpp are also in same directory as main.cpp </br>
Build and run the project using any compiler or C++ IDE (preferably Visual Studio Code).</br>

## Controls of Game 
| Key  | Action |
| ------------- | ------------- |
| A | Move Bar Left  |
| D | Move Bar Right |
| P | Pause/Resume  |
| Q | Quit game  |
| S | Start Game (From Menu)  |
| I | View Instructions (From Menu)  |
| L | Continue after Life Lost  |
| M | Return to menu (After game over)  |
| B | Back (from Instructions)  |

