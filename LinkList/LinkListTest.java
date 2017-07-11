public class LinkListTest{
	public static void main(String [] args){
		LinkList one = new LinkList();
		int[] A = {5,87,99,5,11,4};
		for(int i=0;i<6;i++){
			one.input(A[i]);
		}
		System.out.println("单链表是：");
		one.output();
		System.out.println('\n'+"在位置4插入新元素66后： ");
		one.insert(4,66);
		one.output();
		System.out.println('\n'+"在位置7插入新元素77后： ");
		one.insert(7,77);
		one.output();
		System.out.println('\n'+"删除第4个元素后：");
		one.delete(4);
		one.output();
		System.out.println('\n'+"删除第9个元素后：");
		one.delete(9);
		one.output();
		System.out.println('\n'+"查找位置为2的元素为："+one.find(2));
		System.out.println("查找位置为0的元素为："+one.find(0));
		System.out.println("由小到大排序后：");
		one.sort();
		one.output();
	}
}
/*/////////////////////测试/////////////////////
单链表是：
5 87 99 5 11 4
在位置4插入新元素66后：
5 87 99 66 5 11 4
在位置7插入新元素77后：
5 87 99 66 5 11 4 77
删除第4个元素后：
5 87 99 5 11 4 77
删除第9个元素后：
位置错误
5 87 99 5 11 4 77
查找位置为2的元素为：87
查找位置为0的元素为：-1
由小到大排序后：
4 5 5 11 77 87 99
*/////////////////////测试/////////////////////