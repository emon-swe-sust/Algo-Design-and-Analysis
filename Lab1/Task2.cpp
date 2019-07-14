// Implement division method of hashing in string using a table

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long redix,i,j,word=0,mod = 100000+3,loop;
    vector<long long> vec;
    vector<long long>List[100000+3];
    string str,str2;
    cout << "Redix: ";
    cin >> redix ;
    cout << endl << "String: ";

    getchar();
    getline(cin,str);

    for(i=0;i<str.size();i++)
    {
        string str1 = "";
        long long num=0,num1=0;
        while(1)
        {
            if(str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '/' || str[i] == '?')
                break;
            str1 = str1+str[i];
            i++;
            if(i >= str.size())
                break;
        }
        reverse(str1.begin(),str1.end());
        long long power = 1;
        for(j=0;j<str1.size();j++)
        {
            long long numb;
            numb = (long long)str1[j];
            num = (num + (numb*power)%mod)%mod;
            num1 = num1 + numb*power;
            power = power * redix;
            power%=mod;
        }
        num = num%mod;
        vec.push_back(num%mod);
        List[num].push_back(num1);
        cout << num << " " << num1 << endl;;
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
        if(num != 0)
        word++;
    }

    cout << "Unique word " << word << endl;

    Search:;

    cout << "Search String: ";
    cin >> str2;

    reverse(str2.begin(),str2.end());
    long long num=0,numb=0,num1=0,power=1;

    for(i=0;i<str2.size();i++)
    {
        numb = (long long)str2[i];
        num = (num + (numb * power)%mod)%mod;
        num1 = num1 + numb*power;
        power = power*redix;
        power = power%mod;
    }
    cout << num << " " << num1 << endl;
    for(i=0;i<List[num].size();i++)
    {
        if(List[num][i] == num1)
        {
            cout << "FOUND" << endl;
            goto here;
        }
    }
    cout << "NOT FOUND" << endl;
    here:;

    cout << "If want to search again type 1: ";

    cin >> loop;
    if(loop == 1)
        goto Search;
    return 0;
}
