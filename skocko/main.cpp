#include <iostream>
#include <cstdlib>
#include <ctime>

void printArr(const int arr[])
{   
    for(int i=0;i < 4; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generateArr(int arr[])
{
    for(int i=0;i < 4; i++)
    {
        int r = std::rand() % 6;  
        arr[i] = r;
    }
}

void readArr(int arr[])
{
    int el;
    printf("give 4 elements, [0-3], space/enter separated \n");
    for(int i=0;i < 4; i++){        
        std::cin >> el;
        arr[i] = el;
    }
}

bool guessArr(const int arr[], const int arra[]){
/*  
    printf("compare "); 
    printArr(arr);
    printf("with    "); 
    printArr(arra);
*/
    int correct=0;
    int incorrect=0;
    int marked[4] = {0,0,0,0};
    int marked_j[4] = {0,0,0,0};
    for(int i=0;i < 4; i++){
        if(arr[i] == arra[i]){
            marked[i] = 1;
            marked_j[i] = 1;
            correct++;
        }
    }
    for (int i = 0; i < 4; i++){
        if (marked[i] == 0){
            for (int j = 0; j < 4; j++){
                if (marked[i] == 0 && marked_j[j] == 0){
                    if (arr[j] == arra[i]){
                        //printf("found inc i %d j %d\n", i, j);
                        marked[i] = 1;
                        marked_j[j] = 1;
                        incorrect++;
                    }
                }
            }
        }
    }
    printf("correct %d incorrect %d\n", correct, incorrect);
    return correct==4;
}


int main()
{
    std::srand(std::time(NULL));   // Initialization, should only be called once. 

    int array[4];
    int guessArray[4] = {3,3,3,3};
    generateArr(array);//readArr(array);
    //printf("you gave\n");
    //printArr(array);
    int steps = 1;
    bool currentGuess = false;
    while(!currentGuess){
        printf("guessing step %d \n", steps++);        
        readArr(guessArray);
        currentGuess = guessArr(guessArray, array);
        if(steps == 7)
            printArr(array);
    }

    return 0;    
}


/*
    int array[4];
    generateArr(array);
    int guessArray[4] = {3,3,3,3};
    int steps = 1;
    bool currentGuess = false;
    while(!currentGuess){
        printf("guessing step %d \n", steps++);
        generateArr(guessArray);
        currentGuess = guessArr(guessArray, array);
    }


        int ts[8][4] = {{2,3,0,0}, {2,3,1,0}, {3,2,0,0}, {0,1,2,3}, 
                    {0,0,0,0}, {1,1,1,1}, {2,2,2,2}, {3,3,3,3}};
    for(int i=0;i < 8; i++){
        guessArr(ts[i]);
    }
*/