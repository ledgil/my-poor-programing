public class LinkListTest{
	public static void main(String [] args){
		LinkList one = new LinkList();
		int[] A = {5,87,99,5,11,4};
		for(int i=0;i<6;i++){
			one.input(A[i]);
		}
		System.out.println("�������ǣ�");
		one.output();
		System.out.println('\n'+"��λ��4������Ԫ��66�� ");
		one.insert(4,66);
		one.output();
		System.out.println('\n'+"��λ��7������Ԫ��77�� ");
		one.insert(7,77);
		one.output();
		System.out.println('\n'+"ɾ����4��Ԫ�غ�");
		one.delete(4);
		one.output();
		System.out.println('\n'+"ɾ����9��Ԫ�غ�");
		one.delete(9);
		one.output();
		System.out.println('\n'+"����λ��Ϊ2��Ԫ��Ϊ��"+one.find(2));
		System.out.println("����λ��Ϊ0��Ԫ��Ϊ��"+one.find(0));
		System.out.println("��С���������");
		one.sort();
		one.output();
	}
}
/*/////////////////////����/////////////////////
�������ǣ�
5 87 99 5 11 4
��λ��4������Ԫ��66��
5 87 99 66 5 11 4
��λ��7������Ԫ��77��
5 87 99 66 5 11 4 77
ɾ����4��Ԫ�غ�
5 87 99 5 11 4 77
ɾ����9��Ԫ�غ�
λ�ô���
5 87 99 5 11 4 77
����λ��Ϊ2��Ԫ��Ϊ��87
����λ��Ϊ0��Ԫ��Ϊ��-1
��С���������
4 5 5 11 77 87 99
*/////////////////////����/////////////////////