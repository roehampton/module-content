# Software Development 2 Lab 2 -- Version Control, HTML forms, CSS and Developer Tools

>## Pre-class task: Creating a GitHub Account and a new repository

> Version control software (CVS, Mercurial and SVN are other examples) maintain your code somewhere backed-up and shareable with your team.  Crucially, they give you ways to work independently on code and then 'merge' and 'resolve conflicts' with other team members' code.  Nothing is ever forgotten by the repository!

>We will use *GitHub* as an online repository for this module.  First, you will need to create an account on GitHub if you haven't already.  Go to [GitHub](https://github.com/) and **Sign Up**.  Two things to note:

> 1. You do not need a paid for account.
> 2. If you are a student, GitHub will give you [unlimited private repositories](https://education.github.com/pack).

> Once you have an account, you need to create a repository.  In GitHub, you will see a **+** near the top of the page, which you can select **New repository** from:

> ![GitHub New Repository](github-new-repo.png)

> This will open a new window.  You need to enter the name for the repository (for example, `sd2`), make sure the repository is **Public** and then select the **Apache 2.0** license type.  **Ensure that a README is added**.  The details are illustrated below:

> ![image-20201227112452665](image-20201227112452665.png)

> Click on **Create repository** and you will be presented with the following: 

> ## Installing Git -- Mainly for Windows

> You need to have the git software on your local computer. Git is normally installed on MacOS and Linux by default. For Windows do the following:

> 1.  Go to Git home page https://git-scm.com/**.
> 2.  Download Git**.
> 3.  Install Git. During install make sure you select to use Visual Studio Code as the default editor.**
> 4.  All other settings can remain as default.**
> 5.  Once installed continue with the rest of the lab.**

>## Set up git with your identity


> Git commits have a collection of information attached to them, including who > created the commit -- their name and email address. We must set this information up when we start using Git. Enter the two following lines into your terminal:

```shell
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
```

> Replacing `you@example.com` with the email you used for your GitHub account, and `Your Name` with your name.



## Revise the main concepts of version control

1. **Origin**  : The centralised repository holding everything, probably 'remote' ie. on a server or service somewhere eg. github
1. **Clone**  : PUll down an entire copy of the repository
1. **Branch** : Independent opies of the main codebase that you can alter and work on
1. **Stage**:  Get files ready to commit
1. **Commit**: Saving a batch of your new work onto your branch with a comment
1. **Pull or fetch** : Bringing down others changes to your local repository
1. **Push** : Pushing your changes back into the origin repository
1. **Merge**: The process of merging your code (probably a branch) with others code

## Other useful terms

1. **Working copy**: The files you are working on right now, probably your branch
1. **Master branch**: Usually the name of the branch everything merges into in the end
1. **Fork** : a copy of the master branch that has divergent, unmerged code.
1. **Hooks** : we won't be using hooks for a while but its good to know they exist. These are actions such as triggering a build on your server that you can program in response to an action in git for example a push to the master branch.  This is the core of 'continuous integration'.



## Lab

## Introduction and getting ready

1. You will do the lab today in PAIRS.  Please swap frequently between the 'driver' and 'navigator'. (see https://en.wikipedia.org/wiki/Pair_programming)
1. __You need ONE repository for this lab Choose the repo of ONE of the members of your pair to to on today__. Follow the instructions at the start of this lab to create a repository if you have not already done so. 

## Cloning a Project in Visual Studio Code

_All members of your group should clone the same project._

Now we need to clone the chosen GitHub project in Visual Studio Code. 

1. **Open Visual Studio Code.**
2. **Make sure no folder is currently open. We can do this by using File then Close Folder from the main menu.**
3. **Click on the Source Control button on the left-hand side of the Visual Studio Code window.**
4. **Your window should now look like this.**

![image-20201227134347876](image-20201227134347876.png)

We need the the location of our repository.  Find it by going the the github page for the repository, click the down arrow on the green 'code' button, and copy the https:// format URL to your clipboard, as below...

![git-clone](git-clone.png)

**Click the Clone Repository button and Visual Studio Code will ask for the repository URL at the top of the window**.  Paste in the URL you obtained from Github as above.

![image-20201227134725482](image-20201227134725482.png)

1. **Press return, and Visual Studio Code will ask you where you want to save the repository. A new directory within your documents directory is a good idea.  Make sure NOT to save onto a ounted onedrive directory.

2. **Visual Studio Code will ask you if you want to open the repository. Choose to do so.**

You now have your GitHub repository cloned to the local machine and opened in Visual Studio Code. Let us add some files to the repository.

1. **Create a new file called <yourname>.txt**  (where yourname is your own name. Put any content in that you want to)

2. **Open the Source Control panel in Visual Studio Code using the button on the left-hand side.**
3. **You will now see a list of changes. We will just add all of them just now. Click the three dots at the top of the Source Control panel and select Changes then Stage All Changes as shown below.**

As an alternative, do the same thing in a terminal window.  From the top menu, 'terminal', click 'new terminal'. This will open a terminal in VS code.

Use the following command to check if there are new files that need to be 'staged' (ie. made ready for the next commit)

```bash

git status
```

NB: The git status command is your go-to command to figure out the relationship of files you have in your local 'working' diretory, and the current state of your repository.

You should at this point see the new 'unstaged' files, or be told if there are 'modified' files in your working tree.

To add the files...

```bash
git add
```

![image-20201227141135038](image-20201227141135038.png)

You have now added your existing files to the *Staging Area* of the local Git repository. Next we need to create a commit from these changes. **Click the three dots again and select Commit then Commit. Visual Studio will ask you for a commit message. Enter `First commit, adding initial files.`**

To do the same thing via the terminal:

```bash
git commit -m 'My meaningful message as this will persist forever!'
```

HINT: A good commit message will help others understand what you did and why. 
ANOTHER HINT: if you forget the -m, a text editor will open where you can type a longer message, but this can get complicated if you are not familiar with CLI text editors, so better to ctr C and start again remembering the -m and putting the message inline.

![image-20201227141500721](image-20201227141500721.png)

We have now created a checkpoint in our code that we can **always** return to.  This is the power of version control.  We are check-pointing our code so we can rewind to previous versions.  As long as you commit often, you can always revert back to a previous version.

Now we need to push these changes to GitHub. **Click the three dots again, and select Push**. You will be asked to log into GitHub. Do so and follow the instructions given. This will keep you authenticated with Github when you use visual studio code.

Refresh the GitHub page.  You should see your files there:

![image-20201227143113032](image-20201227143113032.png)

We have now defined our core workflow with Git using Visual Studio Code:

1. Add the files to the commit -- **Changes then Stage All Changes.**
2. Commit the changes -- **Commit then Commit.**
3. Push the changes -- **Push**.
4. When everyone has pushed, each team member should be able to copy all the new files to their own machine with:

```
git pull
```

. **HINT** -- if someone has already committed a change before you, you will need to pull the changes first before you can push yours.
3. Once everyone on the team has created their files, make sure everyone pulls the current version of the repository so they are up to date.

**Get used to this process - it will save your code from disaster!**.  We have created a checkpoint where we know our code is working and doing what we expect.  Whenever you do a change -- and make your changes small -- and tested the build works, commit and push.  


Now you should continue with the lab, in pairs, commiting each time you complete a task.  Remember to swap driver and navigator frequently.


## More frontend skills: HTML forms and using Developer Tools

When we start to work with a more sophisticated backend, we will need to know how to create forms that eventually we will use to send information into the backend server for storage or to make a customised request.  Lets see how to make input forms in HTML. This example shows the three main types of form element for different types of input.

Example:

```html
<!DOCTYPE html>
<html>

<head>

</head>

<body>

  <h1>HTML Forms example</h1>

  <form action="" method="GET">
    <div>
      <label for="name">Name:</label>
      <input type="text" id="name" name="name">
    </div>
    <div>
      <label for="mail">E-mail:</label>
      <input type="email" id="mail" name="email">
    </div>
    <div>
      <label for="msg">Message:</label>
      <textarea id="msg" name="message"></textarea>
    </div>
    <button type="submit">Submit!!</button>
  </form>

  <p>If you click the "Submit" button, the form-data will be sent back to this page.
    Usually, the action sends data to a different file with scripts that can process it.</p>

</body>

</html>
```

***
#### Git exercise...

__Add a new file with this code. When it is working and you have understood everything here, commit to the 'master' branch of your repository with..__

```bash
git add <filename>.html
git commit -m '<a helpful message>'
git push
```

***

## Sending parameters: GET vs POST

Try changing the 'method' attribute from GET to POST. Can you spot the difference?  It is very important to understand the differences: see https://www.w3schools.com/tags/ref_httpmethods.asp.

## Examining and receiving parameters

In your dynamic web application, sending these kinds of variable values to your application either to SELECT or UPDATE data will be a crucial part of your work and you will mostly use HTML forms to pass in this dynamic data.

As well as being able to debug within your programme, you can use Chrome or Firefox developer tools to examine what is going on Eg. In Chrome, open developer tools, choose the network tab, check 'preserve log' and 'disable cache'.  In the 'Headers' section, after you submit the form by GET or POST, you should see the values you send.  Note that the values you send are labelled using the value of the "name" attribute in the HTML form, in this case name, email and message.  See image below...



>![Form parameters](form-data-dev-tools.png)


***
#### Git exercise...
Type

```
git status
```

The output should indicate that the file has changed.  To commit your changed file you will do, as before:


```bash
git add <filename>.html
git commit -m '<a helpful message>'
git push
```

Look in your git repository. Can you find the commits and the 'diff' information?  Have a good look and see how the changes and history are represented in the github interface.

Whoever did NOT commit the change should perform:

```
git pull

```

to receive the changes from their partner.

***


## A few words about styling:  CSS

You might have noticed how boring our pages look so far! Typically, HTML should only carry information about structure and content.  Styling instructions should be held in linked files called 'cascading style sheets' that apply a look and feel to specified HTML elements.

CSS is an important part of web development, it can get very involved and is fun if you are a visual person.  You need to deal with complexities such as different devices and screen sizes (responsive design), how to implement styles using different web frameworks, and tools that allow you to setup almost programme-like style rules (Sass).  All this is mostly beyond the scope of this module, but its a good set of skills to learn via online courses.  Introduction: https://developer.mozilla.org/en-US/docs/Learn/CSS, but if its an area you are interested in, then you can go a lot deeper in.

For now, lets cheat and connect our pages to an open source online stylesheet called milligram, but doing this will tell us the basics of CSS.  But first, lets create a new branch for this feature...

***
#### Git exercise...

Whoever is 'driving' should create a new branch for this fantastic new feature.  Your branch name should reflect the feature you are working on.

They should do the following (lines starting with a hash are comments)

```
# Check master is up to date
git pull

# 'Checkout' a branch, which in this case is new, and switch to it
git checkout -b <branch name>

# Its good to run git status alot!
git status

```

***

__Now return to the task___


First, link to an external stylesheet, and while we are at it some nicer fonts too.  Add the following between the `<head>` tags:

```html
  <!-- Google Fonts -->
  <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Roboto:300,300italic,700,700italic">

  <!-- CSS Reset -->
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/normalize/8.0.1/normalize.css">

  <!-- Milligram CSS -->
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/milligram/1.4.1/milligram.css">
  ```

  Reload your form and it should look better.

  Now lets bring the form into a neater container so it doesn't take up the width of the page.  We will do this by wrapping the form in a 'div' tag with a class attribute that will pull in style for a narrower, centered container.  Add the following after the `<body>` tag:

```html
  <div class="container">
```

Then close the tag before the </body> tag

```html
</div>
</body>
```

Any better looking?

Finally use developer tools to 'inspect' the styles you have applied, you can manipulate them as well.  You can examine the whole style sheet via the 'sources' tab in developer tools.

>![Inspect CSS](styleinspector.png)


***
#### Git exercise...

Commit to the branch, push the branch to github.  Your partner can pull your branch and merge the change to master (note)

```
# Check things are as you expect
git status

# Add your file to your feature branch
git add <filename>.html
git commit -m '<helpful message>'
git push

# for curiosity, take a look at your branches listed out, and the git log
git branch
git log

```

At this point, you will recieve an error message, but it will tell you what to do to create a remote tracking branch.  Follow the instructions to push your branch.  Note that git error messages, though look intimidating are usually helpful.

Your partner now can 'pull' your branch

```
git fetch --all
git checkout <your branch name>

```

One of you can now merge the changes into the master branch

```
# Checkout the branch you want to merge code into
git checkout master
git merge <your branch name>
# If all goes well, git will figure out how to merge. If not, it will tell you theres a conflict and you will need to hand-edit the file until it is as you want it
# Check the merge went well. If not, you may have to edit the file, the add and commit
git status
# Push the merged code
git push
```

***