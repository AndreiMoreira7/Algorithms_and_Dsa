//php on web is stateless, i can't save the state of a previous request
<?php 
function average($arr){
    $res = 0;
    foreach ($arr as $num){
        if(is_numeric($num)){
             $res += $num;
        }
    }

    if(count($arr) > 0){
        $res /= count($arr);
        echo "the average is $res";
    }
    else{
        echo "no number was inserted";
    }
}

$myarr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]; //test

average($myarr);
?>