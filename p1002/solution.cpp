#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

void solution(const string &in,const int &key,const int &count)
{
    int de_key = in.size()/key;
    int loca = 0;
    cout << "Case #" << count+1 << ":" << endl;
    if (key == 1)
    {
        cout << in << endl;
        return;
    }

    if (in.size()%key == 0){
        // 整除
        for (int i=0;i<de_key;++i)
            for (int j=0;j<key;++j)
                cout << in[i+j*de_key];
    }
    else{
        for (int i=0;i<de_key+1;++i){
            loca = i;
            if (i <de_key){
                for (int j=0;j<key;++j){
                    if (j <= 0)
                        loca += 0;
                    else if (j < in.size()-key*de_key)
                        loca += de_key+1;
                    else
                        loca += de_key;
                    cout << in[loca];
                }
            }
            else{
                for (int j=0;j<in.size()-key*de_key;++j){
                    if (j <= 0)
                        loca += 0;
                    else if (j < in.size()-key*de_key)
                        loca += de_key+1;
                    else
                        loca += de_key;
                    cout << in[loca];
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    //get input
    int testNum = 0;
    cin >> testNum;
    string blank;
    getline(cin,blank);

    vector<string> in_str;
    vector<int> key_list;
    string tmp_str;
    int tmp_key;

    for (int i=0;i<testNum;++i)
    {
        getline(cin,tmp_str);
        in_str.push_back(tmp_str);

        cin >> tmp_key;
        key_list.push_back(tmp_key);
        getline(cin,blank);
    }
    //manipulation process
    for (int i=0;i<testNum;++i){
        solution(in_str[i],key_list[i],i);
    }
    return 0;
}

