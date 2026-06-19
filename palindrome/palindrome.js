const is_palindrome = () =>{
    let word = prompt("input a word and we will verify if is palindrome").replaceAll(" ", "").split("")
    let word_reverse = word.reverse()
    word = word.toString().replaceAll(",", "")
    word_reverse = word_reverse.toString().replaceAll(",", "")
    if(word === word_reverse){
        alert("is palindrome")
        return
    }
    alert("is not palindrome")
}

is_palindrome()