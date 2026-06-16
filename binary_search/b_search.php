<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>

<form action="b_search" method="POST">
    <input type="number" name="search" placeholder="pick a number: [11, 22, 33, 44, 55, 67, 77, 88, 99, 111]">
    <button type="submit">enviar</button>
</form>

<?php 
function search($arr){
    $res = $_POST['search'];
    $left = 0;
    $right = count($arr) - 1;
    $steps = 0;

    while($left <= $right){
        $middle = intdiv($left + ($right - $left), 2);
        $steps++;

        if($res == $arr[$middle]){
            echo "<br>we found the number in [" . $steps . "] steps";
            return;
        }
        else if($res < $arr[$middle]){
            $right = $middle - 1;
        }
        else{
            $left = $middle + 1;
        }
    }
    echo "number wasn't found";
}

$myarr = [11, 22, 33, 44, 55, 67, 77, 88, 99, 111];
search($myarr);

?>

</body>
</html>