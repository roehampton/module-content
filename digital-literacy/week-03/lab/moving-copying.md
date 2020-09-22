# Part 2: Moving, copying and deleting files and directories

Execute the commands given.

Troubleshoot any errors using pwd to check your current Directory

Text after a '#' are comments - don't type these, they are there for explanation.


## mv command

Ensure you are in the first level of your home directory

```bash
cd ~
```

Create new file

```bash
touch new-file-to-move.txt
```

mv: move file to another directory

```bash
mv new-file-to-move.txt my_test_directory/
```

Note the 'trailing' ie. final forward slash '/'. This means that moved file will land into the directory given.

Check that the file is gone from the current directory

```bash
ls
```

Move up a directory, and list again.  Now you should see your file.

```bash
cd my_test_directory
ls
```

mv: Move the file within its existing directory.  This is effectively a rename operation.

```bash
mv new-file-to-move.txt renamed.text
```


**Tip:**
The mv command can be used with files or directories


## cp command

cp is the copy command. It can be used with files or directories, but if a directory containes files, it needs to be used with the -r (recursive) option to ensure that all of the contained files are moved.

Ensure you are in the first level of your home directory

```bash
cd ~
```

Create new ficp: copy file into another directoryle

```bash
touch new-file-to-copy.txt
```

cp: copy file into another directory

```bash
cp new-file-to-copy.txt my_test_directory/
ls #check the file is still present
cd my_test_directory
ls #you should see the file in this location as well

```

Notes: If a file or directory of the same name already exists in the target directory, it will be overwritten so take care!

cp: copy a directory (using the r option), with its files, to a new location

```bash
cd ~ # back to home Directory
ls  # check directory contents
mkdir new-directory # create a new directory
cp -r my_test_directory new-directory/
ls # you should see my_test_directory
cd new-directory
ls # you should see my_test_directory again in this location
```

## **Important** Relative and absolute paths

A path is a unique location to a file or a folder in a file system.  Its really important to know the difference between absolute and relative paths.

An absolute path is defined as the specifying the location of a file or directory from the root directory(/). In other words we can say absolute path is a complete path from start of actual filesystem from / directory.

Some examples of absolute path:
```
/etc/hosts
/var/log
/boot/grub/grub.conf
/home/<username>

```
If you see all these paths started from / directory which is a root directory for every Linux/Unix machines.

A relative path is defined as path related to the present working directory(pwd). Suppose I am located in `/var` and I want to change directory to `/var/log`. I can use relative path concept to change directory as follows

```
cd log
```

But if you did this from your home directory you would receive an error.
To reach the desired directory from anywhere you would use the absolute path:

```
cd /var/log
```

Note that in the exercises in this sheet so far, we have used relative paths, and makes use of `cd..` to move backwards in the file system.


## Now try the following tasks using the knowledge you have acquired:

    1. Make a new directory
    2. Create a file inside it
    3. Move that file to your home directory ie. (hint use mv ../ to go back in the tree)
    4. Create a directory with one file in it
    5. Move the entire directory up to your new_directory directory

Screenshot your terminal and upload it when you have completed this exercise.


### Expert tips and tricks

Use command completion for speed and accuracy.

When you type a command followed by a file or directory name, you can use the tab key to get the shell to complete the full name of the file or directory you want.  Based on the letters you type, it will attempt to 'complete' the name.  Try it!  type the first three letters of the file or directory you want to move or copy and then a tab.  If there is only one possible file that starts with the letters, you will see full completion. If there are a number of matches, you can type some more letters and then try the tab again. Practice, and observe the behaviour.
