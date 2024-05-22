#include <iostream>
#include <stack>
#include <string>
#include <vector>
 
using namespace std;
 
bool is_balanced(const string& str) {
    stack<char> stk;
    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty()) {
                return false;
            } else if ((c == ')' && stk.top() != '(') ||
                       (c == ']' && stk.top() != '[') ||
                       (c == '}' && stk.top() != '{')) {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}
 
int main() {
    int N;
    cin >> N;
    cin.ignore();
    
    vector<string> inputs(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, inputs[i]);
    }
 
    for (const auto& str : inputs) {
        cout << (is_balanced(str) ? "true" : "false") << endl;
    }
    
    return 0;
}
