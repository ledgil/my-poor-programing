/*
模重复平方计算法
java
*/
package xinanMath;

class GetModular {
	static int getModular(int a,int b) {
		return a%b;
	}
}

class GetResult{
	static int getResult(int b,int m,int n) {
			int i=0;
			int a=1;
			int nn = n;
			while (nn>0) {
				nn = nn>>1;
				i++;
			}
			for(int j=0;j<i;j++) {
				if( ((n>>j)&1) == 1 ) 
					a = GetModular.getModular(a*b,m);
				b = GetModular.getModular(b*b,m);	
			}
		return a;
	}
}

public class ModularRepetitionSquaredCalculation{
	public static void main(String[] args) {
		System.out.println(GetResult.getResult(12996,37909,227));

	}
}
