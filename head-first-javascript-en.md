《Head First JavaScript》笔记 
 
 Chapter 1   the interactive web



HTML + CSS + JavaScript = REAL Interactivity

Events are notifications that you can respond to with JavaScript code.

A JavaScript alert is a pop-up windows, or box, that you can use to display information to the user. Displaying an alert box involves writing code to call the JavaScript alert( ) function and passing it the text you want to display.

alert(Text to display);
Functions are reusable pieces of code that perform common tasks.



BULLET POINTS

Events are used to respond to web page happenings with JavaScript code.
The onload event is triggered when a page finishes loading.
You respond to the onload event by setting the onload attribute of the <body> tag.
Functions allow you to bundle JavaScript code into reusable modules.
Some functions require you to pass them information to complete their task.
The alert( ) function is built-in JavaScript function that displays a text message in a small pop-up window.


JavaScript allows web pages to DO THINGS, not just play show and tell.



Chapter 2   storing data

JavaScript uses three basic data types: text, number, and boolean.

Variable data can change--constant data is fixed.



A variable is a storage location in memory with a unique name, like a label on a box that's used to store things. A keyword is a word set aside in JavaScript to perform a particular task, like creating a variable.

var Variable_name;
Initialize a variable with "="

var Variable_name = Initial_value;


Initializing a variable is all about setting its first value--there's nothing stopping that value from being changed later.

BULLET POINTS

Script data can usually be represented by one of the three basic data types: text, number, or boolean.
A variable is a piece of data that can change over the course of a script.
A constant is piece of information that cannot change.
The var keyboard is used to create variables, while const is used to create constants.
The data type of a piece of JavaScript data is established when you set the data to a certain value, and for variables the type can change.


Identifiers must abide by a few naming laws laid down by JavaScript:

An identifier must be at least one character in length.
The first character in an identifier must be a letter, an underscore ( _ ), or a dollar sign ( $ ).
Each character after the first character can be a letter, an underscore ( _ ), a dollar sign ( $ ), or a number.
Spaces and special characters other than _ and $ are not allowed in any part of an identifier.
lowerCamelCase is used to name multiWord variables.



A piece of data is undefined when it has no value.

NaN means Not a Number, NaN is a value that isn't a number even though you're expecting the value to be one.



parseInt( )

Give this function a string and it converts the string to an integer.

parseFloat( )

Give this function a string and it converts the string to a floating point (decimal) number.

Keep in mind that the parseInt( ) and parseFloat( ) functions aren't guaranteed to always work. They'll do their best at converting strings to numbers, but the idea is that you should be providing them with strings that only contain numeric characters.



BULLET POINTS

Although not a strict JavaScript requirement, it's a good coding convention to name constants in ALL UPPERCASE and variables in lowerCamelCase.
Always initialize constants when you create them, and initialize variables whenever possible.
When a variable isn't initialized, it means undefined until a value is eventually assigned to it.
NaN stands for Not a Number, and is used to indicate that a piece of data is not a number when the expectation is that it should be.
String concatenation is very different from mathematical addition, even though both use the familiar plus sign ( + ).
The built-in parseInt( ) and parseFloat( ) functions are used to convert strings to numbers.
An empty string is a clue that a form field has no data.



Chapter 3   exploring the client



You client web browser is responsible for running JavaScript code, which allows scripts access to the client environment.

Browser metrics

Browser metrics include various measurements associated with the size of the browser window, the viewable web page, and even information about the browser vendor and version number.

Browser history

The browser history is the list of recent pages visited. You can use JavaScript to access this list of pages and direct the browser to one of them, effectively creating your own browser navigation controls.

Cookies

Cookies are like variables that get stored on the user's hard drive by the browser so that they last beyond a single web session. In other words, you can leave a page and come back, and the data's still there.

Timers

Timers allow you to trigger a piece of JavaScript code after a specified amount of time has elapsed.



JavaScript timers are triggered when a certain amount of time has passed, as opposed to triggering at a certain time.

