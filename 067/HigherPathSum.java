import java.io.FileDescriptor;
import java.io.FileReader;
import java.io.IOException;

class HigherPathSum{

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

		System.out.println("debug, read string: >"+sb.toString());
		
		return (sb.length()==0? null : sb.toString());
	}

	private static Integer[] tokenizeTriangle(String input) {
		String[] buffer = input.split(" ");
		Integer[] array = new Integer[buffer.length];
		
		for(int i=0; i<buffer.length; i++){
			//System.out.println("debug, converting: >"+buffer[i]+"<");
			array[i] = new Integer(buffer[i]);
		}
		
		return array;
	}

	private static Integer[] walkUp(Integer[] previousRow, Integer[] currentRow) {
		assert(previousRow.length == currentRow.length-1);
		System.out.println("prev length: "+previousRow.length +" curr length: "+ currentRow.length);
		
		Integer[] finalRow = new Integer[currentRow.length];
		
		for (int i=0; i<currentRow.length; i++)
			finalRow[i] = currentRow[i] + (previousRow[i]>previousRow[i+1]? previousRow[i] : previousRow[i+1]);
		
		return finalRow;
	}

	static public void main(String [] args){
		String buffer;
		Integer[] previousRow = null;
		Integer[] currentRow = null;

		FileReader fr = new FileReader(FileDescriptor.in);

		previousRow=tokenizeTriangle(readLine(fr)); // preload first row as is
		while ( (buffer=readLine(fr)) != null ){
			currentRow=tokenizeTriangle(buffer);
			previousRow=walkUp(previousRow,currentRow);
		}

		System.out.println(previousRow[0]);
	}
}
