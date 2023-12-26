# Part Two: Ghostly Escape

In Part Two of the Haunted Wasteland puzzle, you are asked to simulate a scenario where you start at every node ending with 'A' and simultaneously follow all paths until you reach nodes ending with 'Z.' Calculate the number of steps it takes before you're only on nodes that end with 'Z' when starting on every node ending with 'A.'

## Example

Given the following network and instructions:

```
LR

11A = (11B, XXX)
11B = (XXX, 11Z)
11Z = (11B, XXX)
22A = (22B, XXX)
22B = (22C, 22C)
22C = (22Z, 22Z)
22Z = (22B, 22B)
XXX = (XXX, XXX)
```

You start at nodes 11A and 22A (both ending with 'A'). Simultaneously following the left/right instructions, you navigate away from all nodes you're currently on until you're only on nodes ending with 'Z.' In this example, it takes 6 steps to reach nodes ending with 'Z' from all starting nodes ending with 'A.'
