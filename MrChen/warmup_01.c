# include <stdio.h>

void toHexa(int num){
    char hexa[32];
    int len=0;

    if(num == 0){

        hexa[len] = '0';
        len++;

    }

    while(num > 0){

        len++;

        switch( num % 16 ){

            case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:

                hexa[len-1] = num%16 + '0';
                break;

            case 10:

                hexa[len-1] = 'A';
                break;

            case 11:

                hexa[len-1] = 'B';
                break;

            case 12:
            
                hexa[len-1] = 'C';
                break;

            case 13:

                hexa[len-1] = 'D';
                break;

            case 14:

                hexa[len-1] = 'E';
                break;

            case 15:
            
                hexa[len-1] = 'F';
                break;

            default:

                printf("Something Wrong!");

        }

        num = (num / 16);
        

    }

    printf("0x");

    for(int i=len-1; i>=0; --i){ 

        printf("%c", hexa[i]);

        

    }

}

int main(){
    int input;
    scanf("%d", &input);
    toHexa(input);
    return 0;
}

// this is a comment line
/* this is another 
comment line */