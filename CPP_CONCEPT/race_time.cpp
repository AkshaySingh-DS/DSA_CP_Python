#include <iostream>
using namespace std;

long double good(long double mid, long double speed[], long double distance[],long long int n){

        long double maxi = 0.0, mini = 1.0e18;
        long double diff;
        for(long long int i ; i < n; i++){

            diff = speed[i] * mid + distance[i];
            maxi = max(maxi, diff);
            mini = min(mini, diff);
        }

    return (maxi - mini);
}
long double raceTimeTernarySearch(long double speed[], long double distance[], long long int n, long long int k){

        long double left = 0.0, right = double(k);
        long double mid, mid1, mid2, fm1, fm2;
        for (long long int i ; i < n ;i++){

                mid = (right - left) / 3;
                mid1 = left + mid;
                mid2 = right - mid;

                fm1 = good(mid1, speed, distance, n);
                fm2 = good(mid2, speed, distance, n);

                if (fm1 > fm2){

                    left = mid1;

                }
                else{

                    right = mid2;

                }
        }

        return good(left, speed, distance, n);
}
int main(){

    long long int n, k;
    long double speed[10000000], distance[10000000];
    
    cin >> n >> k;
    for (long long int i = 0; i < n; i++){

            cin >> speed[i] >> distance[i];

    }

    cout << raceTimeTernarySearch(speed, distance, n, k);


    return 0;
}