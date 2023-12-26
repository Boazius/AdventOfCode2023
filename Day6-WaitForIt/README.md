## Day 6: Wait For It

You are participating in boat races where your goal is to beat the current record in each race. The races involve toy boats with a unique mechanism. Here's a breakdown of how it works:

### Boat Races

- You are given a sheet of paper with the time allowed for each race and the best distance ever recorded in that race.

- Your toy boat starts with a speed of zero millimeters per millisecond.

- You can hold down a button at the beginning of the race to charge the boat, and releasing the button makes the boat move. The longer you hold the button, the faster the boat will move, but this time counts against the total race time.

### Example Races

Here's an example of three races with their durations and record distances:

| Time (milliseconds) | Distance (millimeters) |
|----------------------|------------------------|
| 7                    | 9                      |
| 15                   | 40                     |
| 30                   | 200                    |

### Calculating Speed

- For each whole millisecond you spend holding down the button at the start, the boat's speed increases by one millimeter per millisecond.

- You can choose how long to hold the button to maximize the distance traveled within the given time.

### Winning Strategies

In each race, you aim to beat the current record. To do this, you need to determine the optimal duration to hold the button. For example, in the first race lasting 7 milliseconds, you could choose to hold the button for 2, 3, 4, or 5 milliseconds to beat the record.

- The number of ways to beat the record varies for each race.

### Task

Your task is to determine the number of ways you can beat the record in each race and then multiply these values together to find the final result.

To summarize, you need to calculate how many ways you can beat the record in each of the three races provided as an example and multiply these numbers together to find the solution.
