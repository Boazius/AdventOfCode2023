# Cube Conundrum

## Description
Given a set of games where cubes of different colors are revealed from a bag, this task involves identifying which games are possible if the bag contained specific numbers of red, green, and blue cubes.

## Task
The goal is to determine the possible games if the bag had 12 red cubes, 13 green cubes, and 14 blue cubes. Calculate the sum of the IDs of those possible games.

## Example
For instance, considering games with cube subsets revealed:
- Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
- Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
- Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
- Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
- Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green

If the bag contained 12 red cubes, 13 green cubes, and 14 blue cubes, games 1, 2, and 5 would have been possible. Games 3 and 4 would have been impossible due to the cube counts revealed in the games.

The sum of the IDs of the possible games (1, 2, and 5) would be 8.
