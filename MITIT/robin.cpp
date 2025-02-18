#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t; // scanf("%d", &t);


    for(int i = 0; i < t; i++) {

        int n, k;
        cin >> n >> k;

        int inventario_robin = 0;
        int cont = 0;

        for(int j = 0; j < n; j++) {

            int oro_a;
            cin >> oro_a;

            if(oro_a >= k) {
                inventario_robin += oro_a;
            } else if(oro_a == 0 && inventario_robin >= 1) {
                inventario_robin--;
                cont++;
            }

        }

        cout << cont << '\n';

    }

    return 0;

}