# Day 7: Camel Cards

Your task is to play the game of Camel Cards. In Camel Cards, you receive a list of hands, and your goal is to order them based on the strength of each hand. Each hand consists of five cards labeled one of A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, or 2, with A being the highest and 2 being the lowest.

## Hand Rankings

Hands are ranked as follows:

1. Five of a kind (e.g., AAAAA)
2. Four of a kind (e.g., AA8AA)
3. Full house (e.g., 23332)
4. Three of a kind (e.g., TTT98)
5. Two pair (e.g., 23432)
6. One pair (e.g., A23A4)
7. High card (e.g., 23456)

Hands are primarily ordered by type, with a specific hierarchy.

## Ordering Rule

If two hands have the same type, the following ordering rule applies:

- Start by comparing the first card in each hand. The hand with the stronger first card is considered stronger.
- If the first cards are the same, compare the second card in each hand.
- Continue comparing cards in order until a difference is found.

## Playing Camel Cards

You are given a list of hands and their corresponding bid amounts (your puzzle input). Each hand wins an amount equal to its bid multiplied by its rank. The weakest hand gets rank 1, the second-weakest hand gets rank 2, and so on up to the strongest hand.

For example:

```markdown
32T3K 765
T55J5 684
KK677 28
KTJJT 220
QQQJA 483
```

In this example, the hands are ranked and winnings are calculated as follows:

- 32T3K (rank 1)
- KTJJT (rank 2)
- KK677 (rank 3)
- T55J5 (rank 4)
- QQQJA (rank 5)

The total winnings are 6440.

Your task is to find the rank of every hand in your set and calculate the total winnings.