#include<bits/stdc++.h>
#include<stdio.h>

#include<stdlib.h>

#define FALSE_VALUE 0
#define TRUE_VALUE 1
using namespace std;

struct treeNode
{
    int item;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};

struct treeNode * root;


void initializeTree()
{
    root = 0;
}


struct treeNode * searchItem(struct treeNode * node, int item)
{
    if(node==0) return 0;
    if(node->item==item) return node; //found, return node
    struct treeNode * t = 0;
    if(item < node->item)
        t = searchItem(node->left, item); //search in the left sub-tree
    else
        t = searchItem(node->right, item); //search in the right sub-tree
    return t;
};


struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

struct treeNode * insertItem(struct treeNode * node, int item)
{
    if(node==0) //insert as the root as the tree is empty
    {
        struct treeNode * newNode = makeTreeNode(item);
        root = newNode;
        return newNode;
    }

    if(node->item==item) return 0; //already an item exists, so return NULL

    if(item<node->item && node->left==0) //insert as the left child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->left = newNode;
        return newNode;
    }

    if(item>node->item && node->right==0) //insert as the right child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->right = newNode;
        return newNode;
    }

    if(item<node->item)
        return insertItem(node->left, item); //insert at left sub-tree
    else
        return insertItem(node->right, item); //insert at right sub-tree
}



int calcNodeHeight(struct treeNode * node) //return height of a node
{
    if(node==0) return -1;
    int l, r;
    l = calcNodeHeight(node->left);
    r = calcNodeHeight(node->right);
    if(l>r) return l+1;
    else return r+1;
}


int calcHeight(int item) //return height of an item in the tree
{
    struct treeNode * node = 0;
    node = searchItem(root, item);
    if(node==0) return -1; //not found
    else return calcNodeHeight(node);
}

int getSize(struct treeNode * node)
{
    if(node==0)return 0;
    int lf,rg;
    rg = getSize(node->right);
    lf = getSize(node->left);

    return rg+lf+1;
}

int calcDepth(int item)//return depth of an item in the tree
{
    if(root==0 || searchItem(root,item)==0){printf("Not found.....");return -1;}
    struct treeNode * temp = root;
    int d=0;
    while(temp->item!=item)
    {
        if(item>temp->item)temp=temp->right;
        else temp = temp->left;
        ++d;
    }
    return d;
    //write your codes here
}

int calcNodeDepth(struct treeNode * node) //return depth of a node
{
    if(node)return calcDepth(node->item);
    else{
        printf("Node dosen't exist.....\n");
        return -1;
    }
    //write your codes here
}


int deleteItem(struct treeNode * node, int item)
{
    struct treeNode* temp = searchItem(node,item);
    if(temp==0){
        printf("Element doesn't exist.....\n");
        return FALSE_VALUE;
    }
    if(temp->left==0 && temp->right==0){
        if(temp==node){
            delete(root);
            initializeTree();
            return TRUE_VALUE;
        }
        while(node){
            if(node->left==temp){node->left=NULL;break;}
            else if(node->right==temp){node->right=NULL;break;}
            if(temp->item>node->item)node=node->right;
            else node = node->left;
        }
    }
    else{

        if(temp->right){

            struct treeNode*tn = temp->right, *par=tn;

            while(tn->left){
                par=tn;
                tn = tn->left;
            }

            temp->item = tn->item;
            if(par==tn)temp->right=tn->right;
            else {par->left=tn->right;}

        }
        else{
            struct treeNode*tn = temp->left, *par=tn;

            while(tn->right){
                par=tn;
                tn = tn->right;
            }

            temp->item = tn->item;
            if(tn==par)temp->left=tn->left;
            else par->right=tn->left;
        }
    }
    return TRUE_VALUE;

    //write your code here, return TRUE, FALSE
}



int getMinItem() //returns the minimum item in the tree
{
    struct treeNode*temp = root;

    if(temp==0){printf("Empty tree.....\n");return FALSE_VALUE;}

    int mn=1e9;
    while(temp)
    {
        if(mn>temp->item)mn=temp->item;
        temp=temp->left;
    }
    if(mn==1e9)return FALSE_VALUE;
    else return mn;
    //write your codes here
}

int getMaxItem() //returns the maximum item in the tree
{

    struct treeNode*temp = root;
    if(temp==0){printf("Empty tree.....\n");return FALSE_VALUE;}
    int mx=-1e9;
    while(temp)
    {
        if(mx<temp->item)mx=temp->item;
        temp=temp->right;
    }
    return mx;
    //write your codes here
}

int rangeSearch(struct treeNode * node, int leftBound, int rightBound) //returns number of items in the
{

    if(leftBound>rightBound )
    {
        printf("Leftbound should be less than rightbound....\n");
        return 0;
    }
    /*else if(node==root && searchItem(node,rightBound)==0 && searchItem(node,leftBound)==0)
    {
        printf("Not found in tree....\n");
        return 0;
    }*/

    if(node==0)return 0;

    return  rangeSearch(node->left,leftBound,rightBound) + (node->item>=leftBound && node->item<=rightBound) +rangeSearch(node->right,leftBound,rightBound);

}


void printInOrder(struct treeNode * node, int height)
{
    if(node==0) return ;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print item
    for(int i=0; i<height; i++)printf("   ");
    printf("%03d\n",node->item);

    //print right sub-tree
    printInOrder(node->right, height-1);
}

