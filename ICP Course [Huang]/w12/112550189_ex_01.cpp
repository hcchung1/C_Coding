#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>

typedef struct _grade {
    int Chinese, Math, English, computer_science;
} grade;

struct student {
    char name[20];
    int student_id;
    grade student_grade;   
}stu[] = {{"Bob", 309553045, {0, 10, 20, 30}}, {"Kevin", 309551116, {100, 100, 50, 100}}, {"Dave", 309551110, {59, 80, 43, 70}}, {"Steve", 309552003, {95, 33, 10, 99}}, {"Stuart", 309552052, {80, 40, 70, 80}}};

int main(){

    int stunum = 5, attnum = 6, qunum = 4;

/*     student* stu = (student*)malloc(sizeof(student) * stunum);

    char enter[20];

    char** table = (char**)malloc(sizeof(char*) * attnum);

    for (int i = 0; i < attnum; i++) {
        table[i] = (char*)malloc(sizeof(char) * 20);
    } */

/*     table[0] = "NAME";
    table[1] = "StudentID";
    table[2] = "Chinese";
    table[3] = "Math";
    table[4] = "English";
    table[5] = "ComputerScience";



    for(int i = 0; i < stunum; i++){

        for(int j = 0; j < attnum; j++){

            scanf("%s", enter);

            if(strcmp(table[j], "NAME") == 0){

                for(int k = 0; k < strlen(enter); k++){
                    stu[i].name[k] = enter[k];
                }

            }
            else if(strcmp(table[j], "StudentID") == 0){

                stu[i].student_id = atoi(enter);

            }
            else if(strcmp(table[j], "Chinese") == 0){

                stu[i].student_grade.Chinese = atoi(enter);

            }
            else if(strcmp(table[j], "Math") == 0){

                stu[i].student_grade.Math = atoi(enter);

            }
            else if(strcmp(table[j], "English") == 0){

                stu[i].student_grade.English = atoi(enter);

            }
            else if(strcmp(table[j], "ComputerScience") == 0){

                stu[i].student_grade.computer_science = atoi(enter);

            }
        }

    } */

    int C, M, E, CS;

    // printf("Input queries score:\nC :");
    char enter[20];
    scanf("%s %d", enter , &C);
    // printf("M :");
    scanf("%s %d", enter, &M);
    //printf("E :");
    scanf("%s %d", enter, &E);
    //printf("CS:");
    scanf("%s %d", enter, &CS);

    printf("\nResult:\n");
    printf("Chinese:");
    for(int i = 0; i < stunum; i++){
        if(stu[i].student_grade.Chinese < C){
            printf("%d ", stu[i].student_id);
        }
    }
    printf("\nMath:");
    for(int i = 0; i < stunum; i++){
        if(stu[i].student_grade.Math < M){
            printf("%d ", stu[i].student_id);
        }
    }
    printf("\nEnglish:");
    for(int i = 0; i < stunum; i++){
        if(stu[i].student_grade.English < E){
            printf("%d ", stu[i].student_id);
        }
    }
    printf("\nComputerScience:");
    for(int i = 0; i < stunum; i++){
        if(stu[i].student_grade.computer_science < CS){
            printf("%d ", stu[i].student_id);
        }
    }
    printf("\n");
    return 0;    
}