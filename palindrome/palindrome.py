def is_palindrome():
    word = input("input a word and we will verify if is palindrom: ").replace(" ", "")
    word_reverse = word[::-1]
    if word.casefold() == word_reverse.casefold():
        print("is palindrome")
        return
    print("is not palindrome")
    
is_palindrome()