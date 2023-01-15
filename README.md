### Archive structure

```bash
student@aa:$ tree -L 1
├── check
├── check_utils
├── install.sh
├── Makefile.example_cpp
├── Makefile.exampleJava
├── README.md
├── sat_oracle.py
├── task.h
├── Task.java
└── tasks
```

### Code Structure

To solve the tasks of ‘trial’ and ‘rise’, we recommend modulation in the following functions:

1. a function that reads the input data from 'stdin'.
1. a function that formulates the clauses to the oracle.
1. a function that calls the oracle (already implemented).
1. a function that deciphers (processes) the response of the oracle.
1. a function that displays the result in 'stdout'.

What contains the 5 methods mentioned above, from which you can inherit one class for each problem separately (e.g: You can have classes Task1, Task2, Task3 that inherit the abstract task class).
Only methods 1, 2, 4, 5 must be implemented. The oracle is already called by the 'ask_oracle' function. You will only have to call it after you have formulated the SAT clauses corresponding to each problem.
Any approach can be used to solve the ‘redemption’ task.

### Makefile

For each problem, there will have to be a corresponding rule in Makefile run\_`<nume_problema`> (e.g: `run_rise`)
**Not allowed to use optimization flags.**

### Running the Checker

To run the checker, use the command ‘./check’
To run a specific task, use the command ‘./check --task {name_task}`. (example: check --task rise).
Tests for each problem can be found in the ‘tasks/<nume_problema>/tests’ folder. (example: tests for the rise problem can be found in the ‘tasks/rise/tasks’ folder.)
After running the checker, an output file is generated for each test in the (`tasks/<nume_problemă>/tests/<XY-nume_problemă>/<XY-nume_problemă.out>`) folder, where XY is the test number
(example: \*\*after running the checker, test result 00 for the ‘rise’ problem, the output will be found at tasks/rise/tests/00-rise/00-rise.out.)

### Test mode

- "Trial": Reference files contain only "true" or "false", representing whether or not the input file has a solution.
  If the answer is true, the checker will check that the displayed indices form a valid cover set.

- 'rise': reference files contain the minimum number of packages purchased. The checker will check that the index of the displayed packets contains the desired cards.
- ‘redemption’: the reference files contain the minimum number of packages purchased. The checker will check that the index of the displayed packets contains the desired cards.
  To measure the performance of the algorithm we use the following formula:

```python
factor1 = (min(given_elems, expected_elems) / expected_elems)
factor2 = 1 - ((abs(given_sets - expected_sets)) / expected_sets)
return 0.5 * factor1 + 0.5 * factor2
```

Where:

- given_sets = the number of packages given in your solution
- expected_sets = the number of packages in the optimal solution
- given_elems = required cards given in your solution
- expected_elems = required cards
