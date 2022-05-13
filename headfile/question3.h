//二叉树的建立 遍历
//先序遍历  根左右
//中序遍历  左根右
//后序遍历  左右根
//层次遍历  当根节点出队 子节点入队
typedef struct ktree
{
    char value;
    struct ktree *left;
    struct ktree *right;
} treeNode;
// theeNode 构造函数
treeNode *ctor_tnode(char v, treeNode *l, treeNode *r);
//二叉树建立 15个节点
treeNode *build_tree();
//先序遍历 根左右
void each_root_left_right(treeNode *top);
//中序遍历 左根右
void each_left_root_right(treeNode *top);
//后序遍历 左右根
void each_left_right_root(treeNode *top);
//层次遍历
void init_each_treesque(treeNode *top);
//求树的深度
int get_depth(treeNode *top);
//输出树的叶子
void show_tree_leaf(treeNode *top);
//输出树的非叶子
void noshow_tree_leaf(treeNode *top);
// 二叉树的 深拷贝  //mater: 被拷贝的对象 利用先序排序
treeNode *deep_copy_tree(treeNode *mater);
// 二叉树的 析构 利用后序排序
void free_tree(treeNode *top);
