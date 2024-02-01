#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int arr[4][4] = {{0,2,0,1},{2,1,3,0},{0,3,2,1},{1,0,1,3}};
    //A - 0, G-1, C-2, T-3
    
    int num;
    cin >> num;
    string s;
    cin >> s;
    
    for(int i =0;i<s.length();i++)
    {
        if(s[i] == 'A')
        {
            v.push_back(0);
        }
        else if(s[i]=='G'){
            v.push_back(1);
        }
        else if(s[i] == 'C')
        {
            v.push_back(2);
        }
        else{
            v.push_back(3);
        }
    }
    
    int n = v.size()-1;
    for(int i =n;i>0;i--)
    {
        int a = v[i];
        int b = v[i-1];
        int val = arr[b][a];
        v.erase(v.begin()+i-1, v.begin()+i+1);
        v.push_back(val);
    }
    
    if(v[0] == 0)
    {
        cout<<"A"<<endl;
    }else if(v[0]==1)
    {
        cout << "G"<<endl;
    }else if(v[0]==2)
    {
        cout<<"C"<<endl;
    }else{
        cout<<"T"<<endl;
    }
    

    return 0;
}