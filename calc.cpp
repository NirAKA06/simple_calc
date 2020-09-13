#include<bits/stdc++.h>
//#include<math.h>
using namespace std;



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

bool anySymbol(string expr)
{
     for(int i=0;i<expr.length();i++)
    {
        if(isSymbol(expr[i]))
        {
            return true;
        }
    }
    return false;
}

double make_num(string expr)
{
    double num=0,k=0;
    int i=0;
    for(i=0;i<expr.length() && expr[i]!='.';i++)
    {
        num=num*10 + (expr[i]-'0');
    }
    if(expr[i]=='.')
    for(i=i+1,k=0.1;i<expr.length();i++)
    {
        num=num + k*((double)(expr[i]-'0'));
        k=k/10;
    }

    return num;
}


int isThere(string expr,char c,int* pos)
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


string solve(string expr)
{
    if(!anySymbol(expr))
        return expr;
    int pos=0;

    
    while(isThere(expr,'/',&pos))
    {
        double num1,num2;
        int l=0,r=0;
        for(r=pos+1;r<expr.length();r++)
        {
            if(isSymbol(expr[r]))
                break;
        }
        num1=make_num(expr.substr(pos+1,r-1));
        for(l=pos-1;l>=0;l--)
        {
            if(isSymbol(expr[l]))
                break;
        }
        num2=make_num(expr.substr(l+1,pos-1));

        if(num2==0.0)
        {
            return "Invalid Expression - Division by zero";
        }
        expr = expr.substr(0,l) + to_string(num1/num2) + expr.substr(r,expr.length()-1);
    }
    while(isThere(expr,'*',&pos))
    {
        double num1,num2;
        int l=0,r=0;
        for(r=pos+1;r<expr.length();r++)
        {
            if(isSymbol(expr[r]))
                break;
        }
        num1=make_num(expr.substr(pos+1,r-1));
        for(l=pos-1;l>=0;l--)
        {
            if(isSymbol(expr[l]))
                break;
        }
        num2=make_num(expr.substr(l+1,pos-1));

        expr = expr.substr(0,l) + to_string(num1*num2) + expr.substr(r,expr.length()-1);
    }
    while(isThere(expr,'+',&pos))
    {
        double num1,num2;
        int l=0,r=0;
        for(r=pos+1;r<expr.length();r++)
        {
            if(isSymbol(expr[r]))
                break;
        }
        num1=make_num(expr.substr(pos+1,r-1));
        for(l=pos-1;l>=0;l--)
        {
            if(isSymbol(expr[l]))
                break;
        }
        num2=make_num(expr.substr(l+1,pos-1));

        expr = expr.substr(0,l) + to_string(num1+num2) + expr.substr(r,expr.length()-1);
    }
    while(isThere(expr,'-',&pos))
    {
        double num1,num2;
        int l=0,r=0;
        for(r=pos+1;r<expr.length();r++)
        {
            if(isSymbol(expr[r]))
                break;
        }
        num1=make_num(expr.substr(pos+1,r-1));
        for(l=pos-1;l>=0;l--)
        {
            if(isSymbol(expr[l]))
                break;
        }
        num2=make_num(expr.substr(l+1,pos-1));

        expr = expr.substr(0,l) + to_string(num1-num2) + expr.substr(r,expr.length()-1);
    }



    return expr;
}


int main()
{
    //cout<<"Hello world";
    string expr;
    cout<<"Enter a expression to calcuate : ";
    cin>>expr;
    //cout<<to_string(4+6)<<endl;


    //cout<<make_num(expr);
    cout<<solve(expr);

    return 0;
}