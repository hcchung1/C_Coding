#include<iostream>
#include<string>
#include <string.h>
#include <stdlib.h>
using namespace std;

char * intToRoman(int num) {
  int numArr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  char *roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int count[13] = {0};
  char *str = (char*)malloc(17 * sizeof(char));
  memset(str, '\0', 17);
  for (int i = 0; i < 13; i++) {
      int count = num / numArr[i];
      while (count-- > 0)
      {
        strcat(str, roman[i]);
      }
      num %= numArr[i];
  }
  return str;
}

int main(void){



    string roman1;
    string roman2;

    while(cin >> roman1){

        if (roman1 == "#") return 0;
        cin >> roman2;
        int ro1[roman1.length()], ro2[roman2.length()];

    int num1 = 0,  num2 = 0, answer = 0;

    for (int i = 0 ; i < roman1.length() ; i++){

        if(roman1[i] == 'M'){

            num1 = num1 + 1000;

        }

        else if (roman1[i] == 'C' and roman1[i+1] == 'M'){

            num1 = num1 + 900;
            i = i+1;

        }

        else if (roman1[i] == 'D'){

            num1 = num1 + 500;

        }

        else if (roman1[i] == 'C' and roman1[i+1] == 'D'){

            num1 = num1 + 400;
            i = i+1;

        }

        else if (roman1[i] == 'C' ){

            num1 = num1 + 100;

        }

        else if (roman1[i] == 'X' and roman1[i+1] == 'C'){

            num1 = num1 + 90;
            i = i+1;

        }
        else if (roman1[i] == 'L'){

            num1 = num1 + 50;

        }

        else if (roman1[i] == 'X' and roman1[i+1] == 'L'){

            num1 = num1 + 40;
            i = i+1;

        }

        else if (roman1[i] == 'X'){

            num1 = num1 + 10;

        }

        else if (roman1[i] == 'I' and roman1[i+1] == 'X'){

            num1 = num1 + 9;
            i = i+1;

        }

        else if (roman1[i] == 'V'){

            num1 = num1 + 5;

        }

        else if (roman1[i] == 'I' and roman1[i+1] == 'V'){

            num1 = num1 + 4;
            i = i+1;

        }

        else if (roman1[i] == 'I'){
            num1 = num1 + 1;

        }

    }

    for (int i = 0 ; i < roman2.length() ; i++){

        if(roman2[i] == 'M'){

            num2 = num2 + 1000;

        }

        else if (roman2[i] == 'C' and roman2[i+1] == 'M'){

            num2 = num2 + 900;
            i = i+1;

        }

        else if (roman2[i] == 'D'){

            num2 = num2 + 500;

        }

        else if (roman2[i] == 'C' and roman2[i+1] == 'D'){

            num2 = num2 + 400;
            i = i+1;

        }

        else if (roman2[i] == 'C' ){

            num2 = num2 + 100;

        }

        else if (roman2[i] == 'X' and roman2[i+1] == 'C'){

            num2 = num2 + 90;
            i = i+1;

        }
        else if (roman2[i] == 'L'){

            num2 = num2 + 50;

        }

        else if (roman2[i] == 'X' and roman2[i+1] == 'L'){

            num2 = num2 + 40;
            i = i+1;

        }

        else if (roman2[i] == 'X'){

            num2 = num2 + 10;

        }

        else if (roman2[i] == 'I' and roman2[i+1] == 'X'){

            num2 = num2 + 9;
            i = i+1;

        }

        else if (roman2[i] == 'V'){

            num2 = num2 + 5;

        }

        else if (roman2[i] == 'I' and roman2[i+1] == 'V'){

            num2 = num2 + 4;
            i = i+1;

        }

        else if (roman2[i] == 'I'){
            num2 = num2 + 1;

        }

    }

    answer = (num1 - num2 < 0)? num2-num1:num1-num2;

    if(answer == 0){
        cout << "ZERO" << endl;
    }
    else{
        printf("%s\n", intToRoman(answer));
    }

    }



    return 0;


}
