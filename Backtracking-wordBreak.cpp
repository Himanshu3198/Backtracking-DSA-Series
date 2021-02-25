#include <bits/stdc++.h>
using namespace std;

bool dictContains(string &word)
{
     bool isexits=false;
    string dictionary[] = {"i", "love", "icecream", "ice", "cream","chocolate"};

    int n = sizeof(dictionary) / sizeof(dictionary[0]);

    for (int i = 0; i < n; i++)
    {
        if (dictionary[i].compare(word)==0)
             {
                 isexits=true;
                 return isexits;
             }

       
    }
 return isexits;

}

void wordBreak(string str,string ans){

    if(str.length()==0){
         cout<< ans<<"\n";
    }

        for(int i=0;i<str.length();i++){

            string left=str.substr(0,i+1);
            if(dictContains(left)){
                string right=str.substr(i+1);
                wordBreak(right,ans+left+" ");
            }
        }
      
}





int main()
{
 

   wordBreak("iloveicecreamchocolate"," ");

 
     return 0;
}