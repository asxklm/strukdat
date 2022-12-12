node* AVLTree(int dat);
int SubtreeHeight(node *nod);
int maxVal(int a, int b);
node *kiriRotate(node *x);
node* kananRotate(node *y);
int getBalance(node *Nod);

node* insert(node* root,int val)
{
    if (root == NULL)
        return  AVLTree(val);

    if (val < root -> val)
        root->kiri = insert(root->kiri,val );
    else if (val > root->val)
        root->right = insert(root->kanan,val );


    root->ht = 1 + maxVal(SubtreeHeight(root->kiri), SubtreeHeight(root->kanan));

    int balance = getBalance(root);

    if (balance > 1 && val < root->kiri->val)
        return kananRotate(root);

    if (balance < -1 && val > root->kanan->val)
        return kiriRotate(root);

    if (balance > 1 && val > root->kiri->val)
    {
        root->kiri = kiriRotate(root->kiri);
        return kananRotate(root);
    }

    if (balance < -1 && val < root->kanan->val)
    {
        root->kanan = kananRotate(root->kanan);
        return kiriRotate(root);
    }
    return root;
}

node* kananRotate(node *y)
{
    node* x = y->kiri;
    node* T2 = x->kanan;

    x->kanan = y;
    y->kiri = T2;

    y->ht = maxVal(SubtreeHeight(y->kiri), SubtreeHeight(y->kanan)) + 1;
    x->ht = maxVal(SubtreeHeight(x->kiri), SubtreeHeight(x->kanan)) + 1;

    return x;
}


node *kiriRotate(node *x)
{
    node *y = x->kanan;
    node *T2 = y->kiri;

    y->kiri = x;
    x->kanan = T2;

    x->ht = maxVal(SubtreeHeight(x->kiri), SubtreeHeight(x->kanan)) + 1;
    y->ht = maxVal(SubtreeHeight(y->kiri), SubtreeHeight(y->kanan)) + 1;

    return y;
}

int getBalance(node *Nod)
{
    if (Nod == NULL)
        return 0;
    return SubtreeHeight(Nod->kiri) - SubtreeHeight(Nod->kanan);
}

int maxVal(int a,int b)
{
    return (a > b) ? a : b;
}

node* AVLTree(int dat)
{
    node* treeNode = (node*)malloc(sizeof(node));

    treeNode->val = dat;

    treeNode->kiri = NULL;
    treeNode->kanan = NULL;
    treeNode->ht = 0;
    return(treeNode);
}

int SubtreeHeight(node *nod)
{
    if (nod == NULL)
        return -1;
    return nod->ht;
}
