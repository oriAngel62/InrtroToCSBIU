//
// Created by ori on 28/12/2020.
//
/***********
* Ori Angel
* 314617739
* 01
* ass06
***********/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "queue.h"
#include "Utils.h"


void options(Trin_Ari *root);

void treePrintMenu(Trin_Ari *root);

/******************
* Function Name: destroyBinTree
* Input: root of the tree and if we found vaccine (1 yes, 0 no)
* Output: -
* Function Operation: delete the members who survive
******************/
void destroyBinTree(Trin_Ari *root, int vaccine) {
    if (root == NULL) {
        return;
    }
    destroyBinTree(root->left, vaccine);
    root->left = NULL;
    destroyBinTree(root->middle, vaccine);
    root->middle = NULL;
    destroyBinTree(root->right, vaccine);
    root->right = NULL;
    if (vaccine) {
        printf("%s ID: %d Survived!\n", root->name, root->id);
    }
    free(root->name);
    free(root);
    root = NULL;
}

/******************
* Function Name: endProgram
* Input: root of the tree and if there is a leak memory problem
* Output: exit the program and return 1
* Function Operation: end the program
******************/
void endProgram(Trin_Ari *root, int isMalloc) {
    if (!isMalloc) {
        printf("Malloc Failed!\n");
    }
    destroyBinTree(root, isMalloc);
    exit(1);
}

/******************
* Function Name: printTheMenu
* Input: -
* Output: print the menu
* Function Operation: print the menu of options
******************/
void printTheMenu(Trin_Ari *root) {
    printf("Please select an operation:\n"
           "\t0. Exit.\n"
           "\t1. Create family.\n"
           "\t2. Add family member.\n"
           "\t3. Print Family-Tree.\n"
           "\t4. Bidud.\n"
           "\t5. Superspreader.\n"
           "\t6. Vaccine.\n"
           "\t7. Print the menu.\n");
    options(root);
}

