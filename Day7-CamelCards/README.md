```markdown
## Day 7: Camel Cards

Learn to play a game called Camel Cards. This game involves ordering a list of poker hands based on their strength, with each hand consisting of five cards labeled A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, or 2, ranked from highest (A) to lowest (2).

### Camel Cards Hand Rankings

Hands are ordered primarily by type, from strongest to weakest:

1. Five of a kind: All five cards have the same label (e.g., AAAAA).
2. Four of a kind: Four cards have the same label, and one card is different (e.g., AA8AA).
3. Full house: Three cards have the same label, and two cards share a different label (e.g., 23332).
4. Three of a kind: Three cards have the same label, and the remaining two cards are distinct from each other (e.g., TTT98).
5. Two pair: Two cards share one label, two other cards share a second label, and the remaining card has a third label (e.g., 23432).
6. One pair: Two cards share one label, and the other three cards have distinct labels from each other and the pair (e.g., A23A4).
7. High card: All cards' labels are distinct and in no specific order (e.g., 23456).

### Hand Comparison Rules

When two hands have the same type, they are further ordered based on specific rules:

1. Compare the first card in each hand. The hand with the stronger first card is considered stronger.
2. If the first card in both hands is the same, compare the second card.
3. Continue comparing subsequent cards until a difference is found.

For example, 33332 and 2AAAA are both four of a kind hands, but 33332 is stronger because its first card is stronger. Similarly, 77888 and 77788 are both full houses, but 77888 is stronger because its third card is stronger (and both hands have the same first and second cards).

### Task

You are provided with a list of hands and their corresponding bids. Your task is to rank these hands in order of strength and calculate their total winnings. Each hand wins an amount equal to its bid multiplied by its rank, where the weakest hand gets rank 1, the second-weakest hand gets rank 2, and so on up to the strongest hand.

For example:

```
32T3K 765
T55J5 684
KK677 28
KTJJT 220
QQQJA 483
```

In this example, the hands are ranked as follows:

1. 32T3K (One pair)
2. KTJJT (Two pair)
3. KK677 (Two pair)
4. T55J5 (Three of a kind)
5. QQQJA (Three of a kind)

The total winnings are calculated as 765 * 1 + 220 * 2 + 28 * 3 + 684 * 4 + 483 * 5, resulting in a total winnings of 6440.

Find the rank of every hand in your set and calculate the total winnings.
```

This markdown provides a summary of the coding task without the story elements.