#  Part 1: working with files and directories.

Remember that the files form an upside down tree structure.

![Directory structure](dirtree.gif?raw=true "Unix Directory Structure")

Now we will practice typing commands and navigating the file system. Type the commands give at the prompt and examine the output.

Type in the text given in the monospaced font.


## Navigating directories and listing files


pwd (Present working directory): outputs the path to the directory you are currently in:

```bash
pwd
```

ls: List the files in the current directory:

```bash
ls
```

mkdir: Create a directory:

```bash
mkdir my_test_directory
```

List again (your new directory should be visible).  Use the ‘long’ flag this time:

```bash
ls -l
```

Observe the columns in the output find out what they are and ask any questions about them in the troubleshooting forum.

Change to the new directory:

```bash
cd my_test_directory
```

Create an empty file:

```bash
touch my_test_file.txt
```

List again (your new directory should be visible).  Use the ‘long’ flag this time:

```bash
ls -l
```

Reassure yourself that you know where you are in the filesystem with the ‘present working directory’ command

```bash
pwd
```

Change ‘back’ to the parent directory  (two dots will move you back in the directory tree)

```bash
cd ..
```

## Now try the following tasks using the knowledge you have acquired:

    1. List the files and directories in your current directory
    2. Move to the directory you previously created
    3. List the files
    4. Create an additional new file
    5. List the files again so you can now see two files
    6. Create a new directory (extending the tree)
    7. Change to the new directory
    8. Try to get back to the directory where you started

Screenshot your terminal and upload it when you have completed this exercise.

### Expert tips and tricks

Find further information on any command you have used by using the **man** command

```bash
man <command>
```

Understand **command flags** (sometimes called options or switches). Options are usually preceeded by a hypen and may also have an argument. The options alter the behaviour of the command or add information to the output. Example:  Try each of the following versions of the ls command. Examine the output and use the 'man pages' to work out what each option does.

```bash
ls
ls -l
ls -l -a
ls -l -a -h
```

**Command history**: When you type commands a history is kept by the shell.
Using the up and down arrow keys, you can scroll to a previous command, edit it if you wan to, and then press RETURN to re-run it.


Next: [Copying and moving files and directories][eaf289c9]

  [eaf289c9]: moving-copying.html "copying and moving files"
