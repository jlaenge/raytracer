# TODO

## Output

It would be nicer to specify the output file as a command line parameter, s.t. the standard output can be used to display progress and debug information during the program run.

## Tests

Refactor the run() method to return a ratio of pass/failure to display more detailed coverage statistics. Alternatively, the test results could be displayed directly via stdout or stderr, e.g.:

```
TestingImage..........[PASSED]
TestingVector3........[FAILED]
    vectorAdditionTest4: Expected '4', got '3' 
```

## Optimization

Speed up the rendering process. E.g. refer to `Hackers Delight` and see if we can speed up the computations.