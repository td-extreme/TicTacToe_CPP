Tyler Decker  
README.md


<h1>Tic Tac Toe</h1>
<p>This project is a command line / terminal version of Tic Tac Toe.</p>
<h2>Makefile</h2>
<ul>
<li>'make run' -- Build and Play the game</li>
<li>'make runTests' -- Build and Run all Tests</li>
<li>'make all' -- Build all executables. </li>
</ul>
<p><strong>Please note testing uses CppUnit</strong></p>
<h2>Testing with CppUnit</h2>
<p>You can still compile and run the game without having CppUnit but will be unable to build the tests.
You can get more information about CppUnit here: <a href="https://freedesktop.org/wiki/Software/cppunit/">freedesktop.org/wiki/Software/cppunit/</a></p>

<h2>Setting Up CppUnit</h2>

<h3>Debian / Ubuntu</h3>

```
sudo apt-get install build-essential
sudo apt-get build-dep libcppunit-dev
```

<h3> OS X </h3>
Please note I do not have a Apple computer and have not set up CppUnit on OS X myself.

From what I found online if you have homebrew installed, you should be able to excute the following commands in a terminal.

Install homebrew if not already on system:
```
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" < /dev/null 2> /dev/null
```

Then run this command to install cppunit
```
brew install cppunit
```
