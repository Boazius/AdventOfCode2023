
# Gear Ratios

## Task
Given an engine schematic represented by numbers and symbols, find the sum of all part numbers in the schematic. Part numbers are any numbers adjacent to a symbol, including diagonally. Periods (.) do not count as symbols.

## Example
Consider this engine schematic snippet:
```
467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..
```
In this example, two numbers (114 and 58) are not part numbers as they are not adjacent to a symbol. The sum of the other adjacent numbers, considered part numbers, is 4361.

The actual engine schematic might be much larger. Your task is to calculate the sum of all part numbers within the given engine schematic.