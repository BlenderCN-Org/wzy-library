《Head First PHP & MySQL》笔记

环境：PHP 5 & MySQL 5.0

Chapter 1 



PHP is a server-side programming language - it runs on a web server.



A form element's action attribute is what connects a form to a PHP script, causing the script to run when the form is submitted.



Fundamental rules of the PHP:

PHP code is always enclosed by <?php and ?>.
Every PHP statement must end with a semicolon ( ; ).
If there is any PHP code in a web page, it's a good idea to name the file on the web server with .php not .html.
PHP variable names must begin with a dollar sign ( $ ).


Rules to create legal variable names:

The first character must be a dollar sign ( $ ).
A variable name must be at least one character in length.
The first character after the dollar sign can be a letter or an underscore ( _ ), and characters after that can be a letter, an underscore, or a number.
Spaces and special character other then _ and $ are not allowed in any part of variable name.
Use all lowercase for variable names.
Separate words in a multi-word variable name with underscore.


Chapter 2   Connecting to MySQL



MySQL stores data inside of database tables (the "SQL" in MySQL stands for Structured Query Language).

SQL is the query language used to communicate with a MySQL database.



Use PHP functions to talk to the database

Connect to a database with the mysqli_connect( ) function.
Create an SQL query and store it as a string in a PHP variable.
Issue the query with the mysqli_query( ) function.
Close the database connection with the mysqli_close( ) function.
The mysqli_connect( ) function treats the location, username, password, and database name as strings, so you must quote them.



The PHP die( ) function terminates a PHP script and provides feedback about code that failed.





An SQL query is a request written in SQL code that is sent to the database server.

The mysli_query( ) function requires a database connection and a query string in order to carry out an SQL query.





Database servers only have a certain number of connections available at a time, so they must be preserved whenever possible.



The SQL SELECT statement lets you tack on clause to control the data returned by the query. It's called WHERE, and you tell it exactly how you want to filter the query results. As follow:

SELECT * FROM aliens_abduction WHERE fang_spotted = 'yes'


Chapter 4   Create and populate a database



CREATE DATABASE is the SQL command used to create a new database.

CREATE DATABASE database_name
Table rows are horizontal, and table columns are vertical.



The CREATE TABLE SQL command is used to create a new table in a database.

CREATE TABLE table_name
(
    column_name1 column_type1,
    column_name2 column_type2,
    ...
)
The USE command selects a database as the default database for subsequent SQL statement.

USE database_name
DESCRIBE reveals the structure of tables.

DESCRIBE table_name


The DROP TABLE command deletes a table AND all its data from the database.

DROP TABLE table_name


A while loop repeats code while a condition is met.

while (test_condition) {
    action
}
DELETE can be used to pinpoint a specific row or rows for deletion.

DELETE FROM talbe_name
A WHERE clause in a DELETE statement lets you pinpoint the row you want to remove, as follow:

DELETE FROM email_list
    WHERE email = 'pr@honey-doit.com'


 Chapter 4    Realistic and practical applications



Validation means making sure the data you get is the data you expect.



The basic if statement has three parts:

The if keyword-This starts off the statement
The test condition-The test condition, or conditional expression, is located in parentheses right after the if keyword. Here's where you put the statement that you want to determine the validity, or truth, of.
The action-The action of an if statement directly follows the test condition and is enclosed in curly braces. Here's where you put the PHP code you want to execute if the condition is, in fact, true.


isset( ) checks that a variable exists and is set.

empty( ) checks to see if a variable has any contents.



PHP logic operators make it possible to structure more elegant if statements.

Logical AND is coded as &&, while logical OR is coded as ||.

The else clause executes code when an if test condition is false.



You can close and open blocks of PHP code to output chunks of HTML code in a PHP script.

By making HTML code dependent on an IF statement, we avoid duplicate code in our script.



$_SERVER['PHP_SELF'] stores away the name of the current script.

The $_POST superglobal allows us to check and see if a form has been submitted.