int maxim(int a,int b){
    return (a>b)*a + b*(a<b) + a*(a==b);
}

int minim(int a,int b){
    return (a>b)*b + a*(a<b) + a*(a==b);
}

void max_min_in_range(int &mx , int &mn , int lo, int hi){

    if(root==0)return;
    struct treeNode*node = root , *lefty = root;

    while(node){
        if(node->item>=lo && node->item<=hi)break;
        else if(node->item > maxim(lo,hi)){node = node->left;lefty=lefty->left;}
        else {node = node->right;lefty=lefty->right;}
    }
    if(node==0)return;
    mx = node->item;
    mn = mx;

    while(node){
        mx = maxim(mx,node->item);
        if(node->item < hi)node = node->right;
        else if(node->item > hi)node = node->left;
        else break;
    }

    while(lefty){
        mn = minim(mn,lefty->item);
        if(lefty->item < lo)lefty = lefty->right;
        else if(lefty->item > lo)lefty = lefty->left;
        else break;
    }
}

void print_Level(struct treeNode *node)
{
    // Base Case
    if (node == NULL)  return;

    // Create an empty queue for level order tarversal
    queue<treeNode *> q;

    // Enqueue Root and initialize height
    q.push(node);

    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;

        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            treeNode *nd = q.front();
            cout << nd->item << " ";
            q.pop();
            if (nd->left != NULL)
                q.push(nd->left);
            if (nd->right != NULL)
                q.push(nd->right);
            nodeCount--;
        }
        cout << endl;
    }
}


map<int,int>dist; /**dist from root*/

void Dist_Maping(struct treeNode* node){

    if(node==NULL)return;

    if(node->left)dist[node->left->item] = dist[node->item]-1;

    if(node->right)dist[node->right->item] = dist[node->item]+1;

    Dist_Maping(node->left);

    Dist_Maping(node->right);
}

void print_dist(struct treeNode * node)
{
    if(node==0) return ;
    //print left sub-tree
    print_dist(node->left);

    printf("%d dist %d\n",node->item,dist[node->item]);

    //print right sub-tree
    print_dist(node->right);
}

void Top_view(struct treeNode*node){

    dist[root->item]=0;
    Dist_Maping(root);
    if (node == NULL)  return;

    // Create an empty queue for level order tarversal
    queue<treeNode *> q;

    // Enqueue Root and initialize height
    q.push(node);
    int D[2][2];
    D[0][0]=0;
    D[1][0]=0;
    cout<<root->item<<" ";

    while (1)
    {
        int nodeCount = q.size();

        if (nodeCount == 0)break;

        D[0][1]=0;
        D[1][1]=0;

        while (nodeCount > 0)
        {
            treeNode *nd = q.front();

            int di  = dist[nd->item];

            if(di>=0){
                if(di>D[0][0])cout<<nd->item<<endl;
                D[0][1] = max(di,D[0][1]);
            }
            else{
                if(di<D[1][0])cout<<nd->item<<endl;
                D[1][1] = min(di,D[1][1]);
            }

            q.pop();

            if (nd->left != NULL) q.push(nd->left);

            if (nd->right != NULL)q.push(nd->right);

            nodeCount--;
        }

        D[0][0]=max(D[0][0],D[0][1]);
        D[1][0]=min(D[1][0],D[1][1]);

    }


}


int main(void)
{
    initializeTree();
    while(1)
    {
        printf("\n1. Insert item. 2. Delete item. 3. Search item. \n");
        printf("4. Print height of tree. 5. Print height of an item. \n");
        printf("6. PrintInOrder. 7. exit. 8. getSize 9. rangesearch . 11. getMaxItem. \n ");
        printf("12. getMinitem. 13. calcNodeDepth. 14. calcDepth. \n");
        printf("15. max_min_in_range. 16. print_level. 17. top_view");
        printf("\n\n");


        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(root, item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(root, item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int height = calcNodeHeight(root);
            printf("Height of tree = %d\n", height);
        }
        else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            int height = calcHeight(item);
            printf("Height of %d = %d\n", item, height);
        }
        else if(ch==6)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==7)
        {
            break;
        }
        else if(ch==8)
        {
            printf("%d\n",getSize(root));
        }
        else if(ch==9)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",rangeSearch(root,l,r));
        }
        else if(ch==12)
        {
            int i=getMinItem();
            if(i!=FALSE_VALUE)printf("%d\n",i);
        }
        else if(ch==11)
        {
            int i=getMaxItem();
            if(i)printf("%d\n",i);

        }
        else if(ch==14)
        {
            int item;
            scanf("%d", &item);
            printf("%d\n",calcDepth(item));
        }
        else if(ch==13)
        {
            int item;
            scanf("%d", &item);
            printf("%d\n",calcNodeDepth(searchItem(root,item)) );
        }
        else if(ch==15){
            int l,r,mx=-1e9,mn=-mx;
            scanf("%d%d",&l,&r);
            max_min_in_range(mx,mn,minim(l,r),maxim(r,l)); /**it's ok*/
            if(maxim(mn,mx) != -1e9)printf("%d %d\n",mx,mn);
        }
        else if(ch==16){
            print_Level(root);
        }
        else if(ch==17)Top_view(root);

    }

}
/**
1 50
1 60
1 40
1 45
1 42
1 41
1 65
1 55
1 70
1 80
1 75

*/
