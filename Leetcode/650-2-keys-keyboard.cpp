class Solution {

    vector<int> get_prime_factors(int n) {

        vector<int> factors;
        
        while(n % 2 == 0) {
            n /= 2;
            factors.push_back(2);
        }

        for(int p = 3; p <= sqrt(n); p += 2) {
            while(n % p == 0) {
                n /= p;
                factors.push_back(p);
            }
        }

        if(n > 2) {
            factors.push_back(n);
        }

        return factors;

    }

public:
    int minSteps(int n) {

        vector<int> prime_factors = get_prime_factors(n);
        
        int operations = 0;
        for(int &p : prime_factors) {
            operations += p;
        }

        return operations;
        
    }
};