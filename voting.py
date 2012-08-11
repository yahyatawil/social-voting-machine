
#author  : yahya tawil
#licence : http://creativecommons.org/licenses/by-nd/3.0
#2011-2012 
#beta

import serial 
import MySQLdb
db = MySQLdb.Connect(host = "localhost" , user = "root" , passwd="abc123", db = "votingmachine")
cur = db.cursor()
con = ['0', '1',  '2']
for index in range(len(con)):
   p = '/dev/ttyACM'+con[index]
   s = serial.Serial(p,baudrate=9600)
   if(s.isOpen()) :
       break;


cur.execute("SELECT fname,lname FROM event")
rows=cur.fetchall()

for row in rows : 
    n_row=''
    n_row=''.join(row) 
    s.write(n_row)
    nxt=s.read()
    if nxt=='1' :
        res=row
        break
    else: print 'res'
    # counter=counter+1 WHERE image_id=15 
print res[0]
fname=''.join(res[0])
lname=''.join(res[1])
action = "UPDATE event SET"
action = action+" votes=votes+1 WHERE fname=\'"
action = action+fname
action = action+"\' AND lname=\'"
action = action+lname
action = action+"\'"
print action
cur.execute(action)
