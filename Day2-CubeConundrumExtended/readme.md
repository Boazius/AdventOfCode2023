# Cube Conundrum - Part Two

## Description
Continuing from the previous task, the objective now is to determine, for each game played, the minimum number of cubes of each color that could have been present in the bag to make the game possible.

## Task
Find the minimum set of cubes required for each game such that it would have been possible to play the game with those cube counts. Calculate the sum of the powers of these sets.

## Example
Considering the same set of games:
- Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
- Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
- Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
- Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
- Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green

The minimum set of cubes for each game:
- Game 1: 4 red, 2 green, 6 blue
- Game 2: 1 red, 3 green, 4 blue
- Game 3: 20 red, 13 green, 6 blue
- Game 4: 14 red, 3 green, 15 blue
- Game 5: 6 red, 3 green, 2 blue

The power (product of red, green, and blue cubes) for these minimum sets:
- Game 1: 48
- Game 2: 12
- Game 3: 1560
- Game 4: 630
- Game 5: 36

Summing up these powers results in 2286.
