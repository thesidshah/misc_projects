<!DOCTYPE html>
<html>
	<head>
		<title>login</title>
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>
	<body>
		<div id="frm">
			<form action="process.php" method="POST">
				<p>
					<label>Username:</label>
					<input type="text" id="user" name="user" required />
				</p>
				<p>
					<label>Password:</label>
					<input type="password" id="pass" name="pass" required />
					<br>enter this as pass:: ' OR '1'='1 
				</p>
				<p>
					<input type="submit" id="btn" value="Login" />
				</p>
			</form>
		</div>
	</body>
</html>