// генерация рандом чисел
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int main(){
    int n, a;
    char play;
    n = 1 + rand()%200;
    do{
        do{

            cout<< "Guess the number: ";
            cin>>a;
            while(a != n){
                if(a<n){
                    cout<< "\nToo low... please try again" <<endl;
                }
                else if(a>n){
                    cout<< "\nToo high... please try again"<<endl;
                }
            }
        }while(a!=n);
        cout<<"\nYou guess the number! n = "<<n<<endl;
        cout<<"\nWant play again? [Y/N]?"<<endl;
        cin>>play;
    }while(play == 'y' || play == 'Y');
    return 0;
}
//почему