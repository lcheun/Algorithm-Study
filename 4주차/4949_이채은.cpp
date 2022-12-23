#include<iostream>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    while(true){
        getline(cin, str);
        if(str == ".") break;
        
        stack<char> brackets;
        bool flag = true;
        
        for(char c : str) {
            if(c == '(' || c == '['){
                brackets.push(c);
            } else if (c == ')'){
                if(brackets.empty() || brackets.top() == '['){
                    flag = false; break;
                }
                brackets.pop();
            } else if ( c == ']'){
                if(brackets.empty() || brackets.top() == '('){
                    flag = false; break;
                }
                brackets.pop();
            }
        }
        cout << ((brackets.empty() && flag)? "yes":"no") << '\n';
    }
}
