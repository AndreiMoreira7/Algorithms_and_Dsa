<?php
    function greater($num){
        $greaterNum = 0;
        for ($n = 0; $n != count($num); $n++){;
            if($num[$n] > $greaterNum){
                $greaterNum = $num[$n];
            }
        }
        echo "the entire array is " . print_r($num, true) . " and the greater number is " . $greaterNum;
    }

    $numbers = array(15, 50, 31);
    greater($numbers);
?>