Timers let you run JavaScript code after a certain amount of time has elapsed.



The setTimeout( ) function

setTimeout(Timer code, Timer delay);
Setting an interval timer is similar to setting a one-shot timer, except you call the setInterval( ) function instead of setTimeout( ). The end result of setting an interval timer is code that gets run over and over as each interval delay expires.



The client window is only the part of the browser window that displays a web page.

The dramatic variation in browser sizes across all computers capable of browsing the Web, including tiny handheld devices and desktop computers with gigantic monitors.

The body.clientWidth and body.clientHeight properties of the document hold the width and height of the client window.



BULLET POINTS

The setTimeout( ) function allows you to create a one-shot timer that triggers JavaScript code after a period of time has elapsed.
To set a timer that repeats at a certain interval, use setInterval( ), which will create an interval timer.
Always specially timer durations in milliseconds, which are thousandths of a second.
Web page elements have a style object you use to set style properties, such as width and height.
The client window is the part of the browser window that displays the web page and nothing else.
You can access the width and height of the client window using the body.clientWidth and body.clientHeight properties of the document object.


The onresize event makes it possible to detect and respond to changes in the browser window size.

JavaScript destroys ALL variables when the browser closes or the page reloads.



BULLET POINTS

A cookie is a piece of text data stored by the browser on the user's computer.
Cookies allow scripts to store data that survives beyond a single web session.
Every cookie has an expiration date, after which the cookie is destroyed by the browser.
Moving script code to an external file is a handy way to make the code more reusable and maintainable.
Cookies can't access a user's hard disk or spread viruses, but they are capable of storing personal data that has been entered in web pages.


Chapter 4   decision making



The if statement is an excellent way to conditionally run a piece of code.

if (Test condition)
    Statement;
Adding an else to if statement.

if (Test condition)
    Statement1;
else
    Statement2;


 BULLET POINTS

Use the if statement to conditionally run a single piece of JavaScript code.
The test condition in an if statement must always result in true or false.
Use the if/else statement to conditionally run one of two different pieces of JavaScript code.
Use a compound statement to run multiple pieces of JavaScript code in place of a single piece of code.
Create a compound statement by surrounding multiple individual statements with curly braces ( { } ).
Compound statement allow the action parts of if and if/else statements to do more than one thing.


Single-line comments start with //, while multiline comments are enclosed between /* and */.

// Comment

/* State of comment
   More comment
   End of comment */
Local variables store temporary information, global variables are stored for the life of the script.

BULLET POINTS

