#### Static Site

Folder restructuring.

#### Git Hooks

**WARNING** -- this is a slightly advanced topic, and isn't necessary to manage your database. You can just do it manually as described above.

We can ask Git to automate the dump, delete, recreate process for us using *Git Hooks.* A Git Hook is just code that is run before or after particular events occur in your repo, such as committing and merging.

When you created a Git repository, Git created some hidden files to manage the repository. These are in a hidden `.git` folder within the root directory of your folder. Within this folder, there is a `hooks` folder which contains any hooks we have defined.

Let us create a pre-commit hook. **In Windows, the easiest thing to do is open Git Bash from the start menu.** Linux and MacOS can do this from the standard terminal. **Change directory in the command prompt to your Git repository folder, and then run the following in the command prompt:**

```shell
nano .git/hooks/pre-commit
```

Enter the following into the file:

```shell
#!/bin/bash
rm students.sql
sqlite3 students.db .dump > students.sql
git add students.sql
```

**Use CTRL-O to save the file, and then CTRL-X to exit.** We have now created a script that will do the following just before a commit is finalised:

* Deletes any existing `students.sql` file.
* Dumps `students.db` into `students.sql`.
* Adds `students.sql` to the Git commit.

As Git checks for differences, this will have no effect if the database has not been updated since the last commit.

**Now run the following command**:

```shell
nano .git/hooks/post-merge
```

The contents for this file are:

```shell
#!/bin/bash
rm students.db
cat students.sql | sqlite3 students.db
```

**Use CTRL-O to save the file, then CTRL-X to exit.** We have created a script that will run after a merge (the end of a pull) that does the following:

* Deletes the existing `students.db` file.
* Creates a new `students.db` file from `students.sql`.

**If you are on MacOS or Linux you will need to make these files executable.** This is done as follows:

```shell
chmod +x .git/hooks/pre-commit
chmod +x .git/hooks/post-merge
```

**NOTE** -- these scripts are not shared in your repository. You will need to set them up on each machine you are working on for them to work effectively.