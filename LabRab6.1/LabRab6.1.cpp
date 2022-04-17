#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    setlocale(0, "rus");
    bool flag = true;
    char str[] = "2*(3-4)+[{3-1} + (4-2)]";
    stack <char> st;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            st.push(str[i]);
        }
        else
        {
            if (str[i] == ')' || str[i] == ']' || str[i] == '}')
            {
                if ((str[i] == ')' && st.top() == '(') || (str[i] == ']' && st.top() == '[') || (str[i] == '}' && st.top() == '{'))
                {
                    st.pop();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
    }
    if (flag == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

}