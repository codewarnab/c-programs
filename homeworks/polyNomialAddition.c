    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    struct Node
    {
        int coeff;
        int pow;
        struct Node* next;
    };

    // Function to validate integer input
    bool validateIntInput(int* input)
    {
        int numScanned = scanf("%d", input);
        while (numScanned != 1)
        {
            // Clear input buffer
            while (getchar() != '\n');

            printf("Invalid input. Please enter an integer: ");
            numScanned = scanf("%d", input);
        }
        return true;
    }

    void readPolynomial(struct Node** poly)
    {
        int coeff, exp, cont;
        struct Node* temp = NULL;
        struct Node* tail = NULL;

        do {
            printf("Coefficient: ");
            if (!validateIntInput(&coeff))
                exit(EXIT_FAILURE);

            printf("Exponent: ");
            if (!validateIntInput(&exp))
                exit(EXIT_FAILURE);

            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            if (newNode == NULL) {
                printf("Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }

            newNode->coeff = coeff;
            newNode->pow = exp;
            newNode->next = NULL;

            if (*poly == NULL) {
                *poly = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            printf("Add more terms? (1 for yes, 0 for no): ");
            if (!validateIntInput(&cont))
                exit(EXIT_FAILURE);

        } while (cont);
    }

    void displayPolynomial(struct Node* poly)
    {
        if (poly == NULL) {
            printf("0");
            return;
        }

        while (poly != NULL)
        {
            printf("%dX^%d", poly->coeff, poly->pow);
            poly = poly->next;
            if (poly != NULL)
                printf(" + ");
        }
    }

    void addPolynomials(struct Node** result, struct Node* first, struct Node* second)
    {
        struct Node* temp = NULL;
        struct Node* tail = NULL;

        while (first != NULL || second != NULL)
        {
            int coeff = 0, pow = 0;
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            if (newNode == NULL) {
                printf("Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }

            if (first && (!second || first->pow > second->pow))
            {
                coeff = first->coeff;
                pow = first->pow;
                first = first->next;
            }
            else if (second && (!first || first->pow < second->pow))
            {
                coeff = second->coeff;
                pow = second->pow;
                second = second->next;
            }
            else
            {
                coeff = first->coeff + second->coeff;
                pow = first->pow;
                first = first->next;
                second = second->next;
            }

            newNode->coeff = coeff;
            newNode->pow = pow;
            newNode->next = NULL;

            if (*result == NULL) {
                *result = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    void freePolynomial(struct Node* poly)
    {
        while (poly != NULL)
        {
            struct Node* temp = poly;
            poly = poly->next;
            free(temp);
        }
    }

    int main()
    {
        struct Node* first = NULL;
        struct Node* second = NULL;
        struct Node* result = NULL;

        printf("\nEnter the corresponding data:-\n");
        printf("\nCreate first polynomial:\n");
        readPolynomial(&first);
        printf("First polynomial: ");
        displayPolynomial(first);
        printf("\n\nCreate second polynomial:\n");
        readPolynomial(&second);
        printf("Second polynomial: ");
        displayPolynomial(second);
        addPolynomials(&result, first, second);
        printf("\n\nAddition completed\n");
        printf("Final polynomial: ");
        displayPolynomial(result);
        printf("\n");

        // Free dynamically allocated memory
        freePolynomial(first);
        freePolynomial(second);
        freePolynomial(result);

        return 0;
    }
