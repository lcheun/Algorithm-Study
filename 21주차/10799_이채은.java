import java.util.Stack;
import java.util.Scanner;


public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        Stack<String> stack = new Stack<>();
        String x = sc.next();
        String[] pipe = x.split("");
        int size = pipe.length;
        int pnum=0; //잘린 파이프 개수
        int curr=0; //현재 읽는 파이프 개수
        
        for(int i=0; i<size; i++){
            stack.push(pipe[i]);
        }
        while(!stack.isEmpty()) {
        	String element = stack.pop();
        	if(element.equals(")")) {
        		String top = stack.peek();
        		if(top.equals(")")) curr++;
        		else {
        			pnum += curr;
        			stack.pop();
        		}
        	}
        	else {
        		pnum += 1;
        		curr -= 1;
        	}
        }
        System.out.println(pnum);
        sc.close();
    }
}
