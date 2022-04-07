# Lab 05A: UML

In this lab we will be examining UML briefly, and class diagrams in detail.  UML (the Unified Modelling Language) is designed to visualise software.  As software has several ways of being viewed, UML likewise provides a number of diagram types.  We will only mention four here but the [Wikipedia page on UML](https://en.wikipedia.org/wiki/Unified_Modeling_Language) points to further information.

## Behavioural Objectives

- [ ] **Define** the *two main types of UML diagram*.
- [ ] **Describe** the *elements of a UML class diagram*.
- [ ] **Add code** to an *application via a class diagram*.

## UML Diagram Types

UML diagrams can be divided into two broad types:

- **Behavioural diagrams**: those which describe the behaviour of the system as it executes.
- **Structural diagrams**: those which describe the static structure of the system.

The four most common diagram types are **use case diagrams**, **activity diagrams**, **class diagrams**, and **sequence diagrams**.  Class diagrams are a *structural diagram* whereas the other three are *behavioural diagrams*.

### Use Case Diagram

We covered use case diagrams in the last lab.  Essentially, use case diagrams try to capture the abstract behaviour of a system at specification time.  They are a useful tool for communicating with stakeholders or providing a high-level overview of specification behaviour.  However, they tend to have little direct mapping to actual code developed.

### Activity Diagram

Activity diagrams you are likely familiar with, although the name might be unusual.  An activity diagram is just a flow chart:

<p><a href="https://commons.wikimedia.org/wiki/File:Activity_conducting.svg#/media/File:Activity_conducting.svg"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/e7/Activity_conducting.svg/1200px-Activity_conducting.svg.png" alt="Activity conducting.svg"></a><br>By ​<a href="https://en.wikipedia.org/wiki/Main_Page" class="extiw" title="en:Main Page">spanish Wikipedia</a> user <a href="https://en.wikipedia.org/wiki/User:Gwaur" class="extiw" title="en:User:Gwaur">Gwaur</a>, <a href="http://creativecommons.org/licenses/by-sa/3.0/" title="Creative Commons Attribution-Share Alike 3.0">CC BY-SA 3.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=4812400">Link</a></p>

Whereas the use case diagram captures functionality required from a user story point of view, the activity diagram allows steps to be defined in the process.  This comes closer to actual code to be written, and can be refined to the point of actual code statements if need be, although that is very low-level.  As a learner, activity diagrams can be very useful to help you map out how to code at a low-level.  As you become more experienced, activity diagrams become more abstract and a communication tool between stakeholders.

### Class Diagram

Is the focus of the main part of the lab so we will cover this later.

### Sequence Diagram

Sequence diagrams map the communication between components (objects) as a system executes, and focuses on the method calls between objects.  For example:

<p><a href="https://commons.wikimedia.org/wiki/File:CheckEmail.svg#/media/File:CheckEmail.svg"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/9b/CheckEmail.svg/1200px-CheckEmail.svg.png" alt="CheckEmail.svg"></a><br>By Coupling_loss_graph.svg - File:CheckEmail.png, <a href="https://creativecommons.org/licenses/by-sa/3.0" title="Creative Commons Attribution-Share Alike 3.0">CC BY-SA 3.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=20544977">Link</a></p>

Here, an object of type `Computer` has a method `checkEmail` called on it.  The `Computer` then calls methods on a `Server` object such as `newEmail`.  The point of the sequence diagram is that it captures actual object interactions.  The sequences themselves are likely already captured in the activity diagram, but now we are using concrete object specifications to bring our solution to code.

## UML Class Diagram Overview

Of the four diagrams discussed, class diagrams are the most complex.  Here is a simple example:

<p><a href="https://commons.wikimedia.org/wiki/File:KP-UML-Generalization-20060325.svg#/media/File:KP-UML-Generalization-20060325.svg"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/6/66/KP-UML-Generalization-20060325.svg/1200px-KP-UML-Generalization-20060325.svg.png" alt="KP-UML-Generalization-20060325.svg"></a><br>By No machine-readable author provided. <a href="//commons.wikimedia.org/w/index.php?title=User:Noodlez84&amp;action=edit&amp;redlink=1" class="new" title="User:Noodlez84 (page does not exist)">Noodlez84</a> assumed (based on copyright claims). - No machine-readable source provided. Own work assumed (based on copyright claims)., Public Domain, <a href="https://commons.wikimedia.org/w/index.php?curid=659677">Link</a></p>

A class diagram attempts to capture the details of a class in a diagram.  There are quite a few details, including:

- the class or interface.
- the name of the class.
- relationships between classes (e.g., inheritance).
- attributes of the class (i.e., class variables) including types.
- methods of the class including parameter and return types.
- the visibility levels of attributes and methods (i.e., *private*, *public*, *protected*).

Each of these points requires some form of visual metaphor:

- classes are represented by rectangles.
- the name is put at the top of the rectangle.
- relationships are shown via lines and arrows between rectangles.
- attributes are listed in a section under the name with types noted after them.
- methods are listed in a section under the attributes with types and parameters noted.
- visibility is marked before an item: `+` for public, `-` for private, and `#` for protected.

### Class Diagram Relationships

There are several different relationship types between classes.  The point of mapping them out is to understand how classes are related so when we make changes we know the likely impact.  Below is the common relationship types:

<p><a href="https://commons.wikimedia.org/wiki/File:Uml_class_relation_arrows_en.svg.png#/media/File:Uml_class_relation_arrows_en.svg.png"><img src="https://upload.wikimedia.org/wikipedia/commons/0/0b/Uml_class_relation_arrows_en.svg.png" alt="Uml class relation arrows en.svg.png"></a><br>By Yanpas - <a class="external free" href="https://commons.wikimedia.org/wiki/File:Uml_classes_en.svg">https://commons.wikimedia.org/wiki/File:Uml_classes_en.svg</a>, <a href="https://creativecommons.org/licenses/by-sa/4.0" title="Creative Commons Attribution-Share Alike 4.0">CC BY-SA 4.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=63418088">Link</a></p>

- *association* is the most generic relationship type.
- *inheritance* means that a class is a specialisation of another class.
- *realization/implementation* is when a class implements an *interface*.
- *dependency* is a special form of association where changes to a class means the dependant class will likely have to change.
- *aggregation* is a special form of association denoting a *has-a* relationship.  This is not considered a strong relationship in so far as the class does not own the associated object.
- *composition* is as aggregation but now the class **owns** the object.  When an instance of the owning object is destroyed so are its components.




## Exercises

Now try to create the relevant diagrams for your project.