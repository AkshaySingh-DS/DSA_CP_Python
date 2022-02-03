/* Problem Statement : https://www.codingninjas.com/codestudio/problems/is-it-a-circular-linked-list_981265?leftPanelTab=0
Time complexity : O(N)
Space Complexity: O(1) iterative and O(N) recursion */



/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

//iterative approach
bool circularLL(Node* head)
{
    // Write your code here
    Node *temp = head -> next;
    
    while (temp != NULL and temp != head)
        temp = temp -> next;
    
    if (temp == head)
        return true;
    
    return false;
    
}

//recusive solution
bool solvecircular(Node *head, Node* temp){

    //base case
    if (temp == head)
        return true;
    
    if (temp == NULL)
        return false;
    
    //recursive case
    return solvecircular(head, temp -> next);
    
}

bool circularLL(Node* head)
{
    // Write your code here
    return solvecircular(head, head -> next);
    
}

