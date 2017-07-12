/*
二叉树
c++
简单实现
（主程序部分）
*/

#include"iostream"
#include"Bitree.h"
using namespace std;

int main()
{
	Bitree Bitree1;
	bnode*root1 = new bnode;//新建二叉树Bitree1和它的根结点root1
	
	Bitree1.creat_Bitree();
	cout << "以先序顺序连续输入字符，以#表示空结点：";
	Bitree1.input(&root1);
	//Bitree1.input_2(&root1);
	cout << "先序遍历二叉树：" <<endl;
	Bitree1.preorder_output(root1);
	cout << endl << "中序遍历二叉树："<<endl;
	Bitree1.inorder_output(root1);
	cout <<endl<< "后序遍历二叉树：" <<endl;
	Bitree1.lastorder_output(root1);
	cout << endl << "二叉树的总结点数为：" << Bitree1.bitree_count_all(root1) << endl;
	cout << "二叉树的叶子结点数为："<< Bitree1.bitree_count_leaf(root1) << endl;
	cout << "二叉树的度为1的结点数为："<< Bitree1.bitree_count_degree_1(root1) << endl;
	cout << "二叉树的深度（高度）为："<< Bitree1.bitree_deepth(root1) << endl;
	cout  << "交换左右子树后的先序遍为：" << endl;
	Bitree1.swap(root1);
	Bitree1.preorder_output(root1);
	cout << endl;

	//-建立新二叉树Bitree2
	Bitree  Bitree2;
	bnode*root2 = root1;
	Bitree2.creat_Bitree();
	cout <<endl<< "建立新的二叉树复制前面的二叉树，新的二叉树先序为：" << endl;
	Bitree2.copy(root2);
	Bitree2.preorder_output(root2);
	cout << endl;

	system("pause");
	return 0;
	
}
/*////////////////////////////////////////////////测试////////////////////////////////////////////////
以先序顺序连续输入字符，以#表示空结点：abcde##f##g##hi##j##klm##n##op#q##rs##tu###		
先序遍历二叉树：
a b c d e f g h i j k l m n o p q r s t u
中序遍历二叉树：
e d f c g b i h j a m l n k p q o s r u t
后序遍历二叉树：
e f d g c i j h b m n l q p s u t r o k a
二叉树的总结点数为：21
二叉树的叶子结点数为：10
二叉树的度为1的结点数为：2
二叉树的深度（高度）为：6
交换左右子树后的先序遍为：
a k o r t u s p q l n m b h j i c g d f e

建立新的二叉树复制前面的二叉树，新的二叉树先序为：
a k o r t u s p q l n m b h j i c g d f e
请按任意键继续. . .
/*////////////////////////////////////////////////测试////////////////////////////////////////////////