Comments are a great way to remind yourself of code to add later.
Don't be afraid to use lots of comments to document your code so that it's easier to understand.
Use a pair of forward slashes ( // ) to start a single-line comment.
Multiline comments start with /* and end with */.
Global variables are created at the script level, outside of any function or other body of code, and are kept around for the life of the script.
Local variables are created (and destroyed) inside a body of code, and can only be accessed within that code.
Local variables are preferred over global variables because their access is more tightly controlled.


Choice of five

if (chosenCase == "A")
    openCase("A");
else if (chosenCase == "B")
    openCase("B");
else if (chosenCase == "C")
    openCase("C");
else if (chosenCase == "D")
    openCase("D");
else if (chosenCase == "E")
    openCase("E");


The switch/case statement efficiently chooses between more than two things.

switch (chosenCase) {
case "A":
    openCase("A");
    break;
case "B":
    openCase("B");
    break;
case "C":
    openCase("C");
    break;
case "D":
    openCase("D");
    break;
case "E":
    openCase("E");
    break;
}
Here's the general format for the switch/case statement.

switch (Test data) {
case Match 1:
    Statement;
    ...
    break;
...
default:
    Statement;
    ...
    break;
}
Switch case statement process as following:

Enclose the test data in parentheses and open the compound statement ( { ).
Write the case match followed by a colon ( : ).
Write the code that gets run if there is a match. This can be multiple lines code--there is no need for a compound statement.
Add a break statement--don't forget the semicolon ( ; ).
Optionally include a default branch for when there is no match.
Close the compound statement ( } ).


Chapter 5   looping



For loops let you repeat code a certain number of times.

A for loop consists of four different parts:

1.   Initialization

Initialization takes place one time, at the start of a for loop.

2.   Test condition

The test condition checks to see if the loop should continue with another cycle.

3.   Action

The action part of the loop is the code that is actually repeated in each cycle.

4.   Update

The update part of the loop updates any loop variables at the end of a cycle.

for loop format:

for (Init; Test; Update)
    Action;
Arrays store multiple pieces of data in a single place.



BULLET POINTS

for loops repeat a piece of JavaScript code a specific number of times.
The increment ( ++ ) and decrement ( -- ) operators provide a handy way to update loop counters.
An array allows you to store multiple pieces of data in a single place.
Although an array holds multiple pieces of information, it has a single variable name.
Indexed arrays are accessed using numeric keys called indexes.
Indexed arrays work great with loops because they allow you to use a loop counter to loop through array data.


Boolean logic operators can be combined to carry out complex decisions.

while loops let you repeat code while a certain condition is true.

while (Test)
    Action;


BULLET POINTS

The break statement immediately breaks out of a loop, skipping any remaining loop code.
Boolean logic operators allow you to create powerful true/false logic for making decisions.
The while loop runs a piece of code as long as a certain test condition remains true.
Avoid an infinite loop by making sure the test condition is somehow affected by code within the while loop.


A while loop can do everything a for loop can do, and vice versa.

Init;
while (Test) {
    Action;
    Update;
}
Two-dimensional arrays allow you to store tabular data.



BULLET POINTS

Two-dimensional arrays allow you to store rows and columns of data in tabular structures.
When accessing an individual piece of data in a 2-D array, you must specially both the row and column of the index.
Nested loops can be used to iterate through the data in a 2-D array.
Just like normal arrays, 2-D arrays can be created and initialized from array object literals.


Chapter 6   functions



Functions turn big problems into small problems.

The most basic JavaScript function syntax:

function Name() {
    Body
}
One or more arguments can appear inside the parentheses.

function Name(Arguments) {
    Body
}
BULLET POINTS

Functions allow you to turn big problems into small problems, which become much easier to solve.
Functions provide a mechanism to separate script tasks and then complete them with reusable chunks of code.
Functions serve as a great way to eliminate duplicate code since the code in a function can be reused as many times as you want.
Arguments allow you to pass data into functions as input for a given task.


A return value allow you to return a piece of data from a function.

The return value of a function replaces the call to the function.

The return statement can be used by itself to end a function.



BULLET POINTS

The return statement allows functions to return data back to the code that called them.
When a piece of data is returned from a function, it stands in for the code that called the function.
A function can only return a single piece of data.
The return statement can be used without any data to simply end a function early.


Separating functionality from content makes web applications easier to build and maintain.

A function is really just a variable whose value is a reference to the function body.

Function references provide a convenient way to wire event handler functions to events.

Function literals let you create anonymous event handler functions.

The onload event handler is an excellent place to initialize all events.



BULLET POINTS

Callback functions are called by the browser in response to things that take place outside of the script.
Function references can be used to assign functions as if they were variables.
Function references let you wire event handler functions in JavaScript code without altering HTML code.
Function literals are nameless functions that are handy in situations when a named function isn't necessary.


Chapter 7   forms and validation



Entering data into a form sets off a chain of interesting JavaScript events.

Select the input field (onfocus).
Enter data into the field.
Leave the input field to move to the next one (onblur/onchange).
Select the next input field (onfocus).
Enter data into the field...
The onblur event is a perfect trigger for data validation.

A non-empty validation function checks to make sure form fields aren't left empty.



BULLET POINTS

Every form filed is accessible as a JavaScript object.
Within a form object there is a property called form that represents the entire form as an array of fields.
The onblur event is fired when the input focus leaves a form field, and is a great way to trigger a data validation function.
Alert boxes are a very clunky and often annoying way of notifying user of data validation problems.
A passive approach to validation help is much more intuitive and less of a hassle for users.
The length property of a string reveals the number of characters in the string.


The steps of how a date validation function might work:

Break apart form field value into a collection of substrings, using a forward slash as the basis for separating the string.
Analyze the month substring to make sure it is exactly two characters in length and that it is a number.
Analyze the day substring to make sure it is exactly two characters in length and that it is a number.
Analyze the year substring to make sure it is exactly four characters in length and that it is a number.
Ignore any other data following the second forward slash.


Quantifiers are applied to sub-patterns that precede them within a regular expression, and provide control over how many times a sub-pattern appears in a pattern.

*

Preceding sub-pattern must appear 0 or more times.

+

Preceding sub-pattern must appear 1 or more times.

?

Preceding sub-pattern must appear 0 or 1 time.

{ n }

Preceding sub-pattern must appear exactly n times in a row.

( )

Group characters and/or metacharacters together in a sub-pattern.



Quantifiers control the number of times a sub-pattern appears in a regular expression.



The test( ) method of the RegExp object is used to test a string for a regular expression pattern.

The following steps must be carried out by the general validateRegEx( ) function:

Perform a test on the regular expression that is passed as an argument, using the input string that is also passed in.
If the pattern matches, set the help message to the help text that is passed as an argument, and then return false.
If the pattern doesn't match, clear the help message and return true.


{ min, max }

Preceding sub-pattern must appear at least min times in a row but no more than max times.



BULLET POINTS

A regular expression matches a pattern of text in a string, and is enclosed within forward slashes.
In addition to normal text, regular expressions are built out of metacharacters and quantities, which provide careful control over how a text patterns is matched.
In JavaScript, regular expressions are supposed by the built-in RegExp object, but it is rarely seen because regular expressions are typically created as literals.
The test( ) method in the RegExp object is used to a test a regular expression pattern on a string of text.


this | that

The pattern matches if the this sub-pattern or the that sub-pattern match.



[ChracterClass]

CharacterClass is a set of regular expression rules for matching a single character.

Character classes offer an efficient way to control optional characters in a regular expression pattern.



Chapter 8   wrangling the page



The innerHTML property provides access to all of the content stored in an element.

DOM means the Document Object Model.

The DOM "sees" a web page as a hierarchical tree of nodes.

DOM nodes are classified according to their node types.

DOCUMENT

The top node in a DOM tree, representing the document itself, and appearing just above html element.

ELEMENT

Any HTML element that corresponds to a tag in HTML code.

TEXT

The text content for an element, always stored as a child node beneath an element.

ATTRIBUTE

An attribute of an element, accessible through an element node, but not present directly in the DOM tree.



Node properties are handy for traversing through nodes in the DOM tree.

nodeValue

The value stored in a node, only for text and attribute nodes (not elements).

nodeType

The type of a node, such as DOCUMENT or TEXT, but expressed as a number.

childNodes

Arrays containing all of the child nodes beneath a node, in the order that the nodes appear in the HTML code.

firstChild

The first child node beneath a node.

lastChild

The last child node beneath a node.



Three (safe) steps for changing node text.

Remove all child nodes.
Create a new text node based upon the new content.
Append the newly created text node as a child node.
Do this with three DOM methods:

removeChild( ) - Remove a child node from a node; pass in the child node to be removed.
createTextNode( ) - Create a text node from a string of text.
appendChild( ) - Add a node as the last child of the node; pass in the child node to be added.


BULLET POINTS

Although not a web standard, the innerHTML property provides access to all of the content stored in an element.
The Document Object Model, or DOM, provides a standardized mechanism of accessing and modifying web page data.
The DOM look at a web page like a hierarchical tree of related nodes.
The DOM alternative to changing web page content with innerHTML involves removing all of the child nodes of an element, and then creating and appending a new child node that contains the new content.


The DOM is a web standard way of manipulating HTML that allows more control than using the innerHTML property.



The className property of a node provides access to the style class.

The style property of a node provides access to individual style properties.



BULLET POINTS

The className node property makes big style changes by changing the entire style class of a node.
The style node property makes small style changes by providing access to individual style properties of a node.
A CSS style class has nothing to do with a JavaScript class--they are completely different things.
Elements on a page can be dynamically shown or hidden using the visibility style property of the element object.
The display style property can accomplish a similar show/hide effect by setting it to display:none (hide) or display:block (show).


A decision history feature in Stick Figure Adventure can be a very useful story debugging tool.



BULLET POINTS

Any HTML element can be created using the document objects creatElement( ) method.
To add text content to an element, a child text node must be created and appended to the element.
By carefully adding and removing nodes in the DOM tree, a web page can be disassembled and reassembled at will.


Chapter 9   bringing data to life



Data + actions = object

Objects link variables and functions together inside a storage container.

Properties and methods are the object equivalents of variables and functions.

You typically access object properties and methods using a special operator called the dot operator.

Object.Property/Method
The dot operator references a property or method from an object.

BULLET POINTS

 Objects are a special kind of data structure that combine data with code that acts on the data.
In practical terms, an object is really just variables and functions combined into a single structure.
When placed into an object, variables become known as properties, while functions become known as methods.
Properties and methods are referenced by supplying the name of the object followed by a dot followed by the name of the property or method.


A custom object allows the two pieces of blog data to be combined into a single entity.

A constructor is responsible for creating an object.

The this keyword is the key to creating object properties inside a constructor.

function Invitation(who, what, when, where) {
    this.who = who;
    this.what = what;
    this.when = when;
    this.where = where;
}
The built-in Date object represents a moment in time.

Within the Date object, time is expressed in milliseconds.

The new operator creates objects with the help of constructors.



BULLET POINTS

The standard JavaScript Date objects represents an instant in time, expressed in milliseconds.
The Date object includes several methods for accessing the different pieces and parts of a date and time.
The Date object is smart enough to know how to manipulate dates mathematically, as well as compare dates to each other.
Like most objects other than String, you create a Date object using the new operator.


The toString( ) method provides a string representation of an object.

An array is really just an object.



The sorting behavior is determined by a comparison function that sort( ) calls to handle the comparison of each sorted item in an array. Here's an example of what the function typically looks like:

function compare(x, y) {
    return x = y;
}
The return value of the compare( ) function is a number that determines the resulting sort order of x as compared to y.

Your custom compare( ) function is injected into the array sorting equation when you call the sort( ) method--just pass a reference to the compare( ) function into the method.

nums.sort(compare);
BULLET POINTS

The toString( ) method is used to convert any object to a text representation.
Arrays and string are both really just objects, relying on the standard Array and String objects in JavaScript for their methods and data storage.
The sort( ) method of the Array object can be used to sort an array in any order you want.
The indexOf( ) method in the String object searches for a string of text within another string, returning the index of the search string location.


The Math object is an organizational object that hoses math methods and constant.



Chapter 10   creating custom objects



An object class is a template, while an object instance is the thing created from the template.

The this keyword is used to set properties and methods that are owned by an instance.

Storing a method in a class allows all instances to share one copy.



BULLET POINTS

A class is a description of an object, while an instance is an actual object that has been created based upon that description.
A class lays out the properties and methods of an object, while an instance places real data in the properties, giving the methods something to work with.
The this keyword is used to access an instance from within its own code.
The prototype object allows methods to be stored in a class, preventing instances from unnecessarily duplicating code.


A class properly is stored once in a class but accessible to all instances.

The prototype object allows you to extend built-in JavaScript objects.

Class methods are owned by a class, and can only access class properties.



Chapter 11   kill bugs dead



Mismatched or missing curly braces are a common JavaScript bug that can be avoided with attention to detail.

Something as simple as a typo can often wreak havoc on a script.



BULLET POINTS

Although most browsers provide an error console that provides information about JavaScript errors, they can't always be trusted as completely accurate.
Even though browsers often yield sketchy error information, they do usually provide valuable clues about where to start looking for trouble.
Curly braces around blocks of code are a common source of bugs--be careful to always match opening and closing braces.
Simple typographical error are easy to make but not necessarily easy to find--always check the naming of identifiers.


Syntax errors are always reported by browsers, assuming that error reporting is enabled.

Quotes and apostrophes should be alternated when using JavaScript strings in HTML attributes.

Escape characters are used to specify literal characters in strings.

Alert boxes can be very handy for getting a quick look at the value of a variable.



BULLET POINTS

Syntax errors involve code that violates JavaScript language rules, and are usually caught by the JavaScript interpreter.
Strings must be carefully enclosed within matching quotes or apostrophes.
Quotes and apostrophes should be mixed (but still in matching pairs) in HTML event handler attributes that contain JavaScript code.
Alert boxes offer a primitive but useful option for watching variables throughout a script.
It's a common error to accidentally code a test condition with = when you really mean ==.


Runtime errors occur only because of specific conditions that take place while a script is running.

Comments are extremely useful for temporarily disabling code.

A shadow variable occurs when local and global variables are created with the same name... not good!



Chapter 12   dynamic data



Ajax allows a web page to dynamically receive data from a web server.

XML is a markup language used to format any kind of data.



JavaScript to the Ajax rescue: XMLHttpRequest

readyState

The numeric state of the request: 0 (uninitialized), 1 (open), 2 (sent), 3 (receiving), or 4 (loaded).

status

The HTTP status code of the request, such as 404 (not found) or 200 (OK).

onreadystatechange

A reference to the function that is called when the state of the request changes. (This property is unique in that it holds a reference to the custom event handler that is called when the state of the Ajax request changes -- this event handler function is where the response is processed.)

responseText

The response data returned from the server, as a string of plain text.

responseXML

The response data returned from the server, as an object consisting of a tree of XML nodes.

abort( )

Cancel the request. (This method is only used if the Ajax request needs to be cancelled.)

open( )

Prepare a request by specifying its type and URL, among other things.

send( )

Send the request to the server for processing.



The two types of requests used with Ajax are GET and POST, the same ones used when submitting HTML forms.

GET

Used for data retrieval that doesn't change anything on the server. Small amounts of data can still be sent to the server in the URL, if necessary. GET is perfect for retrieving the data from an XML file on the server.

POST

Used to send data to the server that somehow causes change in the state of the server, such as saving data to a database. Data can still be returned in a response. POST is ideal for a task such as dynamically adding a new blog entry to the blog using a web form.



The send( ) method is used to prepare and issue an Ajax request to a server in a single call. All Ajax requests issued using send( ) are either GET or POST requests, which correspond to HTML form submission requests. The difference is that an Ajax request doesn't require a complete reload of a page.

send(type, url, handler, postDataType, postData)
type

The type of the request, GET or POST.

url

The URL of the server. Data can be packaged into this URL if necessary.

postDataType

The type of data being sent (only for POSTs, not required for GETs).

handler

The callback function used to handle the response.

postData

The data to be sent (only for POSTs, not required for GETs). POST data can be submitted in several different formats.



BULLET POINTS

The XMLHttpRequest object is the standard object for carrying out Ajax requests but it can be somewhat messy to use.
The custom AjaxRequest object serves as a convenient way to use Ajax without having to deal directly with XMLHttpRequest.
Ajax requests always fall into one of two types, GET or POST, which is determined by the data being sent to the server, as well as how the data affects the server.
The send( ) method of the AjaxRequest object.


The client script handles the response to an Ajax request using a custom callback function.



The familiar <script> tag is used to import JavaScript code that is stored in external files.

the end.

