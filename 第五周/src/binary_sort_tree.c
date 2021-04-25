//
// Created by ABCPAN on 2021/4/24.
//
#include <stdlib.h>
#include "binary_sort_tree.h"
#include <stdio.h>
#include "LinkStack.h"
#include "LQueue.h"

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr P) {
    if (P == NULL) {
        printf("创造失败\n");
        return failed;
    }
    P->root = (NodePtr) malloc(sizeof(Node));
    P->root->right = P->root->left = NULL;
    P->root->value = EOF;
    return succeed;
}


/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr P, SQElemType v) {
    if (P == NULL || P->root == NULL) {
        printf("插入失败\n");
        return failed;
    }
    if (P->root->left == NULL && P->root->right == NULL && P->root->value == EOF) {
        P->root->value = v;
        printf("插入成功\n");
        return succeed;
    }
    NodePtr root = P->root;
    NodePtr parent;
    NodePtr p = (NodePtr) malloc(sizeof(Node));
    p->value = v;
    p->left = p->right = NULL;
    while (root) {
        parent = root;
        if (v < root->value)
            root = root->left;
        else
            root = root->right;
    }
    if (v < parent->value)
        parent->left = p;
    else if (v > parent->value)
        parent->right = p;
    else {
        printf("此数已经在树中，插入失败\n");
        return failed;
    }
    printf("插入成功\n");
    return succeed;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr P, SQElemType v) {
    if (P == NULL || P->root == NULL) {
        printf("传入指针有误\n");
        return failed;
    }
    NodePtr root = P->root;
    if (root->right == NULL && root->left == NULL && root->value == EOF) {
        printf("此树为空，无法删除\n");
        return failed;
    }
    NodePtr L, LL;
    NodePtr t;
    t = root;
    if (BST_search(t, v) == NULL) {
        printf("此数不在数中\n");
        return failed;
    }
    NodePtr p = root;
    NodePtr parent = root;
    int child = 0;
    while (p) {
        if (p->value == v) {  //判断节点的值与传入的值的大小，此时是等于的情况
            if (!p->left && !p->right) {  // 当此节点为叶节点时
                if (p == root)  // 当它既是叶节点，又是根节点时，直接free掉
                {
                    free(p);
                    P->root=NULL;
                    return succeed;
                } else if (child == 0) {  // 当它是父节点的左节点时
                    parent->left = NULL;
                    free(p);
                } else {  // 为右节点时
                    parent->right = NULL;
                    free(p);
                }
            } else if (!p->left) {  // 如果它左节点不为零
                if (child == 0)
                    parent->left = p->right;
                else
                    parent->right = p->right;
                free(p);
            } else if (!p->right) {  // 如果它右节点不为零
                if (child == 0)
                    parent->left = p->left;
                else
                    parent->right = p->left;
                free(p);
            } else {      // 它左右节点都不为零
                LL = p;
                L = p->right;
                if (L->left) {
                    LL = L;
                    L = L->left;
                    p->value = L->value;
                    LL->left = L->left;
                    for (; L->left; L = L->left);
                    L->left = p->left;
                    p->left = NULL;
                } else {
                    p->value = L->value;
                    LL->right = L->right;
                }
            }
            p = NULL;  //跳出循环
        } else if (v < p->value) {  // 小于节点值的时候，向左走
            child = 0;
            parent = p;
            p = p->left;
        } else {  // 大于节点值的时候，向右走
            child = 1;
            parent = p;
            p = p->right;
        }
    }
    printf("删除成功\n");
    return succeed;
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
NodePtr BST_search(NodePtr T, SQElemType v) {
    if (!T || v == T->value) {
        return T;
    } else if (v < T->value)
        return BST_search(T->left, v);
    else
        return BST_search(T->right, v);
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr P, void (*visit)(NodePtr)) {
    if (P == NULL||P->root==NULL) {
        printf("ERROR\n");
        return failed;
    }
    LinkStack *Stack = (LinkStack *) malloc(sizeof(LinkStack));
    initLStack(Stack);
    NodePtr root = P->root;
    while (root || !isEmptyLStack(Stack)) {
        if (root) {
            visit(root);
            if (root->right)
                pushLStack(Stack, root->right);
            root = root->left;
        } else
            popLStack(Stack, &root);
    }
    destroyLStack(&Stack);
    return succeed;
}

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr T, void (*visit)(NodePtr)) {
    if (T) {
        visit(T);
        BST_preorderR(T->left, visit);
        BST_preorderR(T->right, visit);
    }
    return succeed;
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr P, void (*visit)(NodePtr)) {
    if (P == NULL||P->root==NULL) {
        printf("ERROR\n");
        return failed;
    }
    LinkStack *Stack = (LinkStack *) malloc(sizeof(LinkStack));
    initLStack(Stack);
    NodePtr root = P->root;
    while (root || !isEmptyLStack(Stack)) {
        if (root) {
            pushLStack(Stack, root);
            root = root->left;
        } else {
            popLStack(Stack, &root);
            visit(root);
            root = root->right;
        }
    }
    destroyLStack(&Stack);
    return succeed;
}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr T, void (*visit)(NodePtr)) {
    if (T) {
        BST_inorderR(T->left, visit);
        visit(T);
        BST_inorderR(T->right, visit);
    }
    return succeed;
}
/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr P, void (*visit)(NodePtr)) {
    if (P == NULL||P->root==NULL) {
        printf("ERROR\n");
        return failed;
    }
    NodePtr blank;
    LinkStack *Stack = (LinkStack *) malloc(sizeof(LinkStack));
    initLStack(Stack);
    NodePtr root = P->root;
    NodePtr preNode, currNode;
    preNode = NULL;
    pushLStack(Stack, root);
    while (!isEmptyLStack(Stack)) {
        getTopLStack(Stack, &currNode);
        if (preNode == NULL || preNode->left == currNode || preNode->right == currNode) {
            if (currNode->left)
                pushLStack(Stack, currNode->left);
            else if (currNode->right)
                pushLStack(Stack, currNode->right);
        } else if (currNode->left == preNode) {
            if (currNode->right)
                pushLStack(Stack, currNode->right);
        } else {
            visit(currNode);
            popLStack(Stack, &blank);
        }
        preNode = currNode;
    }
    destroyLStack(&Stack);
    return succeed;
}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr T, void (*visit)(NodePtr)) {
    if (T) {
        BST_postorderR(T->left, visit);
        BST_postorderR(T->right, visit);
        visit(T);
    }
    return succeed;
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr P, void (*visit)(NodePtr)) {
    int curlayer = 0;
    NodePtr T = P->root;
    int nextlayer = 0;
    LinkQueue *queue = InitQueue();
    EnQueue(queue, T);
    curlayer++;
    NodePtr p = popQueue(queue);
    while (p) {
        curlayer--;
        visit(p);
        if (p->left) {
            EnQueue(queue, p->left);
            nextlayer++;
        }
        if (p->right) {
            EnQueue(queue, p->right);
            nextlayer++;
        }
        if (curlayer == 0) {
            curlayer = nextlayer;
            nextlayer = 0;
            printf("\n");
        }
        p = popQueue(queue);
    }
    return succeed;
}


void print(NodePtr T) {
    printf("%d\n", T->value);
}


void menu() {
    printf("二叉排序数\n");
    printf("a,插入数字\n");
    printf("b,查找数字\n");
    printf("c,删除数字\n");
    printf("d,递归前序遍历\n");
    printf("e，递归中序遍历\n");
    printf("f,递归后序遍历\n");
    printf("g，迭代前序遍历\n");
    printf("h，迭代中序遍历\n");
    printf("i，迭代后序遍历\n");
    printf("j,层序遍历\n");
    printf("q，退出程序\n");
}