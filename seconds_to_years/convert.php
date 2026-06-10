<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
<?php
    function seconds_to_years($total_seconds)
    {
        $units = [
            ["name" => "year", "value" => 31536000],
            ["name" => "month", "value" => 2629800],
            ["name" => "week", "value" => 604800],
            ["name" => "day", "value" => 86400],
            ["name" => "hour", "value" => 3600],
            ["name" => "minute", "value" => 60],
            ["name" => "second", "value" => 1]
        ];

        $result = [];

        for ($i = 0; $i < count($units); $i++) {
            $amount = intdiv($total_seconds, $units[$i]["value"]);
            $total_seconds %= $units[$i]["value"];
            $result[] = ["name" => $units[$i]["name"], "value" => $amount];
        }

        foreach ($result as $item) {
            echo $item["value"] . " " . $item["name"] . "(s)<br>";
        }
    }

    $seconds1 = 40000000;
    $seconds2 = 78526762;

    echo "output 1:<br>";
    seconds_to_years($seconds1);

    echo "<br>output 2:<br>";
    seconds_to_years($seconds2);

?>

</body>

</html>