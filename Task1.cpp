// Take a string and count unique word using hashing

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long redix,i,j,word=0,mod = 100000+3;
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
        long long num=0;
        while(1)
        {
            if(str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '/' || str[i] == '?')
                break;
            str1 = str[i]+str1;
            i++;
            if(i >= str.size())
                break;
        }
        for(j=0;j<str1.size();j++)
        {
            long long numb,power;
            numb = (long long)str[j];
            power = pow(redix,j);
            num = (num + (numb)*(power))%mod;
        }
        vec.push_back(num%mod);
    }
    sort(vec.begin(),vec.end());
    for(i=0;i<vec.size();i++)
    {
        long long num;
        num = vec[i];
        while(vec[i] == num)
        {
            i++;
            if(i >= vec.size())
                break;
        }
        i--;
        word++;
    }

    cout << "Unique word " << word << endl;
    return 0;
}