if (isset($_POST['submit'])) {
   ...
}


DROP TABLE would destroy data, but SQL has another command that lets you make changes to an existing table without losing any data. It's called ALTER TABLE, and we can use it to create a new column without having to drop the table and destroy its data. Here's what the general format of an ALTER TABLE statement looks like for adding a new column to a table:

ALTER TABLE table_name ADD column_name column_type


The foreach loop takes an array and loops through each element in the array without the need for a test condition or loop counter. As it steps through each element in the array, it temporarily stores the value of that element in a variable. Assuming an array is stored in a variable named $customers, this code steps through each one:

foreach ($customers as $customer) {
    echo $customer;
};


Chapter 5   Working with data stored in files



Image filenames are stored in the database as part of an INSERT statement.

The $_FILES built-in superglobal variable provides access to information about uploaded files.

Databases are great for storing text data, but it's usually better for them to reference binary data in external files.



SHARED script data needs to be accessible throughout an application without code duplication.

Include files allow you to SHARE code across multiple scripts.

The REQUIRE_ONCE statement inserts SHARED script code into other scripts.



Web applications often include pages for public access, as well as admin pages that are only for site maintenance.

The URL of a script can be used to pass data as a GET request.



The two types of web requests, GET and POST, control how you shuttle data between scripts.

The real distinction between GET and POST has to do with the intent of a request. GET is used primarily to retrieve data from the server without affecting anything on the server. POST, on the other hand, typically involves sending data to the server, after which the state of the server usually changes somehow in response to the data that was sent.



Chapter 6   Securing your application



The header( ) function lets you create and send a header from a PHP script.

PHP scripts can use headers to control how the server delivers web content to the browser.
The built-in PHP header( ) function is used to send headers to the browser, which can be used to redirect a page, control the content type of a page, or request the authentication of a page.
When headers are sent to the browser using the header( ) function, calls to the header( ) function must come before any other content is sent.
When a page is protected using HTTP authentication, the user name and password entered by the user are stored in the $_SERVER superglobal.
The "basic realm" of an HTTP authentication is a security zone that gets associated with a specific user name and password, allowing multiple pages to be secured together.
The built-in PHP exit( ) function exits a PHP script, preventing any code following it from being executed or otherwise sent to the browser.


Form fields are a security weak point for web applications because they allow users to enter data.

SQL injections can be prevented by properly processing form data.



The SQL DEFAULT command is what allows you to specify a default value for a column, as following:

ALTER TABLE guitarwars
MODIFY COLUMN approved TINYINT
DEFAULT 0
Whenever possible, insist on form data being in the format you've requested.



PHP & MySQL Toolbox



header( )

This built-in PHP function is used to send a header from the server to the browser, allowing you to perform tasks such as redirecting the page, specifying a certain content type, or carrying out HTTP authentication.

$_SERVER

Among other things, this built-in PHP superglobal stores the user name and password entered by the user when attempting to access a page REQUIRING HTTP authentication. You can check these against expected values to protect pages that need to be secured.

exit( )

This built-in PHP function causes a PHP script to stop immediately. Once a script encounters the exit( ) function, no additional PHP code is executed and no additional HTML code is delivered to the browser.

is_numeric( )

This built-in PHP function checks to see if a value is a number. It is useful for checking to see if a numeric form field actually holds a numeric value.

trim( ), mysqli_real_excape_string( )

These two built-in PHP function are handy for processing form data and preventing problematic characters from interfering with SQL queries. The first function trims leading and trailing spaces, while the latter escapes special characters.

DEFAULT value

This SQL statement establishes the default value of a column in a table. If a new row is added and the column isn't set, it will take on the default value.

Human Moderation

Everything in moderation! In this case, it means that a human being is often the best line of defense in identifying and eliminating unwanted content being posted by others. Automated security techniques are still important, but it's hard to beat a living, breathing person with a brain!

SQL Injection