/******************
* Function Name: newRoot
* Input: root name and id, all the information for create new leaf
* Output: new root
* Function Operation: create new root
******************/
Trin_Ari *newRoot(Trin_Ari *root, char *name, int id) {
    //empty family tree
    if (root == NULL) {
        root = (Trin_Ari *) calloc(1, sizeof(Trin_Ari));
        if (root == NULL) {
            endProgram(root, 0);
        }
        root->name = name;
        root->id = id;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    Trin_Ari *new = (Trin_Ari *) calloc(1, sizeof(Trin_Ari));
    if (new == NULL) {
        endProgram(root, 0);
    }
    new->name = name;
    new->id = id;
    new->left = NULL;
    new->right = NULL;
    return new;
}

/******************
* Function Name: isEmpty
* Input: root for check
* Output: 1 if empty 0 else
* Function Operation: check isEmpty
******************/
static int isEmpty(Trin_Ari *root) {
    if (root == NULL) {
        return 1;
    }
    return 0;
}

/******************
* Function Name: idBelongToSomeone
* Input: root and id
* Output: return the root that the id is belong to
* Function Operation: find who belongs the id
******************/
Trin_Ari *idBelongToSomeone(Trin_Ari *root, int val) {
    if (isEmpty(root)) {
        return NULL;
    }
    if (root->id == val) {
        return root;
    }
    if (idBelongToSomeone(root->left, val) != NULL) {
        return idBelongToSomeone(root->left, val);
    }
    if (idBelongToSomeone(root->middle, val) != NULL) {
        return idBelongToSomeone(root->middle, val);
    }
    if (idBelongToSomeone(root->right, val) != NULL) {
        return idBelongToSomeone(root->right, val);
    }
}

/******************
* Function Name: idCloseFather
* Input: root and id
* Output: return father root
* Function Operation: find the father of the specific id member and return him
******************/
Trin_Ari *idCloseFather(Trin_Ari *root, int val) {
    if (isEmpty(root)) {
        return NULL;
    }
    if (root->left != NULL) {
        if (root->left->id == val) {
            return root;
        }
    }
    if (root->middle != NULL) {
        if (root->middle->id == val) {
            return root;
        }
    }
    if (root->right != NULL) {
        if (root->right->id == val) {
            return root;
        }
    }
    if (idCloseFather(root->left, val) != NULL) {
        return idCloseFather(root->left, val);
    }
    if (idCloseFather(root->middle, val) != NULL) {
        return idCloseFather(root->middle, val);
    }
    if (idCloseFather(root->right, val) != NULL) {
        return idCloseFather(root->right, val);
    }
}

/******************
* Function Name: moreThan3Members
* Input: root
* Output: return true if there is more than 3 members else return false
* Function Operation: find if i can add more sons
******************/
int moreThan3Members(Trin_Ari *root) {
    if (isEmpty(root)) {
        return false;
    }
    if (root->left != NULL && root->middle != NULL && root->right != NULL) {
        return true;
    }
    return false;

}

/******************
* Function Name: enterNewRoot
* Input: root
* Output: return the new root
* Function Operation: check if all the details of the root are correct and return the root
******************/
Trin_Ari *enterNewRoot(Trin_Ari *root) {
    char *nameNewRoot = (char *) calloc((MAX_NAME_LENGTH), sizeof(char));
    if (nameNewRoot == NULL) {
        free(nameNewRoot);
        endProgram(root, 0);
    }
    Bool belong = false;
    int id;
    while (!belong) {
        printf("enter name\n");
        scanf(" %[^\n]", nameNewRoot);
        printf("enter ID\n");
        scanf(" %d", &id);
        if (idBelongToSomeone(root, id) != NULL) {
            printf("ID %d belongs to %s\n", id, idBelongToSomeone(root, id)->name);
        } else {
            belong = true;
        }
    }
    printf("Hello %s, ID: %d\n", nameNewRoot, id);
    if (root == NULL) {
        root = newRoot(root, nameNewRoot, id);
        return root;
    } else {
        Trin_Ari *new = newRoot(root, nameNewRoot, id);
        return new;
    }
}

/******************
* Function Name: mainBuildFamily
* Input: root
* Output: return the first root
* Function Operation: build new family tree by creating the new member
******************/
Trin_Ari *mainBuildFamily(Trin_Ari *root) {
    if (root != NULL) {
        printf("The family has already been created\n");
    } else {
        root = enterNewRoot(root);
    }
    return root;
}

/******************
* Function Name: isIdInTree
* Input: root and id
* Output: return id in the tree
* Function Operation: check if id in the tree
******************/
int isIdInTree(Trin_Ari *root, int val) {
    if (isEmpty(root)) {
        return false;
    }
    if (root->id == val) {
        return true;
    }
    if (isIdInTree(root->left, val)) {
        return true;
    }
    if (isIdInTree(root->middle, val)) {
        return true;
    }
    if (isIdInTree(root->right, val)) {
        return true;
    }
}

/******************
* Function Name: insertMemberToTree
* Input: root father and son
* Output: -
* Function Operation: insert the son to the father
******************/
void insertMemberToTree(Trin_Ari *father, Trin_Ari *son) {
    if (isEmpty(father)) {
        return;
    }
    if (father->left == NULL) {
        father->left = son;
        return;
    }
    if (father->middle == NULL) {
        father->middle = son;
        return;
    }
    if (father->right == NULL) {
        father->right = son;
        return;
    }
}

/******************
* Function Name: scanId
* Input: root and superSpreader
* Output: return id after check, return -1 if the san fail
* Function Operation: check id
******************/
int scanId(Trin_Ari *root, int superSpreader) {
    int id;
    scanf(" %d", &id);
    Trin_Ari *father = idBelongToSomeone(root, id);
    if (father == NULL) {
        if (superSpreader) {
            printf("ID %d does not exist\n", id);
        } else {
            printf("There is no ID %d\n", id);
        }
        return -1;
    }
    return id;
}

/******************
* Function Name: addRoot
* Input: root
* Output: -
* Function Operation: add new root to the family
******************/
void addRoot(Trin_Ari *root) {
    if (isEmpty(root)) {
        printf("Please create the family first\n");
        return;
    }
    printf("Enter the ID of the person who wants to make an appointment?\n");
    int id = scanId(root, 0);
    if (id == -1) {
        return;
    }
    Trin_Ari *father = idBelongToSomeone(root, id);
    if (moreThan3Members(father)) {
        printf("%s ID: %d can't meet more than 3 members!\n", father->name, id);
        return;
    }
    //insert the member
    insertMemberToTree(father, enterNewRoot(root));
}

/******************
* Function Name: printRoot
* Input: root
* Output: -
* Function Operation: print root
******************/
void printRoot(Trin_Ari *root) {
    printf("%s ID: %d\n", root->name, root->id);
}

/******************
* Function Name: printBFSRoot
* Input: root and check if root need stayHome (1 yes 0 no)
* Output: -
* Function Operation:print the BFS with message who need to stay home
******************/
void printBFSRoot(Trin_Ari *root, int stayHome) {
    if (!stayHome) {
        printf("%s %d\n", root->name, root->id);
    } else {
        printf("#StayHome! %s %d\n", root->name, root->id);
    }
}

/******************
* Function Name: printPreOrder
* Input: root
* Output: -
* Function Operation:print PreOrder tree
******************/
void printPreOrder(Trin_Ari *root) {
    if (isEmpty(root)) {
        return;
    }
    printRoot(root);
    printPreOrder(root->left);
    printPreOrder(root->middle);
    printPreOrder(root->right);
}

/******************
* Function Name: countLeaves
* Input: root
* Output: return how many leaves in the tree
* Function Operation: return how many leaves in the tree
******************/
int countLeaves(Trin_Ari *root) {
    if (isEmpty(root)) {
        return 0;
    }
    if (root->left == NULL && root->middle == NULL && root->right == NULL) {
        return 1;
    } else {
        return 1 + countLeaves(root->left) + countLeaves(root->middle) + countLeaves(root->right);
    }
}

/******************
* Function Name: printLeftOrder
* Input: root
* Output: -
* Function Operation: print Left order tree
******************/
void printLeftOrder(Trin_Ari *root) {
    if (isEmpty(root)) {
        return;
    }
    printLeftOrder(root->left);
    printRoot(root);
    printLeftOrder(root->middle);
    printLeftOrder(root->right);
}

/******************
* Function Name: createQueue
* Input: root
* Output: Queue
* Function Operation: create new queue
******************/
Queue *createQueue(Trin_Ari *root) {
    int size = countLeaves(root);
    Queue *q = malloc(size * sizeof(struct Queue));
    if (q == NULL) {
        endProgram(root, 0);
    }
    q->key = (void *) calloc(size, sizeof(Trin_Ari));
    if (q->key == NULL) {
        free(q);
        endProgram(root, 0);
    }
    q->front = -1;
    q->rear = -1;
    return q;
}

/******************
* Function Name: enQueue
* Input: queue and root
* Output: -
* Function Operation: insert the root to the queue
******************/
void enQueue(Queue *q, void *root) {
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    // Adding elements into queue
    q->key[q->rear] = root;
}

/******************
* Function Name: deQueue
* Input: queue
* Output: -
* Function Operation: remove root from queue by add the index of the front
******************/
void deQueue(Queue *q) {
    Trin_Ari *item;
    if (isQueueEmpty(q)) {
        printf("Queue is empty");
    } else {
        // Removing elements from queue
        q->front++;
    }
}

/******************
* Function Name: printFirstQueue
* Input: queue and if stayHome (1 yes 0 no)
* Output: -
* Function Operation: print the head of the queue
******************/
void printFirstQueue(Queue *q, int stayHome) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty");
    } else {
        if (q->front <= q->rear) {
            Trin_Ari *print = q->key[q->front];
            char *name = print->name;
            int id = print->id;
            if (!stayHome) {
                printf("%s %d\n", name, id);
            } else {
                printf("#StayHome! %s %d\n", name, id);
            }
        }
    }
}

