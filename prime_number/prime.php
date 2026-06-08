<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    
<form action="prime.php" method="POST">
    <input type="number" name="prime" placeholder="we'll tell you if it's prime">
    <button type="submit">submit</button>
</form>

<?php 

function prime(){
        $num = $_POST['prime'];
        $sqrt = (int) (sqrt($num));
        for ($n = $num - 1; $n > $sqrt; $n--) {
            if ($num % $n == 0) {
                echo "<br>the number " . $num . " isn't prime";
                return;
            }
        }
        echo "<br> the number " . $num . " is prime";
    }

    prime();

?>

</body>
</html>