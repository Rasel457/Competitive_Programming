#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double

unordered_map<char,int>symbols={{'[',-1},{'(',-2},{'{',-3},{']',1},{')',2},{'}',3}};

string isBalanced(string s)
{
    stack<char>st;
    for(char braket:s)
    {
        if(symbols[braket]<0)
        {
            st.push(braket);
        }
        else
        {
            if(st.empty())
            {
                return "NO";
            }
            else{
                char top=st.top();
                st.pop();
                if(symbols[top]+symbols[braket]!=0)
                {
                    return "NO";
                }
            }
        }
    }
    if(st.empty())
    {
        return "YES";
    }
    else{
        return "NO";
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
         string s;
         cin>>s;
         cout<<isBalanced(s)<<endl;
    }



}
//https://vjudge.net/problem/UVA-673
//https://www.hackerrank.com/challenges/balanced-brackets/problem