#include <iostream>
#include <fstream>
#include <vector>

int main() {
  
    int64_t N;
    {
        std::ifstream entrada_original("data.in", std::ifstream::in);
        entrada_original >> N;
        for (int16_t i = 0; i < N; ++i) {
            int64_t x;
            entrada_original >> x;
        }
    }

    int64_t possible;
    {
        std::ifstream salida_original("data.out", std::ifstream::in);
        salida_original >> possible;
    }

    if(possible == -1) {

        int64_t veredict;

        if(!(std::cin >> veredict)) {
            std::cerr << "Error leyendo la salida del concursante\n";
            std::cout << 0.0 << '\n';
            return 0;
        }
        
        if(veredict == -1) {
            std::cout << 1.0 << '\n';
            return 0;
        } else {
            std::cout << 0.0 << '\n';
            return 0;
        }

    }

    std::vector<int64_t> nums(N);

    for (int64_t i = 0; i < N; ++i) {
        if(!(std::cin >> nums[i])) {
            std::cerr << "Error leyendo la salida del concursante\n";
            std::cout << 0.0 << '\n';
            return 0;
        }
    }

    int64_t alice_sum = 0, bob_sum = 0;
    
    for (int64_t i = 0; i < N; ++i) {
        if(alice_sum <= bob_sum) {
            alice_sum += nums[i];
        } else {
            bob_sum += nums[i];
        }
    }

    if(alice_sum != bob_sum) {
        std::cout << 0.0 << '\n';
        return 0;
    }

    std::cout << 1.0 << '\n';

    return 0;
}