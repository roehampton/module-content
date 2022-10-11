

# Data Visualisation Lab 01 -- Basic Data Analysis and Visualisation with Python Libraries

## Environment Setup for Data Visualisation

Python-based computing environments are one of the most popular options among data scientists. Python provides standard, in-built functionalities that can be extended by importing third-party packages. One of the most common third-party libraries include **NumPy**, **matplotlib**, and **seaborn,** which we will use for this week's lab task. We will also use of the **Scipy** library for some calculations. The labs in this module will use Python-powered Jupyter notebooks to create interactive data science computing environments. A **Jupyter** **notebook** consists of code cells that contain code that can be executed and text cells that are used for documentation purposes. Jupyter notebooks are powered by an engine, in our case Python, that can be on your machine (local runtime) or hosted on a remote, cloud-based machine (hosted runtime). The instructions in each lab will assume that you are using **Google Colab,** but you should be able to use other runtimes, too, such as **Anaconda** (local
setup). If you choose other runtimes you might need to do some minor tweaks,
such as installing a library that is provided by the Google Colab environment
by default. In the lab guidelines, you find a guidance on how to use Google
Colab or Anaconda to work on the lab worksheet and questions.

* ***More
  data visualisation tools will be introduced and used in this module and labs
  consequently.***

## 1. Jupyter Notebook

on Web Browser

The Jupyter Notebook is the original
web application for creating and sharing computational documents. It offers a
simple, streamlined, document-centric experience. Jupyter supports over 40
programming languages, including Python, R, Julia, and Scala. It leverages big
data tools, such as Apache Spark, from Python, R, and Scala. You can explore
the same data with pandas, scikit-learn, ggplot2, and TensorFlow. The Classic
Notebook interface is a document-oriented interface that allows you to
create, view, and execute code in a Jupyter Notebook.

Try **Jupyter Notebook** and **Jupyter
Lab** in your web browser; No installation needed:

 [Project Jupyter | Try Jupyter](https://jupyter.org/try)

## >> Install

Jupyter Notebook

You also can Install the classic Jupyter
Notebook on your runtime environment with:

`pip install notebook`

To run the notebook:

`jupyter notebook`

## 2. Google Colab Notebook

Colab, or "Colaboratory", allows you to write and execute
Python in your browser, with zero configuration required, access to GPUs free
of charge, and easy sharing. Whether you're a student, a data
scientist or an AI researcher, Colab an interactive environment
called a **Colab notebook** that lets you write and execute code.

You can get started working on Colab notebook easily: [https://colab.research.google.com/](https://colab.research.google.com/)

Colab notebook also provides **R notebook:**

[Google Colab](https://colab.research.google.com/drive/1xj_aYLBBPX2oSQ1I4xp5_YZiVhhpC1Ke#scrollTo=CxEqIMB8NuXt)

## 3. Anaconda

Environment

Anaconda
Navigator is a desktop graphical user interface (GUI) included in Anaconda®
distribution that allows you to launch applications and easily manage conda
packages, environments, and channels without using command-line commands.
Navigator can search for packages on Anaconda.org or in a local Anaconda
Repository. It is available for Windows, macOS, and Linux.

Follow these
instructions to install Anaconda on your host machine:

[Installation &#8212; Anaconda documentation](https://docs.anaconda.com/anaconda/install/)

The
following applications are available by default in Navigator:

- [Jupyter Notebook](https://jupyter.readthedocs.io/en/latest/)
- [RStudio](http://docs.rstudio.com/)
- [JupyterLab](https://jupyterlab.readthedocs.io/en/stable/)
- [Spyder](https://www.spyder-ide.org/)
- [PyCharm](https://www.jetbrains.com/pycharm/documentation/)
- [VSCode](https://code.visualstudio.com/docs)
- [Glueviz](http://glueviz.org/en/stable/)
- [Orange 3 App](http://orange.biolab.si/docs/)

**Activity 1: Basic Data
Analysis with Python Libraries**

Ø Use **NumPy** to
compute the Mean, Median, Standard Deviation, and Variance

In this activity, you
will use **NumPy** to do some very basic mathematical calculations on
our `**normal_distribution**` dataset. NumPy has a consistent API, so it should be rather
easy to transfer your knowledge of the mean method to median, variance and
standard deviation.

*#importing the necessary dependencies*

**import** numpy **as** np

*#loading the Dataset*

dataset **=** np**.**genfromtxt('./data/normal_distribution.csv', delimiter**=**',')

*#showing the first two rows of the dataset*

dataset[0:2]

#### Mean

***# Question 1) calculate the mean of the first row***

*# **Question 2) calculate the mean of the last column***

***# Question 3) calculate the mean of the intersection of the first 3 rows and first 3 columns***

#### Median

***# Question 4) calculate the median of the last row***

***# Question 5) calculate the median of the last 3 columns***

***# Question 6) calculate the median of each row***

#### Variance

***# Question 7) calculate the variance of each column***

***# Question 8) calculate the variance of the intersection of the last 2 rows and first 2 columns***

***# Question 9) calculate the standard deviation for the dataset***

**Activity 2: Basic Data Visualisation in Python**   

There is a wide array of libraries you can use to create Python
data visualisations, including **Matplotlib, seaborn, Plotly**, and others. These libraries
help you understand data in a variety of ways: distribution, mean, median,
outlier, skewness, correlation, and spread measurements. In order to see what
you can do with a Python visualisation, let’s in this activity try to visualise
our dataset using a simple bar plot.

### 1. Creating Python Visualisations

with **iris** dataset

Let’s use a common dataset featuring data on [*iris
flowers*](https://scikit-learn.org/stable/modules/generated/sklearn.datasets.load_iris.html#sklearn.datasets.load_iris) to understand
data visualisations at the very beginning of this module. The data set consists
of 50 samples from each of the three species of Iris Flower: *Setosa*, *Virginica*,
and *Versicolor*. Here “Species” is target variable (label) and it has 4
features (Sepal Length), (Sepal Width), (Petal Length), and (Petal Width).

### 2. Import Libraries

First import basic libraries like numpy and pandas and Python data
visualisation libraries like matplotlib and seaborn.

```
import pandas as pd
```

```
import numpy as np
```

```
import matplotlib.pyplot as plt
```

```
import seaborn as sns
```

### 3. Understanding the Dataset

Next, load the dataset from **sklearn** libraries:

`from sklearn.datasets import load_iris`

`iris = load_iris()`

Convert this dataset into a data frame and show the top 5 rows
with 4 features (Sepal Length, Sepal Width, Petal Length, Petal width) and one
target variable (Species).

`#` ***Question 10)*** `***print number of rows and columns***`

`**#**` ***Question 11)*** `***Counts of every unique Species value***`

The output should be as follows:

### 4. Visualise Your Data by **Bar

Plot**

A bar plot is a plot that presents categorical data with
rectangular bars. The length or height of bars is proportional to the frequency
of the category. We can count the values of various categories using bar plots.

***#*** ***Question 12)*** `**plot the frequency of the three species in the Iris Dataset.**`

The output should be as follows:

***#*** ***Question 13)*** `**Describe some visual observations you can conclude from the bar plot.**`
