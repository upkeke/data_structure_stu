// hashTable 
//桶组元素个数 20以内最大的素数 19 
//哈希函数 key%19
//碰撞冲突 通过链地址法 解决
#define HASHSIZE 19

//单个桶
typedef struct ggghas
{
    int key;
    char value;
    struct ggghas* next;
} bucket; 

typedef struct
{
    bucket *head;
    bucket *lastBuck;
} hashItem;

typedef hashItem* hashTable;

hashTable build_hash();
void print_hash(hashTable hash);
void push_back_pair(hashTable hash,int key,char value); 

//查找指定key的值
char get_value(hashTable hash, int key);

//删除 键值对
void delete_pair(hashTable hash, int key);
