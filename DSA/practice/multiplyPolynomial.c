#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};

struct Node *createNode(int coeff, int pow)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;

    return newNode;
}

void appendTerm(struct Node **poly, int coeff, int pow)
{
    struct Node *newNode = createNode(coeff, pow);
    if (*poly == NULL)
    {
        *poly = newNode;
    }
    else
    {
        struct Node *temp = *poly;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayPoly(struct Node *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coeff, poly->pow);
        if (poly->next != NULL)
        {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}

struct Node *multiplyPoly(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    struct Node *ptr1 = poly1;
    struct Node *ptr2;

    while (ptr1 != NULL)
    {
        // Reset ptr2 to the start of poly2 for each term of poly1 to multiply all terms.
        ptr2 = poly2;
        while (ptr2 != NULL)
        {
            int coeff = ptr1->coeff * ptr2->coeff;
            int pow = ptr1->pow + ptr2->pow;
            appendTerm(&result, coeff, pow);
            ptr2 = ptr2->next;
        }
    }

    // combine terms with same power
    // Traverse the result linked list to combine terms with the same power.
    struct Node *ptr = result;
    while (ptr != NULL)
    {
        struct Node *temp = ptr->next; // Pointer to compare terms following the current term.
        struct Node *prev = ptr;       // Tracks the previous node for linking after merging.
        while (temp != NULL)
        {
            if (ptr->pow == temp->pow) // Check if powers are the same.
            {
                ptr->coeff += temp->coeff; // Combine coefficients for like terms.
                prev->next = temp->next;   // Remove the current duplicate node.
                free(temp);                // Free memory of the duplicate node.
                temp = prev->next;         // Move to the next node.
            }
            else
            {
                prev = temp;       // Move prev to the current temp node.
                temp = temp->next; // Move temp to the next node.
            }
        }
        ptr = ptr->next; // Move to the next term in the result list.
    }

        return result; 
}

int main(){
    struct Node * poly1 = NULL ;
    struct Node *poly2 = NULL; 
    struct Node * result = NULL ; 

    // creating first polynomial :3x^2 + 5x + 6 
     appendTerm(&poly1, 3, 2);
    appendTerm(&poly1, 5, 1);
    appendTerm(&poly1, 6, 0);

    // Creating second polynomial: 6x^1 + 1
    appendTerm(&poly2, 6, 1);
    appendTerm(&poly2, 1, 0);

    // Display the polynomials
    printf("First Polynomial: ");
    displayPoly(poly1);
    printf("Second Polynomial: ");
    displayPoly(poly2);

    // Multiply the polynomials
    result = multiplyPoly(poly1, poly2);

    // Display the result
    printf("Resultant Polynomial: ");
    displayPoly(result);

    return 0;
}
