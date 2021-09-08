#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int calculate_grade(string text);

int main(void)
{

    //Prompting user for an input
   string text = get_string("Text: ");
   int index = calculate_grade(text);
   if (index < 1)
   {
    printf("Before Grade 1\n");
   }
   else if(index >= 16)
   {
    printf("Grade 16+\n");
   }
    else
   {
        printf("Grade %i\n", index);
   }
    return 0;
}

int calculate_grade(string text)
{
//Wodrs start from 1, as we are actually counting the spaces.
    int letters = 0, words = 1, sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
    if (isalpha(text[i]))
    {
        letters++;
    }
    if (isspace(text[i]))
    {
        words++;
    }
    if (text[i] == '.'|| text[i] == '?' || text[i] == '!')
    {
        sentences++;
    }
    }

//Calculating the grade via Coleman-Liau index and turning int to float for more accuracy.float index= 0.0588*((float)letters/(float)words*100)-0.296*((float)sentences/(float)words)-15.8;

    float L = (letters * 100.0f) / words;
    float S = (sentences * 100.0f) / words;
    return round(0.0588 * L - 0.296 * S - 15.8);
}