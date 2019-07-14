// Take a string and count unique word using hashing

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long redix,i,j,word=1,mod = 100000+3;
    vector<long long> vec;
    string str;
    cout << "Redix: ";
    cin >> redix ;
    cout << endl << "String: ";

    getchar();
    getline(cin,str);

    for(i=0;i<str.size();i++)
    {
        string str1 = "";
        long long num=0,num1=0,numb,power;
        while(1)
        {
            if(str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '/' || str[i] == '?')
                break;
            str1 = str[i]+str1;
            i++;
            if(i >= str.size())
                break;
        }
        cout << str1 << " - ";
        num=0;
        power=1;
        for(j=0;j<str1.size();j++)
        {
            numb = (long long)str1[j];


            num = (num + (numb)*(power))%mod;
            num1 = num1 + numb*power;
            power*=redix;
            power%=mod;
        }
        vec.push_back(num);
        //cout << num << " " << num1 << endl;
    }
    sort(vec.begin(),vec.end());
    for(i=1;i<vec.size();i++)
    {
        long long num;
        num = vec[i];
        if(vec[i]!=vec[i-1])
        word++;
    }

    cout << "Unique word " << word << endl;
    return 0;
}
