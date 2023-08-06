//
//  eval.cpp
//  32homework2
//
//  Created by Ayan Nath on 2/4/23.
//
#include "Set.h"
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <cctype>
#include <cassert>
using namespace std;

bool precedence (char ch, char top);

int evaluate(string infix, const Set& trueValues, const Set& falseValues, string& postfix, bool& result)
{
    string noSpaces = "";
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix.at(i)!=' ')
            noSpaces=noSpaces+infix.at(i);
    }
    infix = noSpaces;

    if (infix == "")
        return 1;

    if (infix.length() > 0)
    {
        if (infix[0] == '&' || infix[0] == '|' || infix[0] == ')')
            return 1;
        if (!(islower(infix[infix.length() - 1]) || infix[infix.length() - 1] == ')'))
            return 1;
    }

    if (infix.length() == 2)
    {
        if (!(infix[0] == '!' && islower(infix[1])))
            return 1;
    }

    if (infix.length() > 2)
    {
        for (int i = 1; i < infix.length(); i++)
        {
            if (islower(infix[i]))
            {
                if (islower(infix[i-1]) || infix[i-1] == ')' )
                    return 1;
            }

            else if (infix[i] == '|' || infix[i] == '&')
            {
                if (!(islower(infix[i - 1]) || infix[i - 1] == ')'))
                    return 1;
            }

            else if (infix[i]=='!')
            {
                if (infix[i-1]== ')' || islower(infix[i-1]))
                    return 1;
            }

            else if (infix[i]=='(')
            {
                if (islower(infix[i-1]) || infix[i-1] == ')')
                    return 1;
            }

            else if (infix[i]==')')
            {
                if (!(infix[i-1] == ')' || islower(infix[i-1])))
                    return 1;
            }
        }
    }

    //makes sure number of open parenthesis and closed parenthesis are the same
    int closedParens = 0, openParens = 0;

        for (int i = 0; i < infix.length(); i++) {
            if (infix[i] == '(')
                openParens++;
            else if (infix[i] == ')')
                closedParens++;
        }

        if (openParens != closedParens)
            return 1;


    postfix = "";
    stack <char> operatorStack;

    for (int i = 0; i <infix.length(); i++)
    {
        char cur = infix.at(i);
        //cout << cur <<endl;
        if (islower(cur))
        {
            postfix = postfix + cur;
        }

        else if (cur == '(')
        {
            operatorStack.push(cur);
        }

        else if ( cur == ')')
        {
            while (operatorStack.top()!='(')
            {
                postfix = postfix + operatorStack.top();
                operatorStack.pop();
            }

            operatorStack.pop();
        }

        else if (cur == '&' || cur == '|' || cur == '!')
        {
            while (!operatorStack.empty() && operatorStack.top()!='(' && precedence(cur, operatorStack.top()))
            {
                postfix = postfix + operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(cur);
        }

        else if (cur == ' ')
            continue;

        //return if infix to postfix conversion step does not work
        else return 1;
    }


    while (!operatorStack.empty())
    {
        postfix = postfix + operatorStack.top();
        operatorStack.pop();
    }


    bool caseOne = false; // at least one letter in the expression is in neither the
    //            trueValues nor the falseValues sets; and
    bool caseTwo = false; // at least one letter in the expression is in both the
    //            trueValues and the falseValues set.
    for (int i = 0; i < postfix.length(); i++)
    {
        char cur = postfix.at(i);
        if (islower(cur))
        {
            if (trueValues.contains(cur) && falseValues.contains(cur))
                caseTwo = true;

            if (!(trueValues.contains(cur) || falseValues.contains(cur)))
            {
                caseOne = true;
            }
        }
    }

    if (caseOne)
        return 2;

    if (caseTwo)
        return 3;


    stack<bool> operandStack;
    for (int i = 0; i < postfix.length(); i ++)
    {
        char cur = postfix.at(i);


        if (islower(cur))
        {
            if (trueValues.contains(cur))
                operandStack.push(true);
            else if (falseValues.contains(cur))
                operandStack.push(false);
        }

        else
        {
            if (cur == '!')
            {
                bool operand = operandStack.top();
                operandStack.pop();
                operandStack.push(!operand);
            }

            else
            {
                bool operand2 = operandStack.top();
                operandStack.pop();
                bool operand1 = operandStack.top();
                operandStack.pop();

                if (cur == '&')
                {
                    operandStack.push(operand1 && operand2);
                }

                else operandStack.push(operand1 || operand2);
            }
        }
    }


    result = operandStack.top();
    return 0;
}

bool precedence(char ch, char stackTop)
{
    map<char, int> val;
    val['!'] = 2;
    val['&'] = 1;
    val['|'] = 0;
    if (ch == '!')
        return (val[ch] < val[stackTop]);
    return (val[ch] <= val[stackTop]);
}

int main()
        {
            string trueChars  = "tywz";
            string falseChars = "fnx";
            Set trues;
            Set falses;
            for (int k = 0; k < trueChars.size(); k++)
                trues.insert(trueChars[k]);
            for (int k = 0; k < falseChars.size(); k++)
                falses.insert(falseChars[k]);

            string pf;
            bool answer;
            assert(evaluate("w| f", trues, falses, pf, answer) == 0  &&  pf == "wf|" &&  answer);
            assert(evaluate("y|", trues, falses, pf, answer) == 1);
            assert(evaluate("n t", trues, falses, pf, answer) == 1);
            assert(evaluate("nt", trues, falses, pf, answer) == 1);
            assert(evaluate("()", trues, falses, pf, answer) == 1);
            assert(evaluate("()z", trues, falses, pf, answer) == 1);
            assert(evaluate("y(n|y)", trues, falses, pf, answer) == 1);
            assert(evaluate("t(&n)", trues, falses, pf, answer) == 1);
            assert(evaluate("(n&(t|y)", trues, falses, pf, answer) == 1);
            assert(evaluate("n+y", trues, falses, pf, answer) == 1);
            assert(evaluate("", trues, falses, pf, answer) == 1);
            assert(evaluate("f  |  !f & (t&n) ", trues, falses, pf, answer) == 0
                                   &&  pf == "ff!tn&&|"  &&  !answer);
            assert(evaluate(" x  ", trues, falses, pf, answer) == 0  &&  pf == "x"  &&  !answer);
            trues.insert('x');
            assert(evaluate("((x))", trues, falses, pf, answer) == 3);
            falses.erase('x');
            assert(evaluate("((x))", trues, falses, pf, answer) == 0  &&  pf == "x"  &&  answer);
            trues.erase('w');
            assert(evaluate("w| f", trues, falses, pf, answer) == 2);
            falses.insert('w');
            assert(evaluate("w| f", trues, falses, pf, answer) == 0  &&  pf == "wf|" &&  !answer);
            cout << "Passed all tests" << endl;
        }
