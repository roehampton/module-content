# Software Development 2 Lab 07 -- Code Style, Formatting, and Refactoring

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">

In this lab, you will explore the tools Visual Studio provides to support improving your code style as well as maintaining existing code. These are important skills to practice as one of your jobs is to write high-quality code -- indeed we do assess you on it.

## Code Style

Code style is about how consistent and easy to read your code is. Your code should be well presented and easy to read -- think about how you expect our notes and code to appear. You should be aiming for that level of code quality. Indeed, you'd likely complain if our code and notes were not high quality.

### Poor Code Formatting

Poor code formatting comes in a number of forms, but some things to watch out for:

- Inconsistent indentation -- something Python will shout at you about. C++ won't, so it is easy to be lazy.
- Inconsistent curly brackets -- do you use a newline for a curly bracket or do you open on the same line. Pick a style and stick to it.
- Lack of comments -- what does your code do.
- Whitespace -- adding the correct whitespace between lines of code is important. Adding too much or too little makes it harder to understand your code.
- Commented out blocks -- leaving old cold you have commented out in place is messy.

### Code Styles

There are a number of code styles available for C++. Of note are:

- Google
- LLVM
- Mozilla

But there are others.

**Exercise** -- explore these code styles by searching for them on Google (or similar). Determine which styles you find easiest to read and work with and start being consistent in using them.

**Note** -- an employer will have a code style they expect people to work to, so you generally don't have much choice. However, the code you show to employers (they will ask) needs to be consistent.

### Manual Formatting

**Watch the following video.**

<iframe src="https://roehampton.cloud.panopto.eu/Panopto/Pages/Embed.aspx?id=7af1cd7e-62e6-48fa-adb0-ae52000a2a6e&autoplay=false&offerviewer=true&showtitle=true&showbrand=true&captions=true&interactivity=all" height="405" width="720" style="border: 1px solid #464646;" allowfullscreen allow="autoplay"></iframe>

### Auto Formatting

**Watch the following video.**

<iframe src="https://roehampton.cloud.panopto.eu/Panopto/Pages/Embed.aspx?id=353f5412-301f-44fd-befe-ae52000a2a6f&autoplay=false&offerviewer=true&showtitle=true&showbrand=true&captions=true&interactivity=all" height="405" width="720" style="border: 1px solid #464646;" allowfullscreen allow="autoplay"></iframe>

More on formatting via Visual Studio is available here.

[How to automatic format code in Visual Studio - Microsoft Q&A](https://docs.microsoft.com/en-us/answers/questions/550115/automatic-format-code-in-visual-studio.html)

## Updating Code

Often you will want to update your code by changing variable names, type names, or other features. This can be a tedious task. Thankfully, modern software development tools support your work in renaming and tidying up code. This is called **refactoring.**

### Refactoring

**Watch the following video.**

<iframe src="https://roehampton.cloud.panopto.eu/Panopto/Pages/Embed.aspx?id=c8c3a3e0-051a-4bd2-9e27-ae52000a2a68&autoplay=false&offerviewer=true&showtitle=true&showbrand=true&captions=true&interactivity=all" height="405" width="720" style="border: 1px solid #464646;" allowfullscreen allow="autoplay"></iframe>

You can find out more about refactoring here.

[Rename | Microsoft Docs](https://docs.microsoft.com/en-us/cpp/ide/refactoring/rename?view=msvc-170)

[Change Signature | Microsoft Docs](https://docs.microsoft.com/en-us/cpp/ide/refactoring/change-signature?view=msvc-170)

[Extract Function | Microsoft Docs](https://docs.microsoft.com/en-us/cpp/ide/refactoring/extract-function?view=msvc-170)

## Exercises

In the following exercises, you have to tidy the provided code and make it understandable. Use the following process:

1. Auto format the code.
2. Run the program to understand what it does.
3. Rename the functions and variables to something more appropriate. You might have to rename them a few times while you work out what they mean. **Hint -- you should add comments as you go.**
   - All functions have been renamed `Fnnn` where `nnn` is a number.
   - All variables have been renamed `Vnnn` where `nnn` is a number.
   - All `struct` have been renamed `Snnn` where `nnn` is a number.
4. Run the program again to check it is still working.

### Exercise 1

Exercise 1 code is available [here](01.cpp){:target="_blank"}. You have seen this program before, but won't recognise it yet.

### Exercise 2

Exercise 2 code is available [here](02.cpp){:target="_blank"}. You have this program before as well.

### Exercise 3

Exercise 3 code is available [here](03.cpp){:target="_blank"}. You have not seen this code before. You should use documentation to understand what the new code does.