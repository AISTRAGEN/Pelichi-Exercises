#include <iostream>
#include <cstring>

bool itsPalindrome(const char* str) 
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) 
    {
        if (str[i] != str[len - i - 1]) 
        {
            return false;
        }
    }
    return true;
}

int main() 
{
    std::cout << "Enter a sentence: ";
    char sentence[100];
    std::cin.getline(sentence, 100);

    // Видалення пробілів та розділових знаків
    char cleanedSentence[100];
    int j = 0;
    for (int i = 0; i < strlen(sentence); ++i) 
    {
        if (isalpha(sentence[i])) 
        {
            cleanedSentence[j++] = tolower(sentence[i]);
        }
    }
    cleanedSentence[j] = '\0';

    if (itsPalindrome(cleanedSentence)) 
    {
        std::cout << "Its palindrome!" << std::endl;
    }
    else 
    {
        std::cout << "Its not palindrome." << std::endl;
    }

    return 0;
}
