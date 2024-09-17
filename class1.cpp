// calcuplate
// n [2,1000]
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int i, n, j=0,sum_div=0;
    do {
        cout <<  "Enter the n: "<<endl;
        cin >> n;
    } while(n < 2 || n>1000);
    
    cout<< "Divisors: "<<endl;
    for(i=1; i<=n; i++){
            if(n%i==0){
                cout<< i << "";
                j++;
                sum_div+=i;
        }
    }
    cout<< "numbers of div: " << j<<endl;
    cout<< "sum of div: " << sum_div << endl;

}