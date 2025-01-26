#include <iostream>
using namespace std;

class Node
{
    public:
    int row;
    int col;
    int data;
    Node *next;
};


void createSparseNode(Node **p, int row_index,
                     int col_index, int x)
{
    Node *temp = *p;
    Node *r;
     
    // create first Node and assign the passed values and put the address of next node is null
    if (temp == NULL)
    {
        temp = new Node();
        temp->row = row_index;
        temp->col = col_index;
        temp->data = x;
        temp->next = NULL;
        *p = temp;
    }
     
    // add the next node to the tail of the previous created node
    else
    {
        while (temp->next != NULL)   
            temp = temp->next;
             
        r = new Node();
        r->row = row_index;
        r->col = col_index;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}


int main()
{ 
     
    // Take input for no of rows and colums for the Array to be represented as Sparse Matrix
	int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout <<"Enter number of columns: ";
    cin >> cols;

    int inputArray[rows][cols];

    cout << "Enter the elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> inputArray[i][j];
        }
    }


// Print the array which is given input 

    cout << "The array is:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << " " << inputArray[i][j];
        }
        cout << "\n";
    }
     
    // Creating head/first node of list as NULL
    Node *initialNode = NULL;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
             
            // Pass only those values which 
            // are non - zero
            if (inputArray[i][j] != 0)
                createSparseNode(&initialNode, i, j, 
                                inputArray[i][j]);
        }
    }
    
    cout << "Implemented Sparse Matrix";
    cout << "\n";
    
    Node *ptr = initialNode;
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << "\n";

    ptr = initialNode;
    while (ptr != NULL)
    {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << "\n";
    ptr = initialNode;
     
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    
    return 0;
}