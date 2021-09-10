# Software Development 1 
# Lab 6 -– Simple I/O : Creating, storing &amp; retrieving files

In this lab we will explore:

1. How to work with Files and File Paths
2. Use Python to open files
3. Reading and writing files to the computer

You can store data in variables while your program is running, but if you want to keep your data after your program has finished, you need to save it to a file. We have seen how the computer stores all the data we put in into numerical ASCII values, which then get turned into 1s and 0s that get used for our calculations. We can store this physically in a memory bank like a hard drive, a tape, a CD or other physical media. When we save a file, the computer does a similar thing to the conversion of strings into ASCII values (numbers), transforming a series of words into numbers, which get turned into ones and zeroes. For instance, if we print out our program, we could make a book out of it. However, we could also print it our as a very long strip (like the ones that come in fortune cookies) and roll it up. This is what we will be doing when we store something in a file. We will create a single strip of 1s and 0s potentially gigabytes in size that will be stored in a physical device. In this lesson, you will learn how to use Python to create, read, and save files on the hard drive.


## Lesson 1: Files and File Paths
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=9b232aa6-653e-4795-914c-ac6a016addff

Every file in your computer has two key properties: a _filename_ (usually written as one word) and a _path_. The path specifies the location of the file inside the computer. If you right click on a file in Mac, Windows or Linux you can ask for info. It will usually tell you where the file is located at. For example, I have stored the solution to the Coursework in my Mac as:

/Users/Arturo/Dropbox/Roehampton/Soft\_Dev\_1/SD1\_Specifiction/CW1\_solution.ipynb

If you are familiar with Cloud-based storage, you can deduce that my file is not only stored in my Mac&#39;s hard drive, but there is also a copy of it in Dropbox (for safety). You can also tell that I&#39;ve named the file _CW1\_solution.ipynb_. The part of the filename after the last period is called the file&#39;s _extension_ and tells you a file&#39;s type. _CW1\_solution.ipynb_ is a _Jupyter notebook_ document, and _Users_, _Arturo_ and _Dropbox_ all refer to _folders in my computer_ or **directories**.

Folders can contain files and other folders. For example, _CW1\_solution.ipynb_ is in the _SD1\_Specifiction_ folder, which is inside the _Soft\_Dev\_1_ folder, which is inside the _Roehampton_ folder, all inside my _Dropbox_. The  **/** part of the path is the _root folder_, which contains all other folders


![Alt text](img_folders.png?raw=false "Folder Organization")


In Mac and Linux, the root folder is  **/** . In Windows, the root folder is named   C: \  and is also referred to as the   C: drive  .

