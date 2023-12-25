# Seed Mapping Challenge Part 2

Given a series of maps that convert ranges of seed numbers through various categories, determine the lowest location number that corresponds to any seed in the given ranges.

## Task

- The `seeds:` line describes ranges of seed numbers, each range given as a start number and length.
- Convert each seed number through the categories (seed-to-soil, soil-to-fertilizer, etc.) to find its corresponding location number.
- Consider all seeds in the given ranges and determine the lowest location number.

## Example

Seeds: `79 14 55 13`

This describes two ranges:
- First range: seeds 79 to 92 (14 seeds).
- Second range: seeds 55 to 67 (13 seeds).

Seed-to-soil map:
```
50 98 2
52 50 48
```
... (other maps follow)

- Convert each seed number in the ranges through the maps to find location numbers.
- Determine the lowest location number for all seeds in the ranges.

## Input/Output

- [input] list of seed ranges
- [input] conversion maps
- [output] integer: the lowest location number corresponding to any seed in the ranges.