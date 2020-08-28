#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void insert_at_bottom(stack<int> &s, int x)
{
    if(s.empty()){
        s.push(x);
    }
    else{
        int w;
        w = s.top();
        s.pop();
        insert_at_bottom(s,x);
        s.push(w);
    }
}

void rev(stack<int> &s)
{
    if(s.empty()) return;
    int x = s.top();
    s.pop();
    rev(s);
    insert_at_bottom(s,x);
}

void showstack(stack <int> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

int main()
{
    stack<int> s;
    queue<int> v;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    showstack(s);
    rev(s);
    showstack(s);
}
