By convention, main() returns 0 for success and any other value for failure
However, we can tell main() to return any status for use by the environment.

the value that main returns will be stored in the $? variable
we can print that value to terminal using echo:

$: echo $?

In this directory I will write 3 programs:
    one program that executes successfully, returning a status of 0
    one program that is forced to exit with a status of 1
    one program that tells main to return a value higher than 1
