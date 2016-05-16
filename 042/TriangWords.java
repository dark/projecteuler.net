import java.io.FileDescriptor;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;


public class TriangWords {
	
	static final int CAP = 364;
	static final int REALCAP = (int) (Math.sqrt(CAP/2)+1);
	
	private static String readLine(FileReader fr){
		StringBuilder sb = new StringBuilder();
		int readChar;

		try {
			while ( (readChar= fr.read()) != -1 && readChar != '\n'){
				sb.append((char)readChar);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

		//System.out.println("debug, read string: >"+sb.toString());
		
		return (sb.length()==0? null : sb.toString());
	}
	

	private static HashMap<Integer, Boolean> populateTriangs() {
		HashMap<Integer, Boolean> map = new HashMap<Integer, Boolean>();
		
		for (int i=0; i<=CAP; i++)
			map.put(new Integer(i*(i+1)/2), true);
			
		return map;
	}

	private static Integer myHash(String buffer) {
		int res=0;
		
		for(int i=0; i<buffer.length(); i++)
			res+=(buffer.charAt(i)-'A'+1);
			
		return new Integer(res);
	}
	
	static public void main (String[] args){
		FileReader fr = new FileReader(FileDescriptor.in);
		String buffer;
		int i=1;
		HashMap<Integer, Boolean> triangs;
		
		triangs = populateTriangs();
		
		while ( (buffer=readLine(fr)) != null ){
			if (triangs.containsKey(myHash(buffer)))
				System.out.println((i++)+": "+buffer+" --> "+myHash(buffer));
		}
	}

}
