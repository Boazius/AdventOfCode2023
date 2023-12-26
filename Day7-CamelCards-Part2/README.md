# Part Two: Joker Rule

In Part Two of Camel Cards, the Elf introduces an additional rule: J cards are now considered jokers, which can act like any card to make the hand the strongest possible type. However, J cards are the weakest individual cards, even weaker than 2. The order of other cards remains the same: A, K, Q, T, 9, 8, 7, 6, 5, 4, 3, 2, J.

J cards can act as any card to determine hand type, but for breaking ties between two hands of the same type, J is always treated as J, not the card it's pretending to be.

## Example with Joker Rule

Using the new joker rule with the following example:

```markdown
32T3K 765
T55J5 684
KK677 28
KTJJT 220
QQQJA 483
```

The hands are ranked and winnings are calculated as follows:

- 32T3K (rank 1)
- KK677 (rank 2, as it is now the only two pair)
- T55J5 (rank 3)
- QQQJA (rank 4)
- KTJJT (rank 5)

With the new joker rule, the total winnings in this example are 5905.

Your task is to find the rank of every hand in your set using the new joker rule and calculate the new total winnings.