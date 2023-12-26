# Day 8: Haunted Wasteland

You are given a network of labeled nodes with left/right instructions. Starting at node AAA, follow the instructions to reach node ZZZ. The instructions may repeat if necessary (RLRLRL...). Calculate the number of steps required to reach ZZZ from AAA.

## Examples

### Example 1

Input:
```
RL

AAA = (BBB, CCC)
BBB = (DDD, EEE)
CCC = (ZZZ, GGG)
DDD = (DDD, DDD)
EEE = (EEE, EEE)
GGG = (GGG, GGG)
ZZZ = (ZZZ, ZZZ)
```

Output:
```
2
```

Explanation:
Starting at AAA, you go right (R) to CCC and then left (L) to ZZZ, reaching ZZZ in 2 steps.

### Example 2

Input:
```
LLR

AAA = (BBB, BBB)
BBB = (AAA, ZZZ)
ZZZ = (ZZZ, ZZZ)
```

Output:
```
6
```

Explanation:
Starting at AAA, you follow the left/right instructions, which repeat as LLRLLR... and so on. It takes 6 steps to reach ZZZ.