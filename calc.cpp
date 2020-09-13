#include<bits/stdc++.h>
//#include<math.h>

using namespace std;

//Global Variable
string expr="";


bool isOperation(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/') 
        return true;
    else return false;
}
bool isSymbol(char c)
{
    if(isOperation(c))
        return true;
    else if(c=='(')
        return true;
    else return false;
}

bool anySymbol()
{
    int i=0;
    if(expr[0]=='-')
        i++;
    for(;i<expr.length();i++)
    {
        if(isSymbol(expr[i]))
        {
            return true;
        }
    }
    return false;
}

double make_num(int l,int r)
{
    bool neg=false;
    double num=0,k=0;
    int i=0;
    if(expr[l]=='-')
    {
        neg=true;
        l+=1;
    }
    for(i=l;i<=r && expr[i]!='.';i++)
    {
        num=num*10 + (expr[i]-'0');
    }
    if(expr[i]=='.')
    {
        for(i=i+1,k=0.1;i<=r;i++)
        {
            num=num + k*((double)(expr[i]-'0'));
            k=k/10;
        }
    }
    if(neg)
        num=-num;
    return num;
}


int isThere(char c,int* pos)
{
    for(int i=0;i<expr.length();i++)
    {
        if(expr[i]==c)
        {
            *pos=i;
            return true;
        }
    }
    *pos=0;
    return false;
}


void solve(int left=0,int right=expr.length())
{
    if(!anySymbol())
        return;
    int pos=0;

    //cout<<"in solve"<<endl;
    while(isThere('/',&pos))
    {
        double num1,num2;
        int l=0,r=0;
        for(r=pos+1;r<expr.length();r++)
        {
            if(expr[pos+1]=='-')
                continue;
            if(isSymbol(expr[r]))
                break;
        }
        num2=make_num(pos+1,r-1);
        for(l=pos-1;l>=0;l--)
        {
            if(expr[l]=='-')
            {
                l=l-1;
                break;
            }
            if(isSymbol(expr[l]))
                break;
        }
        num1=make_num(l+1,pos-1);

        //cout<<" num1= "<<num1<<" num2= "<<num2<<endl;
        if(num2<=0.0001 && num2>=-0.0001)
        {
            cout<<"Invalid Expression - Division by zero"<<endl;
            return;
        }
        if(l<0)
            l=0;
        expr = expr.substr(0,l) + to_string(num1/num2) + expr.substr(r,expr.length()-1);
    }
    while(isThere('*',&pos))
    {
        double num1,num2;
        int l=0,r=0;
        for(r=pos+1;r<expr.length();r++)
        {
            if(expr[pos+1]=='-')
                continue;
            if(isSymbol(expr[r]))
                break;
        }
        num2=make_num(pos+1,r-1);
        for(l=pos-1;l>=0;l--)
        {
            if(expr[l]=='-')
            {
                l=l-1;
                break;
            }
            if(isSymbol(expr[l]))
                break;
        }
        num1=make_num(l+1,pos-1);

        if(l<0)
            l=0;
        expr = expr.substr(0,l) + to_string(num1*num2) + expr.substr(r,expr.length()-1);
    }
    while(isThere('+',&pos))
    {
        //cout<<"in +"<<endl;
        double num1,num2;
        int l=0,r=0;
        for(r=pos+1;r<expr.length();r++)
        {
            if(expr[pos+1]=='-')
                continue;
            if(isSymbol(expr[r]))
                break;
        }
        num2=make_num(pos+1,r-1);
        for(l=pos-1;l>=0;l--)
        {
            if(expr[l]=='-')
            {
                l=l-1;
                break;
            }
            if(isSymbol(expr[l]))
                break;
        }
        num1=make_num(l+1,pos-1);
        if(l<0)
            l=0;
        //cout<<"in + found number   num1="<<num1<<" num2="<<num2<<endl;
        //cout<<" a  "<<expr.substr(0,0)<<" b  "<<to_string(num1+num2)<<" c "<<expr.substr(r,expr.length()-1)<<endl;
        expr = expr.substr(0,l) + to_string(num1+num2) + expr.substr(r,expr.length()-1);
        //cout<<"final expr = "<<expr<<endl;
    }
    for(int pos=0;pos<expr.length();pos++)
    if(expr[pos]=='-')
    {
        
        double num1,num2;
        int l=0,r=0;
        for(r=pos+1;r<expr.length();r++)
        {
            if(expr[pos+1]=='-')
                continue;
            if(isSymbol(expr[r]))
                break;
        }
        num2=make_num(pos+1,r-1);
        for(l=pos-1;l>=0;l--)
        {
            if(expr[l]=='-')
            {
                l=l-1;
                break;
            }
            if(isSymbol(expr[l]))
                break;
        }
        num1=make_num(l+1,pos-1);
        
        cout<<" num1= "<<num1<<"  num2= "<<num2<<endl;

        if(l<0)
            l=0;
        expr = expr.substr(0,l) + to_string(num1-num2) + expr.substr(r,expr.length()-1);
        
    }

    solve();
    return;
}


int main()
{
    //cout<<"Hello world";
    //string expr;
    cout<<"Enter a expression to calcuate : ";
    cin>>expr;
    //cout<<to_string(4+6)<<endl;

    

    //cout<<make_num(expr);
    solve();
    cout<<expr;

    return 0;
}