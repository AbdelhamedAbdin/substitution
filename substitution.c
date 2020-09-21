# include <stdio.h>
# include <string.h>
# include <cs50.h>
# include <ctype.h>

int main(int argc, string argv[])
{
    // check if key is exists
    if (argc != 2)
    {
        printf("%s", "usage: ./substitution key\n");
        return 1;
    }
    else
    {
        // key
        string ciphertext = argv[1]; // "VCHRPZGJNTLSKFBDQWAXEUYMOI"
        int cipher_length = strlen(ciphertext);
        string msg_error = "\0";
        int x = 0;

        if (cipher_length == 26)
        {
            int msg_num = 0;
            for (int i = 0; i < strlen(ciphertext); i++)
            {
                if (isdigit(ciphertext[i]))
                {
                    msg_num = 0; // false
                }
                else
                {
                    msg_num = 1; // true
                }
            }
            if (msg_num == 1)
            {

                string plaintext = get_string("plaintext: ");
                int n = strlen(plaintext);
                int a_letter = 'a';
                char plaintext_cp[n]; // copy from the original text
                char text[n];
                strcpy(plaintext_cp, plaintext);

                // to read the chars into plaintext
                for (int i = 0; i < n; i++)
                {
                    char lower_char = tolower(plaintext_cp[i]);
                    if (lower_char >= 'a' && lower_char <= 'z')
                    {
                        int covert_to_ascii = lower_char; // 101
                        int index = covert_to_ascii - a_letter;
                        if (islower(plaintext[i]))
                        {
                            text[i] = tolower(ciphertext[index]);
                        }
                        else
                        {
                            text[i] = toupper(ciphertext[index]);
                        }
                    }
                    else
                    {
                        text[i] = lower_char;
                    }
                }
                printf("ciphertext: %s\n", text);
                return 0;
            }
            else
            {
                printf("%s\n", "key must only contain alphabetic characters.");
                return 0;
            }
        }
        else
        {
            printf("%s\n", "Key must contain 26 characters.");
            return 1;
        }
    }
}