A security breach that involves an evil-doer somehow compromising a SQL query to gain unwarranted access to a database. Most SQL injections involve tricking a web form into passing along dangerous data directly to a dynamically constructed query. So form validation is often the solution.

HTTP Authentication

A simple web security technique that limits access to a web page or script using a user name and password. Although not intended for highly sensitive security applications, HTTP authentication can be handy for quickly adding a degree of security to a web application.

Column/Value Query

A type of INSERT query where columns and their respective values are carefully matched to each other, as opposed to relying on the order of the data matching the structural order of the columns in the table.

Form Validation

The process of checking all of the data entered by a user into a form to ensure that it is in the expected format. In addition to making forms easier to use, validation can help make web applications more secure by not allowing users to enter bad data.



Chapter 7   Building personalized web apps



Prepping the database for log-ins

Use ALTER to add username and password columns to the table.
Build a new Log-In script that prompts the user to enter their username and password.
CONNECT the Log-In script to the rest of the Mismatch application.


An application log-in requires a user interface for entering the username and password.

The MySQL SHA( ) function encrypts a piece of text into a unique 40-character code. For example, this code inserts a new user into the mismatch_user table, making sure to encrypt the password with SHA( ) along the way:

INSERT INTO mismatch_user
  (username,password,join_date) VALUES ('jnettles', SHA('tatlover'), NOW())
The SHA( ) function provides one-way encryption-you can't decrypt data that has been encrypted.



HTTP authentication stores data persistently on the client but doesn't allow you to delete it when you're done.

Cookies allow you to persistently store small pieces of data on the client that can outlive any single script... and can be deleted at will!

The PHP setcookie( ) function allows you to store data in cookies.