If you plug into the computer another storage device other than the basic hard drive (like a USB memory stick, a DVD player or another hard drive, it will appear as an **Additional Volume.** In Mac, they appear as new folders under the **/Volumes** folder. On Linux, they appear as new folders under the  **/mnt** (short for &quot;mount&quot;) folder. In Windows, they appear as new, lettered root drives, such as  D: \  or  E: \  .

**Style Tip** : While folder names and filenames are not case sensitive on Windows and OS X, they are case sensitive on Linux. It is good practice to keep the names short and without spaces.

Exercise: **Investigate your Current Working Directory.** Every program that runs on your computer has a _current working directory_, or _cwd_. If you have used Anaconda&#39;s Jupyter notebooks, you are a bit familiar with navigating to the Working Directory where your notebook will be stored. You can get the current working directory as a string value with the **os.getcwd()** function and change it with **os.chdir()**. Enter the following into your Jupyter notebook

    import os
    os.getcwd()


you can also list all the files that are in your working directory with:


    os.listdir()
    
    
and change the directory with:

    os.chdir('NEW_PATH')
    
    
where NEW\_PATH is going to be the path to the new working directory. Try changing directories to one folder above your current working directory.

Exercise: Your programs can create new directories (folders) with the **os.makedirs()** function. Be mindful of the differences between operating system paths! Try changing paths in your Jupyter notebook:


    import os
    my_path = os.getcwd() + "/newDir2"
    my_path
    os.makedirs(my_path)


**Takeaway** : Files are organized into folders (also called directories), and a path describes the location of a file. Every program running on your computer has a current working directory. The _**os.path**_ module has many functions for manipulating file paths.


## Lesson 2: Opening Files
Video:https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=9165561b-730f-4fb5-b210-ac6a016ade3c

Now that we know how to work with with folders and paths, we can now specify the location of files to read and write. You probably have an intuitive knowledge of how this works. You can open a text file by double clicking on its icon (if you have a text handling program associated with that extension). You can use a text handling program (like Microsoft Word) to alter its contents and you can save the changes in the file. However, for our Jupyter notebooks, the process is not as straight forward. Let&#39;s start by understanding one of the most basic types of files: 
**Plaintext files**.

_Plaintext files_ contain only basic text characters, as their name suggest. They do not include any other information such font, size, or colour that a _richtext_ file such as a Word document might have. Text files with the _.txt_ extension or Jupyter notebook files with the _.ipynb_ extension are examples of plaintext files. They can be opened with simple text programs such as Windows&#39;s Notepad or OS X&#39;s TextEdit applications. These programs can read the contents of plaintext files and treat them as an ordinary string value. In the case of Jupyter notebooks, we want to do something special with the text: we want the computer to understand the text as a command. Hence, it is important to open these kind of files, not by double clicking on their icons, but by going into the Jupyter Program and opening the file from inside the application.

Jupyter notebooks are interactive documents that contain code, narratives, plots, images, etc. They are an excellent place for experimenting with code and data. They are a JSON file format, which you might hear about in the future.  JSON is a plain text format, they can be version-controlled and shared with colleagues. Jupyter needs to be actually running on your own computer, acting as a server, to interpret these files. You have to open these files inside of Jupyter.

All other file types such as word processing documents, PDFs, images, spreadsheets, and executable programs are much more complex and program-specific. These are known as _**Binary files**_. If you open a binary file in Notepad or TextEdit, they will look like scrambled nonsense. Each binary file type is different and must be handled in its own. You might even create your own type someday. To handle these files, Python has many modules make working with binary files easier.

There are three steps to reading or writing files in Python.

1. Call the **open()** function to return a _File object_.
2. Call the **read()** or **write()** method on the _File object_.
3. Close the file by calling the **close()** method on the _File objec_t.

_File objects_ represent files on your computer. it is another type of value in Python, but we have already started to think about some of the data we manipulate as Objects.

To open a file with the _open()_ function, you pass it a string path indicating the file you want to open. The _open()_ function returns a _File object_. Usually, a file object is immediately assigned to a variable like this:


    <variable > = open (<name >, <mode >) 
    
    
Exercise: Try it by creating a text file named _hello.txt_ using Notepad or TextEdit. Type **Hello world!** as the content of this text file and save it in your user home folder. Get the file path by right clicking the icon of the file and asking the file info.


    helloFile = open(“FILE_PATH”)
    
    
The _open()_ function will open the file in &quot;reading plaintext&quot; mode, or _read mode_. When a file is opened in read mode, Python lets you only read data from the file; you can&#39;t write or modify it. Read mode is the default mode for files you open in Python, however, we can read from or write to the file by calling methods on the File object in _helloFile_.

**Takeaway:** Your programs can directly interact with the contents of text files.


## Lesson 3: File Reading &amp; Writing
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=befbdce7-9eab-4beb-9c49-ac6a016adde2

Now that we have a File object, you can start reading from it. If you want to read the entire contents of a file as a string value, use the File object&#39;s read() method.

Example: Let&#39;s continue using the _hello.txt_ File object we stored in helloFile. We can use the method .read() to access its contents:


    helloContent  = helloFile.read()
    helloContent



We can think of the contents of a file as a single large string. The **read()** method returns the string that is stored in the file. Alternatively, you can use the **readlines()** method to get a _list_ of string values from the file, one string for each line of text.

Example: A sonnet is a poem of fourteen lines using any of a number of formal rhyme schemes, in English typically having ten syllables per line. Shakespeare wrote many. Lets write down his sonnet 29 in a text file. Create a file named _sonnet.txt_ in the same working directory as _your python notebook_ and copy the following text in it:

When, in disgrace with fortune and men&#39;s eyes,

I all alone beweep my outcast state,
 And trouble deaf heaven with my bootless cries,

And look upon myself and curse my fate,

Make sure to separate the four lines with line breaks. We can then open the file as:


    sonnetFile = open('sonnet.txt')
    sonnetFile.readlines()


Notice that each of the string values in the output ends with a newline character, \n , except for the last line of the file. A list of strings can often be easier to work with than a single large string value.

Python also allows you to write content to a file in a way similar to how the print() function &quot;writes&quot; strings to the screen. Python does not allow us to write directly to a file opened in read mode. Instead, we need to open it in **write plaintext** mode or **append plaintext** mode. These words should be familiar to you now after working with lists. **Write plaintext** or Write mode will overwrite the existing file and start from scratch. Think of it as erasing the connection it had to the contents and linking it to brand new information (just like when we cahnge a variable&#39;s value with a new value). **Write plaintext** mode is accessed by inputting **&#39;w&#39;** as the second argument to _open()_. **Append plaintext** , or append mode will, as the name suggest, attach text to the end of the existing file. This is exactly like appending to a list in a variable. The difference is, like in the case of lists, that this actually alters the contents of the file, leaving what was there originally intact. To open the file in append mode, we need to input **&#39;a&#39;** as the second argument to open(). Finally, if the filename passed to open() does not exist, both write and append mode will create a new file with the filename you chose. After reading or writing a file, call the **close()** method before opening the file again.

Exercise: Let&#39;s try creating a new file, bacon .txt, and store some data in it. We start by opening _bacon.txt_ in write mode. Since there isn&#39;t a _bacon.txt_ yet, Python can create one for us. Calling write() on the opened file and passing write() the string argument _&#39;Hello world! /n&#39;_ writes the string to the file and returns the number of characters written, including the newline. Then we close the file.


    baconFile = open('bacon.txt', 'w')
    baconFile.write('Hello world!\n') 
    baconFile.close() 


Exercise: To add text to the existing contents of the file instead of replacing the string we just wrote, we open the file in append mode. We write &#39;Bacon is not a vegetable.&#39; to the file and close it. Finally, to print the file contents to the screen, we open the file in its default read mode, call read(), store the resulting File object in content, close the file, and print content. Note that the write() method does not automatically add a newline character to the end of the string like the print() function does. You will have to add this character yourself.


    baconFile = open('bacon.txt', 'a')
    baconFile.write('Bacon is not a vegetable.') 
    baconFile = open('bacon.txt')
    content = baconFile.read()
    baconFile.close()
    print(content)
    
    


Exercise: You can save variables in your Python programs to binary shelf files using the shelve module. This way, your program can restore data to variables from the hard drive. The shelve module will let you add Save and Open features to your program. Look up on the Standard Library documentation information on the shelve module and save the following list:

**cats = [&#39;Zophie&#39;, &#39;Pooka&#39;, &#39;Simon&#39;]**

Use the same module to retrieve this information as a variable.

Takeaway: The open() function can open files to read in their contents as one large string (with the read() method) or as a list of strings (with the readlines() method). The open() function can open files in write or append mode to create new text files or add to existing text files, respectively.

FIN
