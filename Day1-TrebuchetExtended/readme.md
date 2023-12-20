# Day 1: Trebuchet?!

## Task Description

The document consists of lines of text; On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.


For example:

- `1abc2` gives a calibration value of 12.
- `pqr3stu8vwx` gives a calibration value of 38.
- `a1b2c3d4e5f` gives a calibration value of 15.
- `treb7uchet` gives a calibration value of 77.

The task is to consider the entire calibration document and calculate the sum of all the calibration values.

### Extension:
It looks like some of the digits are actually spelled out with letters: one, two, three, four, five, six, seven, eight, and nine also count as valid "digits".

Equipped with this new information, you now need to find the real first and last digit on each line. For example:

```plaintext
two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen
```
In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76. Adding these together produces 281.