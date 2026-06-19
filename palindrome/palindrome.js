const is_palindrome = () =>{
    let word = prompt("input a word and we will verify if is palindrome").replaceAll(" ", "").split("")
    alert(word)
    let word_reverse = word.reverse()
    alert(word_reverse)
    word = word.toString().replaceAll(",", "")
    alert(word)
    word_reverse = word_reverse.toString().replaceAll(",", "")
    alert(word_reverse)
    if(word === word_reverse){
        alert("is palindrome")
        alert(word)
        alert(word_reverse)
        return
    }
    alert("is not palindrome")
}

is_palindrome()