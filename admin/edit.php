<?php
session_start();

require_once 'includes/filter-wrapper.php';
require_once 'db.php';

//errors
$errors = array();

$playerId = filter_input(INPUT_GET, 'id',FILTER_SANITIZE_NUMBER_INT);
	//if there's no id redriect to the homepage
	if(empty($playerId))
	{
		header('location: index.php?'. SID);
		exit;
	}

//sanitize all the fields
$firstName = filter_input(INPUT_POST, 'firstName',FILTER_SANITIZE_STRING);

$lastName = filter_input(INPUT_POST, 'lastName',FILTER_SANITIZE_STRING);

$goals = filter_input(INPUT_POST, 'goals',FILTER_SANITIZE_STRING);

$assists = filter_input(INPUT_POST, 'assists',FILTER_SANITIZE_STRING);

$points = filter_input(INPUT_POST, 'points',FILTER_SANITIZE_STRING);

$team = filter_input(INPUT_POST, 'team',FILTER_SANITIZE_NUMBER_INT);

if($_SERVER['REQUEST_METHOD'] == 'POST')
{
	//validate the form
	if(empty($firstName))
		$errors['firstName']=true;

	if(empty($lastName))
		$errors['lastName']=true;

	if(empty($goals))
		//$errors['goals']=true;

	if(empty($assists))
		//$errors['assists']=true;

	if(empty($points))
		//$errors['points']=true;

	if(empty($team))
		$errors['team']=true;	

	//if there are no errors put data into database
	if(empty($errors))
	{
		$sql = $db->prepare('UPDATE stats SET firstName = :firstName, lastName = :lastName, goals = :goals, assists = :assists, points = :points, team = :team WHERE playerId = :playerId');
		$sql->bindValue(':playerId', $playerId, PDO::PARAM_INT);
		$sql->bindValue(':firstName', $firstName, PDO::PARAM_STR);
		$sql->bindValue(':lastName', $lastName, PDO::PARAM_STR);
		$sql->bindValue(':goals', $goals, PDO::PARAM_STR);
		$sql->bindValue(':assists', $assists, PDO::PARAM_STR);
		$sql->bindValue(':points', $points, PDO::PARAM_STR);
		$sql->bindValue(':team', $team, PDO::PARAM_INT);

		$sql->execute();
		header('location: index.php?' . SID);
		exit;
	}

}
else
{
	//display database information
	//shows the title in the value part
	$sql = $db->prepare('SELECT playerId, firstName, lastName, goals, assists, points, team FROM stats WHERE playerId = :playerId');
	$sql->bindValue(':playerId', $playerId, PDO::PARAM_INT);
	$sql->execute();
	$results = $sql->fetch(PDO::FETCH_OBJ);

	$firstName = $results->firstName;
	$lastName = $results->lastName;
	$goals = $results->goals;
	$assists = $results->assists;
	$points = $results->points;
	$team = $results->team;
	
}

?>
<html>
<head>
<title>Edit</title>
<style>
body {
	background-color: #CCCCFF;	
}

h1{
	margin:0;
	padding:2px;
}
#content {
	border-radius:10px;
	-moz-border-radius:10px; /* Old Firefox */
	
	background-color: rgba(0,0,0,0.3);
	width: 600px;
	margin: 0 auto;
	padding: 10px;
	border: 1px solid black;
}
</style>
</head>
<body>
	<div id="content">
		<h1> Lake Mary Hockey</h1>
    <form action="edit.php?id=<?php echo $playerId; ?>" method="post">

        <div>
        	<label for="firstName">First Name</label>
            <?php if(isset($errors['firstName'])): ?>
            <label for "firstName"><p class="error">Error! Enter first name</p></label>
            <?php endif; ?>
            <input id="firstName" name="firstName" value="<?php echo $firstName; ?>">
        </div>

        <div>
        	<label for="lastName">Last Name</label>
            <?php if(isset($errors['lastName'])): ?>
            <label for "lastName"><p class="error">Error! Enter last name</p></label>
            <?php endif; ?>
            <input id="lastName" name="lastName" value="<?php echo $lastName; ?>">
        </div>

        <div>
        	<label for="goals">Goals</label>
            <?php if(isset($errors['goals'])): ?>
            <label for "goals"><p class="error">Error! Enter Goals</p></label>
            <?php endif; ?>
            <input id="goals" name="goals" value="<?php echo $goals; ?>">
        </div>

        <div>
        	<label for="assists">Assists</label>
            <?php if(isset($errors['assists'])): ?>
            <label for "assists"><p class="error">Error! Enter assists</p></label>
            <?php endif; ?>
            <input id="assists" name="assists" value="<?php echo $assists; ?>">
        </div>

        <div>
        	<label for="points">Points</label>
            <?php if(isset($errors['points'])): ?>
            <label for "points"><p class="error">Error! Enter points</p></label>
            <?php endif; ?>
            <input id="points" name="points" value="<?php echo $points; ?>">
        </div>

        <div>
        	<label for="team">Team</label>
            <?php if(isset($errors['team'])): ?>
            <label for "team"><p class="error">Error! Enter team (Number based)</p></label>
            <?php endif; ?>
            <input id="team" name="team" value="<?php echo $team; ?>">
        </div>

        <div>
            <a href="index.php">&lt;&lt;Back</a>
            <button type="submit">Save</button>
        </div>

    </form>
  </div>
</body>
</html>