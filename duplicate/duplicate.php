<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<?php 
function remove_duplicates($arr){
    $arr = array_unique($arr);
    echo "the array without duplicates is ";
    print_r($arr);
    return;
}

$myarr = [3, 5, 7, 3, 1, 1, 10, 3, 7, 5, 1, 10, 10];
remove_duplicates($myarr)

?>
<body>
    
</body>
</html>