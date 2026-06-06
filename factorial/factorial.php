//using php web

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="algoritmos.php" method="POST">
        <input type="number" name = "fatorial" placeholder="Digite um número e retornarei o fatorial dele">
        <button type="submit">enviar</button>
    </form>
    <?php 
    
    function fat(){
        $num = $_POST['fatorial'];
        for ($n = $num - 1; $n != 1; $n--){
            $num *= $n;
        }
        echo  $num;
    }
    
    fat();
    
    ?>
</body>
</html>