#include "postEval.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void replace_all_distinct(string &str, const string &old_val, const string &new_val)
{
    for (size_t pos = 0; pos != string::npos; pos += new_val.length())
    {
        if ((pos = str.find(old_val, pos)) != string::npos)
            str.replace(pos, old_val.length(), new_val);
        else
            break;
    }
}

class ExprTree
{
private:
    struct TreeNode
    {
        string oper;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
    };

    TreeNode *root = nullptr;
    bool isOper(string term)
    {
        return term.size() == 1 && operStr.find(term[0]) != string::npos;
    }
    vector<string> expr2Vec(string expr)
    {
        auto posExpr = convert(expr);
        vector<string> ret;
        int start = 0, end = 0;
        auto e_size = posExpr.size();
        for (int i = 0; i < e_size; i++)
        {
            if (!isspace(posExpr[i]))
                end++;
            else
            {
                ret.push_back(posExpr.substr(start, end - start));
                end = start = end + 1;
            }
        }
        ret.push_back(posExpr.substr(start, e_size - start));
        return ret;
    }
    int max_level(TreeNode *node)
    {
        if (!node)
            return 0;
        return std::max(max_level(node->left), max_level(node->right)) + 1;
    }

public:
    int height;
    ExprTree(string expr)
    {
        auto vec = expr2Vec(expr);
        stack<TreeNode *> st;
        for (int i = 0; i < vec.size(); i++)
        {
            if (!isOper(vec[i]))
            {
                st.push(new TreeNode{vec[i]});
            }
            else
            {
                auto rhs = st.top();
                st.pop();
                auto lhs = st.top();
                st.pop();
                st.push(new TreeNode{vec[i], lhs, rhs});
            }
        }
        root = st.top();
        height = max_level(root);
    }
    friend ostream &operator<<(ostream &os, ExprTree exprTree);
    void traverse(TreeNode *node, vector<string> &treeVec, int level = 0)
    {
        if (!node)
            return;
        treeVec[level] += node->oper;
        traverse(node->left, treeVec, level + 1);
        for (int i = 0; i < height; i++)
            treeVec[i] += '\t';
        traverse(node->right, treeVec, level + 1);
    }
    vector<string> to_vector()
    {
        vector<string> treeVec(height);
        traverse(root, treeVec);
        return treeVec;
    }
    ~ExprTree() = default;
};
ostream &operator<<(ostream &os, ExprTree exprTree)
{
    auto vec = exprTree.to_vector();
    string::size_type pos(0);
    for (auto &line : vec)
    {
        replace_all_distinct(line, "\t\t", "\t");
        os << line << endl;
    }
    return os;
}

int main(int argc, const char **argv)
{
    string s;
    getline(cin, s);
    auto t = ExprTree(s);
    cout << t;
    return 0;
}