/******************
* Function Name: isQueueEmpty
* Input: queue
* Output: return 1 if the queue is empty else return 0
* Function Operation: check if the queue is empty
******************/
int isQueueEmpty(Queue *q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

/******************
* Function Name: BFS
* Input: root and stayHome
* Output: -
* Function Operation: print BFS of the tree
******************/
void BFS(Trin_Ari *root, int stayHome) {
    if (root == NULL) {
        return;
    }
    printBFSRoot(root, stayHome);
    Queue *queue = createQueue(root);
    if (root->left != NULL) {
        enQueue(queue, root->left);
    }
    if (root->middle != NULL) {
        enQueue(queue, root->middle);
    }
    if (root->right != NULL) {
        enQueue(queue, root->right);
    }
    while (!isQueueEmpty(queue) && queue->front < queue->rear + 1) {
        printFirstQueue(queue, stayHome);
        root = queue->key[queue->front];
        if (root != NULL) {
            deQueue(queue);
            if (root->left != NULL) {
                enQueue(queue, root->left);
            }
            if (root->middle != NULL) {
                enQueue(queue, root->middle);
            }
            if (root->right != NULL) {
                enQueue(queue, root->right);
            }
        }
    }
    free(queue->key);
    free(queue);
}

/******************
* Function Name: bidud
* Input: root
* Output: -
* Function Operation: put the root his sons and the father in bidud
******************/
void bidud(Trin_Ari *root) {
    if (isEmpty(root)) {
        printf("Please create the family first\n");
        return;
    }
    printf("Enter the ID of the suspected member\n");
    int id = scanId(root, 1);
    if (id == -1) {
        return;
    }
    Trin_Ari *leaf = idCloseFather(root, id);
    //search for father
    if (leaf != NULL) {
        printf("#StayHome! %s %d\n", leaf->name, leaf->id);
    }
    leaf = idBelongToSomeone(root, id);
    if (leaf != NULL) {
        printf("#StayHome! %s %d\n", leaf->name, leaf->id);
    }
    if (leaf->left != NULL) {
        printf("#StayHome! %s %d\n", leaf->left->name, leaf->left->id);
    }
    if (leaf->middle != NULL) {
        printf("#StayHome! %s %d\n", leaf->middle->name, leaf->middle->id);
    }
    if (leaf->right != NULL) {
        printf("#StayHome! %s %d\n", leaf->right->name, leaf->right->id);
    }
}

/******************
* Function Name: superSpreader
* Input: root
* Output: -
* Function Operation: print meesage to stay home to all of the leaves that relate to the spreader
******************/
void superSpreader(Trin_Ari *root) {
    if (isEmpty(root)) {
        printf("Please create the family first\n");
        return;
    }
    printf("Enter the ID of the suspected Superspreader\n");
    int id = scanId(root, 1);
    if (id == -1) {
        return;
    }
    Trin_Ari *leaf = idCloseFather(root, id);
    //search for father
    if (leaf != NULL) {
        printf("#StayHome! %s %d\n", leaf->name, leaf->id);
    }
    leaf = idBelongToSomeone(root, id);
    if (leaf != NULL) {
        BFS(leaf, 1);
    }
}

/******************
* Function Name: whoIsYourSon
* Input: father and son
* Output: 1 left 2 middle 3 right
* Function Operation: return who is your specific son right left or middle
******************/
int whoIsYourSon(Trin_Ari *father, Trin_Ari *son) {
    if (father != NULL) {
        if (father->left != NULL) {
            if (father->left == son) {
                return 1;
            }
        }
        if (father->middle != NULL) {
            if (father->middle == son) {
                return 2;
            }
        }
        if (father->right != NULL) {
            if (father->right == son) {
                return 3;
            }
        }
    }
    return -1;
}

/******************
* Function Name: freeSon
* Input: father and son num
* Output: -
* Function Operation: free the son to NULL
******************/
void freeSon(Trin_Ari *father, int sonNum) {
    if (sonNum == 1) {
        father->left = NULL;
    }
    if (sonNum == 2) {
        father->middle = NULL;
    }
    if (sonNum == 3) {
        father->right = NULL;
    }
}

/******************
* Function Name: vaccine
* Input: root
* Output: -
* Function Operation: delete form tree all the members that vaccine
******************/
Trin_Ari *vaccine(Trin_Ari *root) {
    if (isEmpty(root)) {
        printf("Please create the family first\n");
        return root;
    }
    printf("Who got vaccinated (ID)?\n");
    int id = scanId(root, 0);
    if (id == -1) {
        return root;
    }
    Trin_Ari *father = idCloseFather(root, id);
    Trin_Ari *leaf = idBelongToSomeone(root, id);
    int sonNum = whoIsYourSon(father, leaf);
    if (leaf != NULL) {
        destroyBinTree(leaf, 1);
    }
    freeSon(father, sonNum);
    //head of the family was gone
    if (father == NULL) {
        root = NULL;
    }
    return root;
}

/******************
* Function Name: printOptions
* Input: root
* Output: error if there input not valid
* Function Operation: call the functions of the menu
******************/
void printOptions(Trin_Ari *root) {
    char printOptions;
    scanf(" %c", &printOptions);
    switch (printOptions) {
        case '0':
            printTheMenu(root);
            break;
        case '1':
            print2DUtil(root, SPACE);
            break;
        case '2':
            printPreOrder(root);
            break;
        case '3':
            printLeftOrder(root);
            break;
        case '4':
            BFS(root, 0);
            break;
        default: {
            printf("Error: unrecognized operation.\n");
            treePrintMenu(root);
            return;
        }
    }
    printTheMenu(root);
}

/******************
* Function Name: treePrintMenu
* Input: root
* Output: -
* Function Operation:print menu
******************/
void treePrintMenu(Trin_Ari *root) {
    printf("Please select an operation:\n"
           "\t0. Return to the main menu.\n"
           "\t1. Print Trin-Ari family.\n"
           "\t2. Print Pre-order.\n"
           "\t3. Print Left-order.\n"
           "\t4. Print BFS.\n");
    printOptions(root);
}

/******************
* Function Name: options
* Input: -
* Output: print Select the next operation (insert 7 for the entire menu):
* Function Operation: manage the options menu (scan char 0 to 7) and call to the correct functions
******************/
void options(Trin_Ari *root) {
    char option;

    scanf(" %c", &option);
    switch (option) {
        case '0':
            endProgram(root, 1);
            break;
        case '1':
            root = mainBuildFamily(root);
            break;
        case '2':
            addRoot(root);
            break;
        case '3':
            treePrintMenu(root);
        case '4':
            bidud(root);
            break;
        case '5':
            superSpreader(root);
            break;
        case '6':
            root = vaccine(root);
            break;
        case '7':
            printTheMenu(root);
            break;
        default: {
            printf("Error: unrecognized operation.\n");
        }
    }
    printf("Select the next operation (insert 7 for the entire menu):\n");
    options(root);
}