#include"iostream"
#include"Bitree.h"
using namespace std;

int main()
{
	Bitree Bitree1;
	bnode*root1 = new bnode;//�½�������Bitree1�����ĸ����root1
	
	Bitree1.creat_Bitree();
	cout << "������˳�����������ַ�����#��ʾ�ս�㣺";
	Bitree1.input(&root1);
	//Bitree1.input_2(&root1);
	cout << "���������������" <<endl;
	Bitree1.preorder_output(root1);
	cout << endl << "���������������"<<endl;
	Bitree1.inorder_output(root1);
	cout <<endl<< "���������������" <<endl;
	Bitree1.lastorder_output(root1);
	cout << endl << "���������ܽ����Ϊ��" << Bitree1.bitree_count_all(root1) << endl;
	cout << "��������Ҷ�ӽ����Ϊ��"<< Bitree1.bitree_count_leaf(root1) << endl;
	cout << "�������Ķ�Ϊ1�Ľ����Ϊ��"<< Bitree1.bitree_count_degree_1(root1) << endl;
	cout << "����������ȣ��߶ȣ�Ϊ��"<< Bitree1.bitree_deepth(root1) << endl;
	cout  << "��������������������Ϊ��" << endl;
	Bitree1.swap(root1);
	Bitree1.preorder_output(root1);
	cout << endl;

	//---------------------�����¶�����Bitree2-------------------------//
	Bitree  Bitree2;
	bnode*root2 = root1;
	Bitree2.creat_Bitree();
	cout <<endl<< "�����µĶ���������ǰ��Ķ��������µĶ���������Ϊ��" << endl;
	Bitree2.copy(root2);
	Bitree2.preorder_output(root2);
	cout << endl;
	//---------------------�����¶�����Bitree2-------------------------//

	system("pause");
	return 0;
	
}
/*////////////////////////////////////////////////����////////////////////////////////////////////////
������˳�����������ַ�����#��ʾ�ս�㣺abcde##f##g##hi##j##klm##n##op#q##rs##tu###		
���������������
a b c d e f g h i j k l m n o p q r s t u
���������������
e d f c g b i h j a m l n k p q o s r u t
���������������
e f d g c i j h b m n l q p s u t r o k a
���������ܽ����Ϊ��21
��������Ҷ�ӽ����Ϊ��10
�������Ķ�Ϊ1�Ľ����Ϊ��2
����������ȣ��߶ȣ�Ϊ��6
��������������������Ϊ��
a k o r t u s p q l n m b h j i c g d f e

�����µĶ���������ǰ��Ķ��������µĶ���������Ϊ��
a k o r t u s p q l n m b h j i c g d f e
�밴���������. . .
/*////////////////////////////////////////////////����////////////////////////////////////////////////