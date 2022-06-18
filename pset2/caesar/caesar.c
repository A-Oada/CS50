#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool digits_only(string input_s);
string rotate(int key, string input_text);
char rotatelower(int key, char c);
char rotateupper(int key, char c);

int main(int argc, string argv[])
{
    //Checking if the key is valid
    if (argc != 2 || digits_only(argv[1]) == false)
    {
        printf("Usage: ./Caesar Key\n");
        return 1;
    }
    //Get the key from string and turn it to integer
    int key = atoi(argv[1]);
    //Get plaintext
    string input_t = get_string("Plaintext:  ");
    //Encrypt text
    string cipher = rotate(key, input_t);
    //Print the text
    printf("ciphertext: %s\n", cipher);
}

//This function checks if the key is valid by checking if every single char is a digit from 0 to 9 or not
bool digits_only(string input_s)
{
    int j = strlen(input_s);
    for (int i = 0; i < j; i++)
    {
        if (isdigit(input_s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

//Function to apply the key to the plaintext
//The key is applied per digit
string rotate(int key, string input_text)
{
    char cipher[strlen(input_text)];
    for (int i = 0; i <= strlen(input_text); i++)
    {
        //If the key is a large number then the remainder when dividing by 26 will yield a key between 1 and 26
        key = key % 26;
        //If the character is a lower letter
        if (islower(input_text[i]))
        {
            cipher[i] = rotatelower(key, input_text[i]);
        }
        //If the character is an upper case letter
        else if (isupper(input_text[i]))
        {
            cipher[i] = rotateupper(key, input_text[i]);
        }
        //If the letter does not belong to the alphabet (i.e: commas, question marks, dots...etc)
        else
        {
            cipher[i] = input_text[i];
        }
    }
    //Store the char array in the return string;
    string cipher_c = cipher;
    return cipher_c;
}

char rotatelower(int key, char c)
{
    //"97" is the value of lower case 'a' in ASCII
    int shift = c + key;
    if (shift > 122)
    {
        //Letter 'z' = 122, if key equal 1 then we need to shift back to 'a' which is 97 and if it's 2 we need to shift back to 'b' which is 98...etc
        shift = shift - 26;
    }
    char l = shift;
    return l;
}

char rotateupper(int key, char c)
{
    int shift = key + c;
    if (shift > 90)
    {
        //Letter 'Z' = 95, if key equal 1 then we need to shift back to 'A' which is 65 and if it's 2 we need to shift back to 'B' which is 66...etc
        shift = shift - 26;
    }
    char l = shift;
    return l;
}