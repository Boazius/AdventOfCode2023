
## Task

- You have a list of seeds and a series of conversion maps (seed-to-soil, soil-to-fertilizer, etc.).
- Each line in a map contains three numbers: destination range start, source range start, and range length.
- Convert each seed number through the categories to find its corresponding location number.

## Example

Seeds: `79 14 55 13`

Seed-to-soil map:
```
50 98 2
52 50 48
```
... (other maps follow)

- Find the soil number for each seed.
- Continue the conversion through the maps until you reach the location numbers.
- Determine the lowest location number for the initial seeds.

## Input/Output

- [input] list of seeds
- [input] conversion maps
- [output] integer: the lowest location number corresponding to any of the initial seeds.