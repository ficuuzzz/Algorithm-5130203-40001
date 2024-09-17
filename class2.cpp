#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout << "Prime numbers: "<<endl;
    int div,n;
    for (n=2; n<=100; n++){
        div =2;
        while(div < n){
            if(n % div == 0) break;
            div++;
        }
        if (div == n)
            cout << n << " ";
    }
    return 0;
}
// не работает...........
// РАБОТАЕТ