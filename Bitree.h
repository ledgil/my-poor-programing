#include"iostream"
using namespace std;

typedef struct bnode
{
	char data;
	bnode *lchild, *rchild;//�������Ӻ��Һ���
}bnode;

typedef struct Bitree
{
public:	
	void creat_Bitree();							//��ʼ��������
	void input(bnode **T);						//����ָ��ݹ����������
	bnode* input2(bnode*T);					//ͨ������ֵ�ݹ����������
	void preorder_output(bnode *T);		//�������
	void inorder_output(bnode *T);			//�������
	void lastorder_output(bnode *T);		//�������
	int bitree_count_all(bnode*T);			//�����ܽ����
	int bitree_count_leaf(bnode*T);			//����Ҷ�ӽ����
	int bitree_count_degree_1(bnode*T);//�����Ϊ1�Ľ����
	int bitree_deepth(bnode*T);				//��������������
	bnode* swap(bnode*T);						//��������������������
	bnode* copy(bnode*T);						//����һ�ö�����
private:
	bnode *root;				//��һ�����ڵ�
	int count_all;				//�����ܽ��
	int count_leaf;			//����Ҷ�ӽ��
	int count_degree_1;	//�����Ϊ1�Ľ��
}Bitree;//typedef�� "struct Bitree" ����ṹ���˸������ֽ� Bitree����Ҳ������������ը��������������Ӣ��

//��ʼ��������
void Bitree::creat_Bitree()
{
	root = NULL;
	count_all = 0;
	count_leaf = 0;
	count_degree_1 = 0;
}

//����ָ��ݹ����������//�������������
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
//ͨ������ֵ�ݹ����������//�������������
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

//�������������
void Bitree::preorder_output(bnode *T)
{
	if(T)
	{
		cout << T->data << " ";
		preorder_output(T->lchild);
		preorder_output(T->rchild);
	}
}

//�������������
void Bitree::inorder_output(bnode *T)
{
	if(T)
	{
		inorder_output(T->lchild);
		cout << T->data << " ";
		inorder_output(T->rchild);
	}
}

//�������������
void Bitree::lastorder_output(bnode *T)
{
	if (T)
	{
		lastorder_output(T->lchild);
		lastorder_output(T->rchild);
		cout << T->data << " ";
	}
}

//����ڵ���
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

//����Ҷ�ӽ����
int Bitree::bitree_count_leaf(bnode*T)
{
	if (T)
	{
		if (T->lchild == NULL&&T->rchild == NULL)
			count_leaf++;//����������Ӻ��Һ��Ӷ�Ϊ�գ���ýڵ���Ҷ�ӽ��
		bitree_count_leaf(T->lchild);
		bitree_count_leaf(T->rchild);
	}
	return count_leaf;
}

//�����Ϊ1�Ľ�����
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

//�������������ȣ��߶ȣ�
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

//������������
bnode* Bitree::swap(bnode*T)
{
	if (!T || !T->lchild && !T->rchild)
		return T;//û�и�����ֻ�и����
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

//�������ĸ���
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

