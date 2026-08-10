<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>

<form action="palindrome.php" method="post">
    <input type="text" name="palindrome" placeholder="input a palidrome or not">
    <button type="submit">submit</button>
</form>

    <?php 
function is_palindrome(){
    $word = $_POST['palindrome'];
    $word = str_replace(" ", "", $word);
    $word = str_split($word);
    $word_reverse = array_reverse($word);

    if(array_change_key_case($word, CASE_LOWER) == array_change_key_case($word_reverse, CASE_LOWER)){
        echo "is palindrome";
        return;
    }
    echo "is not palindrome";
}

is_palindrome();

?>
</body>
</html>