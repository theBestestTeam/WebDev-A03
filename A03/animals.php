<!--
	FILE			: animal.php
	PROJECT			: PROG2001 - Wed Design and Development
	PROGRAMMER		: Paul Smith & Amy Dayasundara
	FIRST VERSION	: 2019-10-22
	DESCRIPTION		: 
		Purpose of this file is to set up the server side for the
		php file. It will show which file is required to be accessed.
		Ultimately it will show the user's name, photo of the chosen animal
		and an explaination of the animal.
-->

<!DOCTYPE html>
<html>
<head>
	<link href= 'animalStyle.css' rel='stylesheet' type='text/css'>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		
</head>
<body>
<?php
		$secretName = $_POST['secretName'];
		$secretAnimal = $_POST['secretAnimal'];
		
		//Check the animal code and executes accordingly to open the text file and image
		if($secretAnimal == "AO")	
		{
			$result = "armadillo";	//result assigned correct animal name
			$fileName = "theZoo/armadillo.txt";	//appropriate txt file assigned
			$myfile = fopen("theZoo/armadillo.txt", "r") or die("Unable to open file!");	//text file is opened
			$animal = "Armadillo";	//upper case animal name applied for greeting
		}
		if($secretAnimal == "DN")		//process repeats for next potential animal
		{
			$result = "dolphin";
			$fileName = "theZoo/dolphin.txt";
			$myfile = fopen("theZoo/dolphin.txt", "r") or die("Unable to open file!");
			$animal = "Dolphin";
		}
		if($secretAnimal == "MO")
		{
			$result = "moth";
			$fileName = "theZoo/moth.txt";
			$myfile = fopen("theZoo/moth.txt", "r") or die("Unable to open file!");
			$animal = "Moth";
		}
		if($secretAnimal == "QU")
		{
			$result = "quokka";
			$fileName = "theZoo/quokka.txt";
			$myfile = fopen("theZoo/quokka.txt", "r") or die("Unable to open file!");
			$animal = "Quokka";
		}
		if($secretAnimal == "SR")
		{
			$result = "samRockwell";
			$fileName = "theZoo/samRockwell.txt";
			$myfile = fopen("theZoo/samRockwell.txt", "r") or die("Unable to open file!");
			$animal = "Sam Rockwell";
		}
		if($secretAnimal == "TR")
		{
			$result = "tiger";
			$fileName = "theZoo/tiger.txt";
			$myfile = fopen("theZoo/tiger.txt", "r") or die("Unable to open file!");
			$animal = "Tiger";
		}	
?>	
	<div class="row">
	<div class="column">
				</div>
		<div class="column">
		<h2 align="center" id="rcorners1">Hi <?php echo $secretName ?>, welcome to the <?php echo $animal ?> page!</h2>
		<tr>
			<td>		
				<img src="theZoo/<?php echo $result; ?>.jpg">
			</td>
			<td>
				<?php echo fread($myfile,filesize($fileName));fclose($myfile);?>
			</td>
		</tr>
		</div>
	</div>
</body>
</html>