// COmpiled using Dev C ++

#include <stdio.h> // for printf and scanf... etc.

#include <conio.h>  // for getch function

#include <string.h> //for strcpy, strcmp, and strlen

#include <stdlib.h> // rand function

#include <time.h> // use to implement srand

#define clear system("cls") // define system("cls") to clear for easy coding.
#define e 10
#define randomizer srand(time(NULL))

//Prototypes
int introduction(char * answer);
void Print();
void load();
void blank();
void Game();
void showHangman(int);
void planeFig(void);

//Main-Body
int main() {
   /************
   Declarations
   ************/
   THE_ALL_REPEATER_SHORTCUT: {
      printf("\n");
   }
   char answer[100], //answer refers to the hangmanword.
   guess = '\0', //declare guess as a character of terminating character, so that guess will not cause an undefined behavior.
   missed[100]; //missed refers to characters that are inputted by the user, but not in the hangman word
   int x = 0,
   limit = 1,
   wrongTry = 6, //refers to 5 chances by the user to guess the hangman word.
   length; //length of the string 'answer' or the hangman word
   char char_seen[length]; //declare the size of char_seen. AND. look up for repeated input by the user
   int i,
   gameover = 0; //gameover initialize to 0 so that when 0 then stop the execution otherwise comtinue running the program.
   int rewinder = 1, //rewinder set value to 1 so that the program will run, if rewinder doesn't have value of 1, then the entire program will collapse.
   r = 0;

   //Hangman Game Program
   while (rewinder == 1) {
      wrongTry = 6;
      introduction(answer);
      length = strlen(answer); // What is the size of the string answer?
      for (i = 0; i < length; i++) //Initialize all mask value to 0.
      {
         char_seen[i] = 0;
      }
      Print();
      clear;
      load();
      clear;
      planeFig();

      printf("Missed Letters:");
      while (!gameover) {
         // Print word with '_' for unguessed letters
         printf("\nMystery Word : ");
         int j;
         for (j = 0; j < length; ++j) {
            if (char_seen[j]) {
               printf("%c", answer[j]); //substituter  for the guess letters
            } else {
               printf("_ "); //putter for the unguess letters.
            }
         }
         printf("\n");

         // Take the player's next guess
         char guess;
         printf("Guess a Letter. \n");
         scanf(" %c", & guess);

         //duplicate stopper
         for (x = 0; x < limit; x++) {
            if (guess == missed[x]) {
               printf("You have already guess that letter. Choose again. (press any Enter to Guess Again. ) \n");
               getch();
            }
         }

         //If there is a guess correct-identifer
         int l, match = 0;
         for (l = 0; l < length; ++l)
            if (guess == answer[l]) //if there is a match
         {
            match = 1;
            break;
         }

         //if there is no match
         if (match == 0) {
            printf("\nMissed Letters: ");
            missed[x] = guess;
            for (r = 0; r < limit; r++)
               printf(" %c", missed[r]);
            x++;
            limit++;
            --wrongTry;
            showHangman(wrongTry);
            printf("\nMissed Letters: ");
            for (r = 0; r < limit; r++)
               printf(" %c", missed[r]);
         }

         //if there is a match but is repeated
         if (match == 1) {
            int k;
            for (k = 0; k < length; k++) {
               if (answer[k] == guess) {
                  if (char_seen[k]) //if true
                  {
                     missed[x] = guess;
                     for (r = 0; r < limit; r++)
                        printf(" %c", missed[r]);
                     x++;
                     limit++;
                     --wrongTry;
                     showHangman(wrongTry);
                     printf("\nMissed Letters: ");
                     for (r = 0; r < limit; r++)
                        printf(" %c", missed[r]);
                  }
                  char_seen[k] = 1;
               }
            }
         }

         //Verify char_seen if all is filled up.
         int sea = 0;
         gameover = 1;
         for (sea = 0; sea < length; sea++) {
            if (!char_seen[sea]) {
               gameover = 0;
               break;
            }
         }

         //Stop if wrong try reaches limit , or reaches 0.
         if (wrongTry == 0) {
            gameover = 0;
            break;
         }

      } //stop the greatwhile if gameover reaches 0.

      //Results of the Game.
      if (wrongTry == 0) {
         printf("\n\nYou lost! The secret word is \"%s\"!\n", answer);
      }

      if (wrongTry > 0) {
         printf("\n\nYes! The secret word is \"%s\"! You have won!\n", answer);
      }
      int battery = 1; //battery for incorrect input
      while (battery == 1) {
         printf("Do you want to play again? (yes or no)\n");
         char say[3];
         scanf("%s", say);
         if (strcmp(say, "yes") == 0) {
            rewinder = 0;
            battery = 0;
            clear;
            goto THE_ALL_REPEATER_SHORTCUT;
         } //if yes then repeat hangman game program since rewinder =1 and battery 0.
         else if (strcmp(say, "no") == 0) {
            rewinder = 0;
            battery = 0;
         } // if no then stop the program.
         else battery = 1;
      } // end of while

   } //The greatest While	or the Hangman Program Game or while (rewinder)
   return 0;
} //Main Body

