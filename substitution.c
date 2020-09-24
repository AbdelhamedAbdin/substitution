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
        string ciphertext = argv[1];
        int cipher_length = strlen(ciphertext);
        string msg_error = "\0";
        int x = 0;
        // charge of the count of key
        if (cipher_length == 26)
        {
            int msg_num = 0;
            for (int i = 0; i < strlen(ciphertext); i++)
            {
                if (isdigit(ciphertext[i]))
                {
                    msg_num = 0; // false
                    break;
                }
                else
                {
                    msg_num = 1; // true
                }
            }
            string cipher_cp = ciphertext;
            int loop = 0;
            int num = 0;
            int count_char = 0;
            int repeat_msg = 0;

            while (true)
            {
                if (loop < strlen(ciphertext))
                {
                    if (tolower(ciphertext[loop]) == tolower(cipher_cp[num]))
                    {
                        count_char += 1;
                        if (count_char > 1)
                        {
                            repeat_msg = 0; // false
                            break;
                        }
                        else
                        {
                            repeat_msg = 1; // true
                        }
                    }
                }
                else
                {
                    loop = 0;   // reset loop
                    num += 1;  // move to second position
                    count_char = 0;  // reset count
                    if (num >= strlen(ciphertext))
                    {
                        break;
                    }
                }
                loop += 1;
            }
            // charge of alphabetic characters
            if (msg_num == 1)
            {
                // charge of repeated characters
                if (repeat_msg != 0)
                {
                    string plaintext = get_string("plaintext: ");
                    int n = strlen(plaintext);
                    int a_letter = 'a';
                    char plaintext_cp[n + 1]; // copy from the original text
                    char text[n + 1];
                    strcpy(plaintext_cp, plaintext);

                    // to read the chars into plaintext
                    for (int i = 0; i < n; i++)
                    {
                        char lower_char = tolower(plaintext_cp[i]);
                        if (lower_char >= 'a' && lower_char <= 'z')
                        {
                            int covert_to_ascii = lower_char;
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
                    printf("key must not contain repeated character.\n");
                    return 1;
                }
            }
            else
            {
                printf("%s\n", "key must only contain alphabetic characters.");
                return 1;
            }
        }
        else
        {
            printf("%s\n", "Key must contain 26 characters.");
            return 1;
        }
    }
}
