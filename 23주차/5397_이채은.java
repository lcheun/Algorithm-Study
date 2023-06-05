import java.io.*;
import java.util.Stack;

public class Main{
	static Stack<Character> s1 = new Stack<Character>();
	static Stack<Character> s2 = new Stack<Character>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int i=0; i<T; i++){
        	StringBuilder pw = new StringBuilder("");
        	char[] input = br.readLine().toCharArray();
        	for(char tmp : input) {
        		if(tmp == '<') {
                    if(!s1.empty()) s2.push(s1.pop());
            	}
                
                else if(tmp == '>') {
                   if(!s2.empty()) s1.push(s2.pop());
                }
                
                else if(tmp == '-') {
                    if(!s1.empty()) s1.pop();
                }
                    
                else{
                	s1.push(tmp);
                }
        	}
        	
        	while(!s2.empty())
        		s1.push(s2.pop());
        	
        	while(!s1.empty())
        		pw.append(s1.pop());
        	
            System.out.println(pw.reverse());
        }
    }
}
