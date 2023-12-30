#include<iostream>
#include<algorithm>
#include<functional>
#include<math.h>
#include<stdlib.h>
using namespace std;

int m, n, h, r, c, p, num = 0, in = 0, times=0;
int q[100][100], total[200];

void arr(int x, int y){

    in = (q[x][y] == 0)?(0):(1);
    for(int i = y-1; i >=0; i-- ){
        if(q[x][i]==2){
            for(int k = y-1; k > i; k--){
                q[x][k] = in;
            }
            break;
        }
    }
    for(int i = y+1; i <=n; i++ ){
        if(q[x][i]==2){
            for(int k = y+1; k < i; k++){
                q[x][k] = in;
            }
            break;
        }
    }
    for(int i = x-1; i >=0; i-- ){
        if(q[x][i]==2){
            for(int k = x-1; k > i; k--){
                q[x][k] = in;
            }
            break;
        }
    }
    for(int i = x+1; i <=m; i++ ){
        if(q[x][i]==2){
            for(int k =x+1; k < i; k++){
                q[x][k] = in;
            }
            break;
        }
    }
    for(int i = 0; i < m; i++){

        for(int k = 0; k < n; k++){
            total[times] = total[times]+q[i][k];
        }
    }
    total[times] = total[times]-num;
    times++;

}

int main(){

    cin >> m >> n >> h;
    for(int i = 0;i < h; i++){
        cin >> r >> c >> p;
        if(i == 0) {
            num++;
            total[0]=1;
            times++;
            q[r][c]=2;
            continue;
        }
        if(p==0){
            num++;
            q[r][c] = 2;
            arr(r, c);
        }
        else{
            num--;
            q[r][c] = 0;
            arr(r, c);
        }
    }
    int last = total[times-1];
    sort(total, total+h, greater<int>());
    for(int i = 0; i < m; i++){

        for(int k = 0; k < n; k++){
            cout << q[i][k] << " ";
        }
        cout << '\n';
    }
    cout << total[0] << '\n';
    cout << last;
}