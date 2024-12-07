#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void winnerfunc(int robo, int hum)
{
    if (robo > hum)
    {
        printf("\nTotal Points:\nRobot-%d\nYou-%d\n---------------------You lost the game!---------------------", robo, hum);
    }
    else if (hum > robo)
    {
        printf("\nTotal Points:\nYou-%d\nRobot-%d\n---------------------Congratulations! You won!---------------------", hum, robo);
    }
    else if (hum == robo)
    {
        printf("\nTotal Points:\nYou-%d\nRobot-%d\n---------------------Match Draw!!!---------------------", hum, robo);
    }
}

int main()
{
    int robot, num, i, tp_human, tp_robot, repeat;
    char human;
    
    printf("\n\n--------------------------------Welcome to the Rock-Paper-Scissor Game!--------------------------------\n\n");

   
    while (1) {
        tp_human = 0;
        tp_robot = 0;
        
        printf("Enter how many times you want to play: ");
        scanf("%d", &num);
        getchar(); 
        printf("\n---------------------Let's start!---------------------\n");
        printf("\nNote: You will get a penalty if you input invalid characters.\n\n");

        for (i = 0; i < num; i++)
        {
            printf("\nChoose your option-\nr. Rock\np. Paper\ns. Scissor\n\nYour choice is: ");
            human = getchar(); 
            getchar(); 

            
            if (human != 'r' && human != 'p' && human != 's') {
                printf("\nInvalid Input! As a penalty, it's going to be counted as a draw.\n");
                continue; 
            }

            srand(time(NULL));
            robot = (rand() % 3) + 1;  

            if (robot == 1) {
                printf("Robot chose Rock\n");
            } else if (robot == 2) {
                printf("Robot chose Paper\n");
            } else {
                printf("Robot chose Scissors\n");
            }

           
            if ((human == 'r' && robot == 1) || (human == 'p' && robot == 2) || (human == 's' && robot == 3)) {
                printf("\nDraw!!!\n");
            }
            else if (human == 'r' && robot == 2) {
                printf("\nRobot got 1 point\n");
                tp_robot++;
            }
            else if (human == 'r' && robot == 3) {
                printf("\nYou got 1 point\n");
                tp_human++;
            }
            else if (human == 'p' && robot == 1) {
                printf("\nYou got 1 point\n");
                tp_human++;
            }
            else if (human == 'p' && robot == 3) {
                printf("\nRobot got 1 point\n");
                tp_robot++;
            }
            else if (human == 's' && robot == 1) {
                printf("\nRobot got 1 point\n");
                tp_robot++;
            }
            else if (human == 's' && robot == 2) {
                printf("\nYou got 1 point\n");
                tp_human++;
            }

            
            printf("\n--------------\n--------------\n");
            #ifdef _WIN32
            Sleep(1000); 
            #else
            sleep(1); 
            #endif
        }

        
        winnerfunc(tp_robot, tp_human);

        
        printf("\n\n--------------------------------\n\n");
        printf("Want to Play Again?\nPress (1)\nEnter any other key to exit\n");
        scanf("%d", &repeat);

        if (repeat != 1) {
            printf("Thank You for playing!\n");
            break; 
        }
        
    }
    return 0;
}
