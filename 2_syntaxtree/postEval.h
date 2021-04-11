#include <stack>
#include <string>
#include <map>
#include <cctype>
#include <exception>
#include <iostream>
using namespace std;
const string operStr="+-*/()#";
char opOrder[][8] = {">><<><>", ">><<><>", ">>>>><>", ">>>>><>", "<<<<=<=","<<<<=<=", "======="}; 

map<char,int> op2id={{'+',0},{'-',1},{'*',2},{'/',3},{'#',4},{'(',5},{')',6}};

string splitNum(string s,int &i,char pre){
    string intStr;
    for (i=0; i < s.size(); i++)
    {
        if(operStr.find(s[i])==string::npos)
            intStr.push_back(s[i]);
        else if(i==0&&s[0]=='-'&&operStr.find(s[1])==string::npos&&operStr.find(pre)!=string::npos){
            intStr.push_back('-');
        }else
            break;
    }
    if(intStr.size()>0){
        return intStr;
    }
    else return "";
}
char lt(char lhs,char rhs){
    try
    {
        return opOrder[op2id[lhs]][op2id[rhs]];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
}

string convert(string &s){
    s+="#";
    string res;
    stack<string>numStack;
    stack<char>opStack;
    int strSize=s.size();
    int index=0;
    string tmpInt;
    int subIndex;
    char op=0;
    while(index<strSize){
        subIndex=0;
        if(isspace(s[index])){
            index++;
            continue;
        }
        else if ((tmpInt=splitNum(s.substr(index),subIndex,op))!=""){
            numStack.push(tmpInt);
            op=tmpInt[0];
            index+=subIndex;
        }
        else if(!opStack.empty()){
            op=s[index];
            char cmpRes=lt(opStack.top(),op);
            if(cmpRes=='<'){
                opStack.push(op);
            }
            else if(cmpRes=='='){
                opStack.pop();
            }
            else{
                do
                {
                    string lhs=numStack.top();
                    numStack.pop();
                    string rhs=numStack.top();
                    numStack.pop();
                    res=rhs+' '+lhs+' '+opStack.top();
                    opStack.pop();
                    numStack.push(res);
                } while (!opStack.empty()&&lt(opStack.top(),op)=='>');
                if(!opStack.empty()&&opStack.top()=='('&&op==')')opStack.pop();
                if(op!=')')
                    opStack.push(op);
            }
            index++;
        }
        else if(operStr.find(s[index])!=string::npos){
            op=s[index];
            opStack.push(s[index]);
            index++;
        }
        else
            throw invalid_argument("bad input!");
    }

    return numStack.top();
}
