

## Ghost in the Shell

<div align="center">
![image](https://i.pinimg.com/originals/88/b4/d0/88b4d029c342900d92121fea161d100e.gif)
</div>
The Simple Shell is a simple command line interpreter based on the first Unix shell 'sh', created by Ken Thompson in 1971. The Ghost in the Shell is a minimalistic and contains functionality for only the most basic shell tasks - accepting input, parsing the input into a command and its arguments, and executing that input. 


## Authors

- [@HolbieWan](https://github.com/HolbieWan)
- [@niranois13](https://github.com/niranois13)
- [@NadegeL](https://github.com/NadegeL)


## Purpose

The purpose of the simple shell project is to understand:

- How a shell works
- PID and PPIDs
- How processes are created
- How to manipulate the environment of the current process
- The difference between a function and a system call
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?
## Requirements 

- Allowed editors: vi, vim, emacs
- Betty will be proud
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)
## output
 
 - Our program must have the exact same output as :   'sh (/bin/sh) ' as well as the exact same error output.

## Screenshots

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)


## Run Locally

Clone the project

```bash
  git clone https://github.com/niranois13
```

Go to the project directory

```bash
  cd holbertonschool-simple_shell
```

## Running Tests

**_To run tests, compile with_**
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
**_Your shell should work like this in interactive mode:_**

```bash
 $ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
**_Your shell should work like this in  non-interactive mode:_**

```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```


## Flowchart
![!\[alt text\](<./test/holbertonschool-simple_shell shell_flowchart.jpeg>)](Test/Shell_flowchart.jpeg)




<div align="center">
<img src="https://i.pinimg.com/originals/8b/d7/01/8bd701835159269167960889f99f182d.jpg" width= "200" height= "300">
</div>
