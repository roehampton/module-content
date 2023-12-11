# 'Code behind' - how to get your sprint 1 and 2 code working with the WPF gui

### NB this lab sheet accompanies the video at:
[https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=c671c275-6173-4f43-bb60-af6f01701d66](https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=c671c275-6173-4f43-bb60-af6f01701d66)



##  Setup

   1. Start a new project in visual studio - choose WPF project, tick 'place solution and project in the same directory'.

   2. Import your classes from previous sprints. Suggested way: 
        * Create a new directory, give it an appropriate name.  For ease for now I will call mine sprint2
        * Use the 'Add' menu (right click on the folder name), choose 'add existing', now find your files and add them.

Now all your sprint code is available.

   3. Finally as per week 9, add a grid to your GUI, by adding the following __ <Grid> and </Grid> elements as below.  Make sure you have only one Grid element.

```xml

    <Grid>
        <Grid.RowDefinitions>
                <RowDefinition Height="*" />
                <RowDefinition Height="*" />
            </Grid.RowDefinitions>
        <Grid.ColumnDefinitions>
            <ColumnDefinition Width="*" />
            <ColumnDefinition Width="*" />
        </Grid.ColumnDefinitions>
    </Grid>

```


##  List some animals

Note that your main code won't be relevant as you are now in an 'event driven' environment.  However, code you have previously written in Main can be written as part of your event handlers.

#### Create the GUI elements

Using techniques from Lab 9, lets create a text window in which we can see objects we create listed, and a button we will use to initiate the reation of the objects

Add the following 'StackPanel' element within the grid

```xml
        <StackPanel Grid.Row="0" Grid.Column="0">
            <Button x:Name="btnAddItems" Margin="0,5,0,0" Click="AddItems_Click" Background="#FFA3A9E4">List</Button>
            <ListBox x:Name="listItems" Height="200" Background="#FF945E5E" />
        </StackPanel>

```

This will give you a button and a text area that can be populated with your list.


#### Create the event handler to generate the list of items

Hover over 'AddItems_Click, right click and choose 'go to definition'.  This will take you to the MainWindow.xaml.cs file

In lab 9, we added items to the text box from the GUI, but this time, we will use our existing code.  YOu can use similar code here as you used in your Main method.  _This is the simplist possible solution. If you have implemented the singleton design pattern you can use it here instead._

```c#
   private void AddItems_Click(object sender, RoutedEventArgs e)
        {
            // Clear any previous items in the list
            listItems.Items.Clear();

            // Create some new animals
            Lion l1 = new Lion("lionel", 1);
            Elephant e1 = new Elephant("ellie", 2);
            Lion l2 = new Lion("elsa", 3);

            // Add the animals to the GUI listbox
            listItems.Items.Add(l1.getName());
            listItems.Items.Add(e1.getName());
            listItems.Items.Add(l2.getName());


        }
 

```

#### Create an option list for the animals so we can choose one

You can add a 'combobox drop down as follows in your grid:

```xml
        <StackPanel Grid.Row="0" Grid.Column="1" Margin="0,19,0,142" >
            <Label>Choose an animal to visit</Label>
            <ComboBox x:Name="zooComboBox" SelectionChanged="zoo_SelectionChanged"></ComboBox>
        </StackPanel>
```

#### Populate this combobox at the same time as you build your list

Go back to your AddItems_Click event handler and add the following (in addition to the code above)

```c#

            // Clear any previous items in the combobox
            zooComboBox.Items.Clear();

            // Add items to the combobox. We will make it easy by adding a dynamic class with properties value and displayValue
            zooComboBox.Items.Add(new { value = l1.getId(), displayValue = l1.getName() });
            zooComboBox.Items.Add(new { value = e1.getId(), displayValue = e1.getName() }); 
            zooComboBox.Items.Add(new { value = l2.getId(), displayValue = l2.getName() }); 

            // This tells the combobox where to find the value and display value
            zooComboBox.SelectedValuePath = "value";
            zooComboBox.DisplayMemberPath = "displayValue";

```

#### Add the event handler to respond when an item is chosen

Hover over the zoo_SelectionChanged event subscriber and add the following:

```c#

private void zoo_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            // Retrieve the selected item: its a dynamically created data stucture
            var selection = zooComboBox.SelectedItem as dynamic;

            // Show the items selected
            MessageBox.Show("You choose to visit " + selection.displayValue + " " + selection.value);

        }
```



