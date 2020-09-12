#include<bits/stdc++.h>
//#include<math.h>

using namespace std;

bool isSymbol(char c)
{
    if(c=='+' || c=='-' || c=='*')
    {
        return true;
    }
    return false;
}

string solve(string expr)
{
    int num1=0,num2=0;
    for(int i=0;i<expr.length();i++)
    {
        num1=0;num2=0;
        if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*')
        {
            for(int j=i-1,k=0;j>=0;j--)
            {
                num1=num1 + pow(10,k++)*(expr[j]-'0');
            }
            for(int j=i+1;j<expr.length();j++)
            {
                num2=num2*10 + (expr[j]-'0');
            }
            switch(expr[i])
            {
                case '+':
                    //cout<<num1<<" + "<<num2<<" = ";
                    expr=to_string(num1+num2);
                    break;
                case '-':
                    expr=to_string(num1-num2);
                    break;
                case '*':
                    expr=to_string(num1*num2);
                    break;  
            }
            break;
            
        }
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
    cout<<solve(expr);

    return 0;
}