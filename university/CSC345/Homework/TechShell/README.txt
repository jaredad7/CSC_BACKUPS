Techshell, by Jared Dembrun, 2/25/14

Type 'cat hw4' to review example of script usage.
Type 'gcc -o techsh techsh.c' to compile source file.
Type './techsh' to run and test Tech Shell

commands:
The command 'cd' is a built in command. Typing 'cd' without arguments will change to the home directory. Typing 'cd (arg1)' will change to the provided directory, and will return an error if no such directory exists.

The command 'pwd' is built in and will print the full path to the current working directory. However, the full path is already printed just before the command line.

The command 'exit' will end the shell process without errors. There are some fatal errors possible in the program which will exit with errors, such as a failure to fork or a failure to print directory upon waiting for input.

All other commands, including redirection, will behave as expected in the default shell.
