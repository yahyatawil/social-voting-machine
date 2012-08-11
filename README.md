socail voting machine 
----------------------------------------
This project is trying to build a hardware machine to make a simple reputation system in hackerspace events .

project hardware :
1.LCD 16*2 character .
2.pot resistor 10k ohm .
3.keypad 4*4 .

project software :
*voting.ino , is the arduino sketch to produce an interactine user intrface with hardware using the LCD .
*voting.py , is the python script used for connect with arduino and make connection with data base .

dependencies : 
*pyserial , pyhthon module to connect serially with arduino throught USB-serial .
*mysqlDB , python module to connect with mysql database
*mysql , database

respo files :
*voting.ino : arduino code
*voting.py : python code
*form.html , form.php : basic feature form for registration in the database .