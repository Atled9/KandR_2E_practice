compile with command:
gcc main.c itoa.c reverse.c -o {binary name here}

You can test the negative input limit for the itoa() function
by getting INT_MIN using command:
getconf -a | grep INT
