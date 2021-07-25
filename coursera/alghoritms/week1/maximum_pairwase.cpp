#include <iostream>

using namespace std;

long long n, a, max_first, max_second;


int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a;

        if(a >= max_first){
            max_second = max_first;
            max_first = a;
        }else if(a > max_second){
            max_second = a;
        }
    }

    cout << max_first * max_second;

    return 0;
}