"""
Problem Statement : https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473
Time Complexity : O(N)
Space Complexity : O(N)
"""

def isredundantBrackets(expr):
    stack = []
    size = len(expr)
    operators = {'+', '*', '/', '-', '%'}

    # logic
    for char in expr:
        # anything other than closing brackets
        if char != ")":
            stack.append(char)

        else:
            # encountered with closing bracket
            operator = False

            # NOTE: stack_Queue[-1]--> top element
            while stack[-1] != "(":  # also add --> and isEmpty(stack_Queue) with existing one
                top = stack[-1]

                if top in operators:
                    operator = True

                stack.pop()

            # pop "(" and check the status
            stack.pop()

            if operator == False:
                return True

    return False


# NOTE: Assuming we have balanced Paranthesis in expression as well as expression is also
# correct like (a+b) not like aa+b.

if __name__== "__main__":
    expr1 = "((a+b))"
    expr2 = "((a+b)%(d))"
    expr3 = "(a-b)*(e)"
    expr4 = "((a-b)%d)"
    expr5 = "(((a+b)-c)%d) + a"
    expr6 = "(a+b) + c"
    expr7 = "(aa+b)" # return False

    print(isredundantBrackets(expr7))


"""
CPP Solution :

#include <stack>
bool isOperator(char op){
    if (op == '+' or op == '-' or op == '*' or op == '/')
        return true;
    
    return false; 
}

bool findRedundantBrackets(string &s){
    //code string 
    stack <char> st;
    
    for(char ch : s){
        
        //scan the operator 
        if (ch == '(' or isOperator(ch))
            st.push(ch);
        
        
        else{
            //now only letters or. ')' can be possible will ognore the letters 
            if(ch == ')'){
                
                //make initialy as true if it'll not go inside the if function that means we have redundant brackets
                bool isRedundant = true;
                if (isOperator(st.top())){
                    
                    isRedundant = false;
                    
                    while(st.top() != '(')
                        st.pop();
					
                    // now remove the '(' bracket
                    st.pop();        
                }
                if (isRedundant == true)
                    return true;
                //ignoring the letters
        	}
       }
    }
    //here are are aassuming that we have an valid expresssion but might have redundant brackets
    return false;
}
"""