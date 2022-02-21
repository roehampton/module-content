# Software Development 2 Seminar 06 -- Coding Standards

When we write software we aim to get our design correct, ensure that our code compiles with no errors and finally we test and debug our program. Is that enough?

In short, no.  Most software goes through a life cycle whereby the design, implementation, testing and release stages are just the start of the life cycle. After an initial version of the software has been released it will require on going maintenance. As you will be aware, software systems don't wear out in the manner that mechanical systems do, e.g. your car will need regular maintenance (such as oil changes) in order to remain running, but software will run indefinitely without degrading.

Software maintenance has two fundamental types of operation:

- Fixing bugs, these may be bugs that have been missed in initial testing or they may be bugs that have come to light due to the software being used in a different manner.
- Adding new features, end users will inevitably demand new and exciting features to be added to the software. In most cases such features will be small enough that a new piece of software cannot be justified, so they will be added to the existing system.

Both of the above activities will involve making changes to the source code of an existing system. It is important to remember that the person making these changes may not be the person who initially produced the software.  It is important that we write our code in a way which makes it understandable to others (and ourselves!).

## Tutorial Task Part 1

Make a note of the time that you are starting this section at *before* you look at the code below.

Have a look at the following function, it is used to print/format invoices for a point of sale system:

```java
public int print(String c, String[] d, int[] q, int[] uc){
  int[] pr = new int [uc.length];

  for(int x=0; x < uc.length;x++)
    pr[x] = uc[x] * q[x];

  System.out.println("I N V O I C E \n");
  System.out.println("Item\tQty\tCost(p)\n");

  if(!c.equals("")){
    System.out.println("Customer: "+c+"\n");
  }

  String lines = "";
  for (int z=0; z  < d.length; z++){
    lines = lines + d[z] + "\tx " + q[z]+ "\t = "+pr[z]+"\n";
  }

  System.out.print(lines+"\n");
  int t=0;
  for(int x=0; x < pr.length;x++)
    t = t + pr[x];

  System.out.println("Total \t\t = "+t);
  t=t+(int)(t*0.2);
  System.out.println("Total+VAT \t = "+t);
  return t;
}
```

When run the function produces formatted output like this:

```
I N V O I C E 

Item	Qty	Cost(p)

Customer: Bob T. Builder

Screw	x 100	 = 300
Nail	x 150	 = 300
Hammer	x 2	 = 1100
Saw	x 1	 = 799
Drill	x 1	 = 3499

Total 		 = 5998
Total+VAT 	 = 7197
```

Now attempt the two tasks given below. Mark your changes on the code above.

### Tasks

- Indicate on the above listing how you would modify the VAT rate to 15%?
- Indicate on the above listing how you would modify the software to print the unit price as well as the total price e.g.:
  `Screw (3)	x 100	 = 300`

Make a note of roughly how long it has taken you to get to this stage.

## Tutorial Task Part 2

As in part 1, make a note of your starting time before going any further.

The following code performs in exactly the same manner as the previous code:

```java
    /**
    * Invoice printer
    */

    private static  final double VAT =0.2;
    //VAT Rate is set to 20%

    public static int printInvoice(String custName, String[] orderDescription, int[] quantities, int[] unitCost){
      /*
      * Print Invoice to the console
      * Parameters:
      * custName: the name to appear on the invoice
      * orderDescription[]: an array of strings describing the items for the invoice
      * quantities[]: an array of ints denoting the quantities of each item being 
      * ordered
      * unitCost[]: the unit cost (in pence) of each item being ordered
      * 
      * Returns the total cost (including VAT) in pence
      */			

      //Print the invoice header
      printHeader(custName);

      //Print the items line by line + return total cost
      int totalPrice = printItems(orderDescription, quantities, unitCost);

      //Print the invoice footer
      totalPrice = printFooter(totalPrice);
      return totalPrice;
  }

  private static int printFooter(int totalPrice) {
    //Print the invoice footer, with total
    //Returns totalPrice with VAT


    System.out.println("\nTotal \t\t = "+totalPrice);
    totalPrice= addVAT(totalPrice);
    System.out.println("Total+VAT \t = "+totalPrice);
    return totalPrice;
  }

  private static int addVAT(int cost){
    //Add VAT 	tost
    return cost+(int)(cost*VAT);	
  }

  private static int printItems(String[] orderDescription, int[] quantities,int[] unitCost) {
    //Prameters as for PrintIvoice()
    //Returns total price (ex VAT)
    int totalPrice =0;//Total cost of items bought
    for (int z=0; z  < orderDescription.length; z++){//Loop through each item
      int price = unitCost[z] * quantities[z];//Calculate price for each 
      //item
      totalPrice = totalPrice + price; 
      //Print line on invoice
      System.out.println(orderDescription[z] + "\tx " + quantities[z]+ "\t = "+price);
    }
    return totalPrice;
  }

  private static void printHeader(String custName) {
    //Print invoice header
    System.out.println("I N V O I C E \n");
    System.out.println("Item\tQty\tCost(p)\n");


    if(!custName.equals("")){
      System.out.println("Customer: "+custName+"\n");
    }

}
```

Have a look at the above code, it performs exactly the same function (the output is identical).

Now undertake tasks 1 and 2 on the above example. Note the time it has taken you to complete task 2.

## Concluding tasks

In groups of 4-5 discuss the following points, when you have finished you should report back to the rest of the class.

- Highlight the main aspects of the coding style that have changed between the two examples
- Suggest a set of coding guidelines that would help improve the readability of your code.

As a class produce a set of guidelines that will improve the readability of your code.