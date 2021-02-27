// palindrome partition of string using backtracking
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string ans)
{

    int start = 0;
    int end = ans.length() - 1;

    while (start < end)
    {

        if (ans[start] != ans[end])
        {

            return false;
        }
        start++;
        end--;
    }
    return true;
}
void palindromicPartition(string str, string ans)
{

    if (str.length() == 0)
    {
        cout<< ans;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {

        string prefix = str.substr(0, i + 1);
        string ros = str.substr(i + 1);

        if (isPalindrome(prefix))
        {

            palindromicPartition(ros, ans+ "[ " + prefix+" ]"+" " );
        }
    }
}

int main()
{

    string str = "aaba";
    string result;

     palindromicPartition(str, "");
   
    return 0;
}