/*********************
Declaration of Functions
**********************/

void Print() {

   /*********************
   Shows the instructions to the user
   Instructions on how to play the Hangman Game
   ***********************/

   printf("\t\t\t\t\tWelcome to the Hangman Game.\n"); //load();
   getch();
   clear;
   printf("Game instructions:\n");
   printf("\n-> The player must discover the word by guessing letters one at a time.\n\n->"
      " On each wrong guess, a body part is added to a picture of a hanged man. \n\n-> "
      "Player is allowed 5 mistakes, corresponding to hangman's head, body, left arm, right arm, left leg. At the 6th mistake the right leg is drawn, and the game is over. \n\n->"
      " If a letter is repeated more than once, the repeating occurrences are always considered as an error, even if the first time was correct.\n\n->"
      " Once the hanged man is complete, the player loses the game.\n");
   printf("\n\nPress any key to play game...");
   getch();
} //end if void Print

void load() {

   /**************
   shows the loading animation
   ***************/
   int r, q;
   printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t    loading...\n\n\n\n\t\t\t\t\t");
   for (r = 1; r <= 20; r++) {
      for (q = 0; q <= 100000000; q++); //to display the character slowly
      printf("%c", 219);
   }
   printf("\n\n\t\t\t\t(please press any key to continue)");
   getch();
} //end of void load

int introduction(char * answer) {

   /*************************************************
   This is the introduction of the game.
   It asks the user to enter a word to be guessed
   OR he/she will let the program choose for the
   words to be guessed.
   *************************************************/

   char answer1[100]; {
      printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\n");
      printf("#    #       *      # *    #    ########            #        #                 *         #*      #					    \n");
      printf("#    #      * *     #  *   #    #                  #  #    #   #              * *        #  *    #						\n");
      printf("#    #     *   *    #   *  #    #                 #   #   #      #           *   *       #   *   #			            \n");
      printf("######    *******   #    * #    #  #####         #      #         #         *******      #    *  #			            \n");
      printf("#    #    *     *   #     *#    #      #        #       #         #         *     *      #     * #				        \n");
      printf("#    #    *     *   #     *#    #      #       #        #         #         *     *      #      *#				        \n");
      printf("#    #    *     *   #      #    ########      #          #         #        *     *      #       #  		            \n");
      printf("\n\n     Welcome to the Hangman Game. \n-->This program was made by Asher V. Manangan <--\n        URL: ashermanangan.xyz\n");
   }

   //Ask the user for decision and save it to choice.
   int MainMenu = 777;
   while (MainMenu == 777) {
      int decide;
      printf("\nPress 1. Enter the Hangman Word (2 or more players).\nPress 2. Generate a random Hangman Word (You vs Computer).\nDecision: ");
      scanf("%d", & decide);
      getchar();
      if (decide == 1) goto choice1;
      else if (decide == 2) goto choice2;
      else printf("\nIncorrect Input: ");
      MainMenu = 777;
   }

   choice1: {

      printf("\n\nEnter the word to be guessed: ");
      scanf("%s", answer);
      printf("\nYour input: %s", answer);
      printf("\n\n(press any key to continue)");getch();clear;
      return *answer;
   }

   choice2: {

      randomizer;
      char words[e][8] = {
         "cat",
         "dog",
         "cow",
         "rainbow",
         "water",
         "apple",
         "love",
         "cotton",
         "camel",
         "cloud"
      };
      int f;
      f = rand() % 10;
      //  printf("This is the random word: %s", words[f]);
      printf("\nGenerated Successfully");
      strcpy(answer, words[f]);
      printf("\n\n(press any key to continue)");getch();clear;
      return *answer;
   }

} //end for int introduction (char *answer) function

void showHangman(int choice) {

   /*********************************************
   This function show the hangman progress
   of being hanged after each wrong try
   **********************************************/

   switch (choice) {

   case 0:
      system("cls");
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO/", '\\');
      printf("\n\t||    |                                              YOU LOSE THE GAME!");
      printf("\n\t||   / %c", '\\');
      printf("\n\t||      ");
      break;
   case 1:
      system("cls");
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO/", '\\');
      printf("\n\t||    | ");
      printf("\n\t||     %c", '\\');
      printf("\n\t||      ");
      break;
   case 2:
      system("cls");
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO/", '\\');
      printf("\n\t||    | ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      break;
   case 3:
      system("cls");
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO/", '\\');
      printf("\n\t||      ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      break;
   case 4:
      system("cls");
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||   %cO ", '\\');
      printf("\n\t||      ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      break;
   case 5:
      system("cls");
      printf("\n\t||===== ");
      printf("\n\t||    | ");
      printf("\n\t||    O ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      printf("\n\t||      ");
      break;
   } //end of switch-case
   return;
} //end of showhangman

void planeFig(void) {

   /**show the HANGMAN**/

   printf("\n\n\n");
   printf("\tH A N G M A N");
   printf("\n\t+------+");
   printf("\n\t|      | ");
   printf("\n\t|        ");
   printf("\n\t|        ");
   printf("\n\t|        ");
   printf("\n\t|       ");
   printf("\n\t========\n\n\n");
} //end of void plane fig
