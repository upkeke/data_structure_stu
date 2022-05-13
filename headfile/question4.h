//数据结构-图的创建(邻接矩阵)和遍历(BFS+DFS)

//---------------矩阵图结构-------------------
typedef struct gg
{
    char * c_arr; //顶点
    int length; //顶点数
    int ** row_col; //数组
    int bian; //边数
}graph_matrix; //矩阵图结构

//矩阵图构造 传入图有多少个顶点 本次顶点个数为7
graph_matrix* ctor_gra_matr(int length);

//矩阵图读取图信息  //本次7个节点 
//参数：第一个是顶点数组 第二个是 存放是否相邻信息的数组，也可以传入int* 将二维数组首地址强转为int*
void build_gra_matr(graph_matrix *top, char *c_arr,int(*row_col)[7]); 
//矩阵图DFS 深度遍历  
void dfs_gra_matr(graph_matrix*top,int vis_index);
//矩阵图BFS 广度遍历 
void bfs_gra_matr(graph_matrix*top,int vis_index);

//---------------邻接表 图结构-------------------
