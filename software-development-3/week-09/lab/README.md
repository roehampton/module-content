# Lab Session 9: GUI 2  "Code behind"

### Make sure you have completed the introduction tutorial to WPF: 
https://moodle.roehampton.ac.uk/pluginfile.php/3079235/mod_resource/content/2/lab-8-introtogui.pdf

## Lab exercise 1

__Create a simple drop-down list using hard-coded values and capture the result__

Your list will drop down and present the users with options "one", "two" and "three".


1. From the "toolbox" menu, drag a 'combobox' into your grid.  Place it where you want it, using the graphical designer or the XAML code - or a mix of both.
2. Create the options for the combobox by adding 'item' elements.  Here is the first one:

```xml
          <ComboBoxItem>one</ComboBoxItem>
```
The item must be 'children' of the ComboBox element ie. must be nested inside it.   
3. Add two more items to complete the option list.  The complete combobox in xmal should look something like this:

```xml
        <ComboBox x:Name="SimpleComboBox" Grid.Column="0" Grid.Row="2">
            <ComboBoxItem>one</ComboBoxItem>
            <ComboBoxItem>two</ComboBoxItem>
            <ComboBoxItem>three</ComboBoxItem>
        </ComboBox>


```

4. To capture the input, you must add an event handler to the combobox.  Add the following as an attribute to your combobox element:

```xml
SelectionChanged="simple_SelectionChanged"
```

Your full ComboBox code now looks like this:

```xml
        <ComboBox x:Name="SimpleComboBox" SelectionChanged="simple_SelectionChanged" Grid.Column="0" Grid.Row="2">
            <ComboBoxItem>one</ComboBoxItem>
            <ComboBoxItem>two</ComboBoxItem>
            <ComboBoxItem>three</ComboBoxItem>
        </ComboBox>

```

5. Hover over your new event handler in the XAML window and follow the link  'go to definition'.  Here you can add  your function body. We will simply, in this case, capture the selected item and show it in a pop up message box.   Your event handler should look like this:

```c#
        private void simple_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            String message = SimpleComboBox.SelectedItem.ToString();
            MessageBox.Show(message);
        }
```

Make sure your option list works as expected, by selecting different options and making sure the message box picks up the chosen option.

## Lab exercise 2: Linking to your OOP code

You will now create a button which when clicked, will 'build' a zoo and display its animals in a textbox.

This is an exercise in which you will be linking your GUI to code you already created, and thereby provding user interaction to existing code.

1. Download the zoo code folder from Moodle: https://moodle.roehampton.ac.uk/mod/resource/view.php?id=1277424.  Add this as a sub-directory of your wpf project.  This is the code we have been working with, including the zoo singleton and just some animal classes, plus a few extra bits.
2. Examine the code and in particular, take a look at the ZooFacade which creates single entry points to the OOP code. (Facade pattern).
3. Create a button labelled 'Build zoo' in your GUI with an event handler called 'BuildZoo_Click'.  It should look a bit like this:

```xml

 <Button Grid.Column="1" Click="BuildZoo_Click" Content="Build zoo" Grid.Row="2" />
```
4. Create a ListBox element with x:Name attribute zooAnimals, it should be a bit like this:

```
    <ListBox Grid.Row="3" x:Name="zooAnimals" Background="#FFC4CEEC" />
```
5. Complete your event handler like this: 

```c#

	private void BuildZoo_Click(object sender, RoutedEventArgs e)
        {
            ZooFacade zooFacade = new ZooFacade();
            zooFacade.BuildZoo();

            foreach (IAnimal animal in zooFacade.getAnimals())
            {

                //  Add the name of the animal to the list of items in the zooAnimals ListBox element
		zooComboBox.Items.Add(new ComboBoxItem(animal.getId(), animal.getName()));
            }
        }
	       

```

6. Now you should find that when you click the button, the ListBox is populated with the zoo animals.  Look at the ZooFacade and play around with the zoo animals created there.

## Lab exercise 3: Creating an options list from the animals in your zoo

Often when we have a list of options, we need to show the user a meaningful text, while being able to capture a unique ID as that is going to be a lot more robust. HTML options lists work like this.  To make a robust option list in WPF we will need a little utility class which is capable of storing an id and value pair.  As this is part of the GUI essentially, lets keep it outside the zoo and in the same directory as MainWindow.xaml.

1. Create a new file called ComboBoxItem.cs and add the following to it:

```c#
using System;
using System.Collections.Generic;

public class ComboBoxItem
{
    public int value { get; set; }
    public string displayValue { get; set; }

    public ComboBoxItem(int value, string displayValue)
    {
        this.value = value;
        this.displayValue = displayValue;

    }

}

```

2. Add a new ComboBox element to your GUI.  Set its x:Name attribute to zooComboBox and add an event handler called zoo_SelectionChanged. Your element will look a bit like this:

```xml

<ComboBox x:Name="zooComboBox" SelectionChanged="zoo_SelectionChanged" Grid.Row="5" Grid.Column="1"/>
```

3. We want this option list to be populated with the zoo animals, so for convenience, lets populate it at the same time as we populated the ListBox. So go back to the BuildZoo_Click event handler and add extra code.  In the loop, populate and add new ComboBoxItem objects to the zooComboBox element, and outside of the loop, we tell the option list where to find the Id (value) which we will probably want to capture in our code, and the human readable name (displayValue), that will be user-friendly.

The whole function should look like this:

```c#
private void BuildZoo_Click(object sender, RoutedEventArgs e)
        {
            ZooFacade zooFacade = new ZooFacade();
            zooFacade.BuildZoo();

            foreach (IAnimal animal in zooFacade.getAnimals())
            {
                zooAnimals.Items.Add(animal.getName());

                zooComboBox.Items.Add(new ComboBoxItem(animal.getId(), animal.getName()));
            }
            zooComboBox.SelectedValuePath = "value";
            zooComboBox.DisplayMemberPath = "displayValue";

        }
```

Once you have added this, you should find that your option list is populated at the same time as your ListBox, once you have clicked the 'build zoo' button.

4. Finally, you want to make sure you can capture the selection made by the user.  You do this in event handler for  your option list.   Hover over Click=zoo_SelectionChanged and go the function definition.  You can retrieve the selected item (DisplayValue and Id) as follows:

```c#
private void zoo_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ComboBoxItem selection = (ComboBoxItem) zooComboBox.SelectedItem;
            MessageBox.Show(selection.displayValue + " " +  selection.value);
        }
```

What is happening here, is that the selected ComboBoxItem is being returned, and we are then accessing its properties to capture the values.

## Lab exercise 4: Add keepers to the zoo via the UI

You will notice that I have added a Keeper class to our zoo, and for convenience, added an additional list to  the zoo singleton to store the keepers.  The zooFacade can handle adding and retrieving the keepers.

Use what you know to add zoo keepers via the user interface.
1. Create a text input for the name
2. Create a second text input for the id
3. Create an 'add keeper' button.  When clicked, this should create a new Keeper object and add it to the zoo via the ZooFacade AddKeeper(keeper) method.


## Lab exercise 5: Add a second option list for keepers, create a button which will capture BOTH the selected keeper and the selected animal, and output both selections to a message box.

You know everything required to do this.  

HINTS:
   * re-use the ComboBoxItem class for the keepers option list
   * you will find that you can select items from both list, and retrieve the selected values in the event handler of the button just as you did in the event handlers of the option lists themselves.



