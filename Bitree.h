#include"iostream"
using namespace std;

typedef struct bnode
{
	char data;
	bnode *lchild, *rchild;//设置左孩子和右孩子
}bnode;

typedef struct Bitree
{
public:	
	void creat_Bitree();							//初始化二叉树
	void input(bnode **T);						//二级指针递归输入二叉树
	bnode* input2(bnode*T);					//通过返回值递归输入二叉树
	void preorder_output(bnode *T);		//先序遍历
	void inorder_output(bnode *T);			//中序遍历
	void lastorder_output(bnode *T);		//后序遍历
	int bitree_count_all(bnode*T);			//计算总结点数
	int bitree_count_leaf(bnode*T);			//计算叶子结点数
	int bitree_count_degree_1(bnode*T);//计算度为1的结点数
	int bitree_deepth(bnode*T);				//计算二叉树的深度
	bnode* swap(bnode*T);						//交换二叉树的左右子树
	bnode* copy(bnode*T);						//复制一棵二叉树
private:
	bnode *root;				//搞一个根节点
	int count_all;				//计数总结点
	int count_leaf;			//计数叶子结点
	int count_degree_1;	//计算度为1的结点
}Bitree;//typedef把 "struct Bitree" 这个结构起了个新名字叫 Bitree，你也可以起其他屌炸天的名字彰显你的英姿

//初始化二叉树
void Bitree::creat_Bitree()
{
	root = NULL;
	count_all = 0;
	count_leaf = 0;
	count_degree_1 = 0;
}

//二级指针递归输入二叉树//先序输入二叉树
void Bitree::input(bnode **T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		*T = NULL;
	}
	else 
	{
		*T = new bnode;

		(*T)->data = ch;
		input(&(*T)->lchild);
		input(&(*T)->rchild);
	}
}
//通过返回值递归输入二叉树//先序输入二叉树
bnode* Bitree::input2(bnode *T)
{
	char ch;
	cin >> ch;
	
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = new bnode;
		T->data = ch;
		T->lchild = input2(T->lchild);
		T->rchild = input2(T->rchild);
	}
	return T;
}

//先序遍历二叉树
void Bitree::preorder_output(bnode *T)
{
	if(T)
	{
		cout << T->data << " ";
		preorder_output(T->lchild);
		preorder_output(T->rchild);
	}
}

//中序遍历二叉树
void Bitree::inorder_output(bnode *T)
{
	if(T)
	{
		inorder_output(T->lchild);
		cout << T->data << " ";
		inorder_output(T->rchild);
	}
}

//后序遍历二叉树
void Bitree::lastorder_output(bnode *T)
{
	if (T)
	{
		lastorder_output(T->lchild);
		lastorder_output(T->rchild);
		cout << T->data << " ";
	}
}

//计算节点数
int Bitree::bitree_count_all(bnode*T)
{
	if (T)
	{
		count_all++;
		bitree_count_all(T -> lchild);
		bitree_count_all(T -> rchild);
	}
	return count_all;
}

//计算叶子结点数
int Bitree::bitree_count_leaf(bnode*T)
{
	if (T)
	{
		if (T->lchild == NULL&&T->rchild == NULL)
			count_leaf++;//如果结点的左孩子和右孩子都为空，则该节点是叶子结点
		bitree_count_leaf(T->lchild);
		bitree_count_leaf(T->rchild);
	}
	return count_leaf;
}

//计算度为1的结点个数
int Bitree::bitree_count_degree_1(bnode*T)
{
	if (T)
	{
		if ((!T->lchild&&T->rchild) || (T->lchild && !T->rchild))
			count_degree_1++;
		bitree_count_degree_1(T->lchild);
		bitree_count_degree_1(T->rchild);
	}
	return count_degree_1;
}

//计算二叉树的深度（高度）
int Bitree::bitree_deepth(bnode*T)
{
	int i, j;
	if (T == NULL)
		return 0;
	if(!T->lchild && !T->rchild)
		return 1;
	if (T->lchild)
		i=bitree_deepth(T->lchild);
	else
		i = 0;
	if (T->rchild)
		j = bitree_deepth(T->rchild);
	else
		j = 0;
	return i > j ? i + 1 : j + 1;
}

//交换左右子树
bnode* Bitree::swap(bnode*T)
{
	if (!T || !T->lchild && !T->rchild)
		return T;//没有根结点或只有根结点
	bnode*p = new bnode;
	p = T->lchild;
	T->lchild = T->rchild;
	T->rchild = p;
	if (T->lchild)
	{
		T->lchild = swap(T->lchild);
	}
	if (T->rchild)
	{
		T->rchild = swap(T->rchild);
	}
	return T;
}

//二叉树的复制
bnode* Bitree::copy(bnode*T)
{
	bnode*new_bnode;
	if (!T)
		return NULL;
	else
	{
		new_bnode = new bnode;
		new_bnode->data = T->data;
		new_bnode->lchild = copy(T->lchild);
		new_bnode->rchild = copy(T->rchild);
		return new_bnode;
	}
}

