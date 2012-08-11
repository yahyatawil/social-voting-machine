<html>
<body>
<p> thanks , your information is:</p>
<table>
<tr><td>name :</td><td><?echo $_POST["FN"]; ?></td></tr>
<tr><td>email: </td><td><? echo $_POST["email"]; ?></td></tr>
</table>
</body>
</html>

<? 
$EMAIL=$_POST['email'];
$FNAME=$_POST['FN'];
$LNAME=$_POST['LN'];
$PSW=$_POST['pwd1'];
$con=MYSQL_CONNECT("localhost","root","abc123");
MYSQL_SELECT_DB("votingmachine",$con);
$sql = " INSERT INTO event (fname,lname,email,password) VALUES ('$FNAME','$LNAME','$EMAIL','$PSW')";
MYSQL_QUERY($sql);
MYSQL_CLOSE($con);
 ?>
