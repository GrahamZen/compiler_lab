#include "translator.h"

int main(int argc, char const *argv[])
{
    translator t;
    t.tblSt.push(t.t);
    t.offsetSt.push(0);
    auto t1=mktable(t.tblSt.top());
    t.tblSt.push(t1);
    t.offsetSt.push(0);
    
    auto temp=t.tblSt.top();
    temp->enter("a",INT,t.offsetSt.top());
    t.addwidth(44);
    
    temp->enter("x",INT,t.offsetSt.top());
    t.addwidth(4);
    
    auto t2=mktable(t.tblSt.top());
    t.tblSt.push(t2);
    t.offsetSt.push(0);
    
    temp=t.tblSt.top();
    temp->enter("i",INT,t.offsetSt.top());
    t.addwidth(4);
    
    temp=t.tblSt.top();
    temp->addwidth(t.offsetSt.top());
    t.tblSt.pop();
    t.offsetSt.pop();
    t.tblSt.top()->enterproc("readarray",temp);

    auto t3=mktable(t.tblSt.top());
    t.tblSt.push(t3);
    t.offsetSt.push(0);
    temp=t.tblSt.top();
    temp->addwidth(t.offsetSt.top());
    t.tblSt.pop();
    t.offsetSt.pop();
    t.tblSt.top()->enterproc("exchange",temp);

    auto t4=mktable(t.tblSt.top());
    t.tblSt.push(t4);
    t.offsetSt.push(0);

    temp=t.tblSt.top();
    temp->enter("k",INT,t.offsetSt.top());
    t.addwidth(4);
    temp=t.tblSt.top();
    temp->enter("v",INT,t.offsetSt.top());
    t.addwidth(4);

    auto t5=mktable(t.tblSt.top());
    t.tblSt.push(t5);
    t.offsetSt.push(0);
    temp=t.tblSt.top();
    temp->enter("i",INT,t.offsetSt.top());
    t.addwidth(4);
    temp=t.tblSt.top();
    temp->enter("j",INT,t.offsetSt.top());
    t.addwidth(4);

    temp=t.tblSt.top();
    temp->addwidth(t.offsetSt.top());
    t.tblSt.pop();
    t.offsetSt.pop();
    t.tblSt.top()->enterproc("partition",temp);

    temp=t.tblSt.top();
    temp->addwidth(t.offsetSt.top());
    t.tblSt.pop();
    t.offsetSt.pop();
    t.tblSt.top()->enterproc("quicksort",temp);

    temp=t.tblSt.top();
    temp->addwidth(t.offsetSt.top());
    t.tblSt.pop();
    t.offsetSt.pop();
    t.tblSt.top()->enterproc("sort",temp);
    
    temp=t.tblSt.top();
    temp->addwidth(t.offsetSt.top());
    t.tblSt.pop();
    t.offsetSt.pop();

    cout<<t.t;
    return 0;
}