setcookie ('username', 'sidneyk');
echo('<p class="login">You are logged in as ' . $_COOKIE['username']. '.</p>';
setcookie ('user_id', '1');
To delete a cookie, just set its expiration date to a time in the past.

Logging out a user involves deleting the two cookies that keep track of the user. This is done by calling the setcookie( ) function, and passing an expiration date that causes the cookies to get deleted at that time.

setcookie('username', 'sidneyk', time() + (60*60*));
Log out with sessions:

Delete the session variables.
Check to see if a session cookie exists, and if so, delete it.
Destroy the session.
Redirect the user to the home page.


Sessions allow you to persistently store small pieces of data on the server, independently of the client.

Since session data is stored on the server, it is more secure and more reliable than data stored in cookies.

The PHP session_start function starts a session and allows you to begin storing data in session variables.

The session_destroy( ) function closes a session.

Session variables are not automatically deleted when a session is destroyed.

Session variables are destroyed when the user ends a session by closing the browser. Cookies are destroyed when they expire, giving them a longer lifespan than session variables.



PHP & MySQL Toolbox



setcookie( )

This built-in PHP function is used to set a cookie on the browser, including an optional expiration date, after which the cookie is destroyed. If no expiration is provided, the cookie is deleted when the browser is closed.

$_COOKIE

This built-in PHP superglobal is used to access cookie data. It is an array, and each cookie is stored as an entry in the array. So accessing a cookie value involves specifying the name of the cookie as the array index.

SHA (value)

This MySQL function encrypts a piece of text, resulting in a string of 40 hexadecimal characters. This function provides a great way to encrypt data that needs to remain unrecognizable within the database. It is a one-way encryption, however, meaning that there is no "decrypt" function.

session_start( )

This built-in PHP function starts a new session or re-starts a pre-existing session. You must call this function prior to accessing any session variables.

$_SESSION

This built-in PHP superglobal is used to access session data. It is an array, and each session variable is stored as an entry in the array. So accessing the value of a session variable involves specifying the name of the variable as the array index.

session_destroy( )

This built-in PHP function closes a session, and should be called when you're finished with a particular session. This function does not destroy session variables; however, so it's important to MANUALLY clean those up by clearing out the $_SESSION superglobal.



Chapter 8   Control your data, control your world



A description of the data (the tables and columns) in your database, along with any other related objects and the way they all connect is known as a schema.

Creating a diagram of a table lets you keep the design of the table separate from the data that's inside of it.

A foreign key is a column in a table that references the primary key of another table.

Build a Mismatch questionnaire

Use INSERT to add empty response rows to the database the first time the user accesses the form.
Use UPDATE to change response rows based on user responses on the form.
Use SELECT to retrieve the response data required to generate the questionnaire form.
Generate the HTML questionnaire form from response data.
Data-driven dorms rely on data in a MySQL database to generate HTML form fields.

The ternary ? : operator can be used to code if-else statements in a more compact form.



Normalization means designing a database to reduce duplicate data and improve the relationships between data.

Atomic data is atomic data that has been broken down into the smallest form needed for a given database.

Normalization has its benefits, namely improvements in database size and speed.



Normalizing a database involves strictly adhering to a series of design steps.

Make sure your columns are atomic.
Give each table its own primary key.
Make sure non-key columns aren't dependent on each other.


Altering the Mismatch database

In order to take advantage of the new schema, the Mismatch database requires some structural changes. More specifically, we need to create a new mismatch_category table, and then connect it to a new foreign key in the mismatch_topic table. And since the old category column in the mismatch_topic table with all the duplicate category data is no longer needed, we can drop it.

CREATE TABLE mismatch_category (
    category_id INT NOT NULL AUTO_INCREMENT,
    name VARCHAR(48) NOT NULL,
    PRIMARY KEY (category_id)
)

ALTER TABLE mismatch_topic
DROP COLUMN category

ALTER TABLE mismatch_topic
ADD COLUMN category_id INT NOT NULL
Dot notation allows you to reference the table a column belongs to within a join.

An INNER JOIN combines rows from two tables using comparison operators in a condition.



Simplifying ON with USING

Rewrite ON with USING for more concise inner join queries that match on a common column.

The column names must be the same in order to use the USING statement in an inner join.

As an example, the On part of the query relies on columns with the same name (category_id), it can be simplified with a USING statement:

SELECT mismatch_topic.topic_id, mismatch_category.name
    FROM mismatch_topic
    INNER JOIN mismatch_category
    USING (category_id)
    WHERE mismatch_topic.name = 'Horror movies'


An alias allows you to rename a table or column within a query to help simplify the query in some way.



Five steps to a successful mismatch

Grab the user's responses from the mismatch_response table, making sure to join the topic names with the results.
Initialize the mismatch search results, including the variables that keep up with the "best mismatch."
Loop through the user table comparing other people's responses to the user's responses. This involves comparing responses for every person in the database to the user's corresponding responses. A "score" keeps up with how many opposite responses the user SHARES with each person.
After each cycle through the loop, see if the current mismatch is better than the best mismatch so far. If so, store this one as the new "best mismatch," making sure to store away the mismatched topics as well.
Make sure a "best mismatch" was found, then query to get more information about the mismatched user, and show the results.


PHP & MySQL Toolbox



Schemas and Diagrams

A schema is a representation of all the structures (tables, columns, etc.) in your database, along with how they connect. A diagram is a visual depiction of your database, including details about the specific columns responsible for connecting tables.

Normalization

Normalization is the process of altering the design of a database to reduce duplicate data and improve the placement of and relationships between data. The goal is to produce a robust design that holds up well to growing data.

Foreign Key

A column in a table that is used to link the table to another table. A foreign key in a child table typically connects to a primary key in a parent table, effectively linking rows between the two tables.

for ( ... )

A loop that is ideally suited to looping based on a specific number of iterations. Create a for loop by initializing a counter, establishing a test condition, and specifying how the counter is to be updated after each iteration.

? :

The ternary operator is a PHP construct that works like a really compact if-else statement. It is handy for performing simple choices based on a true/false expression.

INNER JOIN

This kind of join combines data from two tables that have matching rows. Unlike a normal query, a join allows you to grab data from more than one table, which is extremely helpful when a database consists of multiple tables.

AS name

This SQL statement establishes an alias, which is a name used to identify a piece of data within a query. Alias are often used to simplifying queries by shortening long table and column names. They can also be used to rename result data when the original table column isn't specific enough.



Chapter 9   String and custom functions



The explode( ) function breaks a string into an array of substrings.

Here's an example:

$search_words = explode ('', 'Tipper Cow');
Preprocessing data allows us to remove unwanted characters and make the data easier to process.

The PHP substr( ) function allows you to extract a portion of a string.

Here's the syntax:

substr (string, start, length)


Custom functions allow you to organize a chunk of PHP code by name so that it can be easily reused.

Following is an example of a custom function called replace_commas( ) that replaces commas with spaces in a string:

function replace_commas($str) {
    $new_str = str_replace(',', ' ', $str);
    return $new_str;
}
A SWITCH statement contains a series of CASE labels that execute different on the value of a variable.

Pagination breaks query results into sets, and displays each set on its own web page.

LIMIT controls what and how many rows are returned by an SQL query.



These variables are also important in determining how the navigation links at the bottom of the page are generated.

$cur_page

Get the current page, $cur_page, from the script URL via $_GET. If no current page is passed through the URL, set $cur_page to the first page (1).

$results_per_page

This is the number of results per page, which you choose based on the look and feel of the page, and how many search results fit nicely on the page with the layout. This is where the second argument to the LIMIT clause comes from.

$skip

Compute the number of rows to skip before the rows on the current page begin, $skip. This variable is what controls where each page begins in terms of results, providing the first argument to the LIMIT clause.

$total

Run a query that retrieves all the rows with no LIMIT, and then count the results and store it in $total. In other words, this is the total number of search results.

$num_pages

Compute the number of pages, $num_pages, using $total divided by $results_per_page. So for any given search, there is a total of $total matching rows, but they are displayed a page at a time, with each page containing $results_per_page matches. There are $num_pages pages, and the current page is identified by $cur_page.



Here's how we can perform the check and call the generate_page_links( ) function, making sure to pass along the required information as function arguments:

if ($num_pages > 1) {
    echo generate_page_links($user_search, $sort, $cur_page, $num_pages);
PHP & MySQL Toolbox



LIKE

Use LIKE to look for data within an SQL query without necessarily requiring an identical match. Put a % in front of and/or after a search term to let LIKE know that the term can have other characters surrounding it.

explode( ), implode( )

The PHP explode( ) function breaks a string apart into an array of substrings that are separated by a common delimiter, such as a space or comma. implode( ) does the opposite - it builds a single string from an array of strings, inserting a delimiter between them.

substr( )

This PHP function extracts a portion of a string based on arguments you supply it. You can grab the beginning of a string, the end of a string, or some piece in between.

str_replace( )

Call this PHP function to do a find-and-replace on a string of text, replacing one character or sequence of characters with another.

Custom function

A chunk of PHP code organized into a named, reusable package. The idea is to isolate code that performs a certain task so that it can be reused with minimal effort and code duplication.

switch-case

A PHP decision-making construct that allows you to execute one of many groups of code based on a single value. If you find yourself with a bunch of nested if-else statement, you may find that you can code it more efficiently as a switch statement.

LIMIT

The LIMIT clause lets you control exactly how many rows are returned by an SQL query. Not only that, but LIMIT can skip rows in the result set, allowing you to isolate a subset of results.



Chapter 10   Regular expressions



Metacharacters let us describe patterns of text within a regular expression.

\d

Looks for a digit. It will match any number from 0 to 9. Keep in mind, \d matches just one digit, so if you wanted to match two-digt number, you'd need to use either \d\d or \d( 2 ).

\w

Looks for any alphanumeric character--in other words, either a letter or a number. It will match one character from the following: a-z and A-Z (both uppercase and lowercase letters), as well as 0-9 (just like \s

Looks for whitespace. \s not only just the space character, but also matches a tab character, or a newline or carriage return. \s will only match one of these characters at a time. If you wanted to match exactly two space characters in a row, you'd need to use \s\s or \s{2}.

^

It looks for the beginning of a string, so you can use it to indicate that match must happen at the start of a text string, rather than anywhere in the string.

.

The period metacharacter, matches any one character, except a newline. It'll match a letter or digit, just like \w, as well as a space or tab, like \s.

$

Looks for the end of a string. You can use this metacharacter with ^ to bookend your match, specifying exactly where it will start and finish.



A character class is a set of rules for matching a single character.

In a character class, the ^ means don't match.



The preg_match( ) function takes a regex pattern, just like those we've been building, and a text string. It returns false if there is no match, and true if there is.

preg_match($regex, $my_string)
The preg_replace( ) function goes one step beyond the preg_match( ) function in performing pattern matching using regular expression.

preg_replace($pattern, $replacement, $my_string)
Standardizing your data gives you better SQL query results.



Valid email address can contain any of these characters in the LocalName portion, although some of them can't be used to start an email address:

! $ & * - = ^ ` | ~ # % ' + / ? _ { }



PHP & MySQL Toolbox



Regular expression

Rules that are used to match patterns of text in strings. PHP includes functions that allow you to use regular expressions to check a string for a certain pattern, as well as find-and-replace patterns of text within a string.

\d, \w, \s, ^, $, ...

Regular expressions are created using metacharacters, which represent text expressions such as three numeric digits (\d\d\d) or whitespace (\w).

preg_match( )

This PHP function checks a string of text to see if it matches a regular expression. The function returns true if there was a match or false if not.

Character class

A set of rules for matching a single character within a regular expression.

preg_replace( )

Use this PHP function to replace a substring within a string based on a regular expression. The function does a  find-and-replace using a regular expression for the find, and replacing with a string you provide it.

checkdnserr( )

This PHP function checks a domain name to see if it actually exists. This is handy when validating an email address because you want to make sure that the domain part of the email is real.



Chapter 11   Visualizing your data... and more!



The Add Score form needs a new field that requires human verification before allowing a high score to be submitted.

A CAPTCHA is a program that protects a web site from automated bots by using a test of some sort.



The rand( ) function returns a random integer within a certain range.

rand( )

This built-in returns a random integer number, either within a specified range or between 0 and the built-in constant RAND_MAX(server dependent). To obtain a random number within a certain range, just pass the lower and upper limits of the range as two arguments to rand( ).

chr( )

This built-in function converts a number to its ASCII character equivalent.



Drawing a dynamic image in PHP requires using GD library functions.



Inside the GD graphics functions

imagecreatetruecolor( )

The imagecreatetruecolor( ) function creates a blank image in memory ready to be drawn to with other GD function. And the return value of imagecreatetruecolor( ) is an image identifier, which is required as the first argument of most GD function to identify the image being drawn.

$img = imagecreatetruecolor(CAPTCHA_WIDTH, CAPTCHA_HEIGHT);
imagecolorallocate( )

The first argument is the image resource identifier, followed by three arguments representing the three numeric components of the RGB (Red-Green-Blue) color value. Each of these values is in the range 0-255. The return value is a color identifier that can be used to specify a color in other drawing functions, often as the argument.

$text_color = imagecolorallocate($img, 0, 0, 0);
imagesetpixel( )

Coordinates start at 0,0 in the upper left corner of the image, and increase to the right and down.

imagesetpixel($img, rand() % CAPTCHA_WIDTH, rand() % CAPTCHA_HEIGHT, $graphic_color);
imageline( )

Call this function to draw a line between two coordinates (x1, y1 and x2,y2). The coordinates are specified relative to the upper-left corner of the image, and the line is drawn in the color passed as the last argument to the function.

imageline($img, 0, rand() % CAPTCHA_HEIGHT,
    CAPTCHA_WIDTH, rand() % CAPCHA_HEIGHT, $graphic_color);
imagerectangle( ), imagefilledrectangle( )

Draw a rectangle starting at one point (x1, y1) and ending at another point (x2, y2) in a certain specified color.

imagefilledrectangle($img, 0, 0, CAPTCHA_WIDTH, CAPTCHA_HEIGHT, $bg_color);
Use the imagettftext( ) function to draw highly customized text with your own TrueType font.

imagettftext($img, 18, 0, 5, CAPTCHA_HEIGHT - 5, $text_color,
    'Courier New Bold.ttf', $pass_phrase);
Mismatch's "five degrees of opposability" involves measuring mismatched topics by category.



PHP & MySQL Toolbox



CAPTCHA

A program that protects a web site from automated spam bots by using a test of some sort For example, a CAPTCHA test might involve discerning letters within a distorted pass-phrase, identifying the content of an image, or analyzing an equation to perform a simple mathematical computation.

GD library

A set of PHP function that are used to draw graphics onto an image. The GD library allows you to dynamically create and draw on images, and then either return them directly to the browser or write them to image files on the server.

imagecreatetruecolor( )

This function is part of the GD graphics library, and is used to create a new image for drawing. The image is initially created in memory, and isn't output for display purposes until calling another function, such as imagepng( ).

imagestring( ),

imagestringup( ),

imagettftext( )

The GD graphics library also allows you to draw text, either with a built-in font or with a TrueType font of your own choosing.

imageline( ),

imagerectangle( ), ...

The GD graphics library offers lots of functions for drawing graphics primitives, such as lines, rectangles, ellipses, and even individual pixels. Each function operates on an existing image that has already been created with imagecreatetruecolor( ).

imagepng( )

When you're finished drawing to an image using GD graphics functions, this function outputs the image so that it can be displayed. You can choose to output the image directly to the web browser or to an image file on the server.

imagedestroy( )

After drawing to an image and outputting it as desired, it's a good idea to destroy the resources associated with it by calling this function.



Chapter 12   Syndication and web services



HTML is for viewing; RSS is for syndicating.

RSS is kinda like the web equivalent of a digital video recorder (DVR).

RSS is a markup language used to describe web content for syndication.

XML is a markup language used to describe any kind of data.

An RSS newsreader is designed to consume the data made available by an RSS newsfeed.



The resulting newsfeed isn't stored in a file but it is an XML document.

Dynamically generate an RSS feed:

Set the content type of the document to XML.
Generate the XML directive to indicate that this is an XML document.
Generate the static RSS code that doesn't come from the database, such as the <rss> tag and the channel information.
Query the aliens_abduction database for alien abduction data.
Loop through the data generating RSS code for each news item.
Generate the static RSS code required to finish up the document, including closing </channel> and </rss> tags.
A standard RSS icon is available to make it clear to users that you offer an RSS newsfeed.



Namespaces are named groups of XML tags, while entities are used to encode special characters within XML documents.

An element is just an abstract way of thinking of an XML tag and the data it contains.

Objects are a special PHP data type that combine data and functions together.

Namespaces make it a bit trickier to access elements within XML data.

Use the children( ) method to isolate all elements associated with a namespace.



PHP & MySQL Toolbox



REST

A means of accessing information on the we purely through URLs. REST allows you to make powerful data requests simply by creating a URL. Such requests are often referred to as "RESTful" requests.

RSS

An XML-based language used to store syndicated content, such as news stories. RSS allows web sites to make their data available to other application and web sites for syndication, and allows you to take advantage of data made available by other site.

simplexml_load_file( )

This built-in PHP function loads an XML file from a URL, and then makes the resulting XML data accessible through an object.

SimpleXMLElement

A built-iin PHP object that is used to access XML data. This object is returned by the simplexml_load_file( ) function, and contains the entire document hierarchy of an XML document.



the end.