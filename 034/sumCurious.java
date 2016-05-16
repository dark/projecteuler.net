
public class sumCurious {

	static final int CAP = 2540160;
	static int[] facts = {1,1,2,6,24,120,720,5040,40320,362880};
	static int[] digits = new int[7];

	private static boolean isCurious(int param) {
		int i, localtot, input;
		
		input=param;
		digits[0] = input%10;
		input = input/10;
		digits[1] = input%10;
		input = input/10;
		digits[2] = input%10;
		input = input/10;
		digits[3] = input%10;
		input = input/10;
		digits[4] = input%10;
		input = input/10;
		digits[5] = input%10;
		input = input/10;
		digits[6] = input;
		
		i=6;
		while( digits[i] == 0)
			i--;
		
		localtot=0;
		while(i>=0){
			localtot += facts[digits[i]];
			i--;
		}

		//System.out.println(""+param+"->"+localtot);
		return (param == localtot);
	}

	static public void main(String[] args){
		for (int i=3; i<CAP; i++)
			if (isCurious(i))
				System.out.println(i);
	}

}
