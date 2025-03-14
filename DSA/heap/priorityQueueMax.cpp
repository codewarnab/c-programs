#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int> p; // max heap

    p.push(10);
    p.push(20);
    p.push(18);
    p.push(15);
    p.push(15);

    cout << p.top() << " ";

    // Delete
    p.pop();

    cout << p.top() << " ";

    // size
    cout << p.size() << endl;

    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
}