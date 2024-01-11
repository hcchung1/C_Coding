#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    
    int rook;

    if(a == e){
        bool flag = false;
        if(b<d && d<f) flag = true;
        if(b>d && d>f) flag = true;
        // printf("%d\n", flag);
        rook = 1;
        if((c == e) && flag) rook = 3;
    }
    else if(b == f){
        bool flag = false;
        if(a<c && c<e) flag = true;
        if(a>c && c>e) flag = true;
        rook = 1;
        if((d == f) && flag) rook = 3;
    }   
    else rook = 2;

    int bishop;
    if(abs(c-e) == abs(d-f)) {

        bool flag = false;
        if(a<c && a>e){
            if(b<d && b>f) flag = true;
            if(b>d && b<f) flag = true;
        }
        if(a>c && a<e){
            if(b<d && b>f) flag = true;
            if(b>d && b<f) flag = true;
        }

        // printf("%d\n", flag);

        if(abs(a-c) == abs(b-d) && flag == true) bishop = 2;

        else bishop = 1;

    }
    else bishop = 2;

    // printf("%d %d\n", rook, bishop);

    return(rook < bishop ? rook : bishop);

}

int main(){

    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    printf("%d", minMovesToCaptureTheQueen(a, b, c, d, e, f));


}