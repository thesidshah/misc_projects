<head>
<style>
body {font-family: Arial, Helvetica, sans-serif;}
* {box-sizing: border-box;}

#btn{
	color: #fef;
	background: #337ab7;
	padding: 5px;
	margin-left: 40%;
	width:20%;
}
.container {
  border-radius: 5px;
  background-color: #f2f2f2;
  padding: 20px;
</style>
</head>
<body>
<div class="container">
<?php
	//Get values passe from form in login.php file
	$username=$_POST['user'];
	$password=$_POST['pass'];
	
	//to prevent mysql injection
	//$username = stripclashes($user);
	//$password = stripclashes($pass);
	//$username = mysql_real_escape_string($username);
	//$password = mysql_real_escape_string($password);
	
	//connect to the server and select database
	$servername="localhost";
	$conn = new mysqli($servername, "root", "", "mini_project");
	$blacklist = array("' OR '1'='1","--",";--",";","/*","*/","@@","char","nchar","varchar","nvarchar","fetch","insert","kill","open","select","alter","begin","cast","create","cursor","declare","delete","drop","end","exec","execute","sys","sysobjects","syscolumns","table","update");
	//mysqli_connect("localhost","root","");
	//mysqli_select_db("login");
	// Check connection
	if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
	}
	//echo stripos($password,$blacklist[1])."stripos<br>";
	foreach ($blacklist as $value) {
	if(strpos($password, $value) !== false)
	{echo "<h1 style='color:red'>SQL injection detected</h1>";}
	}
	
	//Query the database for user
	$sql = "select * from users where username = '$username' and password = '$password'";
	$result = mysqli_query($conn,$sql);
	$row= mysqli_fetch_array($result);
	
	//echo $sql;
	
	
	/*if($row['username']==$username ){
			echo "Login successful! Welcome <h1>".$row['username']."</h1>";
	}
	else{
		echo "failed to login!";
	}*/
	if(empty($row)){
        echo "<h1 style='color:red;' align=center>failed to login!</h1>";	
		}
	else{
			echo "<h1 align=center>Login successful! Welcome ".$row['username']."</h1>";
			
	}
	//echo "Login successful! Welcome ".$row['username'];
?>
<br>
<button id="btn" onclick="document.location = 'feed.html'">Feedback</button>
</div>
</body>