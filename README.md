# Shell <img src="https://github.com/sahilgoswami0901/Shell/assets/107829550/ef2d0863-e890-4281-9984-6b87839f9400" width="35" height="35">
Linux (and other Unix-like OSes) have shells,” or programs, which present
a command-line interface for users to type commands in. In this assignment,
you need to use standard C libraries, including Linux system calls such as
fork(), exec() family system calls, and wait() family system calls.
There are two kinds of commands: “internal” and “external”. Internal
commands are those which are interpreted by the shell program itself, with
out, requiring a different program to handle the expected operations of the
said command). Examples of internal commands are like ‘cd’, ‘pwd’, and exit.
External commands, on the other hand, relate to commands which are not
handled not directly by the shell program but by an external program. Common
examples include ‘ls’, ‘cat’, ‘grep’ etc.
In this assignment, you have two tasks:

1. You need to design a simple shell that can handle three, internal com-
mands – ‘cd’, ‘echo’ and ‘pwd’. These commands would be handled directly
by the shell. Your shell should also be able to handle five external commands
– ‘ls’, ‘cat’, ‘date’, ‘rm’ and ‘mkdir’. For these external commands you need
to write individual programs to handle these commands. To handle these external
commands, the shell should typically create a new process, using the fork()
system ‘call and within each process you need to use the execl() family
system call to run the individual program. The parent program must also
wait for the child program to terminate using the wait() family of system
calls.
2. For each of these commands, you need not handle all the command line
options. Two options per command is sufficient. You need to document
which two options you are handling and need to demonstrate correct func-
tioning of the command with respect to (atleast) your chosen options. You
also need to handle corner cases such as invalid options (graceful degradation).
3. The second task would be the achieve the above functionality of the shell
using pthread create() (instead of fork()) and system() (instead of
execl() family of functions). The thread based execution would be per-
formed if the command is followed by the characters, “&t”. The rest of
the functionalities should remain the same. Note: you only need one set
of external command programs which could be used with either versions
of the shell, be it the that uses fork()/execl() or the one that uses
pthread create()/system().

# Deployment <img src="https://github.com/sahilgoswami0901/Shell/assets/107829550/ceb50133-aa69-4669-8ee9-ddcb05d61c3f" width="35" height="35">
Execute below command to compile all C files given in folder:
```bash
  make 
```
After running above command, you will have object files of C files ready with you then run below command:
```bash
  ./code
```
# Need Help? <img src="https://github.com/sahilgoswami0901/Shopify/assets/107829550/4af264bb-3508-43cd-bc32-14317dad0dc6" width="35" height="35">
Feel free to make bug reports on our issues. You can reach out to me in case you need further assistance.<br/>
Contact us:<br/>
<br/>
🧠 Sahil Goswami: sahil21281@iiitd.ac.in <br/>
