// Time Limit Exceeded!!!!!!!!!
#include <iostream>
#include <vector>
#include <limits>
#include <map>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly_numbers(n, 0);
        vector<int> index(primes.size(), 0);
        map<int, int> sofar;
        
        sofar[1] = 0;
        ugly_numbers[0] = 1;
        int cnt = 1;

        while (cnt < n) {
            int min = numeric_limits<int>::max();
            int position = 0;
            for (int i = 0; i < primes.size(); i++) {
                int tmp = ugly_numbers[index[i]] * primes[i];
                if (tmp < min) {
                    min = tmp;
                    position = i;
                }
            }
            index[position]++;
            if (sofar.find(min) == sofar.end()) {
                ugly_numbers[cnt] = min;
                sofar[min] = 1;
                cnt++;
                cout << "cnt is " << cnt << endl;
                cout << "the ugly number is " << min << endl;
            }
        }
        return ugly_numbers[n-1];
    }
};

int main() {
    //vector<int> primes {3, 5, 7, 11, 19, 23, 29, 41, 43, 47};
    //int n = 15;
    vector<int> primes {2, 7, 13, 19};
    int n = 12;
    Solution s;
    int result = s.nthSuperUglyNumber(n, primes);
    cout << "The result is " << result << endl;
    return 0;
}
