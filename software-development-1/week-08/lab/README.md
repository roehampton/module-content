Lab 8

1. Make a program that &quot;guesses a number&quot; you&#39;ve set. When you run this program, the output will look like this:


        I am thinking of a number between 1 and 20

        Take a guess.

        10
        
        

        Your guess is too low.

        Take a guess.

        15
        
        

        Your guess is too low.

        Take a guess.

        17
        
        

        Your guess is too high.

        Take a guess.

        16
        
        

        Good job! You guessed my number in 4 guesses!



2. Inventory of a Fantasy Game.

You are creating a fantasy video game. The data structure to model the player&#39;s inventory will be a dictionary where the keys are string values describing the item in the inventory and the value is an integer value detailing how many of that item the player has. For example, the dictionary value:


    {'rope': 1, 'torch': 6, 'gold coin': 42, 'dagger': 1, 'arrow': 12} 


means the player has 1 rope, 6 torches, 42 gold coins, and so on.

Write a function named _displayInventory()_ that would take any possible &quot;inventory&quot; and display it like the following:

    Inventory:
    12 arrow
    42 gold coin
    1 rope
    6 torch
    1 dagger
    Total number of items: 62
    
    

Hint: You can use a for loop to loop through all the keys in a dictionary.

3. Create a List to Dictionary Function for the Inventory of a Fantasy Game.

In a famous Japanese RPG, a vanquished dragon&#39;s loot is represented as a list of strings like this:


    dragonLoot = ['gold coin', 'dagger', 'gold coin', 'gold coin', 'ruby'] 


Write a function named _addToInventory(inventory, addedItems)_, where the inventory parameter is a dictionary representing the player&#39;s inventory and the _addedItems_ parameter is a list like _dragonLoot_. The _addToInventory()_ function should return a dictionary that represents the updated inventory. Note that the _addedItems_ list can contain multiples of the same item.


4. Use the setdefault() dictionary method to create a a short program that counts the number of occurrences of each letter in a string.


5. Investigate and use the dictionary&#39;s &quot;Pretty Printing&quot; modules, _pprint_() and _pformat()_ to make a cleaner display for the previous letter counting program


