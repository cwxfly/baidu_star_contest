#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//const int CODE_LEN = 26;

//struct nameCode
//{
//    unsigned long _code[CODE_LEN];
//    unsigned long _count;
//    nameCode(){
//        for (int i=0;i<CODE_LEN;++i){
//            _code[i] = 0;
//        }
//        _count = 0;
//    }
//    bool equal(nameCode &);
//    void update(){++ _count;}
//};

//bool nameCode::equal(nameCode & tmp_code)
//{
//    for (int i=0;i<CODE_LEN;++i)
//    {
//        if (tmp_code._code[i] != _code[i])
//            return false;
//    }
//    return true;
//}

//unsigned long solution(const string & in_str,vector<nameCode> &name_code_list)
//{
//    nameCode tmp_name_code;
//    for (string::size_type i=0;i<in_str.size();++i)
//    {
//        tmp_name_code._code[in_str[i]-65] += 1;
//    }

//    if (name_code_list.empty()){
//        name_code_list.push_back(tmp_name_code);
//        name_code_list[0].update();
//        return 0;
//    }

//    // if tmp_name_code within name_code_list, revise name_code_list
//    unsigned long i=0;
//    bool within = false;
//    for (;i<name_code_list.size();++i){
//        if (name_code_list[i].equal(tmp_name_code)){
//            name_code_list[i].update();
//            within = true;
//            break;
//        }
//    }
//    // if tmp_name_code without name_code_list, add tmp_name_code into name_code_list
//    if (!within){
//        name_code_list.push_back(tmp_name_code);
//        name_code_list[name_code_list.size()-1].update();
//        return 0;
//    }
//    else
//        return name_code_list[i]._count-1;

//}
const int CODE_LEN = 26;

struct nameCode
{
    int _code[CODE_LEN];
//    void setValue(const string &name){
//            for (string::size_type i=0;i<name.size();++i)
//            {
//                _code[name[i]-65] += 1;
//            }
//    }
    //默认构造函数
    nameCode(){
        for (int i=0;i<CODE_LEN;++i){
            _code[i] = 0;
        }
    }
    nameCode(const string &name){
        for (int i=0;i<CODE_LEN;++i){
            _code[i] = 0;
        }
        for (string::size_type i=0;i<name.size();++i)
        {
            _code[name[i]-65] += 1;
        }
    }
    //复制构造函数
    nameCode(const nameCode&);
    //重载赋值操作符
    nameCode& operator = (const nameCode&);
    //重载关系操作符 定义为非成员函数

//    friend bool operator < (const nameCode &ls, const nameCode &rs);
//    bool operator < (const nameCode &other) const{
//        for (int i=0;i<CODE_LEN;++i)
//        {
//            if (_code[i] < other._code[i])
//                return true;
//            if (_code[i] > other._code[i])
//                return false;
//        }
//        return false;
//    }
};
nameCode::nameCode(const nameCode &obj)
{
    for (int i=0;i<CODE_LEN;++i){
        _code[i] = obj._code[i];
    }
}

nameCode& nameCode::operator = (const nameCode &obj)
{
    for (int i=0;i<CODE_LEN;++i){
        this->_code[i] = obj._code[i];
    }
    return *this;
}
bool operator < (const nameCode &ls, const nameCode &rs)
{
    for (int i=0;i<CODE_LEN;++i)
    {
        if (ls._code[i] < rs._code[i])
            return true;
        if (ls._code[i] > rs._code[i])
            return false;
    }
    return false;
}
unsigned long solution(const string &in_str,map<nameCode,unsigned long> &name_code)
{
    nameCode tmp = in_str;
//    tmp.setValue(in_str);
    if (name_code.find(tmp) == name_code.end()){ //未保存
        name_code.insert(map<nameCode,unsigned long>::value_type(tmp,1));
        return 0;
    }
    else{
        name_code[tmp] += 1;
        return name_code[tmp]-1;
    }
}
int main()
{
    unsigned long num = 0;
    cin >> num;
    map<nameCode,unsigned long> name_code;
    vector<string> name_list;
    string tmp_name;

    for (unsigned long i=0;i<num;++i){
//        cin >> name_list[i];
        cin >> tmp_name;
        name_list.push_back(tmp_name);
        tmp_name.clear();
    }

    for (unsigned long i=0;i<num;++i){        
        cout << solution(name_list[i],name_code) << endl;
    }
    return 0;
}

