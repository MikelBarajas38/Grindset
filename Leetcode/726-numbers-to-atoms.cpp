#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {

        int n = formula.size();
        stack<string> atoms;
        stack<string> helper;

        for(int i = 0; i < n; i++) {
            
            if(isupper(formula[i])) {

                string atom = "";
                atom += formula[i];

                i++;
                while(i < n && islower(formula[i])) {
                    atom += formula[i];
                    i++;
                }

                atoms.push(atom);

                if(i > n || !isdigit(formula[i])) {
                    atoms.push("1");
                }

                i--;

            } else if(isdigit(formula[i])) {

                string count = "";
                while(i < n && isdigit(formula[i])) {
                    count += formula[i];
                    i++;
                }
                i--;

                atoms.push(count);

            } else if(formula[i] == ')') {

                i++;
                string count = "";
                while(i < n && isdigit(formula[i])) {
                    count += formula[i];
                    i++;
                }

                if(count == "") {
                    count = "1";
                }

                while(atoms.top() != "(") {
                    helper.push(atoms.top());
                    atoms.pop();
                }
                atoms.pop();

                while(!helper.empty()) {
                    string part = helper.top();
                    helper.pop();
                    if(isdigit(part[0])) {
                        int val = stoi(part) * stoi(count);
                        part = to_string(val); 
                    }
                    atoms.push(part);
                }
                i--;

            } else {
                string atom = "";
                atom += formula[i];
                atoms.push(atom);
            }

        }

        map<string, int> m;
        while(!atoms.empty()) {
            int count = stoi(atoms.top());
            atoms.pop();
            string atom = atoms.top();
            atoms.pop();
            m[atom] += count;
        }

        string res = "";
        for(auto &[atom, count] : m) {
            res += atom;
            if(count > 1) {
                res += to_string(count);
            }
        }

        return res;
        
    }
};

int main() {

    Solution s;

    string formula = "Mg(H2O)N";
    cout << s.countOfAtoms(formula) << '\n';

    formula = "Mg(OH)2";
    cout << s.countOfAtoms(formula) << '\n';

    formula = "K4(ON(SO3)2)2";
    cout << s.countOfAtoms(formula) << '\n';

    return 0;
}