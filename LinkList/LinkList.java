class Node{
	int data;
	Node next;
	
	public Node(int data){
		this.data=data;
	}
}

public class LinkList{
	int count=0;
	Node head;
	Node rear;
	public LinkList(){
		head=null;
		rear=null;
	}
	//��������
	public void input(int data){
		Node s = new Node(data);
		if(head ==null){
			head=s;
			rear=s;
		}
		rear.next=s;
		rear=s;
		rear.next=null;
		count++;
	}
	//��ӡ����
	public void output(){
		Node p=head;
		while(p!=null){
			System.out.print(p.data+" ");
			p=p.next;
		}
	}
	//��������
	public void insert(int location,int data){
		Node p=head;
		if(location>count+1||location<1)
			System.out.println("λ�ô���");
		if(location==1){
			Node s=new Node(data);
			s.next=head;
		}
		if(location==count+1){
			input(data);
		}
		else{
			int j=1;
			while(j!=location-1&&p!=null){
				p=p.next;
				j++;
			}
			Node s=new Node(data);
			s.next=p.next;
			p.next=s;
		}
		
	}
	//ɾ������
	public void delete(int location){
		Node p=head;
		Node q=head;
		if(location>count||location<1)
			System.out.println("λ�ô���");
		else if(location==1){
			head=head.next;
		}
		else{
			int j=1;
			while(j!=location&&p!=null){
				q=p;
				p=p.next;
				j++;
			}
			
			q.next=p.next;
			p.next=null;
		}
	}
	//��������
	public int find(int location){
		Node p=head;
		if(location>count||location<1)
			return -1;
		else{
			int j=1;
			while(j!=location&&p!=null){
				p=p.next;
				j=j+1;
			}	
		}
		return p.data;
	}
	//��������
	public void sort(){
		Node p;
		boolean sign=true;
		int i=0;
		do{
			sign=false;
			for(p=head;p.next!=null;p=p.next){
				if(p.data>p.next.data){
					int temp;
					temp=p.data;
					p.data=p.next.data;
					p.next.data=temp;
					sign=true;
				}
			}
			i++;
		}while(i<count-1&&p!=null);
	}

}